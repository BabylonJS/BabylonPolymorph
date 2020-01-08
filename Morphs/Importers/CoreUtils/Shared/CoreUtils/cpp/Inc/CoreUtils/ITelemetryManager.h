/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_SPECTRESDK_H_INCLUDED)
#include <CoreUtils/SpectreSDK.h>
#endif // COREUTILS_SPECTRESDK_H_INCLUDED

#if !defined(_STRING_)
#include <string>
#endif // _STRING_

#include <map>

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

#include <mutex>

// http://stackoverflow.com/questions/9669071/warning-c4503-when-using-pragma-warning-around-boost-includes
#pragma warning (disable:4503)

extern "C"
{

//-----------------------------------------------------------------------------

/**
* Function signature for the SpectreOnTelemetryEventHandler callback.
*
* \param[in] eventName Specifies the name of the telemetry event.
* \param[in] jsonData The data associated with the telemetry event.
*/
typedef void(SPECTRESDK_CALL *SpectreOnTelemetryEventHandler)(const char* eventName, const char* jsonData);

}


namespace Spectre
{
    namespace Utils
    {
        typedef int TelemetryToken;

        typedef std::function<void SPECTRESDK_CALL (const std::string&, const std::map<std::string, std::string>&, const std::map<std::string, float>&)> OnTelemetryEventHandler;
        typedef std::function<void SPECTRESDK_CALL (const std::string&, const std::string&)> OnTelemetryEventWithJsonHandler;
        typedef std::map<std::string, std::string> StringStringMap;
        typedef std::map<std::string, float> StringFloatMap;

        /**
        * \brief
        * This class defines the interface for the telemetry manager. This API can be used by client code to
        * send custom events to a telemetry service/file.
        */
        class ITelemetryManager
        {
        public:
            virtual ~ITelemetryManager() {}

            /**
            * \brief
            * Add a new handler to the manager. The registered handler will be invoked whenever a telemetry event is sent.
            * If the handler has already been added, it will be added again (no duplicate detection)
            *
            * \return   Token ID of the handler. Client should keep hold of this. It is to be used to remove the handler.
            */
            virtual TelemetryToken AddHandler(OnTelemetryEventHandler handler) = 0;

            /**
            * \brief
            * Add a new handler to the manager. The registered handler will be invoked whenever a telemetry event is sent.
            * If the handler has already been added, it will be added again (no duplicate detection)
            *
            * \return   Token ID of the handler. Client should keep hold of this. It is to be used to remove the handler.
            */
            virtual TelemetryToken AddHandler(OnTelemetryEventWithJsonHandler handler) = 0;

            /**
            * \brief
            * Remove a previously added handler. Once removed, the handler will no longer be invoked for any future telemetry events.
            *
            * \return   true if the handler was found and removed. False if the handler was not registered (or has already been removed)
            */
            virtual bool RemoveHandler(TelemetryToken token) = 0;

            /**
            * \brief
            * Send a telemetry event. Calling this API will forward the events onto all registered handlers synchronously.
            *
            * \return   True if the event was processed correctly (even if no handlers registered). False if an empty eventName specified.
            */
            virtual bool SendEvent(const std::string& eventName, const StringStringMap& stringBag, const StringFloatMap& numberBag) = 0;

            /**
            * \brief
            * Send a telemetry event. Calling this API will forward the events onto all registered handlers synchronously.
            *
            * \return   True if the event was processed correctly (even if no handlers registered). False if an empty eventName specified.
            */
            virtual bool SendEvent(const std::string& eventName, const std::string& jsonData) = 0;

        };

        /**
        * The telemetry singleton holds the ITelemetryManager instance that a module should use for sending telemetry events.
        * Each module (DLL) will end up having it's own global TelemetrySingleton
        */
        class TelemetrySingleton
        {
        public:
            static bool SPECTRESDK_CALL Initialize(ITelemetryManager* instance);

            static void Shutdown()
            {
                s_instance = nullptr;
            }

            static ITelemetryManager* get()
            {
                return s_instance;
            }

        protected:

            static ITelemetryManager* s_instance;
        };

        /**
        * Implementation of the Telemetry Manager
        */
        class TelemetryManager : public ITelemetryManager
        {
        public:
            virtual ~TelemetryManager() {}

            virtual int AddHandler(OnTelemetryEventHandler handler);
            virtual int AddHandler(OnTelemetryEventWithJsonHandler handler);
            virtual bool RemoveHandler(TelemetryToken token);
            virtual bool SendEvent(const std::string& eventName, const StringStringMap& stringBag, const StringFloatMap& numberBag);
            virtual bool SendEvent(const std::string& eventName, const std::string& jsonData);

        protected:
            TelemetryToken m_lastToken = 0;
            std::mutex m_mutexHandlers;
            std::map<TelemetryToken, OnTelemetryEventHandler> m_eventHandlers;
            std::map<TelemetryToken, OnTelemetryEventWithJsonHandler> m_jsonEventHandlers;

        private:
            TelemetryToken AddHandler(std::map<TelemetryToken, std::function<void()>> eventHandlers, std::function<void()> handler);
        };

    } // End namespace Utils

} // End namespace Spectre
