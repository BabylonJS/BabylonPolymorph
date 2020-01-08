/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Assert.h>
#include <CoreUtils/SmartThrow.h>

#include <memory>
#include <istream>

namespace
{
    unsigned long DefaultWriteBufferSize = 4096L * 1024L;
}

namespace Spectre
{
    namespace Transcoder
    {
        class TranscoderTextStream
        {
        public:
            explicit TranscoderTextStream(std::shared_ptr<std::istream> stream);

            inline size_t Read(char* outputBuffer, size_t bufferSize) const;
            inline void ReadLine(char* outputBuffer, size_t bufferSize) const;
            inline void Seek(int64_t moveOffset, uint32_t origin);
            inline size_t CharactersRead() const;

            inline size_t GetPosition() const;

            inline void Close();
            inline bool Fail() const;
            inline bool EndOfStream() const;

            inline size_t GetSize() const;

        protected:
            std::shared_ptr<std::istream> m_stream;
            size_t m_size;
        };
    };
};

inline void Spectre::Transcoder::TranscoderTextStream::ReadLine(char* outputBuffer, size_t bufferSize) const
{
    SpectreAssert(outputBuffer != nullptr);
    SpectreAssert(bufferSize > 0);
    // NOTE: Make sure to null-terminate outputBuffer, since XCode's version of the standard library
    // can incorrectly fail to null-terminate it sometimes, such as when eofbit is set when getline is called
    outputBuffer[0] = '\0';

    m_stream->getline(outputBuffer, bufferSize);

    if (m_stream->fail() && !EndOfStream())
    {
        throw Spectre::Utils::SpectreException("Read Line Failed, while reading stream.");
    }
}

inline size_t Spectre::Transcoder::TranscoderTextStream::Read(char* outputBuffer, size_t bufferSize) const
{
    m_stream->read(outputBuffer, bufferSize);
    return static_cast<size_t>(m_stream->gcount());
}

inline void Spectre::Transcoder::TranscoderTextStream::Seek(int64_t moveOffset, uint32_t origin)
{
    m_stream->seekg(moveOffset, static_cast<std::ios::seekdir>(origin));
}

inline size_t Spectre::Transcoder::TranscoderTextStream::CharactersRead() const
{
    return static_cast<size_t>(m_stream->gcount());
}

inline void Spectre::Transcoder::TranscoderTextStream::Close()
{
}

inline bool Spectre::Transcoder::TranscoderTextStream::Fail() const
{
    return m_stream->fail();
}

inline bool Spectre::Transcoder::TranscoderTextStream::EndOfStream() const
{
    return m_stream->eof();
}

size_t Spectre::Transcoder::TranscoderTextStream::GetSize() const
{
    return m_size;
}

size_t Spectre::Transcoder::TranscoderTextStream::GetPosition() const
{
    return static_cast<size_t>(m_stream->tellg());
}
