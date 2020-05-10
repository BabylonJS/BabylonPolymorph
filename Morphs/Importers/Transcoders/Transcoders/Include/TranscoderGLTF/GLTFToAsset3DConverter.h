/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <GLTFSDK/Document.h>
#include <GLTFSDK/GLTFResourceReader.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>
#include <CoreUtils/StringUtils.h>

#include "TranscoderGLTF/GLTFImportOptions.h"

namespace Babylon
{
    namespace Transcoder
    {
        namespace GLTF
        {
            class GLTFToAsset3DConverter
            {
            public:
                GLTFToAsset3DConverter(Microsoft::glTF::GLTFResourceReader& resourceReader, const GLTFImportOptions& options);
                std::unique_ptr<Asset3D> CreateAsset3D(const Microsoft::glTF::Document& gltfDocument, Babylon::Framework::ICancellationTokenPtr cancellationToken);

            private:
                using NodeMap = std::unordered_map<std::string, SceneNode*>;

                struct VisitorState
                {
                    using MeshMap = std::unordered_map<std::string, std::shared_ptr<Mesh>>; // Key = glTF::Mesh.id, Value: A3d::Mesh
                    using MaterialMap = std::unordered_map<std::string, std::shared_ptr<MaterialDescriptor>>; // Key = glTF::Material.id, Value: A3d::Material
                    using TextureMap = std::unordered_map<std::string, std::shared_ptr<TextureDescriptor>>; // Key = glTF::Texture.id, Value: A3d::Texture
                    using SamplerMap = std::unordered_map<std::string, std::shared_ptr<MaterialLayer::TextureSampler>>; // Key = glTF::Sampler.id, Value: A3d::Sampler

                    VisitorState(const Microsoft::glTF::Document& gltfDocument, bool isAnimationEnabled, bool isLegacyGLTF) :
                        isAnimationEnabled(isAnimationEnabled),
                        isLegacyGLTF(isLegacyGLTF),
                        gltfDoc(gltfDocument)
                    {
                    }

                    bool isAnimationEnabled;
                    bool isLegacyGLTF;

                    const Microsoft::glTF::Document& gltfDoc;

                    NodeMap nodes;
                    MeshMap meshes;
                    MaterialMap materials;
                    TextureMap textures;
                    SamplerMap samplers;

                    SceneNode* currentNode = nullptr;
                    Mesh* currentMesh = nullptr;
                };

                Geometry GltfMeshPrimitiveToA3dGeometry(
                    VisitorState& visitorState,
                    const Microsoft::glTF::MeshPrimitive& meshPrimitive,
                    Babylon::Framework::ICancellationTokenPtr cancellationToken);

                const std::shared_ptr<MaterialDescriptor> GetOrAddMaterial(
                    VisitorState& visitorState,
                    const std::string& materialId);

                const std::shared_ptr<MaterialLayer::TextureSampler> GetOrAddSampler(
                    VisitorState& visitorState, const std::string& samplerId);

                void ImportAnimations(const Microsoft::glTF::Document& gltfDocument, std::unique_ptr<Asset3D>& asset3d, const NodeMap& visitorStateNodes);

                std::shared_ptr<MaterialDescriptor> ParseMaterial(VisitorState& visitorState, const std::string& materialId);
                void ParseMaterialMR(VisitorState& visitorState, std::shared_ptr<MaterialDescriptor>& materialDescriptor, const Microsoft::glTF::Material& mat);
                void GenerateMaterialSG(VisitorState& visitorState, std::shared_ptr<MaterialDescriptor>& materialDescriptor, const Microsoft::glTF::Material& mat);
                void ParseMaterialSG(VisitorState& visitorState, std::shared_ptr<MaterialDescriptor>& materialDescriptor, const Microsoft::glTF::Material& mat);
                std::shared_ptr<TextureDescriptor> ParseTexture(VisitorState& visitorState, const std::string& textureId, std::shared_ptr<MaterialLayer::TextureSampler>& sampler, uint8_t flags = 0);
                std::shared_ptr<MaterialLayer::TextureSampler> ParseSampler(const Microsoft::glTF::Document& gltfDocument, const std::string& samplerId);

                void PopulatePositions(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const;
                void PopulateNormals(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const;
                void PopulateTangents(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const;
                void PopulateUv0(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const;
                void PopulateUv1(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const;
                void PopulateColor(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const;
                void PopulateJoints(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& indicesAccessorId, const std::string& weightsAccessorId) const;
                void PopulateMorphTargetPositions(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const Microsoft::glTF::MorphTarget& morphTarget) const;
                void PopulateMorphTargetNormals(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const Microsoft::glTF::MorphTarget& morphTarget) const;
                void PopulateMorphTargetTangents(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const Microsoft::glTF::MorphTarget& morphTarget) const;

                Microsoft::glTF::GLTFResourceReader& m_resourceReader;
                const GLTFImportOptions m_options;
            };
        }
    }
}
