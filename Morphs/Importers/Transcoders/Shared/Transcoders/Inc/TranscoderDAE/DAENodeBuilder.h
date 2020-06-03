/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <Asset3D/SceneNode.h>
#include <COLLADAFWNode.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAENodeBuilder;

		/// map used to keep trace of the path to reach the builder when build.
		typedef std::vector<DAENodeBuilder*> CircularMap;

		class DAENodeBuilder : public DAEAsset3DBuilder<SceneNode> {

		private:
			DAENodeBuilder * m_parent;
			COLLADAFW::UniqueId m_id;
			COLLADAFW::String m_oid;
			COLLADAFW::Node::NodeType m_type = COLLADAFW::Node::NodeType::NODE;
			std::vector<COLLADAFW::UniqueId> m_instances;
			std::vector<Babylon::Utils::Math::Matrix> m_transforms;
			std::vector<std::shared_ptr<DAENodeBuilder>> m_children;
			std::shared_ptr<Mesh> m_mesh;
			std::shared_ptr<Camera> m_camera;
			std::shared_ptr<Light> m_light;

		public:
			DAENodeBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context), m_parent(nullptr){
			}

			inline std::shared_ptr<SceneNode> Build() {
				return Build(std::make_unique<CircularMap>().get());
			}

			std::shared_ptr<SceneNode> Build(CircularMap* map); 

			std::shared_ptr<Animation::Joint> BuildJoint();

			inline COLLADAFW::Node::NodeType GetType() {
				return m_type;
			}

			inline bool IsJoint() {
				return m_type == COLLADAFW::Node::NodeType::JOINT;
			}

			inline DAENodeBuilder& WithId(COLLADAFW::UniqueId id) {
				m_id = id;
				return *this;
			}

			inline DAENodeBuilder& WithOriginalId(COLLADAFW::String id) {
				m_oid = id;
				return *this;
			}

			DAENodeBuilder& WithInstance(COLLADAFW::UniqueId id);

			inline DAENodeBuilder& WithTransform(Babylon::Utils::Math::Matrix t) {
				m_transforms.push_back(t);
				return *this;
			}

			inline DAENodeBuilder& WithNodeType(COLLADAFW::Node::NodeType t) {
				m_type== t;
				return *this;
			}

			inline DAENodeBuilder& WithChild(std::shared_ptr<DAENodeBuilder> child) {
				m_children.push_back(child);
				child->m_parent = this;
				return *this;
			}

			inline DAENodeBuilder& WithMesh(std::shared_ptr <Mesh> mesh) {
				m_mesh = mesh;
				return *this;
			}

			inline DAENodeBuilder& WithCamera(std::shared_ptr<Camera> cam) {
				m_camera = cam;
				return *this;
			}

			inline DAENodeBuilder& WithLight(std::shared_ptr<Light> light) {
				m_light = light;
				return *this;
			}
		};


	}
}
