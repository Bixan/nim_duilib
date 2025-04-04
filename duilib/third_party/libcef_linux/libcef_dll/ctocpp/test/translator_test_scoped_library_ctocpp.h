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
// $hash=f8b23ebb5c2337fb4cca32d225d117827ee0959f$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_TEST_TRANSLATOR_TEST_SCOPED_LIBRARY_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_TEST_TRANSLATOR_TEST_SCOPED_LIBRARY_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/test/cef_translator_test_capi.h"
#include "include/test/cef_translator_test.h"
#include "libcef_dll/ctocpp/ctocpp_scoped.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefTranslatorTestScopedLibraryCToCpp
    : public CefCToCppScoped<CefTranslatorTestScopedLibraryCToCpp,
                             CefTranslatorTestScopedLibrary,
                             cef_translator_test_scoped_library_t> {
 public:
  CefTranslatorTestScopedLibraryCToCpp();
  virtual ~CefTranslatorTestScopedLibraryCToCpp();

  // CefTranslatorTestScopedLibrary methods.
  int GetValue() override;
  void SetValue(int value) override;
};

constexpr auto CefTranslatorTestScopedLibraryCToCpp_Wrap =
    CefTranslatorTestScopedLibraryCToCpp::Wrap;
constexpr auto CefTranslatorTestScopedLibraryCToCpp_UnwrapOwn =
    CefTranslatorTestScopedLibraryCToCpp::UnwrapOwn;
constexpr auto CefTranslatorTestScopedLibraryCToCpp_UnwrapRaw =
    CefTranslatorTestScopedLibraryCToCpp::UnwrapRaw;

#endif  // CEF_LIBCEF_DLL_CTOCPP_TEST_TRANSLATOR_TEST_SCOPED_LIBRARY_CTOCPP_H_
