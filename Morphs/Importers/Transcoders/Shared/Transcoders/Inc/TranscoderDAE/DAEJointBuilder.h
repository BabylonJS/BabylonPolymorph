/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAENodeBuilder.h>
#include <Asset3D/SceneNode.h>
#include <COLLADAFWNode.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAEJointBuilder : public DAENodeBuilder {

		private:
			Babylon::Utils::Math::Matrix m_invBindPose{ Babylon::Utils::Math::Matrix::Identity };
			Babylon::Utils::Math::Matrix m_localTransform{ Babylon::Utils::Math::Matrix::Identity };

		public:
			DAEJointBuilder(DAEToAsset3DWriterContextPtr context) : DAENodeBuilder(context) {
			}

			inline DAENodeBuilder& WithInverseBindPose(Babylon::Utils::Math::Matrix matrix) {
				m_invBindPose = matrix;
				return *this;
			}

			inline DAENodeBuilder& WithDefaultLocalTransform(Babylon::Utils::Math::Matrix matrix) {
				m_localTransform = matrix;
				return *this;
			}
		};
	}
}
