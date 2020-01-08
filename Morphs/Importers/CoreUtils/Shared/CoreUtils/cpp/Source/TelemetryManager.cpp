/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/Assert.h>
#include <CoreUtils/ITelemetryManager.h>

namespace Spectre
{
    namespace Utils
    {
        // NOTE: There will be a differnt instance per DLL. So each module will need to expose an "initialize telemetry manager API"
        ITelemetryManager* TelemetrySingleton::s_instance = nullptr;

        bool SPECTRESDK_CALL TelemetrySingleton::Initialize(ITelemetryManager* instance)
        {
            if (s_instance != nullptr)
                return false;
            if (instance == nullptr)
                return false;

            s_instance = instance;
            return true;
        }

        //---------------------------------------------------------------------------------------------
        TelemetryToken TelemetryManager::AddHandler(OnTelemetryEventHandler handler)
        {
            std::lock_guard<std::mutex> lockHandlers(m_mutexHandlers);

            auto token = ++m_lastToken;
            m_eventHandlers[token] = handler;
            return token;
        }

        //---------------------------------------------------------------------------------------------
        TelemetryToken TelemetryManager::AddHandler(OnTelemetryEventWithJsonHandler handler)
        {
            std::lock_guard<std::mutex> lockHandlersExpanded(m_mutexHandlers);

            auto token = ++m_lastToken;
            m_jsonEventHandlers[token] = handler;
            return token;
        }

        //---------------------------------------------------------------------------------------------
        bool TelemetryManager::RemoveHandler(TelemetryToken token)
        {
            std::lock_guard<std::mutex> lockHandlers(m_mutexHandlers);
            bool removeHandlersResult = m_eventHandlers.erase(token) == 1;
            bool removeHandlersExpandedResult = m_jsonEventHandlers.erase(token) == 1;

            SpectreAssertExpr((removeHandlersResult || removeHandlersExpandedResult) || (!removeHandlersResult && !removeHandlersExpandedResult), "TelemetryManager::RemoveHandler - token should not exist in both handler tables");

            return removeHandlersResult || removeHandlersExpandedResult;
        }

        //---------------------------------------------------------------------------------------------
        bool TelemetryManager::SendEvent(const std::string& eventName, const StringStringMap& stringBag, const StringFloatMap& numberBag)
        {
            if (eventName.empty())
                return false;

            for (auto handler : m_eventHandlers)
            {
                handler.second(eventName, stringBag, numberBag);
            }
            return true;
        }

        bool TelemetryManager::SendEvent(const std::string& eventName, const std::string& jsonData)
        {
            if (eventName.length() == 0)
                return false;

            for (auto handler : m_jsonEventHandlers)
            {
                handler.second(eventName.c_str(), jsonData.c_str());
            }
            return true;
        }

    } // namespace Framework
} // namespace Spectre
