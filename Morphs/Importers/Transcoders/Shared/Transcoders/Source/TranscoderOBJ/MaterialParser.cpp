/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <Framework/GeometryUtils.h>

#include <TranscoderOBJ/MaterialParser.h>
#include <Asset3D/MaterialDescriptor.h>

namespace
{
    using namespace Spectre::Transcoder;

    LineTypeTranslator<MtlLineType> MtlLineTypeTranslator()
    {
        auto sharedMap = std::map<std::string, MtlLineType>();
        sharedMap["newmtl"] = MtlLineType::newmtl;

        sharedMap["map_Kd"] = MtlLineType::TextureDiffuse;
        sharedMap["map_Ks"] = MtlLineType::TextureSpecular;
        sharedMap["map_d"] = MtlLineType::TextureDetail;
        sharedMap["map_Bump"] = MtlLineType::TextureNormal;
        sharedMap["bump"] = MtlLineType::TextureNormal;
        sharedMap["map_Ke"] = MtlLineType::TextureEmissive;

        sharedMap["Kd"] = MtlLineType::ColorDiffuse;
        sharedMap["d"] = MtlLineType::Opacity;
        sharedMap["Ks"] = MtlLineType::ColorSpecular;
        sharedMap["Ns"] = MtlLineType::SpecularExponent;

        return LineTypeTranslator<MtlLineType>(sharedMap);
    }
}

const LineTypeTranslator<MtlLineType> MaterialObjParser::m_lineTypeTranslator = MtlLineTypeTranslator();

DEFINE_TRACE_AREA(MaterialParser, 0);

MaterialObjParser::MaterialObjParser(IResourceServer& resourceServer)
    : FileParserBase(resourceServer, nullptr),
    m_currentMaterial(std::make_shared<MaterialDescriptor>()),
    m_materialLibrary(std::make_shared<std::map<std::string, std::shared_ptr<MaterialDescriptor>>>())
{
    m_currentMaterial->SetName("EmptyMaterial");
    m_commentChars = "#";
}

MaterialObjParser::~MaterialObjParser()
{
}

void MaterialObjParser::ProcessNonEmptyLine(LineTokensPtr& tokens)
{
    SpectreAssert(tokens->size() > 0);
    SpectreAssert((*tokens)[0].size() > 0);

    if (tokens->size() < 2)
    {
        // TRACE skipping line with not enough tokens.
        return;
    }

    if ((*tokens)[0] == "newmtl")
    {
        /// Concatenate all the tokens that might be part of a name with spaces
        if (tokens->size() > 2)
        {
            auto start = tokens->begin() + 2;
            for (auto i = start; i != tokens->end(); ++i)
                tokens->at(1) += " " + *i;
            /// Remove the rest of the merged tokens
            tokens->erase(start, tokens->end());
        }
        AddNewMaterial(tokens);
        return;
    }

    if (!m_currentMaterial)
    {
        TRACE_INFO(MaterialParser, "No material is generated and the first statement is not newmtl.");
        return;
    }

    Update(tokens);
}

void MaterialObjParser::FinalizeParseStream(void)
{
    if (m_currentMaterial != nullptr)
    {
        (*m_materialLibrary)[m_currentMaterial->GetName()] = m_currentMaterial;
    }
}

void MaterialObjParser::AddNewMaterial(LineTokensPtr& tokens)
{
    if (tokens->size() != 2)
    {
        throw Spectre::Utils::SpectreException("Expected 2 tokens for the material name.");
    }

    // If we have generated a material save it.
    if (m_currentMaterial)
    {
        (*m_materialLibrary)[m_currentMaterial->GetName()] = m_currentMaterial;
    }

    m_currentMaterial = std::make_shared<MaterialDescriptor>();
    m_currentMaterial->SetName(tokens->at(1));
}

void MaterialObjParser::Update(LineTokensPtr& tokens)
{
    auto lineType = m_lineTypeTranslator.LookUp((*tokens)[0]);

    std::shared_ptr<Spectre::Transcoder::TextureDescriptor> texture;
    switch (lineType)
    {
    case MtlLineType::TextureDiffuse:
    case MtlLineType::TextureSpecular:
    case MtlLineType::TextureEmissive:
    case MtlLineType::TextureNormal:
    case MtlLineType::TextureDetail:
        texture = GetTexture(tokens);
        if (texture == nullptr)
        {
            TRACE_INFO(MaterialParser, "Texture couldn't be generated - skipping");
            return;
        }
        break;
    default:
        // Do nothing
        break;
    }

    switch (lineType)
    {
    case MtlLineType::TextureDiffuse:
        m_currentMaterial->GetOrAddLayer(LayerType::kDiffuse)->Texture = texture;
        break;
    case MtlLineType::TextureSpecular:
        m_currentMaterial->GetOrAddLayer(LayerType::kSpecularGlossiness)->Texture = texture;
        break;
    case MtlLineType::TextureEmissive:
        m_currentMaterial->GetOrAddLayer(LayerType::kEmissive)->Texture = texture;
        break;
    case MtlLineType::TextureNormal:
        m_currentMaterial->GetOrAddLayer(LayerType::kNormal)->Texture = texture;
        break;
    case MtlLineType::TextureDetail:
        m_currentMaterial->GetOrAddLayer(LayerType::kDetail)->Texture = texture;
        break;
    case MtlLineType::Opacity:
    {
        auto opacity = Utils::Math::Clamp(m_tokenParser.GetFloatAtPosition(tokens, 1), 0.0f, 1.0f);
        auto diffuseLayer = m_currentMaterial->GetOrAddLayer(LayerType::kDiffuse);
        if (!diffuseLayer->Color)
        {
            diffuseLayer->SetColor(Utils::Math::Color(0.5f, 0.5f, 0.5f, opacity));
        }
        else
        {
            diffuseLayer->Color->A(opacity);
        }
        break;
    }
    case MtlLineType::ColorDiffuse:
    {
        auto color = CreateColor(tokens);
        auto diffuseLayer = m_currentMaterial->GetOrAddLayer(LayerType::kDiffuse);
        if (!diffuseLayer->Color)
        {
            diffuseLayer->SetColor(std::move(color));
        }
        else
        {
            diffuseLayer->Color->R(color.R());
            diffuseLayer->Color->G(color.G());
            diffuseLayer->Color->B(color.B());
        }
        break;
    }
    case MtlLineType::ColorSpecular:
    {
        auto color = CreateColor(tokens);
        auto specularLayer = m_currentMaterial->GetOrAddLayer(LayerType::kSpecularGlossiness);
        if (!specularLayer->Color)
        {
            specularLayer->SetColor(std::move(color));
        }
        else
        {
            specularLayer->Color->R(color.R());
            specularLayer->Color->G(color.G());
            specularLayer->Color->B(color.B());
        }
        break;
    }
    case MtlLineType::SpecularExponent:
    {
        auto smoothness = Spectre::Utils::Math::Clamp(SpecularPowerToSmoothness(m_tokenParser.GetFloatAtPosition(tokens, 1)), 0.0f, 1.0f);
        auto specularLayer = m_currentMaterial->GetOrAddLayer(LayerType::kSpecularGlossiness);
        if (!specularLayer->Color)
        {
            specularLayer->SetColor(Utils::Math::Color(1.0f, 1.0f, 1.0f, smoothness));
        }
        else
        {
            specularLayer->Color->A(smoothness);
        }
        break;
    }
    default:
        TRACE_INFO(MaterialParser, "Material property detected and skipped");
        break;
    }
}

Spectre::Utils::Math::Color MaterialObjParser::CreateColor(LineTokensPtr& tokens) const
{
    // In the form "Ks xyz x y z"
    if (tokens->size() == 5 && (*tokens)[1] == "xyz")
    {
        auto vectorXYZ = m_tokenParser.GetVector3AtPosition(tokens, 2);
        // TODO transform from CIE to RGBA
        return Utils::Math::Color(vectorXYZ);
    }

    // Unexpected number of tokens.
    if (tokens->size() != 4)
    {
        // TODO fix when default color is there
        throw Spectre::Utils::SpectreException("Unexpected number of tokens while parsing color.");
    }

    // In the form "Kd spectral file.rfl factor"
    if ((*tokens)[1] == "spectral")
    {
        throw Spectre::Utils::SpectreException("Not supported color mode.");
    }

    // In the form "Kd r g b"
    auto vec3 = m_tokenParser.GetVector3AtPosition(tokens, 1);
    return Utils::Math::Color(vec3);
}
