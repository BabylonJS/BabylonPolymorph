/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Frame.h>
#include <Framework/MemoryBuffer.h>
#include <Framework/Vertex.h>
#include <Framework/Types.h>
#include <Framework/FormatWriterUtils.h>
#include <Framework/Plugin.h>

#include <CoreUtils/SpectreSDK.h>

#include <cstdint>
#include <memory>

namespace Spectre
{
    namespace Framework
    {
        struct VertexData
        {
            float* m_positionData = nullptr;
            float* m_normalData = nullptr;
            float* m_tangentData = nullptr;
            uint32_t* m_colorData = nullptr;
            float* m_uvData[4] = { nullptr,nullptr,nullptr,nullptr };
            uint32_t* m_indexData = nullptr;
            uint8_t* m_jointIndices = nullptr;
            uint8_t* m_jointWeights = nullptr;

            uint32_t m_numVerticesLocked = 0;
            uint32_t m_numIndicesLocked = 0;
        };

        enum InstanceType
        {
            None = 0,
            Mesh = 1,
            Primitive = 2
        };

        /**
         * Use the GeometryWriter to help you serialize out mesh data in the
         * common object format.
         */
        class SPECTRESDK_API IGeometryWriter
        {
        public:
            virtual ~IGeometryWriter() {}

            virtual void BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                uint32_t numMeshes,
                EByteOrder byteOrder) = 0;

            virtual void BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                uint32_t numMeshes,
                EByteOrder byteOrder,
                EFrameQuality quality) = 0;

            virtual Frame* EndFrame() = 0;

            virtual void BeginMesh(uint32_t meshId,
                                   uint32_t parentId = 0,
                                   uint32_t materialId = 0,
                                   uint32_t skeletonId = 0) = 0;

            virtual void EndMesh() = 0;

            virtual VertexData LockVertexData(uint32_t numVertices, uint32_t numIndices, uint32_t formatMask, bool areIndices32bit = true) = 0;
            virtual void UnlockVertexData(const VertexData& data) = 0;

            /**
             * Set the transform matrix of the current mesh. The transform must be in Column Major format,
             * and must contain 16 floats (4 by 4 matrix).
             * Must be called between a BeginMesh and EndMesh pair.
             */
            virtual void SetTransform(_In_reads_(16) const float* transform) = 0;

            /**
            * Returns the current transform as 16 floats (4 by 4 matrix) in Column Major format.
            * If called before BeginMesh the transform will be uninitialised.
            */
            virtual const float* GetTransform() = 0;

            /**
             * Set the ID of the skeleton which is bound to the current mesh.
             * If called before BeginMesh the transform will be uninitialised.
             */
            virtual void SetSkeletonId(uint32_t skeletonID) = 0;

            /**
             * Returns the ID of the skeleton which is bound to the current mesh.
             * If called before BeginMesh the transform will be uninitialised.
             */
            virtual uint32_t GetSkeletonId() const = 0;

            /**
            * Add a joint to the skeleton. Joints must be added in order (parentJointIndex must exist)
            */
            virtual void AddJoint(uint32_t id, int parentJointIndex, const float* invBindMatrix, const float* transform) = 0;

            /**
            * Set the bounding box of the mesh segment. The box is comprised of 3xfloats for the center (X,Y,Z)
            * and 3x floats for the extents (X,Y,Z)
            */
            virtual void SetBoundingBox(_In_reads_(3) const float* center, _In_reads_(3) const float* extents) = 0;

            /**
            * Set the flags for this mesh segment. This is a bitmask of MeshSegment::Flags type.
            */
            virtual void SetFlags(uint32_t flags) = 0;

            /**
            * Set the source mesh ID which is used to determine which already existing mesh
            * this instance will use.
            */
            virtual void SetSourceMeshID(uint32_t sourceMeshId) = 0;

            /**
             * Add vertices to the current mesh.
             * Must be called between a BeginMesh and EndMesh pair.
             */
            virtual void AddVertex(_In_reads_(numVertices) const Vertex* pVertices, uint32_t numVertices) = 0;

            /**
             * Add indices to the current mesh.
             * Must be called between a BeginMesh and EndMesh pair.
             */
            virtual void AddIndex(_In_reads_(numIndices) const uint32_t* pIndices, uint32_t numIndices) = 0;
            virtual uint32_t GetVersion() const = 0;
            virtual uint32_t GetVertexBufferSize() const = 0;
            virtual uint32_t GetIndexBufferSize() const = 0;
        };

        SPECTRESDK_API IGeometryWriter* GeometryWriterCreate();
        SPECTRESDK_API void GeometryWriterDestroy(IGeometryWriter*& pWriter);

    } // End namespace Framework

} // End namespace Spectre
