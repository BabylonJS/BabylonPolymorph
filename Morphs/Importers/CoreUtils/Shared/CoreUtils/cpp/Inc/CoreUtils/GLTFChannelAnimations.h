/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <set>
#include <map>
#include <string>
#include <vector>
#include <cstdio>

#include <GLTFSDK/GLTF.h>
#include <GLTFSDK/Math.h>
#include <GLTFSDK/AnimationUtils.h>

#include <CoreUtils/Assert.h>
#include <CoreUtils/Math/SimpleMath.h>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/Gltf.h>

namespace Microsoft
{
    namespace glTF
    {
        class BufferBuilder;
    }
}

namespace GLTFChannelInterpolators
{
    // Interpolation helper functions - TODO: move to GLTF SDK Math.h

    inline Microsoft::glTF::Quaternion operator*(const float a, const Microsoft::glTF::Quaternion& q)
    {
        return Microsoft::glTF::Quaternion(q.x * a, q.y * a, q.z * a, q.w * a);
    }

    inline Microsoft::glTF::Quaternion operator*(const Microsoft::glTF::Quaternion& q, float a)
    {
        // Uses operator*(float, Quaternion), above
        return a * q;
    }

    inline Microsoft::glTF::Quaternion operator+(const Microsoft::glTF::Quaternion& q0, const Microsoft::glTF::Quaternion& q1)
    {
        return Microsoft::glTF::Quaternion(q0.x + q1.x, q0.y + q1.y, q0.z + q1.z, q0.w + q1.w);
    }

    inline Microsoft::glTF::Vector3 operator*(const float a, const Microsoft::glTF::Vector3& v)
    {
        return Microsoft::glTF::Vector3(v.x * a, v.y * a, v.z * a);
    }

    inline Microsoft::glTF::Vector3 operator+(const Microsoft::glTF::Vector3& v0, const Microsoft::glTF::Vector3& v1)
    {
        return Microsoft::glTF::Vector3(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);
    }

    inline Microsoft::glTF::Vector3 operator-(const Microsoft::glTF::Vector3& v0, const Microsoft::glTF::Vector3& v1)
    {
        return Microsoft::glTF::Vector3(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);
    }

    inline Microsoft::glTF::Quaternion Normalize(const Microsoft::glTF::Quaternion& q)
    {
        float length = std::sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
        if (std::fabs(length) > 1e-5)
        {
            length = 1.0f / length;
        }
        return length * q;
    }

    inline std::vector<float> operator*(const float a, const std::vector<float>& v)
    {
        std::vector<float> results(v);
        std::for_each(results.begin(), results.end(), [a](float &f) { f *= a; });
        return results;
    }

    inline std::vector<float> operator+(const std::vector<float>& v0, const std::vector<float>& v1)
    {
        SpectreAssert(v0.size() == v1.size());
        std::vector<float> results(v0.size());
        std::transform(v0.begin(), v0.end(), v1.begin(), results.begin(), std::plus<float>());
        return results;
    }

    inline std::vector<float> operator-(const std::vector<float>& v0, const std::vector<float>& v1)
    {
        SpectreAssert(v0.size() == v1.size());
        std::vector<float> results(v0.size());
        std::transform(v0.begin(), v0.end(), v1.begin(), results.begin(), std::minus<float>());
        return results;
    }

    // Quaternion interpolation functions

    // GLTF 2.0 step interpolation (https://github.com/KhronosGroup/glTF/tree/master/specification/2.0):
    // The animated values remain constant to the output of the first keyframe, until the next keyframe.
    // The number of output elements must equal the number of input elements
    inline Microsoft::glTF::Quaternion QuaternionInterpolation_Step(const Microsoft::glTF::Quaternion& q0, const Microsoft::glTF::Quaternion& /*q1*/, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        SpectreUnusedParameter(t);
        return Normalize(q0);
    }

    inline Microsoft::glTF::Quaternion QuaternionInterpolation_Slerp(const Microsoft::glTF::Quaternion& q0, const Microsoft::glTF::Quaternion& q1, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        auto q2 = q1;
        float omega = q0.x * q2.x + q0.y * q2.y + q0.z * q2.z + q0.w * q2.w;
        if (omega < 0.0f)
        {
            omega = -omega;
            q2 = -1.0f * q2;
        }

        omega = Microsoft::glTF::Math::Clamp(omega, -1.0f, 1.0f);

        if (1.0f - omega < 1e-5f)
        {
            return Normalize(q2 * t + q0 * (1.0f - t));
        }

        float theta_0 = std::acosf(omega);
        float theta = theta_0 * t;

        float sinTheta = std::sinf(theta);
        float sinTheta_0 = std::sinf(theta_0);
        float quot = sinTheta / sinTheta_0;
        float s0 = std::cosf(theta) - omega * quot;
        float s1 = quot;

        return Normalize((s0 * q0) + (s1 * q2));
    }

    inline Microsoft::glTF::Quaternion QuaternionInterpolation_CubicSpline(const Microsoft::glTF::Quaternion& q0, const Microsoft::glTF::Quaternion& startTangent, const Microsoft::glTF::Quaternion& q1, const Microsoft::glTF::Quaternion& endTangent, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        float t2 = t * t;
        float t3 = t2 * t;
        auto result = (2.0f * t3 - 3.0f * t2 + 1.0f) * q0 + (t3 - 2.0f * t2 + t) * startTangent + (-2.0f * t3 + 3.0f * t2) * q1 + (t3 - t2) * endTangent;
        return Normalize(result);
    }

    // Vector3 interpolation functions

    // GLTF 2.0 step interpolation (https://github.com/KhronosGroup/glTF/tree/master/specification/2.0):
    // The animated values remain constant to the output of the first keyframe, until the next keyframe.
    // The number of output elements must equal the number of input elements
    inline Microsoft::glTF::Vector3 Vector3Interpolation_Step(const Microsoft::glTF::Vector3& v0, const Microsoft::glTF::Vector3& v1, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        return (t != 1.0f) ? v0 : v1;
    }

    inline Microsoft::glTF::Vector3 Vector3Interpolation_Linear(const Microsoft::glTF::Vector3& v0, const Microsoft::glTF::Vector3& v1, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        auto result = v0 + t * (v1 - v0);
        return result;
    }

    inline Microsoft::glTF::Vector3 Vector3Interpolation_CubicSpline(const Microsoft::glTF::Vector3& v0, const Microsoft::glTF::Vector3& startTangent, const Microsoft::glTF::Vector3& v1, const Microsoft::glTF::Vector3& endTangent, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        float t2 = t * t;
        float t3 = t2 * t;
        auto result = (2.0f * t3 - 3.0f * t2 + 1.0f) * v0 + (t3 - 2.0f * t2 + t) * startTangent + (-2.0f * t3 + 3.0f * t2) * v1 + (t3 - t2) * endTangent;
        return result;
    }

    // VectorN interpolation functions - used for morph target weights

    // GLTF 2.0 step interpolation (https://github.com/KhronosGroup/glTF/tree/master/specification/2.0):
    // The animated values remain constant to the output of the first keyframe, until the next keyframe.
    // The number of output elements must equal the number of input elements
    inline std::vector<float> MorphWeightsInterpolation_Step(const std::vector<float>& v0, const std::vector<float>& /*v1*/, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        SpectreUnusedParameter(t);
        return v0;
    }

    inline std::vector<float> MorphWeightsInterpolation_Linear(const std::vector<float>& v0, const std::vector<float>& v1, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        auto result = v0 + t * (v1 - v0);
        return result;
    }

    inline std::vector<float> MorphWeightsInterpolation_CubicSpline(const std::vector<float>& v0, const std::vector<float>& startTangent, const std::vector<float>& v1, const std::vector<float>& endTangent, float t)
    {
        SpectreAssert(0.0f <= t && t <= 1.0f);
        float t2 = t * t;
        float t3 = t2 * t;
        auto result = (2.0f * t3 - 3.0f * t2 + 1.0f) * v0 + (t3 - 2.0f * t2 + t) * startTangent + (-2.0f * t3 + 3.0f * t2) * v1 + (t3 - t2) * endTangent;
        return result;
    }
} // GLTFChannelInterpolators

class GLTFChannelAnimations
{
public:
    GLTFChannelAnimations() = default;
    ~GLTFChannelAnimations() = default;

    GLTFChannelAnimations(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::GLTFResourceReader& reader);

    GLTFChannelAnimations(
        std::map<std::string, std::pair<float, float>>& animationTimes,
        std::map<std::string, Microsoft::glTF::Animation>& animations,
        std::vector<std::string>& animationOrdering,
        std::map<std::string, std::vector<float>>& inputAccesors);

    //TODO: make this a variadic function
    void LoadOutputAccessorData(
        std::string& accessorId,
        const std::vector<float>& positions,
        const std::vector<float>& scales,
        const std::vector<float>& rotations,
        const std::vector<float>& weights);

    //TODO: make this a variadic function
    void LoadNodeBasePoseData(
        std::string& nodeId,
        const Microsoft::glTF::Vector3& position,
        const Microsoft::glTF::Vector3& scale,
        const Microsoft::glTF::Quaternion& rotation,
        const std::vector<float>& weights);

    void LoadAnimationData(const std::string& gltfAnimationId, const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::GLTFResourceReader& reader);

    std::pair<float, float> GetAnimationTime(const std::string& animationId) const { return m_animationTimes.at(animationId); }
    std::string GetAnimationName(const std::string& animationId) const { return m_animations.at(animationId).name; }

    std::vector<std::string> GetTargetedNodeIds(const std::string& animationId) const;
    void RetargetNodeIds(const std::map<std::string /*oldNodeId*/, std::string/*newNodeId*/>& oldNodeToNewNodeIdMap);

    // \brief
    // Gets a list of gltf animation ids that target the specified node.
    std::vector<std::string> GetAnimationIdsForTargetNodeId(
        const std::string& targetNodeId) const;

    size_t GetAnimationCount() const { return m_animationOrdering.size(); }

    std::string GetAnimationId(size_t animationIndex) const { return m_animationOrdering.at(animationIndex); }

    // NOTE: Temporary transition function. Can be removed once skeletal animation support is implemented.
    bool HasAnimation(const std::string& animationId) const
    {
        auto it = std::find(m_animationOrdering.begin(), m_animationOrdering.end(), animationId);
        return (it != m_animationOrdering.end()) ? !it->empty() : false;
    }

    template<typename ChannelDataType>
    bool Evaluate(
        const std::string& animationId,
        const std::string& nodeId,
        Microsoft::glTF::TargetPath targetPath,
        float currentTime,
        ChannelDataType& result)
    {
        static_assert(sizeof(ChannelDataType) == -1, "Only Vector3 and Quaternion and std::vector<float> specializations are supported");
        return false;
    }

    std::vector<Microsoft::glTF::Animation> ExportAnimationData(Microsoft::glTF::BufferBuilder& bufferBuilder) const;
    Microsoft::glTF::Animation ExportAnimationData(size_t animationIndex, Microsoft::glTF::BufferBuilder& bufferBuilder) const;

    bool GetNodeBasePose(
        const std::string& nodeId,
        Microsoft::glTF::Vector3& translation,
        Microsoft::glTF::Quaternion& rotation,
        Microsoft::glTF::Vector3& scale,
        std::vector<float>& weights) const;

    void ValidateAccessorData() const;

    Spectre::Utils::glTF::AnimationMetadata::eType GetAnimationTypes(const std::string& animationId, const std::set<std::string>& jointNodeIds) const;

protected:
    struct SamplerChannelData
    {
        SamplerChannelData() = default;

        SamplerChannelData(
            const std::vector<float>& positionsIn,
            const std::vector<float>& rotationsIn,
            const std::vector<float>& scalesIn,
            const std::vector<float>& weightsIn,
            size_t numMorphTargetsIn) :
            position(positionsIn),
            rotation(rotationsIn),
            scale(scalesIn),
            weights(weightsIn),
            numMorphTargets(numMorphTargetsIn),
            numPositions(position.size() / 3),
            numRotations(rotation.size() / 4),
            numScales(scale.size() / 3)
        {
            // TODO: Revisit this interface to allow better validation and reporting, e.g. of numMorphTargets

            if (position.size() % 3 != 0)
            {
                throw Spectre::Utils::SpectreInvalidArgException("SamplerChannelData -- invalid number of position components on channel");
            }

            if (rotation.size() % 4 != 0)
            {
                throw Spectre::Utils::SpectreInvalidArgException("SamplerChannelData -- invalid number of rotation components on channel");
            }

            if (scale.size() % 3 != 0)
            {
                throw Spectre::Utils::SpectreInvalidArgException("SamplerChannelData -- invalid number of scale components on channel");
            }
        }

        std::vector<float> position;
        std::vector<float> rotation;
        std::vector<float> scale;
        std::vector<float> weights;
        size_t numMorphTargets = 0;  // This is the dimension of a weights keyframe
        size_t numPositions = 0; // Number of aggregate position entries (Vector3s)
        size_t numRotations = 0; // Number of aggregate rotation entries (Quaternions)
        size_t numScales = 0; // Number of aggregate scale entries (Vector3s) 
    };

    struct NodeBasePose
    {
        Microsoft::glTF::Vector3 translation;
        Microsoft::glTF::Quaternion rotation;
        Microsoft::glTF::Vector3 scale;
        std::vector<float> weights;
    };

    template<typename ChannelDataType>
    ChannelDataType Interpolate(
        const Microsoft::glTF::InterpolationType& interpolationType,
        float currentTime,
        const std::pair<float, float>& inputTimes,
        const std::vector<ChannelDataType>& outputValues)
    {
        static_assert(sizeof(ChannelDataType) == -1, "Only Vector3 and Quaternion specializations are supported");
        return {};
    }

    std::vector<float> InterpolateWeights(
        const Microsoft::glTF::InterpolationType& interpolationType,
        float currentTime,
        const std::pair<float, float>& inputTimes,
        const std::vector<float>& outputValues,
        const uint32_t dim);

    std::map<std::string /*animationId*/, std::pair<float, float>> m_animationTimes;

    std::map<std::string /*animationId*/, Microsoft::glTF::Animation>   m_animations;
    std::vector<std::string /*animationId*/>                            m_animationOrdering; // Save animation ordering for serializing

    std::map<std::string /*accessorId*/, std::vector<float>> m_inputAccessors;

    std::map<std::string /*accessorId*/, SamplerChannelData> m_outputAccessors;

    std::map<std::string /*nodeId*/, NodeBasePose> m_targetNodeBasePoses;

    std::pair<float, float> GetKeyFrameTimes(const std::string& accessorId, float currentTime, size_t& lowerKeyFrameIndex, size_t& upperKeyFrameIndex);

    void GetKeyFramePositions(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<Microsoft::glTF::Vector3>& outputValues, size_t numOutputValues);
    void GetKeyFrameRotations(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<Microsoft::glTF::Quaternion>& outputValues, size_t numOutputValues);
    void GetKeyFrameScales(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<Microsoft::glTF::Vector3>& outputValues, size_t numOutputValues);
    void GetKeyFrameWeights(const std::string& accessorId, size_t lowerKeyFrameIndex, size_t upperKeyFrameIndex, std::vector<float>& outputValues, size_t numOutputValues);

    bool HasKeyFrameTimes(const std::string& accessorId);
    void AddKeyFrameTimes(const std::string& accessorId, std::vector<float>&& keyFrameTimes);
    void UpdateAnimationTime(const std::string& animationId, const std::string& accessorId);

    void AddKeyFramePositions(const std::string& accessorId, std::vector<float>&& keyFrameValues);
    void AddKeyFrameRotations(const std::string& accessorId, std::vector<float>&& keyFrameValues);
    void AddKeyFrameScales(const std::string& accessorId, std::vector<float>&& keyFrameValues);
    void AddKeyFrameWeights(const std::string& accessorId, std::vector<float>&& keyFrameValues, const size_t numMorphTargets );

    inline float GetInterpolatedTime(float currentTime, float lowerTime, float upperTime)
    {
        float interpolationTime = (currentTime - lowerTime) / (upperTime - lowerTime + 1e-5f);
        interpolationTime = Microsoft::glTF::Math::Clamp(interpolationTime, 0.0f, 1.0f);
        return interpolationTime;
    }
};

template<>
inline Microsoft::glTF::Vector3 GLTFChannelAnimations::Interpolate(
    const Microsoft::glTF::InterpolationType& interpolationType,
    float currentTime,
    const std::pair<float, float>& inputTimes,
    const std::vector<Microsoft::glTF::Vector3>& outputValues)
{
    const float interpolatedTime = GetInterpolatedTime(currentTime, inputTimes.first, inputTimes.second);

    Microsoft::glTF::Vector3 result;
    switch (interpolationType)
    {
    case Microsoft::glTF::InterpolationType::INTERPOLATION_STEP:
        result = GLTFChannelInterpolators::Vector3Interpolation_Step(outputValues[0], outputValues[1], interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_LINEAR:
        result = GLTFChannelInterpolators::Vector3Interpolation_Linear(outputValues[0], outputValues[1], interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_CUBICSPLINE:
        result = GLTFChannelInterpolators::Vector3Interpolation_CubicSpline(outputValues[1], outputValues[2], outputValues[4], outputValues[3], interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_UNKNOWN:
        throw Spectre::Utils::SpectreInvalidArgException("Interpolate() -- invalid interpolation type UNKNOWN specified");
    }

    return result;
}

template<>
inline Microsoft::glTF::Quaternion GLTFChannelAnimations::Interpolate(
    const Microsoft::glTF::InterpolationType& interpolationType,
    float currentTime,
    const std::pair<float, float>& inputTimes,
    const std::vector<Microsoft::glTF::Quaternion>& outputValues)
{
    const float interpolatedTime = GetInterpolatedTime(currentTime, inputTimes.first, inputTimes.second);

    Microsoft::glTF::Quaternion result;
    switch (interpolationType)
    {
    case Microsoft::glTF::InterpolationType::INTERPOLATION_STEP:
        result = GLTFChannelInterpolators::QuaternionInterpolation_Step(outputValues[0], outputValues[1], interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_LINEAR:
        result = GLTFChannelInterpolators::QuaternionInterpolation_Slerp(outputValues[0], outputValues[1], interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_CUBICSPLINE:
        result = GLTFChannelInterpolators::QuaternionInterpolation_CubicSpline(outputValues[1], outputValues[2], outputValues[4], outputValues[3], interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_UNKNOWN:
        throw Spectre::Utils::SpectreInvalidArgException("Interpolate() -- invalid interpolation type UNKNOWN specified");
    }

    return result;
}

inline std::vector<float> GLTFChannelAnimations::InterpolateWeights(
    const Microsoft::glTF::InterpolationType& interpolationType,
    float currentTime,
    const std::pair<float, float>& inputTimes,
    const std::vector<float>& outputValues,
    const uint32_t dim)
{
    const float interpolatedTime = GetInterpolatedTime(currentTime, inputTimes.first, inputTimes.second);

    std::vector<float> result;
    auto it0 = outputValues.begin();
    auto it1 = it0 + dim;
    auto it2 = it1 + dim;
    std::vector<float> key0(it0, it1);
    std::vector<float> key1(it1, it2);

    switch (interpolationType)
    {
    case Microsoft::glTF::InterpolationType::INTERPOLATION_STEP:
        result = GLTFChannelInterpolators::MorphWeightsInterpolation_Step(key0, key1, interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_LINEAR:
        result = GLTFChannelInterpolators::MorphWeightsInterpolation_Linear(key0, key1, interpolatedTime);
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_CUBICSPLINE:
        {
            auto it3 = it2 + dim;
            auto it4 = it3 + dim;
            auto it5 = it4 + dim;
            std::vector<float> key2(it2, it3);
            std::vector<float> key3(it3, it4);
            std::vector<float> key4(it4, it5);
            result = GLTFChannelInterpolators::MorphWeightsInterpolation_CubicSpline(key1, key2, key4, key3, interpolatedTime);
        }
        break;
    case Microsoft::glTF::InterpolationType::INTERPOLATION_UNKNOWN:
        throw Spectre::Utils::SpectreInvalidArgException("InterpolateWeights() -- invalid interpolation type UNKNOWN specified");
    }

    return result;
}

template<>
inline bool GLTFChannelAnimations::Evaluate(
    const std::string& animationId,
    const std::string& nodeId,
    Microsoft::glTF::TargetPath targetPath,
    float currentTime,
    Microsoft::glTF::Vector3& result)
{
    const auto& animationIt = m_animations.find(animationId);
    if (animationIt != m_animations.end())
    {
        const auto& channels = animationIt->second.channels;
        for (const auto& channel : channels.Elements())
        {
            if (channel.target.path == targetPath && channel.target.nodeId == nodeId)
            {
                const auto& samplers = animationIt->second.samplers;
                const auto& sampler = samplers[channel.samplerId];

                size_t lowerFrameIndex = 0;
                size_t upperFrameIndex = 0;
                std::pair<float, float> inputTimes = GetKeyFrameTimes(sampler.inputAccessorId, currentTime, lowerFrameIndex, upperFrameIndex);

                size_t numOutputValueElements = (sampler.interpolation == Microsoft::glTF::INTERPOLATION_CUBICSPLINE) ? 3 : 1;
                std::vector<Microsoft::glTF::Vector3> outputValues;

                if (targetPath == Microsoft::glTF::TargetPath::TARGET_TRANSLATION)
                {
                    GetKeyFramePositions(sampler.outputAccessorId, lowerFrameIndex, upperFrameIndex, outputValues, numOutputValueElements);
                }
                else if (targetPath == Microsoft::glTF::TargetPath::TARGET_SCALE)
                {
                    GetKeyFrameScales(sampler.outputAccessorId, lowerFrameIndex, upperFrameIndex, outputValues, numOutputValueElements);
                }
                else
                {
                    throw Spectre::Utils::SpectreInvalidArgException("Evaluate() -- only TRANSLATION and SCALE target types are supported for the Vector3 specialization");
                }

                if (lowerFrameIndex == upperFrameIndex)
                {
                    result = (sampler.interpolation == Microsoft::glTF::INTERPOLATION_CUBICSPLINE) ? outputValues[1] : outputValues[0];
                }
                else
                {
                    result = Interpolate<Microsoft::glTF::Vector3>(sampler.interpolation, currentTime, inputTimes, outputValues);
                }
                return true;
            }
        }
    }
    else
    {
        throw Spectre::Utils::SpectreInvalidArgException("Evaluate() -- invalid animationId specified");
    }

    return false;
}

template<>
inline bool GLTFChannelAnimations::Evaluate(
    const std::string& animationId,
    const std::string& nodeId,
    Microsoft::glTF::TargetPath targetPath,
    float currentTime,
    Microsoft::glTF::Quaternion& result)
{
    const auto& animationIt = m_animations.find(animationId);
    if (animationIt != m_animations.end())
    {
        const auto& channels = animationIt->second.channels;

        for (const auto& channel : channels.Elements())
        {
            if (channel.target.path == targetPath && channel.target.nodeId == nodeId)
            {
                const auto& samplers = animationIt->second.samplers;
                const auto& sampler = samplers[channel.samplerId];

                size_t lowerFrameIndex = 0;
                size_t upperFrameIndex = 0;
                std::pair<float, float> inputTimes = GetKeyFrameTimes(sampler.inputAccessorId, currentTime, lowerFrameIndex, upperFrameIndex);

                size_t numOutputValues = (sampler.interpolation == Microsoft::glTF::INTERPOLATION_CUBICSPLINE) ? 3 : 1;
                std::vector<Microsoft::glTF::Quaternion> outputValues;

                if (targetPath == Microsoft::glTF::TargetPath::TARGET_ROTATION)
                {
                    GetKeyFrameRotations(sampler.outputAccessorId, lowerFrameIndex, upperFrameIndex, outputValues, numOutputValues);
                }
                else
                {
                    throw Spectre::Utils::SpectreInvalidArgException("Evaluate() -- only ROTATION target type is supported for the Quaternion specialization");
                }

                if (lowerFrameIndex == upperFrameIndex)
                {
                    result = (sampler.interpolation == Microsoft::glTF::INTERPOLATION_CUBICSPLINE) ? outputValues[1] : outputValues[0];
                }
                else
                {
                    result = Interpolate<Microsoft::glTF::Quaternion>(sampler.interpolation, currentTime, inputTimes, outputValues);
                }
                return true;
            }
        }
    }
    else
    {
        throw Spectre::Utils::SpectreInvalidArgException("Evaluate() -- invalid animationId specified");
    }

    return false;
}

template<>
inline bool GLTFChannelAnimations::Evaluate(
    const std::string& animationId,
    const std::string& nodeId,
    Microsoft::glTF::TargetPath targetPath,
    float currentTime,
    std::vector<float>& result)
{
    const auto& animationIt = m_animations.find(animationId);
    if (animationIt != m_animations.end())
    {
        const auto& channels = animationIt->second.channels;
        for (const auto& channel : channels.Elements())
        {
            if (channel.target.path == targetPath && channel.target.nodeId == nodeId)
            {
                const auto& samplers = animationIt->second.samplers;
                const auto& sampler = samplers[channel.samplerId];

                size_t lowerFrameIndex = 0;
                size_t upperFrameIndex = 0;
                std::pair<float, float> inputTimes = GetKeyFrameTimes(sampler.inputAccessorId, currentTime, lowerFrameIndex, upperFrameIndex);

                size_t numOutputValueElements = (sampler.interpolation == Microsoft::glTF::INTERPOLATION_CUBICSPLINE) ? 3 : 1;
                std::vector<float> outputValues;

                if (targetPath == Microsoft::glTF::TargetPath::TARGET_WEIGHTS)
                {
                    GetKeyFrameWeights(sampler.outputAccessorId, lowerFrameIndex, upperFrameIndex, outputValues, numOutputValueElements);
                }
                else
                {
                    throw Spectre::Utils::SpectreInvalidArgException("Evaluate() -- only WEIGHTS target type is supported for the std::vector<float> specialization");
                }

                if (lowerFrameIndex == upperFrameIndex)
                {
                    result.push_back(outputValues[(sampler.interpolation == Microsoft::glTF::INTERPOLATION_CUBICSPLINE) ? 1 : 0]);
                }
                else
                {
                    uint32_t keyFrameDimension = uint32_t(m_outputAccessors[sampler.outputAccessorId].numMorphTargets);
                    result = InterpolateWeights(sampler.interpolation, currentTime, inputTimes, outputValues, keyFrameDimension);
                }
                return true;
            }
        }
    }
    else
    {
        throw Spectre::Utils::SpectreInvalidArgException("Evaluate() -- invalid animationId specified");
    }

    return false;
}
