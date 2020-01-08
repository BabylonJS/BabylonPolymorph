/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <PluginSDK/IResourceServer.h>

#include "TranscoderException.h"
#include <CoreUtils/StreamUtils.h>
#include <TranscoderGLTF/TranscoderGLTF.h>
#include <ExporterGLTF/ExporterGLTF.h>
#include <TranscoderGLTF/GLTFToAsset3DConverter.h>
#include <Framework/Frame.h>
#include <Asset3D/Asset3D.h>
#include <TranscoderGLTF/ImporterGLTF.h>
#include "TranscoderGLTF/IStreamReaderRSAdapter.h"
#include "TranscoderGLTF/GLTFImportOptions.h"

using namespace Spectre::Transcoder;
using namespace Spectre::Utils;
using namespace GLTF;

std::shared_ptr<Asset3D> Spectre::Transcoder::ImportGLTF(
    const std::string& filename,
    IResourceServer* resourceServer,
    FractionalProgressCallback progress,
    Spectre::Framework::ICancellationTokenPtr cancellationToken,
    const std::unordered_map<std::string, std::string>& options,
    uint64_t* streamSize)
{
    auto stream = resourceServer->RequestResource(filename);
    if (stream == nullptr)
    {
        throw TranscoderResourceFailedException("resource not found or empty. " + filename);
    }

    if (streamSize != nullptr)
    {
        *streamSize = Spectre::Utils::GetIStreamLength(*stream);
    }

    try
    {
        auto streamReader = std::make_shared<IStreamReaderRSAdapter>(resourceServer);
        auto asset3d = ImporterGLTF::Import(streamReader, stream, cancellationToken, GLTFImportOptions::ParseOptions(options));
        return asset3d;
    }
    catch (Microsoft::glTF::GLTFException ex)
    {
        throw SpectreException(ex.what());
    }
}