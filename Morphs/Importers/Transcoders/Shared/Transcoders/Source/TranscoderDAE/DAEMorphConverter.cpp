/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>
#include <COLLADAFWMorphController.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAENodeAnimationBuilder> DAEMorphConverter::Convert(const COLLADAFW::MorphController* colladaSkeleton) {
	std::shared_ptr<DAENodeAnimationBuilder> builder = nullptr;

	return builder;
}
