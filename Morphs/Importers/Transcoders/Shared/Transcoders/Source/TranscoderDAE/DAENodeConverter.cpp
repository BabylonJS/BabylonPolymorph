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


std::shared_ptr<SceneNode> DAENodeConverter::Convert(const COLLADAFW::Node* colladaNode, std::shared_ptr<SceneNode> node) {

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
	COLLADAFW::TransformationPointerArray colladaTransforms = colladaNode->getTransformations();
	COLLADABU::Math::Matrix4 matrix = COLLADABU::Math::Matrix4::IDENTITY;
	for (size_t i = 0; i != colladaTransforms.getCount(); i++) {
		/// aggrgate
		matrix = matrix * getMatrixFromTransform(colladaTransforms[i], 1);
	}
	/// save the transformation to the new node
	node->SetTransform(toBabylonMatrix(matrix));


	/// INSTANCES
	/// ---------
	COLLADAFW::InstanceGeometryPointerArray colladaGeometries = colladaNode->getInstanceGeometries();
	size_t countGeometry = colladaGeometries.getCount();
	COLLADAFW::InstanceControllerPointerArray colladaControllers = colladaNode->getInstanceControllers();
	size_t countController = colladaControllers.getCount();
	COLLADAFW::InstanceNodePointerArray colladaNodes = colladaNode->getInstanceNodes();
	size_t countNode = colladaNodes.getCount();
	size_t totalCount = countGeometry + countController + countNode;

	/// GEOMETRY
	for (size_t i = 0; i != countGeometry; i++) {

		COLLADAFW::InstanceGeometry* colladaInstance = colladaGeometries[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		std::shared_ptr<Mesh> mesh = m_context->getGeometryLibrary()[colladaUid];
		if (mesh) {
			if (totalCount == 1) {
				node->SetMesh(mesh);
				continue;
			}
			/// because Asset3D node do NOT accept more than one Mesh, we might create direct children to hold differents meshes
			std::shared_ptr<SceneNode> child = node->CreateChildNode();
			child->SetName(mesh->GetName());
			child->SetMesh(mesh);
		}
	}


	/// CONTROLLER - Note the controller instance lead to skin which are binded to Mesh...
	for (size_t i = 0; i != countController; i++) {

		COLLADAFW::InstanceController* colladaInstance = colladaControllers[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		COLLADAFW::UniqueId meshUid = m_context->getControllerToSkinIndex()[colladaUid];
		std::shared_ptr<Mesh> mesh = m_context->getGeometryLibrary()[meshUid];
		if (mesh) {
			if (totalCount == 1) {
				node->SetMesh(mesh);
				continue;
			}
			/// because Asset3D node do NOT accept more than one Mesh, we might create direct children to hold differents meshes
			std::shared_ptr<SceneNode> child = node->CreateChildNode();
			child->SetName(mesh->GetName());
			child->SetMesh(mesh);
		}
	}

	/// NODES
	for (size_t i = 0; i != countNode; i++) {

		COLLADAFW::InstanceNode* colladaInstance = colladaNodes[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		std::shared_ptr<SceneNode> sn = m_context->getNodeLibrary()[colladaUid];
		if (sn) {
			node->AddChildNode(sn);
		}
	}

	/// HIERARCHY
	/// ----------
	COLLADAFW::NodePointerArray colladaChildNodes = colladaNode->getChildNodes();
	for (size_t i = 0; i != colladaChildNodes.getCount(); i++) {
		std::shared_ptr<SceneNode> child = Convert(colladaChildNodes[i]);
		if (child) {
			node->AddChildNode(child);
		}
	}
	return node;
}

std::shared_ptr<SceneNode> DAENodeConverter::Convert(const COLLADAFW::Node* colladaNode) {
	return Convert(colladaNode, std::make_shared<SceneNode>());
}

