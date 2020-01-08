/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <string>

#include <GLTFSDK/Deserialize.h>
#include <GLTFSDK/GLBResourceReader.h>
#include <GLTFSDK/ExtensionsKHR.h>

#include <CoreUtils/Trace.h>

#include "TranscoderGLTF/GLTFToAsset3DConverter.h"
#include "TranscoderGLTF/ImporterGLB.h"
#include "TranscoderGLTF/GLTFImportOptions.h"

using namespace Microsoft;
using namespace Spectre::Utils;
using namespace Spectre::Transcoder;

DEFINE_TRACE_AREA(ImporterGLB, 0);

std::shared_ptr<Asset3D> ImporterGLB::Import(
    const std::shared_ptr<Microsoft::glTF::IStreamReader>& streamReader,
    std::shared_ptr<std::istream> glbStream,
    Spectre::Framework::ICancellationTokenPtr cancellationToken,
    const std::unordered_map<std::string, std::string>& options)
{
    if (cancellationToken == nullptr)
    {
        cancellationToken = Spectre::Framework::MakeNullCancellationToken();
    }

    Microsoft::glTF::GLBResourceReader resourceReader(streamReader, glbStream);
    auto json = resourceReader.GetJson();

    cancellationToken->CheckCancelledAndThrow();

    auto doc = Microsoft::glTF::Deserialize(json, Microsoft::glTF::KHR::GetKHRExtensionDeserializer(), Microsoft::glTF::DeserializeFlags::IgnoreByteOrderMark);
    Microsoft::glTF::Validation::Validate(doc);

    cancellationToken->CheckCancelledAndThrow();

    GLTF::GLTFToAsset3DConverter converter(resourceReader, GLTFImportOptions::ParseOptions(options));
    return converter.CreateAsset3D(doc, cancellationToken);
}