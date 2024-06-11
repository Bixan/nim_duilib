#ifndef DUILIB_CONFIG_LINUX_H_
#define DUILIB_CONFIG_LINUX_H_

#include <cstddef>

#define UILIB_API

typedef unsigned int    UINT;
typedef std::size_t     LRESULT;
typedef std::size_t     WPARAM;
typedef std::size_t     LPARAM;

//#define MAKEWORD(a, b)      ((uint16_t)(((uint8_t)(((size_t)(a)) & 0xff)) | ((uint16_t)((uint8_t)(((size_t)(b)) & 0xff))) << 8))
//#define MAKELONG(a, b)      ((uint32_t)(((uint16_t)(((size_t)(a)) & 0xffff)) | ((uint32_t)((uint16_t)(((size_t)(b)) & 0xffff))) << 16))
//#define LOWORD(l)           ((uint16_t)(((size_t)(l)) & 0xffff))
//#define HIWORD(l)           ((uint16_t)((((size_t)(l)) >> 16) & 0xffff))
//#define LOBYTE(w)           ((uint8_t)(((size_t)(w)) & 0xff))
//#define HIBYTE(w)           ((uint8_t)((((size_t)(w)) >> 8) & 0xff))
//
//#define GET_X_LPARAM(lp)    ((int)(short)LOWORD(lp))
//#define GET_Y_LPARAM(lp)    ((int)(short)HIWORD(lp))
//
//#define GET_WHEEL_DELTA_WPARAM(wParam)  ((short)HIWORD(wParam))
//#define GET_KEYSTATE_WPARAM(wParam)     (LOWORD(wParam))

#endif //DUILIB_CONFIG_LINUX_H_
