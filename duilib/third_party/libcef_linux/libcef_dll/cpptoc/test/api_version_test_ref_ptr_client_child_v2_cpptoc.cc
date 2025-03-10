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
// $hash=fd96754e2ee96243aa15e611a2d9921d7b92f6b0$
//

#include "libcef_dll/cpptoc/test/api_version_test_ref_ptr_client_child_v2_cpptoc.h"

#include "libcef_dll/shutdown_checker.h"

#if CEF_API_ADDED(13302)

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK api_version_test_ref_ptr_client_child_v2_get_other_value(
    struct _cef_api_version_test_ref_ptr_client_child_v2_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      CefApiVersionTestRefPtrClientChildV2CppToC::Get(self)->GetOtherValue();

  // Return type: simple
  return _retval;
}

#if CEF_API_ADDED(13303)
int CEF_CALLBACK api_version_test_ref_ptr_client_child_v2_get_another_value(
    struct _cef_api_version_test_ref_ptr_client_child_v2_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      CefApiVersionTestRefPtrClientChildV2CppToC::Get(self)->GetAnotherValue();

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_ADDED(13303)

int CEF_CALLBACK api_version_test_ref_ptr_client_child_v2_get_value_legacy(
    struct _cef_api_version_test_ref_ptr_client_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      CefApiVersionTestRefPtrClientChildV2CppToC::Get(
          reinterpret_cast<cef_api_version_test_ref_ptr_client_child_v2_t*>(
              self))
          ->GetValueLegacy();

  // Return type: simple
  return _retval;
}

#if CEF_API_ADDED(CEF_EXPERIMENTAL)
int CEF_CALLBACK api_version_test_ref_ptr_client_child_v2_get_value_exp(
    struct _cef_api_version_test_ref_ptr_client_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      CefApiVersionTestRefPtrClientChildV2CppToC::Get(
          reinterpret_cast<cef_api_version_test_ref_ptr_client_child_v2_t*>(
              self))
          ->GetValueExp();

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_ADDED(CEF_EXPERIMENTAL)

#if CEF_API_REMOVED(13301)
int CEF_CALLBACK api_version_test_ref_ptr_client_child_v2_get_value(
    struct _cef_api_version_test_ref_ptr_client_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      CefApiVersionTestRefPtrClientChildV2CppToC::Get(
          reinterpret_cast<cef_api_version_test_ref_ptr_client_child_v2_t*>(
              self))
          ->GetValue();

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_REMOVED(13301)

#if CEF_API_RANGE(13301, 13302)
int CEF_CALLBACK api_version_test_ref_ptr_client_child_v2_get_value_v1(
    struct _cef_api_version_test_ref_ptr_client_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      CefApiVersionTestRefPtrClientChildV2CppToC::Get(
          reinterpret_cast<cef_api_version_test_ref_ptr_client_child_v2_t*>(
              self))
          ->GetValueV1();

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_RANGE(13301, 13302)

#if CEF_API_ADDED(13302)
int CEF_CALLBACK api_version_test_ref_ptr_client_child_v2_get_value_v2(
    struct _cef_api_version_test_ref_ptr_client_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }

  // Execute
  int _retval =
      CefApiVersionTestRefPtrClientChildV2CppToC::Get(
          reinterpret_cast<cef_api_version_test_ref_ptr_client_child_v2_t*>(
              self))
          ->GetValueV2();

  // Return type: simple
  return _retval;
}
#endif  // CEF_API_ADDED(13302)

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefApiVersionTestRefPtrClientChildV2CppToC::
    CefApiVersionTestRefPtrClientChildV2CppToC() {
  GetStruct()->get_other_value =
      api_version_test_ref_ptr_client_child_v2_get_other_value;
#if CEF_API_ADDED(13303)
  GetStruct()->get_another_value =
      api_version_test_ref_ptr_client_child_v2_get_another_value;
#endif
  GetStruct()->base.get_value_legacy =
      api_version_test_ref_ptr_client_child_v2_get_value_legacy;
#if CEF_API_REMOVED(13301)
  GetStruct()->base.get_value =
      api_version_test_ref_ptr_client_child_v2_get_value;
#endif
#if CEF_API_RANGE(13301, 13302)
  GetStruct()->base.get_value_v1 =
      api_version_test_ref_ptr_client_child_v2_get_value_v1;
#endif
#if CEF_API_ADDED(13302)
  GetStruct()->base.get_value_v2 =
      api_version_test_ref_ptr_client_child_v2_get_value_v2;
#endif
#if CEF_API_ADDED(CEF_EXPERIMENTAL)
  GetStruct()->base.get_value_exp =
      api_version_test_ref_ptr_client_child_v2_get_value_exp;
#endif
}

// DESTRUCTOR - Do not edit by hand.

CefApiVersionTestRefPtrClientChildV2CppToC::
    ~CefApiVersionTestRefPtrClientChildV2CppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefApiVersionTestRefPtrClientChildV2>
CefCppToCRefCounted<CefApiVersionTestRefPtrClientChildV2CppToC,
                    CefApiVersionTestRefPtrClientChildV2,
                    cef_api_version_test_ref_ptr_client_child_v2_t>::
    UnwrapDerived(CefWrapperType type,
                  cef_api_version_test_ref_ptr_client_child_v2_t* s) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<
    CefApiVersionTestRefPtrClientChildV2CppToC,
    CefApiVersionTestRefPtrClientChildV2,
    cef_api_version_test_ref_ptr_client_child_v2_t>::kWrapperType =
    WT_API_VERSION_TEST_REF_PTR_CLIENT_CHILD_V2;

#endif  // CEF_API_ADDED(13302)
