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

using namespace Babylon::Transcoder;
using namespace Babylon::Utils;
using namespace GLTF;

std::shared_ptr<Asset3D> Babylon::Transcoder::ImportGLB(
    const std::string& filename,
    IResourceServer* resourceServer,
    FractionalProgressCallback progress,
    Babylon::Framework::ICancellationTokenPtr cancellationToken,
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
        *streamSize = Babylon::Utils::GetIStreamLength(*istream);
    }

    try
    {
        auto streamReader = std::make_shared<IStreamReaderRSAdapter>(resourceServer);
        asset3d = ImporterGLB::Import(streamReader, istream, cancellationToken, options);
    }
    catch (Microsoft::glTF::GLTFException ex)
    {
        throw BabylonException(ex.what());
    }

    return asset3d;
}