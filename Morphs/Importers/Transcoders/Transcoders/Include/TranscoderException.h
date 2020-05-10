/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#ifndef TRANSCODER_EXCEPTION_H_INCLUDED
#define TRANSCODER_EXCEPTION_H_INCLUDED

#ifndef _STRING_
#include <string>
#endif

#include <CoreUtils/SmartThrow.h>

namespace Babylon
{
    namespace Transcoder
    {
        struct TranscoderException :
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
            Babylon::Utils::BabylonTelemetryException
#else
            Babylon::Utils::BabylonException
#endif
        {
            TranscoderException(std::string const& message, bool assert = false);
            TranscoderException(std::string file, int line, std::string const& message, bool assert = false);
        };

        struct TranscoderInvalidArgException : public TranscoderException
        {

            TranscoderInvalidArgException(std::string file, int line, std::string const& message, bool assert = false)
                : TranscoderException(file, line, message, assert)
            {}
        };

        struct TranscoderNotImplException : public TranscoderException
        {
            TranscoderNotImplException(std::string file, int line, std::string const& message, bool assert = false)
                : TranscoderException(file, line, message, assert)
            {}
        };

        struct TranscoderOutofMemoryException : public TranscoderException
        {
            TranscoderOutofMemoryException(std::string file, int line, std::string const& message, bool assert = false)
                : TranscoderException(file, line, message, assert)
            {}
        };

        struct TranscoderInvalidDataException : public TranscoderException
        {
            TranscoderInvalidDataException(std::string file, int line, std::string const& message, bool assert = false)
                : TranscoderException(file, line, message, assert)
            {}
        };

        struct TranscoderResourceFailedException : public TranscoderException
        {
            TranscoderResourceFailedException(std::string file, int line, std::string const& message, bool assert = false)
                : TranscoderException(file, line, message, assert)
            {}
        };

        struct TranscoderInvalidOperationException : public TranscoderException
        {
            TranscoderInvalidOperationException(std::string file, int line, std::string const& message, bool assert = false)
                : TranscoderException(file, line, message, assert)
            {}
        };
    }
}
// Define TranscoderException to use new TranscoderException structure
// TranscoderException will take same parameters as BabylonException
#define TranscoderException(...) Babylon::Transcoder::TranscoderException(__FILE__, __LINE__, __VA_ARGS__)
#define TranscoderInvalidArgException(...) Babylon::Transcoder::TranscoderInvalidArgException(__FILE__, __LINE__, __VA_ARGS__)
#define TranscoderNotImplException(...) Babylon::Transcoder::TranscoderNotImplException(__FILE__, __LINE__, __VA_ARGS__)
#define TranscoderOutofMemoryException(...) Babylon::Transcoder::TranscoderOutofMemoryException(__FILE__, __LINE__, __VA_ARGS__)
#define TranscoderInvalidDataException(...) Babylon::Transcoder::TranscoderInvalidDataException(__FILE__, __LINE__, __VA_ARGS__)
#define TranscoderResourceFailedException(...) Babylon::Transcoder::TranscoderResourceFailedException(__FILE__, __LINE__, __VA_ARGS__)
#define TranscoderInvalidOperationException(...) Babylon::Transcoder::TranscoderInvalidOperationException(__FILE__, __LINE__, __VA_ARGS__)

#endif // TRANSCODER_EXCEPTION_H_INCLUDED
