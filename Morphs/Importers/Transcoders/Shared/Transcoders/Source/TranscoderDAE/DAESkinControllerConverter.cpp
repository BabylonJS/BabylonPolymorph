/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <TranscoderDAE/DAEMeshBuilder.h>
#include <TranscoderDAE/DAESkinGeometryBuilder.h>

#include <COLLADAFWSkinController.h>

DEFINE_TRACE_AREA(DAESkinControllerConverter, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<DAESkinController> DAESkinControllerConverter::Convert(const COLLADAFW::SkinController* colladaController) {
	
	std::shared_ptr<DAESkinController> builder = std:: make_shared<DAESkinController>();

	COLLADAFW::UniqueId skinControllerDataId = colladaController->getSkinControllerData();
	std::shared_ptr<DAESkinData> data = getContext()->getSkinDataLibrary()[skinControllerDataId];

	std::shared_ptr<IDAEMeshBuilder> mb = getContext()->getGeometryLibrary()[colladaController->getSource()];
	if (!mb) {
		TRACE_WARN(DAESkinControllerConverter, "Not able to found mesh source %s - Controller will be ignored.", colladaController->getSource().toAscii());
		return builder;
	}

	builder->mesh = mb;
	builder->data =data;

#ifdef SKIN_NORMALIZE_WEIGHT
	int n = data->getNumberOfComponents();
	if (n > MAX_JOINT_INFLUENCES) {
		TRACE_WARN(DAESkinControllerConverter, "Asset 3D currently accept ONLY %x joints influences - given %x joints - extra items will be ignored.", MAX_JOINT_INFLUENCES, n);
		n = MAX_JOINT_INFLUENCES;
	}
	/// Normalize weight [0,1]
	for (size_t i = 0; i < data->weights.size(); i++) {
		float weightSum = 0;
		float* weight = data->weights[i];
		/** 
		 * sum all weight using naive method - we do not need a precision more than 6 digits here.
		 * otherwize we can use more sophiticated algorithm such Kahan methods (DAEUtils.h)
		 */
		for (size_t j = 0; j < n; j++) {
			weightSum += std::abs(weight[j]);
		}
		/// if sum is zero, we spread the weight heavenly in each joints...
		for (size_t j = 0; j < n; j++) {
			weight[j] = weightSum ?  weight[j] / weightSum : 1.0/n;
		}
	}
#endif

	/// register joint index as Node COLLADA Unique ID. We can retreive it later using m_context->GetLibraryNode() in order to build the skeleton
	const COLLADAFW::UniqueIdArray& jointIds = colladaController->getJoints();
	for (size_t i = 0; i < jointIds.getCount(); i++) {
		builder->joints.push_back(jointIds[i]);
	}

	return builder;
}
