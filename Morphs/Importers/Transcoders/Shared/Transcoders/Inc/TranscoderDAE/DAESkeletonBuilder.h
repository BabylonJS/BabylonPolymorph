/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <Asset3D/Animation.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAESkeletonBuilder : public DAEAsset3DBuilder<Animation::Skeleton> {

		private:

		public:
			DAESkeletonBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context) {
			}

			std::shared_ptr<Animation::Skeleton> Build() {
				return nullptr;
			}
		};
	}
}
