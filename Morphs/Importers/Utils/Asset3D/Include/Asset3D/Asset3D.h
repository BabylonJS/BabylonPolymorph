/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <vector>

#include <Asset3D/Animation.h>
#include <Asset3D/SceneNode.h>
#include <CoreUtils/BabylonSDK.h>
#include <CoreUtils/GLTFChannelAnimations.h>
#include <CoreUtils/GLTFSkins.h>

namespace Babylon
{
    namespace Transcoder
    {
        /// \brief
        /// Asset3D is a single central 3D scene representation which can serve as the basis for
        /// an 3D conversion pipeline.
        ///
        /// OVERVIEW
        /// --------
        /// An Asset3D is root SceneNode of a hierarchy representing a 3D scene. An Asset3D can be created
        /// programatically by adding child nodes (SceneNode::CreateChildNode) and meshes
        /// (SceneNode::SetMesh), or it can be imported from a number of supported formats
        /// using the global function:
        ///
        /// - Babylon::Transcoder::Import
        ///
        /// Once imported/created, the asset can be operated on by an IAsset3DProcessor (e.g, an implementation
        /// of IAsset3DProcessor might extract metadata from the Asset3D). When the asset has been conditioned
        /// appropriately, it can be exported to a number of supported formats using the global function:
        ///
        /// - Babylon::Transcoder::Export
        ///
        /// A simple use-case of Asset3D would be to convert a 3D model from one format to another 
        /// by directly exporting an imported Asset3D.
        ///
        /// UNITS & AXIS SYSTEMS
        /// --------------------
        ///
        /// Where meaningful, Asset3D assumes that uses a left-handed
        /// coordinate system (Y is up, X is right, and Z is 'away').
        ///
        /// For several import/export formats (e.g. OBJ and STL), units and axis systems are unspecified.
        /// By default the above conversions will lost unit when convert from formats that has unit to
        /// formats that has no unit.

        class Asset3D : public SceneNode
        {
        public:
            using UnitInCentimeter = float; // TODO: Should this be double?

            static constexpr UnitInCentimeter SYSTEMUNIT_NONE       =      0.0f; /* Must be checked before unit conversion */

            static constexpr UnitInCentimeter SYSTEMUNIT_MICROMETER =      0.0001f;
            static constexpr UnitInCentimeter SYSTEMUNIT_MILLIMETER =      0.1f;
            static constexpr UnitInCentimeter SYSTEMUNIT_CENTIMETER =      1.0f;
            static constexpr UnitInCentimeter SYSTEMUNIT_DECIMETER  =     10.0f;
            static constexpr UnitInCentimeter SYSTEMUNIT_METER      =    100.0f;
            static constexpr UnitInCentimeter SYSTEMUNIT_KILOMETER  = 100000.0f;

            static constexpr UnitInCentimeter SYSTEMUNIT_INCH       =      2.54f;
            static constexpr UnitInCentimeter SYSTEMUNIT_FOOT       =     30.48f;
            static constexpr UnitInCentimeter SYSTEMUNIT_YARD       =     91.44f;
            static constexpr UnitInCentimeter SYSTEMUNIT_MILE       = 160934.4f;

            Asset3D();
            virtual ~Asset3D() = default;

            /// Calculates the Bounding Box of the Asset3D at the given transform.
            /// @param[in] transform The transform can be additional transformation to apply or identity matrix.
            virtual BoundingBox CalcTopDownBounds(const Babylon::Utils::Math::Matrix& transform) const override;

            //----------------------------------------------------------
            /// Support for model metadata.  Currently this only reports anim info but can be expanded if necessary.
            /// There is a C# interop counterpart to this struct that should be kept in sync with this declaration.
            /// (Search for ModelMetadata)
            //  Customer for this is Remix
            struct ModelMetadata
            {
                uint32_t numAnimations;
                uint32_t numSkinnedSkeletons;
            };

            ModelMetadata BABYLON_SDK_CALL GetMetadata() const
            {
                ModelMetadata metadata;
                metadata.numAnimations = static_cast<uint32_t>(m_anims.size());
                metadata.numSkinnedSkeletons = static_cast<uint32_t>(m_skeletons.size());
                return metadata;
            }

            // Legacy skinned animations
            void AddAnimation(Animation::SkeletalAnimation&& animation) { m_anims.push_back(std::move(animation)); }
            const std::vector<Animation::SkeletalAnimation>& GetAnimations() const { return m_anims; }
            void SetAnimations(std::vector<Animation::SkeletalAnimation>&& anims) { m_anims = std::move(anims); }

            // Skeletons
            void AddSkeleton(Animation::Skeleton&& skeleton) { m_skeletons.push_back(std::move(skeleton)); }
            const std::vector<Animation::Skeleton>& GetSkeletons() const { return m_skeletons; }
            void SetSkeletons(std::vector<Animation::Skeleton>&& skeletons) { m_skeletons = std::move(skeletons); }

            // Channel animations
            void SetChannelAnimations(std::shared_ptr<GLTFChannelAnimations> channelAnims) { m_channelAnimations = std::move(channelAnims); }
            const std::shared_ptr<GLTFChannelAnimations>& GetChannelAnimations() const { return m_channelAnimations; }
            bool HasChannelAnimations() const { return static_cast<bool>(m_channelAnimations); }

            // Skins
            void SetSkins(std::shared_ptr<GLTFSkins> skins) { m_skins = std::move(skins); }
            const std::shared_ptr<GLTFSkins>& GetSkins() const { return m_skins; }
            bool HasSkins() const { return static_cast<bool>(m_skins); }

            // SystemUnit/Scale
            UnitInCentimeter GetSystemUnit() const { return m_systemUnit; };
            void SetSystemUnit(UnitInCentimeter unit) { m_systemUnit = unit; }
            Utils::Math::Matrix GetUnitScaledTransform(UnitInCentimeter unit) const;

            static float CalculateConversionScale(UnitInCentimeter origUnit, UnitInCentimeter DestUnit);

        protected:
            // Legacy skeletal animation system support.
            std::vector<Animation::Skeleton>                m_skeletons;
            std::vector<Animation::SkeletalAnimation>       m_anims;

            UnitInCentimeter                                m_systemUnit = SYSTEMUNIT_NONE;

            // GLTF animation transcoding support
            std::shared_ptr<GLTFChannelAnimations>          m_channelAnimations;
            std::shared_ptr<GLTFSkins>                      m_skins;
        };

        using Asset3DPtr = std::shared_ptr<Asset3D>;
    }
}
