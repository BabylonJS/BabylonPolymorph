/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/Assert.h>
#include <CoreUtils/GLTFSkins.h>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/Trace.h>

#include <GLTFSDK/AnimationUtils.h>
#include <GLTFSDK/BufferBuilder.h>
#include <GLTFSDK/Document.h>
#include <GLTFSDK/GLTFResourceReader.h>

#include <limits>

DEFINE_TRACE_AREA(GLTFSkins, 0);

void GLTFSkins::LoadSkinData(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::GLTFResourceReader& reader)
{
    if (!m_skins.empty())
    {
        throw Spectre::Utils::SpectreException("GLTFSkins::LoadSkinData() -- skins have already been loaded");
    }

    for (auto& skin : gltfDocument.skins.Elements())
    {
        std::vector<Microsoft::glTF::Matrix4> inverseBindMatrices;

        if (!skin.inverseBindMatricesAccessorId.empty())
        {
            std::vector<float> inverseBindMatricesData = Microsoft::glTF::AnimationUtils::GetInverseBindMatrices(gltfDocument, reader, skin);
            if (inverseBindMatricesData.size() % 16 != 0)
            {
                throw Spectre::Utils::SpectreException("GLTFSkins::LoadSkinData() -- invalid size for inverse bind matrix data");
            }

            size_t numIbms = inverseBindMatricesData.size() / 16;
            SpectreAssert(sizeof(Microsoft::glTF::Matrix4) == sizeof(float) * 16);
            for (size_t i = 0; i < numIbms; i++)
            {
                Microsoft::glTF::Matrix4 ibm;
                std::memcpy(ibm.values.data(), inverseBindMatricesData.data() + i * 16, sizeof(float) * 16);
                inverseBindMatrices.push_back(ibm);
            }
        }
        else
        {
            // No IBMs - fill with default data
            inverseBindMatrices.resize(skin.jointIds.size());
        }

        std::string skinRootId;

        if (!skin.skeletonId.empty())
        {
            auto& node = gltfDocument.nodes.Get(skin.skeletonId);
            m_skinTargetNodeBasePoses.insert({ skin.skeletonId, { node.translation, node.rotation, node.scale } });
            skinRootId = skin.skeletonId;
        }
        else
        {
            // SkeletonId not specified - find LCA of skin joint nodes
            skinRootId = FindSkinRootId(skin, gltfDocument.GetDefaultScene(), gltfDocument.nodes);
        }

        std::for_each(skin.jointIds.begin(), skin.jointIds.end(), [this, gltfDocument](const std::string& jointId)
        {
            auto& node = gltfDocument.nodes.Get(jointId);
            m_skinTargetNodeBasePoses.insert({ jointId, { node.translation, node.rotation, node.scale } });
        });

        size_t skinIndex = gltfDocument.skins.GetIndex(skin.id);
        m_skins.emplace(skinIndex, SkinData{ std::move(inverseBindMatrices), skin, std::move(skinRootId) });

        std::vector<Microsoft::glTF::Matrix4> defaultJointMatrices(skin.jointIds.size());
        SkinningOutput skinningOutput;
        skinningOutput.jointMatrices = std::move(defaultJointMatrices);
        m_skinningOutput.emplace(skinIndex, std::move(skinningOutput));
    }
}

void GLTFSkins::RetargetNodeIds(const std::map<std::string /*oldNodeId*/, std::string/*newNodeId*/>& oldNodeToNewNodeIdMap)
{
    if (oldNodeToNewNodeIdMap.empty())
    {
        return;
    }

    // Update all skeleton joint node ids
    for (auto& skin : m_skins)
    {
        for (auto& jointNodeId : skin.second.skin.jointIds)
        {
            auto newNodeIdIt = oldNodeToNewNodeIdMap.find(jointNodeId);
            if (newNodeIdIt != oldNodeToNewNodeIdMap.end())
            {
                jointNodeId = newNodeIdIt->second;
            }
            else
            {
                throw Spectre::Utils::SpectreInvalidArgException("GLTFSkins::RetargetNodeIds() -- skin joint node does not have a remapping entry");
            }
        }

        // Update skeleton root node id if present
        if (!skin.second.skin.skeletonId.empty())
        {
            auto newNodeIdIt = oldNodeToNewNodeIdMap.find(skin.second.skin.skeletonId);
            if (newNodeIdIt != oldNodeToNewNodeIdMap.end())
            {
                skin.second.skin.skeletonId = newNodeIdIt->second;
            }
            else
            {
                throw Spectre::Utils::SpectreInvalidArgException("GLTFSkins::RetargetNodeIds() -- skin skeletonId node does not have a remapping entry");
            }
        }
    }
}

Microsoft::glTF::Skin GLTFSkins::ExportSkinData(size_t skinIndex, Microsoft::glTF::BufferBuilder& bufferBuilder) const
{
    auto skinData = m_skins.at(skinIndex);
    
    if (!skinData.skin.inverseBindMatricesAccessorId.empty())
    {
        // InverseBindMatrices
        bufferBuilder.AddBufferView();// Don't specify a BufferViewTarget value as this BufferView doesn't store vertex attribute data

        // Pass inverse bind matrices as float vector
        const float* inverseBindMatrixData = skinData.inverseBindMatrices.front().values.data();

        std::string accessorId = bufferBuilder.AddAccessor(inverseBindMatrixData, skinData.inverseBindMatrices.size(), {
            Microsoft::glTF::AccessorType::TYPE_MAT4,
            Microsoft::glTF::ComponentType::COMPONENT_FLOAT }).id;

        skinData.skin.inverseBindMatricesAccessorId = std::move(accessorId);
    }

    return skinData.skin;
}

bool GLTFSkins::GetSkinNodeBasePose(
    const std::string& nodeId,
    Microsoft::glTF::Vector3& translation,
    Microsoft::glTF::Quaternion& rotation,
    Microsoft::glTF::Vector3& scale,
    std::vector<float>& weights) const
{
    auto skinTargetNodeBasePoseIt = m_skinTargetNodeBasePoses.find(nodeId);
    if (skinTargetNodeBasePoseIt != m_skinTargetNodeBasePoses.end())
    {
        auto& basePose = skinTargetNodeBasePoseIt->second;
        translation = basePose.translation;
        rotation = basePose.rotation;
        scale = basePose.scale;
        weights = basePose.weights;
        return true;
    }
    return false;
}

namespace
{
    // A JointPath is a sequential list of GLTF SDK node IDs representing a tree traversal from
    // the scene root (JointPath.front()) to the joint target node (JointPath.back())
    typedef std::vector<std::string> JointPath;

    // Find path from nodeId to targetNode
    bool FindPath(const std::string& nodeId, const Microsoft::glTF::Node& targetNode, const Microsoft::glTF::IndexedContainer<const Microsoft::glTF::Node>& nodes, JointPath& path)
    {
        if (nodeId == targetNode.id)
        {
            return true;
        }

        bool found = false;
        for (auto& childId : nodes.Get(nodeId).children)
        {
            auto& childNode = nodes.Get(childId);
            path.push_back(childId);
            if (FindPath(childNode.id, targetNode, nodes, path))
            {
                found = true;
                break;
            }
            else
            {
                path.pop_back();
            }
        }

        return found;
    }
}

// Brute-force/naive lowest common ancestor (LCA) implementation
//
// (See slide 13 here: https://www.slideshare.net/ekmett/skewbinary-online-lowest-common-ancestor-search)
//
// 1. For each pair of nodes {skin joint, scene root} build a path from scene root to the skin joint as a list of node IDs
// 2. Then cut all path lists to same length (ie. the length of the minimum path)
// 3. Finally, step down the paths from the root until they diverge. The last matching ID is the LCA

std::string GLTFSkins::FindSkinRootId(const Microsoft::glTF::Skin& skin, const Microsoft::glTF::Scene& scene, const Microsoft::glTF::IndexedContainer<const Microsoft::glTF::Node>& nodes) const
{
    std::vector<JointPath> jointPaths;

    // 1. Find paths for all joints in skin
    for (auto& jointId : skin.jointIds)
    {
        auto& jointNode = nodes.Get(jointId);
        JointPath path;
        
        // GLTF scenes do not have an explicit root so search from each node in scene.nodes
        for (auto& sceneRootId : scene.nodes)
        {
            path.push_back(sceneRootId);
            if (FindPath(sceneRootId, jointNode, nodes, path))
            {
                jointPaths.push_back(path);
                break;
            }
            path.pop_back();
        }
    }

    // Some joint nodes are not part of the scene graph so there's no common root
    if (jointPaths.size() != skin.jointIds.size())
    {
        // Legacy Base3D behaviour is to return the first node in the scene
        return scene.nodes.front();
    }

    // 2. Find min path length of joints
    size_t minPathLength = std::numeric_limits<size_t>::max();
    std::for_each(jointPaths.begin(), jointPaths.end(), [&minPathLength](const JointPath& path) { minPathLength = std::min(minPathLength, path.size()); });

    int commonIndex = -1;

    // 3. Check each path element starting from the root and working down towards the joints. 
    //    When the path elements stop matching the LCA was the last one that matched

    // Pick first path to compare against the others
    auto& candidatePath = jointPaths.front();
    for (size_t i = 0; i < minPathLength; i++)
    {
        // If all all other paths have this id in position i it's the LCA
        auto& candidateId = candidatePath.at(i);

        // Skip the first path since that's the candidate
        auto comparePath = jointPaths.begin();
        comparePath++;

        // Check paths 2..n
        for (; comparePath != jointPaths.end(); comparePath++)
        {
            auto& comparePathId = comparePath->at(i);
            if (comparePathId != candidateId)
            {
                // Note: If commonIndex is < 0 then the LCA is the implicit scene root (the parent of the nodes in scene.nodes)
                return (commonIndex >= 0) ? candidatePath.at(commonIndex) : "";
            }
        }
        commonIndex++;
    }

    // Note: If commonIndex is < 0 then the LCA is the implicit scene root (the parent of the nodes in scene.nodes)
    return (commonIndex >= 0) ? candidatePath.at(commonIndex) : "";
}
