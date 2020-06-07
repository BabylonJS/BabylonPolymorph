/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <TranscoderDAE/DAEAnimation.h>
#include <Asset3D/Animation.h>
#include <COLLADAFWUniqueId.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAESkeletonBuilder : public DAEAsset3DBuilder<Animation::Skeleton> {

		private:
			std::shared_ptr<SceneNode> m_root;
			std::shared_ptr<DAESkinController> m_controller;

		public:
			DAESkeletonBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context) {
			}

			std::shared_ptr<Animation::Skeleton> Build();

			DAESkeletonBuilder& DAESkeletonBuilder::WithRoot(std::shared_ptr<SceneNode> root) {
				m_root = root;
				return *this;
			}

			DAESkeletonBuilder& DAESkeletonBuilder::WithSkinData(std::shared_ptr<DAESkinController> controller) {
				m_controller = controller;
				return *this;
			}
		};
	}
}
