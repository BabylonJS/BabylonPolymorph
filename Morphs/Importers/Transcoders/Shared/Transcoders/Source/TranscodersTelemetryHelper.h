/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <string>
#include "Framework/ITelemetryTraceLogger.h"
#include <Framework/TelemetryTraceLoggerAliases.h>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Asset3D/Asset3D.h"

namespace Spectre
{
    namespace Transcoder
    {
        // Helper class for using telemetry in V2
        class TranscodersTelemetryHelper
        {
        public:
            TranscodersTelemetryHelper(const std::string originalExtensionType, const std::string destinationExtensionType, const std::string transcoderVersion, bool enabled);
            ~TranscodersTelemetryHelper();
            void Initialize(const std::unordered_map<std::string, std::string>& transcodeOptions, Spectre::Utils::TelemetryTraceLoggerFactoryFunctionType factory);

            void SendImportStartTelemetry();
            void SendImportCompleteTelemetry(const std::shared_ptr<Spectre::Transcoder::Asset3D> asset3DFromImport, const uint64_t streamByteSize);
            void SendImportAbortTelemetry(const std::string exceptionDetails, const uint64_t streamByteSize);

            void SendExportStartTelemetry();
            void SendExportCompleteTelemetry(const std::shared_ptr<Spectre::Transcoder::Asset3D> asset3DFromImport);
            void SendExportAbortTelemetry(const std::string exceptionDetails);

        private:
            std::shared_ptr<Spectre::Utils::ITelemetryTraceLogger> m_telemetryLogger;
            std::unordered_map<std::string, std::string> m_transcodeOptions;
            bool m_telemetryEnabled;
            std::string m_exceptionDetails;

            const std::string m_originalExtensionType;
            const std::string m_destinationExtensionType;
            const std::string m_transcoderVersion;

            Utils::TelemetryTraceUid m_importActivityID;
            Utils::TelemetryTraceUid m_exportActivityID;

            // The time when this class was initialized
            std::chrono::time_point<std::chrono::steady_clock> m_transcoderInitializedTime;
            // The time when import or export was begun
            std::chrono::time_point<std::chrono::steady_clock> m_transcodeStartTime;

            Spectre::Utils::TelemetryTraceLogger::AnimationStats m_animStats;

            void SendTranscoderInitialization();
            void SendTranscoderDestroyed(const int timeSinceInitialization, const char* exceptionDetails);

            std::string GetTranscodeOptionsStringForTelemetry() const;
            int CalculateElapsedTime(const std::chrono::time_point<std::chrono::steady_clock> startTime);
        };
    }
}