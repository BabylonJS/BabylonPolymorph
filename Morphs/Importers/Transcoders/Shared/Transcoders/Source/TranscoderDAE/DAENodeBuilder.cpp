/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"
#include <algorithm>


#include <TranscoderDAE/DAENodeBuilder.h>
#include <TranscoderDAE/DAEAnimation.h>

DEFINE_TRACE_AREA(DAENodeBuilder, 0);


using namespace Babylon::Transcoder;

std::shared_ptr<SceneNode> DAENodeBuilder::Build(CircularMap* map, std::function<void(DAENodeBuilder*, std::shared_ptr<SceneNode>)> callback) {

	/// AVOID CIRCULAR REF
	if (std::count(map->begin(), map->end(), this)) {
		TRACE_WARN(DAENodeBuilder, "Circular reference detected %s", m_id.toAscii());
		return nullptr;
	}
	map->push_back(this);

	// build the node
	std::shared_ptr<SceneNode> ptr = std::make_shared<SceneNode>();
	ptr->SetName(GetName());

	// do we have transform
	if (m_transforms.size()) {
		Babylon::Utils::Math::Matrix t = Babylon::Utils::Math::Matrix::Identity;
		for (size_t i = 0; i != m_transforms.size(); i++) {
			/// aggrgate
			t = t * m_transforms[i];
		}
		ptr->SetTransform(t);
	}

	// mesh is already baked - on next version, we gonna have a MeshInstanceBuilder
	if (m_mesh) {
		ptr->SetMesh(m_mesh);
	}

	// do we have camera binded
	if (m_camera) {
		ptr->SetCamera(m_camera);
	}

	// light is an extension, may be dismissed in futur version
	if (m_light) {
		ptr->SetLight(m_light);
	}

	// node instances
	if (m_instances.size()) {
		for (size_t i = 0; i != m_instances.size(); i++) {
			std::shared_ptr<DAENodeBuilder> nb = GetContext()->getNodeLibrary()[m_instances[i]];
			if (nb) {
				std::shared_ptr<SceneNode> sn = nb->Build(callback);
				if (sn) {
					ptr->AddChildNode(sn);
				}
			}  else {
				TRACE_WARN(DAENodeBuilder, "Unable to find Instance %s", m_instances[i].toAscii());
			}
		}
	}

	// skin 
	if (m_controller.isValid()) {
		BuildController(ptr);
	}

	// hierarchy..
	if (m_children.size()) {
		for (size_t i = 0; i != m_children.size(); i++) {
			std::shared_ptr<DAENodeBuilder> nb = m_children[i];
			/// Do NOT mix JOINT and NODE down hirerachy
			if (nb->GetType() == m_type) {
				std::shared_ptr<SceneNode> sn = nb->Build(callback);
				if (sn) {
					ptr->AddChildNode(sn);
				}
			}
		}
	}

	if (callback) {
		callback(this, ptr);
	}
	return ptr;
}

//
//std::shared_ptr<Mesh> DAENodeBuilder::BuildSkin(std::shared_ptr<DAESkinController> controller) {
//
//	int n0 = controller->data->getNumberOfComponents();
//	int n = n0;
//	/// Asset3D do NOT support more than 4 joints/weights per vertex
//	if (n > MAX_JOINT_INFLUENCES) {
//		TRACE_WARN(DAENodeBuilder, "Asset 3D currently accept ONLY %x joints influences - given %x joints - extra items will be ignored.", MAX_JOINT_INFLUENCES, n);
//		n = MAX_JOINT_INFLUENCES;
//	}
//
//	controller->meshBuilder->Save();
//
//	/// assign weight and joint to underlying primitives
//	for (auto geom : controller->meshBuilder->GetGeometries()) {
//
//		/// get an ordered list of used vertex (POSITION semantic) inside this primitive
//		std::vector<uint32_t> mapping = geom->GetOriginalIndices();
//		std::vector<uint32_t> indices = geom->GetIndices();
//
//		/**
//		 * assign weigth & joints. We gona flatten array[][n].
//		 */
//		size_t size = controller->data->weights.size() * n;
//		std::vector<float> weights;
//		weights.reserve(size);
//		std::vector<uint32_t> joints;
//		joints.reserve(size);
//
//		for (int i = 0; i != mapping.size(); i++) {
//
//			uint32_t originalIndex = mapping[i];
//			uint32_t index = indices[i];
//			float* weight = controller->data->weights[originalIndex];
//			uint32_t* joint = controller->data->jointIndices[originalIndex];
//			uint32_t offset = index * n0; // we seek offset using original number of component
//
//			/// note : keeping in mind as indices are describnig faces, this should be repeated several time at the same offset
//			joints.insert(joints.begin() + offset, joint, joint + n);
//			weights.insert(weights.begin() + offset, weight, weight + n);
//		}
//
//		geom->WithJoints(std::move(joints), std::move(weights));
//	}
//
//	std::shared_ptr<Mesh> mesh = controller->meshBuilder->Build();
//	controller->meshBuilder->Restore();
//
//	return mesh;
//}

/** 
 Build controller node which is 
 + node
   + skin node
   + skeleton nodes
 And register Skeleton objet to the context.
 */
void DAENodeBuilder::BuildController(std::shared_ptr<SceneNode> node) {

	std::shared_ptr<DAESkinController> SkinController = GetContext()->getSkinControllerLibrary()[m_controller];
	
	if (SkinController) {

		/// Deploying the joint implies to find the root of the skeleton -> ONLY ONE root is allowed so far
		COLLADAFW::UniqueId rootId = findRoots(SkinController->joints, m_context)[0];
		std::shared_ptr<DAENodeBuilder> skeletonRootNodeBuilder = GetContext()->getNodeLibrary()[rootId];
		if (skeletonRootNodeBuilder) {

			std::map<COLLADAFW::UniqueId, std::shared_ptr<SceneNode>> asset3DMap;
			std::map<COLLADAFW::UniqueId, COLLADAFW::UniqueId> parentIndex;

			// build the skeleton node, mapping the builded node and parents with the ColladaOriginal id using callback traverse function
			std::shared_ptr<SceneNode> skeletonRootNode = skeletonRootNodeBuilder->Build([&]( DAENodeBuilder* builder, std::shared_ptr<SceneNode> nodePtr){
				asset3DMap[builder->m_id] = nodePtr;
				parentIndex[builder->m_id] = builder->m_id == rootId ? COLLADAFW::UniqueId::INVALID : builder->GetParent()->m_id;
			});
			
			if (skeletonRootNode) {
				//// register asset nodes
				node->AddChildNode(skeletonRootNode);

				// build the skeleton
				std::shared_ptr<Animation::Skeleton> skeletonPtr = std::make_shared<Animation::Skeleton>();
				for (int i = 0; i != SkinController->joints.size();i++) {
					// get the node and parent node of the joint
					std::shared_ptr<SceneNode> sceneNode = asset3DMap[SkinController->joints[i]];
					COLLADAFW::UniqueId parentId = parentIndex[SkinController->joints[i]];
					std::shared_ptr<SceneNode> parentNode = parentId == COLLADAFW::UniqueId::INVALID ? nullptr : asset3DMap[parentId];

					// build the joint
					Animation::Joint j(sceneNode->GetName(), parentNode ? parentNode->GetId() : -1);
					j.m_sceneNodeId = sceneNode->GetId();
					j.m_uniqueId = (void*)sceneNode.get();
					j.m_InvBindPose = SkinController->data->inverseBindMatrices[i];
					skeletonPtr->m_joints.push_back(j);
				}
				// register the asset3D skeleton into context.
				// use the order of the skeleton declaration to set the index of skeleton, which will be translate as "skinId" attribute under gltfNode

				/// bind the skin 
				node->SetSkeletonID(GetContext()->getSkeletonLibrary().size());
				GetContext()->getSkeletonLibrary()[m_controller] = skeletonPtr;
			}
			else {
				TRACE_WARN(DAENodeBuilder, "Unable to build skeleton hirarchy %s", rootId.toAscii());
			}
		}
		else {
			TRACE_WARN(DAENodeBuilder, "Unable to find Skeleton root %s", rootId.toAscii());
		}
	}
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

