/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Framework/GeometryUtils.h>

#include <CoreUtils/Optional.h>

namespace Babylon
{
    namespace Transcoder
    {
        enum class ProjectionType
        {
            kPerspective,
            kOrthographic
        };

        class Projection
        {
        public:
            virtual ~Projection() = default;

            virtual ProjectionType GetProjectionType() const = 0;
            virtual std::unique_ptr<Projection> Clone() const = 0;
        };

        class Perspective : public Projection
        {
        public:
            Perspective(float znear, float yfov) :
                znear(znear),
                yfov(yfov)
            {
            }

            virtual ProjectionType GetProjectionType() const
            {
                return ProjectionType::kPerspective;
            }

            virtual std::unique_ptr<Projection> Clone() const
            {
                return std::make_unique<Perspective>(*this);
            }

            Utils::Optional<float> zfar;
            float znear;
            Utils::Optional<float> aspectRatio;
            float yfov;
        };

        class Orthographic : public Projection
        {
        public:
            Orthographic(float zfar, float znear, float xmag, float ymag) :
                zfar(zfar),
                znear(znear),
                xmag(xmag),
                ymag(ymag)
            {
            }

            virtual ProjectionType GetProjectionType() const
            {
                return ProjectionType::kOrthographic;
            }

            virtual std::unique_ptr<Projection> Clone() const
            {
                return std::make_unique<Orthographic>(*this);
            }

            float zfar;
            float znear;
            float xmag;
            float ymag;
        };
    }
}
