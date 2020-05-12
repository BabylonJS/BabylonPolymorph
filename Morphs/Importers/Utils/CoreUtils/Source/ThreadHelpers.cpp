/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/ThreadHelpers.h>

#ifdef _WIN32
#if !defined(WIN32_LEAN_AND_MEAN)
# define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#endif

namespace Babylon
{
namespace Utils
{

//-----------------------------------------------------------------------------

#ifdef _WIN32

    // from http://msdn.microsoft.com/en-us/library/xcb2z8hs.aspx
    void SetThreadName(uint32_t threadId, char const* threadName)
    {
        static DWORD const MS_VC_EXCEPTION = 0x406D1388;

#pragma pack(push, 8)
        struct THREADNAME_INFO
        {
            DWORD dwType;     // Must be 0x1000.
            LPCSTR szName;    // Pointer to name (in user addr space).
            DWORD dwThreadID; // Thread ID (-1=caller thread).
            DWORD dwFlags;    // Reserved for future use, must be zero.

            THREADNAME_INFO(DWORD threadId, char const* threadName)
                :
                dwType(0x1000),
                szName(threadName),
                dwThreadID(threadId),
                dwFlags(0)
            {
                // do nothing
            }
        };
#pragma pack(pop)

        auto info = THREADNAME_INFO(threadId, threadName);
        __try
        {
            RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
        }
#pragma warning(push)
#pragma warning(disable: 6320) // Exception-filter expression is the constant EXCEPTION_EXECUTE_HANDLER
#pragma warning(disable: 6322) // Empty _except block
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            // do nothing
        }
#pragma warning(pop)
    }

//-----------------------------------------------------------------------------
#else // _WIN32
//-----------------------------------------------------------------------------

    // TODO: Implement this, if possible, on other platforms.
    void SetThreadName(uint32_t threadId, char const* threadName)
    {
    }

#endif // _WIN32

} // Utils
} // Babylon

//-----------------------------------------------------------------------------

#ifndef _WIN32

// TODO: Implement this, if possible, on other platforms.
uint32_t GetCurrentThreadId()
{
    return 0;
}

#endif // _WIN32
