#pragma once
/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEMeshBuilder.h>
#include <Asset3D/Animation.h>


namespace Babylon
{
	namespace Transcoder
	{
		class DAESkinControllerBuilder : public IDAEMeshBuilder {

		private:
			std::shared_ptr<DAESkinData> m_data;
			std::shared_ptr<DAEMeshBuilder> m_mesh;
			std::vector<COLLADAFW::UniqueId> m_joints;

		public:
			DAESkinControllerBuilder(DAEToAsset3DWriterContextPtr context) : IDAEMeshBuilder(context) {
			}

			std::shared_ptr<Mesh> Build();

			inline DAESkinControllerBuilder& WithData(std::shared_ptr<DAESkinData> data) {
				m_data = data;
				return *this;
			}

			inline DAESkinControllerBuilder& WithJoint(COLLADAFW::UniqueId joint) {
				m_joints.push_back(joint);
				return *this;
			}

			inline DAESkinControllerBuilder& WithSkin(std::shared_ptr<DAEMeshBuilder> skin) {
				m_mesh = skin;
				return *this;
			}

			const std::vector<std::shared_ptr<DAEGeometryBuilder>> GetGeometries(std::function<bool(const const std::shared_ptr<DAEGeometryBuilder>&)> predicate = nullptr) {
				return m_mesh->GetGeometries(predicate);
			}

		};
	}
}
