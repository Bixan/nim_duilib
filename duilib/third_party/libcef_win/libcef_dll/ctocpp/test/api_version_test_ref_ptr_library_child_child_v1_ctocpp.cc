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
// $hash=253c2a5e8cadac4d0a3204e74b31da060c872876$
//

#include "libcef_dll/ctocpp/test/api_version_test_ref_ptr_library_child_child_v1_ctocpp.h"

#include "libcef_dll/shutdown_checker.h"

#if CEF_API_RANGE(13301, 13302)

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<
    CefApiVersionTestRefPtrLibraryChildChildV1> CefApiVersionTestRefPtrLibraryChildChildV1::
    Create() {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_api_version_test_ref_ptr_library_child_child_v1_create();

  // Return type: refptr_same
  return CefApiVersionTestRefPtrLibraryChildChildV1CToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<
    CefApiVersionTestRefPtrLibraryChildChildV1> CefApiVersionTestRefPtrLibraryChildChildV1::
    Create(int value, int other_value, int other_other_value) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval =
      cef_api_version_test_ref_ptr_library_child_child_v1_create_with_default(
          value, other_value, other_other_value);

  // Return type: refptr_same
  return CefApiVersionTestRefPtrLibraryChildChildV1CToCpp_Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
int CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::GetOtherOtherValue() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_other_other_value) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_other_other_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::SetOtherOtherValue(
    int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_other_other_value) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_other_other_value(_struct, value);
}

NO_SANITIZE("cfi-icall")
int CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::GetOtherValue() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_child_t*>(
          GetStruct());
  if (!_struct->get_other_value) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_other_value(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::SetOtherValue(
    int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_child_t*>(
          GetStruct());
  if (!_struct->set_other_value) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_other_value(_struct, value);
}

NO_SANITIZE("cfi-icall")
int CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::GetValueLegacy() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->get_value_legacy) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value_legacy(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::SetValueLegacy(
    int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->set_value_legacy) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value_legacy(_struct, value);
}

#if CEF_API_ADDED(CEF_EXPERIMENTAL)
NO_SANITIZE("cfi-icall")
int CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::GetValueExp() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->get_value_exp) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value_exp(_struct);

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_ADDED(CEF_EXPERIMENTAL)

#if CEF_API_ADDED(CEF_EXPERIMENTAL)
NO_SANITIZE("cfi-icall")
void CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::SetValueExp(int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->set_value_exp) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value_exp(_struct, value);
}
#endif  // CEF_API_ADDED(CEF_EXPERIMENTAL)

#if CEF_API_REMOVED(13301)
NO_SANITIZE("cfi-icall")
int CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::GetValue() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->get_value) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value(_struct);

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_REMOVED(13301)

#if CEF_API_REMOVED(13301)
NO_SANITIZE("cfi-icall")
void CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::SetValue(int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->set_value) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value(_struct, value);
}
#endif  // CEF_API_REMOVED(13301)

#if CEF_API_RANGE(13301, 13302)
NO_SANITIZE("cfi-icall")
int CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::GetValueV1() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->get_value_v1) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value_v1(_struct);

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_RANGE(13301, 13302)

#if CEF_API_RANGE(13301, 13302)
NO_SANITIZE("cfi-icall")
void CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::SetValueV1(int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->set_value_v1) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value_v1(_struct, value);
}
#endif  // CEF_API_RANGE(13301, 13302)

#if CEF_API_ADDED(13302)
NO_SANITIZE("cfi-icall")
int CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::GetValueV2() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->get_value_v2) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_value_v2(_struct);

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_ADDED(13302)

#if CEF_API_ADDED(13302)
NO_SANITIZE("cfi-icall")
void CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::SetValueV2(int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct =
      reinterpret_cast<cef_api_version_test_ref_ptr_library_t*>(GetStruct());
  if (!_struct->set_value_v2) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value_v2(_struct, value);
}
#endif  // CEF_API_ADDED(13302)

// CONSTRUCTOR - Do not edit by hand.

CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::
    CefApiVersionTestRefPtrLibraryChildChildV1CToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefApiVersionTestRefPtrLibraryChildChildV1CToCpp::
    ~CefApiVersionTestRefPtrLibraryChildChildV1CToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_api_version_test_ref_ptr_library_child_child_v1_t*
CefCToCppRefCounted<CefApiVersionTestRefPtrLibraryChildChildV1CToCpp,
                    CefApiVersionTestRefPtrLibraryChildChildV1,
                    cef_api_version_test_ref_ptr_library_child_child_v1_t>::
    UnwrapDerived(CefWrapperType type,
                  CefApiVersionTestRefPtrLibraryChildChildV1* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<
    CefApiVersionTestRefPtrLibraryChildChildV1CToCpp,
    CefApiVersionTestRefPtrLibraryChildChildV1,
    cef_api_version_test_ref_ptr_library_child_child_v1_t>::kWrapperType =
    WT_API_VERSION_TEST_REF_PTR_LIBRARY_CHILD_CHILD_V1;

#endif  // CEF_API_RANGE(13301, 13302)
