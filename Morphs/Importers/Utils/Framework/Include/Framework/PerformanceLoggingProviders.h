/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

namespace Babylon
{
namespace Utils
{

using TimePoint = std::chrono::high_resolution_clock::time_point;

constexpr long long GetTimeInNanoseconds(const Babylon::Utils::TimePoint time)
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(time.time_since_epoch()).count();
}

/** "Interface" Structs for Providers **/
//-------------------------------------------------------------------------------------------------

struct ITimeProvider
{
    virtual ~ITimeProvider() = default;

    virtual TimePoint GetCurrentTime() const = 0;
};

//-------------------------------------------------------------------------------------------------

struct IMemoryStatsProvider
{
    virtual ~IMemoryStatsProvider() = default;

    virtual uint64_t GetTotalPhysicalMemory() const = 0;
    virtual uint64_t GetCommitedMemory() const = 0;
    virtual uint64_t GetCurrentlyUsedMemory() const = 0;
};

//-------------------------------------------------------------------------------------------------

struct ITraceProvider
{
    virtual ~ITraceProvider() = default;

    virtual void Register() = 0;
    virtual void Unregister() = 0;

    virtual bool HasSubscriber() const = 0;

    virtual void TraceMark(
        const char* eventName,
        TimePoint   currentTime,
        int         eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) = 0;

    virtual void TraceMeasurement(
        const char* eventName,
        TimePoint   currentTime,
        double      eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) = 0;

    virtual void TraceMeasurement(
        const char* eventName,
        TimePoint   currentTime,
        const char* eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) = 0;

    virtual void TraceMeasurement(
        const char* eventName,
        TimePoint   currentTime,
        unsigned long long eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) = 0;

    virtual void TraceTimeSpan(
        const char* eventName,
        TimePoint   currentTime,
        TimePoint   startTime,
        const char* functionName,
        const char* fileName,
        int         lineNumber) = 0;
};

//-------------------------------------------------------------------------------------------------
// Platform-agnostic provider implementations

struct DefaultTimeProvider : ITimeProvider
{
    virtual TimePoint GetCurrentTime() const override;
};


// Info structs
struct TraceInfo_Base
{
public:
    virtual ~TraceInfo_Base() = default;

    std::string eventName;
    TimePoint timestamp;
    std::string functionName;
    std::string fileName;
    int lineNumber = 0;

    virtual std::string ToString() const { return std::string(); }
    virtual size_t GetMemoryFootprint() const;
};

struct TraceInfo_Mark : TraceInfo_Base
{
public:
    int eventTracedValue = 0;

    virtual std::string ToString() const override;
    virtual size_t GetMemoryFootprint() const override;
};

struct TraceInfo_Double : TraceInfo_Base
{
public:
    double eventTracedValue = 0.0;

    virtual std::string ToString() const override;
    virtual size_t GetMemoryFootprint() const override;
};

struct TraceInfo_Char : TraceInfo_Base
{
public:
    std::string eventTracedValue;

    virtual std::string ToString() const override;
    virtual size_t GetMemoryFootprint() const override;
};

struct TraceInfo_ULongLong : TraceInfo_Base
{
public:
    unsigned long long eventTracedValue = 0ULL;

    virtual std::string ToString() const override;
    virtual size_t GetMemoryFootprint() const override;
};

struct TraceInfo_Timespan : TraceInfo_Base
{
public:
    TimePoint startTime;

    virtual std::string ToString() const override;
    virtual size_t GetMemoryFootprint() const override;
};

// In-Memory trace information gatherer
struct DefaultTraceProvider : ITraceProvider
{
public:
    DefaultTraceProvider();
    DefaultTraceProvider(size_t InitialReserve);

    ~DefaultTraceProvider() override;

    virtual void Register() override;
    virtual void Unregister() override {}

    virtual bool HasSubscriber() const override { return true; }

    virtual void TraceMark(
        const char* eventName,
        TimePoint   currentTime,
        int         eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) override;

    virtual void TraceMeasurement(
        const char* eventName,
        TimePoint   currentTime,
        double      eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) override;

    virtual void TraceMeasurement(
        const char* eventName,
        TimePoint   currentTime,
        const char* eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) override;

    virtual void TraceMeasurement(
        const char* eventName,
        TimePoint   currentTime,
        unsigned long long eventTracedValue,
        const char* functionName,
        const char* fileName,
        int         lineNumber) override;

    virtual void TraceTimeSpan(
        const char* eventName,
        TimePoint   currentTime,
        TimePoint   startTime,
        const char* functionName,
        const char* fileName,
        int         lineNumber) override;

    // Const accessor
    const std::vector< std::unique_ptr<TraceInfo_Base> >& GetTraceInfo() {
        m_Traces.shrink_to_fit();
        return m_Traces;
    }

    // Returns true if the number of traces contained exceeds our initial reservation
    bool HasReallocTracesArray();
    uint64_t GetMemoryFootprint() { return m_MemFootprint; }

private:
    // Internal arrays
    std::vector< std::unique_ptr<TraceInfo_Base> > m_Traces;
    uint64_t m_MemFootprint;

    // Initial entries amount reserved for trace info. Want to avoid re-alloc cost during performance testing
    size_t InitialTraceReservation;
};

struct DefaultMemoryStatsProvider : IMemoryStatsProvider
{
    virtual uint64_t GetTotalPhysicalMemory() const override;
    virtual uint64_t GetCommitedMemory() const override;
    virtual uint64_t GetCurrentlyUsedMemory() const override;
};

// Empty-stub version of the trace provider to be used when none are specified
struct StubTraceProvider : ITraceProvider
{
    virtual void Register() override {}
    virtual void Unregister() override {}

    virtual bool HasSubscriber() const override { return false; }

    virtual void TraceMark(
        const char* /*eventName*/,
        TimePoint   /*currentTime*/,
        int         /*eventTracedValue*/,
        const char* /*functionName*/,
        const char* /*fileName*/,
        int         /*lineNumber*/) override {}

    virtual void TraceMeasurement(
        const char* /*eventName*/,
        TimePoint   /*currentTime*/,
        double      /*eventTracedValue*/,
        const char* /*functionName*/,
        const char* /*fileName*/,
        int         /*lineNumber*/) override {}

    virtual void TraceMeasurement(
        const char* /*eventName*/,
        TimePoint   /*currentTime*/,
        const char* /*eventTracedValue*/,
        const char* /*functionName*/,
        const char* /*fileName*/,
        int         /*lineNumber*/) override {}

    virtual void TraceMeasurement(
        const char* /*eventName*/,
        TimePoint   /*currentTime*/,
        unsigned long long /*eventTracedValue*/,
        const char* /*functionName*/,
        const char* /*fileName*/,
        int         /*lineNumber*/) override {}

    virtual void TraceTimeSpan(
        const char* /*eventName*/,
        TimePoint   /*currentTime*/,
        TimePoint   /*startTime*/,
        const char* /*functionName*/,
        const char* /*fileName*/,
        int         /*lineNumber*/) override {}
};

}
}
