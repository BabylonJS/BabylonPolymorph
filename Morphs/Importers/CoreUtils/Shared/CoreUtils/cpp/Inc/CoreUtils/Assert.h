/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
#pragma once

#if !defined(COREUTILS_ASSERT_H_INCLUDED)
#define COREUTILS_ASSERT_H_INCLUDED

#if !defined(_STDEXCEPT_)
#include <stdexcept>
#endif // _STDEXCEPT_

#if !defined(_STRING_)
#include <string>
#endif //_STRING_

//--------------------------------------------------------------------------------

#ifdef _WIN32

#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#define SPECTRE_DEBUG_BREAK()  (!IsDebuggerPresent() ? __fastfail(FAST_FAIL_FATAL_APP_EXIT) : __debugbreak())

#else // _WIN32

#include <signal.h>

// TODO: Each platform should define it's own debug break handler.
// This is the fallback when no other is defined.

#define SPECTRE_DEBUG_BREAK()  ((void)(raise(SIGTRAP)))

#define _STRINGIZEX(x) #x
#define _STRINGIZE(x) _STRINGIZEX(x)

#ifndef __FUNCTION__
#define __FUNCTION__ "unknown"
#endif

#endif // _WIN32

//--------------------------------------------------------------------------------


#if !defined(COREUTILS_SMARTTHROW_H_INCLUDED)
#include <CoreUtils/SmartThrow.h>
#endif // COREUTILS_SMARTTHROW_H_INCLUDED

#if !defined(COREUTILS_SPECTRESDK_H_INCLUDED)
#include <CoreUtils/SpectreSDK.h>
#endif // COREUTILS_SPECTRESDK_H_INCLUDED

#define WLOCATION L"Spectre Assert failed:\n\nFile: " __FILE__ " (line: " _STRINGIZE(__LINE__) ")\nFunction: " __FUNCTION__ "\n"

//--------------------------------------------------------------------------------
typedef void(SPECTRESDK_CALL *SpectreAssertFailHandlerType)(const wchar_t* msg);

extern SpectreAssertFailHandlerType SpectreAssertFailHandler;

#if FEATURE_PREFAST
// In prefast builds we tell prefast that anything which is asserted is assumed true
#define SpectreAssert(x) do {(!!(x) || (__debugbreak(), 0)); __analysis_assume(!!(x));} while(false)
#define SpectreAssertExpr(x, e) do {(!!(x) || (__debugbreak(), 0)); __analysis_assume(!!(x));} while(false)

#elif FEATURE_ASSERTS_ENABLED

#define SpectreAssert(x) (!!(x) || (SpectreAssertFailHandler ? SpectreAssertFailHandler(WLOCATION) : SPECTRE_DEBUG_BREAK(), 0))
#define SpectreAssertExpr(x, e) (!!(x) || (SpectreAssertFailHandler ? SpectreAssertFailHandler(WLOCATION #e) : SPECTRE_DEBUG_BREAK(), 0))

#else

#define SpectreAssert(x)
#define SpectreAssertExpr(x, e)

#endif

// Macros used to eliminate compiler warning generated when formal
// parameters or local variables are not unused in certain builds
// (for example, used for assert conditions in debug, but not used in release).
#if defined(_WIN32) || defined(_WIN64)
#define SpectreUnusedParameter(x) UNREFERENCED_PARAMETER(x)
#define SpectreUnusedLocal(x) DBG_UNREFERENCED_LOCAL_VARIABLE(x)
#else
#define SpectreUnusedParameter(x) (void)x
#define SpectreUnusedLocal(x) (void)x
#endif

//--------------------------------------------------------------------------------

#endif // COREUTILS_ASSERT_H_INCLUDED
