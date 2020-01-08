/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <utility>
#include <vector>
#include <string>

#include <CoreUtils/EnumFlagSet.h>
#include <CoreUtils/Math/SimpleMath.h>
#include <CoreUtils/SpectreSDK.h>

#include <Asset3D/ITraversable.h>

namespace Spectre
{
    namespace Transcoder
    {
        namespace Animation
        {
            // Note, this may be assumed to be 4 by code that assumes
            // sizeof(uint8_t [kNUMBER_OF_BONES_PER_VERTEX]) == sizeof(uint32_t)
            // change with care.
            enum class Constants { NUMBER_OF_BONES_PER_VERTEX = 4 };
            static_assert(static_cast<size_t>(Constants::NUMBER_OF_BONES_PER_VERTEX) == sizeof(uint32_t), "Some code may assume we can cast to / from uint32 types");
            using TimeRange = std::pair<double, double>;
            using Weight = std::uint8_t;
            using BoneIndex = std::uint8_t;
            using Weights = Weight[static_cast<size_t>(Constants::NUMBER_OF_BONES_PER_VERTEX)];
            using BoneIndexes = BoneIndex[static_cast<size_t>(Constants::NUMBER_OF_BONES_PER_VERTEX)];

            struct Joint
            {
                using Matrix = Spectre::Utils::Math::Matrix;

                Joint(std::string name = std::string(), int parentJointIndex = -1)
                    : m_Name(std::move(name)),
                    m_ParentJointIndex(parentJointIndex)
                {}

                std::string m_Name;
                int         m_ParentJointIndex = -1;                ///< Index of parent joint (or -1 if this joint has no parent). A joint's parent must precede it in the Joints list.
                Matrix      m_InvBindPose{ Matrix::Identity };      ///< The inverse bind pose for this joint (used for calculating the vertex skinning transform)
                Matrix      m_LocalTransform{ Matrix::Identity };   ///< The default local transform of this joint (used when a joint is missing animation data)
                void*       m_uniqueId = nullptr;                   ///< taken from the FbxNode, but anything unique will do
                uint32_t    m_sceneNodeId = 0;                      ///< ID of the Asset3D scene node associated with this joint
            };

            using SkeletonID = unsigned;
            const static SkeletonID NullSkeletonID = static_cast<SkeletonID>(-1);
            struct Skeleton
            {
                std::string                             m_name;
                std::vector<Joint>                      m_joints;
                const Skeleton& operator=(const Skeleton& other)
                {
                    m_joints = other.m_joints;
                    return *this;
                }
            };

            // Represent an animation rot/trans/scale at single point in time
            struct MotionState
            {
                MotionState() :
                    trans(Utils::Math::Vector3::Zero),
                    rot(Utils::Math::Quaternion::Identity),
                    scale(Utils::Math::Vector3::One)
                {}

                MotionState(const Spectre::Utils::Math::Vector3& t,
                    const Spectre::Utils::Math::Quaternion& r,
                    const Spectre::Utils::Math::Vector3& s)
                    :trans(t), rot(r), scale(s) {}
                Spectre::Utils::Math::Vector3       trans;
                Spectre::Utils::Math::Quaternion    rot;
                Spectre::Utils::Math::Vector3       scale;
            };

            // JointAnim defines the animation for a particular joint
            struct JointAnim
            {
                SkeletonID                  m_skeletonId;           ///< Id of the skeleton this joint belongs to
                uint32_t                    m_skeletonJointIndex;   ///< Index of the joint in the skeleton
                std::vector<double>         m_keyframeTimes;        ///< associated time values for each keyframe in the list below
                std::vector<MotionState>    m_keyframeValues;       ///< a sequence of scale/rot/trans values, for a single node, in a single animation
            };

            //  Metadata flags
            enum class eMetadataFlags : uint32_t
            {
                kNone = 0x00000000,
                kMorphAnimationFound = 0x00000001,     // Morph animation data was detected on load
                kMorphAnimationLoaded = 0x00000002,     // Morph animation data is supported, loaded and will be propagated
                kNodeAnimationFound = 0x00000004,     // Node animation data was detected on load
                kNodeAnimationLoaded = 0x00000008,     // Node animation data is supported, loaded and will be propagated
                kSkeletonAnimationFound = 0x00000010,     // Skeletal animation data was detected on load
                kSkeletonAnimationLoaded = 0x00000020      // Skeletal animation data is supported, loaded and will be propagated
            };
            using MetadataFlags = Utils::EnumFlagSet<eMetadataFlags>;

            class SkeletalAnimation: public ITraversableWithName
            {
            public:
                SkeletalAnimation()
                    : SkeletalAnimation(std::vector<JointAnim>(), {0,0})
                {}
                SkeletalAnimation(std::vector<JointAnim>&& jointKeyFrames, TimeRange timeRange)
                    : ITraversableWithName()
                    , m_jointKeyframes(std::move(jointKeyFrames))
                    , m_timeSpan(timeRange)
                    , m_metadataFlags(eMetadataFlags::kNone)
                {}

                bool SPECTRESDK_CALL IsSupported() const { return m_metadataFlags.Test(eMetadataFlags::kSkeletonAnimationLoaded); }
                bool SPECTRESDK_CALL IsMissingData() const { return m_metadataFlags.Test(eMetadataFlags::kMorphAnimationFound) ||
                                                                    m_metadataFlags.Test(eMetadataFlags::kNodeAnimationFound); }

                std::vector<JointAnim>  m_jointKeyframes; // one per joint
                TimeRange               m_timeSpan;
                MetadataFlags           m_metadataFlags;
            };

            struct NodeAnimation
            {
                // ASSUMES: linear interpolation of keyframes due to
                // how we sample animation values from FBX anim curves
                std::vector<double>         m_keyframeTimes;
                std::vector<MotionState>    m_keyframeValues;
                TimeRange                   m_timeSpan;
                std::string                 m_name;
            };
        }
    }
}
