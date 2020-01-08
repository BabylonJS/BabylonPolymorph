/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <string>
#include <exception>

#include <CoreUtils/Assert.h>

DECLARE_TRACE_AREA(SmartThrow);

// Macro used in CX code, that marks the beginning of a guarded section of code (a try/catch basically).
// Use CX_GUARD_END to mark the end of the guarded code. Exceptions thrown form guarded code will be
// logged and translated into Platform::Exception(s)
#define CX_GUARD_BEGIN() try {

// Macro used in CX code, that marks the end of a guarded section of code (a try/catch basically).
// Use CX_GUARD_BEING to mark the beginning of the guarded code. Exceptions thrown form guarded code will be
// logged and translated into Platform::Exception(s)
#define CX_GUARD_END() }\
catch (const ::Spectre::Utils::SpectreException& e)\
{\
    std::string msg = ("EXCEPTION: " + std::string(__FUNCTION__) + "\nTYPE=SpectreException\nMESSAGE=" + e.m_message);\
    OutputDebugStringA(msg.c_str());\
    throw ref new Platform::Exception(e.m_hr, ::Spectre::Utils::LexicalCast<Platform::String^>(msg));\
}\
catch (const std::exception& e)\
{\
    std::string msg = ("EXCEPTION: " + std::string(__FUNCTION__) + " - std::xception=" + std::string(e.what()));\
    OutputDebugStringA(msg.c_str());\
    throw ref new Platform::Exception(E_FAIL, ::Spectre::Utils::LexicalCast<Platform::String^>(msg));\
}\
catch (Platform::Exception^ e)\
{\
    OutputDebugStringA(("EXCEPTION: " + std::string(__FUNCTION__) + " - Platform::Exception=" + ::Spectre::Utils::LexicalCast<std::string>(e->Message)).c_str());\
    throw;\
}\
catch (...)\
{\
    throw ref new Platform::Exception(E_FAIL, "EXCEPTION: " + ::Spectre::Utils::LexicalCast<Platform::String^>(__FUNCTION__) + " - Unknown Exception");\
}


namespace Spectre
{
namespace Utils
{

namespace P = Platform;

inline P::Exception^ SpectreWinRTException(P::String^ message, bool assert = true)
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing Platform::Exception with message '%ws'", message->Data());
        SpectreAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing Platform::Exception with message '%ws'", message->Data());
    }

    return P::Exception::CreateException(E_FAIL, message);
}

inline P::Exception^ SpectreWinRTException(DWORD win32Error, P::String^ message, bool assert = true)
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing Platform::Exception with message '%ws' and win32 error %u", message->Data(), win32Error);
        SpectreAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing Platform::Exception with message '%ws' and win32 error %u", message->Data(), win32Error);
    }

    return P::Exception::CreateException(HRESULT_FROM_WIN32(win32Error), message);
}

inline P::Exception^ SpectreWinRTException(HRESULT hr, P::String^ message, bool assert = true)
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing Platform::Exception with message '%ws' and HRESULT error 0x%.8x", message->Data(), hr);
        SpectreAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing Platform::Exception with message '%ws' and HRESULT error 0x%.8x", message->Data(), hr);
    }

    return P::Exception::CreateException(hr, message);
}

inline std::exception_ptr GetWinRTExceptionPtr(HRESULT hr, P::String^ message)
{
    std::exception_ptr ptr;
    try
    {
        throw SpectreWinRTException(hr, message, false);
    }
    catch (...)
    {
        ptr = std::current_exception();
    }
    return ptr;
}

inline void ThrowIfFailedWinRT(HRESULT hr)
{
    if (FAILED(hr))
    {
        throw Platform::Exception::CreateException(hr);
    }
}

} // namespace Utils

} // namespace Spectre
