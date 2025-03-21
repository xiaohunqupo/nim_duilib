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
// $hash=8affe6fef8fae243a33a4d30f20cc7a7f2be50d0$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_TEST_API_VERSION_TEST_SCOPED_CLIENT_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_TEST_API_VERSION_TEST_SCOPED_CLIENT_CPPTOC_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/test/cef_api_version_test_capi.h"
#include "include/test/cef_api_version_test.h"
#include "libcef_dll/cpptoc/cpptoc_scoped.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed wrapper-side only.
class CefApiVersionTestScopedClientCppToC
    : public CefCppToCScoped<CefApiVersionTestScopedClientCppToC,
                             CefApiVersionTestScopedClient,
                             cef_api_version_test_scoped_client_t> {
 public:
  CefApiVersionTestScopedClientCppToC();
  virtual ~CefApiVersionTestScopedClientCppToC();
};

constexpr auto CefApiVersionTestScopedClientCppToC_WrapOwn =
    CefApiVersionTestScopedClientCppToC::WrapOwn;
constexpr auto CefApiVersionTestScopedClientCppToC_WrapRaw =
    CefApiVersionTestScopedClientCppToC::WrapRaw;
constexpr auto CefApiVersionTestScopedClientCppToC_UnwrapOwn =
    CefApiVersionTestScopedClientCppToC::UnwrapOwn;
constexpr auto CefApiVersionTestScopedClientCppToC_UnwrapRaw =
    CefApiVersionTestScopedClientCppToC::UnwrapRaw;
constexpr auto CefApiVersionTestScopedClientCppToC_GetWrapper =
    CefApiVersionTestScopedClientCppToC::GetWrapper;

inline cef_api_version_test_scoped_client_t*
CefApiVersionTestScopedClientCppToC_WrapRawAndRelease(
    CefRawPtr<CefApiVersionTestScopedClient> c) {
  auto [ownerPtr, structPtr] = CefApiVersionTestScopedClientCppToC_WrapRaw(c);
  ownerPtr.release();
  return structPtr;
}

#endif  // CEF_LIBCEF_DLL_CPPTOC_TEST_API_VERSION_TEST_SCOPED_CLIENT_CPPTOC_H_
