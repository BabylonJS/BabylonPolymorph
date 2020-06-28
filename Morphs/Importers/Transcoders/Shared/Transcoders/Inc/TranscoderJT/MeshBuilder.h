/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Asset3D/Mesh.h>
#include <TranscoderJT/GeometryBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{

		template<typename TContext>
		class MeshBuilder : public Asset3DBuilder<Mesh,TContext> {

			typedef std::vector<std::shared_ptr<GeometryBuilder<TContext>>> Geometries;

		private:
			Geometries m_geometries;

		public:
			MeshBuilder(TContext * context) : Asset3DBuilder(context)
			{
			}

			std::shared_ptr<Mesh> Build(std::shared_ptr<Mesh> existingAsset = nullptr) {
				std::shared_ptr<Mesh> mesh = existingAsset ? existingAsset : std::make_shared<Mesh>();
				for (int i = 0; i != m_geometries.size(); i++) {
					mesh->AddGeometry(std::move(*m_geometries[i]->Build()));
				}
				mesh->SetName(GetName());
				return mesh;
			}

			inline MeshBuilder& WithGeometries(std::vector<std::shared_ptr<GeometryBuilder<TContext>>>&& geometries) {
				m_geometries = std::move(geometries);
				return *this;
			}

			inline MeshBuilder& WithGeometry(std::shared_ptr<GeometryBuilder<TContext>> geometry) {
				if (geometry) {
					m_geometries.push_back(geometry);
				}
				return *this;
			}

			const Geometries GetGeometries(std::function<bool(const Geometries&)> predicate = nullptr) {
				std::vector<std::shared_ptr<GeometryBuilder<TContext>>> tmp;
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
