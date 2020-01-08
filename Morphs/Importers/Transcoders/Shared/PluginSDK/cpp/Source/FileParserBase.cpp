/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "PluginSDKPch.h"

#include <CoreUtils/StringUtils.h>
#include <PluginSDK/FileParserBase.h>
#include <PluginSDK/TranscoderTextStream.h>

using namespace Spectre::Transcoder;

FileParserBase::FileParserBase(IResourceServer& resourceServer, UpdateReporter* progressReporter = nullptr)
    : IParser(resourceServer),
    m_progressReporter(progressReporter),
    m_charactersRead(0),
    m_streamLength(0)
{
}

FileParserBase::~FileParserBase()
{
}

void FileParserBase::ParseStream(std::shared_ptr<TranscoderTextStream> stream, size_t maxLineSize)
{
    SpectreAssert(stream!=nullptr);

    if (stream == nullptr || stream->EndOfStream())
    {
        return;
    }

    auto line = std::make_unique<char[]>(maxLineSize);
    m_streamLength = stream->GetSize();

    size_t numRead = 0;
    do
    {
        numRead = ReadLine(stream.get(), line.get(), maxLineSize);

        if (numRead == 0)
        {
            continue;
        }

        // Get the number of elements read from the stream except from the null termination symbol.
        size_t lineLength = (size_t)numRead - 1;
        ParseLine(line.get(), lineLength);

        m_charactersRead += numRead;
        if (m_progressReporter)
        {
            float percentage = m_streamLength != 0 ? Spectre::Utils::Math::Clamp((float)m_charactersRead / (float)m_streamLength, 0.0f, 1.f) : 0.1f;
            m_progressReporter->ReportCompletedParsing(percentage);
        }
    } while (!stream->Fail() && !stream->EndOfStream());

    FinalizeParseStream();
}

size_t FileParserBase::ReadLine(TranscoderTextStream* stream, char* buffer, size_t maxLineSize)
{
    stream->ReadLine(buffer, maxLineSize);

    return stream->CharactersRead();
}

LineTokensPtr FileParserBase::GetTokens(
    char* mergedTokens,
    size_t lineLength,
    const char* delimiters) const
{
    SpectreUnusedParameter(lineLength);

    /// Find and remove line comments
    if (!m_commentChars.empty())
    {
        /// Find the start of the comment and terminate the string
        if (auto start = strstr(mergedTokens, m_commentChars.c_str()))
            start[0] = '\0';
    }

    auto tokens = std::make_unique<std::vector<std::string>>();
    char* nextToken = nullptr;

    auto currentToken = strtok_s(mergedTokens, delimiters, &nextToken);
    while (currentToken)
    {
        tokens->push_back(std::string(currentToken));
        currentToken = strtok_s(nullptr, delimiters, &nextToken);
    }

    return tokens;
}

void FileParserBase::ParseLine(char* line, size_t lineLength)
{
    auto tokens = GetTokens(line, lineLength);

    // Skip empty line
    if (tokens->size() == 0)
    {
        return;
    }

    ProcessNonEmptyLine(tokens);
}
