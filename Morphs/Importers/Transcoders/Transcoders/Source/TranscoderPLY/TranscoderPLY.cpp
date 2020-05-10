/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include "TranscoderException.h"
#include <TranscoderPLY/TranscoderPLY.h>
#include <TranscoderPLY/PLYParser.h>

#include <ImagingComponent/ImagingComponent.h>

#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/StringUtils.h>
#include <CoreUtils/Trace.h>

#include <PluginSDK/TranscodeOptions.h>

DEFINE_TRACE_AREA(TranscoderPLY, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<Asset3D> Babylon::Transcoder::ImportPLY(
    const std::string& filename,
    IResourceServer* resourceServer,
    FractionalProgressCallback progress,
    Babylon::Framework::ICancellationTokenPtr cancellationToken,
    const std::unordered_map<std::string, std::string>& options,
    uint64_t* streamSize)
{
    TranscodeOptions transcodeOptions;
    transcodeOptions.Parse(options);

    auto stream = resourceServer->RequestTextFileResource(filename);
    if (stream == nullptr)
    {
        throw TranscoderResourceFailedException("resource not found or empty. " + filename);
    }

    if (streamSize != nullptr)
    {
        *streamSize = stream->GetSize();
    }

    PLYParser fileParser(stream, resourceServer, progress, cancellationToken);

    fileParser.ParseStreamToPly();

    //release the stream as soon as possible
    stream.reset();

    return fileParser.CreateAsset3d();
}
