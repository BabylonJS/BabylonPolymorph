/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <algorithm>
#include <stack>

#include <Asset3D/Geometry.h>

#include <TranscoderJT/Asset3DBuilder.h>

namespace Babylon
{
    namespace Transcoder
    {
		template<typename TContext>		
		class GeometryBuilder : public Asset3DBuilder<Geometry, TContext> {


		private:
			GeometryTopology m_topo;
			std::vector<uint32_t> m_indices;
			std::vector<uint32_t> m_originalIndices;
			std::vector<Babylon::Utils::Math::Vector3> m_positions;
			std::vector<Babylon::Utils::Math::Vector3> m_normals;
			std::vector<Babylon::Utils::Math::Vector4> m_tangents;
			std::map<int16_t, std::vector<Babylon::Utils::Math::Vector2>> m_uvs;
			std::vector<uint32_t> m_colors;

		public:
			GeometryBuilder(TContext * context) : Asset3DBuilder<Geometry, TContext>(context)
			{
				m_topo = GeometryTopology::kTriangles;
			}

			std::shared_ptr<Geometry> Build(std::shared_ptr<Geometry> existingAsset = nullptr) {
				 
				std::shared_ptr<Geometry> geom = existingAsset ? existingAsset : std::make_shared<Geometry>();

				geom->SetTopology(m_topo);
				if (m_indices.size()) {
					geom->SetIndices(m_indices);
				}

				if (m_positions.size()) {
					geom->SetPositions(m_positions);
				}

				if (m_normals.size()) {
					geom->SetNormals(m_normals);
				}

				if (m_tangents.size()) {
					geom->SetTangents(m_tangents);
				}

				if (m_colors.size()) {
					geom->SetColors(m_colors);
				}
				return geom;
			}

			inline GeometryBuilder& WithTopology(GeometryTopology topo) {
				m_topo = topo;
				return *this;
			}

			inline GeometryBuilder& WithIndices(std::vector<uint32_t>&& indices) {
				m_indices = std::move(indices);
				return *this;
			}

			/// Original indices is used to keep trace of indices used in the original format. This allow us to bind features, such weight to vertices
			inline GeometryBuilder& WithOriginalIndices(std::vector<uint32_t>&& originals) {
				m_originalIndices = std::move(originals);
				return *this;
			}

			inline GeometryBuilder& WithPositions(std::vector<Babylon::Utils::Math::Vector3>&& positions) {
				m_positions = std::move(positions);
				return *this;
			}

			inline GeometryBuilder& WithNormals(std::vector<Babylon::Utils::Math::Vector3>&& normals) {
				m_normals = std::move(normals);
				return *this;
			}

			inline GeometryBuilder& WithTangents(std::vector<Babylon::Utils::Math::Vector4> tangents) {
				m_tangents = std::move(tangents);
				return *this;
			}

			inline GeometryBuilder& WithColors(std::vector<uint32_t>&& colors) {
				m_colors = std::move(colors);
				return *this;
			}

			inline GeometryBuilder& WithUvs(std::vector<Babylon::Utils::Math::Vector2>&& uvs, int16_t channel) {
				m_uvs[channel] = std::move(uvs);
				return *this;
			}

			inline bool HasUVs() {
				return m_uvs.size() != 0;
			}

			inline const std::string& GetMaterialName() {
				return m_materialName;
			}

			inline const std::vector<uint32_t>& GetOriginalIndices() {
				return m_originalIndices;
			}

			inline const std::vector<uint32_t>& GetIndices() {
				return m_indices;
			}
		};
	}
}

