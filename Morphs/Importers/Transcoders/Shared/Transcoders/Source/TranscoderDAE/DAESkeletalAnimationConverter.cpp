/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>
#include <COLLADAFWAnimation.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAESkeletalAnimationBuilder> DAESkeletalAnimationConverter::Convert(const COLLADAFW::Animation* colladaSkeleton) {
	std::shared_ptr<DAESkeletalAnimationBuilder> builder = nullptr;

	return builder;
}
