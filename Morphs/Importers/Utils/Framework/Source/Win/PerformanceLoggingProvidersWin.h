/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <atomic>
#include <Framework/PerformanceLoggingProviders.h>

namespace Babylon
{
namespace Utils
{
        class ETWTraceProvider : public ITraceProvider
        {
        public:
            virtual void Register() override;
            virtual void Unregister() override;

            virtual bool HasSubscriber() const override;

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

        private:
            // An ETW provider can't be registered if it already is,
            // so we need to make sure to only do so once even in the
            // case of multiple concurrent ETWTraceProvider instances.
            static std::atomic<int32_t> s_registrationCount;
        };

        //-------------------------------------------------------------------------------------------------
}
}