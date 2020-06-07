/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"
#include <algorithm>

#include <TranscoderDAE/DAENodeBuilder.h>
#include <TranscoderDAE/DAEAnimation.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>

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
				std::shared_ptr<SceneNode> sn = nb->Build();
				if (sn) {
					ptr->AddChildNode(sn);
				}
			}  else {
				TRACE_WARN(DAENodeBuilder, "Unable to find Instance %s", m_instances[i].toAscii());
			}
		}
	}

	if (m_controller.isValid()) {

		std::shared_ptr<DAESkinController> sc = GetContext()->getSkinControllerLibrary()[m_controller];
		if (sc) {
			/// Deploying the joint implies to find the root of the skeleton -> ONLY ONE root is allowed so far
			COLLADAFW::UniqueId root = findRoots(sc->joints, m_context)[0];

	
			std::shared_ptr<DAENodeBuilder> nb = GetContext()->getNodeLibrary()[root];
			if (nb) {
				std::shared_ptr<SceneNode> sn = nb->Build();
				if (sn) {
					std::shared_ptr<DAESkeletonBuilder> skb = std::make_shared<DAESkeletonBuilder>(GetContext());
					skb->WithRoot(sn).WithSkinData(sc);

					sn->SetSkeletonID(sn->GetId());
					GetContext()->getSkeletonLibrary().push_back(skb);
					
					ptr->AddChildNode(sn);
				} else {
					TRACE_WARN(DAENodeBuilder, "Unable to build skeleton hirarchy %s", root.toAscii());
				}
			} else {
				TRACE_WARN(DAENodeBuilder, "Unable to find Skeleton root %s", root.toAscii());
			}
		}

	}

	if (m_children.size()) {
		for (size_t i = 0; i != m_children.size(); i++) {
			std::shared_ptr<DAENodeBuilder> nb = m_children[i];
			/// Do NOT mix JOINT and NODE down hirerachy
			if (nb->GetType() == m_type) {
				std::shared_ptr<SceneNode> sn = nb->Build();
				if (sn) {
					ptr->AddChildNode(sn);
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
		TRACE_WARN(DAENodeBuilder, "Detected duplicate instance reference on node %s:%s - reference skipped.", m_id.toAscii(), id.toAscii());
	}
	return *this;
}

