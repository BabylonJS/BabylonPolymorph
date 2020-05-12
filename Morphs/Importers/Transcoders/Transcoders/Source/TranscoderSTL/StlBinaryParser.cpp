/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <CoreUtils/StreamUtils.h>

#include <Framework/GeometryUtils.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <PluginSDK/UpdateReporter.h>
#include <TranscoderSTL/StlBinaryParser.h>
#include <sstream>

#pragma strict_gs_check(on)
#pragma pack(2)

DEFINE_TRACE_AREA(StlBinaryParser, 0);

namespace
{
    struct STLTriangle
    {
        Babylon::Utils::Math::Vector3 normal;
        Babylon::Utils::Math::Vector3 vertex_1;
        Babylon::Utils::Math::Vector3 vertex_2;
        Babylon::Utils::Math::Vector3 vertex_3;
        uint16_t attributeCount;
    };

    const long long HeaderSize = 80;
}

using namespace Babylon::Transcoder;

StlBinaryParser::StlBinaryParser(IResourceServer& resourceServer, UpdateReporter* updateReporter, Babylon::Framework::ICancellationTokenPtr cancellationToken)
    : IParser(resourceServer),
    m_updateReporter(updateReporter),
    m_cancellationToken(cancellationToken)
{
    if (m_cancellationToken == nullptr)
    {
        m_cancellationToken = Babylon::Framework::MakeNullCancellationToken();
    }
}

StlBinaryParser::~StlBinaryParser()
{
}

// Read up to triangleCount triangles.
Geometry StlBinaryParser::ReadGeometry(std::shared_ptr<std::istream> stream, uint32_t triangleCount)
{
    Geometry geometry(std::make_shared<MaterialDescriptor>());
    
    auto vertexCount = 3 * triangleCount;

    std::vector<Babylon::Utils::Math::Vector3> positions;
    positions.reserve(vertexCount);

    for (uint32_t i = 0; i < vertexCount; i += 3)
    {
        STLTriangle triangle;
        stream->read(reinterpret_cast<char*>(&triangle), sizeof(triangle));
        auto readCount = stream->gcount();
        if (readCount != sizeof(triangle))
        {
            break;
        }

        positions.push_back(FlipYZAxis(triangle.vertex_1));
        positions.push_back(FlipYZAxis(triangle.vertex_2));
        positions.push_back(FlipYZAxis(triangle.vertex_3));

        if (m_updateReporter)
        {
            m_updateReporter->ReportCompletedParsing(static_cast<float>(i) / static_cast<float>(vertexCount));
        }

        m_cancellationToken->CheckCancelledAndThrow();
    }

    geometry.SetPositions(std::move(positions));

    return geometry;
}

uint32_t ParseTriangleCount(std::shared_ptr<std::istream> stream)
{
    stream->seekg(HeaderSize, std::ios::beg);

    if (!stream->good())
    {
        throw Babylon::Utils::BabylonException("Cannot seek past the header");
    }

    // Triangle count.
    uint32_t triangleCount = 0;
    stream->read(reinterpret_cast<char*>(&triangleCount), sizeof(triangleCount));
    auto readTriangleCount = stream->gcount();
    if (readTriangleCount != sizeof(triangleCount))
    {
        throw Babylon::Utils::BabylonException("Cannot read the triangle number");
    }

    return triangleCount;
}

std::shared_ptr<Asset3D> StlBinaryParser::ParseStream(std::shared_ptr<std::istream> stream)
{
    stream->seekg(0, std::ios::beg);

    auto streamLength = Utils::GetIStreamLength(*stream);

    if (streamLength < (84 + sizeof(STLTriangle)))
    {
        throw Babylon::Utils::BabylonException("The file contains no data.");
    }

    uint32_t triangleCount = ParseTriangleCount(stream);

    // Verify file integrity.
    uint64_t estimateFileSize = 84 + (triangleCount * sizeof(STLTriangle));

    if (estimateFileSize != static_cast<uint64_t>(streamLength))
    {
        std::stringstream message;
        message << "The file does not have the expected size. Expected: " << estimateFileSize << " Actual: " << streamLength;

        throw Babylon::Utils::BabylonException(message.str());
    }

    auto geometry = ReadGeometry(stream, triangleCount);

    if (m_updateReporter)
    {
        m_updateReporter->ReportCompletedParsing(1.f);
    }

    auto asset3d = std::make_shared<Asset3D>();
    asset3d->SetMesh(std::make_shared<Mesh>(std::move(geometry)));

    return asset3d;
}
