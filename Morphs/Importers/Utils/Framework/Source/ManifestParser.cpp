/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/ManifestParser.h>
#include <CoreUtils/RapidJson.h>
#include <CoreUtils/StringUtils.h>

typedef Babylon::rapidjson::GenericDocument<Babylon::rapidjson::UTF16<>> WDocument;
typedef Babylon::rapidjson::GenericValue<Babylon::rapidjson::UTF16<>> WValue;

namespace Babylon
{
namespace Framework
{

ManifestParser::ManifestParser(std::wstring const& jsonString)
{
    WDocument root;
    root.Parse(jsonString.c_str());

    m_manifest.Id = root[L"Id"].GetString();
    m_manifest.PackageVersion = root[L"PackageVersion"].GetString();

    for (const auto& member : root[L"Resource"].GetObject())
    {
        for (const auto& frameData : member.value.GetArray())
        {
            FrameContent content;
            content.LOD = (Framework::EFrameQuality)frameData[L"LOD"].GetInt();
            content.Compression = (Framework::EFrameCompression)frameData[L"Compression"].GetInt();
            content.StreamGUID = frameData[L"StreamGUID"].GetString();
            if (frameData.HasMember(L"Size"))
            {
                content.Size = frameData[L"Size"].GetUint64();
            }

            Framework::EFrameType frameType = Framework::kFrameUnknown;
            std::wstring frameTypeStr = member.name.GetString();

            if (frameTypeStr == L"Geometry")  frameType = Framework::kFrameGeom;
            else if (frameTypeStr == L"Material")  frameType = Framework::kFrameMaterial;
            else if (frameTypeStr == L"Metadata")  frameType = Framework::kFrameMetadata;
            else if (frameTypeStr == L"Scene")     frameType = Framework::kFrameScene;
            else if (frameTypeStr == L"Texture")   frameType = Framework::kFrameTexture;
            else if (frameTypeStr == L"Animation") frameType = Framework::kFrameAnim;

            m_manifest[frameType].push_back(content);
        }
    }
}

} // namespace Engine
} // namespace Babylon
