/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <ExporterGLTF/ExtensionsMSFT.h>

// NOTE: We are using the GLTFSDK version of rapidjson (through RapidJsonUtils) since the Serialize.h API takes a GLTFSDK rapidjson.
// This means that we must be compiled with the same version of rapidjson as when the GLTFSDK was compiled.
// If we were to diverge versions then we could get runtime errors as we may be linking with the wrong code.
// The only safe way to resolve this is to not expose the use of rapidjson outside of the GLTFSDK.
#include <GLTFSDK/RapidJsonUtils.h>
#include <GLTFSDK/Document.h>
#include <GLTFSDK/ExtensionsKHR.h>

using namespace Spectre::Transcoder;
using namespace Microsoft;

namespace
{
    std::string SerializeMSFT_lod(const MSFT_lod& msftLod, const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::ExtensionSerializer& /*serializer*/)
    {
        glTF::rapidjson::Document doc;
        auto& a = doc.GetAllocator();

        std::vector<size_t> lodIndices;
        lodIndices.reserve(msftLod.ids.size());
        for (const auto& lodId : msftLod.ids)
        {
            lodIndices.push_back(glTF::ToKnownSizeType(gltfDocument.materials.GetIndex(lodId)));
        }

        glTF::rapidjson::Value MSFT_lod(glTF::rapidjson::kObjectType);
        {
            MSFT_lod.AddMember(glTF::RapidJsonUtils::ToStringValue(MSFT_LOD_IDS_KEY, a), glTF::RapidJsonUtils::ToJsonArray(lodIndices, a), a);
        }

        glTF::rapidjson::StringBuffer buffer;
        glTF::rapidjson::Writer<glTF::rapidjson::StringBuffer> writer(buffer);
        MSFT_lod.Accept(writer);

        return buffer.GetString();
    }

    std::string SerializeMSFT_texture_dds(const MSFT_texture_dds& msftTextureDds, const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::ExtensionSerializer& /*serializer*/)
    {
        glTF::rapidjson::Document doc;
        auto& a = doc.GetAllocator();

        auto source = glTF::RapidJsonUtils::ToStringValue("source", a);
        auto imageIndex = glTF::ToKnownSizeType(gltfDocument.images.GetIndex(msftTextureDds.imageId));

        glTF::rapidjson::Value MSFT_texture_dds(glTF::rapidjson::kObjectType);
        {
            MSFT_texture_dds.AddMember(source, imageIndex, a);
        }

        glTF::rapidjson::StringBuffer buffer;
        glTF::rapidjson::Writer<glTF::rapidjson::StringBuffer> writer(buffer);
        MSFT_texture_dds.Accept(writer);

        return buffer.GetString();
    }

    void SerializeTextureInfo(const glTF::Document& doc, const glTF::TextureInfo& textureInfo, glTF::rapidjson::Value& textureValue, glTF::rapidjson::Document::AllocatorType& a)
    {
        glTF::RapidJsonUtils::AddOptionalMemberIndex("index", textureValue, textureInfo.textureId, doc.textures, a);
        if (textureInfo.texCoord != 0)
        {
            textureValue.AddMember("texCoord", glTF::ToKnownSizeType(textureInfo.texCoord), a);
        }
    }

    std::string SerializeMSFT_packing_normalRoughnessMetallic(const MSFT_packing_normalRoughnessMetallic& msftPackingNRM, const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::ExtensionSerializer& /*serializer*/)
    {
        // TODO: Recursive serialization (if this extension has more extensions on top of it)
        glTF::rapidjson::Document doc;
        auto& a = doc.GetAllocator();

        glTF::rapidjson::Value MSFT_packing_normalRoughnessMetallic(glTF::rapidjson::kObjectType);
        {
            if (!msftPackingNRM.normalRoughnessMetallicTexture.textureId.empty())
            {
                glTF::rapidjson::Value normalRoughnessMetallicTexture(glTF::rapidjson::kObjectType);
                {
                    SerializeTextureInfo(gltfDocument, msftPackingNRM.normalRoughnessMetallicTexture, normalRoughnessMetallicTexture, a);
                    if (msftPackingNRM.normalRoughnessMetallicTexture.scale != 1.0f)
                    {
                        normalRoughnessMetallicTexture.AddMember("scale", msftPackingNRM.normalRoughnessMetallicTexture.scale, a);
                    }
                    MSFT_packing_normalRoughnessMetallic.AddMember("normalRoughnessMetallicTexture", normalRoughnessMetallicTexture, a);
                }
            }
        }

        glTF::rapidjson::StringBuffer buffer;
        glTF::rapidjson::Writer<glTF::rapidjson::StringBuffer> writer(buffer);
        MSFT_packing_normalRoughnessMetallic.Accept(writer);
        return buffer.GetString();
    }

    std::string SerializeMSFT_packing_occlusionRoughnessMetallic(const MSFT_packing_occlusionRoughnessMetallic& msftPackingORM, const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::ExtensionSerializer& /*serializer*/)
    {
        // TODO: Recursive serialization (if this extension has more extensions on top of it)
        glTF::rapidjson::Document doc;
        auto& a = doc.GetAllocator();

        glTF::rapidjson::Value MSFT_packing_occlusionRoughnessMetallic(glTF::rapidjson::kObjectType);
        {
            if (!msftPackingORM.occlusionRoughnessMetallicTexture.textureId.empty())
            {
                glTF::rapidjson::Value occlusionRoughnessMetallicTexture(glTF::rapidjson::kObjectType);
                {
                    SerializeTextureInfo(gltfDocument, msftPackingORM.occlusionRoughnessMetallicTexture, occlusionRoughnessMetallicTexture, a);
                    if (msftPackingORM.occlusionRoughnessMetallicTexture.strength != 1.0f)
                    {
                        occlusionRoughnessMetallicTexture.AddMember("strength", msftPackingORM.occlusionRoughnessMetallicTexture.strength, a);
                    }
                    MSFT_packing_occlusionRoughnessMetallic.AddMember("occlusionRoughnessMetallicTexture", occlusionRoughnessMetallicTexture, a);
                }
            }

            if (!msftPackingORM.roughnessMetallicOcclusionTexture.textureId.empty())
            {
                glTF::rapidjson::Value roughnessMetallicOcclusionTexture(glTF::rapidjson::kObjectType);
                {
                    SerializeTextureInfo(gltfDocument, msftPackingORM.roughnessMetallicOcclusionTexture, roughnessMetallicOcclusionTexture, a);
                    if (msftPackingORM.roughnessMetallicOcclusionTexture.strength != 1.0f)
                    {
                        roughnessMetallicOcclusionTexture.AddMember("strength", msftPackingORM.roughnessMetallicOcclusionTexture.strength, a);
                    }
                    MSFT_packing_occlusionRoughnessMetallic.AddMember("roughnessMetallicOcclusionTexture", roughnessMetallicOcclusionTexture, a);
                }
            }

            if (!msftPackingORM.normalTexture.textureId.empty())
            {
                glTF::rapidjson::Value normalTexture(glTF::rapidjson::kObjectType);
                {
                    SerializeTextureInfo(gltfDocument, msftPackingORM.normalTexture, normalTexture, a);
                    if (msftPackingORM.normalTexture.scale != 1.0f)
                    {
                        normalTexture.AddMember("scale", msftPackingORM.normalTexture.scale, a);
                    }
                    MSFT_packing_occlusionRoughnessMetallic.AddMember("normalTexture", normalTexture, a);
                }
            }
        }

        glTF::rapidjson::StringBuffer buffer;
        glTF::rapidjson::Writer<glTF::rapidjson::StringBuffer> writer(buffer);
        MSFT_packing_occlusionRoughnessMetallic.Accept(writer);
        return buffer.GetString();
    }
}

Microsoft::glTF::ExtensionSerializer Spectre::Transcoder::GetMSFTKHRExtensionSerializer()
{
    auto extensionSerializer = glTF::KHR::GetKHRExtensionSerializer();
    extensionSerializer.AddHandler<MSFT_lod,                                glTF::Material>(MSFT_LOD,         SerializeMSFT_lod);
    extensionSerializer.AddHandler<MSFT_texture_dds,                        glTF::Texture >(MSFT_TEXTURE_DDS, SerializeMSFT_texture_dds);
    extensionSerializer.AddHandler<MSFT_packing_normalRoughnessMetallic,    glTF::Material>(MSFT_PACKING_NORMALROUGHNESSMETALLIC,    SerializeMSFT_packing_normalRoughnessMetallic);
    extensionSerializer.AddHandler<MSFT_packing_occlusionRoughnessMetallic, glTF::Material>(MSFT_PACKING_OCCLUSIONROUGHNESSMETALLIC, SerializeMSFT_packing_occlusionRoughnessMetallic);

    return extensionSerializer;
}