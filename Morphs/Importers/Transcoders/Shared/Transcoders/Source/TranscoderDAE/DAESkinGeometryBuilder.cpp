/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimation.h>
#include <TranscoderDAE/DAEMeshBuilder.h>
#include <TranscoderDAE/DAESkinGeometryBuilder.h>

DEFINE_TRACE_AREA(DAESkinGeometryBuilder, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<Mesh> DAESkinGeometryBuilder::Build() {

	int n0 = m_controller->data->getNumberOfComponents();
	int n = n0;
	/// Asset3D do NOT support more than 4 joints/weights per vertex
	if (n > MAX_JOINT_INFLUENCES) {
		TRACE_WARN(DAESkinGeometryBuilder, "Asset 3D currently accept ONLY %x joints influences - given %x joints - extra items will be ignored.", MAX_JOINT_INFLUENCES, n);
		n = MAX_JOINT_INFLUENCES;
	}

	m_controller->meshBuilder->Save();

	/// assign weight and joint to underlying primitives
	for (auto geom : m_controller->meshBuilder->GetGeometries()) {

		/// get an ordered list of used vertex (POSITION semantic) inside this primitive
		std::vector<uint32_t> mapping = geom->GetOriginalIndices();
		std::vector<uint32_t> indices = geom->GetIndices();

		/** 
		 * assign weigth & joints. We gona flatten array[][n].
		 */
		size_t size = m_controller->data->weights.size() * n;
		std::vector<float> weights;
		weights.reserve(size);
		std::vector<uint32_t> joints;
		joints.reserve(size);

		for (int i = 0; i != mapping.size();i++) {

			uint32_t originalIndex = mapping[i];
			uint32_t index = indices[i];
			float* weight = m_controller->data->weights[originalIndex];
			uint32_t* joint = m_controller->data->jointIndices[originalIndex];

			for (int k = 0; k != n; k++) {
				joints.push_back(joint[k]);
				weights.push_back(weight[k]);
			}
		}

		geom->WithJoints(std::move(joints), std::move(weights));
	}

	std::shared_ptr<Mesh> mesh = m_controller->meshBuilder->Build();
	m_controller->meshBuilder->Restore();

	return mesh;
}

