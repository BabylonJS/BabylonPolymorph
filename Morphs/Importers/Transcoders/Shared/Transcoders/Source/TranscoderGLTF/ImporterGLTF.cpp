/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <GLTFSDK/Deserialize.h>
#include <GLTFSDK/GLTFResourceReader.h>
#include <GLTFSDK/ExtensionsKHR.h>

#include <CoreUtils/StreamUtils.h>

#include "TranscoderGLTF/GLTFToAsset3DConverter.h"
#include "TranscoderGLTF/ImporterGLTF.h"
#include "TranscoderGLTF/GLTFImportOptions.h"

using namespace Microsoft;
using namespace Babylon::Transcoder;
using namespace Babylon::Transcoder::GLTF;

std::shared_ptr<Asset3D> ImporterGLTF::Import(
    const std::shared_ptr<glTF::IStreamReader>& streamReader,
    std::shared_ptr<std::istream> stream,
    Babylon::Framework::ICancellationTokenPtr cancellationToken,
    const GLTFImportOptions& options)
{
    if (cancellationToken == nullptr)
    {
        cancellationToken = Babylon::Framework::MakeNullCancellationToken();
    }

    glTF::GLTFResourceReader resourceReader(streamReader);

    cancellationToken->CheckCancelledAndThrow();

    auto json = ImporterGLTF::ParseJson(*stream);
    auto doc = glTF::Deserialize(json, glTF::KHR::GetKHRExtensionDeserializer(), glTF::DeserializeFlags::IgnoreByteOrderMark);
    glTF::Validation::Validate(doc);

    cancellationToken->CheckCancelledAndThrow();

    GLTFToAsset3DConverter converter(resourceReader, options);
    return converter.CreateAsset3D(doc, cancellationToken);
}

std::string ImporterGLTF::ParseJson(std::istream& stream)
{
    auto dq = Babylon::Utils::ConvertStreamToDeque<char>(stream);

    //Copy deque into string after we reserve memory to prevent growing the string.
    std::string s;
    s.reserve(dq.size());
    s.assign(dq.begin(), dq.end());

    return s;
}