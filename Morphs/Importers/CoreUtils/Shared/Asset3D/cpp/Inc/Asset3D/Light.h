/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include "Asset3D/ITraversable.h"

namespace Babylon
{
    namespace Transcoder
    {
		enum class LightType {
			AMBIENT,
			DIRECTIONAL,
			POINT,
			SPOT,
			UNKOWN
		};
		
		class Light : public ITraversableWithName
        {
        public:
            Light() : ITraversableWithName(), 
				m_type(LightType::UNKOWN),
				m_color(Vector4(1,1,1,1)),
				m_constantAttenuation(0.0),
				m_linearAttenuation(0.0),
				m_quadraticAttenuation(0.0)
			{
            }

			inline const LightType GetType() { return m_type; }
			inline void SetType(LightType t) { m_type = t; }

			inline const Babylon::Utils::Math::Color GetColor() { return m_color; }
			inline void SetColor(Babylon::Utils::Math::Color color) { m_color = color; }
			inline void SetColor(float r, float g, float b, float a) { m_color.x = r; m_color.y = r; m_color.z = r; m_color.w = a; }

			inline const float GetConstantAttenuation() { return m_constantAttenuation; }
			inline void SetConstantAttenuation(float v) { m_constantAttenuation = v; }
			
			inline const float GetLinearAttenuation() { return m_linearAttenuation; }
			inline void SetLinearAttenuation(float v) { m_linearAttenuation = v; }

			inline const float GetQuadraticAttenuation() { return m_quadraticAttenuation; }
			inline void SetQuadraticAttenuation(float v) { m_quadraticAttenuation = v; }

		private:

			LightType m_type;
			Babylon::Utils::Math::Color m_color;
			float m_constantAttenuation;
			float m_linearAttenuation;
			float m_quadraticAttenuation;
        };
    }
}
