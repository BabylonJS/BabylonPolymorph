/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <Asset3D/Light.h>


namespace Babylon
{
	namespace Transcoder
	{
		class DAELightBuilder : public DAEAsset3DBuilder<Light> {

		private:
			LightType m_type;
			Babylon::Utils::Math::Color m_color;
			float m_constantAttenuation;
			float m_linearAttenuation;
			float m_quadraticAttenuation;

		public:
			DAELightBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context){
			}

			std::shared_ptr<Light> Build() {
				std::shared_ptr<Light> ptr = std::make_shared<Light>();
				ptr->SetType(m_type);
				ptr->SetColor(m_color);
				if (m_type == LightType::POINT) {
					ptr->SetConstantAttenuation(m_constantAttenuation);
					ptr->SetLinearAttenuation(m_linearAttenuation);
					ptr->SetQuadraticAttenuation(m_quadraticAttenuation);
				}
				return ptr;
			}

			inline DAELightBuilder& WithType(LightType type) {
				m_type = type;
				return *this;
			}

			inline DAELightBuilder& WithColor(float r, float g, float b, float a = 1.0) {
				m_color.x = r; m_color.y = g; m_color.z = b; m_color.w = a;
				return *this;
			}

			inline DAELightBuilder& WithConstantAttenuation(float v) {
				m_constantAttenuation = v;
				return *this;
			}
			
			inline DAELightBuilder& WithLinearAttenuation(float v) {
				m_linearAttenuation = v;
				return *this;
			}

			inline DAELightBuilder& WithQuadraticAttenuation(float v) {
				m_quadraticAttenuation = v;
				return *this;
			}
		};
	}
}
