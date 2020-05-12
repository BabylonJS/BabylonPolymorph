/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include "TranscoderException.h"
#include <TranscoderSTL/TranscoderSTL.h>
#include <TranscoderSTL/StlAsciiParser.h>
#include <TranscoderSTL/StlBinaryParser.h>

#include <ImagingComponent/ImagingComponent.h>

#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/StringUtils.h>
#include <CoreUtils/Trace.h>
#include <CoreUtils/ITelemetryManager.h>
#include <CoreUtils/RapidJson.h>
#include <CoreUtils/StreamUtils.h>
#include <PluginSDK/TranscodeOptions.h>
#include <PluginSDK/TranscoderTextStream.h>
#include <ExporterSTL/ExporterAsciiStl.h>

DEFINE_TRACE_AREA(TranscoderSTL, 0);

namespace
{
    const size_t StlMinimumValidLength = 15;
}

namespace SF = Babylon::Framework;
using namespace Babylon::Transcoder;
using namespace Babylon::rapidjson;


std::string Read(std::shared_ptr<std::istream> stream, size_t count)
{
    std::vector<char> buffer(count);
    stream->read(buffer.data(), buffer.size());

    auto bytesRead = static_cast<size_t>(stream->gcount());

    if (stream->eof())
    {
        stream->clear();
        stream->seekg(0, std::ios::beg);
    }

    return std::string(buffer.begin(), buffer.begin() + bytesRead);
}

// Hard to detect binary now that we dont limit file size to matching triangle count.
// Now default assume binary if not ascii
StlFileType Babylon::Transcoder::GetStlFileType(std::shared_ptr<std::istream> stream)
{
    auto filetype = StlFileType::Unknown;

    stream->seekg(0);

    // This is a bit hacky, try to read 10000 bytes, but lots of STL-ASCII files are shorter than this
    // So the Read function has to check EOF, then clear the failbit
    std::string buffer = Read(stream, 10000);

    stream->seekg(0, std::ios::beg);

    if (buffer.size() < StlMinimumValidLength)
    {
        throw Babylon::Utils::BabylonException("Invalid Length");
    }

    // If its a text file -  does it contain expected fields?
    auto foundSolid = buffer.find("solid");
    auto foundFacet = buffer.find("facet");

    if (foundSolid != std::string::npos &&
        foundFacet != std::string::npos)
    {
        filetype = StlFileType::Ascii;
    }
    else
    {
        filetype = StlFileType::Binary;
    }

    return filetype;
}

std::shared_ptr<Asset3D> Babylon::Transcoder::ImportSTL(
    const std::string& filename,
    IResourceServer* resourceServer,
    FractionalProgressCallback progress,
    Babylon::Framework::ICancellationTokenPtr cancellationToken,
    const std::unordered_map<std::string, std::string>& options,
    uint64_t* streamSize)
{
    TranscodeOptions transcodeOptions;
    transcodeOptions.Parse(options);

    auto istream = resourceServer->RequestResource(filename);
    if (istream == nullptr)
    {
        throw TranscoderResourceFailedException("resource not found or empty. " + filename);
    }

    Asset3DPtr asset3D;

    if (streamSize != nullptr)
    {
        *streamSize = Babylon::Utils::GetIStreamLength(*istream);
    }

    auto fileType = GetStlFileType(istream);
    auto transcoderStream = std::make_shared<TranscoderTextStream>(istream);

    UpdateReporter percentageReporter;
    percentageReporter.SetProgressReporter(progress);

    switch (fileType)
    {
    case StlFileType::Ascii:
    {
        StlAsciiParser asciiFileParser(*resourceServer, &percentageReporter, cancellationToken);
        asciiFileParser.ParseStream(transcoderStream);
        asset3D = asciiFileParser.GetAsset3D();
        break;
    }
    case StlFileType::Binary:
    {
        StlBinaryParser fileParser(*resourceServer, &percentageReporter, cancellationToken);
        asset3D = fileParser.ParseStream(istream);
        break;
    }
    case StlFileType::Unknown:
        throw Babylon::Utils::BabylonNotImplException("Unsupported STL file type detected", false);
    default:
        throw Babylon::Utils::BabylonNotImplException("Unsupported for this STL file type not implemented", false);
    }

#if FEATURE_TELEMETRYENABLED
    if (auto telemetryManager = Babylon::Utils::TelemetrySingleton::get())
    {
        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        writer.StartObject();
        writer.Key("FileFormat");
        writer.String("stl");
        writer.Key("FileEncoding");
        writer.String(fileEncoding.c_str());
        writer.EndObject();

        telemetryManager->SendEvent("fileEncodingInformation", buffer.GetString());
    }
#endif
    return asset3D;
}