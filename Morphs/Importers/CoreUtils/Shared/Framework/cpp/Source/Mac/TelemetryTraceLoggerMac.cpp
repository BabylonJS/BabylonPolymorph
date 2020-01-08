/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/


// Include the empty TelemetryTraceLogger stub methods,
// conveniently available for platforms to include until
// they have a native solution.

#include "TelemetryTraceLoggerMac.h"

#include <Framework/ITelemetryTraceLogger.h>
#include <Framework/Types.h>
#include <Framework/TelemetryTraceLoggerJson.h>
#include <CoreUtils/RapidJson.h>
#include <CoreUtils/PimplImpl.h>
#include <uuid/uuid.h>

DEFINE_TRACE_AREA(CoreUtils_TelemetryTracing, 0);

using namespace Spectre::Utils;

namespace
{
    void LogEvent(CanvasCll& canvasCll, std::string eventName, const char* eventData)
    {
        canvasCll.Log(eventName, eventData);
    }
}

//-------------------------------------------------------------------------------------------------

class TelemetryTraceUid::Impl
{
public:
    Impl(): m_uuid()
    {
        uuid_clear(m_uuid);
        m_uuidStr[0] = '\0';
    }

    Impl(uuid_t uuid)
    {
        uuid_copy(m_uuid, uuid);
        uuid_unparse_lower(uuid, m_uuidStr);
    }

    const char* GetUIDAsString() const
    {
        return m_uuidStr;
    }

    bool IsNull() const
    {
        return uuid_is_null(m_uuid) == 1;
    }

private:
    uuid_t m_uuid;
    char m_uuidStr[37];
};

//-------------------------------------------------------------------------------------------------

TelemetryTraceUid TelemetryTraceUid::CreateUid()
{
    uuid_t uuid;
    uuid_generate(uuid);

    return { uuid };
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
    return m_impl->IsNull();
}

const char* TelemetryTraceUid::GetUIDAsString() const
{
    return m_impl->GetUIDAsString();
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

// @TODO: No need for this
const TelemetryTraceUid TelemetryTraceUid::Zero = TelemetryTraceUid();

//-------------------------------------------------------------------------------------------------

TelemetryTraceLoggerMac::TelemetryTraceLoggerMac()
    : m_canvasActivityID(TelemetryTraceUid::CreateUid())
    , m_loadActivityID(TelemetryTraceUid::CreateUid())
    , m_transcoderActivityID(TelemetryTraceUid::CreateUid())
    , m_tag("CanvasDefault")
{
    // TODO: Get processor architecture
    m_architecture = "Mac";

    m_jsonTelemLogger = std::make_shared<TelemetryTraceLoggerJson>(
        [&canvasCll = m_canvasCll](const char* eventName, const char* jsonData)
    {
        // Send the telemetry data out the mac telem pipe
        LogEvent(canvasCll, eventName, jsonData);
    });

    m_jsonTelemLogger->SetBaseArchitecture(m_architecture);
    m_jsonTelemLogger->SetCanvasActivityID(m_canvasActivityID);
    m_jsonTelemLogger->SetTranscoderActivityID(m_transcoderActivityID);
}

//-------------------------------------------------------------------------------------------------

TelemetryTraceLoggerMac::~TelemetryTraceLoggerMac() = default;

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::CanvasInitialization(bool success, const char* exceptionDetails, const char* packageVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->CanvasInitialization(success, exceptionDetails, packageVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::CanvasDestroyed(int durationMS, const char* exceptionDetails)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->CanvasDestroyed(durationMS, exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::CanvasSuspended(int durationMS, const char* exceptionDetails)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->CanvasSuspended(durationMS, exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::LoadModelSessionStart(const TelemetryTraceUid& loadActivityID, const char* extension)
{
    m_canvasCll.IncrementCorrelationVector();
    //NOTE: the telemetry event name is "Load3DModelStart" to minimize breaking changes
    m_jsonTelemLogger->LoadModelSessionStart(loadActivityID, extension);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::LoadModelSessionAbort(const TelemetryTraceUid& loadActivityId, const char* exceptionDetails)
{
    m_canvasCll.IncrementCorrelationVector();
    //NOTE: the telemetry event name is "Load3DModelAbort" to minimize breaking changes
    m_jsonTelemLogger->LoadModelSessionAbort(loadActivityId, exceptionDetails);

    // TODO:
    // Set correlation vector back to base level as leaving Load process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::LoadModelSessionEnd(
    const TelemetryTraceUid& loadActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::LoaderStats& loaderStats,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    m_canvasCll.IncrementCorrelationVector();
    //NOTE: the telemetry event name is "Load3DModelEnd" to minimize breaking changes
    m_jsonTelemLogger->LoadModelSessionEnd(
        loadActivityId, success, exceptionDetails, duration, loaderStats, animStats);

    // TODO: Do we need to reset the correlation vector?
    // Set correlation vector back to base level as leaving Load process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::SerializeModelSessionStart(const TelemetryTraceUid& serializeActivityId, const char* extension)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->SerializeModelSessionStart(serializeActivityId, extension);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::SerializeModelSessionEnd(
    const TelemetryTraceUid& serializeActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->SerializeModelSessionEnd(
        serializeActivityId, success, exceptionDetails, duration, animStats);

    // TODO: Set correlation vector back to base level as leaving Serialize process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::SerializeModelSessionAbort(
    const TelemetryTraceUid& serializeActivityId,
    const char* exceptionDetails)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->SerializeModelSessionAbort(serializeActivityId, exceptionDetails);

    // TODO: Set correlation vector back to base level as leaving Serialize process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::CanvasException(const char* exceptionDetails)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->CanvasException(exceptionDetails);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::TranscoderInitialization(
    bool success,
    const char* exceptionDetails,
    const char* packageVersion,
    const char* transcoderVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->TranscoderInitialization(success, exceptionDetails, packageVersion, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::TranscoderDestroyed(
    int durationMS,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->TranscoderDestroyed(durationMS, exceptionDetails, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::Import3DModelStart(
    const TelemetryTraceUid&  importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* importOptions,
    const char* transcoderVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->Import3DModelStart(importActivityID, originalModelExtensionType, destinationModelExtensionType,
        importOptions, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::Import3DModelAbort(
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    uint32_t sizeInKB,
    const char* transcoderVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->Import3DModelAbort(importActivityID, exceptionDetails, sizeInKB, transcoderVersion);

    // TODO: Set correlation vector back to base level as leaving import process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::Import3DModelEnd(
    const TelemetryTraceUid& importActivityID,
    bool success,
    const char* exceptionDetails,
    int durationMS,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    size_t vertexCount,
    size_t indexCount,
    size_t textureCount,
    long long vertexBufferMemory,
    long long indexBufferMemory,
    long long textureMemory,
    unsigned int numAnimations,
    unsigned int numBones,
    unsigned int animationTypes,
    float totalAnimationDuration,
    uint32_t sizeInKB,
    const char* transcoderVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->Import3DModelEnd(
        importActivityID, success, exceptionDetails, durationMS, originalModelExtensionType, destinationModelExtensionType, vertexCount, indexCount,
        textureCount, vertexBufferMemory, indexBufferMemory, textureMemory, numAnimations, numBones, animationTypes, totalAnimationDuration, sizeInKB,
        transcoderVersion);

    // TODO: Set correlation vector back to base level as leaving import process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::Export3DModelStart(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* transcoderVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->Export3DModelStart(exportActivityID, importActivityID, originalModelExtensionType, destinationModelExtensionType, transcoderVersion);
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::Export3DModelAbort(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    m_canvasCll.IncrementCorrelationVector();
    m_jsonTelemLogger->Export3DModelAbort(exportActivityID, importActivityID, exceptionDetails, transcoderVersion);

    // TODO: Set correlation vector back to base level as leaving export process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerMac::Export3DModelEnd(
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
    long long vertexBufferMemory,
    long long indexBufferMemory,
    long long textureMemory,
    unsigned int numAnimations,
    unsigned int numBones,
    unsigned int animationTypes,
    float totalAnimationDuration,
    const char* transcoderVersion)
{
    m_jsonTelemLogger->Export3DModelEnd(
        exportActivityID, importActivityID, success, exceptionDetails, durationMS, originalModelExtensionType, destinationModelExtensionType, vertexCount,
        indexCount, textureCount, vertexBufferMemory, indexBufferMemory, textureMemory, numAnimations, numBones, animationTypes, totalAnimationDuration,
        transcoderVersion);

    // TODO: Set correlation vector back to base level as leaving export process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
}
