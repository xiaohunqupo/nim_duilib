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
// $hash=f4c3f9fc2e723828c6b7289554c3527f005da603$
//

#include "libcef_dll/ctocpp/test/api_version_test_scoped_library_child_child_v2_ctocpp.h"

#if CEF_API_ADDED(13302)

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefOwnPtr<
    CefApiVersionTestScopedLibraryChildChildV2> CefApiVersionTestScopedLibraryChildChildV2::
    Create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval = cef_api_version_test_scoped_library_child_child_v2_create();

  // Return type: ownptr_same
  return CefApiVersionTestScopedLibraryChildChildV2CToCpp_Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefOwnPtr<
    CefApiVersionTestScopedLibraryChildChildV2> CefApiVersionTestScopedLibraryChildChildV2::
    Create(int value, int other_value, int other_other_value) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  auto* _retval =
      cef_api_version_test_scoped_library_child_child_v2_create_with_default(
          value, other_value, other_other_value);

  // Return type: ownptr_same
  return CefApiVersionTestScopedLibraryChildChildV2CToCpp_Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
int CefApiVersionTestScopedLibraryChildChildV2CToCpp::GetOtherOtherValue() {
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
void CefApiVersionTestScopedLibraryChildChildV2CToCpp::SetOtherOtherValue(
    int value) {
  auto* _struct = GetStruct();
  if (!_struct->set_other_other_value) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_other_other_value(_struct, value);
}

NO_SANITIZE("cfi-icall")
int CefApiVersionTestScopedLibraryChildChildV2CToCpp::GetOtherValue() {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_child_t*>(
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
void CefApiVersionTestScopedLibraryChildChildV2CToCpp::SetOtherValue(
    int value) {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_child_t*>(
          GetStruct());
  if (!_struct->set_other_value) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_other_value(_struct, value);
}

NO_SANITIZE("cfi-icall")
int CefApiVersionTestScopedLibraryChildChildV2CToCpp::GetValueLegacy() {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
void CefApiVersionTestScopedLibraryChildChildV2CToCpp::SetValueLegacy(
    int value) {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
  if (!_struct->set_value_legacy) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value_legacy(_struct, value);
}

#if CEF_API_ADDED(CEF_EXPERIMENTAL)
NO_SANITIZE("cfi-icall")
int CefApiVersionTestScopedLibraryChildChildV2CToCpp::GetValueExp() {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
void CefApiVersionTestScopedLibraryChildChildV2CToCpp::SetValueExp(int value) {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
int CefApiVersionTestScopedLibraryChildChildV2CToCpp::GetValue() {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
void CefApiVersionTestScopedLibraryChildChildV2CToCpp::SetValue(int value) {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
int CefApiVersionTestScopedLibraryChildChildV2CToCpp::GetValueV1() {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
void CefApiVersionTestScopedLibraryChildChildV2CToCpp::SetValueV1(int value) {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
int CefApiVersionTestScopedLibraryChildChildV2CToCpp::GetValueV2() {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
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
void CefApiVersionTestScopedLibraryChildChildV2CToCpp::SetValueV2(int value) {
  auto* _struct =
      reinterpret_cast<cef_api_version_test_scoped_library_t*>(GetStruct());
  if (!_struct->set_value_v2) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->set_value_v2(_struct, value);
}
#endif  // CEF_API_ADDED(13302)

// CONSTRUCTOR - Do not edit by hand.

CefApiVersionTestScopedLibraryChildChildV2CToCpp::
    CefApiVersionTestScopedLibraryChildChildV2CToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefApiVersionTestScopedLibraryChildChildV2CToCpp::
    ~CefApiVersionTestScopedLibraryChildChildV2CToCpp() {}

template <>
cef_api_version_test_scoped_library_child_child_v2_t*
CefCToCppScoped<CefApiVersionTestScopedLibraryChildChildV2CToCpp,
                CefApiVersionTestScopedLibraryChildChildV2,
                cef_api_version_test_scoped_library_child_child_v2_t>::
    UnwrapDerivedOwn(CefWrapperType type,
                     CefOwnPtr<CefApiVersionTestScopedLibraryChildChildV2> c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
cef_api_version_test_scoped_library_child_child_v2_t*
CefCToCppScoped<CefApiVersionTestScopedLibraryChildChildV2CToCpp,
                CefApiVersionTestScopedLibraryChildChildV2,
                cef_api_version_test_scoped_library_child_child_v2_t>::
    UnwrapDerivedRaw(CefWrapperType type,
                     CefRawPtr<CefApiVersionTestScopedLibraryChildChildV2> c) {
  CHECK(false) << __func__ << " called with unexpected class type " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppScoped<
    CefApiVersionTestScopedLibraryChildChildV2CToCpp,
    CefApiVersionTestScopedLibraryChildChildV2,
    cef_api_version_test_scoped_library_child_child_v2_t>::kWrapperType =
    WT_API_VERSION_TEST_SCOPED_LIBRARY_CHILD_CHILD_V2;

#endif  // CEF_API_ADDED(13302)
