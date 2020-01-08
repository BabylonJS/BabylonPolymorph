/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <PluginSDK/IResourceServer.h>

#include "TranscoderException.h"
#include <CoreUtils/StreamUtils.h>
#include <TranscoderGLTF/GLTFToAsset3DConverter.h>
#include <TranscoderGLTF/TranscoderGLB.h>
#include <ExporterGLTF/ExporterGLB.h>
#include <TranscoderGLTF/ImporterGLB.h>
#include <TranscoderGLTF/IStreamReaderRSAdapter.h>

using namespace Spectre::Transcoder;
using namespace Spectre::Utils;
using namespace GLTF;

std::shared_ptr<Asset3D> Spectre::Transcoder::ImportGLB(
    const std::string& filename,
    IResourceServer* resourceServer,
    FractionalProgressCallback progress,
    Spectre::Framework::ICancellationTokenPtr cancellationToken,
    const std::unordered_map<std::string, std::string>& options,
    uint64_t* streamSize)
{
    std::shared_ptr<Asset3D> asset3d;

    auto istream = resourceServer->RequestResource(filename);
    if (istream == nullptr)
    {
        throw TranscoderResourceFailedException(filename);
    }

    if (streamSize != nullptr)
    {
        *streamSize = Spectre::Utils::GetIStreamLength(*istream);
    }

    try
    {
        auto streamReader = std::make_shared<IStreamReaderRSAdapter>(resourceServer);
        asset3d = ImporterGLB::Import(streamReader, istream, cancellationToken, options);
    }
    catch (Microsoft::glTF::GLTFException ex)
    {
        throw SpectreException(ex.what());
    }

    return asset3d;
}