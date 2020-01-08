/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Math/SimpleMath.h>

#include <Asset3D/ITraversable.h>
#include <Asset3D/BoundingBox.h>
#include <Asset3D/MaterialDescriptor.h>

namespace Spectre
{
    namespace Transcoder
    {
        enum class GeometryTopology
        {
            kTriangles,
            kPoints,
            kLines
        };

        // TODO: Generate Faceted Normals
        // TODO: Generate Smooth Normals
        // TODO: Add support for uint16_t indices
        class Geometry : public ITraversableBase
        {
        public:
            Geometry(
                std::shared_ptr<MaterialDescriptor> material = nullptr,
                const BoundingBox& boundingBox = BoundingBox::Uninitialized)
                : ITraversableBase(),
                m_material(std::move(material)),
                m_boundingBox(boundingBox),
                m_topology(GeometryTopology::kTriangles)
            {
            }

            // Material
            const std::shared_ptr<MaterialDescriptor>& GetMaterial() const { return m_material; }
            bool HasMaterial() const { return static_cast<bool>(m_material); }

            // Bounding Box
            void CalculateBoundingBox();
            const BoundingBox& GetBoundingBox() const { return m_boundingBox; }
            virtual BoundingBox CalcTopDownBounds(const Spectre::Utils::Math::Matrix& transform) const;

            // Topology
            GeometryTopology GetTopology() const { return m_topology; }
            void SetTopology(GeometryTopology topology) { m_topology = topology; }

            // Buffer **SET** from a vector
            void SetIndices(const std::vector<uint16_t>& indices) { m_indices = std::vector<uint32_t>(indices.begin(), indices.end()); }
            void SetIndices(std::vector<uint32_t> indices) { m_indices = std::move(indices); }
            void SetPositions(std::vector<Spectre::Utils::Math::Vector3> positions) { m_positions = std::move(positions); }
            void SetNormals(std::vector<Spectre::Utils::Math::Vector3> normals) { m_normals = std::move(normals); }
            void SetUv0s(std::vector<Spectre::Utils::Math::Vector2> uv0s) { m_uv0s = std::move(uv0s); }
            void SetUv1s(std::vector<Spectre::Utils::Math::Vector2> uv1s) { m_uv1s = std::move(uv1s); }
            void SetTangents(std::vector<Spectre::Utils::Math::Vector4> tangents) { m_tangents = std::move(tangents); }
            void SetColors(std::vector<uint32_t> colors) { m_colors = std::move(colors); }
            void SetJoints(std::vector<uint32_t>&& jointIndices, std::vector<uint32_t>&& jointWeights);

            // Buffer **SET** from a pointer
            void SetIndices(const uint16_t* indices, size_t indexCount);
            void SetIndices(const uint32_t* indices, size_t indexCount);
            void SetPositions(const float* positions, size_t positionCount);
            void SetNormals(const float* normals, size_t normalCount);
            void SetUv0s(const float* uv0s, size_t uv0Count);
            void SetUv1s(const float* uv1s, size_t uv1Count);
            void SetTangents(const float* tangents, size_t tangentCount);
            void SetColors(const uint32_t* colors, size_t colorCount);

            // Buffer **APPEND** a single element
            void AddIndex(uint32_t index) { m_indices.push_back(index); }
            void AddPosition(const Spectre::Utils::Math::Vector3& position) { m_positions.push_back(position); }
            void AddNormal(const Spectre::Utils::Math::Vector3& normal) { m_normals.push_back(normal); }
            void AddUv0(const Spectre::Utils::Math::Vector2& uv0) { m_uv0s.push_back(uv0); }
            void AddUv1(const Spectre::Utils::Math::Vector2& uv1) { m_uv1s.push_back(uv1); }
            void AddTangent(const Spectre::Utils::Math::Vector4& tangent) { m_tangents.push_back(tangent); }
            void AddColor(uint32_t color) { m_colors.push_back(color); }
            void AddJoint(uint32_t jointIndex, uint32_t jointWeight)
            {
                m_jointIndices.push_back(jointIndex);
                m_jointWeights.push_back(jointWeight);
            }
            void AddMorphTargetPositions(std::vector<float>&& morphPositions);
            void AddMorphTargetNormals(std::vector<float>&& morphNormals);
            void AddMorphTargetTangents(std::vector<float>&& morphTangents);

            // Buffer **ACCESSORS**
            const std::vector<uint32_t>& GetIndices() const { return m_indices; }
            const std::vector<Spectre::Utils::Math::Vector3>& GetPositions() const { return m_positions; }
            const std::vector<Spectre::Utils::Math::Vector3>& GetNormals() const { return m_normals; }
            const std::vector<Spectre::Utils::Math::Vector2>& GetUv0s() const { return m_uv0s; }
            const std::vector<Spectre::Utils::Math::Vector2>& GetUv1s() const { return m_uv1s; }
            const std::vector<Spectre::Utils::Math::Vector4>& GetTangents() const { return m_tangents; }
            const std::vector<uint32_t>& GetColors() const { return m_colors; }
            const std::vector<uint32_t>& GetJointIndices() const { return m_jointIndices; }
            const std::vector<uint32_t>& GetJointWeights() const { return m_jointWeights; }
            const std::vector<std::vector<float>>& GetMorphTargetPositions() const { return m_morphTargetPositions; }
            const std::vector<std::vector<float>>& GetMorphTargetNormals() const { return m_morphTargetNormals; }
            const std::vector<std::vector<float>>& GetMorphTargetTangents() const { return m_morphTargetTangents; }

            bool HasIndices()  const { return !m_indices.empty(); }
            bool HasPositions() const { return !m_positions.empty(); }
            bool HasNormals()  const { return !m_normals.empty(); }
            bool HasUv0s()     const { return !m_uv0s.empty(); }
            bool HasUv1s()     const { return !m_uv1s.empty(); }
            bool HasTangents() const { return !m_tangents.empty(); }
            bool HasColors()   const { return !m_colors.empty(); }
            bool HasSkinnedAnimation() const { return !m_jointIndices.empty() && !m_jointWeights.empty(); }
            bool HasMorphAnimation() const { return !m_morphTargetPositions.empty() || !m_morphTargetNormals.empty() || !m_morphTargetTangents.empty(); }

            // UTILITY METHODS

            // TODO: Replace with operator==?
            bool Compare(const Geometry& other) const;

            size_t GetIndexCount() const { return m_indices.size(); }
            size_t GetVertexCount() const { return m_positions.size(); }

            // DEPRECATED: Geometry will be generalized away from Triangles
            size_t GetTriangleCount() const
            {
                if (m_indices.size() > 0)
                {
                    return m_indices.size() / 3;
                }
                return m_positions.size() / 3;
            }

            size_t GetVertexBufferSize() const;

            std::vector<uint32_t> GetOrGenerateIndices() const;

        private:
            std::shared_ptr<MaterialDescriptor> m_material;
            BoundingBox m_boundingBox;
            GeometryTopology m_topology;

            std::vector<uint32_t> m_indices;
            std::vector<Spectre::Utils::Math::Vector3> m_positions;
            std::vector<Spectre::Utils::Math::Vector3> m_normals;
            std::vector<Spectre::Utils::Math::Vector2> m_uv0s;
            std::vector<Spectre::Utils::Math::Vector2> m_uv1s;
            std::vector<Spectre::Utils::Math::Vector4> m_tangents;
            std::vector<uint32_t> m_colors;
            std::vector<uint32_t> m_jointIndices;
            std::vector<uint32_t> m_jointWeights;
            // Each morph target is a contiguous array of floats holding x,y,z target values corresponding to each vertex
            std::vector<std::vector<float>> m_morphTargetPositions;
            std::vector<std::vector<float>> m_morphTargetNormals;
            std::vector<std::vector<float>> m_morphTargetTangents;
        };
    }
}