/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/Trace.h>
#include <CoreUtils/GLTFChannelAnimations.h>

#include <GLTFSDK/Document.h>
#include <GLTFSDK/GLTFResourceReader.h>
#include <GLTFSDK/BufferBuilder.h>
#include <GLTFSDK/Math.h>

DEFINE_TRACE_AREA(GLTFChannelAnimations, 0);

namespace
{
    // TODO: Move to Validation.cpp in GLTF SDK
    void ValidateKeyFrame(Microsoft::glTF::InterpolationType interpolation, size_t keyFrameTimeCount, size_t keyFrameValueCount)
    {
        // Note: There are 3 elements per keyframe for cubic spline interpolation and 1 element per keyframe for linear and step interpolation
        auto adjustedKeyFrameValueCount = (interpolation == Microsoft::glTF::INTERPOLATION_CUBICSPLINE) ? keyFrameValueCount / 3 : keyFrameValueCount;
        if (keyFrameTimeCount != adjustedKeyFrameValueCount)
        {
            throw Babylon::Utils::BabylonException("GLTFChannelAnimations::ValidateKeyFrame() -- the number of keyframe animation times does not match keyframe values");
        }
    }
}

GLTFChannelAnimations::GLTFChannelAnimations(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::GLTFResourceReader& reader)
{
    for (auto& gltfAnimation : gltfDocument.animations.Elements())
    {
        LoadAnimationData(gltfAnimation.id, gltfDocument, reader);
    }
}

// For loading node animation data from non-GLTF sources
GLTFChannelAnimations::GLTFChannelAnimations(
    std::map<std::string, std::pair<float, float>>& animationTimes,
    std::map<std::string, Microsoft::glTF::Animation>& animations,
    std::vector<std::string>& animationOrdering,
    std::map<std::string, std::vector<float>>& inputAccesors)
    : m_animationTimes(animationTimes),
    m_animations(animations),
    m_animationOrdering(animationOrdering),
    m_inputAccessors(inputAccesors)
    {}

void GLTFChannelAnimations::LoadOutputAccessorData(
    std::string& accessorId,
    const std::vector<float>& positions,
    const std::vector<float>& scales,
    const std::vector<float>& rotations,
    const std::vector<float>& weights)
{
    GLTFChannelAnimations::SamplerChannelData samplerData(positions, rotations, scales, weights, 0);
    m_outputAccessors.emplace(accessorId, std::move(samplerData));
}

void GLTFChannelAnimations::ValidateAccessorData() const
{
    for (auto& animationPair : m_animations)
    {
        auto& gltfAnimation = animationPair.second;

        for (auto& channel : gltfAnimation.channels.Elements())
        {
            if (!gltfAnimation.samplers.Has(channel.samplerId))
            {
                throw Babylon::Utils::BabylonException((std::string("GLTFChannelAnimations::ValidateAccessorData() -- animation samplerId ") + channel.samplerId + " not found").c_str());
            }

            auto& sampler = gltfAnimation.samplers[channel.samplerId];

            auto inputAccessorIt = m_inputAccessors.find(sampler.inputAccessorId);
            if (inputAccessorIt == m_inputAccessors.end())
            {
                throw Babylon::Utils::BabylonException("GLTFChannelAnimations::ValidateAccessorData() -- input accessor not found");
            }

            auto outputAccessorIt = m_outputAccessors.find(sampler.outputAccessorId);
            if (outputAccessorIt == m_outputAccessors.end())
            {
                throw Babylon::Utils::BabylonException("GLTFChannelAnimations::ValidateAccessorData() -- output accessor not found");
            }

            const size_t numKeyFrames = inputAccessorIt->second.size();
            const SamplerChannelData& samplerChannelData = outputAccessorIt->second;
            
            switch (channel.target.path)
            {
            case Microsoft::glTF::TargetPath::TARGET_TRANSLATION:
                ValidateKeyFrame(sampler.interpolation, numKeyFrames, samplerChannelData.numPositions);
                break;
            case Microsoft::glTF::TargetPath::TARGET_ROTATION:
                ValidateKeyFrame(sampler.interpolation, numKeyFrames, samplerChannelData.numRotations);
                break;
            case Microsoft::glTF::TargetPath::TARGET_SCALE:
                ValidateKeyFrame(sampler.interpolation, numKeyFrames, samplerChannelData.numScales);
                break;
            case Microsoft::glTF::TargetPath::TARGET_UNKNOWN:
            case Microsoft::glTF::TargetPath::TARGET_WEIGHTS:
                break;
            }
        }
    }
}

void GLTFChannelAnimations::LoadNodeBasePoseData(
    std::string& nodeId,
    const Microsoft::glTF::Vector3& position,
    const Microsoft::glTF::Vector3& scale,
    const Microsoft::glTF::Quaternion& rotation,
    const std::vector<float>& weights)
{
    GLTFChannelAnimations::NodeBasePose basePose;
    basePose.rotation = rotation;
    basePose.scale = scale;
    basePose.translation = position;
    basePose.weights = weights;
    m_targetNodeBasePoses.emplace(nodeId, basePose);
}

void GLTFChannelAnimations::LoadAnimationData(const std::string& gltfAnimationId, const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::GLTFResourceReader& reader)
{
    auto& gltfAnimation = gltfDocument.animations.Get(gltfAnimationId);
    auto it = m_animations.insert({ gltfAnimation.id, gltfAnimation });
    if (!it.second)
    {
        throw Babylon::Utils::BabylonInvalidArgException("GLTFChannelAnimations::LoadAnimationData() -- animationId already loaded");
    }

    if (m_animationOrdering.size() == 0)
    {
        m_animationOrdering.resize(gltfDocument.animations.Size());
    }
    else if (m_animationOrdering.size() != gltfDocument.animations.Size())
    {
        throw Babylon::Utils::BabylonException("GLTFChannelAnimations::LoadAnimationData() -- number of animations in document does not match previous value");
    }

    size_t animationIndex = gltfDocument.animations.GetIndex(gltfAnimationId);
    if (!m_animationOrdering[animationIndex].empty())
    {
        throw Babylon::Utils::BabylonInvalidArgException("GLTFChannelAnimations::LoadAnimationData() -- invalid animationId specified");
    }
    m_animationOrdering[animationIndex] = gltfAnimation.id;

    // Channels can share samplers--keep track of visited samplers so they aren't duplicated
    std::unordered_set<std::string> loadedSamplers;

    // Collect animation data
    for (const auto& channel : gltfAnimation.channels.Elements())
    {
        const auto& sampler = gltfAnimation.samplers.Get(channel.samplerId);

        if (loadedSamplers.find(sampler.id) == loadedSamplers.end())
        {
            if (!HasKeyFrameTimes(sampler.inputAccessorId))
            {
                auto keyFrameTimes = Microsoft::glTF::AnimationUtils::GetKeyframeTimes(gltfDocument, reader, sampler);
                AddKeyFrameTimes(sampler.inputAccessorId, std::move(keyFrameTimes));
            }
            UpdateAnimationTime(gltfAnimation.id, sampler.inputAccessorId);

            const auto keyFrameTimeCount = m_inputAccessors[sampler.inputAccessorId].size();

            if (channel.target.path == Microsoft::glTF::TargetPath::TARGET_TRANSLATION)
            {
                auto keyFrameTranslations = Microsoft::glTF::AnimationUtils::GetTranslations(gltfDocument, reader, sampler);
                auto keyFrameTranslationCount = keyFrameTranslations.size() / Microsoft::glTF::Accessor::GetTypeCount(Microsoft::glTF::AccessorType::TYPE_VEC3);
                ValidateKeyFrame(sampler.interpolation, keyFrameTimeCount, keyFrameTranslationCount);
                AddKeyFramePositions(sampler.outputAccessorId, std::move(keyFrameTranslations));
            }
            else if (channel.target.path == Microsoft::glTF::TargetPath::TARGET_ROTATION)
            {
                auto keyFrameRotations = Microsoft::glTF::AnimationUtils::GetRotations(gltfDocument, reader, sampler);
                auto keyFrameRotationCount = keyFrameRotations.size() / Microsoft::glTF::Accessor::GetTypeCount(Microsoft::glTF::AccessorType::TYPE_VEC4);
                ValidateKeyFrame(sampler.interpolation, keyFrameTimeCount, keyFrameRotationCount);
                AddKeyFrameRotations(sampler.outputAccessorId, std::move(keyFrameRotations));
            }
            else if (channel.target.path == Microsoft::glTF::TargetPath::TARGET_SCALE)
            {
                auto keyFrameScales = Microsoft::glTF::AnimationUtils::GetScales(gltfDocument, reader, sampler);
                auto keyFrameScaleCount = keyFrameScales.size() / Microsoft::glTF::Accessor::GetTypeCount(Microsoft::glTF::AccessorType::TYPE_VEC3);
                ValidateKeyFrame(sampler.interpolation, keyFrameTimeCount, keyFrameScaleCount);
                AddKeyFrameScales(sampler.outputAccessorId, std::move(keyFrameScales));
            }
            else if (channel.target.path == Microsoft::glTF::TargetPath::TARGET_WEIGHTS)
            {
                auto keyFrameWeights = Microsoft::glTF::AnimationUtils::GetMorphWeights(gltfDocument, reader, sampler);
                auto& node = gltfDocument.nodes.Get(channel.target.nodeId);
                auto& morphMesh = gltfDocument.meshes.Get(node.meshId);
                size_t numMorphTargets = morphMesh.primitives[0].targets.size();
                if (numMorphTargets > 0)
                {
                    ValidateKeyFrame(sampler.interpolation, keyFrameTimeCount, keyFrameWeights.size() / numMorphTargets);
                    AddKeyFrameWeights(sampler.outputAccessorId, std::move(keyFrameWeights), numMorphTargets);
                }
            }
            
            loadedSamplers.insert(sampler.id);
        }

        // Store target node transform as a "base pose" for serialization
        if (!channel.target.nodeId.empty() && m_targetNodeBasePoses.find(channel.target.nodeId) == m_targetNodeBasePoses.end())
        {
            auto& node = gltfDocument.nodes.Get(channel.target.nodeId);
            m_targetNodeBasePoses[channel.target.nodeId] = { node.translation, node.rotation, node.scale, node.weights };
        }
    }
}

std::vector<std::string> GLTFChannelAnimations::GetTargetedNodeIds(const std::string& animationId) const
{
    std::set<std::string> targetedNodeIds;

    const auto& animationIt = m_animations.find(animationId);
    if (animationIt != m_animations.end())
    {
        auto& animationChannels = animationIt->second.channels;
        for (const auto& channel : animationChannels.Elements())
        {
            if (!channel.target.nodeId.empty())
            {
                targetedNodeIds.emplace(channel.target.nodeId);
            }
        }
    }
    else
    {
        throw Babylon::Utils::BabylonInvalidArgException("GLTFChannelAnimations::GetTargetedNodeIds() -- invalid animationId specified");
    }

    return { targetedNodeIds.begin(), targetedNodeIds.end() };
}

std::vector<std::string> GLTFChannelAnimations::GetAnimationIdsForTargetNodeId(
    const std::string& targetNodeId) const
{
    std::vector<std::string> animationIds;

    for (const auto& animationPair : m_animations)
    {
        auto& channels = animationPair.second.channels;
        for (const auto& channel : channels.Elements())
        {
            if (channel.target.nodeId == targetNodeId)
            {
                animationIds.emplace_back(animationPair.first);
                break;
            }
        }
    }

    return animationIds;
}

void GLTFChannelAnimations::RetargetNodeIds(const std::map<std::string /*oldNodeId*/, std::string/*newNodeId*/>& oldNodeToNewNodeIdMap)
{
    if (oldNodeToNewNodeIdMap.empty())
    {
        return;
    }

    // Update all channel target node ids
    for (auto& animationPair : m_animations)
    {
        for (const auto& channel : animationPair.second.channels.Elements())
        {
            if (!channel.target.nodeId.empty())
            {
                auto newNodeIdIt = oldNodeToNewNodeIdMap.find(channel.target.nodeId);
                if (newNodeIdIt != oldNodeToNewNodeIdMap.end())
                {
                    auto channelCopy = channel;
                    channelCopy.target.nodeId = newNodeIdIt->second;
                    animationPair.second.channels.Replace(channelCopy);
                }
                else
                {
                    throw Babylon::Utils::BabylonInvalidArgException("GLTFChannelAnimations::RetargetNodeIds() -- channel target node does not have a remapping entry");
                }
            }
        }
    }

    // Update base pose node ids
    for (auto& oldNodeToNewNodeIdIt : oldNodeToNewNodeIdMap)
    {
        auto targetNodeBasePoseIt = m_targetNodeBasePoses.find(oldNodeToNewNodeIdIt.first);
        if (targetNodeBasePoseIt != m_targetNodeBasePoses.end())
        {
            auto basePose = targetNodeBasePoseIt->second;
            m_targetNodeBasePoses.erase(targetNodeBasePoseIt);
            m_targetNodeBasePoses.emplace(oldNodeToNewNodeIdIt.second, std::move(basePose));
        }
    }
}

std::vector<Microsoft::glTF::Animation> GLTFChannelAnimations::ExportAnimationData(Microsoft::glTF::BufferBuilder& bufferBuilder) const
{
    std::vector<Microsoft::glTF::Animation> animations;

    for (size_t animationIndex = 0; animationIndex < m_animationOrdering.size(); animationIndex++)
    {
        animations.push_back(ExportAnimationData(animationIndex, bufferBuilder));
    }
    return animations;
}

Microsoft::glTF::Animation GLTFChannelAnimations::ExportAnimationData(size_t animationIndex, Microsoft::glTF::BufferBuilder& bufferBuilder) const
{
    auto& animationId = m_animationOrdering.at(animationIndex);
    auto animationIt = m_animations.find(animationId);
    if (animationIt == m_animations.end())
    {
        return {};
    }

    // Ensure there is a buffer to write animation data into
    if (bufferBuilder.GetBufferCount() == 0U)
    {
        bufferBuilder.AddBuffer(Microsoft::glTF::GLB_BUFFER_ID);
    }

    // Copy animation connection data
    auto animation = animationIt->second;

    // Channels can share samplers--keep track of visited samplers so they aren't duplicated
    std::unordered_set<std::string> serializedSamplers;

    // We don't currently store accessors and bufferViews so re-create them from the raw data
    for (auto& channel : animation.channels.Elements())
    {
        auto& sampler = animation.samplers[channel.samplerId];
        if (serializedSamplers.find(sampler.id) == serializedSamplers.end())
        {
            auto newSampler = sampler;
            auto inputAccessorIt = m_inputAccessors.find(newSampler.inputAccessorId);
            BabylonAssert(inputAccessorIt != m_inputAccessors.end());
            if (inputAccessorIt != m_inputAccessors.end())
            {
                auto& keyframeTimes = inputAccessorIt->second;
                std::vector<float> startTime{ keyframeTimes.front() };
                std::vector<float> endTime{ keyframeTimes.back() };

                bufferBuilder.AddBufferView();// Don't specify a BufferViewTarget value as this BufferView doesn't store vertex attribute data

                newSampler.inputAccessorId = bufferBuilder.AddAccessor(keyframeTimes, {
                    Microsoft::glTF::AccessorType::TYPE_SCALAR,
                    Microsoft::glTF::ComponentType::COMPONENT_FLOAT,
                    false,
                    startTime, endTime }).id;

                auto outputAccessorIt = m_outputAccessors.find(newSampler.outputAccessorId);
                BabylonAssert(outputAccessorIt != m_outputAccessors.end());
                if (outputAccessorIt != m_outputAccessors.end())
                {
                    std::vector<float> keyFrameValueEntries;
                    Microsoft::glTF::AccessorType accessorType{};

                    switch (channel.target.path)
                    {
                    case Microsoft::glTF::TargetPath::TARGET_ROTATION:
                        keyFrameValueEntries = outputAccessorIt->second.rotation;
                        accessorType = Microsoft::glTF::AccessorType::TYPE_VEC4;
                        break;
                    case Microsoft::glTF::TargetPath::TARGET_TRANSLATION:
                        keyFrameValueEntries = outputAccessorIt->second.position;
                        accessorType = Microsoft::glTF::AccessorType::TYPE_VEC3;
                        break;
                    case Microsoft::glTF::TargetPath::TARGET_SCALE:
                        keyFrameValueEntries = outputAccessorIt->second.scale;
                        accessorType = Microsoft::glTF::AccessorType::TYPE_VEC3;
                        break;
                    case Microsoft::glTF::TargetPath::TARGET_WEIGHTS:
                        keyFrameValueEntries = outputAccessorIt->second.weights;
                        accessorType = Microsoft::glTF::AccessorType::TYPE_SCALAR;
                        break;
                    default:
                        throw Babylon::Utils::BabylonInvalidArgException("GLTFChannelAnimations::ExportAnimationData() -- unknown channel target path");
                    }

                    bufferBuilder.AddBufferView();// Don't specify a BufferViewTarget value as this BufferView doesn't store vertex attribute data

                    newSampler.outputAccessorId = bufferBuilder.AddAccessor(keyFrameValueEntries, {
                        accessorType,
                        Microsoft::glTF::ComponentType::COMPONENT_FLOAT }).id;

                    // Update with the new sampler
                    animation.samplers.Replace(newSampler);
                }
            }

            serializedSamplers.insert(sampler.id);
        }
    }

    return animation;
}

bool GLTFChannelAnimations::GetNodeBasePose(
    const std::string& nodeId,
    Microsoft::glTF::Vector3& translation,
    Microsoft::glTF::Quaternion& rotation,
    Microsoft::glTF::Vector3& scale,
    std::vector<float>& weights) const
{
    if (m_targetNodeBasePoses.find(nodeId) != m_targetNodeBasePoses.end())
    {
        auto basePose = m_targetNodeBasePoses.at(nodeId);
        translation = basePose.translation;
        rotation = basePose.rotation;
        scale = basePose.scale;
        weights = basePose.weights;
        return true;
    }
    return false;
}

std::pair<float, float> GLTFChannelAnimations::GetKeyFrameTimes(const std::string& accessorId, float currentTime, size_t& lowerKeyFrameIndex, size_t& upperKeyFrameIndex)
{
    const auto& times = m_inputAccessors[accessorId];
    auto upperIt = std::lower_bound(times.begin(), times.end(), currentTime);
    if (upperIt != times.end() && *upperIt == currentTime)
    {
        upperKeyFrameIndex = lowerKeyFrameIndex = std::distance(times.begin(), upperIt);
    }
    else
    {
        upperKeyFrameIndex = std::min(static_cast<size_t>(std::distance(times.begin(), upperIt)), times.size() - 1);
        lowerKeyFrameIndex = static_cast<size_t>(std::max(static_cast<int>(upperKeyFrameIndex) - 1, 0));
    }
    return std::pair<float, float>(times[lowerKeyFrameIndex], times[upperKeyFrameIndex]);
}

void GLTFChannelAnimations::GetKeyFramePositions(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<Microsoft::glTF::Vector3>& outputValues, size_t numOutputValues)
{
    const auto values = reinterpret_cast<const Microsoft::glTF::Vector3*>(m_outputAccessors[accessorId].position.data());
    outputValues.insert(outputValues.begin(), &values[lowerKeyFrameIndex * numOutputValues], &values[upperKeyFrameIndex * numOutputValues + numOutputValues]);
}

void GLTFChannelAnimations::GetKeyFrameRotations(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<Microsoft::glTF::Quaternion>& outputValues, size_t numOutputValues)
{
    const auto values = reinterpret_cast<const Microsoft::glTF::Quaternion*>(m_outputAccessors[accessorId].rotation.data());
    outputValues.insert(outputValues.begin(), &values[lowerKeyFrameIndex * numOutputValues], &values[upperKeyFrameIndex * numOutputValues + numOutputValues]);
}

void GLTFChannelAnimations::GetKeyFrameScales(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<Microsoft::glTF::Vector3>& outputValues, size_t numOutputValues)
{
    const auto values = reinterpret_cast<const Microsoft::glTF::Vector3*>(m_outputAccessors[accessorId].scale.data());
    outputValues.insert(outputValues.begin(), &values[lowerKeyFrameIndex * numOutputValues], &values[upperKeyFrameIndex * numOutputValues + numOutputValues]);
}

void GLTFChannelAnimations::GetKeyFrameWeights(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<float>& outputValues, size_t numOutputValues)
{
    const auto values = static_cast<float *>(m_outputAccessors[accessorId].weights.data());
    size_t keyFrameDimension = m_outputAccessors[accessorId].numMorphTargets;  // This is the dimension of each keyframe weight vector

    outputValues.insert(outputValues.begin(), &values[(lowerKeyFrameIndex * numOutputValues)*keyFrameDimension], &values[((upperKeyFrameIndex * numOutputValues) + numOutputValues)*keyFrameDimension]);
}

bool GLTFChannelAnimations::HasKeyFrameTimes(const std::string& accessorId)
{
    return (m_inputAccessors.find(accessorId) != m_inputAccessors.end());
}

void GLTFChannelAnimations::AddKeyFrameTimes(const std::string& accessorId, std::vector<float>&& keyFrameTimes)
{
    m_inputAccessors[accessorId] = std::move(keyFrameTimes);
}

void GLTFChannelAnimations::UpdateAnimationTime(const std::string& animationId, const std::string& accessorId)
{
    if (m_animationTimes.find(animationId) == m_animationTimes.end())
    {
        m_animationTimes[animationId] = { FLT_MAX, FLT_MIN };
    }
    m_animationTimes[animationId].first = std::min(m_animationTimes[animationId].first, m_inputAccessors[accessorId].front());
    m_animationTimes[animationId].second = std::max(m_animationTimes[animationId].second, m_inputAccessors[accessorId].back());
}

void GLTFChannelAnimations::AddKeyFramePositions(const std::string& accessorId, std::vector<float>&& keyFrameValues)
{
    m_outputAccessors[accessorId].position = std::move(keyFrameValues);
}

void GLTFChannelAnimations::AddKeyFrameRotations(const std::string& accessorId, std::vector<float>&& keyFrameValues)
{
    m_outputAccessors[accessorId].rotation = std::move(keyFrameValues);
}

void GLTFChannelAnimations::AddKeyFrameScales(const std::string& accessorId, std::vector<float>&& keyFrameValues)
{
    m_outputAccessors[accessorId].scale = std::move(keyFrameValues);
}

void GLTFChannelAnimations::AddKeyFrameWeights(const std::string& accessorId, std::vector<float>&& keyFrameValues, size_t numMorphTargets)
{
    m_outputAccessors[accessorId].weights = std::move(keyFrameValues);
    m_outputAccessors[accessorId].numMorphTargets = numMorphTargets;
}

Babylon::Utils::glTF::AnimationMetadata::eType GLTFChannelAnimations::GetAnimationTypes(const std::string& animationId, const std::set<std::string>& jointNodeIds) const
{
    unsigned int animationType = 0;

    const auto& animation = m_animations.at(animationId);

    for (size_t j = 0; j < animation.channels.Size(); j++)
    {
        auto& channel = animation.channels[j];

        if (channel.target.path == Microsoft::glTF::TargetPath::TARGET_WEIGHTS)
        {
            animationType |= Babylon::Utils::glTF::AnimationMetadata::kMorph;
        }
        else if (jointNodeIds.find(channel.target.nodeId) == jointNodeIds.end())
        {
            // Found animation targeting a non-joint node
            animationType |= Babylon::Utils::glTF::AnimationMetadata::kNode;
        }
        else
        {
            animationType |= Babylon::Utils::glTF::AnimationMetadata::kSkinned;
        }
    }

    return static_cast<Babylon::Utils::glTF::AnimationMetadata::eType>(animationType);
}
