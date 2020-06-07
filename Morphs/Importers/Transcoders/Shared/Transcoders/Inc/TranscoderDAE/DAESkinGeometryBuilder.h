#pragma once
/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEMeshBuilder.h>
#include <TranscoderDAE/DAEAnimation.h>


namespace Babylon
{
	namespace Transcoder
	{
		class DAESkinGeometryBuilder : public IDAEMeshBuilder {

		private:
			std::shared_ptr<DAESkinController> m_controller;
		public:
			DAESkinGeometryBuilder(DAEToAsset3DWriterContextPtr context, std::shared_ptr<DAESkinController> controller = nullptr) : IDAEMeshBuilder(context),m_controller(controller) {
			}

			std::shared_ptr<Mesh> Build();


			inline DAESkinGeometryBuilder& WithSkinController(std::shared_ptr<DAESkinController> controller) {
				m_controller = controller;
				return *this;
			}

			const std::vector<std::shared_ptr<DAEGeometryBuilder>> GetGeometries(std::function<bool(const const std::shared_ptr<DAEGeometryBuilder>&)> predicate = nullptr) {
				return m_controller->mesh->GetGeometries(predicate);
			}
		};
	}
}
