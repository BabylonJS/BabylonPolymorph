/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "FrameworkPch.h"
#include <TraceLoggingProvider.h>
#include <Win/PerformanceLoggingProvidersWin.h>

#define TRACE_LOGGING_ON 1

//-------------------------------------------------------------------------------------------------
#ifdef TRACE_LOGGING_ON
// This GUID was generated manually using Visual Studio create GUID tool
// You are not suppose to change it, if you do, make sure you update BabylonEvenLog.wprp
// GUID {9091CF64-70BB-42E0-A8A1-5C6913825AC4}
TRACELOGGING_DEFINE_PROVIDER(
    g_BabylonLoggingProvider,
    "BabylonTraceLoggingProvider",
    (
        0x9091cf64,
        0x70bb,
        0x42e0,
        0xa8,
        0xa1,
        0x5c,
        0x69,
        0x13,
        0x82,
        0x5a,
        0xc4));

#endif // TRACE_LOGGING_ON

//-------------------------------------------------------------------------------------------------

std::atomic<int32_t> Babylon::Utils::ETWTraceProvider::s_registrationCount;

//-------------------------------------------------------------------------------------------------

void Babylon::Utils::ETWTraceProvider::Register()
{
    if (s_registrationCount++ == 0)
    {
#if TRACE_LOGGING_ON
        TraceLoggingRegister(g_BabylonLoggingProvider);
#endif
    }
}

//-------------------------------------------------------------------------------------------------

void Babylon::Utils::ETWTraceProvider::Unregister()
{
    if (--s_registrationCount == 0)
    {
#if TRACE_LOGGING_ON
        TraceLoggingUnregister(g_BabylonLoggingProvider);
#endif
    }
}

//-------------------------------------------------------------------------------------------------

bool Babylon::Utils::ETWTraceProvider::HasSubscriber() const
{
#if TRACE_LOGGING_ON
    return TraceLoggingProviderEnabled(g_BabylonLoggingProvider, 0, 0) != FALSE;
#else
    return false;
#endif
}

//-------------------------------------------------------------------------------------------------

void Babylon::Utils::ETWTraceProvider::TraceMark(
    const char* eventName,
    TimePoint   currentTime,
    int         eventTracedValue,
    const char* functionName,
    const char* fileName,
    int         lineNumber)
{
#if TRACE_LOGGING_ON

    TraceLoggingWrite(
        g_BabylonLoggingProvider,
        "BabylonMarkEvent",
        TraceLoggingValue(eventName, "EventName"),
        TraceLoggingValue(GetTimeInNanoseconds(currentTime), "TimeOffset"),
        TraceLoggingValue(eventTracedValue, "Value"),
        TraceLoggingValue(functionName, "FunctionName"),
        TraceLoggingValue(fileName, "FileName"),
        TraceLoggingValue(lineNumber, "LineNumber"));
#endif
}

//-------------------------------------------------------------------------------------------------

void Babylon::Utils::ETWTraceProvider::TraceMeasurement(
    const char* eventName,
    TimePoint   currentTime,
    double      eventTracedValue,
    const char* functionName,
    const char* fileName,
    int         lineNumber)
{
#if TRACE_LOGGING_ON

    TraceLoggingWrite(
        g_BabylonLoggingProvider,
        "BabylonMeasurementEvent",
        TraceLoggingValue(eventName, "EventName"),
        TraceLoggingValue(GetTimeInNanoseconds(currentTime), "TimeOffset"),
        TraceLoggingValue(eventTracedValue, "Value"),
        TraceLoggingValue(functionName, "FunctionName"),
        TraceLoggingValue(fileName, "FileName"),
        TraceLoggingValue(lineNumber, "LineNumber"));
#endif
}

//-------------------------------------------------------------------------------------------------

void Babylon::Utils::ETWTraceProvider::TraceMeasurement(
    const char* eventName,
    TimePoint   currentTime,
    const char* eventTracedValue,
    const char* functionName,
    const char* fileName,
    int         lineNumber)
{
#if TRACE_LOGGING_ON

    TraceLoggingWrite(
        g_BabylonLoggingProvider,
        "BabylonMeasurementEvent",
        TraceLoggingValue(eventName, "EventName"),
        TraceLoggingValue(GetTimeInNanoseconds(currentTime), "TimeOffset"),
        TraceLoggingValue(eventTracedValue, "Value"),
        TraceLoggingValue(functionName, "FunctionName"),
        TraceLoggingValue(fileName, "FileName"),
        TraceLoggingValue(lineNumber, "LineNumber"));
#endif
}

//-------------------------------------------------------------------------------------------------
void Babylon::Utils::ETWTraceProvider::TraceMeasurement(
    const char* eventName,
    TimePoint   currentTime,
    unsigned long long eventTracedValue,
    const char* functionName,
    const char* fileName,
    int         lineNumber)
{
#if TRACE_LOGGING_ON

    TraceLoggingWrite(
        g_BabylonLoggingProvider,
        "BabylonMeasurementEvent",
        TraceLoggingValue(eventName, "EventName"),
        TraceLoggingValue(GetTimeInNanoseconds(currentTime), "TimeOffset"),
        TraceLoggingValue(eventTracedValue, "Value"),
        TraceLoggingValue(functionName, "FunctionName"),
        TraceLoggingValue(fileName, "FileName"),
        TraceLoggingValue(lineNumber, "LineNumber"));
#endif
}

//-------------------------------------------------------------------------------------------------

void Babylon::Utils::ETWTraceProvider::TraceTimeSpan(
    const char* eventName,
    TimePoint   currentTime,
    TimePoint   startTime,
    const char* functionName,
    const char* fileName,
    int         lineNumber)
{
#if TRACE_LOGGING_ON

    TraceLoggingWrite(
        g_BabylonLoggingProvider,
        "BabylonTimeSpanEvent",
        TraceLoggingValue(eventName, "EventName"),
        TraceLoggingValue(GetTimeInNanoseconds(currentTime), "TimeOffset"),
        TraceLoggingValue(GetTimeInNanoseconds(startTime), "StartTime"),
        TraceLoggingValue(functionName, "FunctionName"),
        TraceLoggingValue(fileName, "FileName"),
        TraceLoggingValue(lineNumber, "LineNumber"));
#endif
}

//-------------------------------------------------------------------------------------------------

uint64_t Babylon::Utils::DefaultMemoryStatsProvider::GetTotalPhysicalMemory() const
{
#if defined(__cplusplus_winrt)
    throw std::logic_error("Not implemented yet");
#else
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return statex.ullTotalPhys;
#endif
}

//-------------------------------------------------------------------------------------------------

uint64_t Babylon::Utils::DefaultMemoryStatsProvider::GetCommitedMemory() const
{
    throw std::logic_error("Not implemented yet");
}

//-------------------------------------------------------------------------------------------------

uint64_t Babylon::Utils::DefaultMemoryStatsProvider::GetCurrentlyUsedMemory() const
{
    throw std::logic_error("Not implemented yet");
}

//-------------------------------------------------------------------------------------------------