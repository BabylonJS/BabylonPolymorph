/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAECoreConverter.h>

#include <TranscoderDAE/DAEAnimation.h>

#include <TranscoderDAE/DAEMeshBuilder.h>
#include <TranscoderDAE/DAEFXBuilder.h>
#include <TranscoderDAE/DAECameraBuilder.h>
#include <TranscoderDAE/DAELightBuilder.h>
#include <TranscoderDAE/DAENodeBuilder.h>
#include <TranscoderDAE/DAESkinGeometryBuilder.h>

#include <Asset3D/Asset3D.h>

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWMaterialBinding.h"

DEFINE_TRACE_AREA(DAENodeConverter, 0);

using namespace Babylon::Transcoder;

namespace {

	/// TODO : investigate to the UVSet
	std::shared_ptr<Mesh> BuildMeshWithDefaultMaterial( std::shared_ptr<IDAEMeshBuilder> meshBuilder, DAEToAsset3DWriterContext * ctx) {
		
		meshBuilder->Save();

#ifdef _IMPORT_MATERIAL
		std::vector<std::shared_ptr<DAEGeometryBuilder>> geometryBuilders = meshBuilder->GetGeometries();

		for (int g = 0; g != geometryBuilders.size(); g++) {
			const std::string& mid = geometryBuilders[g]->GetMaterialName();
			const COLLADAFW::UniqueId& colladaEffect = ctx->getMaterialOriginalIdToEffectIndex()[mid];
			std::shared_ptr<DAEMaterialBuilder> materialBuilder = ctx->getEffectLibrary()[colladaEffect];
			geometryBuilders[g]->Save();
			if (materialBuilder) {
				geometryBuilders[g]->WithMaterial(materialBuilder).WithChannelO(0);
			} else {
				TRACE_WARN(DAENodeConverter, "Unable to find material %s", colladaEffect.toAscii());
			}
		}
#endif

		std::shared_ptr<Mesh> m = meshBuilder->Build();
		if (!m) {
			TRACE_WARN(DAENodeConverter, "Unable to build mesh %s", meshBuilder->GetName());
		}

		meshBuilder->Restore();
		return m;
	}

	std::shared_ptr<Mesh> BuildMeshWithBindingMaterial(COLLADAFW::MaterialBindingArray& colladaBindMaterials, std::shared_ptr<IDAEMeshBuilder> meshBuilder, DAEToAsset3DWriterContext* ctx) {
		meshBuilder->Save();

#ifdef _IMPORT_MATERIAL

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
					geometryBuilders[g]->WithMaterial(materialBuilder).WithChannelO(0);
				}
			} else {
				TRACE_WARN(DAENodeConverter, "Unable to find material %s", colladaEffect.toAscii());
			}
		}
#endif

		std::shared_ptr<Mesh> m = meshBuilder->Build();
		if (!m) {
			TRACE_WARN(DAENodeConverter, "Unable to build mesh %s", meshBuilder->GetName());
		}

		meshBuilder->Restore();
		return m ;
	}
}

std::shared_ptr<DAENodeBuilder> DAENodeConverter::Convert(const COLLADAFW::Node* colladaNode) {

	std::shared_ptr<DAENodeBuilder> builder = std::make_shared<DAENodeBuilder>(getContext());
	
	builder->WithId(colladaNode->getUniqueId()).WithNodeType(colladaNode->getType()).WithName(NAME_OR_ID(colladaNode));
	getContext()->getNodeLibrary()[colladaNode->getUniqueId()] = builder;

	/// TRANSFORM
	/// ----------
	COLLADAFW::TransformationPointerArray colladaTransforms = colladaNode->getTransformations();
	for (size_t i = 0; i != colladaTransforms.getCount(); i++) {
		COLLADABU::Math::Matrix4 matrix = getMatrixFromTransform(colladaTransforms[i], 1);
		builder->WithTransform(toBabylonMatrix(matrix));
	}

	/// GEOMETRY
	/// --------
	/// Note : because Asset3D node do NOT accept more than one Mesh, we might create direct children to hold differents meshes
	std::vector<std::shared_ptr<Mesh>> meshes;

	COLLADAFW::InstanceGeometryPointerArray colladaGeometries = colladaNode->getInstanceGeometries();
	size_t countGeometry = colladaGeometries.getCount();
	size_t meshCount = 0;
	for (size_t i = 0; i != countGeometry; i++) {

		COLLADAFW::InstanceGeometry* colladaInstance = colladaGeometries[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();

		std::shared_ptr<Mesh> mesh = nullptr;
		std::shared_ptr<IDAEMeshBuilder> meshBuilderPtr = getContext()->getGeometryLibrary()[colladaUid];
		if (meshBuilderPtr) {

#ifdef _IMPORT_MATERIAL
			/// do we have binding material ??
			COLLADAFW::MaterialBindingArray& colladaBindMaterials = colladaInstance->getMaterialBindings();
			if (colladaBindMaterials.getCount()) {
				mesh = BuildMeshWithBindingMaterial(colladaBindMaterials, meshBuilderPtr, getContext());
			}
			else {
				mesh = BuildMeshWithDefaultMaterial(meshBuilderPtr, getContext());
			}
#else
			mesh = meshBuilder->Build();
#endif
			if (mesh) {
				if (meshCount == 0) {
					builder->WithMesh(mesh);
					continue;
				}
				// subsequent mesh will be saved on dedicated children
				std::shared_ptr<DAENodeBuilder> tmp = std::make_shared<DAENodeBuilder>(m_context);
				if (tmp) {
					tmp->WithMesh(mesh).WithName(mesh->GetName());
					builder->WithChild(tmp);
				}
				meshCount++;
			}
			else {
				TRACE_WARN(DAENodeConverter, "Unable to build mesh %s", meshBuilderPtr->GetName());
			}
		}
		else {
			TRACE_WARN(DAENodeConverter, "Unable to find Geometry %s", colladaUid.toAscii());
		}
	}


	/// CONTROLLER - Note the controller instance lead to skin which is binded to Mesh...
	COLLADAFW::InstanceControllerPointerArray colladaControllers = colladaNode->getInstanceControllers();
	size_t countController = colladaControllers.getCount();
	for (size_t i = 0; i != countController; i++) {

		COLLADAFW::InstanceController* colladaInstance = colladaControllers[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();

		std::shared_ptr<Mesh> mesh = nullptr;
		std::shared_ptr<IDAEMeshBuilder> meshBuilderPtr = getContext()->getGeometryLibrary()[colladaUid];
		if (meshBuilderPtr) {
#ifdef _IMPORT_MATERIAL
			/// do we have binding material ??
			COLLADAFW::MaterialBindingArray& colladaBindMaterials = colladaInstance->getMaterialBindings();
			if (colladaBindMaterials.getCount()) {
				mesh = BuildMeshWithBindingMaterial(colladaBindMaterials, meshBuilderPtr, getContext());
			}
			else {
				mesh = BuildMeshWithDefaultMaterial(meshBuilderPtr, getContext());
			}
#else
			mesh = meshBuilder->Build();
#endif
			if (mesh) {
				if (meshCount == 0) {
					builder->WithMesh(mesh);
					builder->WithController(colladaUid);
					continue;
				}
				// subsequent mesh will be saved on dedicated children
				std::shared_ptr<DAENodeBuilder> tmp = std::make_shared<DAENodeBuilder>(m_context);
				if (tmp) {
					tmp->WithMesh(mesh).WithName(mesh->GetName());
					tmp->WithController(colladaUid);
					builder->WithChild(tmp);
				}
				meshCount++;
			}
			else {
				TRACE_WARN(DAENodeConverter, "Unable to build mesh %s", meshBuilderPtr->GetName());
			}
		}
		else {
			TRACE_WARN(DAENodeConverter, "Unable to find Geometry %s", colladaUid.toAscii());
		}
	}

	/// NODES Instance
	COLLADAFW::InstanceNodePointerArray colladaNodes = colladaNode->getInstanceNodes();
	size_t countNode = colladaNodes.getCount();

	for (size_t i = 0; i != countNode; i++) {
		COLLADAFW::InstanceNode* colladaInstance = colladaNodes[i];
		const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
		builder->WithInstance(colladaUid);
	}

#ifdef _IMPORT_CAMERA
	/// CAMERAS Instance
	COLLADAFW::InstanceCameraPointerArray colladaCameras = colladaNode->getInstanceCameras();
	size_t countCamera = colladaCameras.getCount();
	for (size_t i = 0; i != countCamera; i++) {
		COLLADAFW::InstanceCamera* colladaCamera = colladaCameras[i];
		const COLLADAFW::UniqueId& colladaUid = colladaCamera->getInstanciatedObjectId();
		std::shared_ptr<DAECameraBuilder> cb = m_context->getCameraLibrary()[colladaUid];
		if (cb) {
			if (countCamera == 1) {
				builder->WithCamera(cb->Build());
				continue;
			}
			/// add child node to allow multiple camera
			std::shared_ptr<DAENodeBuilder> tmp = std::make_shared<DAENodeBuilder>(m_context);
			if (tmp) {
				tmp->WithCamera(cb->Build()).WithName(cb->GetName());
				builder->WithChild(tmp);
			}
		}
		else {
			TRACE_WARN(DAENodeConverter, "Unable to find camera %s", colladaUid.toAscii());
		}
	}
#endif


#ifdef _IMPORT_LIGHT
	/// LIGHTS Instance
	COLLADAFW::InstanceLightPointerArray colladaLights = colladaNode->getInstanceLights();
	size_t countLight = colladaLights.getCount();
	for (size_t i = 0; i != countLight; i++) {
		COLLADAFW::InstanceLight* colladaLight = colladaLights[i];
		const COLLADAFW::UniqueId& colladaUid = colladaLight->getInstanciatedObjectId();
		std::shared_ptr<DAELightBuilder> lb = m_context->getLightLibrary()[colladaUid];
		if (lb) {
			if (countLight == 1) {
				builder->WithLight(lb->Build());
				continue;
			}
			/// add child node to allow multiple light
			std::shared_ptr<DAENodeBuilder> tmp = std::make_shared<DAENodeBuilder>(m_context);
			if (tmp) {
				tmp->WithLight(lb->Build()).WithName(lb->GetName());
				builder->WithChild(tmp);
			}
		}
		else {
			TRACE_WARN(DAENodeConverter, "Unable to find light %s", colladaUid.toAscii());
		}
	}
#endif

	/// HIERARCHY
	const COLLADAFW::NodePointerArray colladaChildren = colladaNode->getChildNodes();
	int count = colladaChildren.getCount();
	if (count) {
		for (int i = 0; i != count; i++) {
			std::shared_ptr<DAENodeBuilder> node = Convert(colladaChildren[i]);
			builder->WithChild(node);
		}
	}
	return builder;
}


