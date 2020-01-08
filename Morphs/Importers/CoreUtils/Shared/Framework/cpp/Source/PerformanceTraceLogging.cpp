/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"
#include <Framework/PerformanceTraceLogging.h>

#ifdef _WIN32
#include <Win/PerformanceLoggingProvidersWin.h>
#endif

#define TRACE_LOGGING_ON 1

//-------------------------------------------------------------------------------------------------

#if TRACE_LOGGING_ON
DEFINE_TRACE_AREA(CoreUtils_PerfTracing, 0);
#endif

Spectre::Utils::PerformanceLoggerPtr SPECTRESDK_CALL Spectre::Utils::PerformanceLogger::CreateWithDefaultProviders()
{
#ifdef _WIN32
    auto traceProvider = std::static_pointer_cast<ITraceProvider>(std::make_shared<ETWTraceProvider>());
#else
    auto traceProvider = std::static_pointer_cast<ITraceProvider>(std::make_shared<StubTraceProvider>());
#endif
    auto timeProvider = std::static_pointer_cast<ITimeProvider>(std::make_shared<DefaultTimeProvider>());
    auto memoryStatsProvider = std::static_pointer_cast<IMemoryStatsProvider>(std::make_shared<DefaultMemoryStatsProvider>());
    return std::make_shared<Spectre::Utils::PerformanceLogger>(std::move(traceProvider), std::move(timeProvider), std::move(memoryStatsProvider));
}

//-------------------------------------------------------------------------------------------------

Spectre::Utils::PerformanceLogger::PerformanceLogger(
    ITraceProviderPtr traceProvider,
    ITimeProviderPtr timeProvider,
    IMemoryStatsProviderPtr memoryStatsProvider) :
    m_traceProvider(traceProvider),
    m_timeProvider(timeProvider),
    m_memoryStatsProvider(memoryStatsProvider)
{
    m_traceProvider->Register();
}

//-------------------------------------------------------------------------------------------------

Spectre::Utils::PerformanceLogger::~PerformanceLogger()
{
    m_traceProvider->Unregister();
}

//-------------------------------------------------------------------------------------------------

void Spectre::Utils::PerformanceLogger::AddMark(
    MarkType markType,
    const char* file,
    int line,
    const char* function,
    const char* eventName) const
{
    if (m_traceProvider->HasSubscriber())
    {
        m_traceProvider->TraceMark(
            eventName,
            m_timeProvider->GetCurrentTime(),
            markType,
            function,
            file,
            line);
    }
}

//-------------------------------------------------------------------------------------------------

void Spectre::Utils::PerformanceLogger::AddTimeSpan(
    const char* file,
    int line,
    const char* function,
    const char* name,
    TimePoint startTime) const
{
    if (m_traceProvider->HasSubscriber())
    {
        m_traceProvider->TraceTimeSpan(
            name,
            m_timeProvider->GetCurrentTime(),
            startTime,
            function,
            file,
            line);
    }
}

//-------------------------------------------------------------------------------------------------

bool Spectre::Utils::PerformanceLogger::HasSubscriber() const
{
    return m_traceProvider->HasSubscriber();
}

//-------------------------------------------------------------------------------------------------

const char* Spectre::Utils::PerformanceLogger::GetMeasurementTraceValue(const std::string& measurementValue)
{
    return measurementValue.c_str();
}

//-------------------------------------------------------------------------------------------------

const char* Spectre::Utils::PerformanceLogger::GetMeasurementTraceValue(const char* measurementValue)
{
    return measurementValue;
}

//-------------------------------------------------------------------------------------------------

const unsigned long long Spectre::Utils::PerformanceLogger::GetMeasurementTraceValue(const unsigned long long measurementValue)
{
    return measurementValue;
}

//-------------------------------------------------------------------------------------------------

Spectre::Utils::PerformanceScope::PerformanceScope(
    PerformanceLoggerPtr logger,
    const char* file,
    int line,
    const char* function,
    bool createSingleTraceEvent) :
    PerformanceScope(std::move(logger), file, line, function, "", createSingleTraceEvent)
{
}

//-------------------------------------------------------------------------------------------------

Spectre::Utils::PerformanceScope::PerformanceScope(
    PerformanceLoggerPtr logger,
    const char* file,
    int line,
    const char* function,
    const char* eventName,
    bool createSingleTraceEvent) :
    m_logger(std::move(logger)),
    m_line(line),
    m_file(file),
    m_function(function),
    m_eventName(eventName),
    m_createSingleTraceEvent(createSingleTraceEvent)
{
    if (m_createSingleTraceEvent)
    {
        m_startTime = m_logger->GetCurrentTime();
    }
    else
    {
        m_logger->AddMark(
            PerformanceLogger::EnterScopeMark,
            file,
            line,
            function,
            eventName);
    }
}

//-------------------------------------------------------------------------------------------------

Spectre::Utils::PerformanceScope::~PerformanceScope()
{
    if (m_createSingleTraceEvent)
    {
        m_logger->AddTimeSpan(
            m_file,
            m_line,
            m_function,
            m_eventName,
            m_startTime);
    }
    else
    {
        m_logger->AddMark(
            PerformanceLogger::ExitScopeMark,
            m_file,
            m_line,
            m_function,
            m_eventName);
    }
}

//-------------------------------------------------------------------------------------------------
