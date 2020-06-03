/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"
#ifdef SKIN_NORMALIZE_WEIGHT
#define _USE_MATH_DEFINES
#include <math.h>
#endif

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>
#include <COLLADAFWSkinController.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAESkeletonBuilder> DAESkinControllerConverter::Convert(const COLLADAFW::SkinController* colladaController) {
	
	std::shared_ptr<DAESkeletonBuilder> builder = std:: make_shared< DAESkeletonBuilder>(getContext());
	
	COLLADAFW::UniqueId skinControllerDataId = colladaController->getSkinControllerData();
	std::shared_ptr<DAESkinData> data = getContext()->getSkinLibrary()[skinControllerDataId];
	if (data) {

#ifdef SKIN_NORMALIZE_WEIGHT
		int n = data->getNumberOfComponents();

		for (size_t i = 0; i < data->weights.size(); i++) {
			float weightSum = 0;
			float* weight = data->weights[i];
			for (size_t j = 0; j < n; j++) {
				weightSum = weightSum + std::abs(weight[j]);
			}
			if (weightSum > 0) {
				for (size_t j = 0; j < n; j++) {
					weight[j] = weight[j] / weightSum;
				}
			}
		}
#endif
		/// register joint index as Node COLLADA Unique ID. We can retreive it later using m_context->GetLibraryNode()
		const COLLADAFW::UniqueIdArray& jointIds = colladaController->getJoints();
		for (size_t i = 0; i < jointIds.getCount(); i++) {
			builder->WithJoint(jointIds[i]);
		}
		builder->WithSkinData(data);
	}
	return builder;
}
