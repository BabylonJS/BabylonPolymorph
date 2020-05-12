/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <Asset3D/Asset3D.h>

DEFINE_TRACE_AREA(Asset3D_Root, 0);

namespace Babylon
{
    namespace Transcoder
    {
        Asset3D::Asset3D() : SceneNode()
        {
            SetName("root");
        }

        BoundingBox Asset3D::CalcTopDownBounds(const Babylon::Utils::Math::Matrix& transform) const
        {
            BoundingBox box;
            Utils::Math::Matrix ourTransform = GetTransform() * transform;
            for (auto child : m_children)
            {
                box.Update(child->CalcTopDownBounds(ourTransform));
            }

            if (HasMesh())
            {
                box.Update(m_mesh->CalcTopDownBounds(ourTransform));
            }
            return box;
        }

        float Asset3D::CalculateConversionScale(UnitInCentimeter origUnit, UnitInCentimeter destUnit)
        {
            assert(origUnit != SYSTEMUNIT_NONE && destUnit != SYSTEMUNIT_NONE);
            return origUnit / destUnit;
        }

        Utils::Math::Matrix Asset3D::GetUnitScaledTransform(UnitInCentimeter unit) const
        {
            // If there's no unit information, we can't scale to a different unit *OR*
            // if the asset is already the desired unit, just return the transform
            if (m_systemUnit == SYSTEMUNIT_NONE ||
                m_systemUnit == unit)
            {
                return m_transform;
            }

            // Otherwise convert from the asset's unit to the desired unit
            float scale = Asset3D::CalculateConversionScale(m_systemUnit, unit);
            auto scaleMatrix = Utils::Math::Matrix::CreateScale(scale);
            auto scaledTransform = m_transform * scaleMatrix;
            return scaledTransform;
        }
    } // namespace Transcoder
} // namespace Babylon
