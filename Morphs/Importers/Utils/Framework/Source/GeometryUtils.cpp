/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"
#include <Framework/GeometryUtils.h>
#include <Framework/Cancellation.h>
#include <CoreUtils/Math/SimpleMath.h>
#include <CoreUtils/ThreadPool.h>
#include <unordered_map>

DEFINE_TRACE_AREA(GeometryUtils, 0);

namespace Babylon
{
    //--------------------------------------------------------------------------------------
    inline void CalculateTriangleNormal(const Vector3* pos, uint32_t i0, uint32_t i1, uint32_t i2, bool invertDirection, Vector3* normalsOut)
    {
        Vector3 v0 = pos[i2] - pos[i0];
        Vector3 v1 = pos[i1] - pos[i0];
        Vector3 n = v1.Cross(v0);

        if (invertDirection)
        {
            n = -n;
        }

        normalsOut[i0] += n;
        normalsOut[i1] += n;
        normalsOut[i2] += n;
    }

    //--------------------------------------------------------------------------------------
    inline void CalculateTriangleNormal(const float* pos, uint32_t i0, uint32_t i1, uint32_t i2, bool invertDirection, float* normalsOut)
    {
        i0 *= 3;
        i1 *= 3;
        i2 *= 3;

        const Vector3 i0Vec = Vector3(pos[i0 + 0], pos[i0 + 1], pos[i0 + 2]);
        const Vector3 i1Vec = Vector3(pos[i1 + 0], pos[i1 + 1], pos[i1 + 2]);
        const Vector3 i2Vec = Vector3(pos[i2 + 0], pos[i2 + 1], pos[i2 + 2]);

        Vector3 v0 = i2Vec - i0Vec;
        Vector3 v1 = i1Vec - i0Vec;
        Vector3 n = v1.Cross(v0);

        if (invertDirection)
        {
            n = -n;
        }

        normalsOut[i0 + 0] += n.x;
        normalsOut[i1 + 0] += n.x;
        normalsOut[i2 + 0] += n.x;

        normalsOut[i0 + 1] += n.y;
        normalsOut[i1 + 1] += n.y;
        normalsOut[i2 + 1] += n.y;

        normalsOut[i0 + 2] += n.z;
        normalsOut[i1 + 2] += n.z;
        normalsOut[i2 + 2] += n.z;
    }

    //--------------------------------------------------------------------------------------
    inline void ComputeTriangleTangents(const Vector3* pos, const Vector2* uv,
                                        uint32_t i0, uint32_t i1, uint32_t i2,
                                        bool invertDirection,
                                        Vector3* tan1, Vector3* tan2)
    {
        Vector3 v0 = pos[i0];
        Vector3 v1 = pos[i1];
        Vector3 v2 = pos[i2];

        Vector2 w0 = uv[i0];
        Vector2 w1 = uv[i1];
        Vector2 w2 = uv[i2];

        float x1 = v1.x - v0.x;
        float x2 = v2.x - v0.x;
        float y1 = v1.y - v0.y;
        float y2 = v2.y - v0.y;
        float z1 = v1.z - v0.z;
        float z2 = v2.z - v0.z;

        float s1 = w1.x - w0.x;
        float s2 = w2.x - w0.x;
        float t1 = w1.y - w0.y;
        float t2 = w2.y - w0.y;

        float denom = (s1 * t2 - s2 * t1);
        if( denom == 0.0f )
        {
            // Triangles which are degenerate in UV-space don't contribute to final tangent
            return;
        }

        float r = 1.0F / denom;
        Vector3 sdir((t2 * x1 - t1 * x2) * r, (t2 * y1 - t1 * y2) * r,
                                          (t2 * z1 - t1 * z2) * r);
        Vector3 tdir((s1 * x2 - s2 * x1) * r, (s1 * y2 - s2 * y1) * r,
                                          (s1 * z2 - s2 * z1) * r);

        if (invertDirection)
        {
            sdir = -sdir;
        }

        tan1[i0] += sdir;
        tan1[i1] += sdir;
        tan1[i2] += sdir;

        tan2[i0] += tdir;
        tan2[i1] += tdir;
        tan2[i2] += tdir;
    }

    //--------------------------------------------------------------------------------------
    inline void FinalizeVertexTangents(Vector4* tangents, uint32_t numVertices,
                                       const Vector3* normals, const Vector3* tan1, const Vector3* tan2, bool flipTangents)
    {
        for (uint32_t a = 0; a < numVertices; a++)
        {
            // Normal/Tangent/Bitangent basis
            auto n = normals[a];
            auto t = tan1[a];
            auto b = tan2[a];
            auto res = (t - n *  n.Dot(t));

            // Gram-Schmidt orthogonalize
            tangents[a].x = res.x;
            tangents[a].y = res.y;
            tangents[a].z = res.z;

            // Normalise the XYZ components (tangent vector).
            tangents[a].Normalize();

            // Store the handedness in the W component
            float w = (n.Cross(t).Dot(b)) < 0.0f ? -1.0f : 1.0f;
            tangents[a].w = flipTangents ? -w : w;
        }
    }
}

namespace Babylon
{
    namespace Framework
    {
        struct GeometryProcessingException : public Babylon::Utils::BabylonException
        {
            GeometryProcessingException() : BabylonException("Unspecified error while processing geometry", false) {}
            GeometryProcessingException(const std::string& message) : BabylonException(message, false) {}
        };

        // Constants used for processing
        static const uint32_t TriangleListNextTriangleOffset = 3;
        static const uint32_t TriangleStripNextTriangleOffset = 1;

        static const uint32_t TriangleListBoundary = 0;
        static const uint32_t TriangleStripBoundary = 2;

        static const uint32_t CancellationTokenCheckFrequency = 100;

        // Sanity-checking function that confirms that the vertex count used by the various geometry processing functions
        // is neither zero nor too large.
        // Models may (potentially) contain many millions of vertices, but there is a limit beyond which
        // we run into integer overflow and buffer-allocation problems if we try to process a contiguous array of vertices.
        // We choose a somewhat arbitrary limit of around 67 million vertices (0x4000000) which
        // will allow results to fit into the theoretical maximum size of a size_t (and guarantee that allocations are considerably less
        // than _HEAP_MAXREQ), even for the cases where functions need to return a buffer of (numVerts * sizeof(Vector4)) and
        // Vector4 is a double-precision type (ie 32 bytes for a vec4)
        static bool ValidateVertexCount(uint32_t vertCount, const char* callingFnName)
        {
            if (vertCount > GeometryUtils::MaxAllowedVertices)
            {
                TRACE_IMPORTANT(GeometryUtils, "%s cannot process more than %u vertices (requested: %u)", callingFnName, GeometryUtils::MaxAllowedVertices, vertCount);
                return false;
            }
            else if (vertCount == 0)
            {
                TRACE_IMPORTANT(GeometryUtils, "%s cannot process zero vertices", callingFnName);
                return false;
            }
            return true;
        }

        //--------------------------------------------------------------------------------------
        static void ValidateTopologyVertexCount(uint32_t numVertices, GeometryUtils::TriangularMeshTopology meshTopology)
        {
            if (meshTopology == GeometryUtils::TriangularMeshTopology::TriangleList && numVertices % 3 != 0)
            {
                throw GeometryProcessingException("Number of vertices is not a multiple of three");
            }

            if (meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip && numVertices < 3)
            {
                throw GeometryProcessingException("Number of vertices is less than three");
            }
        }

        //--------------------------------------------------------------------------------------
        static void ValidateTopologyIndexCount(uint32_t numIndices, GeometryUtils::TriangularMeshTopology meshTopology)
        {
            if (meshTopology == GeometryUtils::TriangularMeshTopology::TriangleList && numIndices % 3 != 0)
            {
                throw GeometryProcessingException("Number of indices is not a multiple of three");
            }

            if (meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip && numIndices < 3)
            {
                throw GeometryProcessingException("Number of indices is less than three");
            }
        }

        //--------------------------------------------------------------------------------------
        void GeometryUtils::ComputeNormals(const float* vertices, uint32_t vertCount, const uint32_t* indices, uint32_t indexCount, float* normals)
        {
            for (uint32_t t = 0; t < indexCount; t += 3)
            {
                uint32_t i0 = indices[t + 0];
                uint32_t i1 = indices[t + 1];
                uint32_t i2 = indices[t + 2];

                CalculateTriangleNormal(vertices, i0, i1, i2, false, normals);
            }

            // Normalise the normals
            for (uint32_t idx = 0; idx < vertCount; idx++)
            {
                float x = normals[idx * 3 + 0];
                float y = normals[idx * 3 + 1];
                float z = normals[idx * 3 + 2];
                float length = sqrtf(x*x + y*y + z*z);

                if (length > 0.0f)
                {
                    normals[idx * 3 + 0] /= length;
                    normals[idx * 3 + 1] /= length;
                    normals[idx * 3 + 2] /= length;
                }
            }
        }

        //--------------------------------------------------------------------------------------
        void CalculateNonIndexedNormals(
            const Vector3* const vertices,
            uint32_t numVertices,
            GeometryUtils::TriangularMeshTopology meshTopology,
            Utils::ICancellationTokenPtr const& cancellationToken,
            Vector3* const normals)
        {
            bool isTriangleStrip = meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip;
            uint32_t offset = isTriangleStrip ? TriangleStripNextTriangleOffset : TriangleListNextTriangleOffset;
            uint32_t boundary = isTriangleStrip ? TriangleStripBoundary : TriangleListBoundary;

            for (uint32_t v = 0, i = 0; v < numVertices - boundary; v += offset, ++i)
            {
                if (cancellationToken && i % CancellationTokenCheckFrequency == 0)
                {
                    cancellationToken->CheckCancelledAndThrow();
                }

                bool invert = isTriangleStrip && (v % 2 == 1);  // Every other triangle has reverse winding
                CalculateTriangleNormal(vertices, v, v + 1, v + 2, invert, normals);
            }
        }

        //--------------------------------------------------------------------------------------
        template<typename IndexType>
        void CalculateIndexedNormals(
            const Vector3* const vertices,
            uint32_t numVertices,
            const IndexType* const indices,
            uint32_t numIndices,
            GeometryUtils::TriangularMeshTopology meshTopology,
            Utils::ICancellationTokenPtr const& cancellationToken,
            Vector3* const normals)
        {
            bool isTriangleStrip = meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip;
            uint32_t offset = isTriangleStrip ? TriangleStripNextTriangleOffset : TriangleListNextTriangleOffset;
            uint32_t boundary = isTriangleStrip ? TriangleStripBoundary : TriangleListBoundary;

            for (uint32_t t = 0, i = 0; t < numIndices - boundary; t += offset, ++i)
            {
                IndexType i0 = indices[t + 0];
                IndexType i1 = indices[t + 1];
                IndexType i2 = indices[t + 2];

                // i0, i1 or i2 may be outside the vertex range, leading to
                // out-of-bounds memory access, hence crash.
                if (i0 >= numVertices || i1 >= numVertices || i2 >= numVertices)
                {
                    throw GeometryProcessingException("Index out of range while computing normals");
                }

                if (cancellationToken && i % CancellationTokenCheckFrequency == 0)
                {
                    cancellationToken->CheckCancelledAndThrow();
                }

                bool invert = isTriangleStrip && (t % 2 == 1);  // Every other triangle has reverse winding
                CalculateTriangleNormal(vertices, i0, i1, i2, invert, normals);
            }
        }

        //--------------------------------------------------------------------------------------
        void GeometryUtils::ComputeNormals(
            std::shared_ptr<Vector3>            pVerts,
            uint32_t                            numVertices,
            std::shared_ptr<void>               pIndices,
            uint32_t                            numIndices,
            bool                                bigIndices,
            TriangularMeshTopology              meshTopology,
            NormalsCompletionCallback           completionCallback,
            void*                               callbackUserData,
            Utils::ICancellationTokenPtr const& cancellationToken)
        {
            if (!ValidateVertexCount(numVertices, "ComputeNormals"))
            {
                completionCallback(nullptr, callbackUserData);
                return;
            }

            auto normals = std::shared_ptr<Vector3>(
                (Vector3*)_aligned_malloc(sizeof(Vector3) * numVertices, 16),
                [](void* data) { _aligned_free(data); });

            if (normals.get() == nullptr)
            {
                throw std::bad_alloc();
            }

            memset(normals.get(), 0, sizeof(Vector3) * numVertices);

            const Vector3* const pos = pVerts.get();

            try
            {
                if (!bigIndices)
                {
                    // Small, Indexed
                    ValidateTopologyIndexCount(numIndices, meshTopology);
                    const uint16_t* const indices = static_cast<const uint16_t*>(pIndices.get());
                    CalculateIndexedNormals(pos, numVertices, indices, numIndices, meshTopology, cancellationToken, normals.get());
                }
                else if (pIndices)
                {
                    // Big, Indexed
                    ValidateTopologyIndexCount(numIndices, meshTopology);
                    const uint32_t* const indices = static_cast<const uint32_t*>(pIndices.get());
                    CalculateIndexedNormals(pos, numVertices, indices, numIndices, meshTopology, cancellationToken, normals.get());
                }
                else
                {
                    // Non-indexed
                    ValidateTopologyVertexCount(numVertices, meshTopology);
                    CalculateNonIndexedNormals(pos, numVertices, meshTopology, cancellationToken, normals.get());
                }
            }
            catch (Utils::CancelledException const&)
            {
                throw;
            }
            catch (GeometryProcessingException const& geomExc)
            {
                BabylonUnusedLocal(geomExc);
                TRACE_IMPORTANT(GeometryUtils, geomExc.m_message.c_str());
                completionCallback(nullptr, callbackUserData);
                return;
            }
            catch (...)
            {
                TRACE_IMPORTANT(GeometryUtils, "ComputeNormals threw unexpected exception");
                completionCallback(nullptr, callbackUserData);
                return;
            }

            for (uint32_t i = 0; i < numVertices; ++i)
            {
                normals.get()[i].Normalize();
            }

            completionCallback(normals, callbackUserData);
        }

        //--------------------------------------------------------------------------------------
        void CalculateNonIndexedTangents(
            const Vector3* const vertices,
            uint32_t numVertices,
            const Vector2* const uv,
            GeometryUtils::TriangularMeshTopology meshTopology,
            Utils::ICancellationTokenPtr const& cancellationToken,
            Vector3* const tan1,
            Vector3* const tan2)
        {
            bool isTriangleStrip = meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip;
            uint32_t offset = isTriangleStrip ? TriangleStripNextTriangleOffset : TriangleListNextTriangleOffset;
            uint32_t boundary = isTriangleStrip ? TriangleStripBoundary : TriangleListBoundary;

            for (uint32_t v = 0, i = 0; v < numVertices - boundary; v += offset, ++i)
            {
                if (cancellationToken && i % CancellationTokenCheckFrequency == 0)
                {
                    cancellationToken->CheckCancelledAndThrow();
                }

                bool invert = isTriangleStrip && (v % 2 == 1);  // Every other triangle has reverse winding
                ComputeTriangleTangents(vertices, uv, v, v + 1, v + 2, invert, tan1, tan2);
            }
        }

        //--------------------------------------------------------------------------------------
        template<typename IndexType>
        void CalculateIndexedTangents(
            const Vector3* const vertices,
            uint32_t numVertices,
            const IndexType* const indices,
            uint32_t numIndices,
            const Vector2* const uv,
            GeometryUtils::TriangularMeshTopology meshTopology,
            Utils::ICancellationTokenPtr const& cancellationToken,
            Vector3* const tan1,
            Vector3* const tan2)
        {
            bool isTriangleStrip = meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip;
            uint32_t offset = isTriangleStrip ? TriangleStripNextTriangleOffset : TriangleListNextTriangleOffset;
            uint32_t boundary = isTriangleStrip ? TriangleStripBoundary : TriangleListBoundary;

            for (uint32_t t = 0, i = 0; t < numIndices - boundary; t += offset, ++i)
            {
                IndexType i0 = indices[t + 0];
                IndexType i1 = indices[t + 1];
                IndexType i2 = indices[t + 2];

                // i0, i1 or i2 may be outside the vertex range, leading to
                // out-of-bounds memory access, hence crash.
                if (i0 >= numVertices || i1 >= numVertices || i2 >= numVertices)
                {
                    throw (GeometryProcessingException("Index out of range while computing tangents"));
                }

                if (cancellationToken && i % CancellationTokenCheckFrequency == 0)
                {
                    cancellationToken->CheckCancelledAndThrow();
                }

                bool invert = isTriangleStrip && (t % 2 == 1);  // Every other triangle has reverse winding
                ComputeTriangleTangents(vertices, uv, i0, i1, i2, invert, tan1, tan2);
            }
        }

        //--------------------------------------------------------------------------------------
        void GeometryUtils::ComputeTangents(
            std::shared_ptr<Vector3>        pVerts,
            std::shared_ptr<Vector2>        pUVs,
            std::shared_ptr<Vector3>        pNormals,
            uint32_t                        numVertices,
            std::shared_ptr<void>           pIndices,
            uint32_t                        numIndices,
            bool                            bigIndices,
            TriangularMeshTopology          meshTopology,
            bool                            flipTangents,
            TangentsCompletionCallback      completionCallback,
            void*                           callbackUserData,
            Utils::ICancellationTokenPtr const&  cancellationToken)
        {
            // Src: http://www.terathon.com/code/tangent.html
            // :TODO: Can and should be optimized...

            if (!ValidateVertexCount(numVertices, "ComputeTangents"))
            {
                completionCallback(nullptr, callbackUserData);
                return;
            }

            BabylonAssert(pNormals.get());

            auto outputTangents = std::shared_ptr<Vector4>(
                (Vector4*)_aligned_malloc(sizeof(Vector4) * numVertices, 16),
                [](void* data) { _aligned_free(data); });

            if (outputTangents.get() == nullptr)
            {
                throw std::bad_alloc();
            }

            memset(outputTangents.get(), 0, sizeof(Vector4) * numVertices);

            std::vector<Vector3> tangents1(numVertices * 2);

            Vector3* const tan1 = tangents1.data();
            Vector3* const tan2 = tan1 + numVertices;

            const Vector3* const pos = pVerts.get();
            const Vector2* const uv = pUVs.get();
            const Vector3* const normals = pNormals.get();

            try
            {
                if (!bigIndices)
                {
                    // Small, Indexed
                    ValidateTopologyIndexCount(numIndices, meshTopology);

                    const uint16_t* const indices = static_cast<const uint16_t*>(pIndices.get());
                    CalculateIndexedTangents(pos, numVertices, indices, numIndices, uv, meshTopology, cancellationToken, tan1, tan2);
                }
                else if (pIndices)
                {
                    // Big, Indexed
                    ValidateTopologyIndexCount(numIndices, meshTopology);

                    const uint32_t* const indices = static_cast<const uint32_t*>(pIndices.get());
                    CalculateIndexedTangents(pos, numVertices, indices, numIndices, uv, meshTopology, cancellationToken, tan1, tan2);
                }
                else
                {
                    // Non-indexed
                    ValidateTopologyVertexCount(numVertices, meshTopology);
                    CalculateNonIndexedTangents(pos, numVertices, uv, meshTopology, cancellationToken, tan1, tan2);
                }
            }
            catch (Utils::CancelledException const&)
            {
                throw;
            }
            catch (GeometryProcessingException const& geomExc)
            {
                BabylonUnusedLocal(geomExc);
                TRACE_IMPORTANT(GeometryUtils, geomExc.m_message.c_str());
                completionCallback(nullptr, callbackUserData);
                return;
            }
            catch (...)
            {
                TRACE_IMPORTANT(GeometryUtils, "ComputeTangents threw exception");
                completionCallback(nullptr, callbackUserData);
                return;
            }

            FinalizeVertexTangents(outputTangents.get(), numVertices, normals, tan1, tan2, flipTangents);
            completionCallback(outputTangents, callbackUserData);
        }

        //--------------------------------------------------------------------------------------
        void CalculateNonIndexedeTangentsAndNormals(
            const Vector3* const vertices,
            uint32_t numVertices,
            const Vector2* const uv,
            GeometryUtils::TriangularMeshTopology meshTopology,
            Utils::ICancellationTokenPtr const& cancellationToken,
            Vector3* const normals,
            Vector3* const tan1,
            Vector3* const tan2)
        {
            bool isTriangleStrip = meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip;
            uint32_t offset = isTriangleStrip ? TriangleStripNextTriangleOffset : TriangleListNextTriangleOffset;
            uint32_t boundary = isTriangleStrip ? TriangleStripBoundary : TriangleListBoundary;

            for (uint32_t v = 0, i = 0; v < numVertices - boundary; v += offset, ++i)
            {
                if (cancellationToken && i % CancellationTokenCheckFrequency == 0)
                {
                    cancellationToken->CheckCancelledAndThrow();
                }

                bool invert = isTriangleStrip && (v % 2 == 1);  // Every other triangle has reverse winding
                ComputeTriangleTangents(vertices, uv, v, v + 1, v + 2, invert, tan1, tan2);
                CalculateTriangleNormal(vertices, v, v + 1, v + 2, invert, normals);
            }
        }

        //--------------------------------------------------------------------------------------
        template<typename IndexType>
        void CalculateIndexedTangentsAndNormals(
            const Vector3* const vertices,
            uint32_t numVertices,
            const IndexType* const indices,
            uint32_t numIndices,
            const Vector2* const uv,
            GeometryUtils::TriangularMeshTopology meshTopology,
            Utils::ICancellationTokenPtr const& cancellationToken,
            Vector3* const normals,
            Vector3* const tan1,
            Vector3* const tan2
        )
        {
            bool isTriangleStrip = meshTopology == GeometryUtils::TriangularMeshTopology::TriangleStrip;
            uint32_t offset = isTriangleStrip ? TriangleStripNextTriangleOffset : TriangleListNextTriangleOffset;
            uint32_t boundary = isTriangleStrip ? TriangleStripBoundary : TriangleListBoundary;

            for (uint32_t t = 0, i = 0; t < numIndices - boundary; t += offset, ++i)
            {
                IndexType i0 = indices[t + 0];
                IndexType i1 = indices[t + 1];
                IndexType i2 = indices[t + 2];

                // Avoid out-of-bounds array access from incorrect indices
                if (i0 >= numVertices || i1 >= numVertices || i2 >= numVertices)
                {
                    throw GeometryProcessingException("Index out of range while computing tangents and normals");
                }

                if (cancellationToken && i % CancellationTokenCheckFrequency == 0)
                {
                    cancellationToken->CheckCancelledAndThrow();
                }

                bool invert = isTriangleStrip && (t % 2 == 1);  // Every other triangle has reverse winding
                ComputeTriangleTangents(vertices, uv, i0, i1, i2, invert, tan1, tan2);
                CalculateTriangleNormal(vertices, i0, i1, i2, invert, normals);
            }
        }

        //--------------------------------------------------------------------------------------
        void GeometryUtils::ComputeTangentsAndNormals(
            std::shared_ptr<Vector3>        pVerts,
            std::shared_ptr<Vector2>        pUVs,
            uint32_t                        numVertices,
            std::shared_ptr<void>           pIndices,
            uint32_t                        numIndices,
            bool                            bigIndices,
            TriangularMeshTopology          meshTopology,
            bool                            flipTangents,
            NormTangCompletionCallback      completionCallback,
            void*                           callbackUserData,
            Utils::ICancellationTokenPtr const&  cancellationToken)
        {
            // Src: http://www.terathon.com/code/tangent.html
            // :TODO: Can and should be optimized...

            if (!ValidateVertexCount(numVertices, "ComputeTangentsAndNormals"))
            {
                completionCallback(nullptr, nullptr, callbackUserData);
                return;
            }

            auto outputTangents = std::shared_ptr<Vector4>(
                (Vector4*)_aligned_malloc(sizeof(Vector4) * numVertices, 16),
                [](void* data) { _aligned_free(data); });

            if (outputTangents.get() == nullptr)
            {
                throw std::bad_alloc();
            }

            memset(outputTangents.get(), 0, sizeof(Vector4) * numVertices);

            std::vector<Vector3> tangents1(numVertices * 2);

            Vector3* const tan1 = tangents1.data();
            Vector3* const tan2 = tan1 + numVertices;

            auto normals = std::shared_ptr<Vector3>(
                (Vector3*)_aligned_malloc(sizeof(Vector3) * numVertices, 16),
                [](void* data) { _aligned_free(data); });

            if (normals.get() == nullptr)
            {
                throw std::bad_alloc();
            }

            memset(normals.get(), 0, sizeof(Vector3) * numVertices);

            const Vector3* const pos = pVerts.get();
            const Vector2* const uv = pUVs.get();

            try
            {
                if (!bigIndices)
                {
                    // Small, Indexed
                    ValidateTopologyIndexCount(numIndices, meshTopology);

                    const uint16_t* const indices = static_cast<const uint16_t*>(pIndices.get());
                    CalculateIndexedTangentsAndNormals(pos, numVertices, indices, numIndices, uv, meshTopology, cancellationToken, normals.get(), tan1, tan2);
                }
                else if (pIndices)
                {
                    // Big, Indexed
                    ValidateTopologyIndexCount(numIndices, meshTopology);

                    const uint32_t* const indices = static_cast<const uint32_t*>(pIndices.get());
                    CalculateIndexedTangentsAndNormals(pos, numVertices, indices, numIndices, uv, meshTopology, cancellationToken, normals.get(), tan1, tan2);
                }
                else
                {
                    // Non-indexed
                    ValidateTopologyVertexCount(numVertices, meshTopology);
                    CalculateNonIndexedeTangentsAndNormals(pos, numVertices, uv, meshTopology, cancellationToken, normals.get(), tan1, tan2);
                }
            }
            catch (Utils::CancelledException const&)
            {
                throw;
            }
            catch (GeometryProcessingException const& geomExc)
            {
                BabylonUnusedLocal(geomExc);
                TRACE_IMPORTANT(GeometryUtils, geomExc.m_message.c_str());
                completionCallback(nullptr, nullptr, callbackUserData);
                return;
            }
            catch (...)
            {
                TRACE_IMPORTANT(GeometryUtils, "ComputeTangentsAndNormals threw exception");
                completionCallback(nullptr, nullptr, callbackUserData);
                return;
            }

            FinalizeVertexTangents(outputTangents.get(), numVertices, normals.get(), tan1, tan2, flipTangents);
            completionCallback(outputTangents, normals, callbackUserData);
        }

        //--------------------------------------------------------------------------------------
        // various functors and helpers for ordering / hashing
        //--------------------------------------------------------------------------------------

        struct compare_edge
        {
            bool operator()(const std::pair<uint32_t, uint32_t>& e1, const std::pair<uint32_t, uint32_t>& e2) const
            {
                return (e1.first != e2.first) ? (e1.first < e2.first) : (e1.second < e2.second);
            }
        };

        struct CDirectionalEdge
        {
            uint32_t endPoint1;
            uint32_t endPoint2;
            uint32_t startTriangle;
            uint32_t nTriangleCount;
        };

        struct hashFunc
        {
            size_t operator()(const Vector3 &k) const
            {
                size_t h1 = std::hash<float>()(k.x);
                size_t h2 = std::hash<float>()(k.y);
                size_t h3 = std::hash<float>()(k.z);
                return (h1 ^ (h2 << 1)) ^ h3;
            }
        };

        struct equalsFunc
        {
            bool operator()(const Vector3& lhs, const Vector3& rhs) const
            {
                return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
            }
        };


        //--------------------------------------------------------------------------------------
        static void VerifyManifoldness(
            bool bReturnOnFirstError,
            GeometryUtils::TriangleMeshAnalysisResults& ioResults,
            std::map<std::pair<uint32_t, uint32_t>, CDirectionalEdge, compare_edge> const& EdgeMap,
            std::vector<std::pair<uint32_t, uint32_t>>* nonManifoldEdges,
            std::vector<uint32_t>* nonManifoldTriangles)
        {
            for (auto iter : EdgeMap)
            {
                if (iter.second.nTriangleCount != 2)
                {
                    if (iter.second.nTriangleCount < 2)
                    {
                        ioResults.BoundaryEdges = true;
                    }
                    else
                    {
                        ioResults.InternalEdges = true;
                    }

                    if (nonManifoldEdges)
                    {
                        nonManifoldEdges->push_back(iter.first);
                    }
                    if (nonManifoldTriangles)
                    {
                        nonManifoldTriangles->push_back(iter.second.startTriangle);
                    }
                    if (bReturnOnFirstError)
                    {
                        return;
                    }
                }
            }

            if (nonManifoldTriangles)
            {
                // sort and remove duplicated triangle indices
                std::vector<uint32_t>::iterator it;
                std::sort(nonManifoldTriangles->begin(), nonManifoldTriangles->end());
                it = std::unique(nonManifoldTriangles->begin(), nonManifoldTriangles->end());
                nonManifoldTriangles->resize(std::distance(nonManifoldTriangles->begin(), it));
            }

            return;
        }

        //--------------------------------------------------------------------------------------
        static bool VerifyOrientation(
            uint32_t const* triangleIndices,
            uint32_t nTriangleIndices,
            bool bReturnOnFirstError,
            std::map<std::pair<uint32_t, uint32_t>, CDirectionalEdge, compare_edge>& EdgeMap,
            std::vector<uint32_t>* reversedNormalTriangles)
        {
            bool bIsOriented = true;

            for (uint32_t iTri = 0; (iTri + 2) < nTriangleIndices; iTri += 3)
            {
                uint32_t nID[3] = { 0, 0, 0 };
                nID[0] = triangleIndices[iTri];
                nID[1] = triangleIndices[iTri + 1];
                nID[2] = triangleIndices[iTri + 2];

                if (nID[0] == nID[1] || nID[1] == nID[2] || nID[0] == nID[2]) continue; // skip process triangle with dupplicated vertex indices

                for (uint32_t i = 0; i < 3; ++i)
                {
                    uint32_t e1 = 0, e2 = 0;
                    if (nID[i] < nID[(i + 1) % 3])
                    {
                        e1 = nID[i];
                        e2 = nID[(i + 1) % 3];
                    }
                    else
                    {
                        e2 = nID[i];
                        e1 = nID[(i + 1) % 3];
                    }

                    std::pair<uint32_t, uint32_t> edge(e1, e2);

                    std::map<std::pair<uint32_t, uint32_t>, CDirectionalEdge, compare_edge>::iterator iter = EdgeMap.find(edge);
                    if (iter != EdgeMap.end())
                    {
                        iter->second.nTriangleCount += 1;

                        if (iter->second.endPoint1 == nID[i] && iter->second.endPoint2 == nID[(i + 1) % 3])
                        {
                            bIsOriented = false;
                            if (bReturnOnFirstError)
                            {
                                return bIsOriented;
                            }
                            if (reversedNormalTriangles)
                            {
                                reversedNormalTriangles->push_back(iTri / 3);
                                reversedNormalTriangles->push_back(iter->second.startTriangle);
                            }
                        }
                    }
                    else
                    {
                        CDirectionalEdge directionalEdge;
                        directionalEdge.nTriangleCount = 1;
                        directionalEdge.endPoint1 = nID[i];
                        directionalEdge.endPoint2 = nID[(i + 1) % 3];
                        directionalEdge.startTriangle = iTri / 3;
                        EdgeMap.insert({ edge, directionalEdge });
                    }
                }
            }

            if (reversedNormalTriangles)
            {
                // sort and remove duplicated triangle indices
                std::vector<uint32_t>::iterator it;
                std::sort(reversedNormalTriangles->begin(), reversedNormalTriangles->end());
                it = std::unique(reversedNormalTriangles->begin(), reversedNormalTriangles->end());
                reversedNormalTriangles->resize(std::distance(reversedNormalTriangles->begin(), it));
            }

            return bIsOriented;
        }

        //--------------------------------------------------------------------------------------
        static bool VerifyDuplicatedVertexIndices(
            uint32_t const* triangleIndices,
            uint32_t nTriangleIndices,
            bool bReturnOnFirstError,
            std::vector<uint32_t>* duplicatedVertexIndices)
        {
            if (0 == nTriangleIndices)
            {
                return true;
            }

            bool bHasDuplicatedVertexIndices = false;

            for (uint32_t iTri = 0; (iTri + 2) < nTriangleIndices; iTri += 3)
            {
                uint32_t nID[3] = { 0, 0, 0 };

                nID[0] = triangleIndices[iTri];
                nID[1] = triangleIndices[iTri + 1];
                nID[2] = triangleIndices[iTri + 2];

                if (nID[0] == nID[1] || nID[1] == nID[2] || nID[0] == nID[2])
                {
                    bHasDuplicatedVertexIndices = true;
                    if (duplicatedVertexIndices)
                    {
                        duplicatedVertexIndices->push_back(iTri / 3);
                    }

                    if (bReturnOnFirstError)
                    {
                        return bHasDuplicatedVertexIndices;
                    }
                }
            }

            if (duplicatedVertexIndices)
            {
                // sort and remove duplicated triangles
                std::vector<uint32_t>::iterator it;
                std::sort(duplicatedVertexIndices->begin(), duplicatedVertexIndices->end());
                it = std::unique(duplicatedVertexIndices->begin(), duplicatedVertexIndices->end());
                duplicatedVertexIndices->resize(std::distance(duplicatedVertexIndices->begin(), it));
            }

            return bHasDuplicatedVertexIndices;
        }

        //--------------------------------------------------------------------------------------
        struct GeometryUtils::TriangleMeshAnalysisContext::Impl
        {
            std::vector<uint32_t> remappedTriangleIndices;
            std::unordered_map<Vector3,uint32_t,hashFunc,equalsFunc> uniqueVertPositions;
            size_t OOBIndexMeshCount = 0;

            bool AddMesh(Vector3 const* vertices,size_t nVertices,uint32_t const* triangleIndices,size_t nTriangleIndices)
            {
                for(uint32_t triIndex = 0; triIndex < nTriangleIndices; ++triIndex)
                {
                    if(triangleIndices[triIndex] >= nVertices)
                    {
                        // If mesh contains any out-of-bounds indices, we can't sensibly analyse it - ignore the entire mesh
                        OOBIndexMeshCount += 1;
                        return false;
                    }
                }

                uniqueVertPositions.reserve(uniqueVertPositions.size() + nTriangleIndices);
                remappedTriangleIndices.reserve(remappedTriangleIndices.size() + nTriangleIndices);

                // Remap triangle indices such that duplicated positions alias to the same index
                for(uint32_t triIndex = 0; triIndex < nTriangleIndices; ++triIndex)
                {
                    auto v3 = vertices[triangleIndices[triIndex]];
                    auto it = uniqueVertPositions.find(v3);
                    if(it == uniqueVertPositions.end())
                    {
                        it = uniqueVertPositions.insert({v3,uint32_t(uniqueVertPositions.size())}).first;
                    }
                    remappedTriangleIndices.emplace_back(uint32_t(it->second));
                }

                return true;
            }

            //--------------------------------------------------------------------------------------
            TriangleMeshAnalysisResults Analyse(
                bool bReturnOnFirstError,
                std::vector<uint32_t>* duplicatedVertexIndices,
                std::vector<std::pair<uint32_t,uint32_t>>* nonManifoldEdges,
                std::vector<uint32_t>* nonManifoldTriangles,
                std::vector<uint32_t>* reversedNormalTriangles) const
            {
                if(OOBIndexMeshCount > 0)
                {
                    // If any mesh contains any out-of-bounds indices, we can't sensibly analyse anything - ignore the entire set
                    TriangleMeshAnalysisResults results;
                    results.VertexIndexOutOfBounds = true;
                    return results;
                }

                uint32_t const* triangleIndices = remappedTriangleIndices.data();
                uint32_t nTriangleIndices = static_cast<uint32_t>(remappedTriangleIndices.size());
                return AnalyseTriangleMesh(triangleIndices, nTriangleIndices, bReturnOnFirstError,duplicatedVertexIndices,nonManifoldEdges,nonManifoldTriangles,reversedNormalTriangles);
            }
        };

        //--------------------------------------------------------------------------------------
        GeometryUtils::TriangleMeshAnalysisContext::TriangleMeshAnalysisContext() : m_pImpl( std::make_unique<Impl>() )
        {
        }

        //--------------------------------------------------------------------------------------
        GeometryUtils::TriangleMeshAnalysisContext::~TriangleMeshAnalysisContext()
        {
        }

        //--------------------------------------------------------------------------------------
        bool GeometryUtils::TriangleMeshAnalysisContext::AddMesh(Vector3 const* vertices,size_t nVertices,uint32_t const* triangleIndices,size_t nTriangleIndices)
        {
            return m_pImpl->AddMesh(vertices,nVertices,triangleIndices,nTriangleIndices);
        }

        //--------------------------------------------------------------------------------------
        GeometryUtils::TriangleMeshAnalysisResults GeometryUtils::TriangleMeshAnalysisContext::Analyse(
            bool bReturnOnFirstError,
            std::vector<uint32_t>* duplicatedVertexIndices,
            std::vector<std::pair<uint32_t,uint32_t>>* nonManifoldEdges,
            std::vector<uint32_t>* nonManifoldTriangles,
            std::vector<uint32_t>* reversedNormalTriangles) const
        {
            return m_pImpl->Analyse(bReturnOnFirstError,duplicatedVertexIndices,nonManifoldEdges,nonManifoldTriangles,reversedNormalTriangles);
        }

        //--------------------------------------------------------------------------------------
        GeometryUtils::TriangleMeshAnalysisResults GeometryUtils::AnalyseTriangleMesh(
            Vector3 const* vertices, size_t nVertices,
            uint32_t const* triangleIndices, size_t nTriangleIndices,
            bool bReturnOnFirstError,
            std::vector<uint32_t>* duplicatedVertexIndices,
            std::vector<std::pair<uint32_t, uint32_t>>* nonManifoldEdges,
            std::vector<uint32_t>* nonManifoldTriangles,
            std::vector<uint32_t>* reversedNormalTriangles)
        {
            GeometryUtils::TriangleMeshAnalysisContext context;
            context.AddMesh(vertices,nVertices,triangleIndices,nTriangleIndices);
            return context.Analyse(bReturnOnFirstError,duplicatedVertexIndices,nonManifoldEdges,nonManifoldTriangles,reversedNormalTriangles);
        }


        //--------------------------------------------------------------------------------------
        GeometryUtils::TriangleMeshAnalysisResults GeometryUtils::AnalyseTriangleMesh(
            uint32_t const* triangleIndices, size_t nTriangleIndices,
            bool bReturnOnFirstError,
            std::vector<uint32_t>* duplicatedVertexIndices,
            std::vector<std::pair<uint32_t, uint32_t>>* nonManifoldEdges,
            std::vector<uint32_t>* nonManifoldTriangles,
            std::vector<uint32_t>* reversedNormalTriangles)
        {
            TriangleMeshAnalysisResults results;

            bool bHasDuplicatedVertexIndices = VerifyDuplicatedVertexIndices(triangleIndices, (uint32_t)nTriangleIndices, bReturnOnFirstError, duplicatedVertexIndices);
            if (bHasDuplicatedVertexIndices)
            {
                results.DegenerateTris = true;
                if (bReturnOnFirstError)
                {
                    return results;
                }
            }

            std::map<std::pair<uint32_t, uint32_t>, CDirectionalEdge, compare_edge> EdgeMap;
            bool bIsOriented = VerifyOrientation(triangleIndices, (uint32_t)nTriangleIndices, bReturnOnFirstError, EdgeMap, reversedNormalTriangles);
            if (!bIsOriented)
            {
                results.InconsistentWindingOrder = true;
                if (bReturnOnFirstError)
                {
                    return results;
                }
            }

            VerifyManifoldness(bReturnOnFirstError, results, EdgeMap, nonManifoldEdges, nonManifoldTriangles);
            return results;
        }
    } // namespace Framework

} // namespace Babylon
