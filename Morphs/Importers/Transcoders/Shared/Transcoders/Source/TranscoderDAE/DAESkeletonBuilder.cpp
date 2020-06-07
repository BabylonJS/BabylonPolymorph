/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimation.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>

DEFINE_TRACE_AREA(DAESkeletonBuilder, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<Animation::Skeleton> DAESkeletonBuilder::Build() {

	std::shared_ptr<Animation::Skeleton> ptr = std::make_shared<Animation::Skeleton>();

	ISceneNodeUtils::DFS(m_root.get(), [&](const SceneNode* sceneNode, const SceneNode* parentNode) mutable {
		Animation::Joint j(sceneNode->GetName(), parentNode? parentNode->GetId():-1);
		j.m_sceneNodeId = sceneNode->GetId();
		j.m_uniqueId = (void*)sceneNode;
		ptr->m_joints.push_back(j);
	});

	return ptr;
}

