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
// $hash=a77ae77f46d058e2f8ee48e6fe5fdb2b90358f32$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_VIEWS_WINDOW_DELEGATE_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_VIEWS_WINDOW_DELEGATE_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/views/cef_window_capi.h"
#include "include/capi/views/cef_window_delegate_capi.h"
#include "include/views/cef_window.h"
#include "include/views/cef_window_delegate.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class CefWindowDelegateCppToC
    : public CefCppToCRefCounted<CefWindowDelegateCppToC,
                                 CefWindowDelegate,
                                 cef_window_delegate_t> {
 public:
  CefWindowDelegateCppToC();
  virtual ~CefWindowDelegateCppToC();
};

constexpr auto CefWindowDelegateCppToC_Wrap = CefWindowDelegateCppToC::Wrap;
constexpr auto CefWindowDelegateCppToC_Unwrap = CefWindowDelegateCppToC::Unwrap;

#endif  // CEF_LIBCEF_DLL_CPPTOC_VIEWS_WINDOW_DELEGATE_CPPTOC_H_
