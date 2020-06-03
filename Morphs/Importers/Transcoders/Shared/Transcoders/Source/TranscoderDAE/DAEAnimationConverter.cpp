/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>
#include <COLLADAFWAnimation.h>
#include <COLLADAFWAnimationCurve.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAEAnimationData> DAEAnimationConverter::Convert(const COLLADAFW::Animation* colladaAnimation) {
	std::shared_ptr<DAEAnimationData> ptr = nullptr;
	if (colladaAnimation->getAnimationType() == COLLADAFW::Animation::ANIMATION_CURVE) {

		ptr = std::make_shared< DAEAnimationData>();
		COLLADAFW::AnimationCurve* animationCurve = (COLLADAFW::AnimationCurve*)colladaAnimation;
		COLLADAFW::FloatOrDoubleArray inputArray = animationCurve->getInputValues();
		COLLADAFW::FloatOrDoubleArray outputArray = animationCurve->getOutputValues();

		int inputLength = inputArray.getValuesCount();
		int outputLength = outputArray.getValuesCount();

		float value;
		for (int i = 0; i < inputLength; i++) {
			switch (inputArray.getType()) {
			case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
				value = (float)(inputArray.getDoubleValues()->getData()[i]);
				break;
			case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
				value = inputArray.getFloatValues()->getData()[i];
				break;
			}
			ptr->inputs.push_back(value);
		}
		for (int i = 0; i < outputLength; i++) {
			switch (outputArray.getType()) {
			case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE:
				value = (float)(outputArray.getDoubleValues()->getData()[i]);
				break;
			case COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT:
				value = outputArray.getFloatValues()->getData()[i];
				break;
			}
			ptr->outputs.push_back(value);
		}
	}
	return ptr;
}
