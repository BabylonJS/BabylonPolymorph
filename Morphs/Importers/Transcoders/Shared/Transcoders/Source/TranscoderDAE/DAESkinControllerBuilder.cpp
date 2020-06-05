/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimation.h>
#include <TranscoderDAE/DAEMeshBuilder.h>
#include <TranscoderDAE/DAESkinControllerBuilder.h>

DEFINE_TRACE_AREA(DAESkinControllerBuilder, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<Mesh> DAESkinControllerBuilder::Build() {

	int n = m_data->getNumberOfComponents();
	/// Asset3D do NOT support more than 4 joints/weights per vertex
	if (n > MAX_JOINT_INFLUENCES) {
		TRACE_WARN(DAESkinControllerBuilder, "Asset 3D currently accept ONLY %x joints influences - given %x joints - extra items will be ignored.", MAX_JOINT_INFLUENCES, n);
		n = MAX_JOINT_INFLUENCES;
	}

	m_mesh->Save();

	/// assign weight and joint to underlying primitives
	for (auto geom : m_mesh->GetGeometries()) {

		/// get an ordered list of used vertex (POSITION semantic) inside this primitive
		std::vector<uint32_t> indices = geom->GetOriginalIndices();
		std::sort(indices.begin(), indices.end());
		auto last = std::unique(indices.begin(), indices.end());
		indices.erase(last, indices.end());

		/// then assign weigth & joints
		std::vector<float> weights;
		std::vector<uint32_t> joints;
		for (auto i : indices) {
			float* weight = m_data->weights[i];
			uint32_t* joint = m_data->jointIndices[i];
			for (size_t j = 0; j < n; j++) {
				joints.push_back(joint[j]);
				weights.push_back(weight[j]);
			}
		}

		geom->WithJoints(std::move(joints), std::move(weights));
	}

	std::shared_ptr<Mesh> m = m_mesh->Build();
	m_mesh->Restore();

	return m;

}

