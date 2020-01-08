/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_SMARTTHROW_H_INCLUDED)
#define COREUTILS_SMARTTHROW_H_INCLUDED

#ifdef _WIN32

#if !defined(_INC_WINDOWS)
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#endif // _INC_WINDOWS

#endif // _WIN32

#include <CoreUtils/Trace.h>
#include <exception>
#include <string>

DECLARE_TRACE_AREA(SmartThrow);

namespace Spectre
{
    namespace Utils
    {

        struct SpectreException : public std::runtime_error
        {
            SpectreException(std::string const& message, bool assert = false);
#ifdef _WIN32
            SpectreException(DWORD win32Error, std::string const& message, bool assert = false);
            SpectreException(HRESULT hr, std::string const& message, bool assert = false);
#endif // _WIN32

            std::string const m_message;
#ifdef _WIN32
            DWORD const       m_win32Error;
            HRESULT const     m_hr;
#endif // _WIN32
        };

        struct SpectreInvalidArgException : public SpectreException
        {
            SpectreInvalidArgException(std::string const& message, bool assert = false)
#ifdef _WIN32
                : SpectreException(E_INVALIDARG, message, assert)
#else
                : SpectreException(message, assert)
#endif
            {}
        };

        struct SpectreFailException : public SpectreException
        {
            SpectreFailException(std::string const& message, bool assert = false)
#ifdef _WIN32
                : SpectreException(E_FAIL, message, assert)
#else
                : SpectreException(message, assert)
#endif
            {}
        };

        struct SpectreNotImplException : public SpectreException
        {
            SpectreNotImplException(std::string const& message, bool assert = false)
#ifdef _WIN32
                : SpectreException(E_NOTIMPL, message, assert)
#else
                : SpectreException(message, assert)
#endif
            {}
        };

        template<class E>
        inline std::exception_ptr GetExceptionPtr()
        {
            std::exception_ptr ptr;
            try
            {
                throw E();
            }
            catch (...)
            {
                ptr = std::current_exception();
            }
            return ptr;
        }

        template<class E, class ... Args>
        inline std::exception_ptr GetExceptionPtr(Args && ... args)
        {
            std::exception_ptr ptr;
            try
            {
                throw E(std::forward<Args>(args) ...);
            }
            catch (...)
            {
                ptr = std::current_exception();
            }
            return ptr;
        }

#ifdef _WIN32

        inline void ThrowIfFailed(HRESULT hr)
        {
            if (FAILED(hr))
            {
                throw SpectreException(hr, "Thrown from ThrowIfFailed.", false);
            }
        }

        inline void ThrowIfFailed(HRESULT hr, const char* customMessage)
        {
            if (FAILED(hr))
            {
                throw SpectreException(hr, customMessage, false);
            }
        }
#endif // _WIN32

    } // namespace Utils
} // namespace Spectre

// Macros to enable the tracking of file and line number, automatically disabled.
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
#include <CoreUtils/SpectreTelemetryException.h>
#define SpectreException(...) SpectreTelemetryException(__FILE__, __LINE__, __VA_ARGS__)
#define SpectreInvalidArgException(...) SpectreTelemetryInvalidArgException(__FILE__, __LINE__, __VA_ARGS__)
#define SpectreFailException(...) SpectreTelemetryFailException(__FILE__, __LINE__, __VA_ARGS__)
#define SpectreNotImplException(...) SpectreTelemetryNotImplException(__FILE__, __LINE__, __VA_ARGS__)
#define ThrowIfFailed(...) ThrowIfFailed(__FILE__, __LINE__, __VA_ARGS__)
#endif // FEATURE_TELEMETRYEXCEPTIONSENABLED

#endif // COREUTILS_SMARTTHROW_H_INCLUDED
