/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "FrameworkPch.h"
#include <Framework/TelemetryTraceDualLogger.h>

using namespace Babylon::Utils;

//-------------------------------------------------------------------------------------------------

TelemetryTraceDualLogger::TelemetryTraceDualLogger(std::shared_ptr<ITelemetryTraceLogger> loggerA, std::shared_ptr<ITelemetryTraceLogger> loggerB)
    : m_loggerA(loggerA),
      m_loggerB(loggerB)
{
    BabylonAssertExpr(loggerA, "TelemetryTraceDualLogger instantiated with null loggerA.");
    BabylonAssertExpr(loggerB, "TelemetryTraceDualLogger instantiated with null loggerB.");
}

//-------------------------------------------------------------------------------------------------

TelemetryTraceDualLogger::~TelemetryTraceDualLogger()
{
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::SetCorrelationVectorGUID(TelemetryTraceLoggerCorrelationVectorId guid)
{
    m_loggerA->SetCorrelationVectorGUID(guid);

    m_loggerB->SetCorrelationVectorGUID(guid);
}

//-------------------------------------------------------------------------------------------------


void TelemetryTraceDualLogger::CanvasInitialization(bool success, const char* exceptionDetails, const char* packageVersion)
{
    m_loggerA->CanvasInitialization(success, exceptionDetails, packageVersion);

    m_loggerB->CanvasInitialization(success, exceptionDetails, packageVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::CanvasDestroyed(int durationMS, const char* exceptionDetails)
{
    m_loggerA->CanvasDestroyed(durationMS, exceptionDetails);

    m_loggerB->CanvasDestroyed(durationMS, exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::CanvasSuspended(int durationMS, const char* exceptionDetails)
{
    m_loggerA->CanvasSuspended(durationMS, exceptionDetails);

    m_loggerB->CanvasSuspended(durationMS, exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::LoadModelSessionStart(const TelemetryTraceUid& loadActivityID, const char* extension)
{
    m_loggerA->LoadModelSessionStart(loadActivityID, extension);

    m_loggerB->LoadModelSessionStart(loadActivityID, extension);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::LoadModelSessionAbort(const TelemetryTraceUid& loadActivityId, const char* exceptionDetails)
{
    m_loggerA->LoadModelSessionAbort(loadActivityId, exceptionDetails);

    m_loggerB->LoadModelSessionAbort(loadActivityId, exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::LoadModelSessionEnd(const TelemetryTraceUid& loadActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::LoaderStats& loaderStats,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    m_loggerA->LoadModelSessionEnd(
        loadActivityId, success, exceptionDetails, duration, loaderStats, animStats);

    m_loggerB->LoadModelSessionEnd(
        loadActivityId, success, exceptionDetails, duration, loaderStats, animStats);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::SerializeModelSessionStart(const TelemetryTraceUid& serializeActivityId, const char* extension)
{
    m_loggerA->SerializeModelSessionStart(serializeActivityId, extension);

    m_loggerB->SerializeModelSessionStart(serializeActivityId, extension);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::SerializeModelSessionEnd(const TelemetryTraceUid& serializeActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    m_loggerA->SerializeModelSessionEnd(
        serializeActivityId, success, exceptionDetails, duration, animStats);

    m_loggerB->SerializeModelSessionEnd(
        serializeActivityId, success, exceptionDetails, duration, animStats);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::SerializeModelSessionAbort(
    const TelemetryTraceUid& serializeActivityId,
    const char* exceptionDetails)
{
    m_loggerA->SerializeModelSessionAbort(serializeActivityId, exceptionDetails);

    m_loggerB->SerializeModelSessionAbort(serializeActivityId, exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::CanvasException(const char* exceptionDetails)
{
    m_loggerA->CanvasException(exceptionDetails);

    m_loggerB->CanvasException(exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::TranscoderInitialization(
    bool success,
    const char* exceptionDetails,
    const char* packageVersion,
    const char* transcoderVersion)
{
    m_loggerA->TranscoderInitialization(success, exceptionDetails, packageVersion, transcoderVersion);

    m_loggerB->TranscoderInitialization(success, exceptionDetails, packageVersion, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::TranscoderDestroyed(
    int durationMS,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    m_loggerA->TranscoderDestroyed(durationMS, exceptionDetails, transcoderVersion);

    m_loggerB->TranscoderDestroyed(durationMS, exceptionDetails, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::Import3DModelStart(
    const TelemetryTraceUid& importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* importOptions,
    const char* transcoderVersion)
{
    m_loggerA->Import3DModelStart(importActivityID, originalModelExtensionType, destinationModelExtensionType,
        importOptions, transcoderVersion);

    m_loggerB->Import3DModelStart(importActivityID, originalModelExtensionType, destinationModelExtensionType,
        importOptions, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::Import3DModelAbort(
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    uint32_t sizeInKB,
    const char* transcoderVersion)
{
    m_loggerA->Import3DModelAbort(importActivityID, exceptionDetails, sizeInKB, transcoderVersion);

    m_loggerB->Import3DModelAbort(importActivityID, exceptionDetails, sizeInKB, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::Import3DModelEnd(
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
    const char* transcoderVersion)
{
    m_loggerA->Import3DModelEnd(
        importActivityID, success, exceptionDetails, durationMS, originalModelExtensionType, destinationModelExtensionType, vertexCount, indexCount,
        textureCount, vertexBufferMemory, indexBufferMemory, textureMemory, numAnimations, numBones, animationTypes, totalAnimationDuration, sizeInKB,
        transcoderVersion);

    m_loggerB->Import3DModelEnd(
        importActivityID, success, exceptionDetails, durationMS, originalModelExtensionType, destinationModelExtensionType, vertexCount, indexCount,
        textureCount, vertexBufferMemory, indexBufferMemory, textureMemory, numAnimations, numBones, animationTypes, totalAnimationDuration, sizeInKB,
        transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::Export3DModelStart(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* transcoderVersion)
{
    m_loggerA->Export3DModelStart(exportActivityID, importActivityID, originalModelExtensionType, destinationModelExtensionType, transcoderVersion);

    m_loggerB->Export3DModelStart(exportActivityID, importActivityID, originalModelExtensionType, destinationModelExtensionType, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::Export3DModelAbort(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    m_loggerA->Export3DModelAbort(exportActivityID, importActivityID, exceptionDetails, transcoderVersion);

    m_loggerB->Export3DModelAbort(exportActivityID, importActivityID, exceptionDetails, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceDualLogger::Export3DModelEnd(
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
    const char* transcoderVersion)
{
    m_loggerA->Export3DModelEnd(
        exportActivityID, importActivityID, success, exceptionDetails, durationMS, originalModelExtensionType, destinationModelExtensionType, vertexCount,
        indexCount, textureCount, vertexBufferMemory, indexBufferMemory, textureMemory, numAnimations, numBones, animationTypes, totalAnimationDuration,
        transcoderVersion);

    m_loggerB->Export3DModelEnd(
        exportActivityID, importActivityID, success, exceptionDetails, durationMS, originalModelExtensionType, destinationModelExtensionType, vertexCount,
        indexCount, textureCount, vertexBufferMemory, indexBufferMemory, textureMemory, numAnimations, numBones, animationTypes, totalAnimationDuration,
        transcoderVersion);
}
