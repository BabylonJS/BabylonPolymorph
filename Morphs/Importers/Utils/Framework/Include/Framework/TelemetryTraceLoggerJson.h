/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <Framework/ITelemetryTraceLogger.h>
#include <Framework/TelemetryTraceLoggerAliases.h>
#include <Framework/Types.h>

namespace Babylon
{
    namespace Utils
    {
        class TelemetryTraceLoggerJson : public ITelemetryTraceLogger
        {
        public:
            TelemetryTraceLoggerJson(TelemetryTraceLoggerClientCallback callback);
            ~TelemetryTraceLoggerJson();

            const std::shared_ptr<TelemTraceLoggerAttributes> GetAttributes() override { return nullptr; }

            void SetBaseArchitecture(std::string arch) { m_baseArchitecture = arch; }

            void SetCanvasActivityID(const TelemetryTraceUid& canvasId) { m_canvasActivityID = canvasId; }

            void SetTranscoderActivityID(const TelemetryTraceUid& transcoderId) { m_transcoderActivityID = transcoderId; }

            void SetCorrelationVectorGUID(TelemetryTraceLoggerCorrelationVectorId guid) override { BabylonUnusedParameter(guid); };

            void CanvasInitialization(bool success, const char* exceptionDetails, const char* packageVersion) override;

            void CanvasDestroyed(int durationMS, const char* exceptionDetails) override;

            void CanvasSuspended(int durationMS, const char* exceptionDetails) override;

            void LoadModelSessionStart(const TelemetryTraceUid& loadActivityId, const char* extension) override;

            void LoadModelSessionEnd(
                const TelemetryTraceUid& loadActivityID,
                bool success,
                const char* exceptionDetails,
                std::chrono::milliseconds duration,
                const TelemetryTraceLogger::LoaderStats& loaderStats,
                const TelemetryTraceLogger::AnimationStats& animStats) override;

            void LoadModelSessionAbort(const TelemetryTraceUid& loadActivityId, const char* exceptionDetails) override;

            void SerializeModelSessionStart(const TelemetryTraceUid& serializeActivityId, const char* extension) override;

            void SerializeModelSessionEnd(
                const TelemetryTraceUid& serializeActivityId,
                bool success,
                const char* exceptionDetails,
                std::chrono::milliseconds duration,
                const TelemetryTraceLogger::AnimationStats& animStats) override;

            void SerializeModelSessionAbort(
                const TelemetryTraceUid& serializeActivityId,
                const char* exceptionDetails) override;

            void CanvasException(const char* exceptionDetails) override;

            void TranscoderInitialization(
                bool success,
                const char* exceptionDetails,
                const char* packageVersion,
                const char* transcoderVersion) override;

            void TranscoderDestroyed(
                int durationMS,
                const char* exceptionDetails,
                const char* transcoderVersion) override;

            void Import3DModelStart(
                const TelemetryTraceUid& importActivityID,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                const char* importOptions,
                const char* transcoderVersion) override;

            void Import3DModelAbort(
                const TelemetryTraceUid& importActivityID,
                const char* exceptionDetails,
                uint32_t sizeInKB,
                const char* transcoderVersion) override;

            void Import3DModelEnd(
                const TelemetryTraceUid& importActivityID,
                bool success,
                const char* exceptionDetails,
                int durationMS,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                size_t vertexCount,
                size_t indexCount,
                size_t textureCount,
                int64_t vertexBufferMemory,
                int64_t indexBufferMemory,
                int64_t textureMemory,
                unsigned int numAnimations,
                unsigned int numBones,
                unsigned int animationTypes,
                float totalAnimationDuration,
                uint32_t sizeInKB,
                const char* transcoderVersion) override;

            void Export3DModelStart(
                const TelemetryTraceUid& exportActivityID,
                const TelemetryTraceUid& importActivityID,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                const char* transcoderVersion) override;

            void Export3DModelAbort(
                const TelemetryTraceUid& exportActivityID,
                const TelemetryTraceUid& importActivityID,
                const char* exceptionDetails,
                const char* transcoderVersion) override;

            void Export3DModelEnd(
                const TelemetryTraceUid& exportActivityID,
                const TelemetryTraceUid& importActivityID,
                bool success,
                const char* exceptionDetails,
                int durationMS,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                size_t vertexCount,
                size_t indexCount,
                size_t textureCount,
                int64_t vertexBufferMemory,
                int64_t indexBufferMemory,
                int64_t textureMemory,
                unsigned int numAnimations,
                unsigned int numBones,
                unsigned int animationTypes,
                float totalAnimationDuration,
                const char* transcoderVersion) override;

            void SetTag(const std::string& tag) override
            {
                m_tag = tag;
            }

        private:

            TelemetryTraceUid m_canvasActivityID;
            TelemetryTraceUid m_loadActivityID;
            TelemetryTraceUid m_transcoderActivityID;

            // Architecture Type
            std::string m_baseArchitecture;
            std::string m_tag;

            TelemetryTraceLoggerClientCallback m_telemetryCallback;
        };
    }
}
