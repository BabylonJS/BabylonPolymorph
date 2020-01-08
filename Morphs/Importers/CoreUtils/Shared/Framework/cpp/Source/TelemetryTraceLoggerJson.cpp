/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/


#include "FrameworkPch.h"
#include <Framework/TelemetryTraceLoggerJson.h>

#include <Framework/Types.h>
#include <CoreUtils/RapidJson.h>
#include <CoreUtils/PimplImpl.h>

using namespace Spectre::Utils;

//-------------------------------------------------------------------------------------------------

namespace
{
    const char* GetSuccessMessage(bool success)
    {
        return success ? "success" : "fail";
    }

    const char* EnsureNotNull(const char* s)
    {
        return s != nullptr ? s : "";
    }

    std::shared_ptr<const std::string> GetJsonTelemDataString(Spectre::rapidjson::Document& event)
    {
        Spectre::rapidjson::StringBuffer buffer;
        Spectre::rapidjson::Writer<Spectre::rapidjson::StringBuffer> writer(buffer);
        event.Accept(writer);
        return std::make_shared<const std::string>(buffer.GetString());
    }
}

//-------------------------------------------------------------------------------------------------

TelemetryTraceLoggerJson::TelemetryTraceLoggerJson(TelemetryTraceLoggerClientCallback callback)
    : m_canvasActivityID(TelemetryTraceUid::Zero)
    , m_loadActivityID(TelemetryTraceUid::Zero)
    , m_transcoderActivityID(TelemetryTraceUid::Zero)
    , m_tag("CanvasDefault")
    , m_telemetryCallback(callback)
{
    m_baseArchitecture = "Unknown";
}

//-------------------------------------------------------------------------------------------------

TelemetryTraceLoggerJson::~TelemetryTraceLoggerJson() = default;

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::CanvasInitialization(bool success, const char* exceptionDetails, const char* packageVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("result", rapidjson::StringRef(GetSuccessMessage(success)), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("architecture", rapidjson::StringRef(m_baseArchitecture.c_str()), doc.GetAllocator());
    doc.AddMember("packageVersion", rapidjson::StringRef(EnsureNotNull(packageVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("CanvasInitialization", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::CanvasDestroyed(int durationMS, const char* exceptionDetails)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("durationMS", durationMS, doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("CanvasDestroyed", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::CanvasSuspended(int durationMS, const char* exceptionDetails)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("durationMS", durationMS, doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("CanvasSuspended", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::LoadModelSessionStart(const TelemetryTraceUid& loadActivityID, const char* extension)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("loadActivityID", rapidjson::StringRef(loadActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("extension", rapidjson::StringRef(EnsureNotNull(extension)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Load3DModelStart", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::LoadModelSessionAbort(const TelemetryTraceUid& loadActivityId, const char* exceptionDetails)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("loadActivityID", rapidjson::StringRef(loadActivityId.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Load3DModelAbort", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::LoadModelSessionEnd(
    const TelemetryTraceUid& loadActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::LoaderStats& loaderStats,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("loadActivityID", rapidjson::StringRef(loadActivityId.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("result", rapidjson::StringRef(GetSuccessMessage(success)), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("durationMS", static_cast<int64_t>(duration.count()), doc.GetAllocator());

    doc.AddMember("nodeCount", loaderStats.m_nodeCount, doc.GetAllocator());
    doc.AddMember("meshInstanceCount", loaderStats.m_meshInstanceCount, doc.GetAllocator());
    doc.AddMember("meshCount", loaderStats.m_meshCount, doc.GetAllocator());
    doc.AddMember("materialCount", loaderStats.m_materialCount, doc.GetAllocator());
    doc.AddMember("indexCount", loaderStats.m_indexCount, doc.GetAllocator());
    doc.AddMember("vertexCount", loaderStats.m_vertexCount, doc.GetAllocator());
    doc.AddMember("textureCount", loaderStats.m_textureCount, doc.GetAllocator());
    doc.AddMember("indexDataSize", loaderStats.m_indexDataSize, doc.GetAllocator());
    doc.AddMember("vertexDataSize", loaderStats.m_vertexDataSize, doc.GetAllocator());
    doc.AddMember("textureDataSize", loaderStats.m_textureDataSize, doc.GetAllocator());

    doc.AddMember("numAnimations", animStats.m_numAnimations, doc.GetAllocator());
    doc.AddMember("numBones", static_cast<uint32_t>(animStats.m_boneIds.size()), doc.GetAllocator());
    doc.AddMember("animationTypes", static_cast<uint32_t>(animStats.m_animationTypes.to_ulong()), doc.GetAllocator());
    doc.AddMember("animationDuration", animStats.m_totalAnimationDuration, doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Load3DModelEnd", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::SerializeModelSessionStart(const TelemetryTraceUid& serializeActivityId, const char* extension)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("serializeActivityID", rapidjson::StringRef(serializeActivityId.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("extension", rapidjson::StringRef(EnsureNotNull(extension)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("SerializeModelSessionStart", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::SerializeModelSessionEnd(
    const TelemetryTraceUid& serializeActivityId,
    bool success,
    const char* exceptionDetails,
    std::chrono::milliseconds duration,
    const TelemetryTraceLogger::AnimationStats& animStats)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("serializeActivityID", rapidjson::StringRef(serializeActivityId.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("result", rapidjson::StringRef(::GetSuccessMessage(success)), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("durationMS", static_cast<int64_t>(duration.count()), doc.GetAllocator());
    doc.AddMember("numAnimations", animStats.m_numAnimations, doc.GetAllocator());
    doc.AddMember("numBones", static_cast<uint32_t>(animStats.m_boneIds.size()), doc.GetAllocator());
    doc.AddMember("animationTypes", static_cast<uint32_t>(animStats.m_animationTypes.to_ulong()), doc.GetAllocator());
    doc.AddMember("animationDuration", animStats.m_totalAnimationDuration, doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("SerializeModelSessionEnd", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::SerializeModelSessionAbort(
    const TelemetryTraceUid& serializeActivityId,
    const char* exceptionDetails)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("serializeActivityID", rapidjson::StringRef(serializeActivityId.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("SerializeModelSessionAbort", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::CanvasException(const char* exceptionDetails)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("canvasActivityID", rapidjson::StringRef(m_canvasActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("loadActivityID", rapidjson::StringRef(m_loadActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("CanvasException", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::TranscoderInitialization(
    bool success,
    const char* exceptionDetails,
    const char* packageVersion,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("result", rapidjson::StringRef(GetSuccessMessage(success)), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("architecture", rapidjson::StringRef(m_baseArchitecture.c_str()), doc.GetAllocator());
    doc.AddMember("packageVersion", rapidjson::StringRef(EnsureNotNull(packageVersion)), doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("TranscoderInitialization", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::TranscoderDestroyed(
    int durationMS,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("durationMS", durationMS, doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("TranscoderDestroyed", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::Import3DModelStart(
    const TelemetryTraceUid&  importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* importOptions,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("importActivityID", rapidjson::StringRef(importActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("originalModelExtensionType", rapidjson::StringRef(EnsureNotNull(originalModelExtensionType)), doc.GetAllocator());
    doc.AddMember("destinationModelExtensionType", rapidjson::StringRef(EnsureNotNull(destinationModelExtensionType)), doc.GetAllocator());
    doc.AddMember("importOptions", rapidjson::StringRef(EnsureNotNull(importOptions)), doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Import3DModelStart", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::Import3DModelAbort(
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    uint32_t sizeInKB,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("importActivityID", rapidjson::StringRef(importActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("sizeInKB", sizeInKB, doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Import3DModelAbort", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::Import3DModelEnd(
    const TelemetryTraceUid& importActivityID,
    bool success,
    const char* exceptionDetails,
    int durationMS,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    size_t vertexCount,
    size_t indexCount,
    size_t textureCount,
    int64_t  vertexBufferMemory,
    int64_t  indexBufferMemory,
    int64_t  textureMemory,
    unsigned int numAnimations,
    unsigned int numBones,
    unsigned int animationTypes,
    float totalAnimationDuration,
    uint32_t sizeInKB,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("importActivityID", rapidjson::StringRef(importActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("result", rapidjson::StringRef(GetSuccessMessage(success)), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("durationMS", durationMS, doc.GetAllocator());
    doc.AddMember("originalModelExtensionType", rapidjson::StringRef(EnsureNotNull(originalModelExtensionType)), doc.GetAllocator());
    doc.AddMember("destinationModelExtensionType", rapidjson::StringRef(EnsureNotNull(destinationModelExtensionType)), doc.GetAllocator());
    doc.AddMember("vertexCount", static_cast<uint32_t>(vertexCount), doc.GetAllocator());
    doc.AddMember("indexCount", static_cast<uint32_t>(indexCount), doc.GetAllocator());
    doc.AddMember("textureCount", static_cast<uint32_t>(textureCount), doc.GetAllocator());
    doc.AddMember("vertexBufferMemory", vertexBufferMemory, doc.GetAllocator());
    doc.AddMember("indexBufferMemory", indexBufferMemory, doc.GetAllocator());
    doc.AddMember("textureMemory", textureMemory, doc.GetAllocator());
    doc.AddMember("numAnimations", numAnimations, doc.GetAllocator());
    doc.AddMember("numBones", numBones, doc.GetAllocator());
    doc.AddMember("animationTypes", animationTypes, doc.GetAllocator());
    doc.AddMember("animationDuration", totalAnimationDuration, doc.GetAllocator());
    doc.AddMember("sizeInKB", sizeInKB, doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Import3DModelEnd", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::Export3DModelStart(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* originalModelExtensionType,
    const char* destinationModelExtensionType,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exportActivityID", rapidjson::StringRef(exportActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("importActivityID", rapidjson::StringRef(importActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("originalModelExtensionType", rapidjson::StringRef(EnsureNotNull(originalModelExtensionType)), doc.GetAllocator());
    doc.AddMember("destinationModelExtensionType", rapidjson::StringRef(EnsureNotNull(destinationModelExtensionType)), doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Export3DModelStart", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::Export3DModelAbort(
    const TelemetryTraceUid& exportActivityID,
    const TelemetryTraceUid& importActivityID,
    const char* exceptionDetails,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exportActivityID", rapidjson::StringRef(exportActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("importActivityID", rapidjson::StringRef(importActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Export3DModelAbort", telemData->c_str());
}

//-------------------------------------------------------------------------------------------------

void TelemetryTraceLoggerJson::Export3DModelEnd(
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
    int64_t  vertexBufferMemory,
    int64_t  indexBufferMemory,
    int64_t  textureMemory,
    unsigned int numAnimations,
    unsigned int numBones,
    unsigned int animationTypes,
    float totalAnimationDuration,
    const char* transcoderVersion)
{
    if (m_telemetryCallback == nullptr)
        return;

    Spectre::rapidjson::Document doc;
    doc.SetObject();
    doc.AddMember("transcoderActivityID", rapidjson::StringRef(m_transcoderActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("exportActivityID", rapidjson::StringRef(exportActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("importActivityID", rapidjson::StringRef(importActivityID.GetUIDAsString()), doc.GetAllocator());
    doc.AddMember("result", rapidjson::StringRef(GetSuccessMessage(success)), doc.GetAllocator());
    doc.AddMember("exceptionDetails", rapidjson::StringRef(EnsureNotNull(exceptionDetails)), doc.GetAllocator());
    doc.AddMember("durationMS", durationMS, doc.GetAllocator());
    doc.AddMember("originalModelExtensionType", rapidjson::StringRef(EnsureNotNull(originalModelExtensionType)), doc.GetAllocator());
    doc.AddMember("destinationModelExtensionType", rapidjson::StringRef(EnsureNotNull(destinationModelExtensionType)), doc.GetAllocator());
    doc.AddMember("vertexCount", static_cast<uint32_t>(vertexCount), doc.GetAllocator());
    doc.AddMember("indexCount", static_cast<uint32_t>(indexCount), doc.GetAllocator());
    doc.AddMember("textureCount", static_cast<uint32_t>(textureCount), doc.GetAllocator());
    doc.AddMember("vertexBufferMemory", vertexBufferMemory, doc.GetAllocator());
    doc.AddMember("indexBufferMemory", indexBufferMemory, doc.GetAllocator());
    doc.AddMember("textureMemory", textureMemory, doc.GetAllocator());
    doc.AddMember("numAnimations", numAnimations, doc.GetAllocator());
    doc.AddMember("numBones", numBones, doc.GetAllocator());
    doc.AddMember("animationTypes", animationTypes, doc.GetAllocator());
    doc.AddMember("animationDuration", totalAnimationDuration, doc.GetAllocator());
    doc.AddMember("transcoderVersion", rapidjson::StringRef(EnsureNotNull(transcoderVersion)), doc.GetAllocator());

    auto telemData = GetJsonTelemDataString(doc);
    m_telemetryCallback("Export3DModelEnd", telemData->c_str());
}


