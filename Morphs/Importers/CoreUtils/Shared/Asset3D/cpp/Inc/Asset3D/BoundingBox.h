/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <array>

#include <Framework/GeometryUtils.h>

namespace Babylon
{
    namespace Transcoder
    {
        class BoundingBox
        {
        public:
            BoundingBox();
            BoundingBox(const BoundingBox& other);
            explicit BoundingBox(const std::vector<Babylon::Utils::Math::Vector3>& positions);
            BoundingBox(std::array<float, 3> center, std::array<float, 3> extents);
            BoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

            ~BoundingBox();

            inline bool operator== (const BoundingBox& other) const;

            inline void Validate();

            inline void Update(std::vector<Babylon::Utils::Math::Vector3> const& positions);
            inline void Update(Babylon::Utils::Math::Vector3 const& position);
            inline void Update(BoundingBox const& boundingBox);
            inline void Set(std::array<float, 3> center, std::array<float, 3> extents);
            inline bool IsInitialised() const { return m_isInitialised; }

            inline std::array<float, 3> GetCenter() const;
            inline std::array<float, 3> GetExtents() const;
            inline float GetScale() const;

            inline void Recenter(std::array<float, 3> newCenter);
            inline void RecenterToOrigin();
            inline void Rescale(float scale);
            inline void Normalise();

            void Transform(Babylon::Utils::Math::Matrix transform);
            Vector3 GetMaxima() const { return Vector3(m_maxima[0], m_maxima[1], m_maxima[2]); }
            Vector3 GetMinima() const { return Vector3(m_minima[0], m_minima[1], m_minima[2]); }
            static const BoundingBox Zero;
            static const BoundingBox Uninitialized;

        protected:
            bool m_isInitialised;

            std::array<float, 3> m_minima;
            std::array<float, 3> m_maxima;
        };
    }
}

inline bool Babylon::Transcoder::BoundingBox::operator== (const Babylon::Transcoder::BoundingBox& other) const
{
    return m_minima == other.m_minima && m_maxima == other.m_maxima;
}

inline void Babylon::Transcoder::BoundingBox::Update(std::vector<Babylon::Utils::Math::Vector3> const& positions)
{
    for (auto& position : positions)
    {
        Update(position);
    }

    m_isInitialised = true;
}

inline void Babylon::Transcoder::BoundingBox::Update(Babylon::Utils::Math::Vector3 const& position)
{
    m_minima[0] = std::min(m_minima[0], position.x);
    m_minima[1] = std::min(m_minima[1], position.y);
    m_minima[2] = std::min(m_minima[2], position.z);

    m_maxima[0] = std::max(m_maxima[0], position.x);
    m_maxima[1] = std::max(m_maxima[1], position.y);
    m_maxima[2] = std::max(m_maxima[2], position.z);

    m_isInitialised = true;
}

inline void Babylon::Transcoder::BoundingBox::Update(Babylon::Transcoder::BoundingBox const& boundingBox)
{
    if (boundingBox.m_isInitialised)
    {
        m_minima[0] = std::min(m_minima[0], boundingBox.m_minima[0]);
        m_minima[1] = std::min(m_minima[1], boundingBox.m_minima[1]);
        m_minima[2] = std::min(m_minima[2], boundingBox.m_minima[2]);

        m_maxima[0] = std::max(m_maxima[0], boundingBox.m_maxima[0]);
        m_maxima[1] = std::max(m_maxima[1], boundingBox.m_maxima[1]);
        m_maxima[2] = std::max(m_maxima[2], boundingBox.m_maxima[2]);

        m_isInitialised = true;
    }
}

inline void Babylon::Transcoder::BoundingBox::Set(std::array<float, 3> center, std::array<float, 3> extents)
{
    m_minima = { {center[0] - extents[0], center[1] - extents[1], center[2] - extents[2]} };
    m_maxima = { {center[0] + extents[0], center[1] + extents[1], center[2] + extents[2]} };

    m_isInitialised = true;
}

inline std::array<float, 3> Babylon::Transcoder::BoundingBox::GetCenter() const
{
    std::array<float, 3> center;

    if (m_isInitialised)
    {
        center[0] = (m_maxima[0] + m_minima[0]) * 0.5f;
        center[1] = (m_maxima[1] + m_minima[1]) * 0.5f;
        center[2] = (m_maxima[2] + m_minima[2]) * 0.5f;
    }
    else
    {
        center.fill(0);
    }

    return center;
}

inline std::array<float, 3> Babylon::Transcoder::BoundingBox::GetExtents() const
{
    std::array<float, 3> extents;

    if (m_isInitialised)
    {
        extents[0] = (m_maxima[0] - m_minima[0]) * 0.5f;
        extents[1] = (m_maxima[1] - m_minima[1]) * 0.5f;
        extents[2] = (m_maxima[2] - m_minima[2]) * 0.5f;
    }
    else
    {
        extents.fill(0);
    }

    return extents;
}

inline float Babylon::Transcoder::BoundingBox::GetScale() const
{
    if (!m_isInitialised)
    {
        return 0.;
    }

    float maxExtent = 0.;
    for (int i = 0; i < 3; ++i)
    {
        maxExtent = std::max(maxExtent, std::fabs(m_maxima[i] - m_minima[i]));
    }

    return maxExtent == 0.f ? 0.f : 1.f/maxExtent;
}

inline void Babylon::Transcoder::BoundingBox::Validate()
{
    for (int i = 0; i < 3; ++i)
    {
        if (m_maxima[i] >= m_minima[i])
        {
            continue;
        }

        m_isInitialised = false;
        m_minima = { {+FLT_MAX, +FLT_MAX, +FLT_MAX} };
        m_maxima = { {-FLT_MAX, -FLT_MAX, -FLT_MAX} };
        break;
    }
}

inline void Babylon::Transcoder::BoundingBox::Recenter(std::array<float, 3> newCenter)
{
    auto extents = GetExtents();
    Set(newCenter, extents);
}

inline void Babylon::Transcoder::BoundingBox::RecenterToOrigin()
{
    std::array<float, 3> origin{ {0, 0, 0} };
    Recenter(origin);
}

inline void Babylon::Transcoder::BoundingBox::Rescale(float scale)
{
    auto extents = GetExtents();
    for (int i = 0; i < 3; ++i)
    {
        extents[i] *= scale;
    }

    auto center = GetCenter();
    Set(center, extents);
}

inline void Babylon::Transcoder::BoundingBox::Normalise()
{
    auto scale = GetScale();
    Rescale(scale);
}

/************************************************************************************************************
Equal (maybe should be member function?)
Probably only used for testing, but useful to have around.
Rules
If either is unitiliased they are equal if (and only if) both are unitialised.
Otherwise, they are equal if the Centre and Extents match.
************************************************************************************************************/
inline bool Equal(const Babylon::Transcoder::BoundingBox& a, const Babylon::Transcoder::BoundingBox& b)
{
    if (a.IsInitialised() != b.IsInitialised())
        return false;

    if (!a.IsInitialised())
        return true;
    auto aCentre = a.GetCenter();
    auto bCentre = b.GetCenter();
    if (!std::equal(begin(aCentre), end(aCentre), begin(bCentre)))
        return false;
    auto aExt = a.GetExtents();
    auto bExt = b.GetExtents();
    if (!std::equal(begin(aExt), end(aExt), begin(bExt)))
        return false;
    return true;
}
