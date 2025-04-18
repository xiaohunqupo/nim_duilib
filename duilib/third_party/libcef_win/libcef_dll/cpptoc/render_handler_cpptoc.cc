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
// $hash=930d9f127618d8124dd9d8e5611e5fef29e47b72$
//

#include "libcef_dll/cpptoc/render_handler_cpptoc.h"

#include "libcef_dll/cpptoc/accessibility_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/drag_data_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

struct _cef_accessibility_handler_t* CEF_CALLBACK
render_handler_get_accessibility_handler(struct _cef_render_handler_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  CefRefPtr<CefAccessibilityHandler> _retval =
      CefRenderHandlerCppToC::Get(self)->GetAccessibilityHandler();

  // Return type: refptr_same
  return CefAccessibilityHandlerCppToC_Wrap(_retval);
}

int CEF_CALLBACK
render_handler_get_root_screen_rect(struct _cef_render_handler_t* self,
                                    struct _cef_browser_t* browser,
                                    cef_rect_t* rect) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: rect; type: simple_byref
  DCHECK(rect);
  if (!rect) {
    return 0;
  }

  // Translate param: rect; type: simple_byref
  CefRect rectVal = rect ? *rect : CefRect();

  // Execute
  bool _retval = CefRenderHandlerCppToC::Get(self)->GetRootScreenRect(
      CefBrowserCToCpp_Wrap(browser), rectVal);

  // Restore param: rect; type: simple_byref
  if (rect) {
    *rect = rectVal;
  }

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK
render_handler_get_view_rect(struct _cef_render_handler_t* self,
                             struct _cef_browser_t* browser,
                             cef_rect_t* rect) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: rect; type: simple_byref
  DCHECK(rect);
  if (!rect) {
    return;
  }

  // Translate param: rect; type: simple_byref
  CefRect rectVal = rect ? *rect : CefRect();

  // Execute
  CefRenderHandlerCppToC::Get(self)->GetViewRect(CefBrowserCToCpp_Wrap(browser),
                                                 rectVal);

  // Restore param: rect; type: simple_byref
  if (rect) {
    *rect = rectVal;
  }
}

int CEF_CALLBACK
render_handler_get_screen_point(struct _cef_render_handler_t* self,
                                struct _cef_browser_t* browser,
                                int viewX,
                                int viewY,
                                int* screenX,
                                int* screenY) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: screenX; type: simple_byref
  DCHECK(screenX);
  if (!screenX) {
    return 0;
  }
  // Verify param: screenY; type: simple_byref
  DCHECK(screenY);
  if (!screenY) {
    return 0;
  }

  // Translate param: screenX; type: simple_byref
  int screenXVal = screenX ? *screenX : 0;
  // Translate param: screenY; type: simple_byref
  int screenYVal = screenY ? *screenY : 0;

  // Execute
  bool _retval = CefRenderHandlerCppToC::Get(self)->GetScreenPoint(
      CefBrowserCToCpp_Wrap(browser), viewX, viewY, screenXVal, screenYVal);

  // Restore param: screenX; type: simple_byref
  if (screenX) {
    *screenX = screenXVal;
  }
  // Restore param: screenY; type: simple_byref
  if (screenY) {
    *screenY = screenYVal;
  }

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
render_handler_get_screen_info(struct _cef_render_handler_t* self,
                               struct _cef_browser_t* browser,
                               cef_screen_info_t* screen_info) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: screen_info; type: simple_byref
  DCHECK(screen_info);
  if (!screen_info) {
    return 0;
  }

  // Translate param: screen_info; type: simple_byref
  CefScreenInfo screen_infoVal = screen_info ? *screen_info : CefScreenInfo();

  // Execute
  bool _retval = CefRenderHandlerCppToC::Get(self)->GetScreenInfo(
      CefBrowserCToCpp_Wrap(browser), screen_infoVal);

  // Restore param: screen_info; type: simple_byref
  if (screen_info) {
    *screen_info = screen_infoVal;
  }

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK
render_handler_on_popup_show(struct _cef_render_handler_t* self,
                             struct _cef_browser_t* browser,
                             int show) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnPopupShow(CefBrowserCToCpp_Wrap(browser),
                                                 show ? true : false);
}

void CEF_CALLBACK
render_handler_on_popup_size(struct _cef_render_handler_t* self,
                             struct _cef_browser_t* browser,
                             const cef_rect_t* rect) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: rect; type: simple_byref_const
  DCHECK(rect);
  if (!rect) {
    return;
  }

  // Translate param: rect; type: simple_byref_const
  CefRect rectVal = rect ? *rect : CefRect();

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnPopupSize(CefBrowserCToCpp_Wrap(browser),
                                                 rectVal);
}

void CEF_CALLBACK render_handler_on_paint(struct _cef_render_handler_t* self,
                                          struct _cef_browser_t* browser,
                                          cef_paint_element_type_t type,
                                          size_t dirtyRectsCount,
                                          cef_rect_t const* dirtyRects,
                                          const void* buffer,
                                          int width,
                                          int height) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: dirtyRects; type: simple_vec_byref_const
  DCHECK(dirtyRectsCount == 0 || dirtyRects);
  if (dirtyRectsCount > 0 && !dirtyRects) {
    return;
  }
  // Verify param: buffer; type: simple_byaddr
  DCHECK(buffer);
  if (!buffer) {
    return;
  }

  // Translate param: dirtyRects; type: simple_vec_byref_const
  std::vector<CefRect> dirtyRectsList;
  if (dirtyRectsCount > 0) {
    for (size_t i = 0; i < dirtyRectsCount; ++i) {
      CefRect dirtyRectsVal = dirtyRects[i];
      dirtyRectsList.push_back(dirtyRectsVal);
    }
  }

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnPaint(CefBrowserCToCpp_Wrap(browser),
                                             type, dirtyRectsList, buffer,
                                             width, height);
}

void CEF_CALLBACK
render_handler_on_accelerated_paint(struct _cef_render_handler_t* self,
                                    struct _cef_browser_t* browser,
                                    cef_paint_element_type_t type,
                                    size_t dirtyRectsCount,
                                    cef_rect_t const* dirtyRects,
                                    const cef_accelerated_paint_info_t* info) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: dirtyRects; type: simple_vec_byref_const
  DCHECK(dirtyRectsCount == 0 || dirtyRects);
  if (dirtyRectsCount > 0 && !dirtyRects) {
    return;
  }
  // Verify param: info; type: simple_byref_const
  DCHECK(info);
  if (!info) {
    return;
  }

  // Translate param: dirtyRects; type: simple_vec_byref_const
  std::vector<CefRect> dirtyRectsList;
  if (dirtyRectsCount > 0) {
    for (size_t i = 0; i < dirtyRectsCount; ++i) {
      CefRect dirtyRectsVal = dirtyRects[i];
      dirtyRectsList.push_back(dirtyRectsVal);
    }
  }
  // Translate param: info; type: simple_byref_const
  CefAcceleratedPaintInfo infoVal = info ? *info : CefAcceleratedPaintInfo();

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnAcceleratedPaint(
      CefBrowserCToCpp_Wrap(browser), type, dirtyRectsList, infoVal);
}

void CEF_CALLBACK
render_handler_get_touch_handle_size(struct _cef_render_handler_t* self,
                                     struct _cef_browser_t* browser,
                                     cef_horizontal_alignment_t orientation,
                                     cef_size_t* size) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: size; type: simple_byref
  DCHECK(size);
  if (!size) {
    return;
  }

  // Translate param: size; type: simple_byref
  CefSize sizeVal = size ? *size : CefSize();

  // Execute
  CefRenderHandlerCppToC::Get(self)->GetTouchHandleSize(
      CefBrowserCToCpp_Wrap(browser), orientation, sizeVal);

  // Restore param: size; type: simple_byref
  if (size) {
    *size = sizeVal;
  }
}

void CEF_CALLBACK render_handler_on_touch_handle_state_changed(
    struct _cef_render_handler_t* self,
    struct _cef_browser_t* browser,
    const cef_touch_handle_state_t* state) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: state; type: simple_byref_const
  DCHECK(state);
  if (!state) {
    return;
  }

  // Translate param: state; type: simple_byref_const
  CefTouchHandleState stateVal = state ? *state : CefTouchHandleState();

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnTouchHandleStateChanged(
      CefBrowserCToCpp_Wrap(browser), stateVal);
}

int CEF_CALLBACK
render_handler_start_dragging(struct _cef_render_handler_t* self,
                              struct _cef_browser_t* browser,
                              struct _cef_drag_data_t* drag_data,
                              cef_drag_operations_mask_t allowed_ops,
                              int x,
                              int y) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: drag_data; type: refptr_diff
  DCHECK(drag_data);
  if (!drag_data) {
    return 0;
  }

  // Execute
  bool _retval = CefRenderHandlerCppToC::Get(self)->StartDragging(
      CefBrowserCToCpp_Wrap(browser), CefDragDataCToCpp_Wrap(drag_data),
      allowed_ops, x, y);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK
render_handler_update_drag_cursor(struct _cef_render_handler_t* self,
                                  struct _cef_browser_t* browser,
                                  cef_drag_operations_mask_t operation) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  CefRenderHandlerCppToC::Get(self)->UpdateDragCursor(
      CefBrowserCToCpp_Wrap(browser), operation);
}

void CEF_CALLBACK
render_handler_on_scroll_offset_changed(struct _cef_render_handler_t* self,
                                        struct _cef_browser_t* browser,
                                        double x,
                                        double y) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnScrollOffsetChanged(
      CefBrowserCToCpp_Wrap(browser), x, y);
}

void CEF_CALLBACK render_handler_on_ime_composition_range_changed(
    struct _cef_render_handler_t* self,
    struct _cef_browser_t* browser,
    const cef_range_t* selected_range,
    size_t character_boundsCount,
    cef_rect_t const* character_bounds) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Verify param: selected_range; type: simple_byref_const
  DCHECK(selected_range);
  if (!selected_range) {
    return;
  }
  // Verify param: character_bounds; type: simple_vec_byref_const
  DCHECK(character_boundsCount == 0 || character_bounds);
  if (character_boundsCount > 0 && !character_bounds) {
    return;
  }

  // Translate param: selected_range; type: simple_byref_const
  CefRange selected_rangeVal = selected_range ? *selected_range : CefRange();
  // Translate param: character_bounds; type: simple_vec_byref_const
  std::vector<CefRect> character_boundsList;
  if (character_boundsCount > 0) {
    for (size_t i = 0; i < character_boundsCount; ++i) {
      CefRect character_boundsVal = character_bounds[i];
      character_boundsList.push_back(character_boundsVal);
    }
  }

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnImeCompositionRangeChanged(
      CefBrowserCToCpp_Wrap(browser), selected_rangeVal, character_boundsList);
}

void CEF_CALLBACK
render_handler_on_text_selection_changed(struct _cef_render_handler_t* self,
                                         struct _cef_browser_t* browser,
                                         const cef_string_t* selected_text,
                                         const cef_range_t* selected_range) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }
  // Unverified params: selected_text, selected_range

  // Translate param: selected_range; type: simple_byref_const
  CefRange selected_rangeVal = selected_range ? *selected_range : CefRange();

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnTextSelectionChanged(
      CefBrowserCToCpp_Wrap(browser), CefString(selected_text),
      selected_rangeVal);
}

void CEF_CALLBACK
render_handler_on_virtual_keyboard_requested(struct _cef_render_handler_t* self,
                                             struct _cef_browser_t* browser,
                                             cef_text_input_mode_t input_mode) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  CefRenderHandlerCppToC::Get(self)->OnVirtualKeyboardRequested(
      CefBrowserCToCpp_Wrap(browser), input_mode);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefRenderHandlerCppToC::CefRenderHandlerCppToC() {
  GetStruct()->get_accessibility_handler =
      render_handler_get_accessibility_handler;
  GetStruct()->get_root_screen_rect = render_handler_get_root_screen_rect;
  GetStruct()->get_view_rect = render_handler_get_view_rect;
  GetStruct()->get_screen_point = render_handler_get_screen_point;
  GetStruct()->get_screen_info = render_handler_get_screen_info;
  GetStruct()->on_popup_show = render_handler_on_popup_show;
  GetStruct()->on_popup_size = render_handler_on_popup_size;
  GetStruct()->on_paint = render_handler_on_paint;
  GetStruct()->on_accelerated_paint = render_handler_on_accelerated_paint;
  GetStruct()->get_touch_handle_size = render_handler_get_touch_handle_size;
  GetStruct()->on_touch_handle_state_changed =
      render_handler_on_touch_handle_state_changed;
  GetStruct()->start_dragging = render_handler_start_dragging;
  GetStruct()->update_drag_cursor = render_handler_update_drag_cursor;
  GetStruct()->on_scroll_offset_changed =
      render_handler_on_scroll_offset_changed;
  GetStruct()->on_ime_composition_range_changed =
      render_handler_on_ime_composition_range_changed;
  GetStruct()->on_text_selection_changed =
      render_handler_on_text_selection_changed;
  GetStruct()->on_virtual_keyboard_requested =
      render_handler_on_virtual_keyboard_requested;
}

// DESTRUCTOR - Do not edit by hand.

CefRenderHandlerCppToC::~CefRenderHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefRenderHandler> CefCppToCRefCounted<
    CefRenderHandlerCppToC,
    CefRenderHandler,
    cef_render_handler_t>::UnwrapDerived(CefWrapperType type,
                                         cef_render_handler_t* s) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefRenderHandlerCppToC,
                                   CefRenderHandler,
                                   cef_render_handler_t>::kWrapperType =
    WT_RENDER_HANDLER;
