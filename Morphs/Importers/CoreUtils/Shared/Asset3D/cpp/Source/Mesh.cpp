/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <algorithm>

#include <Asset3D/Mesh.h>

DEFINE_TRACE_AREA(Asset3D_Mesh, 0);

using namespace Spectre::Transcoder;

Mesh::Mesh(std::vector<Geometry>&& geometries)
    : ITraversableWithName(),
    m_geometries(std::move(geometries))
{
    CalculateBoundingBox();
}

Mesh::Mesh(Geometry&& geometry)
    : ITraversableWithName()
{
    m_geometries.push_back(std::move(geometry));
    CalculateBoundingBox();
}

Mesh::Mesh()
    : ITraversableWithName(),
    m_geometries(std::vector<Geometry>()),
    m_boundingBox(BoundingBox::Zero)
{
}

size_t Mesh::GetTriangleCount() const
{
    size_t count = 0;
    for (auto& geometry : m_geometries)
    {
        count += geometry.GetTriangleCount();
    }
    return count;
}

size_t Mesh::GetVertexCount() const
{
    size_t count = 0;
    for (auto& geometry : m_geometries)
    {
        count += geometry.GetVertexCount();
    }
    return count;
}

size_t Mesh::GetIndexCount() const
{
    size_t count = 0;
    for (auto& geometry : m_geometries)
    {
        count += geometry.GetIndexCount();
    }
    return count;
}

void Mesh::CalculateBoundingBox()
{
    for (auto& geometry : m_geometries)
    {
        geometry.CalculateBoundingBox();
        m_boundingBox.Update(geometry.GetBoundingBox());
    }
}

BoundingBox Mesh::CalcTopDownBounds(const Spectre::Utils::Math::Matrix& transform) const
{
    BoundingBox boundingBox;
    for (auto& geometry : m_geometries)
    {
        boundingBox.Update(geometry.CalcTopDownBounds(transform));
    }
    return boundingBox;
}

bool Mesh::Compare(const Mesh& rhs)
{
    return GetName() == rhs.GetName()
        && m_flags == rhs.m_flags
        && m_boundingBox == rhs.m_boundingBox
        && std::equal(
        m_geometries.begin(), m_geometries.end(),
        rhs.m_geometries.begin(), rhs.m_geometries.end(),
        [](const Geometry& a, const Geometry& b)
    {
        return a.Compare(b);
    });
}

MeshFlags Spectre::Transcoder::operator|(MeshFlags lhs, MeshFlags rhs)
{
    const auto result =
        static_cast<std::underlying_type_t<MeshFlags>>(lhs) |
        static_cast<std::underlying_type_t<MeshFlags>>(rhs);

    return static_cast<MeshFlags>(result);
}

MeshFlags& Spectre::Transcoder::operator|=(MeshFlags& lhs, MeshFlags rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

MeshFlags Spectre::Transcoder::operator&(MeshFlags lhs, MeshFlags rhs)
{
    const auto result =
        static_cast<std::underlying_type_t<MeshFlags>>(lhs) &
        static_cast<std::underlying_type_t<MeshFlags>>(rhs);

    return static_cast<MeshFlags>(result);
}

MeshFlags& Spectre::Transcoder::operator&=(MeshFlags& lhs, MeshFlags rhs)
{
    lhs = lhs & rhs;
    return lhs;
}