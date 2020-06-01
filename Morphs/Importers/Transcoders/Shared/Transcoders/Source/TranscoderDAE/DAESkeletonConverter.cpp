/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>
#include <COLLADAFWSkinController.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAESkeletonBuilder> DAESkeletonConverter::Convert(const COLLADAFW::SkinController* colladaSkeleton) {
	std::shared_ptr<DAESkeletonBuilder> builder = nullptr;

	return builder;
}
