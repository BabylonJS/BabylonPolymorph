/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <map>

#include <PluginSDK/FileParserBase.h>
#include <Asset3D/TextureDescriptor.h>
#include <PluginSDK/LineTokensPtr.h>
#include <PluginSDK/LineTypeTranslator.h>
#include <PluginSDK/TokenParser.h>
#include <CoreUtils/StreamUtils.h>
#include "MtlLineType.h"

namespace Spectre
{
    namespace Transcoder
    {
        /*
        *  A MaterialParser is created by a GeometryParser and it's purpose is to parse a single .mtl and create
        *  the Material Library, by calling the ParseStream. The GeometryParser will get ownership of the
        *  MaterialLibrary and destroy the MaterialParser.
        */
        template<typename T> class LineTypeTranslator;
        class MaterialObjParser : public FileParserBase
        {
        public:
            explicit MaterialObjParser(IResourceServer& resourceServer);
            virtual ~MaterialObjParser();

            // Get the created MaterialLibrary
            std::shared_ptr<std::map<std::string, std::shared_ptr<MaterialDescriptor>>> GetMaterialLibrary() const { return m_materialLibrary; }

        protected:
            void Update(LineTokensPtr& tokens);

            inline std::shared_ptr<Spectre::Transcoder::TextureDescriptor> GetTexture(LineTokensPtr& tokens);
            inline std::shared_ptr<Spectre::Transcoder::TextureDescriptor> GenerateTexture(const std::string& textureName);

            virtual void ProcessNonEmptyLine(LineTokensPtr& tokens) override;
            virtual void FinalizeParseStream(void) override;

            // Create a new material that will then parse.
            void AddNewMaterial(LineTokensPtr& tokens);

            Spectre::Utils::Math::Color CreateColor(LineTokensPtr& tokens) const;

            TokenParser m_tokenParser;

            // Static dictionary that maps string litterals to MtlLineType
            // in order to choose how to process the line.
            static const LineTypeTranslator<MtlLineType> m_lineTypeTranslator;

            // The current material that is being parserd and updated.
            // It will be eventually added to m_materialLibrary.
            std::shared_ptr<MaterialDescriptor> m_currentMaterial;

            // The full list of materials that this .mtl file contains. When the .mtl file is parsed the
            // Material Library is being handed over to the GeometryParser that created the MaterialParser.
            std::shared_ptr<std::map<std::string, std::shared_ptr<MaterialDescriptor>>> m_materialLibrary;

            std::unordered_map<std::string, std::shared_ptr<TextureDescriptor>> m_textures;
        };
    }
}

inline std::shared_ptr<Spectre::Transcoder::TextureDescriptor> Spectre::Transcoder::MaterialObjParser::GetTexture(LineTokensPtr& tokens)
{
    std::string textureName = tokens->at(1);
    for (size_t i = 2; i < tokens->size(); i++)
    {
        textureName += " " + tokens->at(i);
    }

    auto result = m_textures.emplace(textureName, nullptr);
    if (result.second)
    {
        // Successfully inserted nullptr, so update it to a generated texture
        result.first->second = GenerateTexture(textureName);
    }

    return result.first->second;
}

inline std::shared_ptr<Spectre::Transcoder::TextureDescriptor> Spectre::Transcoder::MaterialObjParser::GenerateTexture(const std::string& textureName)
{
    if (auto textureStream = m_resourceServer.RequestResource(textureName))
    {
        size_t textureSize = 0;
        auto textureData = Spectre::Utils::ReadStreamIntoUniquePtr(*textureStream, textureSize);

        auto texture = std::make_shared<TextureDescriptor>(std::move(textureData), textureSize);
        texture->SetName(textureName);
        return texture;
    }
    return nullptr;
}