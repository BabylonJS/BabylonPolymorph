/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include "Asset3D/ITraversable.h"
#include <Framework/GeometryUtils.h>
#include "Projection.h"

namespace Spectre
{
    namespace Transcoder
    {
        class Camera : public ITraversableWithName
        {
        public:
            Camera(std::unique_ptr<Projection>&& projection) :
                ITraversableWithName(), m_projection(std::move(projection))
            {
            }

            Camera(const Camera& c) :
                ITraversableWithName(),
                m_projection(c.m_projection->Clone())
            {
            }

            const Perspective& GetPerspective() const
            {
                if (auto ret = dynamic_cast<Perspective*>(m_projection.get()))
                {
                    return *ret;
                }
                throw Spectre::Utils::SpectreException("Projection is not perspective");
            }

            const Orthographic& GetOrthographic() const
            {
                if (auto ret = dynamic_cast<Orthographic*>(m_projection.get()))
                {
                    return *ret;
                }
                throw Spectre::Utils::SpectreException("Projection is not orthographic");
            }

            ProjectionType GetProjectionType() const
            {
                return m_projection->GetProjectionType();
            }

        private:
            std::unique_ptr<Projection> m_projection;
        };
    }
}
