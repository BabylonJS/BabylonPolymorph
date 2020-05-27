/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEConverter.h>

#include <TranscoderDAE/DAEMeshBuilder.h>
#include <Asset3D/Mesh.h>
#include <COLLADAFWGeometry.h>
#include <COLLADAFWMesh.h>

#include <Asset3D/SceneNode.h>
#include <COLLADAFWScene.h>
#include <COLLADAFWNode.h>

#include <Asset3D/Camera.h>
#include <COLLADAFWCamera.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAEMeshConverter : public DAEAbstractConverter<COLLADAFW::Mesh, DAEMeshBuilder> {
		public:
			DAEMeshConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAEMeshBuilder> Convert(const COLLADAFW::Mesh* from);
		};


		class DAECameraConverter : public DAEAbstractConverter<COLLADAFW::Camera, DAECameraBuilder> {
		public:
			DAECameraConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAECameraBuilder> Convert(const COLLADAFW::Camera* from);
		};

		class DAENodeConverter : public DAEAbstractConverter<COLLADAFW::Node, SceneNode> {
		public:
			DAENodeConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<SceneNode> Convert(const COLLADAFW::Node* from);
			std::shared_ptr<SceneNode> Convert(const COLLADAFW::Node* colladaNode, std::shared_ptr<SceneNode> node);
			std::shared_ptr<SceneNode> ConvertBreadthFirst(const COLLADAFW::NodePointerArray* nodes, std::shared_ptr<SceneNode> node = nullptr);
		};

		class DAEVirtualSceneConverter : public DAEAbstractConverter<COLLADAFW::VisualScene, Asset3D> {
		public:
			DAEVirtualSceneConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<Asset3D> Convert(const COLLADAFW::VisualScene* from);
		};
	}
}
#pragma once
