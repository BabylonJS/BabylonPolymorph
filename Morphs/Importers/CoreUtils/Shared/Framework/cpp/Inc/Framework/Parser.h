/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Frame.h>
#include <Framework/MeshSegment.h>
#include <Framework/TextureSegment.h>
#include <Framework/AnimationSegment.h>
#include <Framework/MaterialSegment.h>

#include <CoreUtils/SpectreSDK.h>

namespace SU = Spectre::Utils;

namespace Spectre
{
    namespace Engine
    {
        // <summary>
        // Template class which provides safeguards for code parsing raw BXF streams. It's main purpose is to
        // ensure that all accesses are within bounds.
        // </summary>
        template <typename T>
        class SafeBXFReader
        {
        protected:

            // NOTE: We explicitly want these to be 64 bit values. This allows the class to be safe if adding 2 32 bit numbers both of
            // which max_int (0xFFFFFFFF). Otherwise they would wrap and could cause security issues/errors in parsing
            const T* m_type;
            uint64_t m_base;
            uint64_t m_size;
        public:
            SafeBXFReader(const void* buffer, uint64_t bufferSizeInBytes) :
                m_type(static_cast<const T*>(buffer)),
                m_base((uint64_t)buffer),
                m_size(bufferSizeInBytes)
            {
                if (buffer == nullptr)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - NULL buffer");
                if (sizeof(T) > bufferSizeInBytes)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - Sizeof Type exceeds buffer size");
            }

            template<typename U>
            SafeBXFReader(const void* buffer, const SafeBXFReader<U>& parentBuffer) :
                m_type(static_cast<const T*>(buffer)),
                m_base((uint64_t)buffer)
            {
                if (buffer == nullptr)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - NULL buffer");
                if (m_base < parentBuffer.Base())
                    throw SU::SpectreInvalidArgException("SafeBXFReader - child buffer is outside parent buffer");
                if (m_base >= parentBuffer.Base() + parentBuffer.SizeInBytes())
                    throw SU::SpectreInvalidArgException("SafeBXFReader - child buffer is outside parent buffer");

                m_size = parentBuffer.SizeInBytes() - (m_base - parentBuffer.Base());

                if (sizeof(T) > m_size)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - Sizeof Type exceeds buffer size");
            }

            inline const T* Item() const { return m_type; }
            inline uint64_t SizeInBytes() const { return m_size; }
            inline uint64_t Base() const { return m_base; }

            template <typename OffsetType>
            const OffsetType* GetRelativeBuffer(uint32_t offset, uint64_t bufferSize, const std::string& errMessage) const
            {
                uint64_t bufferOffset = m_base + offset;

                if (bufferSize == 0)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - zero sized buffer : " + errMessage);
                if (bufferOffset + bufferSize > (m_base + m_size))
                    throw SU::SpectreInvalidArgException("SafeBXFReader - bufferOffset overflow : " + errMessage);

                return reinterpret_cast<const OffsetType*>(bufferOffset);
            }

            template <typename MemberType>
            void ValidateAlignment(uint64_t offset) const
            {
                if (offset % alignof(MemberType) != 0)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - invalid alignment");
            }

            void ValidateOffset(uint64_t offset) const
            {
                if (offset == 0)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - relativeOffset size 0");
                if (offset > m_size)
                    throw SU::SpectreInvalidArgException("SafeBXFReader - relativeOffset overflows buffer size");
            }

            void ValidateChunkType(uint8_t chunkType)
            {
                if(chunkType != static_cast<uint8_t>(Spectre::Framework::AnimationSkinned::EChunkType::kFixedTimeStep))
                {
                    throw SU::SpectreInvalidArgException("SafeBXFReader - unknown ChunkType.");
                }
            }
        };

        // <summary>
        // Class used to load data from the Common Object Format. This serves as
        // sample code essentially, showing how easy it is to parse the format
        // Strict validation can be enabled to enable additional correctness checks for things which don't impinge on app safety
        // </summary>
        class Parser
        {
        public:
            using MeshProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::MeshSegmentLittleEndian*, uint32_t, void*)>;
            using SceneNodeProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::NodeSegment*, uint32_t, void*)>;
            using TextureProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::TextureSegmentLittleEndian*, uint32_t, void*)>;
            using MaterialProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::MaterialSegmentLittleEndian*, uint32_t, void*)>;
            using LightProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::LightSegmentLittleEndian*, uint32_t, void*)>;
            using SkeletonProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::SkeletonSegment*, uint32_t, void*)>;
            using AnimationSkinnedProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::AnimationSkinned*, uint32_t, void*)>;
            using MeshInstanceProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::MeshInstanceSegmentLittleEndian*, uint32_t, void*)>;
            using SceneProcess = std::function<void SPECTRESDK_CALL (const Spectre::Framework::SceneSegmentLittleEndian*, uint32_t, void*)>;
            using FrameLODComplete = std::function<void SPECTRESDK_CALL (Spectre::Framework::EFrameType frameType, Spectre::Framework::EFrameQuality quality)>;

            // Constructor for Transcoder and others that need unit conversion (scene process)
            Parser(MeshProcess processMeshCB,
                TextureProcess processTextureCB,
                MaterialProcess processMaterialCB,
                LightProcess processLightCB,
                SceneNodeProcess processSceneNodeCB,
                SkeletonProcess processSkeletonCB,
                SceneProcess processSceneCB = nullptr,
                AnimationSkinnedProcess processAnimationSkinnedCB = nullptr,
                MeshInstanceProcess processInstanceCB = nullptr,
                bool strictValidation = false);

            /**
             * Parses complete and partial frames given a buffer and its size.
             *
             * \param[in]  buffer                The buffer containing complete or partial frames to parse
             *
             * \param[in]  bufferSizeInBytes     The size of the buffer in bytes
             *
             * \param[out] incompleteFrameOffset UINT32_MAX if there were no incomplete frames in the buffer, otherwise
             *                                   the offset of the incomplete frame is written to the parameter.
             *
             * \param[out] incompleteFrameSize   UINT32_MAX if there were no incomplete frames in the buffer or if the
             *                                   incomplete frame didn't contain the full header. Otherwise, the size of
             *                                   the incomplete frame is written to the parameter.
             *
             * \param[in]  userData              Some arbitrary user data
             */
            void Parse(
                const void* buffer,
                uint32_t bufferSizeInBytes,
                _Out_ uint32_t& incompleteFrameOffset,
                _Out_ uint32_t& incompleteFrameSize,
                void* userData = nullptr,
                FrameLODComplete frameLODComplete = nullptr
                );

        protected:
            void ParseFrame_V0_SceneSegment(const Spectre::Framework::FrameLittleEndian* pFrame, uint32_t sizeInBytes, void* pUserData);

            uint32_t ParseFrame_V0(SafeBXFReader<Spectre::Framework::FrameLittleEndian> reader, void* pUserData, FrameLODComplete frameLODComplete);
            void ParseFrame_V0_MeshSegment(SafeBXFReader<Spectre::Framework::MeshBaseSegment> mesh, void* pUserData);

            void ParseFrame_V0_AnimationSegment(SafeBXFReader<Spectre::Framework::AnimationHeader> anim, void* pUserData);

        protected:
            MeshProcess m_meshCB;
            TextureProcess m_textureCB;
            MaterialProcess m_materialCB;
            LightProcess m_lightCB;
            SceneNodeProcess m_sceneNodeCB;
            SkeletonProcess m_skeletonCB;
            AnimationSkinnedProcess m_animationSkinnedCB;
            MeshInstanceProcess m_instanceCB;
            SceneProcess m_sceneCB;
            bool m_strictValidation = false;

            std::map<uint32_t, size_t> m_skeletonJointCounts;       ///< Skeleton ID -> Skeleton joint count
            std::vector<uint32_t> m_loadedMeshIDs;
        };

    } // namespace Engine
} // namespace Spectre
