/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_SPECTRESDK_H_INCLUDED)
#define COREUTILS_SPECTRESDK_H_INCLUDED

#if defined(_USRDLL) && !defined(SPECTRESDK_API)
#  ifdef SPECTRESDK_EXPORT
#    define SPECTRESDK_API __declspec(dllexport)
#  else
#    define SPECTRESDK_API __declspec(dllimport)
#  endif // SPECTRESDK_EXPORT
#else
#  define SPECTRESDK_API
#endif

#if defined(_M_IX86) && !defined(SPECTRESDK_CALL)
#  define SPECTRESDK_CALL __cdecl
#else
#  define SPECTRESDK_CALL
#endif

/// Deprecated macro for cases where using [[deprecated]] directly doesn't work in old compiler versions.
#if defined(_MSC_VER) && _MSC_VER < 1910
#define SPECTRE_DEPRECATED(MESSAGE) __declspec(deprecated(MESSAGE))
#else
#define SPECTRE_DEPRECATED(MESSAGE) [[deprecated(MESSAGE)]]
#endif

#endif // COREUTILS_SPECTRESDK_H_INCLUDED
