#ifndef UI_CEF_CONTROL_MEMORY_DC_H_
#define UI_CEF_CONTROL_MEMORY_DC_H_

#include "duilib/duilib_defs.h"

namespace ui {

/** 内存dc类，维护HBITMAP与HDC对象，方便快速的储存位图数据
 * @copyright (c) 2016, NetEase Inc. All rights reserved
 * @author Redrain
 * @date 2016/7/19
 */
class CefMemoryDC
{
public:
    CefMemoryDC();
    ~CefMemoryDC();

    // 初始化内存dc数据，并创建出对应的位图对象
    // 如果pBits参数不为空，则用pBits参数的数据填充位图
    // 此函数可以反复调用，会自动删除原来的位图对象
    bool Init(HDC src_dc, int width, int height, const LPVOID pBits = NULL);

    // 删除位图对象并初始化变量
    void DeleteDC();

    // 判断内存dc是否可以使用
    bool IsValid();

    HDC GetDC();
    HBITMAP GetBitmap();

    // 获取内存位图数据指针，可用于填充位图
    BYTE* GetBits();
    // 获取内存位图的宽度
    int GetWidth();
    // 获取内存位图的高度
    int GetHeight();

private:
    bool CreateMemoryDC(HDC src_dc, int width, int height, void** pBits);

private:
    HDC m_hMemDC;
    HBITMAP m_pBitmap;
    HBITMAP m_pOldBitmap;
    BITMAP m_bitmapInfo;

    SIZE m_bitmapSize;
    bool m_bValid;
};

} //namespace ui

#endif //UI_CEF_CONTROL_MEMORY_DC_H_
