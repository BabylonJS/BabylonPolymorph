/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <TranscoderDAE/DAEMeshBuilder.h>
#include <TranscoderDAE/DAESkinControllerBuilder.h>

#include <COLLADAFWSkinController.h>

DEFINE_TRACE_AREA(DAESkinControllerConverter, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<DAESkinControllerBuilder> DAESkinControllerConverter::Convert(const COLLADAFW::SkinController* colladaController) {
	
	std::shared_ptr<DAESkinControllerBuilder> builder = std:: make_shared<DAESkinControllerBuilder>(getContext());

	COLLADAFW::UniqueId skinControllerDataId = colladaController->getSkinControllerData();
	std::shared_ptr<DAESkinData> data = getContext()->getSkinDataLibrary()[skinControllerDataId];

	std::shared_ptr<DAEMeshBuilder> mb = getContext()->getGeometryLibrary()[colladaController->getSource()];
	if (!mb) {
		TRACE_WARN(DAESkinControllerConverter, "Not able to found mesh source %s - Controller will be ignored.", colladaController->getSource().toAscii());
		return builder;
	}

	builder->WithSkin(mb).WithData(data);

	int n = data->getNumberOfComponents();

	/// Normalize weight [0,1]
	for (size_t i = 0; i < data->weights.size(); i++) {
		float weightSum = 0;
		float* weight = data->weights[i];
		for (size_t j = 0; j < n; j++) {
			weightSum = weightSum + std::abs(weight[j]);
		}
		for (size_t j = 0; j < n; j++) {
			if (weightSum) {
				weight[j] = weight[j] / weightSum;
			}
		}
	}

	/// register joint index as Node COLLADA Unique ID. We can retreive it later using m_context->GetLibraryNode() in order to build the skeleton
	const COLLADAFW::UniqueIdArray& jointIds = colladaController->getJoints();
	for (size_t i = 0; i < jointIds.getCount(); i++) {
		builder->WithJoint(jointIds[i]);
	}

	return builder;
}
