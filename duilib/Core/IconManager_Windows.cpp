#include "IconManager_Windows.h"
#include "duilib/Utils/StringUtil.h"
#include "duilib/Core/Window.h"
#include "duilib/Image/ImageLoadAttribute.h"

#ifdef DUILIB_BUILD_FOR_WIN

namespace ui 
{

IconManager::IconManager():
    m_nNextID(1),
    m_prefix(_T("icon:"))
{
}

IconManager::~IconManager()
{
    for (const auto& iter : m_iconMap) {
        HICON hIcon = iter.second;
        if (hIcon != nullptr) {
            ::DestroyIcon(hIcon);
        }
    }
}

DString IconManager::GetIconString(HICON hIcon) const
{
    uint32_t id = GetIconID(hIcon);
    if (id == 0) {
        return DString();
    }
    else {
        return GetIconString(id);
    }
}

DString IconManager::GetIconString(uint32_t id) const
{
    ASSERT(id > 0);
    DString str = m_prefix;
    str += StringUtil::UInt32ToString(id);
    return str;
}

bool IconManager::IsIconString(const DString& str) const
{
    return str.find(m_prefix) == 0;
}

HICON IconManager::GetIcon(const DString& str) const
{
    if (str.empty()) {
        return nullptr;
    }
    size_t pos = str.find(m_prefix);
    ASSERT(pos == 0);
    if (pos != 0) {
        return nullptr;
    }
    DString idStr = str.substr(pos + m_prefix.size());
    uint32_t id = StringUtil::StringToUInt32(idStr.c_str(), nullptr, 10);
    return GetIcon(id);
}

UiSize IconManager::GetIconSize(const DString& str) const
{
    return GetIconSize(GetIcon(str));
}

struct ScopedICONINFO :
    public ICONINFO {
    ScopedICONINFO() {
        hbmColor = nullptr;
        hbmMask = nullptr;
    }
    ~ScopedICONINFO() {
        if (hbmColor) {
            ::DeleteObject(hbmColor);
        }
        if (hbmMask) {
            ::DeleteObject(hbmMask);
        }
    }
};

bool IconManager::LoadIconData(const DString& str,
                               const Window* pWindow,
                               const ImageLoadAttribute& loadAtrribute,
                               bool bEnableDpiScale,
                               std::vector<uint8_t>& bitmapData,
                               uint32_t& bitmapWidth,
                               uint32_t& bitmapHeight,
                               bool& bDpiScaled) const
{
    bitmapData.clear();
    bitmapWidth = 0;
    bitmapHeight = 0;
    bDpiScaled = false;

    HICON hIcon = GetIcon(str);
    ASSERT(hIcon != nullptr);
    if (hIcon == nullptr) {
        return false;
    }

    ScopedICONINFO iconInfo;
    if (!::GetIconInfo(hIcon, &iconInfo)) {
#ifdef _DEBUG
        DWORD dwLastError = ::GetLastError();
        (void)dwLastError;
        ASSERT(!"GetIconInfo failed!");
#endif
        return false;
    }

    if (!iconInfo.fIcon) {
        return false;
    }

    int32_t nWidth = 0;
    int32_t nHeight = 0;
    if (iconInfo.hbmColor != nullptr) {
        BITMAP bmp = { 0 };
        ::GetObject(iconInfo.hbmColor, sizeof(bmp), &bmp);
        nWidth = bmp.bmWidth;
        nHeight = bmp.bmHeight;
    }
    if ((nWidth <= 0) || (nHeight <= 0)) {
        return false;
    }

    uint32_t iconWidth = nWidth;
    uint32_t iconHeight = nHeight;
    //此处：如果只设置了宽度或者高度，那么会按锁定纵横比的方式对整个图片进行缩放
    if (!loadAtrribute.CalcImageLoadSize(iconWidth, iconHeight)) {
        iconWidth = nWidth;
        iconHeight = nHeight;
    }

    //加载图片时，按需对图片大小进行DPI自适应
    bool bNeedDpiScale = bEnableDpiScale;
    if (loadAtrribute.HasSrcDpiScale()) {
        //如果配置文件中有设置scaledpi属性，则以配置文件中的设置为准
        bNeedDpiScale = loadAtrribute.NeedDpiScale();
    }
    if (bNeedDpiScale && (pWindow != nullptr)) {
        uint32_t dpiScale = pWindow->Dpi().GetScale();
        ASSERT(dpiScale > 0);
        if (dpiScale != 0) {
            float scaleRatio = (float)dpiScale / 100.0f;
            iconWidth = static_cast<int>(iconWidth * scaleRatio);
            iconHeight = static_cast<int>(iconHeight * scaleRatio);
            bDpiScaled = true;
        }
    }

    if ((iconWidth > 0) && (iconHeight > 0)) {
        nWidth = iconWidth;
        nHeight = iconHeight;
    }

    BITMAPINFOHEADER bi = { 0 };
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = nWidth;
    bi.biHeight = -nHeight;
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;

    HWND hWnd = (pWindow != nullptr) ? pWindow->NativeWnd()->GetHWND() : nullptr;
    HDC hdc = ::GetDC(hWnd);
    uint32_t* bits = nullptr;
    HBITMAP dib = ::CreateDIBSection(hdc,
                                     reinterpret_cast<BITMAPINFO*>(&bi),
                                     DIB_RGB_COLORS,
                                     reinterpret_cast<void**>(&bits),
                                     nullptr,
                                     0);
    ASSERT(dib != nullptr);
    if (dib == nullptr)    {
        ::ReleaseDC(hWnd, hdc);
        return false;
    }
    if (bits == nullptr) {
        ::ReleaseDC(hWnd, hdc);
        ::DeleteObject(dib);
        return false;
    }
    HDC dibDC = ::CreateCompatibleDC(hdc);
    ::ReleaseDC(hWnd, hdc);
    hdc = nullptr;

    HGDIOBJ oldObj = ::SelectObject(dibDC, dib);

    const size_t num_pixels = (size_t)nWidth * nHeight;
    memset(bits, 0, num_pixels * 4);
    ::DrawIconEx(dibDC, 0, 0, hIcon, nWidth, nHeight, 0, nullptr, DI_MASK);

    bool* opaque = (new bool[num_pixels]);
    for (size_t i = 0; i < num_pixels; ++i)    {
        opaque[i] = !bits[i];
    }

    memset(bits, 0, num_pixels * 4);
    ::DrawIconEx(dibDC, 0, 0, hIcon, nWidth, nHeight, 0, nullptr, DI_NORMAL);

    bitmapData.resize(num_pixels * 4, 0);
    ::memcpy(bitmapData.data(), (void*)(bits), num_pixels * 4);

    bool bitmap_has_alpha_channel = false;
    const uint32_t* pixels = static_cast<const uint32_t*>((const void*)bitmapData.data());
    for (const uint32_t* end = pixels + num_pixels; pixels != end; ++pixels) {
        if ((*pixels & 0xff000000) != 0) {
            bitmap_has_alpha_channel = true;
        }
    }
    if (!bitmap_has_alpha_channel) {
        uint32_t* p = static_cast<uint32_t*>((void*)bitmapData.data());
        for (size_t i = 0; i < num_pixels; ++p, ++i) {
            if (opaque[i]) {
                *p |= 0xff000000;
            }
            else {
                *p &= 0x00000000;
            }
        }
    }

    ::SelectObject(dibDC, oldObj);
    ::DeleteObject(dib);
    ::DeleteDC(dibDC);
    delete[] opaque;

    bitmapWidth = nWidth;
    bitmapHeight = nHeight;
    return true;
}

UiSize IconManager::GetIconSize(HICON hIcon) const
{
    if (hIcon == nullptr) {
        return UiSize();
    }
    ScopedICONINFO iconInfo;
    if (!::GetIconInfo(hIcon, &iconInfo)) {
        return UiSize();
    }
    int32_t nWidth = 0;
    int32_t nHeight = 0;
    if (iconInfo.hbmColor != nullptr) {
        BITMAP bmp = { 0 };
        ::GetObject(iconInfo.hbmColor, sizeof(bmp), &bmp);
        nWidth = bmp.bmWidth;
        nHeight = bmp.bmHeight;
    }
    if ((nWidth <= 0) || (nHeight <= 0)) {
        return UiSize();
    }
    return UiSize(nWidth, nHeight);
}

uint32_t IconManager::AddIcon(HICON hIcon)
{
    if (hIcon == nullptr) {
        return 0;
    }
    uint32_t id = GetIconID(hIcon);
    if (id == 0) {

#ifdef _DEBUG
        //校验句柄的有效性
        ScopedICONINFO iconInfo;
        if (!::GetIconInfo(hIcon, &iconInfo)) {
            DWORD dwLastError = ::GetLastError();
            (void)dwLastError;
            //ASSERT(!"GetIconInfo failed!");
            return id;
        }
#endif

        id = m_nNextID++;
        m_iconMap[id] = hIcon;        
    }
    return id;
}

void IconManager::RemoveIcon(HICON hIcon)
{
    uint32_t id = GetIconID(hIcon);
    if (id != 0) {
        m_iconMap.erase(id);
    }
}

void IconManager::RemoveIcon(uint32_t id)
{
    if (id != 0) {
        m_iconMap.erase(id);
    }
}

uint32_t IconManager::GetIconID(HICON hIcon) const
{
    for (const auto& iter : m_iconMap) {
        if (iter.second == hIcon) {
            return iter.first;
        }
    }
    return 0;
}

HICON IconManager::GetIcon(uint32_t id) const
{
    auto iter = m_iconMap.find(id);
    if (iter != m_iconMap.end()) {
        return iter->second;
    }
    return nullptr;
}

}

#endif //DUILIB_BUILD_FOR_WIN
