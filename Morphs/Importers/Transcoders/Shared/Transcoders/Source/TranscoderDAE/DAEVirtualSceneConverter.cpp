/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/DAESceneConverter.h>

#include "COLLADAFWVisualScene.h"

Babylon::Utils::Math::Matrix toBabylonMatrix(COLLADABU::Math::Matrix4 colladaMatrix) {

	const COLLADABU::Math::Real* m[4];
	m[0] = colladaMatrix[0];
	m[1] = colladaMatrix[1];
	m[2] = colladaMatrix[2];
	m[3] = colladaMatrix[3];

	/** 
	 * The Babylon math library packs matrices in a row major order.
	 * According to specification "Matrices in COLLADA are column matrices in the mathematical sense".
	 * we then need to transpose.
	 */

	Babylon::Utils::Math::Matrix tmp(	m[0][0], m[1][0], m[2][0], m[3][0],
										m[0][1], m[1][1], m[2][1], m[3][1],
										m[0][2], m[1][2], m[2][2], m[3][2],
										m[0][3], m[1][3], m[2][3], m[3][3]);
	
	return tmp;
}

using namespace Babylon::Transcoder;

std::shared_ptr<SceneNode> DAEVirtualSceneConverter::Convert(const COLLADAFW::VisualScene* colladaScene) {
	std::shared_ptr<SceneNode> scene = std::make_shared<SceneNode>();
	scene->SetName(colladaScene->getName());

	/// loop over nodes
	COLLADAFW::NodePointerArray colladaRootNodes = colladaScene->getRootNodes();
	for (int i = 0; i != colladaRootNodes.getCount(); i++) {
		COLLADAFW::Node* colladaNode = colladaRootNodes[i];
		std::shared_ptr<SceneNode> n = scene->CreateChildNode();
		n->SetName(colladaNode->getName());
		if (n) {

			/// looking for transform - note we do ONLY support one transformation per node so far
			COLLADABU::Math::Matrix4 colladaTransform = colladaNode->getTransformationMatrix();
			n->SetTransform(toBabylonMatrix(colladaTransform));

			/// looking for geometry instance - note we do ONLY support one geometry per node so far
			COLLADAFW::InstanceGeometryPointerArray & colladaGeometries = colladaNode->getInstanceGeometries();
			for (int j = 0; j != colladaGeometries.getCount(); j++) {

				COLLADAFW::InstanceGeometry* colladaInstance = colladaGeometries[j];
				const COLLADAFW::UniqueId & colladaUid  = colladaInstance->getInstanciatedObjectId();
				std::shared_ptr<Mesh> m = m_context->getGeometryLibrary()[colladaUid];
				if (m) {
					n->SetMesh(m);
				}
			}

			/// looking for controller instance - Note the controller instance use contrioller, then skin whic are binded to Mesh...
			COLLADAFW::InstanceControllerPointerArray& colladaControllers = colladaNode->getInstanceControllers();
			for (int j = 0; j != colladaControllers.getCount(); j++) {

				COLLADAFW::InstanceController* colladaInstance = colladaControllers[j];
				const COLLADAFW::UniqueId& colladaUid = colladaInstance->getInstanciatedObjectId();
				COLLADAFW::UniqueId meshUid = m_context->getSkinLibrary()[colladaUid];
				std::shared_ptr<Mesh> m = m_context->getGeometryLibrary()[meshUid];
				if (m) {
					n->SetMesh(m);
				}
			}

		}
	}
	return scene;
}
