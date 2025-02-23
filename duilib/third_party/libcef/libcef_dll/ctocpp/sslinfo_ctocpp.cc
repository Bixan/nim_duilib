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
// $hash=9358f17a8e9c9a17766892e264cf228bf996becc$
//

#include "libcef_dll/ctocpp/sslinfo_ctocpp.h"

#include "libcef_dll/ctocpp/x509_certificate_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") cef_cert_status_t CefSSLInfoCToCpp::GetCertStatus() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_cert_status) {
    return CERT_STATUS_NONE;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_cert_status_t _retval = _struct->get_cert_status(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefX509Certificate> CefSSLInfoCToCpp::GetX509Certificate() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_x509_certificate) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_x509_certificate(_struct);

  // Return type: refptr_same
  return CefX509CertificateCToCpp_Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

CefSSLInfoCToCpp::CefSSLInfoCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefSSLInfoCToCpp::~CefSSLInfoCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_sslinfo_t*
CefCToCppRefCounted<CefSSLInfoCToCpp, CefSSLInfo, cef_sslinfo_t>::UnwrapDerived(
    CefWrapperType type,
    CefSSLInfo* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefSSLInfoCToCpp,
                                   CefSSLInfo,
                                   cef_sslinfo_t>::kWrapperType = WT_SSLINFO;
