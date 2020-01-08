/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <functional>
#include <memory>
#include <vector>

#include <Framework/Vertex.h>
#include <Framework/Frame.h>
#include <Framework/GeometryWriter.h>
#include <Framework/Types.h>

namespace
{
    inline uint32_t GetIndexBufferElementSizeInBytes(uint32_t numVertices)
    {
        return (numVertices >= std::numeric_limits<uint16_t>::max()) ? sizeof(uint32_t) : sizeof(uint16_t);
    }
}

namespace Spectre
{
    namespace Framework
    {
        namespace V1
        {

            class GeometryWriter : public IGeometryWriter, public CommonFrameWriter
            {
            private:
                static const uint32_t sVERSION = 1;

            public:
                GeometryWriter();
                virtual ~GeometryWriter();

                virtual void BeginFrame(
                    std::shared_ptr<IBuffer> const& outputBuffer,
                    uint32_t numMeshes,
                    EByteOrder byteOrder) override;

                virtual void BeginFrame(
                    std::shared_ptr<IBuffer> const& outputBuffer,
                    uint32_t numMeshes,
                    EByteOrder byteOrder,
                    EFrameQuality quality) override;

                virtual Frame* EndFrame() override;

                virtual void BeginMesh(uint32_t meshId, uint32_t parentId = 0, uint32_t materialId = 0, uint32_t skeletonId = 0) override;
                virtual void EndMesh() override;

                virtual void AddJoint(uint32_t id, int parentJointIndex, const float* invBindMatrix, const float* transform) override;

                virtual VertexData LockVertexData(uint32_t numVertices, uint32_t numIndices, uint32_t formatMask, bool areIndices32bit = true) override;
                virtual void UnlockVertexData(const VertexData& data) override;

                virtual void SetSkeletonId(uint32_t skeletonID) override;
                virtual uint32_t GetSkeletonId() const override;
                virtual void SetTransform(_In_reads_(16) const float* transform) override;
                virtual const float* GetTransform() override;
                virtual void SetBoundingBox(_In_reads_(3) const float* center, _In_reads_(3) const float* extents) override;
                virtual void SetFlags(uint32_t flags) override;
                virtual void AddVertex(_In_reads_(numVertices) const Vertex* pVertices, uint32_t numVertices) override;
                virtual void AddIndex(_In_reads_(numIndices) const uint32_t* pIndices, uint32_t numIndices) override;
                virtual uint32_t GetVersion() const override;

                virtual void SetSourceMeshID(uint32_t sourceMeshId) override;
                virtual uint32_t GetVertexBufferSize() const override;
                virtual uint32_t GetIndexBufferSize() const override;
            protected:
                void Reset();
                inline bool IsValidMesh() const { return m_meshId != 0; }

                void EndMeshSegment();
                void EndNodeSegment();
                void EndSkeletonSegment();
                void EndMeshInstanceSegment();

                uint32_t WriteArray(
                    _In_reads_bytes_(numElements*elementSizeInBytes) void* srcArray,
                    uint32_t numElements,
                    uint32_t elementSizeInBytes,
                    std::shared_ptr<IBuffer> const& outputBuffer);
                uint32_t WriteIndexArray(
                    _In_reads_bytes_(numElements * GetIndexBufferElementSizeInBytes(numVertices)) void* srcArray,
                    uint32_t numElements,
                    uint32_t numVertices,
                    std::shared_ptr<IBuffer> const& outputBuffer);
            private:
                GeometryWriter(const GeometryWriter& rhs);
                GeometryWriter& operator=(const GeometryWriter& other);

                enum BufferIDs
                {
                    kBufferPos = 0,
                    kBufferkNormal,
                    kBufferTangent,
                    kBufferColor,
                    kBufferUV0,
                    kBufferUV1,
                    kBufferIndex,
                    kBufferJointIndices,
                    kBufferJointWeights,

                    kNumBuffers //Must be last
                };

                enum IndexType
                {
                    kIndexUnknown = 0,
                    kIndexSmall,
                    kIndexBig
                };

                // Working buffers


                MemoryBuffer m_buffers[kNumBuffers];

                uint32_t m_meshId;
                uint32_t m_materialId;
                uint32_t m_skeletonId;
                uint32_t m_meshParentId;
                uint32_t m_totalVertices;
                uint32_t m_totalIndices;
                IndexType m_indexType;
                float m_transform[16];
                float m_bbox[6];
                uint16_t m_flags;
                bool m_hasBoundingBox;
                uint32_t m_sourceMeshId;
                InstanceType m_instanceType;

                bool m_hasLockedData;                       // True if a caller holds a lock on our data

                bool m_areIndices32bit = true;
                std::vector<SkeletonSegment::Joint> m_joints;
            };

            GeometryWriter::GeometryWriter()
            {
                m_meshId = 0;
                m_meshParentId = 0;
                m_indexType = kIndexUnknown;
                m_totalIndices = 0;
                m_totalVertices = 0;
                m_hasLockedData = false;
                m_instanceType = InstanceType::None;
                m_flags = 0;
            }

            GeometryWriter::~GeometryWriter()
            {
            }

            uint32_t GeometryWriter::GetVersion() const
            {
                return sVERSION;
            }

            void GeometryWriter::Reset()
            {
                this->DoReset();

                m_meshId = 0;
                m_meshParentId = 0;
                m_materialId = 0;
                m_skeletonId = 0;
                m_indexType = kIndexUnknown;
                m_totalIndices = 0;
                m_totalVertices = 0;
                m_frameStartOffset = 0;
                m_hasLockedData = false;
                m_flags = 0;
                m_hasBoundingBox = false;
                m_joints.clear();
                m_instanceType = None;

                memset(m_bbox, 0, sizeof(m_bbox));

                // Reset all buffers
                for (int i = 0; i < kNumBuffers; ++i)
                {
                    m_buffers[i].Reset();
                }
            }

            //---------------------------------------------------------------------
            void GeometryWriter::BeginFrame(
                std::shared_ptr<Spectre::Framework::IBuffer> const& outputBuffer,
                uint32_t numMeshes,
                EByteOrder byteOrder)
            {
                BeginFrame(outputBuffer, numMeshes, byteOrder, EFrameQuality::kHigh);
            }

            void GeometryWriter::BeginFrame(
                std::shared_ptr<Spectre::Framework::IBuffer> const& outputBuffer,
                uint32_t numMeshes,
                EByteOrder byteOrder,
                EFrameQuality quality)
            {
                Reset();
                this->SetFrameQualityLevel(quality);
                this->DoBeginFrame(outputBuffer, numMeshes, byteOrder, kFrameGeom);
            }

            //---------------------------------------------------------------------
            Frame* GeometryWriter::EndFrame()
            {
                if (m_meshId != 0)
                {
                    throw Utils::SpectreFailException("Missing call to EndMesh");
                }

                return this->DoEndFrame();
            }

            //---------------------------------------------------------------------
            void GeometryWriter::BeginMesh(uint32_t meshId, uint32_t parentId, uint32_t materialId, uint32_t skeletonId)
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("GeometryWriter::BeginMesh: You must call BeginFrame first");
                }
                if (m_meshId != 0)
                {
                    throw Utils::SpectreFailException("Call to BeginMesh without a call to EndMesh");
                }
                if (meshId == 0)
                {
                    throw Utils::SpectreInvalidArgException("Invalid meshId of 0 specified");
                }
                SpectreAssertExpr(m_hasLockedData == false, "GeoemtryWriter::BeginMesh - has locked data");

                // Reset all buffers
                for (int i = 0; i < kNumBuffers; ++i)
                {
                    m_buffers[i].Reset();
                }

                // Set transform to identity
                memset(m_transform, 0, sizeof(m_transform));
                m_transform[0] = m_transform[5] = m_transform[10] = m_transform[15] = 1.0f;

                memset(m_bbox, 0, sizeof(m_bbox));

                m_hasBoundingBox = false;
                m_meshId = meshId;
                m_meshParentId = parentId;
                m_materialId = materialId;
                m_skeletonId = skeletonId;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::EndMesh()
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("GeoemtryWriter::EndMesh - NULL output buffer");
                }
                if (!IsValidMesh())
                {
                    throw Utils::SpectreFailException("GeoemtryWriter::EndMesh - Need to call BeginMesh first");
                }
                if ((m_totalIndices % 3) != 0)
                {
                    throw Utils::SpectreFailException("GeoemtryWriter::EndMesh - Invalid index count");
                }
                SpectreAssertExpr(m_hasLockedData == false, "GeoemtryWriter::EndMesh - has locked data");

                // Ensure data is valid
                if (m_totalVertices > 0 && m_joints.size() > 0)
                {
                    throw Utils::SpectreFailException("GeoemtryWriter::EndMesh - Cannot have Joint and Vertex data on same object");
                }

                if (m_instanceType != None && m_joints.size() > 0)
                {
                    throw Utils::SpectreFailException("GeoemtryWriter::EndMesh - Cannot have Joint data within an instance segment");
                }

                if (m_instanceType != None && m_totalVertices > 0)
                {
                    throw Utils::SpectreFailException("GeoemtryWriter::EndMesh - Cannot have Vertex data within an instance segment");
                }

                if (m_totalVertices > 0)
                {
                    EndMeshSegment();
                }
                else if (m_joints.size() > 0)
                {
                    EndSkeletonSegment();
                }
                else if (m_instanceType != InstanceType::None)
                {
                    EndMeshInstanceSegment();
                }
                else
                {
                    EndNodeSegment();
                }

                // Update state

                ++m_numItems;

                // Reset the state

                m_meshId = 0;
                m_meshParentId = 0;
                m_indexType = kIndexUnknown;
                m_totalIndices = 0;
                m_totalVertices = 0;
                m_joints.clear();
                m_sourceMeshId = 0;
                m_instanceType = None;
                m_flags = 0;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::EndMeshSegment()
            {
                // Write out a MeshSegment which contains mesh geometry data
                // Copy the serialized streams to the output buffer

                MeshSegment segment;
                memset(&segment, 0, sizeof(segment));

                segment.Version = m_byteSwapU32(MeshSegment::kVersion0);
                segment.MeshID = m_byteSwapU32(m_meshId);
                segment.ParentID = m_byteSwapU32(m_meshParentId);
                segment.MaterialID = m_byteSwapU32(m_materialId);
                segment.NumVertices = m_byteSwapU32(m_totalVertices);
                segment.NumIndices = m_byteSwapU32(m_totalIndices);
                segment.Type = MeshBaseSegment::kTypeGeometry;
                segment.Flags = m_byteSwapU16(m_flags);

                if (m_skeletonId)
                {
                    // This mesh is linked to a skeleton. This extra information is described by an extension header:
                    MeshSkeletonBinding skeletonBinding;
                    memset(&skeletonBinding, 0, sizeof(skeletonBinding));
                    skeletonBinding.SkeletonID = m_byteSwapU32(m_skeletonId);
                    AddExtensionHeader(ExtensionHeader::kMeshSkeletonBinding, skeletonBinding);
                }

                // Transform

                uint32_t* srcTransform = (uint32_t*)m_transform;
                for (int i = 0; i < 16; ++i, ++srcTransform)
                {
                    *srcTransform = m_byteSwapU32(*srcTransform);
                }
                memcpy_s(segment.Transform, sizeof(float) * 16, m_transform, sizeof(float) * 16);

                // Calculate format mask

                if (m_totalIndices > 0)
                {
                    if (GetIndexBufferElementSizeInBytes(m_totalVertices) == sizeof(uint32_t))
                    {
                        segment.FormatMask |= MeshSegment::kHasBigIndices;
                    }
                    else
                    {
                        segment.FormatMask |= MeshSegment::kHasIndices;
                    }
                }

                if (m_buffers[kBufferPos].GetSizeInBytes() > 0)
                    segment.FormatMask |= MeshSegment::kHasPosition;

                if (m_buffers[kBufferColor].GetSizeInBytes() > 0)
                {
                    segment.FormatMask |= MeshSegment::kHasColor;
                    // New files have this additional flag for vertex colors
                    segment.Flags |= MeshSegment::Flags::kDisplayVertexColors;
                }

                if (m_buffers[kBufferkNormal].GetSizeInBytes() > 0)
                    segment.FormatMask |= MeshSegment::kHasNormals;

                if (m_buffers[kBufferTangent].GetSizeInBytes() > 0)
                    segment.FormatMask |= MeshSegment::kHasTangents;

                if (m_buffers[kBufferUV0].GetSizeInBytes() > 0)
                    segment.FormatMask |= MeshSegment::kHasUV0;

                if (m_buffers[kBufferUV1].GetSizeInBytes() > 0)
                    segment.FormatMask |= MeshSegment::kHasUV1;

                if (m_buffers[kBufferJointIndices].GetSizeInBytes() > 0 &&
                    m_buffers[kBufferJointWeights].GetSizeInBytes() > 0)
                    segment.FormatMask |= MeshSegment::kHasJointData;

                if (m_hasBoundingBox)
                {
                    uint32_t* bbox = (uint32_t*)m_bbox;
                    bbox[0] = m_byteSwapU32(bbox[0]);
                    bbox[1] = m_byteSwapU32(bbox[1]);
                    bbox[2] = m_byteSwapU32(bbox[2]);
                    bbox[3] = m_byteSwapU32(bbox[3]);
                    bbox[4] = m_byteSwapU32(bbox[4]);
                    bbox[5] = m_byteSwapU32(bbox[5]);
                    memcpy_s(segment.BoundsCenter, sizeof(float) * 3, &bbox[0], sizeof(float) * 3);
                    memcpy_s(segment.BoundsExtents, sizeof(float) * 3, &bbox[3], sizeof(float) * 3);

                    segment.FormatMask |= MeshSegment::kHasBoundingBox;
                }

                segment.FormatMask = m_byteSwapU32(segment.FormatMask);
                segment.Flags = m_byteSwapU16(segment.Flags);

                // Write header...

                uint32_t headerOffset = m_outputBuffer->WriteDataRaw(&segment, sizeof(segment), 4);

                // Save mesh offset

                m_savedItemOffsets.push_back(headerOffset);

                // Write the arrays

                uint32_t firstExtensionHeaderOffset = FlushExtensionHeaders();
                uint32_t posOffset = 0;
                uint32_t colOffset = 0;
                uint32_t normalOffset = 0;
                uint32_t tangentOffset = 0;
                uint32_t uv0Offset = 0;
                uint32_t uv1Offset = 0;
                uint32_t indexOffset = 0;
                uint32_t jointIndexOffset = 0;
                uint32_t jointWeightOffset = 0;

                if (m_buffers[kBufferPos].GetSizeInBytes() > 0)
                    posOffset = WriteArray(static_cast<void*>(m_buffers[kBufferPos].GetBuffer()), m_totalVertices * 3, sizeof(float), m_outputBuffer);

                if (m_buffers[kBufferColor].GetSizeInBytes() > 0)
                    colOffset = WriteArray(static_cast<void*>(m_buffers[kBufferColor].GetBuffer()), m_totalVertices, sizeof(uint32_t), m_outputBuffer);

                if (m_buffers[kBufferkNormal].GetSizeInBytes() > 0)
                {
                    normalOffset = WriteArray(static_cast<void*>(m_buffers[kBufferkNormal].GetBuffer()), m_totalVertices * 3, sizeof(float), m_outputBuffer);
                }

                if (m_buffers[kBufferTangent].GetSizeInBytes() > 0)
                {
                    tangentOffset = WriteArray(static_cast<void*>(m_buffers[kBufferTangent].GetBuffer()), m_totalVertices * 4, sizeof(float), m_outputBuffer);
                }

                if (m_buffers[kBufferUV0].GetSizeInBytes() > 0)
                {
                    uv0Offset = WriteArray(static_cast<void*>(m_buffers[kBufferUV0].GetBuffer()), m_totalVertices * 2, sizeof(float), m_outputBuffer);
                }

                if (m_buffers[kBufferUV1].GetSizeInBytes() > 0)
                {
                    uv1Offset = WriteArray(static_cast<void*>(m_buffers[kBufferUV1].GetBuffer()), m_totalVertices * 2, sizeof(float), m_outputBuffer);
                }

                if (m_buffers[kBufferJointIndices].GetSizeInBytes() > 0)
                {
                    jointIndexOffset = WriteArray(static_cast<void*>(m_buffers[kBufferJointIndices].GetBuffer()), m_totalVertices * 4, sizeof(uint8_t), m_outputBuffer);
                }

                if (m_buffers[kBufferJointWeights].GetSizeInBytes() > 0)
                {
                    jointWeightOffset = WriteArray(static_cast<void*>(m_buffers[kBufferJointWeights].GetBuffer()), m_totalVertices * 4, sizeof(uint8_t), m_outputBuffer);
                }

                // Write indices

                if (m_totalIndices > 0)
                {
                    indexOffset = WriteIndexArray(static_cast<void*>(m_buffers[kBufferIndex].GetBuffer()),
                                                  m_totalIndices,
                                                  m_totalVertices,
                                                  m_outputBuffer);
                }

                // Patch the offsets (these are relative to the mesh header, not the frame)...

                MeshSegment* pHeader = (MeshSegment*)m_outputBuffer->GetBuffer(headerOffset);
                pHeader->OffsetToFirstExtensionHeader = firstExtensionHeaderOffset == 0 ? firstExtensionHeaderOffset : (firstExtensionHeaderOffset - headerOffset);
                pHeader->OffsetColors = colOffset == 0 ? colOffset : (colOffset - headerOffset);
                pHeader->OffsetNormals = normalOffset == 0 ? normalOffset : (normalOffset - headerOffset);
                pHeader->OffsetTangents = tangentOffset == 0 ? tangentOffset : (tangentOffset - headerOffset);
                pHeader->OffsetUV0 = uv0Offset == 0 ? uv0Offset : (uv0Offset - headerOffset);
                pHeader->OffsetUV1 = uv1Offset == 0 ? uv1Offset : (uv1Offset - headerOffset);
                pHeader->OffsetPos = posOffset == 0 ? posOffset : (posOffset - headerOffset);
                pHeader->OffsetIndices = indexOffset == 0 ? indexOffset : (indexOffset - headerOffset);
                pHeader->OffsetJointIndices = jointIndexOffset == 0 ? jointIndexOffset : (jointIndexOffset - headerOffset);
                pHeader->OffsetJointWeights = jointWeightOffset == 0 ? jointWeightOffset : (jointWeightOffset - headerOffset);

                pHeader->OffsetToFirstExtensionHeader = m_byteSwapU32(pHeader->OffsetToFirstExtensionHeader);
                pHeader->OffsetColors = m_byteSwapU32(pHeader->OffsetColors);
                pHeader->OffsetNormals = m_byteSwapU32(pHeader->OffsetNormals);
                pHeader->OffsetTangents = m_byteSwapU32(pHeader->OffsetTangents);
                pHeader->OffsetUV0 = m_byteSwapU32(pHeader->OffsetUV0);
                pHeader->OffsetUV1 = m_byteSwapU32(pHeader->OffsetUV1);
                pHeader->OffsetPos = m_byteSwapU32(pHeader->OffsetPos);
                pHeader->OffsetIndices = m_byteSwapU32(pHeader->OffsetIndices);
                pHeader->OffsetJointIndices = m_byteSwapU32(pHeader->OffsetJointIndices);
                pHeader->OffsetJointWeights = m_byteSwapU32(pHeader->OffsetJointWeights);
            }

            //---------------------------------------------------------------------
            void GeometryWriter::EndNodeSegment()
            {
                // Write out a NodeSegment which specifies a sceneNode in the hierarchy, and
                // contains only a transform

                NodeSegment segment;
                memset(&segment, 0, sizeof(segment));

                segment.Version = m_byteSwapU32(MeshSegment::kVersion0);
                segment.MeshID = m_byteSwapU32(m_meshId);
                segment.ParentID = m_byteSwapU32(m_meshParentId);
                segment.Type = MeshBaseSegment::kTypeNode;

                if (m_hasBoundingBox)
                {
                    uint32_t* bbox = reinterpret_cast<uint32_t*>(m_bbox);
                    bbox[0] = m_byteSwapU32(bbox[0]);
                    bbox[1] = m_byteSwapU32(bbox[1]);
                    bbox[2] = m_byteSwapU32(bbox[2]);
                    bbox[3] = m_byteSwapU32(bbox[3]);
                    bbox[4] = m_byteSwapU32(bbox[4]);
                    bbox[5] = m_byteSwapU32(bbox[5]);
                    memcpy_s(segment.BoundsCenter, sizeof(float) * 3, &bbox[0], sizeof(float) * 3);
                    memcpy_s(segment.BoundsExtents, sizeof(float) * 3, &bbox[3], sizeof(float) * 3);
                }

                // Transform

                uint32_t* srcTransform = (uint32_t*)m_transform;
                for (int i = 0; i < 16; ++i, ++srcTransform)
                {
                    *srcTransform = m_byteSwapU32(*srcTransform);
                }
                memcpy_s(segment.Transform, sizeof(float) * 16, m_transform, sizeof(float) * 16);

                // Write header...

                uint32_t headerOffset = m_outputBuffer->WriteDataRaw(&segment, sizeof(segment), 4);

                // Save mesh offset

                m_savedItemOffsets.push_back(headerOffset);
            }

            //---------------------------------------------------------------------
            void GeometryWriter::EndSkeletonSegment()
            {
                // Write out a NodeSegment which specifies a sceneNode in the hierarchy, and
                // contains only a transform

                uint16_t numJoints = (uint16_t)m_joints.size();

                uint32_t headerOffset = m_outputBuffer->ReserveSpace(sizeof(SkeletonSegment) + sizeof(SkeletonSegment::Joint) * numJoints, 4);
                SkeletonSegment* segment = (SkeletonSegment*)m_outputBuffer->GetBuffer(headerOffset);

                segment->Version = m_byteSwapU32(SkeletonSegment::kVersion0);
                segment->MeshID = m_byteSwapU32(m_meshId);
                segment->ParentID = m_byteSwapU32(m_meshParentId);
                segment->NumJoints = m_byteSwapU16(numJoints);
                segment->Type = MeshBaseSegment::kTypeSkeleton;

                void* pJointData = m_outputBuffer->GetBuffer(headerOffset + sizeof(SkeletonSegment));
                memcpy_s(pJointData,
                         sizeof(SkeletonSegment::Joint) * numJoints,
                         &m_joints[0],
                         sizeof(SkeletonSegment::Joint) * numJoints);

                // Save mesh offset

                m_savedItemOffsets.push_back(headerOffset);
            }

            //---------------------------------------------------------------------
            void GeometryWriter::EndMeshInstanceSegment()
            {
                MeshInstanceSegment segment;
                memset(&segment, 0, sizeof(segment));

                segment.Version = m_byteSwapU32(MeshInstanceSegment::kVersion0);
                segment.MeshID = m_byteSwapU32(m_meshId);
                segment.SourceMeshID = m_byteSwapU32(m_sourceMeshId);
                segment.MaterialID = m_byteSwapU32(m_materialId);
                segment.ParentID = m_byteSwapU32(m_meshParentId);
                segment.Type = MeshBaseSegment::kTypeInstance;

                uint32_t* srcTransform = (uint32_t*)m_transform;
                for (int i = 0; i < 16; ++i, ++srcTransform)
                {
                    *srcTransform = m_byteSwapU32(*srcTransform);
                }

                if (m_instanceType == InstanceType::Primitive)
                    segment.IsPrimitive = 1;

                memcpy_s(segment.Transform, sizeof(float) * 16, m_transform, sizeof(float) * 16);

                if (m_hasBoundingBox)
                {
                    uint32_t* bbox = (uint32_t*)m_bbox;
                    bbox[0] = m_byteSwapU32(bbox[0]);
                    bbox[1] = m_byteSwapU32(bbox[1]);
                    bbox[2] = m_byteSwapU32(bbox[2]);
                    bbox[3] = m_byteSwapU32(bbox[3]);
                    bbox[4] = m_byteSwapU32(bbox[4]);
                    bbox[5] = m_byteSwapU32(bbox[5]);
                    memcpy_s(segment.BoundsCenter, sizeof(float) * 3, &bbox[0], sizeof(float) * 3);
                    memcpy_s(segment.BoundsExtents, sizeof(float) * 3, &bbox[3], sizeof(float) * 3);

                    segment.HasBoundingBox = 1;
                }

                // Write header (which in this case is the entire segment).

                uint32_t headerOffset = m_outputBuffer->WriteDataRaw(&segment, sizeof(segment), 4);

                // Save mesh instance offset.

                m_savedItemOffsets.push_back(headerOffset);
            }

            //---------------------------------------------------------------------
            void GeometryWriter::SetSourceMeshID(uint32_t sourceMeshId)
            {
                m_sourceMeshId = sourceMeshId;
                m_instanceType = Mesh;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::AddJoint(uint32_t id, int parentJointIndex, const float* invBindMatrix, const float* transform)
            {
                if (parentJointIndex < 0)
                    parentJointIndex = -1;

                if (parentJointIndex >= (int)m_joints.size())
                {
                    throw Utils::SpectreFailException("GeometryWriter::AddJoint - Invalid parent joint index");
                }

                SkeletonSegment::Joint j;
                j.Id = m_byteSwapU32(id);
                j.ParentJointIndex = parentJointIndex;

                uint32_t* pIdx = (uint32_t*)&j.ParentJointIndex;
                *pIdx = m_byteSwapU32(*pIdx);

                memcpy_s(j.InverseBindMatrix, sizeof(float) * 16, invBindMatrix, sizeof(float) * 16);
                memcpy_s(j.Transform, sizeof(float) * 16, transform, sizeof(float) * 16);

                /*uint32_t* srcTransform = (uint32_t*)j.InverseBindMatrix;
                for (int i = 0; i < 16; ++i, ++srcTransform)
                {
                    *srcTransform = m_byteSwapU32(*srcTransform);
                }*/
                m_joints.push_back(j);
            }

            //---------------------------------------------------------------------
            VertexData GeometryWriter::LockVertexData(uint32_t numVertices, uint32_t numIndices, uint32_t formatMask, bool areIndices32bit)
            {
                SpectreAssertExpr(m_hasLockedData == false, "GeoemtryWriter::LockVertexData - already locked");
                SpectreAssertExpr(m_totalVertices == 0, "GeoemtryWriter::LockVertexData - lock only allowed on new meshes");
                SpectreAssertExpr(m_totalIndices == 0, "GeoemtryWriter::LockVertexData - lock only allowed on new meshes");

                m_hasLockedData = true;

                VertexData ret;
                memset(&ret, 0, sizeof(ret));

                // Reserve space

                // Position
                uint32_t offset = m_buffers[kBufferPos].ReserveSpace(numVertices * sizeof(float) * 3, 4);
                ret.m_positionData = (float*)m_buffers[kBufferPos].GetBuffer(offset);

                if ((formatMask & MeshSegment::kHasColor) != 0)
                {
                    offset = m_buffers[kBufferColor].ReserveSpace(numVertices * sizeof(uint32_t), 4);
                    ret.m_colorData = (uint32_t*)m_buffers[kBufferColor].GetBuffer(offset);
                }

                if ((formatMask & MeshSegment::kHasNormals) != 0)
                {
                    offset = m_buffers[kBufferkNormal].ReserveSpace(numVertices * sizeof(float) * 3, 4);
                    ret.m_normalData = (float*)m_buffers[kBufferkNormal].GetBuffer(offset);
                }

                if ((formatMask & MeshSegment::kHasTangents) != 0)
                {
                    offset = m_buffers[kBufferTangent].ReserveSpace(numVertices * sizeof(float) * 4, 4);
                    ret.m_tangentData = (float*)m_buffers[kBufferTangent].GetBuffer(offset);
                }

                if ((formatMask & MeshSegment::kHasUV0) != 0)
                {
                    offset = m_buffers[kBufferUV0].ReserveSpace(numVertices * sizeof(float) * 2, 4);
                    ret.m_uvData[0] = (float*)m_buffers[kBufferUV0].GetBuffer(offset);
                }

                if ((formatMask & MeshSegment::kHasUV1) != 0)
                {
                    offset = m_buffers[kBufferUV1].ReserveSpace(numVertices * sizeof(float) * 2, 4);
                    ret.m_uvData[1] = (float*)m_buffers[kBufferUV1].GetBuffer(offset);
                }

                if ((formatMask & MeshSegment::kHasJointData) != 0)
                {
                    offset = m_buffers[kBufferJointIndices].ReserveSpace(numVertices * sizeof(uint8_t) * 4, 4);
                    ret.m_jointIndices = (uint8_t*)m_buffers[kBufferJointIndices].GetBuffer(offset);

                    offset = m_buffers[kBufferJointWeights].ReserveSpace(numVertices * sizeof(uint8_t) * 4, 4);
                    ret.m_jointWeights = (uint8_t*)m_buffers[kBufferJointWeights].GetBuffer(offset);
                }

                if (numIndices > 0)
                {
                    uint32_t size = 0;
                    uint32_t align = 0;

                    if (areIndices32bit)
                    {
                        size = numIndices * sizeof(uint32_t);
                        align = 4;
                        m_areIndices32bit = true;
                    }
                    else
                    {
                        size = numIndices * sizeof(uint16_t);
                        align = 2;
                        m_areIndices32bit = false;
                    }

                    // Note: this allocates according to numIndices rather than numVertices because
                    // this is for the index data (unlike all the cases above).
                    offset = m_buffers[kBufferIndex].ReserveSpace(size, align);
                    ret.m_indexData = (uint32_t*)m_buffers[kBufferIndex].GetBuffer(offset);
                }

                ret.m_numIndicesLocked = numIndices;
                ret.m_numVerticesLocked = numVertices;

                // Update counts

                m_totalVertices += numVertices;
                m_totalIndices += numIndices;
                return ret;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::UnlockVertexData(const VertexData& data)
            {
                SpectreUnusedParameter(data);
                SpectreAssertExpr(m_hasLockedData == true, "GeoemtryWriter::UnlockVertexData - not locked");
                SpectreAssertExpr(data.m_numIndicesLocked == m_totalIndices, "GeoemtryWriter::UnlockVertexData - unexpected index count");
                SpectreAssertExpr(data.m_numVerticesLocked == m_totalVertices, "GeoemtryWriter::UnlockVertexData - unexpected vertex count");
                m_hasLockedData = false;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::SetSkeletonId(uint32_t skeletonID)
            {
                m_skeletonId = skeletonID;
            }

            //---------------------------------------------------------------------
            uint32_t GeometryWriter::GetSkeletonId() const
            {
                return m_skeletonId;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::SetTransform(_In_reads_(16) const float* transform)
            {
                memcpy_s(m_transform, sizeof(float) * 16, transform, sizeof(float) * 16);
            }

            //---------------------------------------------------------------------
            const float* GeometryWriter::GetTransform()
            {
                return m_transform;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::SetBoundingBox(_In_reads_(3) const float* center, _In_reads_(3) const float* extents)
            {
                memcpy_s(&m_bbox[0], 3 * sizeof(float), center, 3 * sizeof(float));
                memcpy_s(&m_bbox[3], 3 * sizeof(float), extents, 3 * sizeof(float));
                m_hasBoundingBox = true;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::SetFlags(uint32_t flags)
            {
                m_flags = static_cast<uint16_t>(flags);
            }

            //---------------------------------------------------------------------
            // <summary>
            // Write and byte swap the specified vertex array to the output buffer
            // </summary>
            uint32_t GeometryWriter::WriteArray(_In_reads_bytes_(numElements*elementSizeInBytes)void* srcArray,
                                                uint32_t numElements,
                                                uint32_t elementSizeInBytes,
                                                std::shared_ptr<Spectre::Framework::IBuffer> const&  outputBuffer)
            {
                // Byte swap the array elements first
                if (elementSizeInBytes > sizeof(uint32_t))
                {
                    throw Utils::SpectreInvalidArgException("Element size not supported. Add support if you need it");
                }

                uint32_t bufferOffset = outputBuffer->WriteDataRaw(srcArray, elementSizeInBytes * numElements, elementSizeInBytes);
                srcArray = outputBuffer->GetBuffer(bufferOffset);

                if (elementSizeInBytes == sizeof(uint16_t))
                {
                    uint16_t* p = (uint16_t*)srcArray;
                    for (uint32_t i = 0; i < numElements; ++i, ++p)
                    {
                        *p = m_byteSwapU16(*p);
                    }
                }
                else if (elementSizeInBytes == sizeof(uint32_t))
                {
                    uint32_t* p = (uint32_t*)srcArray;
                    for (uint32_t i = 0; i < numElements; ++i, ++p)
                    {
                        *p = m_byteSwapU32(*p);
                    }
                }

                return bufferOffset;
            }

            //---------------------------------------------------------------------
            // <summary>
            // Write the index array to the final output buffer.
            // The source array is either a uint32_t* or uint16_t* buffer, depending on m_areIndices32bit flag.
            // The final format of the indices depends on the number of vertices referenced by the indices.
            // If less than 65535, then we output uint16_t* array. Else it's a 32bit array.
            // </summary>
            uint32_t GeometryWriter::WriteIndexArray(
                _In_reads_bytes_(numElements * GetIndexBufferElementSizeInBytes(numVertices)) void* srcArray,
                uint32_t numElements,
                uint32_t numVertices,
                std::shared_ptr<Spectre::Framework::IBuffer> const& outputBuffer)
            {
                uint32_t elementSizeInBytes = GetIndexBufferElementSizeInBytes(numVertices);

                uint32_t bufferOffset = outputBuffer->ReserveSpace(elementSizeInBytes * numElements, elementSizeInBytes);
                void* destArray = outputBuffer->GetBuffer(bufferOffset);

                if (elementSizeInBytes == sizeof(uint16_t))
                {
                    uint16_t* dest = (uint16_t*)destArray;

                    if(m_areIndices32bit)
                    {
                        uint32_t* src = (uint32_t*)srcArray;
                        for (uint32_t i = 0; i < numElements; ++i, ++dest, ++src)
                        {
                            *dest = m_byteSwapU16((uint16_t)*src);
                        }
                    }
                    else
                    {
                        uint16_t* src = (uint16_t*)srcArray;
                        for(uint32_t i = 0; i < numElements; ++i,++dest,++src)
                        {
                            *dest = m_byteSwapU16(*src);
                        }
                    }
                }
                else
                {
                    uint32_t* dest = (uint32_t*)destArray;
                    uint32_t* src = (uint32_t*)srcArray;
                    for (uint32_t i = 0; i < numElements; ++i, ++dest, ++src)
                    {
                        *dest = m_byteSwapU32(*src);
                    }
                }

                return bufferOffset;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::AddVertex(_In_reads_(numVertices) const Vertex* pVertices, uint32_t numVertices)
            {
                SpectreAssertExpr(m_hasLockedData == false, "GeoemtryWriter::AddVertex - has locked data");

                // Serialize all vertex data. We serialize into intermediate buffers, which will later be
                // combined into the output buffer. We DO NOT byte swap at this stage, instead do it later on
                // inside EndMesh. This will allow us to vectorize the byte-swapping since we're dealing with
                // uniform arrays
                if (!IsValidMesh())
                {
                    throw Utils::SpectreFailException("Need to call BeginMesh first");
                }

                for (uint32_t i = 0; i < numVertices; ++i)
                {
                    auto v = pVertices[i];

                    m_buffers[kBufferPos].WriteDataRaw(v.Position, sizeof(float) * 3);

                    SpectreAssertExpr(v.HasNormal || m_buffers[kBufferkNormal].GetSizeInBytes() == 0, "GeometryWriter::AddVertex - If a vertex has a normal, they all need to!");
                    SpectreAssertExpr(v.HasTangent || m_buffers[kBufferTangent].GetSizeInBytes() == 0, "GeometryWriter::AddVertex - If a vertex has a tngent, they all need to!");
                    SpectreAssertExpr(v.HasUV0 || m_buffers[kBufferUV0].GetSizeInBytes() == 0, "GeometryWriter::AddVertex - If a vertex has UV0, they all need to!");
                    SpectreAssertExpr(v.HasUV1 || m_buffers[kBufferUV1].GetSizeInBytes() == 0, "GeometryWriter::AddVertex - If a vertex has UV1, they all need to!");
                    SpectreAssertExpr(v.HasColor || m_buffers[kBufferColor].GetSizeInBytes() == 0, "GeometryWriter::AddVertex - If a vertex has COLOR, they all need to!");

                    if (v.HasNormal)
                    {
                        m_buffers[kBufferkNormal].WriteDataRaw(v.Normal, sizeof(float) * 3);
                    }

                    if (v.HasTangent)
                    {
                        m_buffers[kBufferTangent].WriteDataRaw(v.Tangent, sizeof(float) * 4);
                    }

                    if (v.HasUV0)
                    {
                        m_buffers[kBufferUV0].WriteDataRaw(v.UV0, sizeof(float) * 2);
                    }

                    if (v.HasUV1)
                    {
                        m_buffers[kBufferUV1].WriteDataRaw(v.UV1, sizeof(float) * 2);
                    }

                    if (v.HasColor)
                    {
                        m_buffers[kBufferColor].WriteDataRaw(v.Rgba, sizeof(uint8_t) * 4);
                    }
                }

                m_totalVertices += numVertices;
            }

            //---------------------------------------------------------------------
            void GeometryWriter::AddIndex(_In_reads_(numIndices) const uint32_t* pIndices, uint32_t numIndices)
            {
                if (!IsValidMesh())
                {
                    throw Utils::SpectreFailException("Need to call BeginMesh first");
                }
                if (m_indexType == kIndexSmall)
                {
                    throw Utils::SpectreFailException("Have both SMALL and BIG indices. Not allowed.");
                }

                if ((numIndices % 3) != 0)
                {
                    numIndices -= (numIndices % 3);
                }
                if (numIndices <= 0)
                {
                    throw Utils::SpectreInvalidArgException("GeometryWriter: Index count must be multiple of 3 and greater and 0");
                }
                SpectreAssertExpr(m_hasLockedData == false, "GeoemtryWriter::AddIndex - has locked data");

                m_buffers[kBufferIndex].WriteDataRaw(pIndices, numIndices * sizeof(uint32_t));
                m_totalIndices += numIndices;
            }

            uint32_t GeometryWriter::GetVertexBufferSize() const
            {
                uint32_t result = 0;
                for (int i = 0; i < kNumBuffers; ++i)
                {
                    result += m_buffers[i].GetSizeInBytes();
                }
                return result;
            }

            uint32_t GeometryWriter::GetIndexBufferSize() const
            {
                return m_buffers[kBufferIndex].GetSizeInBytes();
            }

        } // namespace V1

        SPECTRESDK_API IGeometryWriter* GeometryWriterCreate()
        {
            return new V1::GeometryWriter();
        }

        SPECTRESDK_API void GeometryWriterDestroy(IGeometryWriter*& pWriter)
        {
            if (pWriter == nullptr)
                return;

            delete pWriter;
            pWriter = nullptr;
        }

    } // Namespace Framework

} // Namespace Spectre
