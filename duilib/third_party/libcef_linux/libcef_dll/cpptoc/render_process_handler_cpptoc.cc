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
// $hash=9d68e272bb2bcb5f4abac0eb741834c0e0714321$
//

#include "libcef_dll/cpptoc/render_process_handler_cpptoc.h"

#include "libcef_dll/cpptoc/load_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/dictionary_value_ctocpp.h"
#include "libcef_dll/ctocpp/domnode_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/ctocpp/process_message_ctocpp.h"
#include "libcef_dll/ctocpp/v8_context_ctocpp.h"
#include "libcef_dll/ctocpp/v8_exception_ctocpp.h"
#include "libcef_dll/ctocpp/v8_stack_trace_ctocpp.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK render_process_handler_on_web_kit_initialized(
    struct _cef_render_process_handler_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }

  // Execute
  CefRenderProcessHandlerCppToC::Get(self)->OnWebKitInitialized();
}

void CEF_CALLBACK render_process_handler_on_browser_created(
    struct _cef_render_process_handler_t* self,
    struct _cef_browser_t* browser,
    struct _cef_dictionary_value_t* extra_info) {
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
  // Unverified params: extra_info

  // Execute
  CefRenderProcessHandlerCppToC::Get(self)->OnBrowserCreated(
      CefBrowserCToCpp_Wrap(browser),
      CefDictionaryValueCToCpp_Wrap(extra_info));
}

void CEF_CALLBACK render_process_handler_on_browser_destroyed(
    struct _cef_render_process_handler_t* self,
    struct _cef_browser_t* browser) {
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
  CefRenderProcessHandlerCppToC::Get(self)->OnBrowserDestroyed(
      CefBrowserCToCpp_Wrap(browser));
}

struct _cef_load_handler_t* CEF_CALLBACK
render_process_handler_get_load_handler(
    struct _cef_render_process_handler_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return NULL;
  }

  // Execute
  CefRefPtr<CefLoadHandler> _retval =
      CefRenderProcessHandlerCppToC::Get(self)->GetLoadHandler();

  // Return type: refptr_same
  return CefLoadHandlerCppToC_Wrap(_retval);
}

void CEF_CALLBACK render_process_handler_on_context_created(
    struct _cef_render_process_handler_t* self,
    struct _cef_browser_t* browser,
    struct _cef_frame_t* frame,
    struct _cef_v8_context_t* context) {
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
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }
  // Verify param: context; type: refptr_diff
  DCHECK(context);
  if (!context) {
    return;
  }

  // Execute
  CefRenderProcessHandlerCppToC::Get(self)->OnContextCreated(
      CefBrowserCToCpp_Wrap(browser), CefFrameCToCpp_Wrap(frame),
      CefV8ContextCToCpp_Wrap(context));
}

void CEF_CALLBACK render_process_handler_on_context_released(
    struct _cef_render_process_handler_t* self,
    struct _cef_browser_t* browser,
    struct _cef_frame_t* frame,
    struct _cef_v8_context_t* context) {
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
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }
  // Verify param: context; type: refptr_diff
  DCHECK(context);
  if (!context) {
    return;
  }

  // Execute
  CefRenderProcessHandlerCppToC::Get(self)->OnContextReleased(
      CefBrowserCToCpp_Wrap(browser), CefFrameCToCpp_Wrap(frame),
      CefV8ContextCToCpp_Wrap(context));
}

void CEF_CALLBACK render_process_handler_on_uncaught_exception(
    struct _cef_render_process_handler_t* self,
    struct _cef_browser_t* browser,
    struct _cef_frame_t* frame,
    struct _cef_v8_context_t* context,
    struct _cef_v8_exception_t* exception,
    struct _cef_v8_stack_trace_t* stackTrace) {
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
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return;
  }
  // Verify param: context; type: refptr_diff
  DCHECK(context);
  if (!context) {
    return;
  }
  // Verify param: exception; type: refptr_diff
  DCHECK(exception);
  if (!exception) {
    return;
  }
  // Verify param: stackTrace; type: refptr_diff
  DCHECK(stackTrace);
  if (!stackTrace) {
    return;
  }

  // Execute
  CefRenderProcessHandlerCppToC::Get(self)->OnUncaughtException(
      CefBrowserCToCpp_Wrap(browser), CefFrameCToCpp_Wrap(frame),
      CefV8ContextCToCpp_Wrap(context), CefV8ExceptionCToCpp_Wrap(exception),
      CefV8StackTraceCToCpp_Wrap(stackTrace));
}

void CEF_CALLBACK render_process_handler_on_focused_node_changed(
    struct _cef_render_process_handler_t* self,
    struct _cef_browser_t* browser,
    struct _cef_frame_t* frame,
    struct _cef_domnode_t* node) {
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
  // Unverified params: frame, node

  // Execute
  CefRenderProcessHandlerCppToC::Get(self)->OnFocusedNodeChanged(
      CefBrowserCToCpp_Wrap(browser), CefFrameCToCpp_Wrap(frame),
      CefDOMNodeCToCpp_Wrap(node));
}

int CEF_CALLBACK render_process_handler_on_process_message_received(
    struct _cef_render_process_handler_t* self,
    struct _cef_browser_t* browser,
    struct _cef_frame_t* frame,
    cef_process_id_t source_process,
    struct _cef_process_message_t* message) {
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
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return 0;
  }
  // Verify param: message; type: refptr_diff
  DCHECK(message);
  if (!message) {
    return 0;
  }

  // Execute
  bool _retval =
      CefRenderProcessHandlerCppToC::Get(self)->OnProcessMessageReceived(
          CefBrowserCToCpp_Wrap(browser), CefFrameCToCpp_Wrap(frame),
          source_process, CefProcessMessageCToCpp_Wrap(message));

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefRenderProcessHandlerCppToC::CefRenderProcessHandlerCppToC() {
  GetStruct()->on_web_kit_initialized =
      render_process_handler_on_web_kit_initialized;
  GetStruct()->on_browser_created = render_process_handler_on_browser_created;
  GetStruct()->on_browser_destroyed =
      render_process_handler_on_browser_destroyed;
  GetStruct()->get_load_handler = render_process_handler_get_load_handler;
  GetStruct()->on_context_created = render_process_handler_on_context_created;
  GetStruct()->on_context_released = render_process_handler_on_context_released;
  GetStruct()->on_uncaught_exception =
      render_process_handler_on_uncaught_exception;
  GetStruct()->on_focused_node_changed =
      render_process_handler_on_focused_node_changed;
  GetStruct()->on_process_message_received =
      render_process_handler_on_process_message_received;
}

// DESTRUCTOR - Do not edit by hand.

CefRenderProcessHandlerCppToC::~CefRenderProcessHandlerCppToC() {}

template <>
CefRefPtr<CefRenderProcessHandler> CefCppToCRefCounted<
    CefRenderProcessHandlerCppToC,
    CefRenderProcessHandler,
    cef_render_process_handler_t>::UnwrapDerived(CefWrapperType type,
                                                 cef_render_process_handler_t*
                                                     s) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefRenderProcessHandlerCppToC,
                                   CefRenderProcessHandler,
                                   cef_render_process_handler_t>::kWrapperType =
    WT_RENDER_PROCESS_HANDLER;
