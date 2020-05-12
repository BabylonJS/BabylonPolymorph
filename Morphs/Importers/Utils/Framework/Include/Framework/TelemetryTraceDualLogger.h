/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/ITelemetryTraceLogger.h>

namespace Babylon
{
    namespace Utils
    {
        class TelemetryTraceDualLogger : public ITelemetryTraceLogger
        {
        public:
            TelemetryTraceDualLogger(std::shared_ptr<ITelemetryTraceLogger> loggerA, std::shared_ptr<ITelemetryTraceLogger> loggerB);
            ~TelemetryTraceDualLogger();

            const std::shared_ptr<TelemTraceLoggerAttributes> GetAttributes() override { return nullptr; }

            void SetCorrelationVectorGUID(TelemetryTraceLoggerCorrelationVectorId guid) override;

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

            std::string m_tag;
            std::shared_ptr<ITelemetryTraceLogger> m_loggerA;
            std::shared_ptr<ITelemetryTraceLogger> m_loggerB;
        };
    }
}