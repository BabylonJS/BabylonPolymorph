/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAEFXConverter.h>
#include <TranscoderDAE/DAETextureBuilder.h>
#include <TranscoderDAE/DAEFXBuilder.h>

#include <CoreUtils/Math/SimpleMath.h>

#include <COLLADAFWEffect.h>
#include <COLLADAFWEffectCommon.h>


using namespace Babylon::Transcoder;

#define _ToColor(c)  Babylon::Utils::Math::Color(c.getRed(),c.getGreen(), c.getBlue(),c.getAlpha())

std::shared_ptr<MaterialDescriptor::LayerInfo> DAEEffectConverter::SetLayer(const COLLADAFW::EffectCommon* effectCommon, const COLLADAFW::ColorOrTexture* src, std::shared_ptr<DAEMaterialBuilder> material) {

	std::shared_ptr<MaterialDescriptor::LayerInfo> layer = nullptr;

	if (src->isTexture()) {
		layer = std::make_shared<LayerInfo>();
		COLLADAFW::Texture colladaTexture = src->getTexture();
		const COLLADAFW::SamplerPointerArray& colladaSamplers = effectCommon->getSamplerPointerArray();
		COLLADAFW::Sampler* colladaSampler = (COLLADAFW::Sampler*)colladaSamplers[colladaTexture.getSamplerId()];
		std::shared_ptr<DAETextureBuilder> tb = getContext()->getImageLibrary()[colladaSampler->getSourceImage()];
		if (tb) {
			layer->Texture = tb->Build();
			std::shared_ptr<MaterialLayer::TextureSampler> sampler = std::make_shared<MaterialLayer::TextureSampler>();
			layer->Sampler = *sampler;
		}
	} else if (src->isColor()) {
		layer = std::make_shared<LayerInfo>();
		const COLLADAFW::Color& color = src->getColor();
		layer->SetColor(_ToColor(color));
	}
	return layer;
}


std::shared_ptr<DAEMaterialBuilder> DAEEffectConverter::Convert(const COLLADAFW::Effect * effect) {
	
	std::shared_ptr<DAEMaterialBuilder> materialBuilderPtr = std::make_shared<DAEMaterialBuilder>(getContext());
	materialBuilderPtr->WithName(effect->getName().empty() ? effect->getOriginalId() : effect->getName());

	/** 
	 * The <profile_COMMON> elements encapsulate all the values and declarations for a platform-independent 
	 * fixed-function shader. All platforms are required to support <profile_COMMON>. <profile_COMMON>
	 * effects are designed to be used as the reliable fallback when no other profile is recognized by the
	 * current effects runtime. 
	 * ONE effect makes ONE material, it really isn't possible to process more than one of these
	 */
	const COLLADAFW::CommonEffectPointerArray & commonEffects = effect->getCommonEffects();
	if (commonEffects.getCount() > 0) {

		/// non sens to get more than one common effect
		const COLLADAFW::EffectCommon* effectCommon = commonEffects[0];

		materialBuilderPtr->	
			 WithEmissive(SetLayer(effectCommon, &effectCommon->getEmission(), materialBuilderPtr))
			.WithDiffuse(SetLayer(effectCommon, &effectCommon->getDiffuse(), materialBuilderPtr))
			.WithSpecular(SetLayer(effectCommon, &effectCommon->getSpecular(), materialBuilderPtr));



		//COLLADAFW::ColorOrTexture transparent = effectCommon->getTransparent();
		//if (transparent.isTexture()) {
		//	std::cerr << "WARNING: Effect " << effect->getOriginalId() <<
		//		" contains a transparent texture that will be omitted from" <<
		//		" the converted model." << std::endl;
		//}
		//else if (transparent.isColor()) {
		//	float* diffuse = material->values->diffuse;
		//	if (diffuse == NULL) {
		//		diffuse = new float[4];
		//		diffuse[0] = 1.0;
		//		diffuse[1] = 1.0;
		//		diffuse[2] = 1.0;
		//		diffuse[3] = 1.0;
		//		material->values->diffuse = diffuse;
		//	}
		//	float* transparentValues = new float[4];
		//	packColladaColor(transparent.getColor(), transparentValues);
		//	auto opaqueMode = effectCommon->getOpaqueMode();
		//	bool alwaysUseAlpha = (opaqueMode == COLLADAFW::EffectCommon::OpaqueMode::A_ONE) ||
		//		(opaqueMode == COLLADAFW::EffectCommon::OpaqueMode::A_ZERO);
		//	bool oneMinus = (opaqueMode == COLLADAFW::EffectCommon::OpaqueMode::RGB_ZERO) ||
		//		(opaqueMode == COLLADAFW::EffectCommon::OpaqueMode::A_ZERO);
		//	for (size_t i = 0; i < 4; i++) {
		//		auto transparentValue = transparentValues[alwaysUseAlpha ? 3 : i];

		//		if (!alwaysUseAlpha && i == 3) { //RGB_ZERO or RGB_ONE - use luminance for alpha
		//			transparentValue = (transparentValues[0] * 0.212671) +
		//				(transparentValues[1] * 0.715160) +
		//				(transparentValues[2] * 0.072169);
		//		}

		//		diffuse[i] *= (oneMinus ? (1.0 - transparentValue) : transparentValue);
		//	}
		//	if (diffuse[3] < 1.0) {
		//		material->transparent = true;
		//	}
		//	delete transparentValues;
		//}

		//COLLADAFW::FloatOrParam shininess = effectCommon->getShininess();
		//if (shininess.getType() == COLLADAFW::FloatOrParam::FLOAT) {
		//	float shininessValue = shininess.getFloatValue();
		//	if (shininessValue >= 0) {
		//		material->values->shininess = new float[1];
		//		material->values->shininess[0] = shininessValue;
		//	}
		//}

		//COLLADAFW::FloatOrParam transparency = effectCommon->getTransparency();
		//if (transparency.getType() == COLLADAFW::FloatOrParam::FLOAT) {
		//	float transparencyValue = transparency.getFloatValue();
		//	if (_options->invertTransparency) {
		//		transparencyValue = 1.0 - transparencyValue;
		//	}
		//	if (transparencyValue < 1.0) {
		//		material->values->transparency = new float[1];
		//		material->values->transparency[0] = transparencyValue;
		//		material->transparent = true;
		//	}
		//}

		//auto bumpTextureIt = _extrasHandler->bumpTextures.find(effect->getUniqueId());
		//if (bumpTextureIt != _extrasHandler->bumpTextures.end()) {
		//	material->values->bumpTexture = fromColladaTexture(effectCommon, (*bumpTextureIt).second->samplerId);
		//}

		//bool doubleSided = _extrasHandler->doubleSided.find(effect->getUniqueId()) != _extrasHandler->doubleSided.end();
		//if (doubleSided) {
		//	material->doubleSided = true;
		//}

		//_effectTextureMapping[effectId] = textureMapping;
		//_effectInstances[effectId] = material;
	}

	return materialBuilderPtr;
}
