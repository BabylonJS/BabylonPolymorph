/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <algorithm>
#include <stack>

#include <Asset3D/Geometry.h>

#include <TranscoderJT/GeometryBuilder.h>
#include <TranscoderJT/MaterialBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
		template<typename TContext>
		class GeometryInstanceBuilder : public Asset3DInstanceBuilder<Geometry, TContext> {

		private:
			int16_t m_uvChannel0 = UV_CHANNEL_NONE;
			int16_t m_uvChannel1 = UV_CHANNEL_NONE;
			std::string m_materialName;
			std::shared_ptr<MaterialBuilder<TContext>> m_materialBuilder;
			std::vector<uint32_t> m_jointIndices;
			std::vector<float> m_jointWeights;

		public:
			GeometryInstanceBuilder(std::shared_ptr<GeometryBuilder<TContext>>) : Asset3DInstanceBuilder<Geometry, TContext>(model) {
			}

			inline GeometryInstanceBuilder& WithMaterialName(std::string materialName) {
				m_materialName = materialName;
				return *this;
			}

			inline GeometryInstanceBuilder& WithMaterial(std::shared_ptr<MaterialBuilder<TContext>> material) {
				m_materialBuilder = material;
				return *this;
			}

			inline GeometryInstanceBuilder& WithJoints(std::vector<uint32_t>&& jointIndices, std::vector<float>&& jointWeights) {
				m_jointIndices = std::move(jointIndices);
				m_jointWeights = std::move(jointWeights);
				return *this;
			}

			inline GeometryInstanceBuilder& WithChannelO(int16_t channel) {
				m_uvChannel0 = channel;
				return *this;
			}

			inline GeometryInstanceBuilder& WithChannel1(int16_t channel) {
				m_uvChannel1 = channel;
				return *this;
			}

			inline const std::string& GetMaterialName() {
				return m_materialName;
			}

			virtual std::shared_ptr<Geometry> Build(std::shared_ptr<Geometry> existingAsset = nullptr) {
				std::shared_ptr<Geometry> geom = existingAsset;
				if (!geom) {
					std::shared_ptr<MaterialDescriptor> desc = m_materialBuilder? m_materialBuilder->Build() : nullptr;
					geom = std::make_shared<Geometry>(desc);
				}
				geom = GetModel()->Build(geom);
				if (m_uvChannel0 != UV_CHANNEL_NONE && m_uvs.find(m_uvChannel0) != m_uvs.end()) {
					geom->SetUv0s(m_uvs[m_uvChannel0]);
				}
				if (m_uvChannel1 != UV_CHANNEL_NONE && m_uvs.find(m_uvChannel1) != m_uvs.end()) {
					geom->SetUv1s(m_uvs[m_uvChannel1]);
				}
				if (m_jointIndices.size()) {
					/// build a unique vector, sorted ascendant, of POSITION indices, which may reffer to weight
					std::vector<uint32_t> weights;
					weights.reserve(m_jointWeights.size());
					for (auto w : m_jointWeights) {
						/// save the weight as uint32_t normalized 
						weights.push_back(normalized_pack<uint16_t>(w));
					}
					geom->SetJoints(std::vector<uint32_t>(m_jointIndices), std::move(weights));
				}
				return geom;
			}
		};
	}
}

