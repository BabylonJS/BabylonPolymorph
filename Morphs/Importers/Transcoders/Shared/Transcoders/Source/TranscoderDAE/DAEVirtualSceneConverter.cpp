/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAESceneConverter.h>

#include <Asset3D/Asset3D.h>

#include "COLLADAFWVisualScene.h"


using namespace Babylon::Transcoder;


std::shared_ptr<SceneNode> DAEVirtualSceneConverter ::Convert(const COLLADAFW::Node* colladaNode) {

	std::shared_ptr<SceneNode> node = std::make_shared<SceneNode>();
	node->SetName(colladaNode->getName());
	
	/// TRANSFORM
	/// ----------
	/**
	 * Get the transformations matrix :
	 * Collada is defined a set of transformation matrix. According to specification those transformations
	 * could be any of lookAt,matrix,rotate,scale, skew and translate.
	 * OpenCollada is holding any of these into a Transform Object.
	 * Asset3D is support ONLY ONE transformation matrix perx node, then we need to aggregate the 
	 * transformation by multiply the matrix together.
	 */
	COLLADAFW::TransformationPointerArray colladaTransforms  = colladaNode->getTransformations();
	COLLADABU::Math::Matrix4 m = COLLADABU::Math::Matrix4::IDENTITY;
	for (int i = 0; i != colladaTransforms.getCount(); i++) {
		/// aggrgate
		m = m * getMatrixFromTransform(colladaTransforms[i], 1);
	}
	/// save the transformation to the new node
	node->SetTransform(toBabylonMatrix(m));


	/// INSTANCES
	/// ---------

	COLLADAFW::InstanceGeometryPointerArray colladaGeometries = colladaNode->getInstanceGeometries();
	int countGeometry = colladaGeometries.getCount();
	COLLADAFW::InstanceControllerPointerArray colladaControllers = colladaNode->getInstanceControllers();
	int countController = colladaControllers.getCount();
	int totalCount = countGeometry + countController;

	/// GEOMETRY
	for (int i = 0; i != countGeometry; i++) {

		COLLADAFW::InstanceGeometry* colladaInstance = colladaGeometries[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		std::shared_ptr<Mesh> m = m_context->getGeometryLibrary()[colladaUid];
		if (m) {
			if (totalCount == 1) {
				node->SetMesh(m);
				continue;
			}
			/// because Asset3D node do NOT accept more than one Mesh, we might create direct children to hold differents meshes
			std::shared_ptr<SceneNode> child = node->CreateChildNode();
			child->SetName(m->GetName());
			child->SetMesh(m);
		}
	}


	/// CONTROLLER - Note the controller instance use contrioller, then skin whic are binded to Mesh...
	for (int i = 0; i != countController; i++) {

		COLLADAFW::InstanceController* colladaInstance = colladaControllers[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		COLLADAFW::UniqueId meshUid = m_context->getSkinLibrary()[colladaUid];
		std::shared_ptr<Mesh> m = m_context->getGeometryLibrary()[meshUid];
		if (m) {
			if (totalCount == 1) {
				node->SetMesh(m);
				continue;
			}
			/// because Asset3D node do NOT accept more than one Mesh, we might create direct children to hold differents meshes
			std::shared_ptr<SceneNode> child = node->CreateChildNode();
			child->SetName(m->GetName());
			child->SetMesh(m);
		}
	}

	/// HIERARCHY
	/// ---------
	COLLADAFW::NodePointerArray colladaChildNodes = colladaNode->getChildNodes();
	for (int i = 0; i != colladaChildNodes.getCount(); i++) {
		std::shared_ptr<SceneNode> child = Convert(colladaChildNodes[i]);
		if (child) {
			node->AddChildNode(child);
		}
	}
	return node;
}


std::shared_ptr<Asset3D> DAEVirtualSceneConverter::Convert(const COLLADAFW::VisualScene* colladaScene) {
	
	std::shared_ptr<Asset3D> scene = std::make_shared<Asset3D>();
	scene->SetName(colladaScene->getName());

	/// loop over root nodes
	COLLADAFW::NodePointerArray colladaRootNodes = colladaScene->getRootNodes();
	for (int i = 0; i != colladaRootNodes.getCount(); i++) {
		COLLADAFW::Node* colladaNode = colladaRootNodes[i];
		std::shared_ptr<SceneNode> child = Convert(colladaRootNodes[i]);
		if (child) {
			scene->AddChildNode(child);
		}
	}
	return scene;
}
