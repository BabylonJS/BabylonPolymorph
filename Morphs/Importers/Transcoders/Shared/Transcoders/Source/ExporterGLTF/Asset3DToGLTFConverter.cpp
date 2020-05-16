/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <string>
#include <queue>
#include <algorithm>
#include <sstream>

// TODO: TEMP COMMENT
//#include <BabylonVersionInternal.h>

#include <ImagingComponent/ImagingComponent.h>
#include <CoreUtils/Gltf.h>
#include <CoreUtils/GLTFChannelAnimations.h>
#include <CoreUtils/Memory.h>

#include <Asset3D/Camera.h>
#include <Asset3D/Animation.h>
#include <Asset3D/MaterialConversionUtils.h>
#include <Asset3D/TexturePackingUtils.h>
#include <ExporterGLTF/Asset3DToGLTFConverter.h>
#include <ExporterGLTF/ExtensionsMSFT.h>

#include <GLTFSDK/BufferBuilder.h>
#include <GLTFSDK/Constants.h>
#include <GLTFSDK/PBRUtils.h>
#include <GLTFSDK/Serialize.h>

DEFINE_TRACE_AREA(Asset3DToGLTFConverter, 0);

using namespace Babylon::Transcoder;
using namespace Microsoft;

namespace glTFUtils = Babylon::Utils::glTF;

namespace
{
    void AppendElementValues(std::vector<float>& elements, const Babylon::Utils::Math::Quaternion& element)
    {
        elements.push_back(element.x);
        elements.push_back(element.y);
        elements.push_back(element.z);
        elements.push_back(element.w);
    }

    void AppendElementValues(std::vector<float>& elements, const Babylon::Utils::Math::Vector3& element)
    {
        elements.push_back(element.x);
        elements.push_back(element.y);
        elements.push_back(element.z);
    }

    template<typename T>
    void AppendElementValues(std::vector<T>& elements, const std::vector<T>& element)
    {
        elements.insert(std::end(elements), std::begin(element), std::end(element));
    }

    struct PositionExtents
    {
        std::vector<float> min;
        std::vector<float> max;
    };

    PositionExtents GetExtents(const std::vector<Babylon::Utils::Math::Vector3>& positions)
    {
        std::vector<float> min(3, std::numeric_limits<float>::max());
        std::vector<float> max(3, std::numeric_limits<float>::lowest());

        for (const auto& position : positions)
        {
            min[0] = std::min(position.x, min[0]);
            min[1] = std::min(position.y, min[1]);
            min[2] = std::min(position.z, min[2]);
            max[0] = std::max(position.x, max[0]);
            max[1] = std::max(position.y, max[1]);
            max[2] = std::max(position.z, max[2]);
        }

        return { min, max };
    }

    PositionExtents GetExtents(const std::vector<float>& positions)
    {
        std::vector<float> min(3, std::numeric_limits<float>::max());
        std::vector<float> max(3, std::numeric_limits<float>::lowest());

        for (size_t i = 0; i < positions.size(); i += 3)
        {
            min[0] = std::min(positions[i],     min[0]);
            min[1] = std::min(positions[i + 1], min[1]);
            min[2] = std::min(positions[i + 2], min[2]);
            max[0] = std::max(positions[i],     max[0]);
            max[1] = std::max(positions[i + 1], max[1]);
            max[2] = std::max(positions[i + 2], max[2]);
        }

        return { min, max };
    }

    template<typename T, typename GetElementFunction>
    std::vector<T> FlattenElements(const GetElementFunction& getElementFunction, size_t elementCount, short componentCount)
    {
        if (elementCount == 0 || componentCount == 0)
        {
            return std::vector<T>();
        }

        std::vector<T> values;
        values.reserve(elementCount * componentCount);

        for (size_t i = 0; i < elementCount; ++i)
        {
            auto element = getElementFunction(i);
            AppendElementValues(values, element);
        }
        return values;
    }

    void ValidateNormals(const std::vector<Babylon::Utils::Math::Vector3>& normals)
    {
        size_t warnCount = 0;
        for (size_t i = 0; i < normals.size(); i++)
        {
            if (normals[i] == Babylon::Utils::Math::Vector3::Zero)
            {
                warnCount++;
                if (warnCount < 10)
                {
                    TRACE_WARN(Asset3DToGLTFConverter, "Normal with length ZERO found at index %zu output may be invalid glTF", i);
                }
            }
        }

        if (warnCount > 0)
        {
            TRACE_WARN(Asset3DToGLTFConverter, "Normal with length ZERO found %zu times. Output may be invalid glTF.", warnCount);
        }
    }

    void ValidateTangents(const std::vector<Babylon::Utils::Math::Vector4>& tangents)
    {
        size_t warnCount = 0;
        for (size_t i = 0; i < tangents.size(); i++)
        {
            if (tangents[i] == Babylon::Utils::Math::Vector4::UnitW)
            {
                warnCount++;
                if (warnCount < 10)
                {
                    TRACE_WARN(Asset3DToGLTFConverter, "Tangent with length ZERO found at index %zu output may be invalid glTF", i);
                }
            }

            // Have not encountered any input with non-zero, non-unit tangents so skipping expensive normalization.
            // Correct way of normalizing a tangent for glTF:
            //     auto vec = Babylon::Utils::Math::Vector3(tangent.x, tangent.y, tangent.z);
            //     vec.Normalize();
            //     return Babylon::Utils::Math::Vector4(vec.x, vec.y, vec.z, std::copysign(1.0f, tangent.w));
        };

        if (warnCount > 0)
        {
            TRACE_WARN(Asset3DToGLTFConverter, "Tangent with length ZERO found %zu times. Output may be invalid glTF.", warnCount);
        }
    }

    std::vector<uint8_t> GetJoint0s(const Geometry& geometry)
    {
        auto getElementFunction = [&geometry](size_t i)
        {
            const auto joint = geometry.GetJointIndices()[i];
            std::vector<uint8_t> joint0 = {
                static_cast<uint8_t>((joint >> 0) & 0xFF),
                static_cast<uint8_t>((joint >> 8) & 0xFF),
                static_cast<uint8_t>((joint >> 16) & 0xFF),
                static_cast<uint8_t>((joint >> 24) & 0xFF)
            };
            return joint0;
        };
        return FlattenElements<uint8_t>(getElementFunction, geometry.GetVertexCount(), glTF::Accessor::GetTypeCount(glTF::TYPE_VEC4));
    }

    std::vector<float> GetWeight0s(const Geometry& geometry)
    {
        // Serialize joint weights as floats to avoid a bug in Babylon.js (as of 2018-01-05)
        // which doesn't correctly load the packed normalized values we use internally
        auto getElementFunction = [&geometry](size_t i)
        {
            const auto packedWeights = geometry.GetJointWeights()[i];
            std::vector<float> weight0 = {
                ((packedWeights >> 0) & 0xFF) / 255.0f,
                ((packedWeights >> 8) & 0xFF) / 255.0f,
                ((packedWeights >> 16) & 0xFF) / 255.0f,
                ((packedWeights >> 24) & 0xFF) / 255.0f
            };
            return weight0;
        };

        return FlattenElements<float>(getElementFunction, geometry.GetVertexCount(), glTF::Accessor::GetTypeCount(glTF::TYPE_VEC4));
    }

    std::vector<float> GetRotationKeyframeValues(const std::vector<Babylon::Transcoder::Animation::MotionState>& jointMotion)
    {
        auto getElementFunction = [&jointMotion](size_t i)
        {
            Babylon::Utils::Math::Quaternion normalized;
            jointMotion[i].rot.Normalize(normalized);
            return normalized;
        };

        return FlattenElements<float>(getElementFunction, jointMotion.size(), 4);
    }

    std::vector<float> GetTranslationKeyframeValues(const std::vector<Babylon::Transcoder::Animation::MotionState>& jointMotion)
    {
        auto getElementFunction = [&jointMotion](size_t i)
        {
            return jointMotion[i].trans;
        };

        return FlattenElements<float>(getElementFunction, jointMotion.size(), 3);
    }

    std::vector<float> GetScaleKeyframeValues(const std::vector<Babylon::Transcoder::Animation::MotionState>& jointMotion)
    {
        auto getElementFunction = [&jointMotion](size_t i)
        {
            return jointMotion[i].scale;
        };

        return FlattenElements<float>(getElementFunction, jointMotion.size(), 3);
    }

    // From: \Engine\Products\Components\NativeRenderer\cpp\Source\Engine\SceneNode.cpp
    bool MatrixDecompose(const Babylon::Utils::Math::Matrix& matrix,
        Babylon::Utils::Math::Vector3& outScale,
        Babylon::Utils::Math::Quaternion& outRotation,
        Babylon::Utils::Math::Vector3& outTranslation)
    {
        // WORKAROUND FOR BUG IN XMMatrixDecompose().
        //
        // The implementation*** of XMMatrixDecompose() used by SimpleMath::Matrix::Decompose() has a bug
        // whereby the wrong rotation is returned if the input matrix has a small scaling. In particular,
        // if axis magnitudes are smaller than around 0.0001 (XM3_DECOMP_EPSILON), then the rotation quaternion
        // often includes an erroneous 180-degree rotation compared to the correct result.
        //
        // This affects many matrices, but a simple example is a basic uniform scale matrix (no rotation or translation):
        //      [k 0 0 0]
        //      [0 k 0 0]       where k < 0.0001
        //      [0 0 k 0]
        //      [0 0 0 1]
        //
        // For this matrix, Matrix::Decompose() returns an output rotation quaternion of {1,0,0,0}, i.e. a 180-degree rotation around the x axis,
        // whereas the correct result has no rotation, i.e. the identity quaternion {0,0,0,1} or its equivalent {0,0,0,-1}.
        //
        // We workaround this rather curious state of affairs by extracting the scale manually, prior to calling Matrix::Decompose().
        //
        //
        // *** The source code for XMMatrixDecompose is in DirectXMathMatrix.inl, usually distributed as part of the Windows Kits SDK, e.g.:
        //      C:\Program Files(x86)\Windows Kits\10\Include\10.0.10586.0\um\DirectXMathMatrix.inl

        // Note: Right/Up/Backward are rows in order (0,1,2) for the axes (x,y,z) according to SimpleMath nomenclature.
        Babylon::Utils::Math::Vector3 axisX = matrix.Right();
        Babylon::Utils::Math::Vector3 axisY = matrix.Up();
        Babylon::Utils::Math::Vector3 axisZ = matrix.Backward();
        Babylon::Utils::Math::Vector3 translation = matrix.Translation();

        // Early out from decomposing matrices with zero upper 3x3s. These can come from animations that have 
        // zero rotation and scale but valid translations. e.g. As generated by Adobe Animate samples
        if (axisX == Babylon::Utils::Math::Vector3::Zero &&
            axisY == Babylon::Utils::Math::Vector3::Zero &&
            axisZ == Babylon::Utils::Math::Vector3::Zero)
        {
            outScale = Babylon::Utils::Math::Vector3::Zero;
            outRotation = Babylon::Utils::Math::Quaternion::Identity;
            outTranslation = translation;
            return true;
        }

        float lengthX = axisX.Length();
        float lengthY = axisY.Length();
        float lengthZ = axisZ.Length();
        Babylon::Utils::Math::Vector3 scaleExtracted{ lengthX, lengthY, lengthZ };

        if (lengthX != 0.0f)
            axisX /= lengthX;

        if (lengthY != 0.0f)
            axisY /= lengthY;

        if (lengthZ != 0.0f)
            axisZ /= lengthZ;

        Babylon::Utils::Math::Matrix matrixAdjusted = Babylon::Utils::Math::Matrix
        {
            Babylon::Utils::Math::Vector4::ToVector4(axisX, 0.0f),
            Babylon::Utils::Math::Vector4::ToVector4(axisY, 0.0f),
            Babylon::Utils::Math::Vector4::ToVector4(axisZ, 0.0f),
            Babylon::Utils::Math::Vector4::ToVector4(translation, 1.0f)
        };

        if (matrixAdjusted.Decompose(outScale, outRotation, outTranslation))
        {
            // We now combine our extracted scale with any extra scale extracted by Decompose().
            // Because we've already extracted the primary scaling, the remaining scale
            // should only be any reflection/handedness changes required to allow
            // decomposition into a rotation and scale.
            outScale *= scaleExtracted;
            return true;
        }

        return false;
    }

    void SetGltfTRS(glTF::Node& node, const Babylon::Utils::Math::Matrix& sourceMatrix)
    {
        Babylon::Utils::Math::Vector3 translation;
        Babylon::Utils::Math::Quaternion rotation;
        Babylon::Utils::Math::Vector3 scale;

        MatrixDecompose(sourceMatrix, scale, rotation, translation);

        node.translation.x = translation.x;
        node.translation.y = translation.y;
        node.translation.z = translation.z;

        node.rotation.x = rotation.x;
        node.rotation.y = rotation.y;
        node.rotation.z = rotation.z;
        node.rotation.w = rotation.w;

        node.scale.x = scale.x;
        node.scale.y = scale.y;
        node.scale.z = scale.z;
    }

    std::string GetGenerator()
    {
        std::stringstream ss;
        // TODO: TEMP COMMENT
        ss << glTF::MSFT_GLTF_EXPORTER_NAME << " "; // << Babylon_PACKAGE_VERSION;
        return ss.str();
    }

    void CopyExtensionsToNode(const ITraversableBase& a3dNode, glTF::Document& doc, glTF::glTFProperty& gltfNode, const std::string& extensionsKey)
    {
        auto extensions = a3dNode.GetExtensions(extensionsKey);
        for (auto it = extensions.ExtensionMap.begin(); it != extensions.ExtensionMap.end(); ++it)
        {
            const std::string& key = it->first;
            const std::string& val = *(it->second).get();
            gltfNode.extensions[key] = val;
            doc.extensionsUsed.emplace(key);
        }
    }

    void CopyExtrasToNode(const ITraversableBase& a3dNode, glTF::glTFProperty& gltfNode)
    {
        gltfNode.extras = a3dNode.GetExtras();
    }

    // Should only be called once for each gltfNode
    void CopyToGltfProperty(const ITraversableBase& a3dNode, glTF::Document& doc, glTF::glTFProperty& gltfNode, const std::string& extensionsKey = Babylon::Utils::glTF::kExtensionsDefault)
    {
        BabylonAssert(gltfNode.extras.empty());
        CopyExtensionsToNode(a3dNode, doc, gltfNode, extensionsKey);
        CopyExtrasToNode(a3dNode, gltfNode);
    }

    Microsoft::glTF::MeshMode GetGltfMeshPrimitiveMode(const Babylon::Transcoder::GeometryTopology topology)
    {
        switch (topology)
        {
        case GeometryTopology::kTriangles:
            return glTF::MeshMode::MESH_TRIANGLES;

        case GeometryTopology::kLines:
            return glTF::MeshMode::MESH_LINES;

        case GeometryTopology::kPoints:
            return glTF::MeshMode::MESH_POINTS;
        }

        throw Babylon::Utils::BabylonException("Unrecognized primitive mode.");
    }

    glTF::Camera ToGLTFCamera(const Babylon::Transcoder::Camera& cam)
    {
        switch (cam.GetProjectionType())
        {
        case Babylon::Transcoder::ProjectionType::kPerspective:
        {
            auto& perspective = cam.GetPerspective();

            auto gltfPerspective = std::make_unique<glTF::Perspective>(
                perspective.znear,
                perspective.yfov);

            if (perspective.aspectRatio)
            {
                gltfPerspective->aspectRatio = *perspective.aspectRatio;
            }

            if (perspective.zfar)
            {
                gltfPerspective->zfar = *perspective.zfar;
            }

            return glTF::Camera(std::to_string(cam.GetId()), cam.GetName(), std::move(gltfPerspective));
        }
        case Babylon::Transcoder::ProjectionType::kOrthographic:
        {
            auto& orthographic = cam.GetOrthographic();

            auto gltfOrthographic = std::make_unique<glTF::Orthographic>(
                orthographic.zfar,
                orthographic.znear,
                orthographic.xmag,
                orthographic.ymag);

            return glTF::Camera(std::to_string(cam.GetId()), cam.GetName(), std::move(gltfOrthographic));
        }
        default:
            throw Babylon::Utils::BabylonException("Unrecognized camera projection type");
        }
    }

    glTF::Color3 ToGLTFColor3(const Babylon::Utils::Math::Color& color)
    {
        return glTF::Color3(color.R(), color.G(), color.B());
    }

    glTF::Color4 ToGLTFColor4(const Babylon::Utils::Math::Color& color)
    {
        return glTF::Color4(color.R(), color.G(), color.B(), color.A());
    }

    glTF::AlphaMode ToGLTFAlphaMode(RenderingMode renderingMode)
    {
        switch (renderingMode)
        {
        case RenderingMode::Opaque:
            return glTF::ALPHA_OPAQUE;
        case RenderingMode::Blend:
            return glTF::ALPHA_BLEND;
        case RenderingMode::Mask:
            return glTF::ALPHA_MASK;
        default:
            throw Babylon::Utils::BabylonException("Call MaterialDescriptor::ConvertFromLegacy() to detect exact RenderingMode");
        }
    }
}

Asset3DToGLTFConverter::Asset3DToGLTFConverter(const Asset3D& asset3d, const GLTFExportOptions& options, Babylon::Framework::ICancellationTokenPtr cancellationToken)
    : m_asset3d(asset3d),
    m_options(options),
    m_cancellationToken(cancellationToken)
{
    if (m_cancellationToken == nullptr)
    {
        m_cancellationToken = Babylon::Framework::MakeNullCancellationToken();
    }
}

std::shared_ptr<glTF::Document> Asset3DToGLTFConverter::Write(IGLTFWriter& writer)
{
    glTF::Asset asset;
    asset.version = glTF::GLTF_VERSION_2_0;
    asset.generator = GetGenerator();

    m_gltfDocument = std::make_shared<glTF::Document>(std::move(asset));

    PopulateDocument(writer);

    auto extensionSerializer = GetMSFTKHRExtensionSerializer();
    writer.Finalize(*m_gltfDocument, extensionSerializer);

    return m_gltfDocument;
}

glTF::MeshPrimitive Asset3DToGLTFConverter::CreateMeshPrimitive(glTF::BufferBuilder& bufferBuilder, const Geometry& geometry) const
{
    m_cancellationToken->CheckCancelledAndThrow();

    glTF::MeshPrimitive meshPrimitive;
    meshPrimitive.mode = GetGltfMeshPrimitiveMode(geometry.GetTopology());

    if (geometry.HasIndices())
    {
        bufferBuilder.AddBufferView(glTF::ELEMENT_ARRAY_BUFFER);
        meshPrimitive.indicesAccessorId = bufferBuilder.AddAccessor(geometry.GetIndices(), { glTF::TYPE_SCALAR, glTF::COMPONENT_UNSIGNED_INT }).id;
    }

    // Positions
    {
        const auto& positions = geometry.GetPositions();
        const auto extents = GetExtents(positions);

        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_POSITION] = bufferBuilder.AddAccessor(positions.data(), positions.size(), { glTF::TYPE_VEC3, glTF::COMPONENT_FLOAT, false, std::move(extents.min), std::move(extents.max) }).id;
    }

    if (geometry.HasNormals())
    {
        const auto& normals = geometry.GetNormals();
        ValidateNormals(normals);

        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_NORMAL] = bufferBuilder.AddAccessor(normals.data(), normals.size(), { glTF::TYPE_VEC3, glTF::COMPONENT_FLOAT }).id;
    }

    if (geometry.HasTangents())
    {
        const auto& tangents = geometry.GetTangents();
        ValidateTangents(tangents);

        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_TANGENT] = bufferBuilder.AddAccessor(tangents.data(), tangents.size(), { glTF::TYPE_VEC4, glTF::COMPONENT_FLOAT }).id;
    }

    if (geometry.HasUv0s())
    {
        const auto& uv0s = geometry.GetUv0s();
        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_TEXCOORD_0] = bufferBuilder.AddAccessor(uv0s.data(), uv0s.size(), { glTF::TYPE_VEC2, glTF::COMPONENT_FLOAT }).id;
    }

    if (geometry.HasUv1s())
    {
        const auto& uv1s = geometry.GetUv1s();
        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_TEXCOORD_1] = bufferBuilder.AddAccessor(uv1s.data(), uv1s.size(), { glTF::TYPE_VEC2, glTF::COMPONENT_FLOAT }).id;
    }

    if (geometry.HasColors())
    {
        const auto& colors = geometry.GetColors();
        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_COLOR_0] = bufferBuilder.AddAccessor(colors.data(), colors.size(), { glTF::TYPE_VEC4, glTF::COMPONENT_UNSIGNED_BYTE, true }).id;
    }

    if (geometry.HasSkinnedAnimation())
    {
        const auto joint0s = GetJoint0s(geometry);
        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_JOINTS_0] = bufferBuilder.AddAccessor(joint0s, { glTF::TYPE_VEC4, glTF::COMPONENT_UNSIGNED_BYTE }).id;

        const auto weight0s = GetWeight0s(geometry);
        bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
        meshPrimitive.attributes[glTF::ACCESSOR_WEIGHTS_0] = bufferBuilder.AddAccessor(weight0s, { glTF::TYPE_VEC4, glTF::COMPONENT_FLOAT }).id;
    }

    if (geometry.HasMorphAnimation())
    {
        std::vector<float> min;
        std::vector<float> max;

        // Positions
        const auto& morphTargetsPositions = geometry.GetMorphTargetPositions();
        meshPrimitive.targets.resize(morphTargetsPositions.size());
        for (size_t i = 0; i < morphTargetsPositions.size(); i++)
        {
            auto extents = GetExtents(morphTargetsPositions[i]);
            bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
            meshPrimitive.targets[i].positionsAccessorId = bufferBuilder.AddAccessor(morphTargetsPositions[i], { glTF::TYPE_VEC3, glTF::COMPONENT_FLOAT, false, std::move(extents.min), std::move(extents.max) }).id;
        }

        // Normals
        const auto& morphTargetsNormals = geometry.GetMorphTargetNormals();
        BabylonAssert(morphTargetsNormals.size() == 0 || (morphTargetsNormals.size() == morphTargetsPositions.size()));
        for (size_t i = 0; i < morphTargetsNormals.size(); i++)
        {
            bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
            meshPrimitive.targets[i].normalsAccessorId = bufferBuilder.AddAccessor(morphTargetsNormals[i], { glTF::TYPE_VEC3, glTF::COMPONENT_FLOAT }).id;
        }

        // Tangents
        const auto& morphTargetsTangents = geometry.GetMorphTargetTangents();
        BabylonAssert(morphTargetsTangents.size() == 0 || (morphTargetsTangents.size() == morphTargetsPositions.size()));
        for (size_t i = 0; i < morphTargetsTangents.size(); i++)
        {
            bufferBuilder.AddBufferView(glTF::ARRAY_BUFFER);
            meshPrimitive.targets[i].tangentsAccessorId = bufferBuilder.AddAccessor(morphTargetsTangents[i], { glTF::TYPE_VEC3, glTF::COMPONENT_FLOAT }).id;
        }
    }

    return meshPrimitive;
}

void Asset3DToGLTFConverter::AddAnimationsAndSkeletons(glTF::BufferBuilder& bufferBuilder)
{
    if (m_asset3d.GetSkeletons().size() == 0 && m_asset3d.GetAnimations().size() == 0)
    {
        return;
    }

    auto& skeletons = m_asset3d.GetSkeletons();
    for (size_t skeletonIndex = 0; skeletonIndex < skeletons.size(); skeletonIndex++)
    {
        auto& skeleton = skeletons[skeletonIndex];

        // Skin Transcoding
        glTF::Skin skin;
        skin.id = std::to_string(skeletonIndex);
        skin.name = skeleton.m_name;
        skin.jointIds.reserve(skeleton.m_joints.size());

        std::vector<float> invBindMatrices;
        invBindMatrices.reserve(skeleton.m_joints.size() * 16);

        for (size_t jointIndex = 0; jointIndex < skeleton.m_joints.size(); jointIndex++)
        {
            const auto floatMatrix = static_cast<const float*>(skeleton.m_joints[jointIndex].m_InvBindPose);
            invBindMatrices.insert(invBindMatrices.end(), floatMatrix, floatMatrix + 16);
        }

        bufferBuilder.AddBufferView();// Don't specify a BufferViewTarget value as this BufferView doesn't store vertex attribute data

        const glTF::Accessor& invBindAccessor = bufferBuilder.AddAccessor(invBindMatrices, {glTF::TYPE_MAT4, glTF::COMPONENT_FLOAT });

        skin.inverseBindMatricesAccessorId = invBindAccessor.id;

        for (size_t jointIndex = 0; jointIndex < skeleton.m_joints.size(); jointIndex++)
        {
            auto& joint = skeleton.m_joints[jointIndex];

            // Set Skeleton ID to joint node with no parent
            // TODO: Root of joint hierachy should point to root scene node if no root joint node is defined
            if (joint.m_ParentJointIndex == -1)
            {
                skin.skeletonId = std::to_string(joint.m_sceneNodeId);
            }

            skin.jointIds.push_back(std::to_string(joint.m_sceneNodeId));
        }

        m_gltfDocument->skins.Append(std::move(skin));
    }

    // Animation data is written into a separate buffer than geometry LOD information, as it can be shared
    // across different geometry LODs

    auto& animations = m_asset3d.GetAnimations();
    for (size_t animIndex = 0; animIndex < animations.size(); animIndex++)
    {
        auto& animItem = animations[animIndex];

        //  Skip animations which have no skeleton data (until we support other types)
        if (!(animItem.m_metadataFlags & Animation::eMetadataFlags::kSkeletonAnimationLoaded))
        {
            continue;
        }

        glTF::Animation gltfAnim;
        gltfAnim.name = animItem.GetName();
        gltfAnim.id = std::to_string(m_gltfDocument->animations.Size());

        gltfAnim.channels.Reserve(3 * animItem.m_jointKeyframes.size());
        gltfAnim.samplers.Reserve(3 * animItem.m_jointKeyframes.size());

        for (size_t jointIndex = 0; jointIndex < animItem.m_jointKeyframes.size(); jointIndex++)
        {
            auto& jointAnim = animItem.m_jointKeyframes[jointIndex];

            if (jointAnim.m_keyframeTimes.size() == 0)
            {
                continue;
            }

            auto& joint = skeletons[jointAnim.m_skeletonId].m_joints[jointAnim.m_skeletonJointIndex];
            std::string nodeId = std::to_string(joint.m_sceneNodeId);
            size_t index = animIndex * animItem.m_jointKeyframes.size() + jointIndex;

            std::vector<float> keyframeTimes;
            keyframeTimes.reserve(jointAnim.m_keyframeTimes.size());
            std::transform(jointAnim.m_keyframeTimes.begin(), jointAnim.m_keyframeTimes.end(),
                back_inserter(keyframeTimes), [](double d) { return static_cast<float>(d); });

            // TODO: Write out keyframeTimes accessor once instead of 3 times (CreateChannelAndSampler does it currently)

            // Store all rotation, translation, and scale joint movements (per joint) into separate channels and samplers.
            auto motionRotData = CreateChannelAndSampler(
                bufferBuilder, nodeId, index, glTF::TARGET_ROTATION,
                keyframeTimes, GetRotationKeyframeValues(jointAnim.m_keyframeValues), glTF::TYPE_VEC4);

            auto motionTranData = CreateChannelAndSampler(
                bufferBuilder, nodeId, index, glTF::TARGET_TRANSLATION,
                keyframeTimes, GetTranslationKeyframeValues(jointAnim.m_keyframeValues), glTF::TYPE_VEC3);

            auto motionScaleData = CreateChannelAndSampler(
                bufferBuilder, nodeId, index, glTF::TARGET_SCALE,
                keyframeTimes, GetScaleKeyframeValues(jointAnim.m_keyframeValues), glTF::TYPE_VEC3);

            gltfAnim.channels.Append(motionRotData.first);
            gltfAnim.channels.Append(motionTranData.first);
            gltfAnim.channels.Append(motionScaleData.first);

            gltfAnim.samplers.Append(motionRotData.second);
            gltfAnim.samplers.Append(motionTranData.second);
            gltfAnim.samplers.Append(motionScaleData.second);
        }

        CopyToGltfProperty(animItem, *m_gltfDocument, gltfAnim);

        m_gltfDocument->animations.Append(std::move(gltfAnim));
    }
}

void Asset3DToGLTFConverter::AddGLTFChannelAnimations(glTF::BufferBuilder& bufferBuilder)
{
    auto gltfChannelAnimations = m_asset3d.GetChannelAnimations();
    for (size_t animationIndex = 0; animationIndex < gltfChannelAnimations->GetAnimationCount(); animationIndex++)
    {
        auto gltfAnimation = gltfChannelAnimations->ExportAnimationData(animationIndex, bufferBuilder);
        m_gltfDocument->animations.Append(std::move(gltfAnimation));
    }

    auto gltfSkins = m_asset3d.GetSkins();
    for (size_t skinIndex = 0; skinIndex < gltfSkins->GetSkinCount(); skinIndex++)
    {
        auto gltfSkin = gltfSkins->ExportSkinData(skinIndex, bufferBuilder);
        m_gltfDocument->skins.Append(std::move(gltfSkin));
    }
}

void Asset3DToGLTFConverter::AddMaterials(IGLTFWriter& writer, const std::unordered_map<uint32_t, MaterialDescriptor*>& materials)
{
    for (auto& materialPair : materials)
    {
        auto& material = materialPair.second;
        material->ConvertFromLegacy();

        auto gltfMaterialFull = AddMaterial(writer, material, 1);

        // Add LODs if necessary
        switch(m_options.TranscodingMode)
        {
        case TranscodingMode::SgLods:
        case TranscodingMode::MrSgLods:
        {
            auto gltfMaterialHalf  = AddMaterial(writer, material, 2);
            auto gltfMaterialQuart = AddMaterial(writer, material, 4);

            auto lodExt = std::make_unique<MSFT_lod>();
            lodExt->ids.push_back(gltfMaterialHalf.id);
            lodExt->ids.push_back(gltfMaterialQuart.id);

            gltfMaterialFull.SetExtension(std::move(lodExt));

            m_gltfDocument->materials.Append(std::move(gltfMaterialHalf));
            m_gltfDocument->materials.Append(std::move(gltfMaterialQuart));
            m_gltfDocument->extensionsUsed.insert(MSFT_LOD);
            break;
        }

        default:
            break;
        }

        m_gltfDocument->materials.Append(std::move(gltfMaterialFull));
    }
}

std::pair<glTF::AnimationChannel, glTF::AnimationSampler> Asset3DToGLTFConverter::CreateChannelAndSampler(
    glTF::BufferBuilder& bufferBuilder,
    const std::string& nodeId,
    size_t skeletonCount,
    glTF::TargetPath path,
    const std::vector<float>& keyframeTimes,
    const std::vector<float>& keyframeValues,
    glTF::AccessorType accessorType) const
{
    const std::string idSuffix = nodeId + std::to_string(skeletonCount) + "_" + std::to_string(path) + "_";

    glTF::AnimationTarget target;
    target.nodeId = nodeId;
    target.path = path;

    glTF::AnimationSampler sampler;
    sampler.id = "ANIMATION_SAMPLER_" + idSuffix;
    sampler.interpolation = glTF::INTERPOLATION_LINEAR;

    glTF::AnimationChannel channel;
    channel.id = "ANIMATION_CHANNEL_" + idSuffix;
    channel.samplerId = sampler.id;
    channel.target = target;

    const float minKeyframe = keyframeTimes[0];
    const float maxKeyframe = keyframeTimes[keyframeTimes.size() - 1];

    bufferBuilder.AddBufferView();// Don't specify a BufferViewTarget value as this BufferView doesn't store vertex attribute data
    const glTF::Accessor& inputAccessor = bufferBuilder.AddAccessor(keyframeTimes, { glTF::TYPE_SCALAR, glTF::COMPONENT_FLOAT, false, { minKeyframe }, { maxKeyframe } });
    sampler.inputAccessorId = inputAccessor.id;

    bufferBuilder.AddBufferView();// Don't specify a BufferViewTarget value as this BufferView doesn't store vertex attribute data
    const glTF::Accessor& outputAccessor = bufferBuilder.AddAccessor(keyframeValues, { accessorType, glTF::COMPONENT_FLOAT });
    sampler.outputAccessorId = outputAccessor.id;

    return std::make_pair<glTF::AnimationChannel, glTF::AnimationSampler>(std::move(channel), std::move(sampler));
}

void Asset3DToGLTFConverter::PopulateDocument(IGLTFWriter& writer)
{
    std::unordered_map<uint32_t, MaterialDescriptor*> materials;
    std::unordered_map<std::string, glTF::Node> nodes;

    CopyToGltfProperty(m_asset3d, *m_gltfDocument, *m_gltfDocument.get(), Babylon::Utils::glTF::kExtensionsRootGltfKey);

    glTF::Scene gltfScene;
    gltfScene.id = m_asset3d.GetIdString();

    CopyToGltfProperty(m_asset3d, *m_gltfDocument, gltfScene, Babylon::Utils::glTF::kExtensionsDefaultSceneKey);

    ISceneNodeUtils::DFS(&m_asset3d,
        [&](const SceneNode* sceneNode, const SceneNode* parentNode)
    {
        glTF::Node gltfNode;
        gltfNode.id = sceneNode->GetIdString();
        gltfNode.name = sceneNode->GetName();
        gltfNode.weights = sceneNode->GetMorphWeights();

        if (parentNode == nullptr) // SceneNode = glTF::Node (root)
        {
            SetGltfTRS(gltfNode, m_asset3d.GetUnitScaledTransform(Asset3D::SYSTEMUNIT_METER));
            gltfScene.nodes.push_back(gltfNode.id);
        }
        else // SceneNode = glTF::Node (non-root)
        {
            SetGltfTRS(gltfNode, sceneNode->GetTransform());
            nodes[parentNode->GetIdString()].children.push_back(gltfNode.id);
        }

        CopyToGltfProperty(*sceneNode, *m_gltfDocument, gltfNode);

        if (sceneNode->GetCamera())
        {
            auto a3dCamera = sceneNode->GetCamera().get();
            auto camera = ToGLTFCamera(*a3dCamera);
            CopyToGltfProperty(*a3dCamera, *m_gltfDocument, camera);
            m_gltfDocument->cameras.Append(std::move(camera));
            gltfNode.cameraId = camera.id;
        }

        if (sceneNode->HasMesh())
        {
            Mesh& mesh = *sceneNode->GetMesh().get();

            gltfNode.meshId = mesh.GetIdString();

            if (!m_gltfDocument->meshes.Has(gltfNode.meshId))
            {
                glTF::Mesh gltfMesh;
                gltfMesh.id = mesh.GetIdString();
                gltfMesh.name = mesh.GetName();
                gltfMesh.weights = mesh.GetMorphWeights();

                CopyToGltfProperty(mesh, *m_gltfDocument, gltfMesh);

                for (const auto& geometry : mesh.GetGeometries())
                {
                    AddPrimitiveToMesh(writer.GetBufferBuilder(), gltfMesh, geometry, materials);
                }

                m_gltfDocument->meshes.Append(std::move(gltfMesh));
            }

            // TODO: Should this just be nested under HasMesh? Should we throw if there is a skeleton without a Mesh?
            if (sceneNode->HasSkeleton())
            {
                gltfNode.skinId = std::to_string(sceneNode->GetSkeletonID());
            }
        }

        nodes.emplace(gltfNode.id, gltfNode);

        return true;
    });

    for(auto node : nodes)
    {
        m_gltfDocument->nodes.Append(std::move(node.second));
    }

    m_gltfDocument->SetDefaultScene(std::move(gltfScene));

    // Animation export
    if (!m_asset3d.HasChannelAnimations())
    {
        // Use legacy animation exporter -- for animations loaded from the FBX skeletal animation importer
        AddAnimationsAndSkeletons(writer.GetBufferBuilder());
    }
    else
    {
        // Use the new channel animations-based animation exporter
        AddGLTFChannelAnimations(writer.GetBufferBuilder());
    }

    // Should be done after Meshes and Animations since it avoids needing to pad the buffer to keep it 4-byte aligned
    AddMaterials(writer, materials);
}

void Asset3DToGLTFConverter::AddPrimitiveToMesh(glTF::BufferBuilder& bufferBuilder, glTF::Mesh& gltfMesh, const Geometry& geometry, std::unordered_map<uint32_t, MaterialDescriptor*>& materials)
{
    glTF::MeshPrimitive primitive = CreateMeshPrimitive(bufferBuilder, geometry);

    // TODO: Support nullptr material by not writing out any material
    std::shared_ptr<MaterialDescriptor> material = geometry.GetMaterial();
    if (material) {
        materials[material->GetId()] = material.get();
        primitive.materialId = material.get()->GetIdString();
    }
    CopyToGltfProperty(geometry, *m_gltfDocument, primitive);

    gltfMesh.primitives.push_back(std::move(primitive));
}

TextureCompressionType Asset3DToGLTFConverter::GetCompliantTextureCompressionType(TextureChannels channels)
{
    if (m_minecraftAsset) return TextureCompressionType::PNG;

    switch (m_options.TextureCompression)
    {
    case ExportTextureMode::PNG:
        return TextureCompressionType::PNG;

    case ExportTextureMode::PNG256:
        return TextureCompressionType::PNG256;

    case ExportTextureMode::JPEGPNG:
        return (channels == TextureChannels::k3Channel) ? TextureCompressionType::JPEG : TextureCompressionType::PNG;

    case ExportTextureMode::JPEGPNG256:
        return (channels == TextureChannels::k3Channel) ? TextureCompressionType::JPEG : TextureCompressionType::PNG256;

    default:
        throw Babylon::Utils::BabylonException("Unrecognized ExportTextureMode");
    }
}

TextureCompressionType Asset3DToGLTFConverter::GetDDSTextureCompressionType(TextureChannels channels)
{
    switch (channels)
    {
    case TextureChannels::k2Or3Channel:
        return TextureCompressionType::BC5;
    case TextureChannels::k3Channel:
    case TextureChannels::k4Channel:
        return TextureCompressionType::BC7;
    default:
        throw Babylon::Utils::BabylonException("Unrecognized TextureChannels");
    }
}

void Asset3DToGLTFConverter::SetTextureInfo(const std::shared_ptr<MaterialDescriptor::LayerInfo>& layer, glTF::TextureInfo& textureInfo, IGLTFWriter& writer, const uint8_t scale, TextureChannels channels, bool compliantImage, bool ddsImage)
{
    if (layer->Texture)
    {
        const std::string& samplerId = AddSampler(layer->Sampler);
        textureInfo.textureId = AddTexture(writer, layer->Texture.get(), scale, samplerId, channels, compliantImage, ddsImage);
        textureInfo.texCoord = layer->UVSetIndex;

        if (layer->TextureTransform != Babylon::Utils::Math::Matrix::Identity)
        {
            bool hasTextureTransform = Babylon::Utils::glTF::TryGetTextureTransform(layer->TextureTransform, textureInfo);
            if (hasTextureTransform)
            {
                // Register extension
                m_gltfDocument->extensionsUsed.insert(glTF::KHR::TextureInfos::TEXTURETRANSFORM_NAME);
            }
        }
    }
}

void Asset3DToGLTFConverter::SetMaterialTextureTransform(const std::shared_ptr<MaterialDescriptor::LayerInfo>& layer, Microsoft::glTF::TextureInfo& textureInfo)
{
    if (layer && layer->TextureTransform != Babylon::Utils::Math::Matrix::Identity)
    {
        bool hasTextureTransform = Babylon::Utils::glTF::TryGetTextureTransform(layer->TextureTransform, textureInfo);
        if (hasTextureTransform)
        {
            // Register extension
            m_gltfDocument->extensionsUsed.insert(glTF::KHR::TextureInfos::TEXTURETRANSFORM_NAME);
        }
    }
}

glTF::Material Asset3DToGLTFConverter::AddMaterial(IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale)
{
    glTF::Material material;
    material.id = materialDesc->GetIdString();
    if (scale != 1)
    {
        material.id += "_" + std::to_string(scale);
    }

    material.name = materialDesc->GetName();

    material.alphaMode = ToGLTFAlphaMode(materialDesc->GetRenderingMode());
    material.alphaCutoff = materialDesc->GetAlphaCutoff();
    material.doubleSided = !materialDesc->HasRenderingOption(RenderingOption::SingleSided);

    switch (m_options.TranscodingMode)
    {
    case TranscodingMode::Passthrough:
    {
        bool mr = ApplyMaterialMR(material, writer,
            materialDesc->GetLayer(LayerType::kBaseColor), materialDesc->GetLayer(LayerType::kMetallicRoughness), scale);
        bool sg = ApplyMaterialSG(material, writer,
            materialDesc->GetLayer(LayerType::kDiffuse), materialDesc->GetLayer(LayerType::kSpecularGlossiness), scale);

        if (sg)
        {
            // SG provided, therefore KHR_materials_pbrSpecularGlossiness goes in extensionsUsed
            m_gltfDocument->extensionsUsed.insert(glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME);

            if (!mr)
            {
                // MR not provided, therefore KHR_materials_pbrSpecularGlossiness goes in extensionsRequired
                m_gltfDocument->extensionsRequired.insert(glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME);
            }
        }
        break;
    }

    case TranscodingMode::MrOnly:
        ApplyOrGenerateMaterialMR(material, writer, materialDesc, scale);
        break;

    case TranscodingMode::SgOnly:
    case TranscodingMode::SgLods:
        ApplyOrGenerateMaterialSG(material, writer, materialDesc, scale);

        // Only SG provided, therefore KHR_materials_pbrSpecularGlossiness goes in extensionsUsed & extensionsRequired
        m_gltfDocument->extensionsUsed.insert(glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME);
        m_gltfDocument->extensionsRequired.insert(glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME);
        break;

    case TranscodingMode::MrSg:
    case TranscodingMode::MrSgLods:
        ApplyOrGenerateMaterialMR(material, writer, materialDesc, scale);
        ApplyOrGenerateMaterialSG(material, writer, materialDesc, scale);

        // Both MR & SG provided, therefore KHR_materials_pbrSpecularGlossiness goes in extensionsUsed
        m_gltfDocument->extensionsUsed.insert(glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME);
        break;

    case TranscodingMode::MsftPackingNrm:
        ApplyMsftPackingNrm(material, writer, materialDesc);
        break;

    default:
        throw Babylon::Utils::BabylonException("Unrecognized TranscodingMode");
    }

    switch (m_options.TranscodingMode)
    {
    case TranscodingMode::Passthrough:
    case TranscodingMode::MrOnly:
    case TranscodingMode::SgOnly:
    case TranscodingMode::SgLods:
    case TranscodingMode::MrSg:
    case TranscodingMode::MrSgLods:
        ApplyCommonMaterialLayers(material, writer, materialDesc, scale);
        break;

    // Other modes do not use all material layers
    case TranscodingMode::MsftPackingNrm:
        break;

    default:
        throw Babylon::Utils::BabylonException("Unrecognized TranscodingMode");
    }

    // Unlit extension
    if (materialDesc->HasRenderingOption(RenderingOption::Unlit))
    {
        m_gltfDocument->extensionsUsed.insert(glTF::KHR::Materials::UNLIT_NAME);
        material.SetExtension<Microsoft::glTF::KHR::Materials::Unlit>();
    }

    CopyToGltfProperty(*materialDesc, *m_gltfDocument, material);

    return material;
}

void Asset3DToGLTFConverter::ApplyOrGenerateMaterialMR(glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale)
{
    auto mrLayers = materialDesc->GetOrGenerateMetalRough();
    ApplyMaterialMR(material, writer, mrLayers.Albedo, mrLayers.Workflow, scale);
}

bool Asset3DToGLTFConverter::ApplyMaterialMR(glTF::Material& material, IGLTFWriter& writer,
    const std::shared_ptr<MaterialLayer>& baseColorLayer,
    const std::shared_ptr<MaterialLayer>& metalRoughLayer,
    const uint8_t scale)
{
    if (!baseColorLayer && !metalRoughLayer)
    {
        return false;
    }

    if (baseColorLayer)
    {
        auto channels = (material.alphaMode == glTF::AlphaMode::ALPHA_OPAQUE) ? TextureChannels::k3Channel : TextureChannels::k4Channel;
        SetTextureInfo(baseColorLayer, material.metallicRoughness.baseColorTexture, writer, scale, channels);
        if (baseColorLayer->Color)
        {
            material.metallicRoughness.baseColorFactor = ToGLTFColor4(*baseColorLayer->Color);
        }
    }

    if (metalRoughLayer)
    {
        SetTextureInfo(metalRoughLayer, material.metallicRoughness.metallicRoughnessTexture, writer, scale, TextureChannels::k3Channel);
        if (metalRoughLayer->Color)
        {
            material.metallicRoughness.metallicFactor  = metalRoughLayer->Color->B();
            material.metallicRoughness.roughnessFactor = metalRoughLayer->Color->G();
        }
    }
    return true;
}

void Asset3DToGLTFConverter::ApplyOrGenerateMaterialSG(glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale)
{
    auto sgLayers = materialDesc->GetOrGenerateSpecGloss();
    ApplyMaterialSG(material, writer, sgLayers.Albedo, sgLayers.Workflow, scale);
}

bool Asset3DToGLTFConverter::ApplyMaterialSG(glTF::Material& material, IGLTFWriter& writer,
    const std::shared_ptr<MaterialLayer>& diffuseLayer,
    const std::shared_ptr<MaterialLayer>& specGlossLayer,
    const uint8_t scale)
{
    if (!diffuseLayer && !specGlossLayer)
    {
        return false;
    }

    auto sgExtension = std::make_unique<glTF::KHR::Materials::PBRSpecularGlossiness>();

    if (diffuseLayer)
    {
        auto channels = (material.alphaMode == glTF::AlphaMode::ALPHA_OPAQUE) ? TextureChannels::k3Channel : TextureChannels::k4Channel;
        SetTextureInfo(diffuseLayer, sgExtension->diffuseTexture, writer, scale, channels);
        if (diffuseLayer->Color)
        {
            sgExtension->diffuseFactor = ToGLTFColor4(*diffuseLayer->Color);
        }
    }

    if (specGlossLayer)
    {
        SetTextureInfo(specGlossLayer, sgExtension->specularGlossinessTexture, writer, scale, TextureChannels::k4Channel);
        if (specGlossLayer->Color)
        {
            sgExtension->specularFactor = ToGLTFColor3(*specGlossLayer->Color);
            sgExtension->glossinessFactor = specGlossLayer->Color->A();
        }
    }

    /// FIX - Material with Diffuse only are exported without specular factor, which lead to texture NOT rendered. 
    if (!specGlossLayer || specGlossLayer->Color) {
        float v = 0;
        sgExtension->specularFactor = glTF::Color3(v,v,v);
    }

    material.SetExtension(std::move(sgExtension));
    return true;
}

void Asset3DToGLTFConverter::ApplyCommonMaterialLayers(glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc, const uint8_t scale)
{
    // Normal
    auto normalLayer = materialDesc->GetLayer(LayerType::kNormal);
    if (normalLayer)
    {
        SetTextureInfo(normalLayer, material.normalTexture, writer, scale, TextureChannels::k3Channel);
        material.normalTexture.scale = normalLayer->Coefficient;
    }

    // Occlusion
    auto occlusionLayer = materialDesc->GetLayer(LayerType::kOcclusion);
    if (occlusionLayer)
    {
        SetTextureInfo(occlusionLayer, material.occlusionTexture, writer, scale, TextureChannels::k3Channel);
        material.occlusionTexture.strength = occlusionLayer->Coefficient;
    }

    // Emissive
    auto emissiveLayer = materialDesc->GetLayer(LayerType::kEmissive);
    if (emissiveLayer)
    {
        if (emissiveLayer->Color)
        {
            material.emissiveFactor = ToGLTFColor3(*emissiveLayer->Color);
        }
        SetTextureInfo(emissiveLayer, material.emissiveTexture, writer, scale, TextureChannels::k3Channel);
    }
}

void Asset3DToGLTFConverter::ApplyMsftPackingNrm(glTF::Material& material, IGLTFWriter& writer, MaterialDescriptor* materialDesc)
{
    auto mrLayers = materialDesc->GetOrGenerateMetalRough();

    auto& baseColorLayer  = mrLayers.Albedo;
    auto& metalRoughLayer = mrLayers.Workflow;
    auto  normal          = materialDesc->GetLayer(LayerType::kNormal);

    if (baseColorLayer)
    {
        if (baseColorLayer->Color)
        {
            material.metallicRoughness.baseColorFactor = ToGLTFColor4(*baseColorLayer->Color);
        }

        // STANDARD + BC7 -> material.metallicRoughness.baseColorTexture
        auto channels = (material.alphaMode == glTF::AlphaMode::ALPHA_OPAQUE) ? TextureChannels::k3Channel : TextureChannels::k4Channel;
        SetTextureInfo(baseColorLayer, material.metallicRoughness.baseColorTexture, writer, 1, channels, true, true);
    }

    if (metalRoughLayer)
    {
        if (metalRoughLayer->Color)
        {
            material.metallicRoughness.metallicFactor  = metalRoughLayer->Color->B();
            material.metallicRoughness.roughnessFactor = metalRoughLayer->Color->G();
        }

        // STANDARD -> material.metallicRoughness.metallicRoughnessTexture
        SetTextureInfo(metalRoughLayer, material.metallicRoughness.metallicRoughnessTexture, writer, 1, TextureChannels::k3Channel);
    }

    auto normalLayer = materialDesc->GetLayer(LayerType::kNormal);
    if (normalLayer)
    {
        // STANDARD -> material.normalTexture
        SetTextureInfo(normalLayer, material.normalTexture, writer, 1, TextureChannels::k3Channel);
        material.normalTexture.scale = normalLayer->Coefficient;
    }

    auto normalRoughnessMetallic = TexturePackingUtils::PackNormalRoughnessMetallic(normalLayer, metalRoughLayer);
    if (normalRoughnessMetallic)
    {
        auto packingNRM = std::make_unique<MSFT_packing_normalRoughnessMetallic>();
        // BC7 -> material.MSFT_packing_normalRoughnessMetallicTexture.normalRoughnessMetallicTexture
        SetTextureInfo(normalRoughnessMetallic, packingNRM->normalRoughnessMetallicTexture, writer, 1, TextureChannels::k4Channel, false, true);

        material.SetExtension(std::move(packingNRM));
        m_gltfDocument->extensionsUsed.insert(MSFT_PACKING_NORMALROUGHNESSMETALLIC);
    }
}

std::string Asset3DToGLTFConverter::AddSampler(const MaterialLayer::TextureSampler& sampler)
{
    glTF::Sampler gltfSampler;

    if (sampler.filter)
    {
        using EFilterMode = Babylon::Framework::SamplerDefinition::EFilterMode;

        switch (*sampler.filter)
        {
        case EFilterMode::kMinPoint_MagPoint_MipPoint:
        case EFilterMode::kMinPoint_MagPoint_MipLinear:
        case EFilterMode::kMinLinear_MagPoint_MipPoint:
        case EFilterMode::kMinLinear_MagPoint_MipLinear:
            gltfSampler.magFilter = glTF::MagFilter_NEAREST;
            break;
        case EFilterMode::kMinPoint_MagLinear_MipPoint:
        case EFilterMode::kMinPoint_MagLinear_MipLinear:
        case EFilterMode::kMinLinear_MagLinear_MipPoint:
        case EFilterMode::kMinLinear_MagLinear_MipLinear:
            gltfSampler.magFilter = glTF::MagFilter_LINEAR;
            break;
        }

        // Note that Babylon and D3D11 don't have the notion of a sampler
        // that doesn't do mipmapping. While handling GLTF we read, but do
        // not write, the NEAREST and LINEAR filter settings, which is
        // why they do not appear below.
        // (During deserialization NEAREST and LINEAR are promoted to the
        // equivalent of NEAREST_MIPMAP_NEAREST and LINEAR_MIPMAP_NEAREST)

        switch (*sampler.filter)
        {
        case EFilterMode::kMinPoint_MagPoint_MipPoint:
        case EFilterMode::kMinPoint_MagLinear_MipPoint:
            gltfSampler.minFilter = glTF::MinFilter_NEAREST_MIPMAP_NEAREST;
            break;
        case EFilterMode::kMinLinear_MagPoint_MipPoint:
        case EFilterMode::kMinLinear_MagLinear_MipPoint:
            gltfSampler.minFilter = glTF::MinFilter_LINEAR_MIPMAP_NEAREST;
            break;
        case EFilterMode::kMinPoint_MagPoint_MipLinear:
        case EFilterMode::kMinPoint_MagLinear_MipLinear:
            gltfSampler.minFilter = glTF::MinFilter_NEAREST_MIPMAP_LINEAR;
            break;
        case EFilterMode::kMinLinear_MagPoint_MipLinear:
        case EFilterMode::kMinLinear_MagLinear_MipLinear:
            gltfSampler.minFilter = glTF::MinFilter_LINEAR_MIPMAP_LINEAR;
            break;
        }
    }

    using EAddressMode = Babylon::Framework::SamplerDefinition::EAddressMode;

    auto convertWrap = [](EAddressMode asset3DWrapIn, glTF::WrapMode& gltfWrapOut)
    {
        switch (asset3DWrapIn)
        {
            case EAddressMode::kClamp:
                gltfWrapOut = glTF::Wrap_CLAMP_TO_EDGE;
                break;
            case EAddressMode::kWrap:
                gltfWrapOut = glTF::Wrap_REPEAT;
                break;
            case EAddressMode::kMirroredWrap:
                gltfWrapOut = glTF::Wrap_MIRRORED_REPEAT;
                break;
        }
    };

    convertWrap(sampler.wrapU, gltfSampler.wrapS);
    convertWrap(sampler.wrapV, gltfSampler.wrapT);

    auto SamplerExists = [&gltfSampler](const glTF::Sampler& existingSampler)
    {
        return gltfSampler.minFilter == existingSampler.minFilter &&
            gltfSampler.magFilter == existingSampler.magFilter &&
            gltfSampler.wrapS == existingSampler.wrapS &&
            gltfSampler.wrapT == existingSampler.wrapT;
    };

    auto it = std::find_if(m_samplers.begin(), m_samplers.end(), SamplerExists);
    if (it == m_samplers.end())
    {
        auto samplerId = std::to_string(m_samplers.size());
        gltfSampler.id = samplerId;
        m_samplers.push_back(gltfSampler);
        m_gltfDocument->samplers.Append(std::move(gltfSampler));
        return samplerId;
    }
    return it->id;
}

std::string Asset3DToGLTFConverter::AddTexture(IGLTFWriter& writer, const TextureDescriptor* textureDesc, const uint8_t scale, const std::string& samplerId, TextureChannels channels, bool compliantImage, bool ddsImage)
{
    BabylonAssert(compliantImage || ddsImage);

    // TODO: This will result in awkward resizing where the input dimensions are not divisible by scale or where the input image is too small
    const int width = std::max(1, static_cast<int>(textureDesc->GetWidthInPixels() / scale));
    const int height = std::max(1, static_cast<int>(textureDesc->GetHeightInPixels() / scale));

    auto id    = textureDesc->GetIdString() + "_" + std::to_string(width) + "x" + std::to_string(height);
    auto ddsId = id + "_dds";

    auto textureId = compliantImage ? id : ddsId;

    if (m_textures.find(textureId) != m_textures.end())
    {
        return textureId;
    }

    glTF::Texture texture;
    texture.id = textureId;
    texture.name = textureDesc->GetName();
    texture.samplerId = samplerId;
    CopyToGltfProperty(*textureDesc, *m_gltfDocument, texture);

    if (compliantImage)
    {
        auto type = GetCompliantTextureCompressionType(channels);
        switch (type)
        {
        case TextureCompressionType::PNG:
            writer.WriteImage(*m_gltfDocument, textureDesc->EncodeToPNG(width, height), id, glTF::MIMETYPE_PNG, glTF::FILE_EXT_PNG);
            break;
        case TextureCompressionType::PNG256:
            writer.WriteImage(*m_gltfDocument, textureDesc->EncodeToPNG256(width, height), id, glTF::MIMETYPE_PNG, glTF::FILE_EXT_PNG);
            break;
        case TextureCompressionType::JPEG:
            writer.WriteImage(*m_gltfDocument, textureDesc->EncodeToJPEG(width, height), id, glTF::MIMETYPE_JPEG, glTF::FILE_EXT_JPEG);
            break;
        default:
            throw Babylon::Utils::BabylonException("Unsupported CompressionType");
        }

        texture.imageId = id;
    }

    if (ddsImage)
    {
        auto type = GetDDSTextureCompressionType(channels);
        switch (type)
        {
        case TextureCompressionType::BC5:
            writer.WriteImage(*m_gltfDocument, textureDesc->EncodeToDDSBC5(width, height), ddsId, MIMETYPE_DDS, FILE_EXT_DDS);
            break;
        case TextureCompressionType::BC7:
            writer.WriteImage(*m_gltfDocument, textureDesc->EncodeToDDSBC7(width, height), ddsId, MIMETYPE_DDS, FILE_EXT_DDS);
            break;
        default:
            throw Babylon::Utils::BabylonException("Unsupported CompressionType");
        }

        texture.SetExtension(std::make_unique<MSFT_texture_dds>(ddsId));
        m_gltfDocument->extensionsUsed.insert(MSFT_TEXTURE_DDS);
    }

    m_gltfDocument->textures.Append(std::move(texture));

    m_textures.emplace(textureId);

    return textureId;
}
