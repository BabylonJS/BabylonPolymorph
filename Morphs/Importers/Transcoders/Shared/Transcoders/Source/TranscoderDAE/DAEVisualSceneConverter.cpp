/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAECoreConverter.h>
#include <TranscoderDAE/DAENodeBuilder.h>
#include <TranscoderDAE/DAEAnimation.h>

#include <Asset3D/Asset3D.h>

#include "COLLADAFWVisualScene.h"

using namespace Babylon::Transcoder;

std::shared_ptr<Asset3D> DAEVisualSceneConverter::Convert(const COLLADAFW::VisualScene* colladaScene) {
	
	std::shared_ptr<Asset3D> scene = std::make_shared<Asset3D>();
	scene->SetName(colladaScene->getName().empty() ? _DEFAULT_SCENE_NAME : colladaScene->getName());
	scene->SetTransform(getContext()->getUpAxisTransfrom());
	scene->SetSystemUnit(getContext()->getScaleMeter() * Asset3D::SYSTEMUNIT_METER);

	/// loop over root nodes, convert and build in one pass. 
	COLLADAFW::NodePointerArray colladaRootNodes = colladaScene->getRootNodes();
	DAENodeConverter nc(getContext());
	int count = colladaRootNodes.getCount();
	if (count != 0) {
		for (int i = 0; i != count; i++) {
			COLLADAFW::Node* colladaNode = colladaRootNodes[i];
			/// convert will reference the node into nodeLibrary
			std::shared_ptr<DAENodeBuilder> builder = nc.Convert(colladaRootNodes[i]);

			if (builder && colladaNode->getType() == COLLADAFW::Node::NodeType::NODE) {
				std::shared_ptr<SceneNode> node = builder->Build();
				if (node) {
					scene->AddChildNode(node);
				}
			}
		}
	}

	/// morphs

	/// animations


	return scene;
}
