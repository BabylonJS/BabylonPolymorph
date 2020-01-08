/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <functional>
#include <memory>

#include <PluginSDK/LineTokensPtr.h>
#include <PluginSDK/UpdateReporter.h>
#include <PluginSDK/IParser.h>

namespace Spectre
{
    namespace Transcoder
    {
        class TranscoderTextStream;

        /*
        * The class is used to parse a text file containing 3D asset data.
        * Child classes need to implement ProcessNonEmptyLine() and FinalizeFile()
        * to control the creation of different Descriptors to be encoded to BXF.
        */
        class FileParserBase : public IParser
        {
        public:
            explicit FileParserBase(IResourceServer& resourceServer, UpdateReporter* updateReporter);
            virtual ~FileParserBase();

            virtual void ParseStream(std::shared_ptr<TranscoderTextStream> stream, size_t maxLineSize = 4096);
            LineTokensPtr GetTokens(char* line, size_t lineLength, const char* m_delimiters = "\n \r\t") const;
            virtual size_t ReadLine(TranscoderTextStream* stream, char* outputBuffer, size_t maxLineSize);

        protected:
            void ParseLine(char* line, size_t lineLength);

            virtual void ProcessNonEmptyLine(LineTokensPtr& tokens) = 0;
            virtual void FinalizeParseStream(void) = 0;

            UpdateReporter* m_progressReporter;
            size_t m_charactersRead;
            size_t m_streamLength;
            /// Starting chars of a line comment. Example // or #
            std::string m_commentChars;
        };
    }
}
