/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAESceneConverter.h>

#include <TranscoderDAE/DAEMeshBuilder.h>

#include <Asset3D/Asset3D.h>

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWMaterialBinding.h"


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
    
	/// bind the name.
	node->SetName(node->GetIdString());

	/// INSTANCES
	/// ---------
	COLLADAFW::InstanceGeometryPointerArray colladaGeometries = colladaNode->getInstanceGeometries();
	size_t countGeometry = colladaGeometries.getCount();
	COLLADAFW::InstanceControllerPointerArray colladaControllers = colladaNode->getInstanceControllers();
	size_t countController = colladaControllers.getCount();
	COLLADAFW::InstanceNodePointerArray colladaNodes = colladaNode->getInstanceNodes();
	size_t countNode = colladaNodes.getCount();
	size_t totalMeshCount = countGeometry + countController ;

	/// Note : because Asset3D node do NOT accept more than one Mesh, we might create direct children to hold differents meshes
	std::vector<std::shared_ptr<Mesh>> meshes;

	/// GEOMETRY
	for (size_t i = 0; i != countGeometry; i++) {

		COLLADAFW::InstanceGeometry* colladaInstance = colladaGeometries[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();

		std::shared_ptr<DAEMeshBuilder> meshBuilder = m_context->getGeometryLibrary()[colladaUid];
		if (meshBuilder) {

			/// get the instance material
			COLLADAFW::MaterialBindingArray & colladaBindMaterials = colladaInstance->getMaterialBindings();
			if (colladaBindMaterials.getCount()) {
				for (size_t j = 0; j != colladaBindMaterials.getCount(); j++) {
					
					/** 
					 * The <bind>and <bind_vertex_input> elements bind the target to a parameter in an <effect>.The
					 * search string that identifies the parameter in the <effect> is specified by the semantic attribute
					 * When locating the parameter in the <effect>, the search is done in the following order :
					 * 1 - Find a COLLADA FX parameter by semantic
					 * 2 - If the profile contains shading language code, find a parameter within the shader by semantic.
					 * 3 - Find a COLLADA FX parameter by sid.
					 * 4 - If the profile contains shading language code, find a parameter within the shader by name
					 */
					 COLLADAFW::MaterialBinding& colladaBinding = colladaBindMaterials[j];
					 const COLLADAFW::UniqueId& colladaMaterialUid = colladaBinding.getReferencedMaterial();

					/**
					 * According that Asset3D DO NOT Provide a way to instanciate N material for ONE geometry, this is where we clone the mesh
					 * using the builder GetGeometries() then GeometryBuilder.WithMaterial() and GeometryBuilder.WithChannelO() and GeometryBuilder.WithChannel1().
					 */
					std::shared_ptr<Mesh> m = meshBuilder->Build();
					meshes.push_back(m);
				}
			} else {
				std::shared_ptr<Mesh> m = meshBuilder->Build();
				meshes.push_back(m);
			}
		}
	}


	/// CONTROLLER - Note the controller instance lead to skin which are binded to Mesh...
	for (size_t i = 0; i != countController; i++) {

		COLLADAFW::InstanceController* colladaInstance = colladaControllers[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		COLLADAFW::UniqueId meshUid = m_context->getControllerToSkinIndex()[colladaUid];
		std::shared_ptr<DAEMeshBuilder> meshBuilder = m_context->getGeometryLibrary()[colladaUid];
		if (meshBuilder) {
			std::shared_ptr<Mesh> m = meshBuilder->Build();
			meshes.push_back(m);
		}
	}

	if (meshes.size()) {
		if (meshes.size() == 1) {
			node->SetMesh(meshes[0]);
		}
		else {
			for (int j = 0; j != meshes.size(); j++) {
				std::shared_ptr<SceneNode> tmp = node->CreateChildNode();
				if (tmp) {
					tmp->SetName(meshes[0]->GetName());
					node->SetMesh(meshes[0]);
				}
			}
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

