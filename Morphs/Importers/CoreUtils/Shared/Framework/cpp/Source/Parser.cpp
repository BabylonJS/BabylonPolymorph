/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/Frame.h>
#include <Framework/Parser.h>
#include <Framework/FormatWriterUtils.h>

DEFINE_TRACE_AREA(Parser, 0);

namespace SU = Spectre::Utils;

namespace Spectre
{
    namespace Engine
    {
        namespace
        {
            const int cMaxExtensionHeaderCount = 32;

            // Validate the TextureSegment
            bool ValidateTexture(SafeBXFReader<Spectre::Framework::TextureSegmentLittleEndian> textureReader)
            {
                auto texture = textureReader.Item();
                // Skip versions we don't support
                if (texture->Version != Spectre::Framework::TextureSegment::kVersion0)
                {
                    //if COOL format is different
                    TRACE_IMPORTANT(Parser, "Incorrect COOL format. Please update your COOL files");
                    return false;
                }

                if (texture->Format >= Spectre::Framework::TextureSegment::kFormatCount)
                    throw SU::SpectreInvalidArgException("Parser: Texture with invalid format");

                // Validate flags

                const uint32_t allFlags = Spectre::Framework::TextureSegment::kFlag_AlphaValid |
                    Spectre::Framework::TextureSegment::kFlag_TextureHasActiveAlpha;

                if ((texture->Flags & ~allFlags) != 0)
                    throw SU::SpectreInvalidArgException("Parser: Texture with invalid flags");

                // Validate offsets

                if (texture->OffsetData < sizeof(Spectre::Framework::TextureSegmentLittleEndian))
                    throw SU::SpectreInvalidArgException("Parser: TextureData offset underflow");
                textureReader.ValidateOffset(texture->OffsetData);
                textureReader.ValidateOffset(texture->OffsetData + texture->SizeInBytes - sizeof(Spectre::Framework::TextureSegmentLittleEndian));

                return true;
            }

            template<typename SegmentT>
            void ValidateDataBufferRanges(
                SafeBXFReader<SegmentT> segmentReader,
                std::vector<std::pair<uint64_t, uint64_t>> const& dataBufferRanges,
                std::string const& exceptionMsgPreamble)
            {
                for (size_t i = 0; i < dataBufferRanges.size(); i++)
                {
                    auto start = dataBufferRanges[i].first;
                    auto end = dataBufferRanges[i].second;

                    segmentReader.ValidateOffset(start);
                    segmentReader.ValidateOffset(end);

                    // Ensure none of the buffers overlap with the other buffers
                    for (size_t j = i + 1; j < dataBufferRanges.size(); j++)
                    {
                        auto otherStart = dataBufferRanges[j].first;
                        auto otherEnd = dataBufferRanges[j].second;

                        if (start >= otherStart && start < otherEnd)      throw SU::SpectreInvalidArgException(exceptionMsgPreamble+" (a)");
                        else if (end > otherStart && end <= otherEnd)     throw SU::SpectreInvalidArgException(exceptionMsgPreamble+" (b)");
                        else if (otherStart >= start && otherStart < end) throw SU::SpectreInvalidArgException(exceptionMsgPreamble+" (c)");
                        else if (otherEnd > start && otherEnd <= end)     throw SU::SpectreInvalidArgException(exceptionMsgPreamble+" (d)");
                    }
                }
            }

            template<typename SegmentT>
            void ValidateExtensionHeaders(
                SafeBXFReader<SegmentT> segmentReader,
                void const* basePtr,
                uint32_t OffsetToFirstExtensionHeader,
                std::vector<std::pair<uint64_t, uint64_t>>& dataRanges)
            {
                if (OffsetToFirstExtensionHeader == 0)
                {
                    // no extension headers
                    return;
                }

                if (OffsetToFirstExtensionHeader < sizeof(SegmentT))
                {
                    throw SU::SpectreInvalidArgException("Parser: Extension header overlaps segment header");
                }

                uint64_t thisHeaderOffset = OffsetToFirstExtensionHeader;
                int extensionHeaderCount;
                for (extensionHeaderCount = 0; extensionHeaderCount < cMaxExtensionHeaderCount; extensionHeaderCount++)
                {
                    segmentReader.ValidateOffset(thisHeaderOffset);
                    segmentReader.ValidateOffset(thisHeaderOffset + sizeof(Framework::ExtensionHeader));

                    auto extensionHeader = reinterpret_cast<Framework::ExtensionHeaderLittleEndian const*>(uintptr_t(basePtr) + thisHeaderOffset);

                    size_t sizeofExtensionHeeader = 0;
                    switch (extensionHeader->Type)
                    {
                    case Framework::ExtensionHeader::kMeshSkeletonBinding:
                    {
                        sizeofExtensionHeeader = sizeof(Framework::MeshSkeletonBinding);
                        break;
                    }
                    default:
                    {
                        throw SU::SpectreInvalidArgException("Parser: Unrecognised extension header type");
                    }
                    }

                    // validate the extended range encompassing the full ExtensionHeader sub-type
                    segmentReader.ValidateOffset(thisHeaderOffset + sizeofExtensionHeeader);

                    dataRanges.push_back( std::make_pair(thisHeaderOffset, thisHeaderOffset + sizeofExtensionHeeader) );

                    if (extensionHeader->OffsetToNextExtensionHeader == 0)
                    {
                        // no more extension headers
                        break;
                    }

                    if (extensionHeader->OffsetToNextExtensionHeader != sizeofExtensionHeeader)
                    {
                        throw SU::SpectreInvalidArgException("Parser: Extension headers are not packed contiguously");
                    }

                    thisHeaderOffset += sizeofExtensionHeeader;
                }

                if (extensionHeaderCount == cMaxExtensionHeaderCount)
                {
                    throw SU::SpectreInvalidArgException("Parser: Extension header limit exceeded");
                }
            }

            // Validate the mesh segment, ensuring fields don't contain any corrupt values, and
            // offsets don't overflow any buffers.
            void ValidateMesh(SafeBXFReader<Spectre::Framework::MeshSegmentLittleEndian> meshReader)
            {
                auto mesh = meshReader.Item();

                std::vector<std::pair<uint64_t, uint64_t>> meshData;
                meshData.reserve(10 + cMaxExtensionHeaderCount);

                // flags
                const uint16_t flags = mesh->GetFlags();

                // Validate format mask

                const uint32_t formatMask = mesh->GetFormatMask();
                if ((formatMask & ~Framework::MeshSegment::kFormatMaskAllFlags) != 0)
                    throw SU::SpectreInvalidArgException("Parser: Invalid format mask in mesh");
                if ((formatMask & Framework::MeshSegment::kHasBigIndices) != 0 &&
                    (formatMask & Framework::MeshSegment::kHasIndices) != 0)
                {
                    throw SU::SpectreInvalidArgException("Parser: Invalid format mask in mesh - can't have both small and big indices");
                }

                // Validate the index buffer

                uint64_t numIndices = mesh->GetNumIndices();
                if (numIndices == 0)
                    throw SU::SpectreInvalidArgException("Parser: Found invalid mesh no indices");
                if ((numIndices % 3) != 0)
                    throw SU::SpectreInvalidArgException("Parser: Found invalid mesh with invalid index count");

                uint64_t indexEnd = 0;
                if (formatMask & Framework::MeshSegment::kHasBigIndices)
                    indexEnd = (uint64_t)(sizeof(uint32_t) * numIndices + mesh->OffsetIndices);
                else if (formatMask & Framework::MeshSegment::kHasIndices)
                    indexEnd = (uint64_t)(sizeof(uint16_t) * numIndices + mesh->OffsetIndices);
                else
                    throw SU::SpectreInvalidArgException("Parser: Invalid format mask - no index flag");

                meshData.push_back( std::make_pair(mesh->OffsetIndices, indexEnd) );

                // Validate extension headers

                ValidateExtensionHeaders(meshReader, mesh, mesh->OffsetToFirstExtensionHeader, meshData);

                // Validate vertex buffer

                uint64_t numVertices = mesh->GetNumVertices();
                if (numVertices == 0)
                    throw SU::SpectreInvalidArgException("Parser: Found invalid mesh no vertices");
                meshData.push_back (std::make_pair(mesh->OffsetPos, mesh->OffsetPos + sizeof(float) * 3 * numVertices));

                if ((formatMask & Framework::MeshSegment::kHasColor) && (flags & Framework::MeshSegment::Flags::kDisplayVertexColors))
                {
                    meshData.push_back (std::make_pair(mesh->OffsetColors, mesh->OffsetColors + sizeof(uint32_t) * numVertices));
                }

                if (formatMask & Framework::MeshSegment::kHasNormals)
                {
                    meshData.push_back (std::make_pair(mesh->OffsetNormals, mesh->OffsetNormals + sizeof(float) * 3 * numVertices));
                }

                if (formatMask & Framework::MeshSegment::kHasTangents)
                {
                    meshData.push_back (std::make_pair(mesh->OffsetTangents, mesh->OffsetTangents + sizeof(float) * 4 * numVertices));
                }

                if (formatMask & Framework::MeshSegment::kHasUV0)
                {
                    meshData.push_back (std::make_pair(mesh->OffsetUV0, mesh->OffsetUV0 + sizeof(float) * 2 * numVertices));
                }

                if (formatMask & Framework::MeshSegment::kHasUV1)
                {
                    meshData.push_back (std::make_pair(mesh->OffsetUV1, mesh->OffsetUV1 + sizeof(float) * 2 * numVertices));
                }

                ValidateDataBufferRanges(meshReader, meshData, "ValidateMesh: Overlapping data buffers in mesh.");
            }
        }

        // Validate the mesh instance segment, ensuring certain expected fields are set and that
        // the mesh referred to by this intance exists
        void ValidateInstance(SafeBXFReader<Spectre::Framework::MeshInstanceSegmentLittleEndian> instanceReader, const std::vector<uint32_t>& loadedMeshIDs)
        {
            auto instance = instanceReader.Item();

            if (instance->GetIsPrimitive() == false)
            {
                if (std::find(loadedMeshIDs.begin(), loadedMeshIDs.end(), instance->SourceMeshID) == loadedMeshIDs.end())
                {
                    throw SU::SpectreInvalidArgException("Parser: Mesh instance does not refer to an existing mesh");
                }
            }
        }

        // Validate the skeleton segment, ensuring fields don't contain any corrupt values, and
        // offsets don't overflow any buffers.
        void ValidateSkeleton(SafeBXFReader<Spectre::Framework::SkeletonSegmentLittleEndian> skelReader)
        {
            auto skel = skelReader.Item();

            size_t sizeOfSkel = sizeof(Spectre::Framework::SkeletonSegmentLittleEndian) + skel->NumJoints * sizeof(Spectre::Framework::SkeletonSegmentLittleEndian::Joint);

            if (skel->NumJoints == 0)
                throw SU::SpectreInvalidArgException("Parser: Found invalid skeleton - no joints");

            skelReader.ValidateOffset(sizeOfSkel);

            for (size_t i = 0; i < skel->NumJoints; i++)
            {
                auto parentIndex = skel->JointData[i].GetParentJointIndex();
                if (parentIndex >= 0)
                {
                    if (size_t(parentIndex) >= i)
                    {
                        throw SU::SpectreInvalidArgException("Parser: Parent doesn't precede child in skeleton data");
                    }
                }
                else if (parentIndex != -1)
                {
                    // -1 is used to denote root/no parent
                    throw SU::SpectreInvalidArgException("Parser: Invalid negative parent index in skeleton data");
                }
            }
        }

        // Validate the animation segment, ensuring fields don't contain any corrupt values, and
        // offsets don't overflow any buffers.
        void ValidateAnimation(SafeBXFReader<Spectre::Framework::AnimationSkinnedLittleEndian> animReader, std::map<uint32_t, size_t> const& skeletonJointCounts, bool strictValidation)
        {
            SpectreUnusedParameter(strictValidation);

            typedef Spectre::Framework::AnimationSkinned SFA;

            auto anim = animReader.Item();

            if(anim->ChunkCount == 0)
            {
                throw SU::SpectreInvalidArgException("Parser: Found invalid animation - no chunks");
            }

            if(anim->SkeletonID == 0)
            {
                throw SU::SpectreInvalidArgException("Parser: Found invalid animation - no linked skeleton");
            }

            if(skeletonJointCounts.find(anim->SkeletonID) == skeletonJointCounts.end())
            {
                throw SU::SpectreInvalidArgException("Parser: Found invalid animation - linked skeleton could not be found");
            }

            size_t linkedSkeletonJointCount = skeletonJointCounts.at(anim->SkeletonID);

            size_t expectedSizeSoFar = sizeof(*anim) + anim->ChunkCount * sizeof(SFA::ChunkHeader);
            animReader.ValidateOffset(expectedSizeSoFar);

            std::vector<std::pair<uint64_t, uint64_t>> dataBufferRanges;
            std::vector<Spectre::Framework::AnimationSkinnedLittleEndian::ChunkHeaderLittleEndian const*> fixedTimeStepChunks;

            uint64_t chunkTypeBits = 0;

            for (uint16_t j = 0; j < anim->ChunkCount; j++)
            {
                auto chunkHeader = &anim->ChunkHeaders[j];
                animReader.ValidateOffset(chunkHeader->ChunkDataOffset);
                animReader.ValidateChunkType(chunkHeader->ChunkType);

                uint64_t chunkTypeMask = (1ull << chunkHeader->ChunkType);
                chunkTypeBits |= chunkTypeMask;
                if (chunkTypeBits != chunkTypeMask)
                {
                    // We might want to relax this restriction in future, but for now we have no need
                    throw SU::SpectreInvalidArgException("ValidateAnimation: Mixture of ChunkTypes.");
                }

                switch (SFA::EChunkType(chunkHeader->ChunkType))
                {
                case SFA::kFixedTimeStep:
                {
                    animReader.ValidateOffset(chunkHeader->ChunkDataOffset + sizeof(SFA::FixedTimeStepChunk));
                    animReader.ValidateAlignment<Spectre::Framework::AnimationSkinnedLittleEndian::FixedTimeStepChunkLittleEndian>(chunkHeader->ChunkDataOffset);
                    auto fixedTimeStepChunkData = chunkHeader->GetChunkData<Spectre::Framework::AnimationSkinnedLittleEndian::FixedTimeStepChunkLittleEndian>();

                    auto chunkHeaderOffset = uintptr_t(chunkHeader) - uintptr_t(anim);

                    auto start = chunkHeaderOffset + chunkHeader->ChunkDataOffset;
                    auto end = chunkHeaderOffset + chunkHeader->ChunkDataOffset + fixedTimeStepChunkData->GetChunkDataSize();
                    dataBufferRanges.push_back (std::pair<uint64_t, uint64_t>(start, end));

                    fixedTimeStepChunks.push_back(chunkHeader);
                    break;
                }
                default:
                {
                    SpectreAssert(false);
                }
                }
            }

            ValidateDataBufferRanges(animReader, dataBufferRanges, "ValidateAnimation: Overlapping data buffers in animation.");

            // Data ranges have all been checked. Now check the actual data:

            for(size_t j=0; j<fixedTimeStepChunks.size(); j++)
            {
                auto chunkHeader = fixedTimeStepChunks[j];
                auto chunkData = chunkHeader->GetChunkData<Spectre::Framework::AnimationSkinnedLittleEndian::FixedTimeStepChunkLittleEndian>();

                // check that chunks have frames
                if(chunkData->FrameCount == 0)
                {
                    throw SU::SpectreInvalidArgException("ValidateAnimation: FixedTimeStepChunk has no frames.");
                }
                // check that joint index is within bounds
                if(chunkData->JointIndex >= linkedSkeletonJointCount)
                {
                    throw SU::SpectreInvalidArgException("ValidateAnimation: FixedTimeStepChunk joint index overflows skeleton joint count.");
                }
            }
        }

        //--------------------------------------------------------------------------------------
        Parser::Parser(MeshProcess processMeshCB,
                       TextureProcess processTextureCB,
                       MaterialProcess processMaterialCB,
                       LightProcess processLightCB,
                       SceneNodeProcess processSceneNodeCB,
                       SkeletonProcess processSkeletonCB,
                       SceneProcess processSceneCB,
                       AnimationSkinnedProcess processAnimationSkinnedCB,
                       MeshInstanceProcess processInstanceCB,
                       bool strictValidation) :
            m_meshCB(processMeshCB),
            m_textureCB(processTextureCB),
            m_materialCB(processMaterialCB),
            m_lightCB(processLightCB),
            m_sceneNodeCB(processSceneNodeCB),
            m_skeletonCB(processSkeletonCB),
            m_animationSkinnedCB(processAnimationSkinnedCB),
            m_instanceCB(processInstanceCB),
            m_sceneCB(processSceneCB),
            m_strictValidation(strictValidation)
        {
        }

        //--------------------------------------------------------------------------------------

        void Parser::Parse(
            const void* buffer,
            uint32_t bufferSizeInBytes,
            _Out_ uint32_t& incompleteFrameOffset,
            _Out_ uint32_t& incompleteFrameSize,
            void* userData,
            FrameLODComplete frameLODComplete)
        {
            // Incomplete frame information defaults
            incompleteFrameOffset = UINT32_MAX;
            incompleteFrameSize = UINT32_MAX;

            auto src = reinterpret_cast<const uint8_t*>(buffer);
            uint32_t idx = 0;

            while (idx < bufferSizeInBytes)
            {
                // If we can't read a full header we need to write the current offset but an
                // unknown size to the out params
                const size_t frameHeaderToSizeNumBytes = sizeof(Spectre::Framework::FrameLittleEndian);
                if ((bufferSizeInBytes - idx) < frameHeaderToSizeNumBytes)
                {
                    incompleteFrameOffset = idx;
                    return;
                }

                auto frame = reinterpret_cast<const Framework::FrameLittleEndian*>(&src[idx]);
                uint32_t bytesToSkip = 0;

                if (frame->Marker == Framework::kFrameMarker &&
                    frame->Signature == Framework::kFrameSignature)
                {
                    // If we have an incomplete frame payload, skip the parse
                    if ((bufferSizeInBytes - idx) < frame->SizeInBytes)
                    {
                        incompleteFrameOffset = idx;
                        incompleteFrameSize = frame->SizeInBytes;
                        return;
                    }

                    if (frame->GetSizeInBytes() < sizeof(frameHeaderToSizeNumBytes))
                    {
                        // Invalid frame size
                        throw SU::SpectreInvalidArgException("Parser: BXF FrameSize is invalid");
                    }

                    switch (frame->GetVersion())
                    {
                        case Framework::kFrameVersion1:
                            bytesToSkip = ParseFrame_V0(SafeBXFReader<Spectre::Framework::FrameLittleEndian>(frame, bufferSizeInBytes), userData, frameLODComplete);
                            break;

                        default:
                            //if COOL format is different
                            throw SU::SpectreInvalidArgException("Parser: Unknown Frame version");
                    }
                }
                else
                {
                    return; // Not a valid frame
                }
                idx += bytesToSkip;
            }
        }

        //--------------------------------------------------------------------------------------

        void Parser::ParseFrame_V0_SceneSegment(const Framework::FrameLittleEndian* pFrame, uint32_t sizeInBytes, void* pUserData)
        {
            for (uint32_t i = 0; i < pFrame->GetNumItems(); i++)
            {
                const Framework::SceneItemCommonHeader* pItem = pFrame->GetItemByIndex<Framework::SceneItemCommonHeader>(i);
                SpectreAssert(pItem != nullptr);

                // Skip versions we don't support
                if (pItem->Version != Spectre::Framework::SceneDefinition::kVersion0)
                {
                    //if COOL format is different
                    TRACE_IMPORTANT(Parser, "Incorrect COOL format. Please update your COOL files");
                    continue;
                }

                switch (pItem->Type)
                {
                    case Framework::SceneItemCommonHeader::ESceneItemType::kScene:
                    {
                        auto scene = static_cast<const Framework::SceneSegmentLittleEndian*>(pItem);
                        SpectreAssert(scene->IsValid());
                        SpectreUnusedLocal(scene);
                        if (m_sceneCB)
                        {
                            m_sceneCB(scene, sizeInBytes, pUserData);
                        }
                    }
                    break;

                    case Framework::SceneItemCommonHeader::ESceneItemType::kLight:
                    {
                        auto light = static_cast<const Framework::LightSegmentLittleEndian*>(pItem);
                        SpectreAssert(light->IsValid());
                        SpectreUnusedLocal(light);
                        if(m_lightCB)
                        {
                            m_lightCB(light, sizeInBytes, pUserData);
                        }
                    }
                    break;

                    case Framework::SceneItemCommonHeader::ESceneItemType::kCamera:
                    {
                        auto camera = static_cast<const Framework::CameraSegmentLittleEndian*>(pItem);
                        SpectreAssert(camera->IsValid());
                        SpectreUnusedLocal(camera);
                        // For future expansion: the camera loading callback should be called here
                        // m_cameraCB(camera, pUserData);
                    }
                    break;
                }
            }
        }

        //--------------------------------------------------------------------------------------

        void Parser::ParseFrame_V0_MeshSegment(SafeBXFReader<Spectre::Framework::MeshBaseSegment> reader, void* pUserData)
        {
            auto header = reader.Item();

            // Skip versions we don't support
            if (header->Version != Spectre::Framework::MeshBaseSegment::kVersion0)
            {
                //if COOL format is different
                throw SU::SpectreInvalidArgException("Parser: Invalid mesh version");
            }

            switch (header->Type)
            {
            case Spectre::Framework::MeshBaseSegment::kTypeGeometry:
            {
                // Mesh geometry
                SafeBXFReader<Spectre::Framework::MeshSegmentLittleEndian> meshReader(header, reader);
                ValidateMesh(meshReader);
                m_loadedMeshIDs.push_back(meshReader.Item()->MeshID);
                if(m_meshCB)
                {
                    m_meshCB(meshReader.Item(), (uint32_t)meshReader.SizeInBytes(), pUserData);
                }
            }break;

            case Spectre::Framework::MeshBaseSegment::kTypeNode:
                // Empty scene node basically...
                if(m_sceneNodeCB)
                {
                    m_sceneNodeCB(static_cast<const Spectre::Framework::NodeSegment*>(header), (uint32_t)reader.SizeInBytes(), pUserData);
                }
                break;

            case Spectre::Framework::MeshBaseSegment::kTypeSkeleton:
            {
                // Skeleton
                SafeBXFReader<Spectre::Framework::SkeletonSegmentLittleEndian> skelReader(header, reader);
                ValidateSkeleton(skelReader);
                if(m_skeletonCB)
                {
                    m_skeletonCB(skelReader.Item(), (uint32_t)skelReader.SizeInBytes(), pUserData);
                }

                auto skel = skelReader.Item();
                m_skeletonJointCounts[skel->MeshID] = skel->GetNumJoints();

            }break;

            case Spectre::Framework::MeshBaseSegment::kTypeInstance:
            {
                SafeBXFReader<Spectre::Framework::MeshInstanceSegmentLittleEndian> instanceReader(header, reader);
                ValidateInstance(instanceReader, m_loadedMeshIDs);
                if (m_instanceCB)
                {
                    m_instanceCB(instanceReader.Item(), (uint32_t)instanceReader.SizeInBytes(), pUserData);
                }
            }break;

            default:
                throw SU::SpectreInvalidArgException("Parser: Invalid mesh type");
            }
        }

        //--------------------------------------------------------------------------------------

        void Parser::ParseFrame_V0_AnimationSegment(SafeBXFReader<Spectre::Framework::AnimationHeader> reader, void* pUserData)
        {
            auto header = reader.Item();

            // Skip versions we don't support
            if (header->Version != Spectre::Framework::AnimationHeader::kVersion0)
            {
                //if COOL format is different
                throw SU::SpectreInvalidArgException("Parser: Invalid animation version");
            }

            switch (header->Type)
            {
            case Spectre::Framework::AnimationHeader::kSkinned:
            {
                // Skinned animation
                SafeBXFReader<Spectre::Framework::AnimationSkinnedLittleEndian> animReader(header, reader);
                ValidateAnimation(animReader, m_skeletonJointCounts, m_strictValidation);
                if (m_animationSkinnedCB)
                {
                    m_animationSkinnedCB(animReader.Item(), (uint32_t)animReader.SizeInBytes(), pUserData);
                }
            }break;

            default:
                throw SU::SpectreInvalidArgException("Parser: Invalid animation type");
            }
        }

        //--------------------------------------------------------------------------------------
        uint32_t Parser::ParseFrame_V0(SafeBXFReader<Spectre::Framework::FrameLittleEndian> reader, void* pUserData, FrameLODComplete frameLODComplete)
        {
            // Is it compressed?

            std::unique_ptr<char[]> workBuffer;
            uint32_t originalFrameSizeInBytes = reader.Item()->GetSizeInBytes();

            auto compression = reader.Item()->GetCompression();
            if (compression != Framework::EFrameCompression::kUncompressed)
            {
                throw SU::SpectreInvalidArgException("Parser: Compression not supported for frame data");
            }

            auto frame = reader.Item();

            // Validate item count and offset array

            uint64_t itemOffsetArraySize = frame->GetNumItems() * sizeof(uint32_t);
            if (itemOffsetArraySize >= (frame->GetSizeInBytes() - sizeof(Framework::FrameUncompressed)))
            {
                throw SU::SpectreInvalidArgException("Parser: Invalid Item Offset array size in Frame");
            }
            for (uint32_t t = 0; t < frame->GetNumItems(); ++t)
            {
                if (frame->Offsets[t] < itemOffsetArraySize - sizeof(uint32_t) + sizeof(Framework::FrameUncompressed))
                    throw SU::SpectreInvalidArgException("Parser: Item Offset underflow in Frame");
            }

            // Validate Quality

            auto quality = frame->GetQuality();
            switch (quality)
            {
            case Spectre::Framework::EFrameQuality::kLow:
            case Spectre::Framework::EFrameQuality::kMedium:
            case Spectre::Framework::EFrameQuality::kHigh:
                break;
            default:
                throw SU::SpectreInvalidArgException("Parser: Invalid Quality Type for frame");
                break;
            };

            Spectre::Framework::EFrameType frameType = (Spectre::Framework::EFrameType)frame->GetType();

            switch (frameType)
            {
            case Spectre::Framework::kFrameGeom:
                for (uint32_t i = 0; i < frame->GetNumItems(); ++i)
                {
                    SafeBXFReader<Spectre::Framework::MeshBaseSegment> meshReader(frame->GetItemByIndex<Spectre::Framework::MeshBaseSegment>(i), reader);
                    ParseFrame_V0_MeshSegment(meshReader, pUserData);
                }
                break;

            case Spectre::Framework::kFrameMetadata:
                // Skip
                break;

            case Spectre::Framework::kFrameAnim:
                for (uint32_t i = 0; i < frame->GetNumItems(); ++i)
                {
                    SafeBXFReader<Spectre::Framework::AnimationHeader> animReader(frame->GetItemByIndex<Spectre::Framework::AnimationHeader>(i), reader);
                    ParseFrame_V0_AnimationSegment(animReader, pUserData);
                }
                break;

            case Spectre::Framework::kFrameTexture:
                for (uint32_t i = 0; i < reader.Item()->GetNumItems(); ++i)
                {
                    SafeBXFReader<Spectre::Framework::TextureSegmentLittleEndian> textureReader(
                        frame->GetItemByIndex<Spectre::Framework::TextureSegmentLittleEndian>(i), reader);
                    if (ValidateTexture(textureReader) && m_textureCB)
                    {
                        m_textureCB(textureReader.Item(), (uint32_t)reader.SizeInBytes(), pUserData);
                    }
                }
                break;

            case Spectre::Framework::kFrameMaterial:
                for (uint32_t i = 0; i < reader.Item()->GetNumItems(); ++i)
                {
                    const Spectre::Framework::MaterialSegmentLittleEndian* material =
                        reader.Item()->GetItemByIndex<Spectre::Framework::MaterialSegmentLittleEndian>(i);

                    // Skip versions we don't support
                    if (material->Version != Spectre::Framework::MaterialDefinition::kVersion0)
                    {
                        //if COOL format is different
                        TRACE_IMPORTANT(Parser, "Incorrect COOL format. Please update your COOL files");
                        continue;
                    }
                    if(m_materialCB)
                    {
                        m_materialCB(material, (uint32_t)reader.SizeInBytes(), pUserData);
                    }
                }
                break;

            case Spectre::Framework::kFrameScene:
                ParseFrame_V0_SceneSegment(reader.Item(), (uint32_t)reader.SizeInBytes(), pUserData);
                break;

            default:
                //if COOL format is different
                throw SU::SpectreInvalidArgException("Parser: Invalid Frame Type");
            }

            if (frameLODComplete != nullptr)
            {
                frameLODComplete(frameType, quality);
            }

            return originalFrameSizeInBytes;
        }

    } // namespace Engine

} // namespace Spectre
