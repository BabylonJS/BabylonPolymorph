/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>
#include <string>
#include <vector>

#include <GLTFSDK/Document.h>
#include <GLTFSDK/GLTF.h>
#include <GLTFSDK/GLTFResourceReader.h>

namespace Microsoft
{
    namespace glTF
    {
        class BufferBuilder;
    }
}

class GLTFSkins
{
public:
    size_t GetSkinCount() const { return m_skins.size(); }
    const std::vector<std::string>& GetSkinJoints(size_t skinIndex) const { return m_skins.at(skinIndex).skin.jointIds; }

    void LoadSkinData(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::GLTFResourceReader& reader);
    Microsoft::glTF::Skin ExportSkinData(size_t skinIndex, Microsoft::glTF::BufferBuilder& bufferBuilder) const;

    // Returns skin.skeletonId if set, or lowest common ancestor of skin.jointIds
    std::string GetSkinRoot(size_t skinIndex) const { return m_skins.at(skinIndex).skinRootId; }

    Microsoft::glTF::Matrix4 GetSkinIBM(size_t skinIndex, size_t jointIndex) const { return m_skins.at(skinIndex).inverseBindMatrices.at(jointIndex); }

    const std::vector<Microsoft::glTF::Matrix4>& GetJointMatrices(size_t skinIndex) const { return m_skinningOutput.at(skinIndex).jointMatrices; }

    void SetJointMatrix(size_t skinIndex, size_t jointIndex, const Microsoft::glTF::Matrix4& jointMatrix)
    {
        m_skinningOutput.at(skinIndex).jointMatrices.at(jointIndex) = jointMatrix;
    }

    void RetargetNodeIds(const std::map<std::string /*oldNodeId*/, std::string /*newNodeId*/>& oldNodeToNewNodeIdMap);

    bool GetSkinNodeBasePose(
        const std::string& nodeId,
        Microsoft::glTF::Vector3& translation,
        Microsoft::glTF::Quaternion& rotation,
        Microsoft::glTF::Vector3& scale,
        std::vector<float>& weights) const;

protected:
    std::string FindSkinRootId(const Microsoft::glTF::Skin& skin, const Microsoft::glTF::Scene& scene, const Microsoft::glTF::IndexedContainer<const Microsoft::glTF::Node>& nodes) const;

    struct SkinData
    {
        std::vector<Microsoft::glTF::Matrix4> inverseBindMatrices;
        Microsoft::glTF::Skin skin;
        std::string skinRootId;
    };

    struct SkinningOutput
    {
        std::vector<Microsoft::glTF::Matrix4> jointMatrices;
    };

    std::map<size_t /*skinIndex*/, SkinData> m_skins;

    std::map<size_t /*skinIndex*/, SkinningOutput> m_skinningOutput;

    struct NodeBasePose
    {
        Microsoft::glTF::Vector3 translation;
        Microsoft::glTF::Quaternion rotation;
        Microsoft::glTF::Vector3 scale;
        std::vector<float> weights;
    };

    std::map<std::string /*nodeId*/, NodeBasePose> m_skinTargetNodeBasePoses;
};
