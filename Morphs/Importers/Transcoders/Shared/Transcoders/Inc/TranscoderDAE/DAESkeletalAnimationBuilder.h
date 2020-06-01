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
		class DAESkeletalAnimationBuilder : public DAEAsset3DBuilder<Animation::SkeletalAnimation> {

		private:

		public:
			DAESkeletalAnimationBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context) {
			}

			std::shared_ptr<Animation::SkeletalAnimation> Build() {
				return nullptr;
			}

		};

	}
}
