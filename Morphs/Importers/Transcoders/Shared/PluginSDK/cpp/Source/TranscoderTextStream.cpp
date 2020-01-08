/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
 #include "PluginSDKPch.h"

#include <sstream>

#include <PluginSDK/TranscoderTextStream.h>
#include <CoreUtils/StreamUtils.h>

using namespace Spectre::Transcoder;
using namespace Spectre::Utils;

TranscoderTextStream::TranscoderTextStream(std::shared_ptr<std::istream> stream)
    : m_stream(stream), m_size(Spectre::Utils::GetIStreamLength(*stream))
{
}