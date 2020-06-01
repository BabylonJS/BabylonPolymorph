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
		class DAENodeAnimationBuilder : public DAEAsset3DBuilder<Animation::NodeAnimation> {

		private:

		public:
			DAENodeAnimationBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context) {
			}

			std::shared_ptr<Animation::NodeAnimation> Build() {
				return nullptr;
			}

		};

	}
}
