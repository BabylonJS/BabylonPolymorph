/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <iostream>
#include <TranscoderDAE/DAEToAsset3DWriter.h>
#include <TranscoderDAE/DAECoreConverter.h>
#include <TranscoderDAE/DAEFXConverter.h>
#include <TranscoderDAE/DAEGeometryBuilder.h>
#include <TranscoderDAE/DAECameraBuilder.h>
#include <TranscoderDAE/DAEFXBuilder.h>

#include <Asset3D\Asset3D.h>

#include <COLLADAFWGeometry.h>
#include <COLLADAFWVisualScene.h>
#include <COLLADAFWImage.h>
#include <COLLADAFWEffect.h>
#include <COLLADAFWLibraryNodes.h>


#include <COLLADASaxFWLIError.h>

using namespace Babylon::Transcoder; 
using namespace Babylon::Framework;

DAEToAsset3DWriterContext::DAEToAsset3DWriterContext(IResourceServer* resourceServer, const std::unordered_map<std::string, std::string>& options, ICancellationTokenPtr cancellationToken) :
	m_options(options),
	m_cancellationToken(cancellationToken),
	m_resourceServer(resourceServer)
{
	setUpAxisType(defaultUpAxis);
}

DAEToAsset3DWriterContext::~DAEToAsset3DWriterContext() {
}

void DAEToAsset3DWriterContext::setUpAxisType(COLLADAFW::FileInfo::UpAxisType t) {
	m_upAxis = t;
	switch (t) {
	case COLLADAFW::FileInfo::UpAxisType::X_UP: {
		m_upAxisTransform = Babylon::Utils::Math::Matrix(
			0, 1, 0, 0,
			-1, 0, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
		break;
	}
	case COLLADAFW::FileInfo::UpAxisType::Z_UP: {
		m_upAxisTransform = Babylon::Utils::Math::Matrix(
			1, 0, 0, 0,
			0, 0, -1, 0,
			0, 1, 0, 0,
			0, 0, 0, 1
		);
		break;
	}
	case COLLADAFW::FileInfo::UpAxisType::Y_UP:
	default: {
		m_upAxisTransform = Babylon::Utils::Math::Matrix::Identity;
		break;
	}
	}
}



DAEToAsset3DWriter::DAEToAsset3DWriter(IResourceServer* resourceServer, const std::unordered_map<std::string, std::string>& options, ICancellationTokenPtr cancellationToken) :
	m_context(resourceServer, options, cancellationToken)
{
}

DAEToAsset3DWriter::~DAEToAsset3DWriter() {
}

/** If this method returns true, the loader stops parsing immediately. If severity is nor CRITICAL
and this method returns false, the loader continues loading.*/
bool DAEToAsset3DWriter::handleError(const COLLADASaxFWL::IError* error) {
	return false;
}

/** This method will be called if an error in the loading process occurred and the loader cannot
continue to to load. The writer should undo all operations that have been performed.
@param errorMessage A message containing informations about the error that occurred.
*/
void DAEToAsset3DWriter::cancel(const COLLADAFW::String& errorMessage) {
}

/** This is the method called. The writer hast to prepare to receive data.*/
void DAEToAsset3DWriter::start() {
	/// nothing to do so far
}

/** This method is called after the last write* method. No other methods will be called after this.*/
void DAEToAsset3DWriter::finish() {
	/// nothing to do so far
}

/** When this method is called, the writer must write the global document asset.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeGlobalAsset(const COLLADAFW::FileInfo* asset) {

	DAEToAsset3DWriterContextPtr ctx = getContext();
	const COLLADAFW::FileInfo::ValuePairPointerArray& valuePairs = asset->getValuePairArray();
	for (size_t i = 0; i < valuePairs.getCount(); i++) {
		const COLLADAFW::FileInfo::ValuePair* valuePair = valuePairs[i];
		const COLLADAFW::String& key = valuePair->first;
		if (key == "authoring_tool") {
			ctx->SetAuthoringTool(valuePair->second);
		}
	}	
	ctx->setUpAxisType(asset->getUpAxisType());
	ctx->setScaleMeter((float)asset->getUnit().getLinearUnitMeter());
	return true;
}

/** When this method is called, the writer must write the scene.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeScene(const COLLADAFW::Scene* scene) {
	m_context.setPrimarySceneId(scene->getInstanceVisualScene()->getInstanciatedObjectId());
	return true;
}

/** When this method is called, the writer must write the entire visual scene.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeVisualScene(const COLLADAFW::VisualScene* visualScene) {
	DAEVirtualSceneConverter c(&m_context);
	std::shared_ptr<Asset3D> s = c.GetNode(visualScene);
	if (s) {
		m_context.getVisualSceneLibrary()[visualScene->getUniqueId()] = s;
	}
	return true;
}

/** 
 * When this method is called, the writer must handle all nodes contained in the library nodes.
 * @return The writer should return true, if writing succeeded, false otherwise.
 **/
bool DAEToAsset3DWriter::writeLibraryNodes(const COLLADAFW::LibraryNodes* colladaLibraryNodes) {
	
	const COLLADAFW::NodePointerArray nodes = colladaLibraryNodes->getNodes();
	int count = nodes.getCount();
	if (count) {
		DAENodeConverter c(&m_context);
		c.ConvertBreadthFirst(&nodes);
	}
	return true;
}

/** When this method is called, the writer must write the geometry.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeGeometry(const COLLADAFW::Geometry* geometry) {

	switch (geometry->getType()) {
		case COLLADAFW::Geometry::GEO_TYPE_MESH: {
			DAEMeshConverter c( &m_context);
			std::shared_ptr<DAEMeshBuilder> m = c.GetNode((COLLADAFW::Mesh*)geometry);
			if (m) {
				m_context.getGeometryLibrary()[geometry->getUniqueId()] = m;
			}
			break;
		}
		default: {
			return false;
		}
	}
	return true;
}

/** When this method is called, the writer must write the material.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeMaterial(const COLLADAFW::Material* colladaMaterial) {
#ifdef _IMPORT_MATERIAL
	/// Collada material is "just" a binding to effect
	m_context.getMaterialUIdToEffectIndex()[colladaMaterial->getUniqueId()] = colladaMaterial->getInstantiatedEffect();
	m_context.getMaterialOriginalIdToEffectIndex()[colladaMaterial->getOriginalId()] = colladaMaterial->getInstantiatedEffect();
#endif
	return true;
}

/** When this method is called, the writer must write the effect.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeEffect(const COLLADAFW::Effect* colladaEffect) {
#ifdef _IMPORT_MATERIAL
	DAEEffectConverter c(&m_context);
	std::shared_ptr<DAEMaterialBuilder> material = c.GetNode(colladaEffect);
	if (material) {
		m_context.getEffectLibrary()[colladaEffect->getUniqueId()] = material;
	}
#endif
	return true;
}

/** When this method is called, the writer must write the camera.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeCamera(const COLLADAFW::Camera* colladaCamera) {
#ifdef _IMPORT_CAMERA
	DAECameraConverter c(&m_context);
	std::shared_ptr<DAECameraBuilder> b = c.GetNode(colladaCamera);
	if (b) {
		m_context.getCameraLibrary()[colladaCamera->getUniqueId()] = b;
	}
#endif
	return true;
}

/** When this method is called, the writer must write the image.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeImage(const COLLADAFW::Image* colladaImage) {
#ifdef _IMPORT_MATERIAL
	DAEImageConverter c(&m_context);
	std::shared_ptr<DAETextureBuilder> texture = c.GetNode(colladaImage);
	if (texture) {
		m_context.getImageLibrary()[colladaImage->getUniqueId()] = texture;
	}
#endif
	return true;
}

/** When this method is called, the writer must write the light.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeLight(const COLLADAFW::Light* light) {
	return true;
}

/** When this method is called, the writer must write the Animation.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeAnimation(const COLLADAFW::Animation* animation) {
	return true;
}

/** When this method is called, the writer must write the AnimationList.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeAnimationList(const COLLADAFW::AnimationList* animationList) {
	return true;
}

/** When this method is called, the writer must write the AnimationClip.
@return The writer should return true, of writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeAnimationClip(const COLLADAFW::AnimationClip* animationClip) {
	return true;
}

/** When this method is called, the writer must write the skin controller data.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeSkinControllerData(const COLLADAFW::SkinControllerData* skinControllerData) {
	/// nothing to do so far
	return true;
}

/** When this method is called, the writer must write the controller.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeController(const COLLADAFW::Controller* controller) {

	/// just index the skin geometry to keep the geometry part of the export even without controller support
	const COLLADAFW::UniqueId& src = controller->getSource();
	m_context.getControllerToSkinIndex()[controller->getUniqueId()] = src;

	return true;
}

/** When this method is called, the writer must write the formulas. All the formulas of the entire
COLLADA file are contained in @a formulas.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeFormulas(const COLLADAFW::Formulas* formulas) {
	/// nothing to do so far
	return true;
}

/** When this method is called, the writer must write the kinematics scene.
@return The writer should return true, if writing succeeded, false otherwise.*/
bool DAEToAsset3DWriter::writeKinematicsScene(const COLLADAFW::KinematicsScene* kinematicsScene) {
	/// nothing to do so far
	return true;
}
