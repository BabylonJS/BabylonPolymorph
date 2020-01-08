/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include "Pointers.h"
#include <CoreUtils/Assert.h>
#include <CoreUtils/Trace.h>
#include "PerformanceLoggingProviders.h"

namespace Spectre
{
namespace Utils
{

/// PerformanceLogger is a class that provides tracing functionality
/// At the moment is support two type of trace events:
/// 1. measurements - trace any value type that is supported by ETW API, useful for outputting custom statistic
/// 2. mark - trace a mark, which is useful for frequency and timings
class PerformanceLogger final
{
public:
    using MarkType = int;
    static const MarkType DefaultMark    = 0;
    static const MarkType EnterScopeMark = 1;
    static const MarkType ExitScopeMark  = 2;

    static PerformanceLoggerPtr SPECTRESDK_CALL CreateWithDefaultProviders();

    /// Constructor has ability to inject dependency of the internal subsystems
    ///
    /// \param traceProvider - underlying mechanism for sending single trace events
    /// \param timeProvider - mechanism that provides current time
    /// \param memoryStatsProvider - mechanism that provides basic information about memory usage
    PerformanceLogger(
        ITraceProviderPtr traceProvider,
        ITimeProviderPtr timeProvider,
        IMemoryStatsProviderPtr memoryStatsProvider);

    ~PerformanceLogger();

    /// Returns whether there are any subscribers listening to this logger.
    /// Can be used to determine whether to do work to calculate logging
    /// results.
    bool HasSubscriber() const;

    /// Returns the current time
    TimePoint GetCurrentTime();

    /// AddMeasurement adds a custom value to the trace
    /// It supports any value that underlying ETW template accepts
    ///
    /// \param file - filename from which trace was called
    /// \param line - source file line number of the trace event
    /// \param function - parent function name of the trace event
    /// \param measurementName - name of the measurement
    /// \param measurementValue - a custom measurement value
    template<typename T>
    void AddMeasurement(
        const char* file,
        int line,
        const char* function,
        const char* measurementName,
        T measurementValue) const;

    /// AddMark adds a mark in the trace which can be used to measure timing and frequency of various events
    ///
    /// \param markType - one of three values: 0 - a default mark, 1 - marks the beginning of a scope, 2 - marks the end of a scope
    /// \param line - source file line number of the trace event
    /// \param function - parent function name of the trace event
    /// \param eventName - name of the mark event
    void AddMark(
        MarkType markType,
        const char* file,
        int line,
        const char* function,
        const char* eventName) const;

    /// AddTimeSpan adds a time span with a start and an end time to the trace.  The end of the time span
    /// is automatically recorded when AddTimeSpan is called.
    ///
    /// \param file - filename from which trace was called
    /// \param line - source file line number of the trace event
    /// \param function - parent function name of the trace event
    /// \param name - name of the time span
    /// \param startTime - start time
    void AddTimeSpan(
        const char* file,
        int line,
        const char* function,
        const char* name,
        TimePoint startTime) const;

    ITraceProviderPtr GetTraceProvider() { return m_traceProvider; }

private:
    static const char* GetMeasurementTraceValue(const char* measurementValue);

    static const char* GetMeasurementTraceValue(const std::string& measurementValue);

    static const unsigned long long GetMeasurementTraceValue(const unsigned long long measurementValue);

    template <typename T>
    static double GetMeasurementTraceValue(T measurementValue);

    ITraceProviderPtr m_traceProvider;
    ITimeProviderPtr m_timeProvider;
    IMemoryStatsProviderPtr m_memoryStatsProvider;
};

template <typename T>
double Spectre::Utils::PerformanceLogger::GetMeasurementTraceValue(T measurementValue)
{
    static_assert(std::is_convertible<T, double>::value, "Cannot convert measurement value to double.");
    return static_cast<double>(measurementValue);
}

template<typename T>
void Spectre::Utils::PerformanceLogger::AddMeasurement(
    const char* file,
    int line,
    const char* function,
    const char* measurementName,
    T measurementValue) const
{
    if (m_traceProvider->HasSubscriber())
    {
        auto value = GetMeasurementTraceValue(measurementValue);

        m_traceProvider->TraceMeasurement(
            measurementName,
            m_timeProvider->GetCurrentTime(),
            value,
            function,
            file,
            line);
    }
}

inline TimePoint Spectre::Utils::PerformanceLogger::GetCurrentTime()
{
    return m_timeProvider->GetCurrentTime();
}

//-------------------------------------------------------------------------------------------------

/// PerformanceScope class is a helper class to implement RAII pattern
/// It sends a mark trace event at the beginning and the end of the scope
class PerformanceScope final
{
public:
    /// Constructor that takes context information from the caller.
    /// file - filename from which trace was called
    /// line - source file line number of the trace event
    /// function - parent function name of the trace event
    /// createSingleTraceEvent (optional) - create a single trace event with both start and end times; defaults to "false" for backward compatibility
    PerformanceScope(
        PerformanceLoggerPtr logger,
        const char* file,
        int line,
        const char* function,
        bool createSingleTraceEvent=false);

    /// Constructor that takes context information from the caller.
    /// file - filename from which trace was called
    /// line - source file line number of the trace event
    /// function - parent function name of the trace event
    /// eventName (optional) - additional event name
    /// createSingleTraceEvent (optional) - create a single trace event with both start and end times; defaults to "false" for backward compatibility
    PerformanceScope(
        PerformanceLoggerPtr logger,
        const char* file,
        int line,
        const char* function,
        const char* eventName = "",
        bool createSingleTraceEvent = false);

    ~PerformanceScope();

private:
    PerformanceLoggerPtr m_logger;
    int m_line;
    const char* m_file;
    const char* m_function;
    const char* m_eventName;
    bool m_createSingleTraceEvent;
    TimePoint m_startTime;
};

//-------------------------------------------------------------------------------------------------
}
}

//-------------------------------------------------------------------------------------------------

#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)
#define MAKE_UNIQUE(x) CONCATENATE(x, __COUNTER__)

#define TRACE_SCOPE(logger, arg1)  Spectre::Utils::PerformanceScope MAKE_UNIQUE(_scope_)(logger, __FILE__, __LINE__, __func__, arg1)
#define TRACE_SCOPE_SINGLE_EVENT(logger, arg1)  Spectre::Utils::PerformanceScope MAKE_UNIQUE(_scope_)(logger, __FILE__, __LINE__, __func__, arg1, true)
#define TRACE_FREQ(logger, arg1) logger->AddMark(Spectre::Utils::PerformanceLogger::DefaultMark, __FILE__, __LINE__, __func__, arg1);
#define TRACE_MEASUREMENT(logger, arg1, arg2) logger->AddMeasurement(__FILE__, __LINE__, __func__, arg1, arg2);
