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
// $hash=bc82b4feefceea57bc9c74a194fa50ccbd3ca032$
//

#include "libcef_dll/ctocpp/dictionary_value_ctocpp.h"

#include "libcef_dll/ctocpp/binary_value_ctocpp.h"
#include "libcef_dll/ctocpp/list_value_ctocpp.h"
#include "libcef_dll/ctocpp/value_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"
#include "libcef_dll/transfer_util.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDictionaryValue> CefDictionaryValue::Create() {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_dictionary_value_create();

  // Return type: refptr_same
  return CefDictionaryValueCToCpp_Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool CefDictionaryValueCToCpp::IsValid() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->is_valid) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefDictionaryValueCToCpp::IsOwned() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->is_owned) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_owned(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefDictionaryValueCToCpp::IsReadOnly() {
  shutdown_checker::AssertNotShutdown();

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

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::IsSame(CefRefPtr<CefDictionaryValue> that) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->is_same) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: that; type: refptr_same
  DCHECK(that.get());
  if (!that.get()) {
    return false;
  }

  // Execute
  int _retval =
      _struct->is_same(_struct, CefDictionaryValueCToCpp_Unwrap(that));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::IsEqual(CefRefPtr<CefDictionaryValue> that) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->is_equal) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: that; type: refptr_same
  DCHECK(that.get());
  if (!that.get()) {
    return false;
  }

  // Execute
  int _retval =
      _struct->is_equal(_struct, CefDictionaryValueCToCpp_Unwrap(that));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDictionaryValue> CefDictionaryValueCToCpp::Copy(
    bool exclude_empty_children) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->copy) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->copy(_struct, exclude_empty_children);

  // Return type: refptr_same
  return CefDictionaryValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") size_t CefDictionaryValueCToCpp::GetSize() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_size) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  size_t _retval = _struct->get_size(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") bool CefDictionaryValueCToCpp::Clear() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->clear) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->clear(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::HasKey(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->has_key) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->has_key(_struct, key.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefDictionaryValueCToCpp::GetKeys(KeyList& keys) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_keys) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: keys; type: string_vec_byref
  cef_string_list_t keysList = cef_string_list_alloc();
  DCHECK(keysList);
  if (keysList) {
    transfer_string_list_contents(keys, keysList);
  }

  // Execute
  int _retval = _struct->get_keys(_struct, keysList);

  // Restore param:keys; type: string_vec_byref
  if (keysList) {
    keys.clear();
    transfer_string_list_contents(keysList, keys);
    cef_string_list_free(keysList);
  }

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::Remove(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->remove) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->remove(_struct, key.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefValueType CefDictionaryValueCToCpp::GetType(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_type) {
    return VTYPE_INVALID;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return VTYPE_INVALID;
  }

  // Execute
  cef_value_type_t _retval = _struct->get_type(_struct, key.GetStruct());

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefValue> CefDictionaryValueCToCpp::GetValue(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_value) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return nullptr;
  }

  // Execute
  auto* _retval = _struct->get_value(_struct, key.GetStruct());

  // Return type: refptr_same
  return CefValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::GetBool(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_bool) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->get_bool(_struct, key.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
int CefDictionaryValueCToCpp::GetInt(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_int) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return 0;
  }

  // Execute
  int _retval = _struct->get_int(_struct, key.GetStruct());

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
double CefDictionaryValueCToCpp::GetDouble(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_double) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return 0;
  }

  // Execute
  double _retval = _struct->get_double(_struct, key.GetStruct());

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
CefString CefDictionaryValueCToCpp::GetString(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_string) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return CefString();
  }

  // Execute
  cef_string_userfree_t _retval = _struct->get_string(_struct, key.GetStruct());

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefBinaryValue> CefDictionaryValueCToCpp::GetBinary(
    const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_binary) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return nullptr;
  }

  // Execute
  auto* _retval = _struct->get_binary(_struct, key.GetStruct());

  // Return type: refptr_same
  return CefBinaryValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDictionaryValue> CefDictionaryValueCToCpp::GetDictionary(
    const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_dictionary) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return nullptr;
  }

  // Execute
  auto* _retval = _struct->get_dictionary(_struct, key.GetStruct());

  // Return type: refptr_same
  return CefDictionaryValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefListValue> CefDictionaryValueCToCpp::GetList(
    const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->get_list) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return nullptr;
  }

  // Execute
  auto* _retval = _struct->get_list(_struct, key.GetStruct());

  // Return type: refptr_same
  return CefListValueCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetValue(const CefString& key,
                                        CefRefPtr<CefValue> value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_value) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_value(_struct, key.GetStruct(),
                                   CefValueCToCpp_Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetNull(const CefString& key) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_null) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_null(_struct, key.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetBool(const CefString& key, bool value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_bool) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_bool(_struct, key.GetStruct(), value);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetInt(const CefString& key, int value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_int) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_int(_struct, key.GetStruct(), value);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetDouble(const CefString& key, double value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_double) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_double(_struct, key.GetStruct(), value);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetString(const CefString& key,
                                         const CefString& value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_string) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }
  // Unverified params: value

  // Execute
  int _retval =
      _struct->set_string(_struct, key.GetStruct(), value.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetBinary(const CefString& key,
                                         CefRefPtr<CefBinaryValue> value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_binary) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_binary(_struct, key.GetStruct(),
                                    CefBinaryValueCToCpp_Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetDictionary(
    const CefString& key,
    CefRefPtr<CefDictionaryValue> value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_dictionary) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_dictionary(_struct, key.GetStruct(),
                                        CefDictionaryValueCToCpp_Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefDictionaryValueCToCpp::SetList(const CefString& key,
                                       CefRefPtr<CefListValue> value) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->set_list) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: key; type: string_byref_const
  DCHECK(!key.empty());
  if (key.empty()) {
    return false;
  }
  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->set_list(_struct, key.GetStruct(),
                                  CefListValueCToCpp_Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefDictionaryValueCToCpp::CefDictionaryValueCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefDictionaryValueCToCpp::~CefDictionaryValueCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_dictionary_value_t* CefCToCppRefCounted<
    CefDictionaryValueCToCpp,
    CefDictionaryValue,
    cef_dictionary_value_t>::UnwrapDerived(CefWrapperType type,
                                           CefDictionaryValue* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefDictionaryValueCToCpp,
                                   CefDictionaryValue,
                                   cef_dictionary_value_t>::kWrapperType =
    WT_DICTIONARY_VALUE;
