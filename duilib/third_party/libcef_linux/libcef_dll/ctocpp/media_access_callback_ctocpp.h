// Copyright (c) 2025 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=08684ee0d1f8cd47c6cacb741a128978002ddace$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_MEDIA_ACCESS_CALLBACK_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_MEDIA_ACCESS_CALLBACK_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_permission_handler_capi.h"
#include "include/cef_permission_handler.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefMediaAccessCallbackCToCpp
    : public CefCToCppRefCounted<CefMediaAccessCallbackCToCpp,
                                 CefMediaAccessCallback,
                                 cef_media_access_callback_t> {
 public:
  CefMediaAccessCallbackCToCpp();
  virtual ~CefMediaAccessCallbackCToCpp();

  // CefMediaAccessCallback methods.
  void Continue(uint32_t allowed_permissions) override;
  void Cancel() override;
};

constexpr auto CefMediaAccessCallbackCToCpp_Wrap =
    CefMediaAccessCallbackCToCpp::Wrap;
constexpr auto CefMediaAccessCallbackCToCpp_Unwrap =
    CefMediaAccessCallbackCToCpp::Unwrap;

#endif  // CEF_LIBCEF_DLL_CTOCPP_MEDIA_ACCESS_CALLBACK_CTOCPP_H_
