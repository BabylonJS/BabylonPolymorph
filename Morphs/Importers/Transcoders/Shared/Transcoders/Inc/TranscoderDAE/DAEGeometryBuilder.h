/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <TranscoderDAE/DAEFXBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
#define UV_CHANNEL_NONE -1
#define UV_CHANNEL_ZERO  0
#define UV_CHANNEL_ZERO  1

		class DAEGeometryBuilder : public DAEAsset3DBuilder<Geometry> {

		private:
			int16_t m_uvChannel0;
			int16_t m_uvChannel1;
			std::shared_ptr<DAEMaterialBuilder> m_materialBuilder;

			struct {
				int16_t m_uvChannel0;
				int16_t m_uvChannel1;
				std::shared_ptr<DAEMaterialBuilder> m_materialBuilder;
			} saved;

			GeometryTopology m_topo;
			std::string m_materialName;
			std::vector<uint32_t> m_indices;
			std::vector<Babylon::Utils::Math::Vector3> m_positions;
			std::vector<Babylon::Utils::Math::Vector3> m_normals;
			std::vector<Babylon::Utils::Math::Vector4> m_tangents;
			std::map<int16_t, std::vector<Babylon::Utils::Math::Vector2>> m_uvs;
			std::vector<uint32_t> m_colors;
			std::vector<uint32_t> m_jointIndices;
			std::vector<uint32_t> m_jointWeights;

		public:
			DAEGeometryBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context), 
				m_uvChannel0(UV_CHANNEL_NONE),
				m_uvChannel1(UV_CHANNEL_NONE)
			{
				m_topo = GeometryTopology::kTriangles;
				Save();
			}

			std::shared_ptr<Geometry> Build() {

				std::shared_ptr<MaterialDescriptor> desc = m_materialBuilder ? m_materialBuilder->Build() : nullptr;
				std::shared_ptr<Geometry> geom = std::make_shared<Geometry>(desc);
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
				if (m_uvChannel0 != UV_CHANNEL_NONE && m_uvs.find(m_uvChannel0) != m_uvs.end()) {
					geom->SetUv0s(m_uvs[m_uvChannel0]);
				}
				if (m_uvChannel1 != UV_CHANNEL_NONE && m_uvs.find(m_uvChannel1) != m_uvs.end()) {
					geom->SetUv1s(m_uvs[m_uvChannel1]);
				}
				if (m_colors.size()) {
					geom->SetColors(m_colors);
				}
				if (m_jointIndices.size()) {
					/// doing RInstance explicit copy
					geom->SetJoints(std::vector<uint32_t>(m_jointIndices), std::vector<uint32_t>(m_jointWeights));
				}
				return geom;
			}

			inline DAEGeometryBuilder& WithTopology(GeometryTopology topo) {
				m_topo = topo;
				return *this;
			}

			inline DAEGeometryBuilder& WithMaterialName(std::string materialName) {
				m_materialName = materialName;
				return *this;
			}

			inline DAEGeometryBuilder& WithMaterial(std::shared_ptr<DAEMaterialBuilder> material) {
				m_materialBuilder = material;
				return *this;
			}

			inline DAEGeometryBuilder& WithIndices(std::vector<uint32_t>&& indices) {
				m_indices = std::move(indices);
				return *this;
			}

			inline DAEGeometryBuilder& WithPositions(std::vector<Babylon::Utils::Math::Vector3>&& positions) {
				m_positions = std::move(positions);
				return *this;
			}
			
			inline DAEGeometryBuilder& WithNormals(std::vector<Babylon::Utils::Math::Vector3>&& normals) {
				m_normals = std::move(normals);
				return *this;
			}
			
			inline DAEGeometryBuilder& WithTangents(std::vector<Babylon::Utils::Math::Vector4> tangents) {
				m_tangents = std::move(tangents);
				return *this;
			}
			
			inline DAEGeometryBuilder& WithColors(std::vector<uint32_t>&& colors) {
				m_colors = std::move(colors);
				return *this;
			}
			
			inline DAEGeometryBuilder& WithJoints(std::vector<uint32_t>&& jointIndices, std::vector<uint32_t>&& jointWeights)
			{
				m_jointIndices = std::move(jointIndices);
				m_jointWeights = std::move(jointWeights);
				return *this;
			}

			inline DAEGeometryBuilder& WithUvs(std::vector<Babylon::Utils::Math::Vector2>&& uvs, int16_t channel)
			{
				m_uvs[channel] = std::move(uvs);
				return *this;
			}

			inline DAEGeometryBuilder& WithChannelO(int16_t channel)
			{
				m_uvChannel0 = channel;
				return *this;
			}

			inline DAEGeometryBuilder& WithChannel1(int16_t channel)
			{
				m_uvChannel1 = channel;
				return *this;
			}

			inline const std::string& GetMaterialName() {
				return m_materialName;
			}

			inline DAEGeometryBuilder& Save() {
				saved.m_materialBuilder = m_materialBuilder;
				saved.m_uvChannel0 = m_uvChannel0;
				saved.m_uvChannel1 = m_uvChannel1;
				return *this;
			}

			inline DAEGeometryBuilder& Restore() {
				m_materialBuilder = saved.m_materialBuilder;
				m_uvChannel0 = saved.m_uvChannel0;
				m_uvChannel1 = saved.m_uvChannel1;
				return *this;
			}
		};
	}
}