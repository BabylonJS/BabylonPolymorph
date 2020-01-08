/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/FileParserBase.h>
#include <PluginSDK/LineTypeTranslator.h>
#include <Asset3D/Asset3D.h>

#include <stack>

namespace Spectre
{
    namespace Transcoder
    {
        class StlAsciiParser : public Transcoder::FileParserBase
        {
        public:
            enum class LineType
            {
                Unknown = 0,
                Solid,
                Facet,
                OuterLoop,
                Vertex,
                EndLoop,
                EndFacet,
                EndSolid,
            };

            StlAsciiParser(IResourceServer& resourceServer, UpdateReporter* updateReporter, Framework::ICancellationTokenPtr cancellationToken = nullptr);

            void ProcessNonEmptyLine(Transcoder::LineTokensPtr& tokens) override;
            void FinalizeParseStream(void) override;

            inline std::shared_ptr<Asset3D> GetAsset3D() const { return m_asset3D; }

        private:
            static const LineTypeTranslator<LineType> m_lineTypeTranslator;

            void ParseSolid(const Transcoder::LineTokensPtr& tokens);
            void ParseFacet(const Transcoder::LineTokensPtr& tokens);
            void ParseOuterLoop(const Transcoder::LineTokensPtr& tokens);
            void ParseVertex(const Transcoder::LineTokensPtr& tokens);

            void ParseEndLoop(const Transcoder::LineTokensPtr& tokens);

            void CheckAndPush(LineType current, LineType parent, const std::string& message);
            void CheckAndPop(LineType sibling, const std::string& message, const Spectre::Transcoder::LineTokensPtr& tokens);

            std::shared_ptr<Asset3D> m_asset3D;

            std::vector<uint32_t> m_indices;
            std::vector<Spectre::Utils::Math::Vector3> m_positions;

            std::stack<LineType> m_hierarchy;

            Framework::ICancellationTokenPtr m_cancellationToken;
        };
    }
}