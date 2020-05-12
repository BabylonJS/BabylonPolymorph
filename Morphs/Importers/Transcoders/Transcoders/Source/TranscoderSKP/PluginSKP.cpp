/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <CoreUtils/Platform.h>
#include <PluginSKP/PluginSKP.h>

#if CANVAS_CAN_USE_SKP()

#include <CoreUtils/StreamUtils.h>
#include <PluginSDK/IResourceServer.h>
#include <PluginSDK/UpdateReporter.h>

#include "ImporterSKP.h"
#include "TranscoderException.h"

#include <sstream>

using namespace Babylon::Transcoder;

std::shared_ptr<Asset3D> Babylon::Transcoder::ImportSKP(
    const std::string& filename,
    IResourceServer* resourceServer,
    FractionalProgressCallback progress,
    Babylon::Framework::ICancellationTokenPtr cancellationToken,
    const std::unordered_map<std::string, std::string>& /*options*/,
    uint64_t* streamSize)
{
    auto stream = resourceServer->RequestResource(filename);
    if (stream == nullptr)
    {
        throw TranscoderResourceFailedException("resource not found or empty. " + filename);
    }

    if (streamSize != nullptr)
    {
        *streamSize = Babylon::Utils::GetIStreamLength(*stream);
    }

    UpdateReporter percentageReporter;
    percentageReporter.SetProgressReporter(progress);
    percentageReporter.SetWeights(1.0f, 0.0f);

    if (cancellationToken == nullptr)
    {
        cancellationToken = Babylon::Framework::MakeNullCancellationToken();
    }

    ImporterSKP importer;
    auto asset3d = importer.ImportToAsset3D(stream, &percentageReporter, cancellationToken);

    return asset3d;
}

#endif