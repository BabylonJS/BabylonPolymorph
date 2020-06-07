/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <algorithm>
#include <stack>

#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <TranscoderDAE/DAEFXBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
#define UV_CHANNEL_NONE -1
#define UV_CHANNEL_ZERO  0
#define UV_CHANNEL_ONE   1

		class DAEGeometryBuilder : public DAEAsset3DBuilder<Geometry> {

			struct params {
				int16_t uvChannel0 = UV_CHANNEL_NONE;
				int16_t uvChannel1 = UV_CHANNEL_NONE;
				std::shared_ptr<DAEMaterialBuilder> materialBuilder;
				std::vector<uint32_t> jointIndices;
				std::vector<float> jointWeights;
			};

		private:
			/// TODO : Improve Save/Restore mechanism
			params m_parameters;
			std::stack<params> m_saved;

			GeometryTopology m_topo;
			std::string m_materialName;
			std::vector<uint32_t> m_indices;
			std::vector<uint32_t> m_originalIndices;
			std::vector<Babylon::Utils::Math::Vector3> m_positions;
			std::vector<Babylon::Utils::Math::Vector3> m_normals;
			std::vector<Babylon::Utils::Math::Vector4> m_tangents;
			std::map<int16_t, std::vector<Babylon::Utils::Math::Vector2>> m_uvs;
			std::vector<uint32_t> m_colors;

		public:
			DAEGeometryBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context)
			{
				m_topo = GeometryTopology::kTriangles;
				Save();
			}

			std::shared_ptr<Geometry> Build() {

				std::shared_ptr<MaterialDescriptor> desc = m_parameters.materialBuilder ? m_parameters.materialBuilder->Build() : nullptr;
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

				if (m_parameters.uvChannel0 != UV_CHANNEL_NONE && m_uvs.find(m_parameters.uvChannel0) != m_uvs.end()) {
					geom->SetUv0s(m_uvs[m_parameters.uvChannel0]);
				}

				if (m_parameters.uvChannel1 != UV_CHANNEL_NONE && m_uvs.find(m_parameters.uvChannel1) != m_uvs.end()) {
					geom->SetUv1s(m_uvs[m_parameters.uvChannel1]);
				}

				if (m_colors.size()) {
					geom->SetColors(m_colors);
				}

				if (m_parameters.jointIndices.size()) {
					/// build a unique vector, sorted ascendant, of POSITION indices, which may reffer to weight
					std::vector<uint32_t> weights;
					weights.reserve(m_parameters.jointWeights.size());
					for (auto w : m_parameters.jointWeights) {
						/// save the weight as uint32_t normalized 
						weights.push_back(normalized_pack<uint16_t>(w));
					}
					geom->SetJoints(std::vector<uint32_t>(m_parameters.jointIndices), std::move(weights));
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
				m_parameters.materialBuilder = material;
				return *this;
			}

			/// Original indices is used to keep trace of indices used in the original format. This allow us to bind features, such weight to vertices
			inline DAEGeometryBuilder& WithIndices(std::vector<uint32_t>&& indices, std::vector<uint32_t>&& originals) {
				m_indices = std::move(indices);
				m_originalIndices = std::move(originals) ;
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
			
			inline DAEGeometryBuilder& WithJoints(std::vector<uint32_t>&& jointIndices, std::vector<float>&& jointWeights) {
				m_parameters.jointIndices = std::move(jointIndices);
				m_parameters.jointWeights = std::move(jointWeights);
				return *this;
			}

			inline DAEGeometryBuilder& WithUvs(std::vector<Babylon::Utils::Math::Vector2>&& uvs, int16_t channel) {
				m_uvs[channel] = std::move(uvs);
				return *this;
			}

			inline bool HasUVs() {
				return m_uvs.size() != 0;
			}

			inline DAEGeometryBuilder& WithChannelO(int16_t channel) {
				m_parameters.uvChannel0 = channel;
				return *this;
			}

			inline DAEGeometryBuilder& WithChannel1(int16_t channel) {
				m_parameters.uvChannel1 = channel;
				return *this;
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

			inline DAEGeometryBuilder& Save() {
				m_saved.push(m_parameters);
				return *this;
			}

			inline DAEGeometryBuilder& Restore() {
				m_parameters = m_saved.top();
				m_saved.pop();
				return *this;
			}
		};
	}
}
