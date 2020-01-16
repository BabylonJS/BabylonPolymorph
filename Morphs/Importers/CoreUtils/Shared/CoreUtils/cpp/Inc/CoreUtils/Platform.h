/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

// Define some useful macros to distinguish between different platform variants
// NOTE: To reduce mistakes  these values are defined as functions so they
// must be called as CANVAS_PLATFORM_IS_X().  Any usage of these
// functions before Platform.h is included will generate an error if the () syntax is used.
// If we just defined static macro values then some compilers will not fail if they are undefined
// DO NOT use these with #ifdef as they will always be defined
//
// CANVAS_PLATFORM_IS_APPLE()              - Returns 1 on IOS or MacOS
//    CANVAS_PLATFORM_IS_IOS()             - Returns 1 on IOS
//    CANVAS_PLATFORM_IS_MACOS()           - Returns 1 on MacOS
//
// CANVAS_PLATFORM_IS_WINDOWS()            - Returns 1 on Windows platforms.
//    CANVAS_PLATFORM_IS_WIN32()           - Returns 1 on Windows Win32 builds
//        CANVAS_PLATFORM_IS_WIN32_ARM64() - Returns 1 on Windows Win32 ARM64 builds
//        CANVAS_PLATFORM_IS_WIN32_X64()   - Returns 1 on Windows Win32 x64 builds
//    CANVAS_PLATFORM_IS_WINRT()           - Returns 1 on Windows WinRT/UWP builds

// CANVAS_PLATFORM_IS_ANDROID()            - Returns 1 on Android platforms.
//
// Example:
//
// #if CANVAS_PLATFORM_IS_IOS()
//     ... Insert IOS-Specific code here ...
// #endif
//

#if defined(__APPLE__)
#   define CANVAS_PLATFORM_IS_APPLE() 1
#   define CANVAS_PLATFORM_IS_WINDOWS() 0
#   define CANVAS_PLATFORM_IS_WIN32() 0
#   define CANVAS_PLATFORM_IS_WIN32_ARM64() 0
#   define CANVAS_PLATFORM_IS_WIN32_X64() 0
#   define CANVAS_PLATFORM_IS_WINRT() 0
#   define CANVAS_PLATFORM_IS_ANDROID() 0
#
#   include <TargetConditionals.h>
#   if (TARGET_OS_SIMULATOR == 1)
#       define CANVAS_PLATFORM_IS_MACOS() 0
#       define CANVAS_PLATFORM_IS_IOS() 1
#       define CANVAS_PLATFORM_IS_IOS_SIMULATOR() 1
#   elif (TARGET_OS_IPHONE == 1)
#       define CANVAS_PLATFORM_IS_MACOS() 0
#       define CANVAS_PLATFORM_IS_IOS() 1
#       define CANVAS_PLATFORM_IS_IOS_SIMULATOR() 0
#   else
#       define CANVAS_PLATFORM_IS_MACOS() 1
#       define CANVAS_PLATFORM_IS_IOS() 0
#       define CANVAS_PLATFORM_IS_IOS_SIMULATOR() 0
#   endif
#elif defined(_WIN32) // Defined as 1 when the compilation target is 32-bit ARM, 64-bit ARM, x86, or x64. Otherwise, undefined.
#   define CANVAS_PLATFORM_IS_APPLE() 0
#   define CANVAS_PLATFORM_IS_MACOS() 0
#   define CANVAS_PLATFORM_IS_IOS() 0
#   define CANVAS_PLATFORM_IS_IOS_SIMULATOR() 0
#   define CANVAS_PLATFORM_IS_WINDOWS() 1
#   define CANVAS_PLATFORM_IS_ANDROID() 0
#
#   if defined(__cplusplus_winrt) // Defined as the integer literal value 201009 when compiled as C++ and the /ZW (Windows Runtime Compilation) compiler option is set. Otherwise, undefined.
#       define CANVAS_PLATFORM_IS_WIN32() 0
#       define CANVAS_PLATFORM_IS_WINRT() 1
#       define CANVAS_PLATFORM_IS_WIN32_ARM64() 0
#       define CANVAS_PLATFORM_IS_WIN32_X64() 0
#   else
#       define CANVAS_PLATFORM_IS_WIN32() 1
#       define CANVAS_PLATFORM_IS_WINRT() 0
#
#       if defined(_WIN64) // _WIN64 Defined as 1 when the compilation target is 64-bit ARM or x64. Otherwise, undefined.
#           if defined(_M_ARM64) // _M_ARM64 Defined as 1 for compilations that target 64-bit ARM processors. Otherwise, undefined.
#               define CANVAS_PLATFORM_IS_WIN32_ARM64() 1
#               define CANVAS_PLATFORM_IS_WIN32_X64() 0
#           else
#               define CANVAS_PLATFORM_IS_WIN32_ARM64() 0
#               define CANVAS_PLATFORM_IS_WIN32_X64() 1
#           endif
#       else
#           define CANVAS_PLATFORM_IS_WIN32_ARM64() 0
#           define CANVAS_PLATFORM_IS_WIN32_X64() 0
#       endif
#   endif
#elif defined(ANDROID)
#   define CANVAS_PLATFORM_IS_APPLE() 0
#   define CANVAS_PLATFORM_IS_WINDOWS() 0
#   define CANVAS_PLATFORM_IS_MACOS() 0
#   define CANVAS_PLATFORM_IS_IOS() 0
#   define CANVAS_PLATFORM_IS_IOS_SIMULATOR() 0
#   define CANVAS_PLATFORM_IS_WIN32() 0
#   define CANVAS_PLATFORM_IS_WIN32_ARM64() 0
#   define CANVAS_PLATFORM_IS_WIN32_X64() 0
#   define CANVAS_PLATFORM_IS_WINRT() 0
#   define CANVAS_PLATFORM_IS_ANDROID() 1
#endif