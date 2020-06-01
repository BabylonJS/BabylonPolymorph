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
#include <COLLADAFWMorphController.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAENodeAnimationBuilder> DAEMorphConverter::Convert(const COLLADAFW::MorphController* colladaSkeleton) {
	std::shared_ptr<DAENodeAnimationBuilder> builder = nullptr;

	return builder;
}
