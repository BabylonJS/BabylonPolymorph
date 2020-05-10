/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <list>

#include <Asset3D/BoundingBox.h>
#include <Asset3D/ITraversable.h>
#include <Asset3D/Geometry.h>

namespace Babylon
{
    namespace Transcoder
    {
        enum class MeshFlags
        {
            None = 0x0,
            // The Asset3D::Mesh represents a Minecraft asset and requires special rendering
            MinecraftMesh = 0x1,
            // The Asset3D::Mesh is a single manifold mesh, but it has been split into multiple Asset3D::Geometry
            // in order to have different materials on different parts of the same mesh
            MultiMaterialMesh = 0x2
        };

        MeshFlags  operator| (MeshFlags lhs, MeshFlags rhs);
        MeshFlags& operator|=(MeshFlags& lhs, MeshFlags rhs);
        MeshFlags  operator& (MeshFlags lhs, MeshFlags rhs);
        MeshFlags& operator&=(MeshFlags& lhs, MeshFlags rhs);

        /*
        * This class stores a number of Geometry objects which represent a Mesh of a 3D asset.
        * It has a bounding box equal to the combined bounding boxes of its Geometry
        */
        class Mesh : public ITraversableWithName
        {
        public:
            Mesh(std::vector<Geometry>&& geometries);
            Mesh(Geometry&& geometry);
            Mesh();

            virtual ~Mesh() = default;

            bool Compare(const Mesh& other);

            std::vector<Geometry>& GetGeometries() { return m_geometries; }
            const std::vector<Geometry>& GetGeometries() const { return m_geometries; }
            void AddGeometry(Geometry&& geometry)
            {
                geometry.CalculateBoundingBox();
                m_boundingBox.Update(geometry.GetBoundingBox());
                m_geometries.push_back(std::move(geometry));
            }

            // Gets the number of Triangles that compose the original Geometry of the Mesh.
            size_t GetTriangleCount() const;

            // Calculates the Bounding Box of the Mesh.
            void SetBoundingBox(const BoundingBox& boundingBox) { m_boundingBox = boundingBox; }
            BoundingBox GetBoundingBox() const { return m_boundingBox; }

            void CalculateBoundingBox();
            BoundingBox CalcTopDownBounds(const Babylon::Utils::Math::Matrix&) const;

            void SetFlags(MeshFlags flags) { m_flags |= flags; }
            MeshFlags GetFlags() const { return m_flags; }
            bool HasFlags(MeshFlags flags) const { return (m_flags & flags) == flags; }

            size_t GetVertexCount() const;
            size_t GetIndexCount() const;

            const std::vector<float>& GetMorphWeights() const { return m_morphWeights; }
            void SetMorphWeights(const std::vector<float>& weights) { m_morphWeights = weights; }

        protected:
            std::vector<Geometry> m_geometries;
            BoundingBox m_boundingBox = BoundingBox::Uninitialized;
            MeshFlags m_flags = MeshFlags::None;
            std::vector<float> m_morphWeights;
        };
    }
}
