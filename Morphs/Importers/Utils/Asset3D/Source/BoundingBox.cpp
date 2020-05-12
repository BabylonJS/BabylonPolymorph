/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <Asset3D/BoundingBox.h>

using namespace Babylon::Transcoder;

const BoundingBox BoundingBox::Zero(0, 0, 0, 0, 0, 0);
const BoundingBox BoundingBox::Uninitialized(+FLT_MAX, -FLT_MAX, +FLT_MAX, -FLT_MAX, +FLT_MAX, -FLT_MAX);

BoundingBox::BoundingBox()
    : m_isInitialised(false),
    m_minima{ {+FLT_MAX, +FLT_MAX, +FLT_MAX} },
    m_maxima{ {-FLT_MAX, -FLT_MAX, -FLT_MAX} }
{
}

BoundingBox::BoundingBox(const BoundingBox& other)
    : m_isInitialised(other.m_isInitialised),
    m_minima(other.m_minima),
    m_maxima(other.m_maxima)
{
}

BoundingBox::BoundingBox(std::vector<Babylon::Utils::Math::Vector3> const& positions)
    : m_isInitialised(true),
    m_minima{ {+FLT_MAX, +FLT_MAX, +FLT_MAX} },
    m_maxima{ {-FLT_MAX, -FLT_MAX, -FLT_MAX} }
{
    if (positions.empty())
    {
        m_isInitialised = false;
    }
    else
    {
        Update(positions);
    }
}

BoundingBox::BoundingBox(std::array<float, 3> center, std::array<float, 3> extents)
    : m_isInitialised(true),
    m_minima{ {center[0] - extents[0], center[1] - extents[1], center[2] - extents[2]} },
    m_maxima{ {center[0] + extents[0], center[1] + extents[1], center[2] + extents[2]} }
{
    Validate();
}

BoundingBox::BoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
    : m_isInitialised(true),
    m_minima{ {minX, minY, minZ} },
    m_maxima{ {maxX, maxY, maxZ} }
{
    Validate();
}

BoundingBox::~BoundingBox()
{
}

void BoundingBox::Transform(Babylon::Utils::Math::Matrix transform)
{
    if (!m_isInitialised)
    {
        return;
    }

    Vector3 bounds[] = { {m_minima[0], m_minima[1], m_minima[2]},
                         {m_maxima[0], m_maxima[1], m_maxima[2]} };

    m_isInitialised = false;
    m_minima = { {+FLT_MAX, +FLT_MAX, +FLT_MAX} };
    m_maxima = { {-FLT_MAX, -FLT_MAX, -FLT_MAX} };

    for (int i = 0; i < 8; i++)
    {
        Vector3 position = { bounds[(i & 4) >> 2].x, bounds[(i & 2) >> 1].y, bounds[i & 1].z };
        Update(Babylon::Utils::Math::Vector3::Transform(position, transform));
    }
}
