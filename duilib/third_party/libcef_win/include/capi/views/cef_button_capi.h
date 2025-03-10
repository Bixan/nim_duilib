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
// $hash=3805078d9fe45a053beba9252aab563c90f01972$
//

#ifndef CEF_INCLUDE_CAPI_VIEWS_CEF_BUTTON_CAPI_H_
#define CEF_INCLUDE_CAPI_VIEWS_CEF_BUTTON_CAPI_H_
#pragma once

#if defined(BUILDING_CEF_SHARED)
#error This file cannot be included DLL-side
#endif

#include "include/capi/views/cef_view_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_label_button_t;

///
/// A View representing a button. Depending on the specific type, the button
/// could be implemented by a native control or custom rendered. Methods must be
/// called on the browser process UI thread unless otherwise indicated.
///
/// NOTE: This struct is allocated DLL-side.
///
typedef struct _cef_button_t {
  ///
  /// Base structure.
  ///
  cef_view_t base;

  ///
  /// Returns this Button as a LabelButton or NULL if this is not a LabelButton.
  ///
  struct _cef_label_button_t*(CEF_CALLBACK* as_label_button)(
      struct _cef_button_t* self);

  ///
  /// Sets the current display state of the Button.
  ///
  void(CEF_CALLBACK* set_state)(struct _cef_button_t* self,
                                cef_button_state_t state);

  ///
  /// Returns the current display state of the Button.
  ///
  cef_button_state_t(CEF_CALLBACK* get_state)(struct _cef_button_t* self);

  ///
  /// Sets the Button will use an ink drop effect for displaying state changes.
  ///
  void(CEF_CALLBACK* set_ink_drop_enabled)(struct _cef_button_t* self,
                                           int enabled);

  ///
  /// Sets the tooltip text that will be displayed when the user hovers the
  /// mouse cursor over the Button.
  ///
  void(CEF_CALLBACK* set_tooltip_text)(struct _cef_button_t* self,
                                       const cef_string_t* tooltip_text);

  ///
  /// Sets the accessible name that will be exposed to assistive technology
  /// (AT).
  ///
  void(CEF_CALLBACK* set_accessible_name)(struct _cef_button_t* self,
                                          const cef_string_t* name);
} cef_button_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_VIEWS_CEF_BUTTON_CAPI_H_
