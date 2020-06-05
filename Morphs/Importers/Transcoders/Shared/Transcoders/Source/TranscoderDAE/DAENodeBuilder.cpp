/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAENodeBuilder.h>

DEFINE_TRACE_AREA(DAENodeBuilder, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<SceneNode> DAENodeBuilder::Build(CircularMap* map) {

	/// AVOID CIRCULAR REF
	if (std::count(map->begin(), map->end(), this)) {
		TRACE_WARN(DAENodeBuilder, "Circular reference detected %s", m_id.toAscii());
		return nullptr;
	}

	std::shared_ptr<SceneNode> ptr = std::make_shared<SceneNode>();
	ptr->SetName(GetName());

	if (m_transforms.size()) {
		Babylon::Utils::Math::Matrix t = Babylon::Utils::Math::Matrix::Identity;
		for (size_t i = 0; i != m_transforms.size(); i++) {
			/// aggrgate
			t = t * m_transforms[i];
		}
		ptr->SetTransform(t);
	}
	if (m_mesh) {
		ptr->SetMesh(m_mesh);
	}
	if (m_camera) {
		ptr->SetCamera(m_camera);
	}
	if (m_light) {
		ptr->SetLight(m_light);
	}
	if (m_instances.size()) {
		for (size_t i = 0; i != m_instances.size(); i++) {
			std::shared_ptr<DAENodeBuilder> nb = GetContext()->getNodeLibrary()[m_instances[i]];
			if (nb) {
				std::shared_ptr<SceneNode> clone = nb->Build();
				if (clone) {
					ptr->AddChildNode(clone);
				}
			}
			else {
				TRACE_WARN(DAENodeBuilder, "Unable to find Node %s", m_instances[i].toAscii());
			}
		}
	}
	if (m_children.size()) {
		for (size_t i = 0; i != m_children.size(); i++) {
			std::shared_ptr<DAENodeBuilder> nb = m_children[i];
			/// do NOT mix NODE and JOINT
			if (nb->GetType() == GetType()) {
				std::shared_ptr<SceneNode> clone = nb->Build();
				if (clone) {
					ptr->AddChildNode(clone);
				}
			}
		}
	}
	return ptr;
}

DAENodeBuilder& DAENodeBuilder::WithInstance(COLLADAFW::UniqueId id) {
	/// avoid duplicate - IE Corrupted file
	if (!std::count(m_instances.begin(), m_instances.end(), id)) {
		m_instances.push_back(id);
	}
	else {
		/// we have a duplicate reference
		TRACE_WARN(DAENodeBuilder, "Detected duplicate reference on node %s:%s - reference skipped.", m_id.toAscii(), id.toAscii());
	}
	return *this;
}

std::shared_ptr<Animation::Joint> DAENodeBuilder::BuildJoint() {
	std::shared_ptr<Animation::Joint> ptr = nullptr;
	if (IsJoint()) {
		ptr = std::make_shared<Animation::Joint>(GetName());
	}
	return ptr;
}
