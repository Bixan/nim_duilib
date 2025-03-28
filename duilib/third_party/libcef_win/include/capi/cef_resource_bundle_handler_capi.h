// Copyright (c) 2025 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=7943ef07f085554227d0f3c42eaa0af46865d06e$
//

#ifndef CEF_INCLUDE_CAPI_CEF_RESOURCE_BUNDLE_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_RESOURCE_BUNDLE_HANDLER_CAPI_H_
#pragma once

#if defined(BUILDING_CEF_SHARED)
#error This file cannot be included DLL-side
#endif

#include "include/capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
/// Structure used to implement a custom resource bundle structure. See
/// CefSettings for additional options related to resource bundle loading. The
/// functions of this structure may be called on multiple threads.
///
/// NOTE: This struct is allocated client-side.
///
typedef struct _cef_resource_bundle_handler_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Called to retrieve a localized translation for the specified |string_id|.
  /// To provide the translation set |string| to the translation string and
  /// return true (1). To use the default translation return false (0). Use the
  /// cef_id_for_pack_string_name() function for version-safe mapping of string
  /// IDS names from cef_pack_strings.h to version-specific numerical
  /// |string_id| values.
  ///
  int(CEF_CALLBACK* get_localized_string)(
      struct _cef_resource_bundle_handler_t* self,
      int string_id,
      cef_string_t* string);

  ///
  /// Called to retrieve data for the specified scale independent |resource_id|.
  /// To provide the resource data set |data| and |data_size| to the data
  /// pointer and size respectively and return true (1). To use the default
  /// resource data return false (0). The resource data will not be copied and
  /// must remain resident in memory. Use the cef_id_for_pack_resource_name()
  /// function for version-safe mapping of resource IDR names from
  /// cef_pack_resources.h to version-specific numerical |resource_id| values.
  ///
  int(CEF_CALLBACK* get_data_resource)(
      struct _cef_resource_bundle_handler_t* self,
      int resource_id,
      void** data,
      size_t* data_size);

  ///
  /// Called to retrieve data for the specified |resource_id| nearest the scale
  /// factor |scale_factor|. To provide the resource data set |data| and
  /// |data_size| to the data pointer and size respectively and return true (1).
  /// To use the default resource data return false (0). The resource data will
  /// not be copied and must remain resident in memory. Use the
  /// cef_id_for_pack_resource_name() function for version-safe mapping of
  /// resource IDR names from cef_pack_resources.h to version-specific numerical
  /// |resource_id| values.
  ///
  int(CEF_CALLBACK* get_data_resource_for_scale)(
      struct _cef_resource_bundle_handler_t* self,
      int resource_id,
      cef_scale_factor_t scale_factor,
      void** data,
      size_t* data_size);
} cef_resource_bundle_handler_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_RESOURCE_BUNDLE_HANDLER_CAPI_H_
