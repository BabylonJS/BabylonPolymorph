/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <unordered_set>
#include <numeric>

#include <GLTFSDK/GLTF.h>
#include <GLTFSDK/GLTFResourceReader.h>
#include <GLTFSDK/MeshPrimitiveUtils.h>
#include <GLTFSDK/PBRUtils.h>
#include <GLTFSDK/Visitor.h>
#include <GLTFSDK/ExtensionsKHR.h>
#include <GLTFSDK/MicrosoftGeneratorVersion.h>
#include <GLTFSDK/AnimationUtils.h>
#include <GLTFSDK/Version.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/Camera.h>
#include <Asset3D/SceneNode.h>
#include <Asset3D/Mesh.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>
#include <CoreUtils/Gltf.h>
#include <CoreUtils/RapidJson.h>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/GLTFChannelAnimations.h>
#include <CoreUtils/Memory.h>

#include "TranscoderGLTF/GLTFToAsset3DConverter.h"
#include "TranscoderGLTF/TransformMatrixUtils.h"
#include "ExporterGLTF/ExtensionsMSFT.h"

using namespace Spectre::Transcoder;
using namespace GLTF;
using namespace Spectre::Utils::Math;
using namespace Microsoft;

DEFINE_TRACE_AREA(GLTFToAsset3DConverter, 0);

namespace
{
    Matrix CreateTransformationMatrix(const glTF::Node &node)
    {
        if (node.GetTransformationType() == glTF::TRANSFORMATION_MATRIX)
        {
            return Matrix(node.matrix.values.data());
        }

        if (node.GetTransformationType() == glTF::TRANSFORMATION_TRS)
        {
            return TransformMatrixUtils::CreateTransformationMatrix(node.scale, node.translation, node.rotation);
        }

        return Matrix::Identity;
    }

    bool IsExtrasAttributeSetAndTrue(const std::string& extrasJson, const char* attributeName)
    {
        if (extrasJson.empty())
        {
            return false;
        }

        Spectre::rapidjson::Document extrasDoc;
        extrasDoc.Parse(extrasJson.c_str());

        bool attributeTrue = extrasDoc.HasMember(attributeName)
            && extrasDoc[attributeName].IsBool()
            && extrasDoc[attributeName].IsTrue();

        return attributeTrue;
    }

    void AddExtensionsToTraversableNode(const std::unordered_map<std::string, std::string>& extensions,
        ITraversableBase* assetNode, const std::string& key, const std::unordered_set<std::string>& extensionBlacklist)
    {
        if (!extensions.empty())
        {
            for (auto it = extensions.begin(); it != extensions.end(); ++it)
            {
                if (extensionBlacklist.find(it->first) == extensionBlacklist.end())
                {
                    assetNode->AddExtensionsItem(key, it->first, it->second);
                }
            }
        }
    }

    void AddExtrasToTraversableNode(const Microsoft::glTF::glTFProperty& gltfNode, ITraversableBase* a3dNode)
    {
        a3dNode->SetExtras(gltfNode.extras);
    }

    void CopyFromGltfProperty(const glTF::glTFProperty& gltfProperty, ITraversableBase* a3dNode, const std::string& key = Spectre::Utils::glTF::kExtensionsDefault,
        const std::unordered_set<std::string>& extensionBlacklist = {})
    {
        AddExtensionsToTraversableNode(gltfProperty.extensions, a3dNode, key, extensionBlacklist);
        AddExtrasToTraversableNode(gltfProperty, a3dNode);
    }

    void CopyFromGltfChildOfRootProperty(const glTF::glTFChildOfRootProperty& gltfProperty, ITraversableWithName* a3dNode, const std::string& key = Spectre::Utils::glTF::kExtensionsDefault,
        const std::unordered_set<std::string>& extensionBlacklist = {})
    {
        a3dNode->SetName(gltfProperty.name);
        CopyFromGltfProperty(gltfProperty, a3dNode, key, extensionBlacklist);
    }

    std::shared_ptr<Spectre::Transcoder::Camera> GltfCameraToA3dCamera(const Microsoft::glTF::Camera& gltfCamera)
    {
        std::shared_ptr<Spectre::Transcoder::Camera> a3dCamera;
        if (gltfCamera.projection->GetProjectionType() == Microsoft::glTF::PROJECTION_ORTHOGRAPHIC)
        {
            const auto& orthographic = gltfCamera.GetOrthographic();
            a3dCamera = std::make_shared<Spectre::Transcoder::Camera>(
                std::make_unique<Spectre::Transcoder::Orthographic>(orthographic.zfar, orthographic.znear, orthographic.xmag, orthographic.ymag));
        }
        else if (gltfCamera.projection->GetProjectionType() == Microsoft::glTF::PROJECTION_PERSPECTIVE)
        {
            const auto& perspective = gltfCamera.GetPerspective();

            auto a3dPerspective = std::make_unique<Spectre::Transcoder::Perspective>(perspective.znear, perspective.yfov);

            if (perspective.zfar)
            {
                a3dPerspective->zfar = perspective.zfar.Get();
            }

            if (perspective.aspectRatio)
            {
                a3dPerspective->aspectRatio = perspective.aspectRatio.Get();
            }

            a3dCamera = std::make_shared<Spectre::Transcoder::Camera>(std::move(a3dPerspective));
        }

        CopyFromGltfChildOfRootProperty(gltfCamera, a3dCamera.get());

        return a3dCamera;
    }

    std::shared_ptr<Spectre::Transcoder::Mesh> GltfMeshToA3dMesh(const Microsoft::glTF::Mesh& mesh)
    {
        auto a3dMesh = std::make_shared<Mesh>();
        a3dMesh->SetMorphWeights(mesh.weights);

        bool isMinecraftModel = IsExtrasAttributeSetAndTrue(mesh.extras, Spectre::Utils::glTF::kMinecraftExtrasAttributeName);
        if (isMinecraftModel)
        {
            a3dMesh->SetFlags(MeshFlags::MinecraftMesh);
        }

        CopyFromGltfChildOfRootProperty(mesh, a3dMesh.get());

        return a3dMesh;
    }

    std::vector<uint32_t> GetTruncatedJointIndices32(const glTF::Document& doc, const glTF::GLTFResourceReader& reader, const glTF::Accessor& accessor)
    {
        std::vector<uint16_t> joints = reader.ReadBinaryData<uint16_t>(doc, accessor);
        std::vector<uint32_t> joints32;
        joints32.reserve(joints.size() / 4);
        for (unsigned int i = 0; i < joints.size(); i += 4)
        {
            if (joints[i]     > std::numeric_limits<uint8_t>::max() ||
                joints[i + 1] > std::numeric_limits<uint8_t>::max() ||
                joints[i + 2] > std::numeric_limits<uint8_t>::max() ||
                joints[i + 3] > std::numeric_limits<uint8_t>::max())
            {
                throw Spectre::Utils::SpectreException("16-bit joint indices not supported");
            }

            joints32.push_back(
                static_cast<uint8_t>(joints[i]) |
                static_cast<uint8_t>(joints[i + 1]) << 8 |
                static_cast<uint8_t>(joints[i + 2]) << 16 |
                static_cast<uint8_t>(joints[i + 3]) << 24);
        }
        return joints32;
    }

    void UpdateLayerTextureParams(const std::shared_ptr<MaterialDescriptor::LayerInfo>& layer, const std::shared_ptr<TextureDescriptor>& texture, const std::shared_ptr<MaterialLayer::TextureSampler>& sampler, const glTF::TextureInfo& gltfTextureInfo)
    {
        layer->Texture = texture;
        layer->Sampler = *sampler;
        layer->UVSetIndex = static_cast<uint32_t>(gltfTextureInfo.texCoord);

        if (gltfTextureInfo.HasExtension<glTF::KHR::TextureInfos::TextureTransform>())
        {
            const auto& gltfTextureTransform = gltfTextureInfo.GetExtension<glTF::KHR::TextureInfos::TextureTransform>();

            layer->TextureTransform = Spectre::Utils::glTF::GetTextureTransformMatrix(gltfTextureTransform);

            if (gltfTextureTransform.texCoord)
            {
                layer->UVSetIndex = static_cast<uint32_t>(gltfTextureTransform.texCoord.Get());
            }
        }
    }
}

GLTFToAsset3DConverter::GLTFToAsset3DConverter(glTF::GLTFResourceReader& resourceReader, const GLTFImportOptions& options)
    : m_resourceReader(resourceReader),
    m_options(options)
{
}

std::unique_ptr<Asset3D> GLTFToAsset3DConverter::CreateAsset3D(const Microsoft::glTF::Document& gltfDocument, Spectre::Framework::ICancellationTokenPtr cancellationToken)
{
    glTF::Version version(gltfDocument.asset.version);

    // Version check
    if (version.major != 2U)
    {
        throw Utils::SpectreException("glTF document version is not supported");
    }

    // Minimum version check
    if (!glTF::IsMinVersionRequirementSatisfied(gltfDocument.asset.minVersion))
    {
        throw Utils::SpectreException("glTF document minimum version is greater than 2.0");
    }

    if (cancellationToken == nullptr)
    {
        cancellationToken = Spectre::Framework::MakeNullCancellationToken();
    }

    std::unique_ptr<Asset3D> asset3d = std::make_unique<Asset3D>();

    // Set unit; Gltf is always in meter
    asset3d->SetSystemUnit(Asset3D::SYSTEMUNIT_METER);

    // Determine whether this GLTF should be treated as a legacy 3DFE model or not.
    bool isLegacyGLTF = Spectre::Utils::glTF::IsLegacyGLTFDocument(gltfDocument);

    VisitorState visitorState(gltfDocument, m_options.ExtractAnimationData, isLegacyGLTF);

    auto scene = gltfDocument.GetDefaultScene();

    // Add extensions/extras from the top-level gltfDocument, if any
    CopyFromGltfProperty(gltfDocument, asset3d.get(), Spectre::Utils::glTF::kExtensionsRootGltfKey);

    // Add extensions from root scene node
    CopyFromGltfChildOfRootProperty(scene, asset3d.get(), Spectre::Utils::glTF::kExtensionsDefaultSceneKey);

    Microsoft::glTF::Visit(gltfDocument, glTF::DefaultSceneIndex,
        [&visitorState, &asset3d, &scene, &cancellationToken](const Microsoft::glTF::Node& node, const Microsoft::glTF::Node* nodeParent)
    {
        cancellationToken->CheckCancelledAndThrow();

        SceneNode* sceneNode = nullptr;

        if (nodeParent == nullptr)
        {
            if(scene.nodes.size() == 1)
            {
                sceneNode = asset3d.get();
            }
            else if (scene.nodes.size() > 1)
            {
                // No parent, so attach it directly to the asset3d. There could be more than one node with no parent
                // since a glTF scene can list multiple root nodes.
                sceneNode = asset3d->CreateChildNode().get();
            }
        }
        else
        {
            // Has parent, so find the parent and attach it
            sceneNode = visitorState.nodes[nodeParent->id]->CreateChildNode().get();
        }

        sceneNode->SetTransform(CreateTransformationMatrix(node));

        CopyFromGltfChildOfRootProperty(node, sceneNode);

        if (visitorState.isAnimationEnabled)
        {
            if (!node.skinId.empty())
            {
                auto skeletonId = static_cast<Animation::SkeletonID>(visitorState.gltfDoc.skins.GetIndex(node.skinId));
                sceneNode->SetSkeletonID(skeletonId);
            }

            sceneNode->SetMorphWeights(node.weights);
        }

        visitorState.nodes[node.id] = sceneNode;
        visitorState.currentNode = sceneNode;
    },
        [&visitorState, &cancellationToken](const Microsoft::glTF::Mesh& mesh, glTF::VisitState visitState)
    {
        cancellationToken->CheckCancelledAndThrow();

        std::shared_ptr<Mesh> a3dMesh;
        if (visitState == glTF::VisitState::New)
        {
            a3dMesh = GltfMeshToA3dMesh(mesh);
            visitorState.meshes[mesh.id] = a3dMesh;
        }
        else if (visitState == glTF::VisitState::Duplicate)
        {
            a3dMesh = visitorState.meshes.at(mesh.id);
        }

        visitorState.currentNode->SetMesh(a3dMesh);

        // Set gltfMesh and gltfPrimitiveIndex so that the MeshPrimitive callback has this info
        visitorState.currentMesh = a3dMesh.get();
    },
        [this, &visitorState, cancellationToken](const glTF::MeshPrimitive& meshPrimitive, glTF::VisitState visitState)
    {
        cancellationToken->CheckCancelledAndThrow();

        if (visitState == glTF::VisitState::New)
        {
            // This also converts any referenced materials, with shared material support
            auto geometry = this->GltfMeshPrimitiveToA3dGeometry(visitorState, meshPrimitive, cancellationToken);
            visitorState.currentMesh->AddGeometry(std::move(geometry));
        }
        // Duplicate MeshPrimitive means the Mesh above it was instanced, no need to process twice
    },
        [&visitorState, cancellationToken](const Microsoft::glTF::Camera& camera, glTF::VisitState)
    {
        // TODO: Instancing support
        cancellationToken->CheckCancelledAndThrow();

        auto a3dCamera = GltfCameraToA3dCamera(camera);
        visitorState.currentNode->SetCamera(a3dCamera);
    }
    );

    if (m_options.ExtractAnimationData)
    {
        ImportAnimations(gltfDocument, asset3d, visitorState.nodes);
    }

    return asset3d;
}

void GLTFToAsset3DConverter::ImportAnimations(const Microsoft::glTF::Document& gltfDocument, std::unique_ptr<Asset3D>& asset3d, const NodeMap& visitorStateNodes)
{
    if (gltfDocument.animations.Elements().size() > 0 || gltfDocument.skins.Elements().size() > 0)
    {
        auto gltfChannelAnimations = std::make_shared<GLTFChannelAnimations>();
        auto gltfSkins = std::make_shared<GLTFSkins>();

        for (auto& animation : gltfDocument.animations.Elements())
        {
            // Import all animations into the new channel animations container which supports
            // reading and writing multiple types of animations in the correct order
            gltfChannelAnimations->LoadAnimationData(animation.id, gltfDocument, m_resourceReader);
        }

        gltfSkins->LoadSkinData(gltfDocument, m_resourceReader);

        // Get all the nodes used in animations and skins and remap them to the corresponding Asset3d ones
        // This ensures they match their target Asset3D scene nodes and will get linked up when exporting

        auto buildRemappingMap = [&visitorStateNodes](const auto& targetedNodeIds)
        {
            std::map<std::string, std::string> gltfToAsset3DNodeIdMap;
            for (auto& nodeId : targetedNodeIds)
            {
                auto visitorStateNodesIt = visitorStateNodes.find(nodeId);
                if (visitorStateNodesIt != visitorStateNodes.end())
                {
                    std::string newNodeId = std::to_string(visitorStateNodes.at(nodeId)->GetId());
                    gltfToAsset3DNodeIdMap[nodeId] = newNodeId;
                }
                else
                {
                    throw Utils::SpectreException("Animation target node not found in scene");
                }
            }

            return gltfToAsset3DNodeIdMap;
        };

        // Animation nodes
        std::vector<std::string> targetedNodeIds;
        for (auto& animation : gltfDocument.animations.Elements())
        {
            auto animationTargetedNodeIds = gltfChannelAnimations->GetTargetedNodeIds(animation.id);
            for (const auto& animationTargetedNodeId : animationTargetedNodeIds)
            {
                if (std::find(targetedNodeIds.begin(), targetedNodeIds.end(), animationTargetedNodeId) == targetedNodeIds.end())
                {
                    targetedNodeIds.push_back(animationTargetedNodeId);
                }
            }
        }

        auto gltfToAsset3DNodeIdMap = buildRemappingMap(targetedNodeIds);
        gltfChannelAnimations->RetargetNodeIds(gltfToAsset3DNodeIdMap);

        // Skin nodes
        std::set<std::string> skinTargetedNodeIds;
        for (auto& skin : gltfDocument.skins.Elements())
        {
            if (!skin.skeletonId.empty())
            {
                skinTargetedNodeIds.emplace(skin.skeletonId);
            }
            skinTargetedNodeIds.insert(skin.jointIds.begin(), skin.jointIds.end());
        }

        auto skinGltfToAsset3DNodeIdMap = buildRemappingMap(skinTargetedNodeIds);
        gltfSkins->RetargetNodeIds(skinGltfToAsset3DNodeIdMap);

        asset3d->SetChannelAnimations(gltfChannelAnimations);
        asset3d->SetSkins(gltfSkins);
    }
}

Geometry GLTFToAsset3DConverter::GltfMeshPrimitiveToA3dGeometry(
    VisitorState& visitorState,
    const glTF::MeshPrimitive& primitive,
    Spectre::Framework::ICancellationTokenPtr cancellationToken)
{
    auto materialDescriptor = GetOrAddMaterial(visitorState, primitive.materialId);
    //  GLTF compliance: Tag known non-compliant GLTF files for special handling downstream.
    if (visitorState.currentMesh->HasFlags(MeshFlags::MinecraftMesh) || visitorState.isLegacyGLTF)
    {
        materialDescriptor->SetRenderingOption(RenderingOption::GLTFNonCompliant);
    }

    // Minecraft export patch--force blend materials to mask
    if (visitorState.currentMesh->HasFlags(MeshFlags::MinecraftMesh)
        && m_options.ForceMinecraftBlendMaterialsToMask)
    {
        if (materialDescriptor->GetRenderingMode() == RenderingMode::Blend)
        {
            materialDescriptor->SetRenderingMode(RenderingMode::Mask);
        }
    }

    Geometry geometry(materialDescriptor);

    switch (primitive.mode)
    {
        case glTF::MeshMode::MESH_TRIANGLES:
            // Topology is already GeometryTopology::kTriangles
            if (!primitive.indicesAccessorId.empty())
            {
                geometry.SetIndices(
                    glTF::MeshPrimitiveUtils::GetIndices32(visitorState.gltfDoc, m_resourceReader, primitive));
            }
            break;

        case glTF::MeshMode::MESH_TRIANGLE_FAN:
        case glTF::MeshMode::MESH_TRIANGLE_STRIP:
            // Topology is already GeometryTopology::kTriangles
            geometry.SetIndices(
                glTF::MeshPrimitiveUtils::GetTriangulatedIndices32(visitorState.gltfDoc, m_resourceReader, primitive));
            break;

        case glTF::MeshMode::MESH_LINES:
            geometry.SetTopology(GeometryTopology::kLines);
            if (!primitive.indicesAccessorId.empty())
            {
                geometry.SetIndices(
                    glTF::MeshPrimitiveUtils::GetIndices32(visitorState.gltfDoc, m_resourceReader, primitive));
            }
            break;

        case glTF::MeshMode::MESH_LINE_LOOP:
        case glTF::MeshMode::MESH_LINE_STRIP:
            geometry.SetTopology(GeometryTopology::kLines);
            geometry.SetIndices(
                glTF::MeshPrimitiveUtils::GetSegmentedIndices32(visitorState.gltfDoc, m_resourceReader, primitive));
            break;

        case glTF::MeshMode::MESH_POINTS:
            geometry.SetTopology(GeometryTopology::kPoints);
            if (!primitive.indicesAccessorId.empty())
            {
                geometry.SetIndices(
                    glTF::MeshPrimitiveUtils::GetIndices32(visitorState.gltfDoc, m_resourceReader, primitive));
            }
            break;

        default:
            throw Utils::SpectreException("Unrecognized primitive mode.");
    }

    // Positions
    {
        auto accessorPositionId = primitive.GetAttributeAccessorId(glTF::ACCESSOR_POSITION);
        PopulatePositions(visitorState.gltfDoc, geometry, accessorPositionId);
        cancellationToken->CheckCancelledAndThrow();
    }

    if (primitive.HasAttribute(glTF::ACCESSOR_NORMAL))
    {
        auto accessorNormalId = primitive.GetAttributeAccessorId(glTF::ACCESSOR_NORMAL);
        PopulateNormals(visitorState.gltfDoc, geometry, accessorNormalId);
        cancellationToken->CheckCancelledAndThrow();
    }

    if (primitive.HasAttribute(glTF::ACCESSOR_TANGENT))
    {
        auto accessorTangentId = primitive.GetAttributeAccessorId(glTF::ACCESSOR_TANGENT);
        PopulateTangents(visitorState.gltfDoc, geometry, accessorTangentId);
        cancellationToken->CheckCancelledAndThrow();
    }

    if (primitive.HasAttribute(glTF::ACCESSOR_TEXCOORD_0))
    {
        auto accessorTexcoord0Id = primitive.GetAttributeAccessorId(glTF::ACCESSOR_TEXCOORD_0);
        PopulateUv0(visitorState.gltfDoc, geometry, accessorTexcoord0Id);
        cancellationToken->CheckCancelledAndThrow();
    }

    if (primitive.HasAttribute(glTF::ACCESSOR_TEXCOORD_1))
    {
        auto accessorTexcoord1Id = primitive.GetAttributeAccessorId(glTF::ACCESSOR_TEXCOORD_1);
        PopulateUv1(visitorState.gltfDoc, geometry, accessorTexcoord1Id);
        cancellationToken->CheckCancelledAndThrow();
    }

    if (primitive.HasAttribute(glTF::ACCESSOR_COLOR_0))
    {
        auto accessorColor0Id = primitive.GetAttributeAccessorId(glTF::ACCESSOR_COLOR_0);
        PopulateColor(visitorState.gltfDoc, geometry, accessorColor0Id);
        cancellationToken->CheckCancelledAndThrow();
    }

    if (m_options.ExtractAnimationData)
    {
        if (primitive.HasAttribute(glTF::ACCESSOR_JOINTS_0) && primitive.HasAttribute(glTF::ACCESSOR_WEIGHTS_0))
        {
            auto accessorJoints0Id = primitive.GetAttributeAccessorId(glTF::ACCESSOR_JOINTS_0);
            auto accessorWeights0Id = primitive.GetAttributeAccessorId(glTF::ACCESSOR_WEIGHTS_0);
            PopulateJoints(visitorState.gltfDoc, geometry, accessorJoints0Id, accessorWeights0Id);
            cancellationToken->CheckCancelledAndThrow();
        }

        for (const auto& morphTarget : primitive.targets)
        {
            if (!morphTarget.positionsAccessorId.empty())
            {
                PopulateMorphTargetPositions(visitorState.gltfDoc, geometry, morphTarget);
                cancellationToken->CheckCancelledAndThrow();
            }

            if (!morphTarget.normalsAccessorId.empty())
            {
                PopulateMorphTargetNormals(visitorState.gltfDoc, geometry, morphTarget);
                cancellationToken->CheckCancelledAndThrow();
            }

            if (!morphTarget.tangentsAccessorId.empty())
            {
                PopulateMorphTargetTangents(visitorState.gltfDoc, geometry, morphTarget);
                cancellationToken->CheckCancelledAndThrow();
            }
        }
    }

    cancellationToken->CheckCancelledAndThrow();

    CopyFromGltfProperty(primitive, &geometry);

    return geometry;
}

const std::shared_ptr<MaterialDescriptor> GLTFToAsset3DConverter::GetOrAddMaterial(
    VisitorState& visitorState,
    const std::string& materialId)
{
    std::shared_ptr<MaterialDescriptor> materialDescriptor;

    // TODO: Support materialId == "" by returning nullptr materialDescriptor
    auto it = visitorState.materials.find(materialId);
    if (it == visitorState.materials.end())
    {
        materialDescriptor = ParseMaterial(visitorState, materialId);
        visitorState.materials[materialId] = materialDescriptor;
    }
    else
    {
        materialDescriptor = it->second;
    }

    return materialDescriptor;
}

const std::shared_ptr<MaterialLayer::TextureSampler> GLTFToAsset3DConverter::GetOrAddSampler(
    VisitorState& visitorState,
    const std::string& samplerId)
{
    std::shared_ptr<MaterialLayer::TextureSampler> sampler;
    auto it = visitorState.samplers.find(samplerId);
    if (it == visitorState.samplers.end())
    {
        sampler = ParseSampler(visitorState.gltfDoc, samplerId);
        visitorState.samplers[samplerId] = sampler;
    }
    else
    {
        sampler = it->second;
    }

    return sampler;
}

void GLTFToAsset3DConverter::ParseMaterialMR(VisitorState& visitorState, std::shared_ptr<MaterialDescriptor>& materialDescriptor, const glTF::Material& mat)
{
    // This method should not be called if KHR_materials_pbrSpecularGlossiness is in "extensionsRequired"

    std::shared_ptr<MaterialLayer::TextureSampler> sampler;

    auto& mr = mat.metallicRoughness;

    // BaseColor
    auto baseColorLayer = materialDescriptor->GetOrAddLayer(LayerType::kBaseColor);
    baseColorLayer->SetColor(
        Utils::Math::Color(mr.baseColorFactor.r, mr.baseColorFactor.g, mr.baseColorFactor.b, mr.baseColorFactor.a));

    if (!mr.baseColorTexture.textureId.empty())
    {
        auto baseColorTexture = ParseTexture(visitorState, mr.baseColorTexture.textureId, sampler);
        UpdateLayerTextureParams(baseColorLayer, baseColorTexture, sampler, mr.baseColorTexture);
    }

    // Specular
    auto mrLayer = materialDescriptor->GetOrAddLayer(LayerType::kMetallicRoughness);
    materialDescriptor->SetMetalRoughFactors(
        mr.metallicFactor,
        mr.roughnessFactor);

    if (!mr.metallicRoughnessTexture.textureId.empty())
    {
        auto metalRoughTexture = ParseTexture(visitorState, mr.metallicRoughnessTexture.textureId, sampler);
        UpdateLayerTextureParams(mrLayer, metalRoughTexture, sampler, mr.metallicRoughnessTexture);
    }
}

void GLTFToAsset3DConverter::ParseMaterialSG(VisitorState& visitorState, std::shared_ptr<MaterialDescriptor>& materialDescriptor, const glTF::Material& mat)
{
    std::shared_ptr<MaterialLayer::TextureSampler> sampler;

    auto sgExtension = mat.GetExtension<glTF::KHR::Materials::PBRSpecularGlossiness>();

    // Diffuse
    auto diffuseLayer = materialDescriptor->AddLayer(LayerType::kDiffuse);
    diffuseLayer->SetColor(
        Utils::Math::Color(sgExtension.diffuseFactor.r, sgExtension.diffuseFactor.g, sgExtension.diffuseFactor.b, sgExtension.diffuseFactor.a));

    if (!sgExtension.diffuseTexture.textureId.empty())
    {
        auto diffuseTexture = ParseTexture(visitorState, sgExtension.diffuseTexture.textureId, sampler);
        UpdateLayerTextureParams(diffuseLayer, diffuseTexture, sampler, sgExtension.diffuseTexture);
    }

    // Specular
    auto specularLayer = materialDescriptor->AddLayer(LayerType::kSpecularGlossiness);
    specularLayer->SetColor(
        Utils::Math::Color(sgExtension.specularFactor.r, sgExtension.specularFactor.g, sgExtension.specularFactor.b, sgExtension.glossinessFactor));

    if (!sgExtension.specularGlossinessTexture.textureId.empty())
    {
        // GLTF specular always stores gloss in alpha channel
        // Techdebt task 12349072: Marking the alpha channel probably belongs in CoreUtil's ImagingComponent instead of here.
        uint8_t flags = Framework::TextureSegmentLittleEndian::kFlag_TextureHasActiveAlpha |
            Framework::TextureSegmentLittleEndian::kFlag_AlphaValid;
        auto specularTexture = ParseTexture(visitorState, sgExtension.specularGlossinessTexture.textureId, sampler, flags);
        UpdateLayerTextureParams(specularLayer, specularTexture, sampler, sgExtension.specularGlossinessTexture);
    }
}

std::shared_ptr<MaterialDescriptor> GLTFToAsset3DConverter::ParseMaterial(VisitorState& visitorState, const std::string& materialId)
{
    glTF::Material mat = materialId.empty() ? glTF::Material() : visitorState.gltfDoc.materials[materialId];
    // Apply legacy override
    if (visitorState.isLegacyGLTF)
    {
        Utils::glTF::OverrideLegacyGLTFMaterial(mat, Utils::glTF::LegacyMode::Transcoder);
    }

    auto materialDesc = std::make_shared<MaterialDescriptor>(false);
    CopyFromGltfChildOfRootProperty(mat, materialDesc.get(), Spectre::Utils::glTF::kExtensionsDefault, { MSFT_LOD });

    // Parse MR if it's available
    if (!visitorState.gltfDoc.IsExtensionRequired(glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME))
    {
        ParseMaterialMR(visitorState, materialDesc, mat);

        //set flag for unlit material extension, only if the material does not have the spec gloss extension.
        //according to the unlit extension spec, the behaviour for combining unlit and specgloss extensions is undefined
        //according to the unlit extension spec, only material properties defined in the core GLTF are to be used, not properties from other material extensions
        //choosing specgloss over unlit when both are present is also consistent with the babylon viewer
        if (mat.HasExtension<glTF::KHR::Materials::Unlit>())
        {
            materialDesc->SetRenderingOption(RenderingOption::Unlit);
        }
    }

    // Parse SG if it's available
    if (visitorState.gltfDoc.IsExtensionUsed(glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME) && mat.HasExtension<glTF::KHR::Materials::PBRSpecularGlossiness>())
    {
        ParseMaterialSG(visitorState, materialDesc, mat);
    }

    std::shared_ptr<MaterialLayer::TextureSampler> sampler;

    // Normal
    if (!mat.normalTexture.textureId.empty())
    {
        auto normalLayer = materialDesc->AddLayer(LayerType::kNormal);
        auto normalTexture = ParseTexture(visitorState, mat.normalTexture.textureId, sampler);
        UpdateLayerTextureParams(normalLayer, normalTexture, sampler, mat.normalTexture);
        normalLayer->Coefficient = mat.normalTexture.scale;
    }

    // Emissive
    if (mat.emissiveFactor != glTF::Color3(0.f, 0.f, 0.f))
    {
        materialDesc->GetOrAddLayer(LayerType::kEmissive)->SetColor(Utils::Math::Color(
            mat.emissiveFactor.r, mat.emissiveFactor.g, mat.emissiveFactor.b, 1.0f));
    }

    if (!mat.emissiveTexture.textureId.empty())
    {
        auto emissiveLayer = materialDesc->GetOrAddLayer(LayerType::kEmissive);
        auto emissiveTexture = ParseTexture(visitorState, mat.emissiveTexture.textureId, sampler);
        UpdateLayerTextureParams(emissiveLayer, emissiveTexture, sampler, mat.emissiveTexture);
    }

    // Occlusion
    if (!mat.occlusionTexture.textureId.empty())
    {
        auto occlusionLayer = materialDesc->AddLayer(LayerType::kOcclusion);
        auto occlusionTexture = ParseTexture(visitorState, mat.occlusionTexture.textureId, sampler);
        UpdateLayerTextureParams(occlusionLayer, occlusionTexture, sampler, mat.occlusionTexture);
        occlusionLayer->Coefficient = mat.occlusionTexture.strength;
    }

    switch(mat.alphaMode)
    {
    case glTF::ALPHA_OPAQUE:
        materialDesc->SetRenderingMode(RenderingMode::Opaque);
        break;
    case glTF::ALPHA_BLEND:
        materialDesc->SetRenderingMode(RenderingMode::Blend);
        break;
    case glTF::ALPHA_MASK:
        materialDesc->SetRenderingMode(RenderingMode::Mask);
        break;
    default:
        materialDesc->SetRenderingMode(RenderingMode::Opaque);
    }

    materialDesc->SetAlphaCutoff(mat.alphaCutoff);

    if (!mat.doubleSided)
    {
        materialDesc->SetRenderingOption(RenderingOption::SingleSided);
    }

    //  GLTF compliance: Tag incoming materials as originating from GLTF.
    materialDesc->SetRenderingOption(RenderingOption::GLTFMaterial);

    return materialDesc;
}

std::shared_ptr<TextureDescriptor> GLTFToAsset3DConverter::ParseTexture(VisitorState& visitorState, const std::string& textureId, std::shared_ptr<MaterialLayer::TextureSampler>& sampler, uint8_t flags)
{
    const glTF::Texture& texture = visitorState.gltfDoc.textures[textureId];
    sampler = texture.samplerId.empty() ? std::make_shared<MaterialLayer::TextureSampler>() : GetOrAddSampler(visitorState, texture.samplerId);

    auto it = visitorState.textures.find(textureId);
    if (it != visitorState.textures.end())
    {
        return it->second;
    }

    // Determine whether it's a Buffer PNG or a URI PNG
    std::shared_ptr<TextureDescriptor> textureDesc;
    const glTF::Image& image = visitorState.gltfDoc.images[texture.imageId];

    std::vector<uint8_t> imageData = m_resourceReader.ReadBinaryData(visitorState.gltfDoc, image);

    auto data = std::make_unique<uint8_t[]>(imageData.size());
    memcpy_s(data.get(), imageData.size(), imageData.data(), imageData.size());

    textureDesc = std::make_shared<TextureDescriptor>(std::move(data), imageData.size());
    textureDesc->SetFlags(flags);

    CopyFromGltfChildOfRootProperty(texture, textureDesc.get());

    visitorState.textures[textureId] = textureDesc;

    return textureDesc;
}

std::shared_ptr<MaterialLayer::TextureSampler> GLTFToAsset3DConverter::ParseSampler(const Microsoft::glTF::Document& gltfDocument, const std::string& samplerId)
{
    std::shared_ptr<MaterialLayer::TextureSampler> sampler = std::make_shared<MaterialLayer::TextureSampler>();

    const auto& gltfSampler = gltfDocument.samplers[samplerId];

    auto getWrapSettings = [](size_t gltfWrap, Framework::SamplerDefinition::EAddressMode &sdkWrap)
    {
        switch (gltfWrap)
        {
            case glTF::Wrap_CLAMP_TO_EDGE:
                sdkWrap = Framework::AddressMode::kClamp;
                break;
            case glTF::Wrap_MIRRORED_REPEAT:
                sdkWrap = Framework::AddressMode::kMirroredWrap;
                break;
            case glTF::Wrap_REPEAT:
                sdkWrap = Framework::AddressMode::kWrap;
                break;
        }
    };

    getWrapSettings(gltfSampler.wrapS, sampler->wrapU);
    getWrapSettings(gltfSampler.wrapT, sampler->wrapV);

    if (gltfSampler.magFilter || gltfSampler.minFilter)
    {
        const auto gltfMagFilter = gltfSampler.magFilter ? gltfSampler.magFilter.Get() : Spectre::Utils::glTF::GetDefaultMagFilterMode();
        const auto gltfMinFilter = gltfSampler.minFilter ? gltfSampler.minFilter.Get() : Spectre::Utils::glTF::GetDefaultMinFilterMode();

        switch (gltfMagFilter)
        {
        case glTF::MagFilter_NEAREST:
            switch (gltfMinFilter)
            {
            case glTF::MinFilter_NEAREST:
                sampler->filter = Framework::FilterMode::kMinPoint_MagPoint_MipPoint;
                break;
            case glTF::MinFilter_LINEAR:
                sampler->filter = Framework::FilterMode::kMinLinear_MagPoint_MipPoint;
                break;
            case glTF::MinFilter_NEAREST_MIPMAP_NEAREST:
                sampler->filter = Framework::FilterMode::kMinPoint_MagPoint_MipPoint;
                break;
            case glTF::MinFilter_LINEAR_MIPMAP_NEAREST:
                sampler->filter = Framework::FilterMode::kMinLinear_MagPoint_MipPoint;
                break;
            case glTF::MinFilter_NEAREST_MIPMAP_LINEAR:
                sampler->filter = Framework::FilterMode::kMinPoint_MagPoint_MipLinear;
                break;
            case glTF::MinFilter_LINEAR_MIPMAP_LINEAR:
                sampler->filter = Framework::FilterMode::kMinLinear_MagPoint_MipLinear;
                break;
            }
            break;

        case glTF::MagFilter_LINEAR:
            switch (gltfMinFilter)
            {
            case glTF::MinFilter_NEAREST:
                sampler->filter = Framework::FilterMode::kMinPoint_MagLinear_MipPoint;
                break;
            case glTF::MinFilter_LINEAR:
                sampler->filter = Framework::FilterMode::kMinLinear_MagLinear_MipPoint;
                break;
            case glTF::MinFilter_NEAREST_MIPMAP_NEAREST:
                sampler->filter = Framework::FilterMode::kMinPoint_MagLinear_MipPoint;
                break;
            case glTF::MinFilter_LINEAR_MIPMAP_NEAREST:
                sampler->filter = Framework::FilterMode::kMinLinear_MagLinear_MipPoint;
                break;
            case glTF::MinFilter_NEAREST_MIPMAP_LINEAR:
                sampler->filter = Framework::FilterMode::kMinPoint_MagLinear_MipLinear;
                break;
            case glTF::MinFilter_LINEAR_MIPMAP_LINEAR:
                sampler->filter = Framework::FilterMode::kMinLinear_MagLinear_MipLinear;
                break;
            }
            break;
        }
    }
    else
    {
        sampler->filter.Clear(); // TextureSampler::filter defaults to kBilinear so set it to 'undefined' if the glTF sampler defines neither min or mag filters
    }

    return sampler;
}

void GLTFToAsset3DConverter::PopulatePositions(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const
{
    auto& positionsAccessor = gltfDocument.accessors[accessorId];
    auto positions = glTF::MeshPrimitiveUtils::GetPositions(gltfDocument, m_resourceReader, positionsAccessor);
    geometry.SetPositions(positions.data(), positionsAccessor.count);
}

void GLTFToAsset3DConverter::PopulateNormals(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const
{
    auto& normalsAccessor = gltfDocument.accessors[accessorId];
    auto normals = glTF::MeshPrimitiveUtils::GetNormals(gltfDocument, m_resourceReader, normalsAccessor);
    geometry.SetNormals(normals.data(), normalsAccessor.count);
}

void GLTFToAsset3DConverter::PopulateTangents(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const
{
    auto& tangentsAccessor = gltfDocument.accessors[accessorId];
    auto tangents = glTF::MeshPrimitiveUtils::GetTangents(gltfDocument, m_resourceReader, tangentsAccessor);
    geometry.SetTangents(tangents.data(), tangentsAccessor.count);
}

void GLTFToAsset3DConverter::PopulateUv0(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const
{
    auto& uv0sAccessor = gltfDocument.accessors[accessorId];
    auto uv0s = glTF::MeshPrimitiveUtils::GetTexCoords(gltfDocument, m_resourceReader, uv0sAccessor);
    geometry.SetUv0s(uv0s.data(), uv0sAccessor.count);
}

void GLTFToAsset3DConverter::PopulateUv1(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const
{
    auto& uv1sAccessor = gltfDocument.accessors[accessorId];
    auto uv1s = glTF::MeshPrimitiveUtils::GetTexCoords(gltfDocument, m_resourceReader, uv1sAccessor);
    geometry.SetUv1s(uv1s.data(), uv1sAccessor.count);
}

void GLTFToAsset3DConverter::PopulateColor(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& accessorId) const
{
    auto& colorsAccessor = gltfDocument.accessors[accessorId];
    auto colors = glTF::MeshPrimitiveUtils::GetColors(gltfDocument, m_resourceReader, colorsAccessor);
    geometry.SetColors(colors.data(), colors.size());
}

void GLTFToAsset3DConverter::PopulateJoints(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const std::string& indicesAccessorId, const std::string& weightsAccessorId) const
{
    auto& jointIndicesAccessor = gltfDocument.accessors[indicesAccessorId];
    // HACK: Truncating 16-bit indices to 8-bit will throw with >255 joints
    auto joints = jointIndicesAccessor.componentType == glTF::COMPONENT_UNSIGNED_BYTE ?
        glTF::MeshPrimitiveUtils::GetJointIndices32(gltfDocument, m_resourceReader, jointIndicesAccessor) :
        GetTruncatedJointIndices32(gltfDocument, m_resourceReader, jointIndicesAccessor);

    auto& jointWeightsAccessor = gltfDocument.accessors[weightsAccessorId];
    auto weights = glTF::MeshPrimitiveUtils::GetJointWeights32(gltfDocument, m_resourceReader, jointWeightsAccessor);

    geometry.SetJoints(std::move(joints), std::move(weights));
}

void GLTFToAsset3DConverter::PopulateMorphTargetPositions(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const Microsoft::glTF::MorphTarget& morphTarget) const
{
    auto targetPositions = glTF::MeshPrimitiveUtils::GetPositions(gltfDocument, m_resourceReader, morphTarget);
    auto& targetPositionAccessor = gltfDocument.accessors[morphTarget.positionsAccessorId];
    SpectreUnusedLocal(targetPositionAccessor);
    SpectreAssert(targetPositions.size() % 3 == 0);
    SpectreAssert(targetPositions.size() / 3 == targetPositionAccessor.count);
    if ((targetPositions.size() / 3 != geometry.GetPositions().size()) && (geometry.GetPositions().size() > 0))
    {
        throw Utils::SpectreException("Morph Target position count differs from mesh.");
    }

    geometry.AddMorphTargetPositions(std::move(targetPositions));
}

void GLTFToAsset3DConverter::PopulateMorphTargetNormals(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const Microsoft::glTF::MorphTarget& morphTarget) const
{
    auto targetNormals = glTF::MeshPrimitiveUtils::GetNormals(gltfDocument, m_resourceReader, morphTarget);
    auto& targetNormalsAccessor = gltfDocument.accessors[morphTarget.normalsAccessorId];
    SpectreUnusedLocal(targetNormalsAccessor);
    SpectreAssert(targetNormals.size() % 3 == 0);
    SpectreAssert(targetNormals.size() / 3 == targetNormalsAccessor.count);
    if ((targetNormals.size() / 3 != geometry.GetNormals().size()) && (geometry.GetNormals().size() > 0))
    {
        throw Utils::SpectreException("Morph Target normal count differs from mesh.");
    }

    geometry.AddMorphTargetNormals(std::move(targetNormals));
}

void GLTFToAsset3DConverter::PopulateMorphTargetTangents(const Microsoft::glTF::Document& gltfDocument, Geometry& geometry, const Microsoft::glTF::MorphTarget& morphTarget) const
{
    auto targetTangents = glTF::MeshPrimitiveUtils::GetTangents(gltfDocument, m_resourceReader, morphTarget);
    auto& targetTangentsAccessor = gltfDocument.accessors[morphTarget.tangentsAccessorId];
    SpectreUnusedLocal(targetTangentsAccessor);
    SpectreAssert(targetTangents.size() % 3 == 0);
    SpectreAssert(targetTangents.size() / 3 == targetTangentsAccessor.count);
    if ((targetTangents.size() / 3 != geometry.GetTangents().size()) && (geometry.GetTangents().size() > 0))
    {
        throw Utils::SpectreException("Morph Target tangent count differs from mesh.");
    }

    geometry.AddMorphTargetTangents(std::move(targetTangents));
}
