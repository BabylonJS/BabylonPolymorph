/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_BABYLON_SDK_H_INCLUDED)
#define COREUTILS_BABYLON_SDK_H_INCLUDED

#if defined(_USRDLL) && !defined(BABYLON_SDK_API)
#  ifdef BABYLON_SDK_EXPORT
#    define BABYLON_SDK_API __declspec(dllexport)
#  else
#    define BABYLON_SDK_API __declspec(dllimport)
#  endif // BabylonSDK_EXPORT
#else
#  define BABYLON_SDK_API
#endif

#if defined(_M_IX86) && !defined(BABYLON_SDK_CALL)
#  define BABYLON_SDK_CALL __cdecl
#else
#  define BABYLON_SDK_CALL
#endif

/// Deprecated macro for cases where using [[deprecated]] directly doesn't work in old compiler versions.
#if defined(_MSC_VER) && _MSC_VER < 1910
#define BABYLON_DEPRECATED(MESSAGE) __declspec(deprecated(MESSAGE))
#else
#define BABYLON_DEPRECATED(MESSAGE) [[deprecated(MESSAGE)]]
#endif

#endif // COREUTILS_BABYLON_SDK_H_INCLUDED
