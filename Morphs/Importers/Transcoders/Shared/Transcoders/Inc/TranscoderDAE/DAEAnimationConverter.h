/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEConverter.h>
#include <TranscoderDAE/DAENodeAnimationBuilder.h>
#include <TranscoderDAE/DAESkeletalAnimationBuilder.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAESkeletonConverter : public DAEAbstractConverter<COLLADAFW::SkinController, DAESkeletonBuilder> {
		public:
			DAESkeletonConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAESkeletonBuilder> Convert(const COLLADAFW::SkinController* from);
		};

		class DAESkeletalAnimationConverter : public DAEAbstractConverter<COLLADAFW::Animation, DAESkeletalAnimationBuilder> {
		public:
			DAESkeletalAnimationConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAESkeletalAnimationBuilder> Convert(const COLLADAFW::Animation* from);
		};

		class DAEMorphConverter : public DAEAbstractConverter<COLLADAFW::MorphController, DAENodeAnimationBuilder> {
		public:
			DAEMorphConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAENodeAnimationBuilder> Convert(const COLLADAFW::MorphController* from);
		};
	}
}
#pragma once
