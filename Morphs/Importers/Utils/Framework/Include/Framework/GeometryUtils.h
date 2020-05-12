/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.        *
*                                                       *
********************************************************/
#pragma once

#include "Pointers.h"
#include "Types.h"
#include "Cancellation.h"

#include <CoreUtils/Cancellation.h>
#include <CoreUtils/BabylonSDK.h>
#include <CoreUtils/Math/SimpleMath.h>

#include <cstdint>
#include <memory>

namespace Babylon
{
    using Utils::Math::Vector2;
    using Utils::Math::Vector3;
    using Utils::Math::Vector4;

    namespace Framework
    {
        /**
        * Utility methods for dealing with geometry
        */
        class GeometryUtils
        {
            typedef std::function<void BABYLON_SDK_CALL (std::shared_ptr<Vector3> const&, void*)> NormalsCompletionCallback;
            typedef std::function<void BABYLON_SDK_CALL (std::shared_ptr<Vector4> const&, void*)> TangentsCompletionCallback;
            typedef std::function<void BABYLON_SDK_CALL (std::shared_ptr<Vector4> const&, std::shared_ptr<Vector3> const&, void*)> NormTangCompletionCallback;

        public:
            static const uint32_t MaxAllowedVertices = 0x4000000;

            enum class TriangularMeshTopology
            {
                TriangleList,
                TriangleStrip
            };

            static void ComputeNormals(std::shared_ptr<Vector3> pVerts,
                                       uint32_t numVertices,
                                       std::shared_ptr<void> pIndices, uint32_t numIndices,
                                       bool bigIndices,
                                       TriangularMeshTopology meshTopology,
                                       NormalsCompletionCallback completionCallback,
                                       void* callbackUserData,
                                       Utils::ICancellationTokenPtr const& cancellationToken);

            static void ComputeNormals(const float* vertices,
                                        uint32_t vertCount,
                                        const uint32_t* indices,
                                        uint32_t indexCount,
                                        float* normals);

            static void ComputeTangents(std::shared_ptr<Vector3> pVerts,
                                        std::shared_ptr<Vector2> pUVs,
                                        std::shared_ptr<Vector3> pNormals,
                                        uint32_t numVertices,
                                        std::shared_ptr<void> pIndices,
                                        uint32_t numIndices,
                                        bool bigIndices,
                                        TriangularMeshTopology meshTopology,
                                        bool flipTangentHandedness,
                                        TangentsCompletionCallback completionCallback,
                                        void* callbackUserData,
                                        Utils::ICancellationTokenPtr const& cancellationToken);

            static void ComputeTangentsAndNormals(std::shared_ptr<Vector3> pVerts,
                                                  std::shared_ptr<Vector2> pUVs,
                                                  uint32_t numVertices,
                                                  std::shared_ptr<void> pIndices,
                                                  uint32_t numIndices,
                                                  bool bigIndices,
                                                  TriangularMeshTopology meshTopology,
                                                  bool flipTangentHandedness,
                                                  NormTangCompletionCallback completionCallback,
                                                  void* callbackUserData,
                                                  Utils::ICancellationTokenPtr const& cancellationToken);

            struct TriangleMeshAnalysisResults
            {
                TriangleMeshAnalysisResults(bool vertexIndexOutOfBounds = false,
                                            bool degenerateTris = false,
                                            bool inconsistentWindingOrder = false,
                                            bool boundaryEdges = false,
                                            bool internalEdges = false)
                : VertexIndexOutOfBounds(vertexIndexOutOfBounds),
                  DegenerateTris(degenerateTris),
                  InconsistentWindingOrder(inconsistentWindingOrder),
                  BoundaryEdges(boundaryEdges),
                  InternalEdges(internalEdges) {}

                bool operator==(const TriangleMeshAnalysisResults& other) const
                {
                    return  (VertexIndexOutOfBounds == other.VertexIndexOutOfBounds) &&
                            (DegenerateTris == other.DegenerateTris) &&
                            (InconsistentWindingOrder == other.InconsistentWindingOrder) &&
                            (BoundaryEdges == other.BoundaryEdges) &&
                            (InternalEdges == other.InternalEdges);
                }

                bool VertexIndexOutOfBounds;
                bool DegenerateTris;
                bool InconsistentWindingOrder;
                bool BoundaryEdges;
                bool InternalEdges;

                bool IsWatertight() const
                {
                    return !(VertexIndexOutOfBounds | DegenerateTris | InconsistentWindingOrder | BoundaryEdges | InternalEdges);
                }
            };

            struct TriangleMeshAnalysisContext
            {
                TriangleMeshAnalysisContext();
                ~TriangleMeshAnalysisContext();

                // Add a mesh to be included in the analysis
                bool AddMesh(Vector3 const* vertices,size_t nVertices,
                             uint32_t const* triangleIndices,size_t nTriangleIndices);

                // Perform the analysis
                TriangleMeshAnalysisResults Analyse(bool bReturnOnFirstError = true,
                                                    std::vector<uint32_t>* duplicatedVertexIndices = nullptr,
                                                    std::vector<std::pair<uint32_t,uint32_t>>* nonManifoldEdges = nullptr,
                                                    std::vector<uint32_t>* nonManifoldTriangles = nullptr,
                                                    std::vector<uint32_t>* reversedNormalTriangles = nullptr) const;

            private:
                // Private implementation
                struct Impl;

                std::unique_ptr<Impl> m_pImpl;
            };

            /// Check if mesh triangles have area, are orientable, and are manifold
            static TriangleMeshAnalysisResults AnalyseTriangleMesh(Vector3 const* vertices, size_t nVertices,
                                                                   uint32_t const* triangleIndices, size_t nTriangleIndices,
                                                                   bool bReturnOnFirstError = true,
                                                                   std::vector<uint32_t>* duplicatedVertexIndices = nullptr,
                                                                   std::vector<std::pair<uint32_t, uint32_t>>* nonManifoldEdges = nullptr,
                                                                   std::vector<uint32_t>* nonManifoldTriangles = nullptr,
                                                                   std::vector<uint32_t>* reversedNormalTriangles = nullptr);

            /// Check if mesh triangles have area, are orientable, and are manifold
            static TriangleMeshAnalysisResults AnalyseTriangleMesh(uint32_t const* triangleIndices, size_t nTriangleIndices,
                                                                   bool bReturnOnFirstError = true,
                                                                   std::vector<uint32_t>* duplicatedVertexIndices = nullptr,
                                                                   std::vector<std::pair<uint32_t, uint32_t>>* nonManifoldEdges = nullptr,
                                                                   std::vector<uint32_t>* nonManifoldTriangles = nullptr,
                                                                   std::vector<uint32_t>* reversedNormalTriangles = nullptr);
        };

    } // End namespace Cool

} // End namespace Babylon
