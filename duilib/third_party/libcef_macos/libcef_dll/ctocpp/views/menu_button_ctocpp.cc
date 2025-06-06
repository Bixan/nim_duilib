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
// $hash=56910f72a9867ae4217731c8c925cd416004efe8$
//

#include "libcef_dll/ctocpp/views/menu_button_ctocpp.h"

#include "libcef_dll/cpptoc/views/menu_button_delegate_cpptoc.h"
#include "libcef_dll/cpptoc/views/view_delegate_cpptoc.h"
#include "libcef_dll/ctocpp/image_ctocpp.h"
#include "libcef_dll/ctocpp/menu_model_ctocpp.h"
#include "libcef_dll/ctocpp/views/browser_view_ctocpp.h"
#include "libcef_dll/ctocpp/views/button_ctocpp.h"
#include "libcef_dll/ctocpp/views/label_button_ctocpp.h"
#include "libcef_dll/ctocpp/views/panel_ctocpp.h"
#include "libcef_dll/ctocpp/views/scroll_view_ctocpp.h"
#include "libcef_dll/ctocpp/views/textfield_ctocpp.h"
#include "libcef_dll/ctocpp/views/view_ctocpp.h"
#include "libcef_dll/ctocpp/views/window_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefMenuButton> CefMenuButton::CreateMenuButton(
    CefRefPtr<CefMenuButtonDelegate> delegate,
    const CefString& text) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: delegate; type: refptr_diff
  DCHECK(delegate.get());
  if (!delegate.get()) {
    return nullptr;
  }
  // Unverified params: text

  // Execute
  auto* _retval = cef_menu_button_create(
      CefMenuButtonDelegateCppToC_Wrap(delegate), text.GetStruct());

  // Return type: refptr_same
  return CefMenuButtonCToCpp_Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::ShowMenu(CefRefPtr<CefMenuModel> menu_model,
                                   const CefPoint& screen_point,
                                   cef_menu_anchor_position_t anchor_position) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->show_menu) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: menu_model; type: refptr_same
  DCHECK(menu_model.get());
  if (!menu_model.get()) {
    return;
  }

  // Execute
  _struct->show_menu(_struct, CefMenuModelCToCpp_Unwrap(menu_model),
                     &screen_point, anchor_position);
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::TriggerMenu() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = GetStruct();
  if (!_struct->trigger_menu) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->trigger_menu(_struct);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefMenuButton> CefMenuButtonCToCpp::AsMenuButton() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->as_menu_button) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->as_menu_button(_struct);

  // Return type: refptr_same
  return CefMenuButtonCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetText(const CefString& text) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_text) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: text; type: string_byref_const
  DCHECK(!text.empty());
  if (text.empty()) {
    return;
  }

  // Execute
  _struct->set_text(_struct, text.GetStruct());
}

NO_SANITIZE("cfi-icall") CefString CefMenuButtonCToCpp::GetText() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->get_text) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_text(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetImage(cef_button_state_t button_state,
                                   CefRefPtr<CefImage> image) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_image) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: image

  // Execute
  _struct->set_image(_struct, button_state, CefImageCToCpp_Unwrap(image));
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefImage> CefMenuButtonCToCpp::GetImage(
    cef_button_state_t button_state) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->get_image) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_image(_struct, button_state);

  // Return type: refptr_same
  return CefImageCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetTextColor(cef_button_state_t for_state,
                                       cef_color_t color) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_text_color) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_text_color(_struct, for_state, color);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetEnabledTextColors(cef_color_t color) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_enabled_text_colors) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_enabled_text_colors(_struct, color);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetFontList(const CefString& font_list) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_font_list) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: font_list; type: string_byref_const
  DCHECK(!font_list.empty());
  if (font_list.empty()) {
    return;
  }

  // Execute
  _struct->set_font_list(_struct, font_list.GetStruct());
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetHorizontalAlignment(
    cef_horizontal_alignment_t alignment) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_horizontal_alignment) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_horizontal_alignment(_struct, alignment);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetMinimumSize(const CefSize& size) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_minimum_size) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_minimum_size(_struct, &size);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetMaximumSize(const CefSize& size) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_label_button_t*>(GetStruct());
  if (!_struct->set_maximum_size) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_maximum_size(_struct, &size);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefLabelButton> CefMenuButtonCToCpp::AsLabelButton() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_button_t*>(GetStruct());
  if (!_struct->as_label_button) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->as_label_button(_struct);

  // Return type: refptr_same
  return CefLabelButtonCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetState(cef_button_state_t state) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_button_t*>(GetStruct());
  if (!_struct->set_state) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_state(_struct, state);
}

NO_SANITIZE("cfi-icall") cef_button_state_t CefMenuButtonCToCpp::GetState() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_button_t*>(GetStruct());
  if (!_struct->get_state) {
    return CEF_BUTTON_STATE_NORMAL;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_button_state_t _retval = _struct->get_state(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetInkDropEnabled(bool enabled) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_button_t*>(GetStruct());
  if (!_struct->set_ink_drop_enabled) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_ink_drop_enabled(_struct, enabled);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetTooltipText(const CefString& tooltip_text) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_button_t*>(GetStruct());
  if (!_struct->set_tooltip_text) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: tooltip_text; type: string_byref_const
  DCHECK(!tooltip_text.empty());
  if (tooltip_text.empty()) {
    return;
  }

  // Execute
  _struct->set_tooltip_text(_struct, tooltip_text.GetStruct());
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetAccessibleName(const CefString& name) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_button_t*>(GetStruct());
  if (!_struct->set_accessible_name) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty()) {
    return;
  }

  // Execute
  _struct->set_accessible_name(_struct, name.GetStruct());
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefBrowserView> CefMenuButtonCToCpp::AsBrowserView() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->as_browser_view) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->as_browser_view(_struct);

  // Return type: refptr_same
  return CefBrowserViewCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefButton> CefMenuButtonCToCpp::AsButton() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->as_button) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->as_button(_struct);

  // Return type: refptr_same
  return CefButtonCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefPanel> CefMenuButtonCToCpp::AsPanel() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->as_panel) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->as_panel(_struct);

  // Return type: refptr_same
  return CefPanelCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefScrollView> CefMenuButtonCToCpp::AsScrollView() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->as_scroll_view) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->as_scroll_view(_struct);

  // Return type: refptr_same
  return CefScrollViewCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefTextfield> CefMenuButtonCToCpp::AsTextfield() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->as_textfield) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->as_textfield(_struct);

  // Return type: refptr_same
  return CefTextfieldCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") CefString CefMenuButtonCToCpp::GetTypeString() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_type_string) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_type_string(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
CefString CefMenuButtonCToCpp::ToString(bool include_children) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->to_string) {
    return CefString();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->to_string(_struct, include_children);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::IsValid() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->is_valid) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::IsAttached() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->is_attached) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_attached(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefMenuButtonCToCpp::IsSame(CefRefPtr<CefView> that) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
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
  int _retval = _struct->is_same(_struct, CefViewCToCpp_Unwrap(that));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefViewDelegate> CefMenuButtonCToCpp::GetDelegate() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_delegate) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_delegate(_struct);

  // Return type: refptr_diff
  return CefViewDelegateCppToC_Unwrap(_retval);
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefWindow> CefMenuButtonCToCpp::GetWindow() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_window) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_window(_struct);

  // Return type: refptr_same
  return CefWindowCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall") int CefMenuButtonCToCpp::GetID() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_id) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_id(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::SetID(int id) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_id) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_id(_struct, id);
}

NO_SANITIZE("cfi-icall") int CefMenuButtonCToCpp::GetGroupID() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_group_id) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_group_id(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::SetGroupID(int group_id) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_group_id) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_group_id(_struct, group_id);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefView> CefMenuButtonCToCpp::GetParentView() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_parent_view) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_parent_view(_struct);

  // Return type: refptr_same
  return CefViewCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefView> CefMenuButtonCToCpp::GetViewForID(int id) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_view_for_id) {
    return nullptr;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = _struct->get_view_for_id(_struct, id);

  // Return type: refptr_same
  return CefViewCToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetBounds(const CefRect& bounds) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_bounds) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_bounds(_struct, &bounds);
}

NO_SANITIZE("cfi-icall") CefRect CefMenuButtonCToCpp::GetBounds() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_bounds) {
    return CefRect();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_rect_t _retval = _struct->get_bounds(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") CefRect CefMenuButtonCToCpp::GetBoundsInScreen() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_bounds_in_screen) {
    return CefRect();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_rect_t _retval = _struct->get_bounds_in_screen(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetSize(const CefSize& size) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_size) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_size(_struct, &size);
}

NO_SANITIZE("cfi-icall") CefSize CefMenuButtonCToCpp::GetSize() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_size) {
    return CefSize();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_size_t _retval = _struct->get_size(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetPosition(const CefPoint& position) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_position) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_position(_struct, &position);
}

NO_SANITIZE("cfi-icall") CefPoint CefMenuButtonCToCpp::GetPosition() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_position) {
    return CefPoint();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_point_t _retval = _struct->get_position(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetInsets(const CefInsets& insets) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_insets) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_insets(_struct, &insets);
}

NO_SANITIZE("cfi-icall") CefInsets CefMenuButtonCToCpp::GetInsets() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_insets) {
    return CefInsets();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_insets_t _retval = _struct->get_insets(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") CefSize CefMenuButtonCToCpp::GetPreferredSize() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_preferred_size) {
    return CefSize();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_size_t _retval = _struct->get_preferred_size(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::SizeToPreferredSize() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->size_to_preferred_size) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->size_to_preferred_size(_struct);
}

NO_SANITIZE("cfi-icall") CefSize CefMenuButtonCToCpp::GetMinimumSize() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_minimum_size) {
    return CefSize();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_size_t _retval = _struct->get_minimum_size(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") CefSize CefMenuButtonCToCpp::GetMaximumSize() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_maximum_size) {
    return CefSize();
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_size_t _retval = _struct->get_maximum_size(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefMenuButtonCToCpp::GetHeightForWidth(int width) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_height_for_width) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_height_for_width(_struct, width);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::InvalidateLayout() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->invalidate_layout) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->invalidate_layout(_struct);
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::SetVisible(bool visible) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_visible) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_visible(_struct, visible);
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::IsVisible() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->is_visible) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_visible(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::IsDrawn() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->is_drawn) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_drawn(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::SetEnabled(bool enabled) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_enabled) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_enabled(_struct, enabled);
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::IsEnabled() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->is_enabled) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_enabled(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetFocusable(bool focusable) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_focusable) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_focusable(_struct, focusable);
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::IsFocusable() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->is_focusable) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_focusable(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::IsAccessibilityFocusable() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->is_accessibility_focusable) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_accessibility_focusable(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefMenuButtonCToCpp::HasFocus() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->has_focus) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->has_focus(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") void CefMenuButtonCToCpp::RequestFocus() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->request_focus) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->request_focus(_struct);
}

NO_SANITIZE("cfi-icall")
void CefMenuButtonCToCpp::SetBackgroundColor(cef_color_t color) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->set_background_color) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_background_color(_struct, color);
}

NO_SANITIZE("cfi-icall") cef_color_t CefMenuButtonCToCpp::GetBackgroundColor() {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_background_color) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_color_t _retval = _struct->get_background_color(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
cef_color_t CefMenuButtonCToCpp::GetThemeColor(int color_id) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->get_theme_color) {
    return 0;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_color_t _retval = _struct->get_theme_color(_struct, color_id);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
bool CefMenuButtonCToCpp::ConvertPointToScreen(CefPoint& point) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->convert_point_to_screen) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->convert_point_to_screen(_struct, &point);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefMenuButtonCToCpp::ConvertPointFromScreen(CefPoint& point) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->convert_point_from_screen) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->convert_point_from_screen(_struct, &point);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefMenuButtonCToCpp::ConvertPointToWindow(CefPoint& point) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->convert_point_to_window) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->convert_point_to_window(_struct, &point);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefMenuButtonCToCpp::ConvertPointFromWindow(CefPoint& point) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->convert_point_from_window) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->convert_point_from_window(_struct, &point);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefMenuButtonCToCpp::ConvertPointToView(CefRefPtr<CefView> view,
                                             CefPoint& point) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->convert_point_to_view) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_same
  DCHECK(view.get());
  if (!view.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->convert_point_to_view(
      _struct, CefViewCToCpp_Unwrap(view), &point);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefMenuButtonCToCpp::ConvertPointFromView(CefRefPtr<CefView> view,
                                               CefPoint& point) {
  shutdown_checker::AssertNotShutdown();

  auto* _struct = reinterpret_cast<cef_view_t*>(GetStruct());
  if (!_struct->convert_point_from_view) {
    return false;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_same
  DCHECK(view.get());
  if (!view.get()) {
    return false;
  }

  // Execute
  int _retval = _struct->convert_point_from_view(
      _struct, CefViewCToCpp_Unwrap(view), &point);

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefMenuButtonCToCpp::CefMenuButtonCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefMenuButtonCToCpp::~CefMenuButtonCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_menu_button_t*
CefCToCppRefCounted<CefMenuButtonCToCpp, CefMenuButton, cef_menu_button_t>::
    UnwrapDerived(CefWrapperType type, CefMenuButton* c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefMenuButtonCToCpp,
                                   CefMenuButton,
                                   cef_menu_button_t>::kWrapperType =
    WT_MENU_BUTTON;
