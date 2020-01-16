/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>

#include <Asset3D/Asset3D.h>
#include <PluginSDK/FileParserBase.h>
#include <TranscoderOBJ/AuthorType.h>
#include <TranscoderOBJ/GeometryLineType.h>
#include <TranscoderOBJ/MaterialParser.h>

namespace Babylon
{
    namespace Utils
    {
        namespace Math
        {
            struct Vector3;
            struct Vector2;
        }
    }

    namespace Transcoder
    {
        // Forward declarations
        class Geometry;
        class MaterialDescriptor;
        template<typename T> class LineTypeTranslator;
        class TokenParser;

        // Type definitions
        typedef std::map<std::string, std::shared_ptr<MaterialDescriptor>> MaterialLibrary;
        typedef std::shared_ptr<MaterialLibrary> MaterialLibraryPtr;
        typedef std::vector<MaterialLibraryPtr> MaterialLibraries;

        class GeometryParser : public FileParserBase
        {
        public:
            explicit GeometryParser(
                IResourceServer& resourceServer,
                UpdateReporter* updateReporter = nullptr,
                Framework::ICancellationTokenPtr cancellationToken = nullptr);

            void SetAuthorSettings(AuthorType author);

            void ProcessNonEmptyLine(LineTokensPtr& tokens) override;
            void FinalizeParseStream(void) override;

            void ProcessVertex(LineTokensPtr& tokens);
            void ProcessTextureVertex(LineTokensPtr& tokens);
            void ProcessNormal(LineTokensPtr& tokens);
            void ProcessFace(LineTokensPtr& tokens);
            void ProcessMaterialLibrary(LineTokensPtr& tokens);
            void ProcessMaterial(LineTokensPtr& tokens);
            void ProcessSmoothingGroup(LineTokensPtr& tokens);
            void ProcessComment(LineTokensPtr& tokens);

            inline std::shared_ptr<Asset3D> GetAsset3D() const { return m_asset3D; }
            virtual size_t ReadLine(TranscoderTextStream* stream, char* outputBuffer, size_t maxLineSize) override;

        protected:
            struct ObjVertex
            {
                std::string v;
                std::string vt;
                std::string vn;
            };

            std::shared_ptr<TranscoderTextStream> RequestTextFileResource(std::string& fileName) const;
            size_t ReadLineWithoutEOL(TranscoderTextStream* stream, char* buffer, size_t maxLineSize);
            void AddVertex(const ObjVertex& vertex);
            ObjVertex GetVertex(const std::string& vertexStr) const;

            std::shared_ptr<MaterialDescriptor> FindMaterial(const std::string& name);

            void AddGeometry(std::shared_ptr<MaterialDescriptor> material);
            void FinalizeGeometry();

            static const LineTypeTranslator<GeometryLineType> m_lineTypeTranslator;
            static const LineTypeTranslator<AuthorType> m_authorTypeTranslator;

            IResourceServer* m_resourceServer;
            Framework::ICancellationTokenPtr m_cancellationToken;

            std::shared_ptr<TokenParser> m_tokenParser;

            std::shared_ptr<Asset3D> m_asset3D;
            std::shared_ptr<Mesh> m_currentMesh;
            Geometry* m_currentGeometry;

            std::vector<Vector3> m_positions;
            std::vector<Vector3> m_normals;
            std::vector<Vector2> m_uv0s;

            bool m_hasSmoothingGroup;

            // Material libraries
            MaterialLibraries m_materialLibraries;
            std::shared_ptr<MaterialDescriptor> m_defaultMaterial;

            AuthorType m_author;
            bool m_yzflip;
            bool m_dataProcessed;
        };
    }
}