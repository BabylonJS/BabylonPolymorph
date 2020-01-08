/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include <string>
#include "CanvasCll.h"
#include "CanvasCllInit.h"

#if ENABLE_MACCLL_LIBRARY
#   include "cll/CllApi.h"
#   include <cll/CorrelationVector.h>

    int Spectre::Utils::CanvasCll::m_cllCount = 0;

#endif // ENABLE_MACCLL_LIBRARY

Spectre::Utils::CanvasCll::CanvasCll()
{
#if ENABLE_MACCLL_LIBRARY
    if (m_cllCount == 0)
    {
        CanvasCllInitForPlatform("A-Canvas3D");
        cll::CllApi::getCv()->initialize(2);
        cll::CllApi::start();
    }

    m_cllCount++;
#endif // #if ENABLE_MACCLL_LIBRARY
}

Spectre::Utils::CanvasCll::~CanvasCll()
{
#if ENABLE_MACCLL_LIBRARY
    m_cllCount--;

    if (m_cllCount == 0)
    {
        cll::CllApi::stop();
    }
#endif // #if ENABLE_MACCLL_LIBRARY
}

void Spectre::Utils::CanvasCll::IncrementCorrelationVector()
{
#if ENABLE_MACCLL_LIBRARY
    cll::CllApi::getCv()->increment();
#endif // #if ENABLE_MACCLL_LIBRARY
}

void Spectre::Utils::CanvasCll::Log(std::string eventName, const char* eventData)
{
#if ENABLE_MACCLL_LIBRARY
    std::vector<cll:: TicketData> ids;
    std::string fullEventName = "Microsoft.Beihai.Core.Canvas." + eventName;
    cll::CllApi::log(fullEventName.c_str(), eventData, cll::Latency::LatencyNormal, cll::Persistence::PersistenceNormal, cll::Sensitivity::SensitivityNone, cll::SampleRate_NoSampling, ids);
#endif
}
