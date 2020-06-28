/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Framework/Enums.h>

#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/MaterialLayer.h>

#include <TranscoderJT/Asset3DBuilder.h>

namespace Babylon
{

#define WithDiffuse(l) WithLayer(LayerType::kDiffuse,(l))
#define WithEmissive(l) WithLayer(LayerType::kEmissive,(l))
#define WithSpecular(l) WithLayer(LayerType::kSpecularGlossiness,(l))

	namespace Transcoder
	{
		using LayerType = Babylon::Framework::TextureMaterialLayer;
		using LayerInfo = Babylon::Transcoder::MaterialLayer;

		template<typename TContext>
		class MaterialBuilder : public Asset3DBuilderWithCache<MaterialDescriptor,TContext> {

		private:
			/// default material 
			std::array<std::shared_ptr<LayerInfo>, static_cast<size_t>(LayerType::kNumLayers)> m_layers;

		public:
			MaterialBuilder(TContext context) : Asset3DBuilderWithCache<MaterialDescriptor, TContext>(context) {
			}

			std::shared_ptr<MaterialDescriptor> BuildCache(std::shared_ptr<MaterialDescriptor> existingAsset = nullptr) {
				std::shared_ptr<MaterialDescriptor> desc = existingAsset? existingAsset: std::make_shared<MaterialDescriptor>(false);
				for (int i = 0; i != m_layers.size(); i++) {
					if (m_layers[i]) {
						/// simply make a copy
						*(desc->AddLayer((LayerType)i)) = *m_layers[i];
					}
				}
				return desc;
			}

			inline MaterialBuilder& WithLayer(LayerType layerType, std::shared_ptr<LayerInfo> layer) {
				if (layer) {
					m_layers[static_cast<size_t>(layerType)] = layer;
				}
				return *this;
			}
		};
	}
}
