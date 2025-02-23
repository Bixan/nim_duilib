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
// $hash=404ce4138f75c7c7e84f7afa78f8b2b0cdcdcb95$
//

#include "libcef_dll/ctocpp/request_ctocpp.h"

#include "libcef_dll/ctocpp/post_data_ctocpp.h"
#include "libcef_dll/transfer_util.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") CefRefPtr<CefRequest> CefRequest::Create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_request_create();

  // Return type: refptr_same
  return CefRequestCToCpp_Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool CefRequestCToCpp::IsReadOnly() {
  auto* _struct = GetStruct();
  if (!_struct->is_read_only) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_read_only(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") CefString CefRequestCToCpp::GetURL() {
  auto* _struct = GetStruct();
  if (!_struct->get_url) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_url(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") void CefRequestCToCpp::SetURL(const CefString& url) {
  auto* _struct = GetStruct();
  if (!_struct->set_url) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty()) {
    return;
  }

  // Execute
  _struct->set_url(_struct, url.GetStruct());
}

NO_SANITIZE("cfi-icall") CefString CefRequestCToCpp::GetMethod() {
  auto* _struct = GetStruct();
  if (!_struct->get_method) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_method(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::SetMethod(const CefString& method) {
  auto* _struct = GetStruct();
  if (!_struct->set_method) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: method; type: string_byref_const
  DCHECK(!method.empty());
  if (method.empty()) {
    return;
  }

  // Execute
  _struct->set_method(_struct, method.GetStruct());
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::SetReferrer(const CefString& referrer_url,
                                   ReferrerPolicy policy) {
  auto* _struct = GetStruct();
  if (!_struct->set_referrer) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: referrer_url

  // Execute
  _struct->set_referrer(_struct, referrer_url.GetStruct(), policy);
}

NO_SANITIZE("cfi-icall") CefString CefRequestCToCpp::GetReferrerURL() {
  auto* _struct = GetStruct();
  if (!_struct->get_referrer_url) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_referrer_url(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
CefRequest::ReferrerPolicy CefRequestCToCpp::GetReferrerPolicy() {
  auto* _struct = GetStruct();
  if (!_struct->get_referrer_policy) {
    return REFERRER_POLICY_DEFAULT;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_referrer_policy_t _retval = _struct->get_referrer_policy(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefPostData> CefRequestCToCpp::GetPostData() {
  auto* _struct = GetStruct();
  if (!_struct->get_post_data) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_post_data(_struct);

  // Return type: refptr_same
  return CefPostDataCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::SetPostData(CefRefPtr<CefPostData> postData) {
  auto* _struct = GetStruct();
  if (!_struct->set_post_data) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: postData; type: refptr_same
  DCHECK(postData.get());
  if (!postData.get()) {
    return;
  }

  // Execute
  _struct->set_post_data(_struct, CefPostDataCToCpp_Unwrap(postData));
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::GetHeaderMap(HeaderMap& headerMap) {
  auto* _struct = GetStruct();
  if (!_struct->get_header_map) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: headerMap; type: string_map_multi_byref
  cef_string_multimap_t headerMapMultimap = cef_string_multimap_alloc();
  DCHECK(headerMapMultimap);
  if (headerMapMultimap) {
    transfer_string_multimap_contents(headerMap, headerMapMultimap);
  }

  // Execute
  _struct->get_header_map(_struct, headerMapMultimap);

  // Restore param:headerMap; type: string_map_multi_byref
  if (headerMapMultimap) {
    headerMap.clear();
    transfer_string_multimap_contents(headerMapMultimap, headerMap);
    cef_string_multimap_free(headerMapMultimap);
  }
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::SetHeaderMap(const HeaderMap& headerMap) {
  auto* _struct = GetStruct();
  if (!_struct->set_header_map) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: headerMap; type: string_map_multi_byref_const
  cef_string_multimap_t headerMapMultimap = cef_string_multimap_alloc();
  DCHECK(headerMapMultimap);
  if (headerMapMultimap) {
    transfer_string_multimap_contents(headerMap, headerMapMultimap);
  }

  // Execute
  _struct->set_header_map(_struct, headerMapMultimap);

  // Restore param:headerMap; type: string_map_multi_byref_const
  if (headerMapMultimap) {
    cef_string_multimap_free(headerMapMultimap);
  }
}

NO_SANITIZE("cfi-icall")
CefString CefRequestCToCpp::GetHeaderByName(const CefString& name) {
  auto* _struct = GetStruct();
  if (!_struct->get_header_by_name) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return CefString();
  }

  // Execute
  cef_string_userfree_t _retval =
      _struct->get_header_by_name(_struct, name.GetStruct());

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::SetHeaderByName(const CefString& name,
                                       const CefString& value,
                                       bool overwrite) {
  auto* _struct = GetStruct();
  if (!_struct->set_header_by_name) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return;
  }
  // Unverified params: value

  // Execute
  _struct->set_header_by_name(_struct, name.GetStruct(), value.GetStruct(),
                              overwrite);
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::Set(const CefString& url,
                           const CefString& method,
                           CefRefPtr<CefPostData> postData,
                           const HeaderMap& headerMap) {
  auto* _struct = GetStruct();
  if (!_struct->set) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: url; type: string_byref_const
  DCHECK(!url.empty());
  if (url.empty()) {
    return;
  }
  // Verify param: method; type: string_byref_const
  DCHECK(!method.empty());
  if (method.empty()) {
    return;
  }
  // Unverified params: postData

  // Translate param: headerMap; type: string_map_multi_byref_const
  cef_string_multimap_t headerMapMultimap = cef_string_multimap_alloc();
  DCHECK(headerMapMultimap);
  if (headerMapMultimap) {
    transfer_string_multimap_contents(headerMap, headerMapMultimap);
  }

  // Execute
  _struct->set(_struct, url.GetStruct(), method.GetStruct(),
               CefPostDataCToCpp_Unwrap(postData), headerMapMultimap);

  // Restore param:headerMap; type: string_map_multi_byref_const
  if (headerMapMultimap) {
    cef_string_multimap_free(headerMapMultimap);
  }
}

NO_SANITIZE("cfi-icall") int CefRequestCToCpp::GetFlags() {
  auto* _struct = GetStruct();
  if (!_struct->get_flags) {
    return UR_FLAG_NONE;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_flags(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void CefRequestCToCpp::SetFlags(int flags) {
  auto* _struct = GetStruct();
  if (!_struct->set_flags) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_flags(_struct, flags);
}

NO_SANITIZE("cfi-icall") CefString CefRequestCToCpp::GetFirstPartyForCookies() {
  auto* _struct = GetStruct();
  if (!_struct->get_first_party_for_cookies) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_first_party_for_cookies(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
void CefRequestCToCpp::SetFirstPartyForCookies(const CefString& url) {
  auto* _struct = GetStruct();
  if (!_struct->set_first_party_for_cookies) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: url

  // Execute
  _struct->set_first_party_for_cookies(_struct, url.GetStruct());
}

NO_SANITIZE("cfi-icall")
CefRequest::ResourceType CefRequestCToCpp::GetResourceType() {
  auto* _struct = GetStruct();
  if (!_struct->get_resource_type) {
    return RT_SUB_RESOURCE;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_resource_type_t _retval = _struct->get_resource_type(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefRequest::TransitionType CefRequestCToCpp::GetTransitionType() {
  auto* _struct = GetStruct();
  if (!_struct->get_transition_type) {
    return TT_EXPLICIT;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_transition_type_t _retval = _struct->get_transition_type(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") uint64_t CefRequestCToCpp::GetIdentifier() {
  auto* _struct = GetStruct();
  if (!_struct->get_identifier) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  uint64_t _retval = _struct->get_identifier(_struct);

  // Return type: simple
  return _retval;
}

// CONSTRUCTOR - Do not edit by hand.

CefRequestCToCpp::CefRequestCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefRequestCToCpp::~CefRequestCToCpp() {}

template <>
cef_request_t*
CefCToCppRefCounted<CefRequestCToCpp, CefRequest, cef_request_t>::UnwrapDerived(
    CefWrapperType type,
    CefRequest* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefRequestCToCpp,
                                   CefRequest,
                                   cef_request_t>::kWrapperType = WT_REQUEST;
