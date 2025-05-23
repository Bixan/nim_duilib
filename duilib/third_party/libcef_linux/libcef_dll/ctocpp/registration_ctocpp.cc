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
// $hash=a95b0547f42c186c1c635ed78a20d4f1bec5f392$
//

#include "libcef_dll/ctocpp/registration_ctocpp.h"

#include "libcef_dll/shutdown_checker.h"

// CONSTRUCTOR - Do not edit by hand.

CefRegistrationCToCpp::CefRegistrationCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefRegistrationCToCpp::~CefRegistrationCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_registration_t*
CefCToCppRefCounted<CefRegistrationCToCpp,
                    CefRegistration,
                    cef_registration_t>::UnwrapDerived(CefWrapperType type,
                                                       CefRegistration* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefRegistrationCToCpp,
                                   CefRegistration,
                                   cef_registration_t>::kWrapperType =
    WT_REGISTRATION;
