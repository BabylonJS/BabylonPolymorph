/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <numeric>
#include <vector>

#include <Asset3D/Geometry.h>
#include <CoreUtils/Math/SimpleMath.h>

using namespace Babylon::Transcoder;
using namespace Babylon::Utils::Math;

namespace
{
    template<typename T>
    std::vector<T> ToVector(const float* data, size_t count)
    {
        std::vector<T> collection(count);

        auto dataIndex = data;
        for (size_t i = 0; i < count; i++)
        {
            collection[i] = T(dataIndex);
            dataIndex += sizeof(T) / sizeof(float);
        }

        return collection;
    }
}

bool Geometry::Compare(const Geometry& other) const
{
    // Doesn't compare material or bounding box
    return other.m_indices              == m_indices
        && other.m_positions            == m_positions
        && other.m_normals              == m_normals
        && other.m_uv0s                 == m_uv0s
        && other.m_uv1s                 == m_uv1s
        && other.m_tangents             == m_tangents
        && other.m_colors               == m_colors
        && other.m_jointIndices         == m_jointIndices
        && other.m_jointWeights         == m_jointWeights
        && other.m_morphTargetPositions == m_morphTargetPositions
        && other.m_morphTargetNormals   == m_morphTargetNormals
        && other.m_morphTargetTangents  == m_morphTargetTangents;
}

// Only used for Telemetry
size_t Geometry::GetVertexBufferSize() const
{
    return
        sizeof(m_positions[0]) * m_positions.size() +
        sizeof(m_normals[0]) * m_normals.size() +
        sizeof(m_uv0s[0]) * m_uv0s.size() +
        sizeof(m_uv1s[0]) * m_uv1s.size() +
        sizeof(m_tangents[0]) * m_tangents.size() +
        sizeof(m_colors[0]) * m_colors.size() +
        sizeof(m_jointIndices[0]) * m_jointIndices.size() +
        sizeof(m_jointWeights[0]) * m_jointWeights.size() +
        sizeof(m_morphTargetPositions[0]) * m_morphTargetPositions.size() +
        sizeof(m_morphTargetNormals[0]) * m_morphTargetNormals.size() +
        sizeof(m_morphTargetTangents[0]) * m_morphTargetTangents.size();
}

void Geometry::SetIndices(const uint16_t* indices, size_t indexCount)
{
    m_indices = std::vector<uint32_t>(indices, indices + indexCount);
}

void Geometry::SetIndices(const uint32_t* indices, size_t indexCount)
{
    m_indices = std::vector<uint32_t>(indices, indices + indexCount);
}

void Geometry::SetPositions(const float* positions, size_t positionCount)
{
    m_positions = ToVector<Vector3>(positions, positionCount);
}

void Geometry::SetNormals(const float* normals, size_t normalCount)
{
    m_normals = ToVector<Vector3>(normals, normalCount);
}

void Geometry::SetUv0s(const float* uv0s, size_t uv0sCount)
{
    m_uv0s = ToVector<Vector2>(uv0s, uv0sCount);
}

void Geometry::SetUv1s(const float* uv1s, size_t uv1sCount)
{
    m_uv1s = ToVector<Vector2>(uv1s, uv1sCount);
}

void Geometry::SetTangents(const float* tangents, size_t tangentCount)
{
    m_tangents = ToVector<Vector4>(tangents, tangentCount);
}

void Geometry::SetColors(const uint32_t* colors, size_t colorCount)
{
    m_colors = std::vector<uint32_t>(colors, colors + colorCount);
}

void Geometry::SetJoints(std::vector<uint32_t>&& jointIndices, std::vector<uint32_t>&& jointWeights)
{
    if (jointIndices.size() != jointWeights.size())
    {
        throw Utils::BabylonException("Must have the same number of joint indices and weights.");
    }
    m_jointIndices = std::move(jointIndices);
    m_jointWeights = std::move(jointWeights);
}

void Geometry::AddMorphTargetPositions(std::vector<float>&& morphPositions)
{
    BabylonAssert(morphPositions.size() % 3 == 0);
    BabylonAssert(m_morphTargetPositions.size() == 0 ||
        (m_morphTargetPositions.size() > 0 && morphPositions.size() == m_morphTargetPositions.front().size()));
    m_morphTargetPositions.emplace_back(std::move(morphPositions));
}

void Geometry::AddMorphTargetNormals(std::vector<float>&& morphNormals)
{
    BabylonAssert(morphNormals.size() % 3 == 0);
    BabylonAssert(m_morphTargetNormals.size() == 0 ||
        (m_morphTargetNormals.size() > 0 && morphNormals.size() == m_morphTargetNormals.front().size()));
    m_morphTargetNormals.emplace_back(std::move(morphNormals));
}

void Geometry::AddMorphTargetTangents(std::vector<float>&& morphTangents)
{
    BabylonAssert(morphTangents.size() % 3 == 0);
    BabylonAssert(m_morphTargetTangents.size() == 0 ||
        (m_morphTargetTangents.size() > 0 && morphTangents.size() == m_morphTargetTangents.front().size()));
    m_morphTargetTangents.emplace_back(std::move(morphTangents));
}

void Geometry::CalculateBoundingBox()
{
    m_boundingBox = BoundingBox(m_positions);
}

BoundingBox Geometry::CalcTopDownBounds(const Babylon::Utils::Math::Matrix& transform) const
{
    BoundingBox boundingBox;
    for (const auto& position : m_positions)
    {
        auto positionTransformed = Vector3::Transform(position, transform);
        boundingBox.Update(positionTransformed);
    }
    return boundingBox;
}

std::vector<uint32_t> Geometry::GetOrGenerateIndices() const
{
    if (!m_indices.empty())
    {
        return GetIndices();
    }

    std::vector<uint32_t> indices(m_positions.size());
    std::iota(indices.begin(), indices.end(), 0);

    return indices;
}