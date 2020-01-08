/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <memory>
#include <bitset>

#include <GLTFSDK/BufferBuilder.h>
#include <GLTFSDK/Constants.h>
#include <GLTFSDK/Document.h>
#include <GLTFSDK/Exceptions.h>
#include <GLTFSDK/ExtensionHandlers.h>
#include <GLTFSDK/ResourceWriter.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/SceneNode.h>
#include <Asset3D/Mesh.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>

#include "ExporterGLTF/GLTFExportOptions.h"

namespace Spectre
{
    namespace Transcoder
    {
        struct IGLTFWriter
        {
        public:
            virtual ~IGLTFWriter() {}
            virtual void WriteImage(Microsoft::glTF::Document& document, const std::vector<uint8_t>& data,
                const std::string& id, const std::string& mimeType, const std::string& extension) = 0;
            virtual void Finalize(Microsoft::glTF::Document& document, const Microsoft::glTF::ExtensionSerializer& extensionSerializer) = 0;
            virtual Microsoft::glTF::BufferBuilder& GetBufferBuilder() = 0;
        };

        class Asset3DToGLTFConverter
        {
        public:
            // TODO: refactor to default constructor
            Asset3DToGLTFConverter(const Asset3D& asset3d, const GLTFExportOptions& options = {}, Framework::ICancellationTokenPtr cancellationToken = nullptr);

            std::shared_ptr<Microsoft::glTF::Document> Write(IGLTFWriter& writer);

        private:
            // NODES/MESHES
            void PopulateDocument(IGLTFWriter& bufferBuilder);
            void AddPrimitiveToMesh(Microsoft::glTF::BufferBuilder& bufferBuilder, Microsoft::glTF::Mesh& gltfMesh, const Geometry& geometry, std::unordered_map<uint32_t, MaterialDescriptor*>& materials);
            Microsoft::glTF::MeshPrimitive CreateMeshPrimitive(Microsoft::glTF::BufferBuilder& bufferBuilder, const Geometry& geometry) const;

            // ANIMATION
            typedef std::pair<Microsoft::glTF::AnimationChannel, Microsoft::glTF::AnimationSampler> AnimationChannelAndSampler;
            void AddAnimationsAndSkeletons(Microsoft::glTF::BufferBuilder& bufferBuilder);
            AnimationChannelAndSampler CreateChannelAndSampler(
                Microsoft::glTF::BufferBuilder& resourceWriter,
                const std::string& nodeId,
                size_t skeletonCount,
                Microsoft::glTF::TargetPath path,
                const std::vector<float>& keyframeTimes,
                const std::vector<float>& keyframeValues,
                Microsoft::glTF::AccessorType accessorType) const;

            void AddGLTFChannelAnimations(Microsoft::glTF::BufferBuilder& bufferBuilder);

            enum class TextureChannels : uint8_t
            {
                k2Or3Channel,
                k3Channel,
                k4Channel
            };

            void AddMaterials(IGLTFWriter& writer, const std::unordered_map<uint32_t, MaterialDescriptor*>& materials);
            Microsoft::glTF::Material AddMaterial(IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale);

            void ApplyOrGenerateMaterialMR(Microsoft::glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale);
            bool ApplyMaterialMR(
                Microsoft::glTF::Material& material, IGLTFWriter& writer,
                const std::shared_ptr<MaterialLayer>& baseColorLayer,
                const std::shared_ptr<MaterialLayer>& metalRoughLayer,
                const uint8_t scale);

            void ApplyOrGenerateMaterialSG(Microsoft::glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale);
            bool ApplyMaterialSG(
                Microsoft::glTF::Material& material, IGLTFWriter& writer,
                const std::shared_ptr<MaterialLayer>& diffuseLayer,
                const std::shared_ptr<MaterialLayer>& specGlossLayer,
                const uint8_t scale);

            void ApplyCommonMaterialLayers(Microsoft::glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale);

            void ApplyMsftPackingNrm(Microsoft::glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc);

            std::string AddSampler(const MaterialLayer::TextureSampler& sampler);

            std::string AddTexture(IGLTFWriter& writer, const TextureDescriptor* textureDesc, const uint8_t scale, const std::string& samplerId, TextureChannels channels,
                bool compliantImage = true, bool ddsImage = false);

            TextureCompressionType GetCompliantTextureCompressionType(TextureChannels channels);
            TextureCompressionType GetDDSTextureCompressionType(TextureChannels channels);

            void SetTextureInfo(const std::shared_ptr<MaterialDescriptor::LayerInfo>& layer, Microsoft::glTF::TextureInfo& textureInfo, IGLTFWriter& writer, const uint8_t scale, TextureChannels textureChannels,
                bool compliantImage = true, bool ddsImage = false);
            void SetMaterialTextureTransform(const std::shared_ptr<MaterialDescriptor::LayerInfo>& layer, Microsoft::glTF::TextureInfo& textureInfo);

            // MEMBERS
            const Asset3D& m_asset3d;
            const GLTFExportOptions m_options;
            std::shared_ptr<Microsoft::glTF::Document> m_gltfDocument;

            std::unordered_set<std::string> m_textures;
            std::unordered_map<std::string, std::string> m_generatedTextures;
            std::vector<Microsoft::glTF::Sampler> m_samplers;

            bool m_minecraftAsset = false;

            Framework::ICancellationTokenPtr m_cancellationToken;
        };
    }
}
