/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <sstream>

#include <PluginSDK/TranscodeOptions.h>
#include <PluginSDK/TranscoderTextStream.h>
#include <PluginSDK/UpdateReporter.h>

#include "TranscoderException.h"
#include <TranscoderOBJ/GeometryParser.h>
#include <TranscoderOBJ/TranscoderOBJ.h>
#include <Framework/Async.h>
#include <ExporterOBJ/ExporterObj.h>

using namespace Babylon::Transcoder;

std::shared_ptr<Asset3D> Babylon::Transcoder::ImportOBJ(const std::string& filename, IResourceServer* resourceServer, FractionalProgressCallback progress, Babylon::Framework::ICancellationTokenPtr cancellationToken, const std::unordered_map<std::string, std::string>& options, uint64_t* streamSize)
{
    TranscodeOptions transcodeOptions;
    transcodeOptions.Parse(options);

    auto istream = resourceServer->RequestTextFileResource(filename);
    if (istream == nullptr)
    {
        throw TranscoderResourceFailedException("resource not found or empty. " + filename);
    }

    if (streamSize != nullptr)
    {
        *streamSize = istream->GetSize();
    }

    UpdateReporter percentageReporter;
    percentageReporter.SetProgressReporter(progress);

    auto fileParser = std::make_unique<GeometryParser>(*resourceServer, &percentageReporter, cancellationToken);
    // MPJ TODO: Need to handle load options in a nice way (e.g. JSON would make extensible, data-driven configurations much easier in future)
    fileParser->ParseStream(istream);

    return fileParser->GetAsset3D();
}