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
#include <TranscoderJT/MaterialBuilder.h>

namespace Babylon
{
    namespace Transcoder
    {
#ifndef UV_CHANNEL_NONE
#define UV_CHANNEL_NONE -1
#endif
#ifndef UV_CHANNEL_ZERO
#define UV_CHANNEL_ZERO 0
#endif
#ifndef UV_CHANNEL_ONE
#define UV_CHANNEL_ONE  1
#endif

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


			int16_t m_uvChannel0 = UV_CHANNEL_NONE;
			int16_t m_uvChannel1 = UV_CHANNEL_NONE;
			std::shared_ptr<MaterialBuilder<TContext>> m_materialBuilder;


		public:
			GeometryBuilder(TContext * context) : Asset3DBuilder<Geometry, TContext>(context)
			{
				m_topo = GeometryTopology::kTriangles;
			}

			std::shared_ptr<Geometry> Build(std::shared_ptr<Geometry> existingAsset = nullptr) {
				 
				std::shared_ptr<Geometry> geom = existingAsset;
				if (!geom) {
					std::shared_ptr<MaterialDescriptor> desc = m_materialBuilder ? m_materialBuilder->Build() : nullptr;
					geom = std::make_shared<Geometry>(desc);
				}

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

				if (m_uvChannel0 != UV_CHANNEL_NONE && m_uvs.find(m_uvChannel0) != m_uvs.end()) {
					geom->SetUv0s(m_uvs[m_uvChannel0]);
				}
				if (m_uvChannel1 != UV_CHANNEL_NONE && m_uvs.find(m_uvChannel1) != m_uvs.end()) {
					geom->SetUv1s(m_uvs[m_uvChannel1]);
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

			inline const std::shared_ptr<MaterialBuilder<TContext>> GetMaterial() {
				return m_materialBuilder;
			}

			inline const std::vector<uint32_t>& GetOriginalIndices() {
				return m_originalIndices;
			}

			inline const std::vector<uint32_t>& GetIndices() {
				return m_indices;
			}

     		inline GeometryBuilder& WithMaterial(std::shared_ptr<MaterialBuilder<TContext>> material) {
				m_materialBuilder = material;
				return *this;
			}

			inline GeometryBuilder& WithChannelO(int16_t channel) {
				m_uvChannel0 = channel;
				return *this;
			}

			inline GeometryBuilder& WithChannel1(int16_t channel) {
				m_uvChannel1 = channel;
				return *this;
			}



		};
	}
}

