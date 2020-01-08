/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include <Framework/ITelemetryTraceLogger.h>
#include <CoreUtils/PimplImpl.h>

namespace Spectre
{
    namespace Utils
    {

        // TODO: Implement telemetry on Android

        class TelemetryTraceUid::Impl
        {
        public:
            Impl() = default;
        };

        //-------------------------------------------------------------------------------------------------

        TelemetryTraceUid TelemetryTraceUid::CreateUid()
        {
            return {};
        }

        TelemetryTraceUid::TelemetryTraceUid() = default;

        TelemetryTraceUid::TelemetryTraceUid(Impl&& impl) : m_impl(std::move(impl))
        {
        }

        TelemetryTraceUid::TelemetryTraceUid(TelemetryTraceUid&& other) = default;

        TelemetryTraceUid::TelemetryTraceUid(const TelemetryTraceUid& other) : m_impl(*other.m_impl)
        {
        }

        TelemetryTraceUid::~TelemetryTraceUid()
        {
        }

        bool TelemetryTraceUid::IsZero() const
        {
            return true;
        }

        const char* TelemetryTraceUid::GetUIDAsString() const
        {
            return "This is not a GUID";
        }

        TelemetryTraceUid& TelemetryTraceUid::operator=(TelemetryTraceUid&& other) = default;

        TelemetryTraceUid& TelemetryTraceUid::operator=(const TelemetryTraceUid& other)
        {
            if (this != &other)
            {
                *m_impl = *other.m_impl;
            }

            return *this;
        }

        const TelemetryTraceUid TelemetryTraceUid::Zero = TelemetryTraceUid();
    }
}