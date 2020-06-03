/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <Asset3D/Animation.h>
#include <COLLADAFWUniqueId.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAESkeletonBuilder : public DAEAsset3DBuilder<Animation::Skeleton> {

		private:
			std::vector<COLLADAFW::UniqueId> m_joints;
			std::shared_ptr<DAESkinData> m_data;

		public:
			DAESkeletonBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context) {
			}

			std::shared_ptr<Animation::Skeleton> Build() {
				return nullptr;
			}

			DAESkeletonBuilder& DAESkeletonBuilder::WithJoint(COLLADAFW::UniqueId id) {
				m_joints.push_back(id);
				return *this;
			}

			DAESkeletonBuilder& DAESkeletonBuilder::WithSkinData(std::shared_ptr<DAESkinData> data) {
				m_data = data;
				return *this;
			}
		};
	}
}
