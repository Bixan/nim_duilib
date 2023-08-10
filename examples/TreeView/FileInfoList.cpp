#include "FileInfoList.h"
#include "FileInfoItem.h"

FileInfoList::FileInfoList()
{
}

FileInfoList::~FileInfoList()
{
    ClearFileList();
}

ui::Control* FileInfoList::CreateElement()
{
    FileInfoItem* item = new FileInfoItem;
    item->AttachEvent(ui::kEventMouseDoubleClick, nbase::Bind(&FileInfoList::OnDoubleClickItem, this, std::placeholders::_1));
    ui::GlobalManager::Instance().FillBoxWithCache(item, L"tree_view/list_item.xml");
    return item;
}

bool FileInfoList::FillElement(ui::Control* pControl, size_t nElementIndex)
{
    FileInfoItem* pItem = dynamic_cast<FileInfoItem*>(pControl);
    ASSERT(pItem != nullptr);
    ASSERT(nElementIndex < m_pathList.size());
    if ((pItem == nullptr) || (nElementIndex >= m_pathList.size())) {
        return false;
    }
    const FileInfo& fileInfo = m_pathList[nElementIndex];
    pItem->InitSubControls(fileInfo, nElementIndex);
    pItem->SetUserDataID(nElementIndex);
    return true;
}

size_t FileInfoList::GetElementCount()
{
    return m_pathList.size();
}

void FileInfoList::SetElementSelected(size_t nElementIndex, bool bSelected)
{

}

bool FileInfoList::IsElementSelected(size_t nElementIndex)
{
    return false;
}

void FileInfoList::AddFileList(const std::vector<FileInfo>& pathList)
{
    m_pathList.reserve(m_pathList.size() + pathList.size());
    for (const FileInfo& fileInfo : pathList) {
        m_pathList.emplace_back(fileInfo);
        ui::GlobalManager::Instance().Icon().AddIcon(fileInfo.m_hIcon);
    }
    // 通知ListBox数据总数变动
    EmitCountChanged();
}

void FileInfoList::SetFileList(const std::vector<FileInfo>& pathList)
{
    ClearFileList();
    AddFileList(pathList);
}

void FileInfoList::ClearFileList()
{
    for (const FileInfo& fileInfo : m_pathList) {
        if (fileInfo.m_hIcon != nullptr) {
            ui::GlobalManager::Instance().Icon().RemoveIcon(fileInfo.m_hIcon);
            ::DestroyIcon(fileInfo.m_hIcon);
        }
    }
    m_pathList.clear();
}

bool FileInfoList::OnDoubleClickItem(const ui::EventArgs& args)
{
    FileInfoItem* pItem = dynamic_cast<FileInfoItem*>(args.pSender);
    if (pItem != nullptr) {
        size_t nElementIndex = pItem->GetUserDataID();
        if (nElementIndex < m_pathList.size()) {
            const FileInfo& fileInfo = m_pathList[nElementIndex];
            if (fileInfo.m_isFolder) {

            }
        }
    }
    return true;
}