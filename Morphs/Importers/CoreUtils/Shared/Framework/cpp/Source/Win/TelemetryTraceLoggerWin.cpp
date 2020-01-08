/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "FrameworkPch.h"
#include "TelemetryTraceLoggerWin.h"

#include <atomic>


DEFINE_TRACE_AREA(CoreUtils_TelemetryTracing, 0);

using namespace Spectre::Utils;

namespace
{
    const char* GetSuccessMessage(bool success)
    {
        return success ? "success" : "fail";
    }
}

//-------------------------------------------------------------------------------------------------

class TelemetryTraceUid::Impl
{
public:
    TelemetryTraceUid::Impl() : m_guid() // This ensures that m_guid is zero-initialized
    {
    }

    TelemetryTraceUid::Impl(GUID guid) : m_guid(guid)
    {
        ConvertToCharArray();
    }

    const GUID& GetGUID() const
    {
        return m_guid;
    }

    const char* GetUIDAsString() const
    {
        if (m_guidAsCharArray[0] == 0)
        {
            ConvertToCharArray();
        }

        return m_guidAsCharArray;
    }

private:
    const static uint32_t NUMCHARSINGUID = 40;

    void ConvertToCharArray() const
    {
        wchar_t bufWide[NUMCHARSINGUID] = { 0 };
        char mbBuf[NUMCHARSINGUID] = { 0 };
        StringFromGUID2(m_guid, bufWide, NUMCHARSINGUID);
        WideCharToMultiByte(CP_ACP, 0, bufWide, -1, mbBuf, NUMCHARSINGUID, NULL, NULL);

        // strip the opening and closing curly braces, if present
        char* src = mbBuf;
        char* dest = m_guidAsCharArray;
        uint32_t count = 0;
        while (*src && count < NUMCHARSINGUID) // extra safe
        {
            if (*src != '{' && *src != '}')
            {
                *dest++ = *src;
            }
            src++;
            count++;
        }
        *dest = '\0';
    }

    GUID m_guid;
    mutable char m_guidAsCharArray[NUMCHARSINGUID] = { 0 };
};

//-------------------------------------------------------------------------------------------------

TelemetryTraceUid TelemetryTraceUid::CreateUid()
{
    GUID guid;

    // According to MSDN CoCreateGuid/UuidCreate only return success codes (even when a GUID
    // isn't guaranteed to be globally unique) so check for S_OK rather than using SUCCEEDED
    if (::CoCreateGuid(&guid) == S_OK)
    {
        return { guid };
    }
    else
    {
        TRACE_WARN(CoreUtils_TelemetryTracing, "Unable to generate a valid, globally unique, GUID");
    }

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
    return m_impl->GetGUID() == Zero.m_impl->GetGUID();
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

const TelemetryTraceUid TelemetryTraceUid::Zero = TelemetryTraceUid();

//-------------------------------------------------------------------------------------------------
/*
The following values could be included from <telemetry\MicrosoftTelemetry.h>
But, this header file is only available to internal builds of windows.
So, we are copying the values here.
*/
#define MICROSOFT_KEYWORD_MEASURES 0x0000400000000000 // Bit 46
#define MICROSOFT_KEYWORD_TELEMETRY 0x0000200000000000 // Bit 45
#define TraceLoggingOptionMicrosoftTelemetry() TraceLoggingOptionGroup(0x4f50731a, 0x89cf, 0x4782, 0xb3, 0xe0, 0xdc, 0xe8, 0xc9, 0x4, 0x76, 0xba)

// Define the GUID for TelemetryProvider
// {0d481997-5998-51af-4ea5-afefe9651b0f}
TRACELOGGING_DEFINE_PROVIDER(
    g_SpectreLoggingTelemetryProvider,
    "Microsoft.Beihai.Core.Canvas",
    (0x0d481997, 0x5998, 0x51af, 0x4e, 0xa5, 0xaf, 0xef, 0xe9, 0x65, 0x1b, 0x0f),
    TraceLoggingOptionMicrosoftTelemetry());

#define TraceLoggingWriteTelemetry(eventName, ...) \
    TraceLoggingWrite( \
        g_SpectreLoggingTelemetryProvider, \
        eventName, \
        TraceLoggingCV(m_correlationVector.get()), \
        TraceLoggingKeyword(MICROSOFT_KEYWORD_TELEMETRY), \
        TraceLoggingBool(true, "UTCReplace_AppSessionGuid"), \
        __VA_ARGS__ \
    )

#define TraceLoggingWriteMeasures(eventName, ...) \
    TraceLoggingWrite( \
        g_SpectreLoggingTelemetryProvider, \
        eventName, \
        TraceLoggingCV(m_correlationVector.get()), \
        TraceLoggingKeyword(MICROSOFT_KEYWORD_MEASURES), \
        TraceLoggingBool(true, "UTCReplace_AppSessionGuid"), \
        __VA_ARGS__ \
    )

// An ETW provider can't be registered if it already is,
// so we need to make sure to only do so once even in the
// case of multiple concurrent ETWTraceProvider instances.
static std::atomic<size_t>               s_registrationCount;

//-------------------------------------------------------------------------------------------------

TelemetryTraceLoggerWin::TelemetryTraceLoggerWin()
    : m_canvasActivityID(TelemetryTraceUid::CreateUid())
    , m_transcoderActivityID(TelemetryTraceUid::CreateUid())
    , m_loadActivityID(TelemetryTraceUid::Zero)
    , m_tag("CanvasDefault")
{
    // Get processor architecture
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    switch (systemInfo.wProcessorArchitecture) {
    case PROCESSOR_ARCHITECTURE_AMD64:
        m_architecture = "x64";
        break;
    case PROCESSOR_ARCHITECTURE_ARM:
        m_architecture = "ARM";
        break;
    case PROCESSOR_ARCHITECTURE_ARM64:
        m_architecture = "ARM64";
        break;
    case PROCESSOR_ARCHITECTURE_INTEL:
        m_architecture = "WIN32";
        break;
    default:
        m_architecture = "UNKNOWN";
        break;
    }

    // Generate a new Correlation Vector
    m_correlationVector = std::make_unique<TraceLoggingCorrelationVector>();
    // Store the CV string
    m_correlationVector->ToString(m_baseSzCv);

    if (s_registrationCount++ == 0)
    {
        TraceLoggingRegister(g_SpectreLoggingTelemetryProvider);
    }

    m_attributes = std::make_shared<TelemTraceLoggerAttributes>(m_canvasActivityID, m_transcoderActivityID, m_architecture);
}

//-------------------------------------------------------------------------------------------------

TelemetryTraceLoggerWin::~TelemetryTraceLoggerWin()
{
    if (--s_registrationCount == 0)
    {
        TraceLoggingUnregister(g_SpectreLoggingTelemetryProvider);
    }
}

//-------------------------------------------------------------------------------------------------

const std::shared_ptr<TelemTraceLoggerAttributes> TelemetryTraceLoggerWin::GetAttributes()
{
    return m_attributes;
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::SetCorrelationVectorGUID(TelemetryTraceLoggerCorrelationVectorId guid)
{
    // Set CorrelationVector if not null
    if (guid != GUID_NULL)
    {
        m_correlationVector.reset(new TraceLoggingCorrelationVector(guid));
        // Store the CV string
        m_correlationVector->ToString(m_baseSzCv);
    }
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::CanvasInitialization(bool success, const char* exceptionDetails, const char* packageVersion)
{
    m_correlationVector->Increment(m_baseSzCv);
    const char * result = "success";
    if (!success) result = "fail";
    TraceLoggingWriteMeasures(
        "CanvasInitialization",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(result, "result"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(m_architecture.c_str(), "architecture"),
        TraceLoggingValue(packageVersion, "packageVersion")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::CanvasDestroyed(int durationMS, const char* exceptionDetails)
{
    m_correlationVector->Increment(m_baseSzCv);
    TraceLoggingWriteMeasures(
        "CanvasDestroyed",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(durationMS, "durationMS"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::CanvasSuspended(int durationMS, const char* exceptionDetails)
{
    m_correlationVector->Increment(m_baseSzCv);
    TraceLoggingWriteMeasures(
        "CanvasSuspended",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(durationMS, "durationMS"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::LoadModelSessionStart(const TelemetryTraceUid& loadActivityID, const char* extension)
{
    // set new loadActivityID that will be used for performance telemetry
    m_loadActivityID = loadActivityID;
    // Set correlationVector to base level before extend, to avoid overflow
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
    m_correlationVector->Increment(m_baseSzCv);
    // Extend correlation vector for load events. Eg. xxxx.2 -> xxxx.2.0
    m_correlationVector.reset(TraceLoggingCorrelationVector::Extend(m_baseSzCv));
    // Store CV string for current load event
    m_correlationVector->ToString(m_secondSzCv);

    //NOTE: the telemetry event name is "Load3DModelStart" to minimize breaking changes
    TraceLoggingWriteMeasures(
        "Load3DModelStart",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(loadActivityID.m_impl->GetGUID(), "loadActivityID"),
        TraceLoggingValue(extension, "extension"));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::LoadModelSessionAbort(const TelemetryTraceUid& loadActivityId, const char* exceptionDetails)
{
    m_correlationVector->Increment(m_secondSzCv);

    //NOTE: the telemetry event name is "Load3DModelAbort" to minimize breaking changes
    TraceLoggingWriteMeasures(
        "Load3DModelAbort",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(loadActivityId.m_impl->GetGUID(), "loadActivityID"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails")
    );

    // Set correlation vector back to base level as leaving Load process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::LoadModelSessionEnd(const TelemetryTraceUid& loadActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::LoaderStats& loaderStats,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    m_correlationVector->Increment(m_secondSzCv);

    //NOTE: the telemetry event name is "Load3DModelEnd" to minimize breaking changes
    TraceLoggingWriteMeasures(
        "Load3DModelEnd",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(loadActivityId.m_impl->GetGUID(), "loadActivityID"),
        TraceLoggingValue(::GetSuccessMessage(success), "result"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(duration.count(), "durationMS"),
        TraceLoggingValue(loaderStats.m_nodeCount, "nodeCount"),
        TraceLoggingValue(loaderStats.m_meshInstanceCount, "meshInstanceCount"),
        TraceLoggingValue(loaderStats.m_meshCount, "meshCount"),
        TraceLoggingValue(loaderStats.m_materialCount, "materialCount"),
        TraceLoggingValue(loaderStats.m_indexCount, "indexCount"),
        TraceLoggingValue(loaderStats.m_vertexCount, "vertexCount"),
        TraceLoggingValue(loaderStats.m_textureCount, "textureCount"),
        TraceLoggingValue(loaderStats.m_indexDataSize, "indexDataSize"),
        TraceLoggingValue(loaderStats.m_vertexDataSize, "vertexDataSize"),
        TraceLoggingValue(loaderStats.m_textureDataSize, "textureDataSize"),
        TraceLoggingValue(animStats.m_numAnimations, "numAnimations"),
        TraceLoggingValue(static_cast<uint32_t>(animStats.m_boneIds.size()), "numBones"),
        TraceLoggingValue(static_cast<uint32_t>(animStats.m_animationTypes.to_ulong()), "animationTypes"),
        TraceLoggingValue(animStats.m_totalAnimationDuration, "animationDuration"));

    // Set correlation vector back to base level as leaving Load process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::SerializeModelSessionStart(const TelemetryTraceUid& serializeActivityId, const char* extension)
{
    // Set correlationVector to base level before extend, to avoid overflow
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
    m_correlationVector->Increment(m_baseSzCv);
    // Extend correlation vector for serialize events. Eg. xxxx.2 -> xxxx.2.0
    m_correlationVector.reset(TraceLoggingCorrelationVector::Extend(m_baseSzCv));
    // Store CV string for current serialize event
    m_correlationVector->ToString(m_secondSzCv);

    TraceLoggingWriteMeasures(
        "SerializeModelSessionStart",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(serializeActivityId.m_impl->GetGUID(), "serializeActivityID"),
        TraceLoggingValue(extension, "extension"));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::SerializeModelSessionEnd(const TelemetryTraceUid& serializeActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    m_correlationVector->Increment(m_secondSzCv);

    TraceLoggingWriteMeasures(
        "SerializeModelSessionEnd",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(serializeActivityId.m_impl->GetGUID(), "serializeActivityID"),
        TraceLoggingValue(::GetSuccessMessage(success), "result"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(duration.count(), "durationMS"),
        TraceLoggingValue(animStats.m_numAnimations, "numAnimations"),
        TraceLoggingValue(static_cast<uint32_t>(animStats.m_boneIds.size()), "numBones"),
        TraceLoggingValue(static_cast<uint32_t>(animStats.m_animationTypes.to_ulong()), "animationTypes"),
        TraceLoggingValue(animStats.m_totalAnimationDuration, "animationDuration")
    );

    // Set correlation vector back to base level as leaving Serialize process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::SerializeModelSessionAbort(
    const TelemetryTraceUid& serializeActivityId,
    const char* exceptionDetails)
{
    m_correlationVector->Increment(m_secondSzCv);

    TraceLoggingWriteMeasures(
        "SerializeModelSessionAbort",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(serializeActivityId.m_impl->GetGUID(), "serializeActivityID"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails")
    );

    // Set correlation vector back to base level as leaving Serialize process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::CanvasException(const char* exceptionDetails)
{
    m_correlationVector->Increment(m_baseSzCv);

    TraceLoggingWriteMeasures(
        "CanvasException",
        TraceLoggingValue(m_canvasActivityID.m_impl->GetGUID(), "canvasActivityID"),
        TraceLoggingValue(m_loadActivityID.m_impl->GetGUID(), "loadActivityID"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::TranscoderInitialization(
    bool success,
    const char* exceptionDetails,
    const char* packageVersion,
    const char* transcoderVersion)
{
    m_correlationVector->Increment(m_baseSzCv);
    const char * result = "success";
    if (!success) result = "fail";
    TraceLoggingWriteMeasures(
        "TranscoderInitialization",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(result, "result"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(m_architecture.c_str(), "architecture"),
        TraceLoggingValue(packageVersion, "packageVersion"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::TranscoderDestroyed(
    int durationMS,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    m_correlationVector->Increment(m_baseSzCv);
    TraceLoggingWriteMeasures(
        "TranscoderDestroyed",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(durationMS, "durationMS"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::Import3DModelStart(
    const TelemetryTraceUid& importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* importOptions,
    const char* transcoderVersion)
{
    // Set correlationVector to base level before extend, to avoid overflow
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
    m_correlationVector->Increment(m_baseSzCv);
    // Extend correlation vector for import events. Eg. xxxx.2 -> xxxx.2.0
    m_correlationVector.reset(TraceLoggingCorrelationVector::Extend(m_baseSzCv));
    // Store CV string for current load event
    m_correlationVector->ToString(m_secondSzCv);
    TraceLoggingWriteMeasures(
        "Import3DModelStart",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(importActivityID.m_impl->GetGUID(), "importActivityID"),
        TraceLoggingValue(originalModelExtensionType, "originalModelExtensionType"),
        TraceLoggingValue(destinationModelExtensionType, "destinationModelExtensionType"),
        TraceLoggingValue(importOptions, "importOptions"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::Import3DModelAbort(
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    uint32_t sizeInKB,
    const char* transcoderVersion)
{
    m_correlationVector->Increment(m_secondSzCv);
    TraceLoggingWriteMeasures(
        "Import3DModelAbort",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(importActivityID.m_impl->GetGUID(), "importActivityID"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(sizeInKB, "sizeInKB"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
    // Set correlation vector back to base level as leaving import process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::Import3DModelEnd(
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
    m_correlationVector->Increment(m_secondSzCv);
    const char * result = "success";
    if (!success) result = "fail";
    TraceLoggingWriteMeasures(
        "Import3DModelEnd",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(importActivityID.m_impl->GetGUID(), "importActivityID"),
        TraceLoggingValue(result, "result"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(durationMS, "durationMS"),
        TraceLoggingValue(originalModelExtensionType, "originalModelExtensionType"),
        TraceLoggingValue(destinationModelExtensionType, "destinationModelExtensionType"),
        TraceLoggingValue(vertexCount, "vertexCount"),
        TraceLoggingValue(indexCount, "indexCount"),
        TraceLoggingValue(textureCount, "textureCount"),
        TraceLoggingValue(vertexBufferMemory, "vertexBufferMemory"),
        TraceLoggingValue(indexBufferMemory, "indexBufferMemory"),
        TraceLoggingValue(textureMemory, "textureMemory"),
        TraceLoggingValue(numAnimations, "numAnimations"),
        TraceLoggingValue(numBones, "numBones"),
        TraceLoggingValue(animationTypes, "animationTypes"),
        TraceLoggingValue(totalAnimationDuration, "animationDuration"),
        TraceLoggingValue(sizeInKB, "sizeInKB"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
    // Set correlation vector back to base level as leaving import process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::Export3DModelStart(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* transcoderVersion)
{
    // Set correlationVector to base level before extend, to avoid overflow
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
    m_correlationVector->Increment(m_baseSzCv);
    // Extend correlation vector for export events. Eg. xxxx.2 -> xxxx.2.0
    m_correlationVector.reset(TraceLoggingCorrelationVector::Extend(m_baseSzCv));
    // Store CV string for current load event
    m_correlationVector->ToString(m_secondSzCv);
    TraceLoggingWriteMeasures(
        "Export3DModelStart",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(exportActivityID.m_impl->GetGUID(), "exportActivityID"),
        TraceLoggingValue(importActivityID.m_impl->GetGUID(), "importActivityID"),
        TraceLoggingValue(originalModelExtensionType, "originalModelExtensionType"),
        TraceLoggingValue(destinationModelExtensionType, "destinationModelExtensionType"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::Export3DModelAbort(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    m_correlationVector->Increment(m_secondSzCv);
    TraceLoggingWriteMeasures(
        "Export3DModelAbort",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(exportActivityID.m_impl->GetGUID(), "exportActivityID"),
        TraceLoggingValue(importActivityID.m_impl->GetGUID(), "importActivityID"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
    // Set correlation vector back to base level as leaving export process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerWin::Export3DModelEnd(
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
    m_correlationVector->Increment(m_secondSzCv);
    const char * result = "success";
    if (!success) result = "fail";
    TraceLoggingWriteMeasures(
        "Export3DModelEnd",
        TraceLoggingValue(m_transcoderActivityID.m_impl->GetGUID(), "transcoderActivityID"),
        TraceLoggingValue(exportActivityID.m_impl->GetGUID(), "exportActivityID"),
        TraceLoggingValue(importActivityID.m_impl->GetGUID(), "importActivityID"),
        TraceLoggingValue(result, "result"),
        TraceLoggingValue(exceptionDetails, "exceptionDetails"),
        TraceLoggingValue(durationMS, "durationMS"),
        TraceLoggingValue(originalModelExtensionType, "originalModelExtensionType"),
        TraceLoggingValue(destinationModelExtensionType, "destinationModelExtensionType"),
        TraceLoggingValue(vertexCount, "vertexCount"),
        TraceLoggingValue(indexCount, "indexCount"),
        TraceLoggingValue(textureCount, "textureCount"),
        TraceLoggingValue(vertexBufferMemory, "vertexBufferMemory"),
        TraceLoggingValue(indexBufferMemory, "indexBufferMemory"),
        TraceLoggingValue(textureMemory, "textureMemory"),
        TraceLoggingValue(numAnimations, "numAnimations"),
        TraceLoggingValue(numBones, "numBones"),
        TraceLoggingValue(animationTypes, "animationTypes"),
        TraceLoggingValue(totalAnimationDuration, "animationDuration"),
        TraceLoggingValue(transcoderVersion, "transcoderVersion")
    );
    // Set correlation vector back to base level as leaving export process.
    // Eg. xxxx.2.2 -> xxxx.2  The next event will be xxxx.3
    m_correlationVector.reset(TraceLoggingCorrelationVector::Set(m_baseSzCv));
}
