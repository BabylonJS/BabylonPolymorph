/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAEFXConverter.h>

#include <COLLADAFWEffect.h>
#include <COLLADAFWEffectCommon.h>

using namespace Babylon::Transcoder;

namespace {

	void packColladaColor(COLLADAFW::Color color, float* packArray) {
		packArray[0] = (float)color.getRed();
		packArray[1] = (float)color.getGreen();
		packArray[2] = (float)color.getBlue();
		packArray[3] = (float)color.getAlpha();
	}

	void UpdateLayerTextureParams(	const std::shared_ptr<MaterialDescriptor::LayerInfo>& layer, 
									const std::shared_ptr<TextureDescriptor>& texture, 
									const std::shared_ptr<MaterialLayer::TextureSampler>& sampler, 
									const COLLADAFW::Texture & colladaTexture)
	{
		layer->Texture = texture;
		layer->Sampler = *sampler;
		//layer->UVSetIndex = static_cast<uint32_t>(gltfTextureInfo.texCoord);

		//if (gltfTextureInfo.HasExtension<glTF::KHR::TextureInfos::TextureTransform>())
		//{
		//	const auto& gltfTextureTransform = gltfTextureInfo.GetExtension<glTF::KHR::TextureInfos::TextureTransform>();

		//	layer->TextureTransform = Babylon::Utils::glTF::GetTextureTransformMatrix(gltfTextureTransform);

		//	if (gltfTextureTransform.texCoord)
		//	{
		//		layer->UVSetIndex = static_cast<uint32_t>(gltfTextureTransform.texCoord.Get());
		//	}
		//}
	}
}

std::shared_ptr<TextureDescriptor> DAEEffectConverter::fromColladaTexture(const COLLADAFW::EffectCommon* effectCommon, COLLADAFW::SamplerID samplerId) {
	const COLLADAFW::SamplerPointerArray& samplers = effectCommon->getSamplerPointerArray();
	COLLADAFW::Sampler* colladaSampler = (COLLADAFW::Sampler*)samplers[samplerId];
	return getContext()->getImageLibrary()[colladaSampler->getSourceImage()];
}

std::shared_ptr<TextureDescriptor> DAEEffectConverter::fromColladaTexture(const COLLADAFW::EffectCommon* effectCommon, COLLADAFW::Texture colladaTexture) {
	return fromColladaTexture(effectCommon, colladaTexture.getSamplerId());
}


std::shared_ptr<MaterialDescriptor> DAEEffectConverter::Convert(const COLLADAFW::Effect * effect) {
	std::shared_ptr<MaterialDescriptor> material = nullptr; 
	const COLLADAFW::CommonEffectPointerArray & commonEffects = effect->getCommonEffects();

	if (commonEffects.getCount() > 0) {

		material = std::make_shared<MaterialDescriptor>();
		COLLADAFW::UniqueId effectId = effect->getUniqueId();
		std::map<std::string, std::shared_ptr<TextureDescriptor>> textureMapping;

		material->SetName(effect->getName().empty()? effect->getOriginalId() : effect->getName());

		/// One effect makes one template material, it really isn't possible to process more than one of these
		const COLLADAFW::EffectCommon* effectCommon = commonEffects[0];
		
		//switch (effectCommon->getShaderType()) {
		//case COLLADAFW::EffectCommon::SHADER_BLINN:
		//	material->technique = GLTF::MaterialCommon::BLINN;
		//	break;
		//case COLLADAFW::EffectCommon::SHADER_CONSTANT:
		//	material->technique = GLTF::MaterialCommon::CONSTANT;
		//	break;
		//case COLLADAFW::EffectCommon::SHADER_PHONG:
		//	material->technique = GLTF::MaterialCommon::PHONG;
		//	break;
		//case COLLADAFW::EffectCommon::SHADER_LAMBERT:
		//	material->technique = GLTF::MaterialCommon::LAMBERT;
		//	break;
		//}

		//bool lockAmbientDiffuse = _extrasHandler->lockAmbientDiffuse.find(effect->getUniqueId()) != _extrasHandler->lockAmbientDiffuse.end();

		//if (!lockAmbientDiffuse) {
		//	COLLADAFW::ColorOrTexture ambient = effectCommon->getAmbient();
		//	if (ambient.isTexture()) {
		//		material->values->ambientTexture = fromColladaTexture(effectCommon, ambient.getTexture());
		//		textureMapping[ambient.getTexture().getTexcoord()] = material->values->ambientTexture;
		//	}
		//	else if (ambient.isColor()) {
		//		material->values->ambient = new float[4];
		//		packColladaColor(ambient.getColor(), material->values->ambient);
		//	}
		//}

		//COLLADAFW::ColorOrTexture diffuse = effectCommon->getDiffuse();
		//if (diffuse.isTexture()) {
		//	std::shared_ptr<MaterialLayer::TextureSampler> sampler;
		//	auto layer = material->AddLayer(LayerType::kDiffuse);
		//	auto texture = fromColladaTexture(effectCommon, diffuse.getTexture());
		//	textureMapping[diffuse.getTexture().getTexcoord()] = texture;

		//	UpdateLayerTextureParams(layer, texture, sampler, mat.diffuseTexture);

		//	//if (lockAmbientDiffuse) {
		//	//	material->values->ambientTexture = material->values->diffuseTexture;
		//	//}
		//}
		//else if (diffuse.isColor()) {
		//	material->values->diffuse = new float[4];
		//	packColladaColor(diffuse.getColor(), material->values->diffuse);
		//	if (lockAmbientDiffuse) {
		//		material->values->ambient = material->values->diffuse;
		//	}
		//}

		//COLLADAFW::ColorOrTexture emission = effectCommon->getEmission();
		//if (emission.isTexture()) {
		//	material->values->emissionTexture = fromColladaTexture(effectCommon, emission.getTexture());
		//	textureMapping[emission.getTexture().getTexcoord()] = material->values->emissionTexture;
		//}
		//else if (emission.isColor()) {
		//	material->values->emission = new float[4];
		//	packColladaColor(emission.getColor(), material->values->emission);
		//}

		//COLLADAFW::ColorOrTexture specular = effectCommon->getSpecular();
		//if (specular.isTexture()) {
		//	material->values->specularTexture = fromColladaTexture(effectCommon, specular.getTexture());
		//	textureMapping[specular.getTexture().getTexcoord()] = material->values->specularTexture;
		//}
		//else if (specular.isColor()) {
		//	material->values->specular = new float[4];
		//	packColladaColor(specular.getColor(), material->values->specular);
		//}

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

	return material;
}
