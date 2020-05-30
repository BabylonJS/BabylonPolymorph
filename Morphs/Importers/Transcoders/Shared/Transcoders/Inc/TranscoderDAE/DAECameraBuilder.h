/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <Asset3D/Camera.h>


namespace Babylon
{
	namespace Transcoder
	{
		class DAECameraBuilder : public DAEAsset3DBuilderWithCache<Camera> {

		private:
			ProjectionType m_type;

			Utils::Optional<float> m_zfar;
			float m_znear;

			Utils::Optional<float> m_aspectRatio;
			float m_yfov;

			float m_xmag;
			float m_ymag;

		public:
			DAECameraBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilderWithCache(context), m_type(ProjectionType::kPerspective){
			}

			std::shared_ptr<Camera> BuildCache() {
				std::shared_ptr<Camera> ptr;
				switch (m_type) {
				case(ProjectionType::kOrthographic): {
					ptr = std::make_shared<Camera>(std::make_unique<Orthographic>(*m_zfar, m_znear, m_xmag, m_ymag));
					break;
				}
				case(ProjectionType::kPerspective):
				default: {
					std::unique_ptr<Perspective> p = std::make_unique<Perspective>(m_znear, m_yfov);

					if (m_zfar.Valid()) {
						p->zfar = *m_zfar;
					}
					if (m_aspectRatio.Valid()) {
						p->aspectRatio = *m_aspectRatio;
					}
					ptr = std::make_shared<Camera>(std::move(p));
				}
				}
				return ptr;
			}

			inline DAECameraBuilder& WithProjectionType(ProjectionType projection) {
				m_type = projection;
				return *this;
			}

			inline DAECameraBuilder& WithZFar(float zfar) {
				m_zfar = zfar;
				return *this;
			}

			inline DAECameraBuilder& WithZNear(float znear) {
				m_znear = znear;
				return *this;
			}

			inline DAECameraBuilder& WithAspectRatio(float aspectRatio) {
				if( !DISCARD_ZERO_ASPECT_RATIO || aspectRatio != 0){
					m_aspectRatio = aspectRatio;
				}
				return *this;
			}

			inline DAECameraBuilder& WithYFov(float yfov) {
				m_yfov = yfov;
				return *this;
			}

			inline DAECameraBuilder& WithXMag(float xmag) {
				m_xmag = xmag;
				return *this;
			}

			inline DAECameraBuilder& WithYMag(float ymag) {
				m_ymag = ymag;
				return *this;
			}
		};
	}
}
