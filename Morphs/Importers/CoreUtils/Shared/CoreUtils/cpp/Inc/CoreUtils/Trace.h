/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_TRACE_H_INCLUDED)
#define COREUTILS_TRACE_H_INCLUDED

#if !defined(_ARRAY_)
#include <array>
#endif // _ARRAY_

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

#if !defined(_MAP_)
#include <map>
#endif // _MAP_

#if !defined(_MUTEX_)
#include <mutex>
#endif // _MUTEX_

#if !defined(_STRING_)
#include <string>
#endif // _STRING_

#if !defined(_VECTOR_)
#include <vector>
#endif // _VECTOR_

#ifdef _WIN32
#define SPECTRE_IN _In_
#define SPECTRE_IN_Z _In_z_
#define SPECTRE_PRINTF_FORMAT_STRING _Printf_format_string_
#else // _WIN32
#define SPECTRE_IN
#define SPECTRE_IN_Z
#define SPECTRE_PRINTF_FORMAT_STRING
#endif // _WIN32

#include <CoreUtils/SpectreSDK.h>

#define FORCE_TRACE_ON          1

#if FORCE_TRACE_ON
#define FEATURE_TRACEENABLED 1
#endif

#if FEATURE_TRACEENABLED
#pragma detect_mismatch("Trace", "on")
#else
#pragma detect_mismatch("Trace", "off")
#endif

#if !FEATURE_TRACEENABLED

// Trace switched off, define all things to empty
#define TRACE_LEVEL(area, level, msg, ...)
#define TRACE_VERBOSE(area, msg, ...)
#define TRACE_INFO(area, msg, ...)
#define TRACE_IMPORTANT(area, msg, ...)
#define TRACE_WARN(area, msg, ...)
#define TRACE_ERROR(area, msg, ...)

#define DECLARE_TRACE_AREA(areaName)
#define DEFINE_TRACE_AREA(areaName, flags)

#else

// These defines must be outside of the namespace
#define TRACE_LEVEL(areaName, level, ...) gTraceLevels##areaName.Output(level, __VA_ARGS__)
#define TRACE_VERBOSE(areaName, ...) gTraceLevels##areaName.Output(Trace::Level::Verbose, __VA_ARGS__)
#define TRACE_INFO(areaName, ...) gTraceLevels##areaName.Output(Trace::Level::Info, __VA_ARGS__);
#define TRACE_IMPORTANT(areaName, ...) gTraceLevels##areaName.Output(Trace::Level::Important, __VA_ARGS__)
#define TRACE_WARN(areaName, ...) gTraceLevels##areaName.Output(Trace::Level::Warn, __VA_ARGS__)
#define TRACE_WARN_ONCE(areaName, ...) {                                         \
    static bool traceOnce = false;                                               \
    if (!traceOnce)                                                              \
    {                                                                            \
        traceOnce = true;                                                        \
        gTraceLevels##areaName.Output(Trace::Level::Warn, __VA_ARGS__);          \
    }                                                                            \
}

#define TRACE_ERROR(areaName, ...) gTraceLevels##areaName.Output(Trace::Level::Errored, __VA_ARGS__)

#define DECLARE_TRACE_AREA(areaName) extern Trace::LevelSettingsWrapper gTraceLevels##areaName;
#define DEFINE_TRACE_AREA(areaName, flags) Trace::LevelSettingsWrapper gTraceLevels##areaName = {nullptr, #areaName, flags}; Trace::LevelSettingsInit gTraceLevels##areaName##Init( gTraceLevels##areaName )

namespace Trace
{
    // The various levels a trace can be at, including the levels devices can be to use them.
    enum Level
    {
        NotSet =    0,
        Verbose =   1,
        Info =      2,
        Important = 3,
        Warn =      4,
        Errored =   5,
        Off =       6,

        MaxLevel =  7,
    };

    // The various devices that we can trace to
    enum Device
    {
        Break =         0,
        Handlers =      1,
        Output =        2,
        File =          3,  // Deprecated

        MaxDevice =     4,
    };

    // Helper struct to make defining trace areas easy
    struct ToFile
    {
        static const size_t Shift = 0;
        enum Internal
        {
            NotSet =    Level::NotSet    << Shift,
            Verbose =   Level::Verbose   << Shift,
            Info =      Level::Info      << Shift,
            Important = Level::Important << Shift,
            Warn =      Level::Warn      << Shift,
            Error =     Level::Errored   << Shift,
            Off =       Level::Off       << Shift,
        
            Mask =      0xF              << Shift,
        };
    };

    struct ToOutput
    {
        static const size_t Shift = 8;
        enum Internal
        {
            NotSet =    Level::NotSet    << Shift,
            Verbose =   Level::Verbose   << Shift,
            Info =      Level::Info      << Shift,
            Important = Level::Important << Shift,
            Warn =      Level::Warn      << Shift,
            Error =     Level::Errored   << Shift,
            Off =       Level::Off       << Shift,

            Mask =      0xF              << Shift,
        };
    };

    struct ToHandlers
    {
        static const size_t Shift = 16;
        enum Internal
        {
            NotSet =    Level::NotSet    << Shift,
            Verbose =   Level::Verbose   << Shift,
            Info =      Level::Info      << Shift,
            Important = Level::Important << Shift,
            Warn =      Level::Warn      << Shift,
            Error =     Level::Errored   << Shift,
            Off =       Level::Off       << Shift,

            Mask =      0xF              << Shift,
        };
    };

    struct BreakOn
    {
        static const size_t Shift = 24;
        enum Internal
        {
            NotSet =    Level::NotSet    << Shift,
            Verbose =   Level::Verbose   << Shift,
            Info =      Level::Info      << Shift,
            Important = Level::Important << Shift,
            Warn =      Level::Warn      << Shift,
            Error =     Level::Errored   << Shift,
            Off =       Level::Off       << Shift,

            Mask =      0xF              << Shift,
        };
    };

    // Main class which holds the Settings for a single area
    class LevelSettings
    {
    public:
        LevelSettings(const char* areaName, uint32_t flags);
        void Output(Level level, const char *formatString, va_list args);
        void ResetLevels();
        void SetLevel(Device d, Level level);
        Level GetLevel(Device d) const;
        std::string GetAreaName() const;
        std::string Serialise() const;
        void Deserialise(const std::string &line);

        std::array< Level, Device::MaxDevice >  m_to;

    public:
        // Internal line-length character limit for a single call to Output (including varargs expansion)
        static const unsigned int kMaxLineLength = 2048;

    private:
        const char* m_areaName;
    };

    void SPECTRESDK_CALL EnableTrace();
    void SPECTRESDK_CALL DisableTrace();

    struct AutoDisableTrace
    {
        AutoDisableTrace(){DisableTrace();}
        ~AutoDisableTrace(){EnableTrace();}
    private:
        AutoDisableTrace(const AutoDisableTrace& notCopyable);
        AutoDisableTrace& operator=(const AutoDisableTrace& notAssignable);
    };

    // Wrapper around 'LevelSettings'. This class is deliberately simple to
    // make sure we can init it at compile/load time so its always available
    // even if someone traces before main is called
    struct LevelSettingsWrapper
    {
        LevelSettings *ptr;
        const char    *areaName;
        uint32_t      flags;
        std::once_flag initOnce;

        void Output(SPECTRE_IN Level level, SPECTRE_IN_Z SPECTRE_PRINTF_FORMAT_STRING const char *formatString, ...);

        void InitIfNecessary();
    };

    // Simple helper class which initializes a 'LevelSettingsWrapper' on construction.
    struct LevelSettingsInit
    {
        LevelSettingsInit( LevelSettingsWrapper &toInit )
        {
            toInit.InitIfNecessary();
        }
    };

    // Call to save the current in memory trace settings
    void SaveCurrentTraceSettings();

    // Call to load trace settings
    void LoadCurrentTraceSettings();

    void SetAreaLevels(Trace::Device device, Trace::Level level);
    void SetAreaLevel(const std::string& area, Trace::Device device, Trace::Level level);

    // Convert from a level enumeration to a nice readable value
    std::string GetLevelName(Trace::Level level);

    // Convert from a device enumeration to a nice readable value
    std::string GetDeviceName(Trace::Device device);

    // Convert from a device enumeration to a really nice readable value
    std::string GetFriendlyDeviceName(Trace::Device device);

    //-----------------------------------------------------------------------------

    typedef unsigned int RegistrationToken;
    typedef std::function<void(std::string const& area, Trace::Level level, std::string const& message)> TraceHandler;

    std::mutex& GetHandlerMapCriticalLock();
    std::map<RegistrationToken, TraceHandler>& GetHandlerMap();
    RegistrationToken GetNewRegistrationToken();

    void NotifyHandlers(std::string const& area, Level level, std::string const& message);
    RegistrationToken AttachTraceHandler(TraceHandler handler);
    void RemoveTraceHandler(RegistrationToken token);

    //-----------------------------------------------------------------------------
} // namespace Trace

#endif /* #FEATURE_TRACEENABLED */

#endif // COREUTILS_TRACE_H_INCLUDED