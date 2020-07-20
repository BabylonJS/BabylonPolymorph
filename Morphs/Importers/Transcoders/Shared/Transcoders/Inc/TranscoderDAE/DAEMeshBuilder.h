/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEGeometryBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
		class IDAEMeshBuilder : public DAEAsset3DBuilder<Mesh> {

		public:
			IDAEMeshBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context)
			{
			}

			virtual std::shared_ptr<Mesh> Build() = 0;

			inline IDAEMeshBuilder& Save() {

				for (auto g : GetGeometries()) {
					g->Save();
				}
				return *this;
			}

			inline IDAEMeshBuilder& Restore() {

				for (auto g : GetGeometries()) {
					g->Restore();
				}
				return *this;
			}

			virtual const std::vector<std::shared_ptr<DAEGeometryBuilder>> GetGeometries(std::function<bool(const const std::shared_ptr<DAEGeometryBuilder>&)> predicate = nullptr) = 0;
		};


		class DAEMeshBuilder : public IDAEMeshBuilder {

		private:
			std::vector<std::shared_ptr<DAEGeometryBuilder>> m_geometries ;

		public:
			DAEMeshBuilder(DAEToAsset3DWriterContextPtr context) : IDAEMeshBuilder(context)
			{
			}

			std::shared_ptr<Mesh> Build() {
				std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
				for (int i = 0; i != m_geometries.size(); i++) {
					mesh->AddGeometry(std::move(*m_geometries[i]->Build()));
				}
				mesh->SetName(GetName());
				return mesh;
			}

			inline DAEMeshBuilder& WithGeometries(std::vector<std::shared_ptr<DAEGeometryBuilder>>&& geometries) {
				m_geometries = std::move(geometries);
				return *this;
			}

			inline DAEMeshBuilder& WithGeometry(std::shared_ptr<DAEGeometryBuilder> geometry) {
				m_geometries.push_back(geometry);
				return *this;
			}

			const std::vector<std::shared_ptr<DAEGeometryBuilder>> GetGeometries(std::function<bool(const const std::shared_ptr<DAEGeometryBuilder>&)> predicate = nullptr) {
				std::vector<std::shared_ptr<DAEGeometryBuilder>> tmp;
				for (size_t i = 0; i != m_geometries.size(); i++) {
					if (!predicate || predicate(m_geometries[i])) {
						tmp.push_back(m_geometries[i]);
					}
				}
				return tmp;
			}
		};
	}
}
