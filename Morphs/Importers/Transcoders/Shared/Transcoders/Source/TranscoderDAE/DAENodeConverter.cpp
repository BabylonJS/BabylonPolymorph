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
#include <TranscoderDAE/DAEFXBuilder.h>

#include <Asset3D/Asset3D.h>

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWMaterialBinding.h"


using namespace Babylon::Transcoder;

namespace {

	/// TODO : investigate to the UVSet
	void BuildMeshWithDefaultMaterial( std::shared_ptr<DAEMeshBuilder> meshBuilder, DAEToAsset3DWriterContext * ctx, std::vector<std::shared_ptr<Mesh>> * meshes) {
		
#ifdef _IMPORT_MATERIAL
		meshBuilder->Save();
		std::vector<std::shared_ptr<DAEGeometryBuilder>> geometryBuilders = meshBuilder->GetGeometries();

		for (int g = 0; g != geometryBuilders.size(); g++) {
			const std::string& mid = geometryBuilders[g]->GetMaterialName();
			const COLLADAFW::UniqueId& colladaEffect = ctx->getMaterialOriginalIdToEffectIndex()[mid];
			std::shared_ptr<DAEMaterialBuilder> materialBuilder = ctx->getEffectLibrary()[colladaEffect];
			geometryBuilders[g]->Save();
			if (materialBuilder) {
				geometryBuilders[g]->WithMaterial(materialBuilder).WithChannelO(0);
			}
		}
		std::shared_ptr<Mesh> m = meshBuilder->Build();

		meshBuilder->Restore();
		if (m) {
			meshes->push_back(m);
		}

		meshBuilder->Restore();
#else
		std::shared_ptr<Mesh> m = meshBuilder->Build();
		meshes.push_back(m);
#endif
	}

	/// TODO : investigate to the UVSet
	void BuildMeshWithBindingMaterial(COLLADAFW::MaterialBindingArray& colladaBindMaterials, std::shared_ptr<DAEMeshBuilder> meshBuilder, DAEToAsset3DWriterContext* ctx, std::vector<std::shared_ptr<Mesh>>* meshes) {
		meshBuilder->Save();

		for (size_t j = 0; j != colladaBindMaterials.getCount(); j++) {

			const COLLADAFW::MaterialBinding& colladaBinding = colladaBindMaterials[j];
			const COLLADAFW::UniqueId& colladaMaterialUid = colladaBinding.getReferencedMaterial();

			const COLLADAFW::UniqueId& colladaEffect = ctx->getMaterialUIdToEffectIndex()[colladaMaterialUid];
			std::shared_ptr<DAEMaterialBuilder> materialBuilder = ctx->getEffectLibrary()[colladaEffect];
			if (materialBuilder) {

				/// get corresponding geometry under the mesh - the one's bind with material name
				std::vector<std::shared_ptr<DAEGeometryBuilder>> geometryBuilders = meshBuilder->GetGeometries([&](const std::shared_ptr<DAEGeometryBuilder> a)->bool {
					return a->GetMaterialName().compare(colladaBinding.getName()) == 0;
				});

				/// assign new material builder
				for (int g = 0; g != geometryBuilders.size(); g++) {
					geometryBuilders[g]->WithMaterial(materialBuilder).WithChannelO(g);
				}
			}
		}
		std::shared_ptr<Mesh> m = meshBuilder->Build();
		if (m) {
			meshes->push_back(m);
		}

		meshBuilder->Restore();
	}
}

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
	size_t totalMeshCount = countGeometry + countController ;

	/// Note : because Asset3D node do NOT accept more than one Mesh, we might create direct children to hold differents meshes
	std::vector<std::shared_ptr<Mesh>> meshes;

	/// GEOMETRY
	for (size_t i = 0; i != countGeometry; i++) {

		COLLADAFW::InstanceGeometry* colladaInstance = colladaGeometries[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();

		std::shared_ptr<DAEMeshBuilder> meshBuilder = getContext()->getGeometryLibrary()[colladaUid];
		if (meshBuilder) {

#ifdef _IMPORT_MATERIAL
			/// do we have binding material ??
			COLLADAFW::MaterialBindingArray & colladaBindMaterials = colladaInstance->getMaterialBindings();
			if (colladaBindMaterials.getCount()) {
				BuildMeshWithBindingMaterial(colladaBindMaterials,meshBuilder, getContext(), &meshes);
			} else {
				BuildMeshWithDefaultMaterial(meshBuilder, getContext(), &meshes);
			}
#else
			std::shared_ptr<Mesh> m = meshBuilder->Build();
			meshes.push_back(m);
#endif
		}
	}

	/// CONTROLLER - Note the controller instance lead to skin which is binded to Mesh...
	for (size_t i = 0; i != countController; i++) {

		COLLADAFW::InstanceController* colladaInstance = colladaControllers[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		COLLADAFW::UniqueId& meshUid = m_context->getControllerToSkinIndex()[colladaUid];
		std::shared_ptr<DAEMeshBuilder> meshBuilder = m_context->getGeometryLibrary()[meshUid];
		if (meshBuilder) {
			BuildMeshWithDefaultMaterial(meshBuilder, getContext(), &meshes);
		}
	}

	/// build the corresponding nodes if we made meshes
	if (meshes.size()) {
		if (meshes.size() == 1) {
			node->SetMesh(meshes[0]);
		}
		else {
			for (int j = 0; j != meshes.size(); j++) {
				std::shared_ptr<SceneNode> tmp = node->CreateChildNode();
				if (tmp) {
					tmp->SetName(meshes[j]->GetName());
					tmp->SetMesh(meshes[j]);
				}
			}
		}
	}

	/// NODES Instance
	for (size_t i = 0; i != countNode; i++) {

		COLLADAFW::InstanceNode* colladaInstance = colladaNodes[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		std::shared_ptr<SceneNode> sn = m_context->getNodeLibrary()[colladaUid];
		if (sn) {
			node->AddChildNode(sn);
		}
	}

	/// HIERARCHY
	const COLLADAFW::NodePointerArray colladaChildren = colladaNode->getChildNodes();
	int count = colladaChildren.getCount();
	if (count) {
		for (int i = 0; i != count; i++) {
			node->AddChildNode(Convert(colladaChildren[i]));
		}
	}
	return node;
}

/**
 * Has sub node MAY contain reference to sibling node, we MUST conduct a Breadth-first algorithm
 * at the top level instead of Deep-first search. Otherwise we gona miss some node_instance.
 * ex :
 * <node id="ID4" name="skp56">
 *    <node id="ID5" name="instance_1">
 *        <matrix>1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1</matrix>
 *        <instance_node url="#ID6" />
 *    </node>
 * </node>
 * <node id="ID6" name="body_1">
 * ...
 * </node>
 */
std::shared_ptr<SceneNode> DAENodeConverter::ConvertBreadthFirst(const COLLADAFW::NodePointerArray * colladaNodes, std::shared_ptr<SceneNode> node) {
	int count = colladaNodes->getCount();
	if (count) {

		/// first pass to bind nodes to library, before going deep in hierarchy
		std::vector<std::shared_ptr<SceneNode>> queue;
		for (int i = 0; i != count; i++) {
			std::shared_ptr<SceneNode> n = node ? node->CreateChildNode() : std::make_shared<SceneNode>();
			if (n) {
				// start to register the node, then it will be available down hierarchy
				getContext()->getNodeLibrary()[(*colladaNodes)[i]->getUniqueId()] = n;
				queue.push_back(n);
			}
		}

		/// then going down hierarchy
		for (int i = 0; i != count; i++) {
			Convert((*colladaNodes)[i], queue[i]);
		}
	}
	return node;
}


std::shared_ptr<SceneNode> DAENodeConverter::Convert(const COLLADAFW::Node* colladaNode) {
	return Convert(colladaNode, std::make_shared<SceneNode>());
}

