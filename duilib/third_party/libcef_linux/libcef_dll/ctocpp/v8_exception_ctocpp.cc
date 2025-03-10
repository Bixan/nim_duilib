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
// $hash=b526fc9328005169181fb26787151d4dc1193b70$
//

#include "libcef_dll/ctocpp/v8_exception_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") CefString CefV8ExceptionCToCpp::GetMessage() {
  auto* _struct = GetStruct();
  if (!_struct->get_message) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_message(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") CefString CefV8ExceptionCToCpp::GetSourceLine() {
  auto* _struct = GetStruct();
  if (!_struct->get_source_line) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_source_line(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
CefString CefV8ExceptionCToCpp::GetScriptResourceName() {
  auto* _struct = GetStruct();
  if (!_struct->get_script_resource_name) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_script_resource_name(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") int CefV8ExceptionCToCpp::GetLineNumber() {
  auto* _struct = GetStruct();
  if (!_struct->get_line_number) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_line_number(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefV8ExceptionCToCpp::GetStartPosition() {
  auto* _struct = GetStruct();
  if (!_struct->get_start_position) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_start_position(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefV8ExceptionCToCpp::GetEndPosition() {
  auto* _struct = GetStruct();
  if (!_struct->get_end_position) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_end_position(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefV8ExceptionCToCpp::GetStartColumn() {
  auto* _struct = GetStruct();
  if (!_struct->get_start_column) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_start_column(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefV8ExceptionCToCpp::GetEndColumn() {
  auto* _struct = GetStruct();
  if (!_struct->get_end_column) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_end_column(_struct);

  // Return type: simple
  return _retval;
}

// CONSTRUCTOR - Do not edit by hand.

CefV8ExceptionCToCpp::CefV8ExceptionCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefV8ExceptionCToCpp::~CefV8ExceptionCToCpp() {}

template <>
cef_v8_exception_t*
CefCToCppRefCounted<CefV8ExceptionCToCpp, CefV8Exception, cef_v8_exception_t>::
    UnwrapDerived(CefWrapperType type, CefV8Exception* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefV8ExceptionCToCpp,
                                   CefV8Exception,
                                   cef_v8_exception_t>::kWrapperType =
    WT_V8_EXCEPTION;
