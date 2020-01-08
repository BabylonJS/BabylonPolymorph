/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <ExporterSTL/ExporterAsciiStl.h>

#include <PluginSDK/TranscodeOptions.h>

DEFINE_TRACE_AREA(ExporterAsciiStl, 0);

using namespace Spectre::Transcoder;

void ExporterAsciiStl::ExportStatic(Asset3DPtr asset3D, const std::string& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress, Spectre::Framework::ICancellationTokenPtr cancellationToken, const std::unordered_map<std::string, std::string>& options)
{
    TranscodeOptions transcodeOptions;
    transcodeOptions.Parse(options);

    if (asset3D->HasNonTriangleGeometry())
    {
        throw Utils::SpectreException("Asset3D contains non-triangle geometry.");
    }

    auto stlFile = streamFactory->CreateStream(assetName + ".stl");

    ExporterAsciiStl exporter(assetName, *stlFile, cancellationToken);
    exporter.Export(*asset3D);
}


ExporterAsciiStl::ExporterAsciiStl(std::string assetName, std::ostream& outputStream, Spectre::Framework::ICancellationTokenPtr cancellationToken)
    : m_outputStream(outputStream),
    m_assetName(assetName),
    m_cancellationToken(cancellationToken)
{
    if (m_cancellationToken == nullptr)
    {
        m_cancellationToken = Spectre::Framework::MakeNullCancellationToken();
    }
}

void ExporterAsciiStl::ProcessAsset3DBeforeChildren(Asset3D& asset3D)
{
    m_outputStream << "solid " << m_assetName << std::endl;
    m_transforms.push(asset3D.GetTransform());
}

void ExporterAsciiStl::ProcessAsset3DAfterChildren(Asset3D& asset3D)
{
    SpectreUnusedParameter(asset3D);
    m_outputStream << "endsolid " << m_assetName << std::endl;
}

void ExporterAsciiStl::ProcessMeshBeforeMaterialAndGeometry(SceneNode&, Mesh& mesh)
{
    auto transform = m_transforms.top();
    for (auto& geometry : mesh.GetGeometries())
    {
        for (size_t i = 0; i < geometry.GetTriangleCount(); ++i)
        {
            m_cancellationToken->CheckCancelledAndThrow();

            uint32_t index0, index1, index2;
            if (geometry.HasIndices())
            {
                index0 = geometry.GetIndices()[i * 3];
                index1 = geometry.GetIndices()[i * 3 + 1];
                index2 = geometry.GetIndices()[i * 3 + 2];
            }
            else
            {
                index0 = static_cast<uint32_t>(i * 3);
                index1 = static_cast<uint32_t>(i * 3 + 1);
                index2 = static_cast<uint32_t>(i * 3 + 2);
            }

            auto position0 = Vector3::Transform(geometry.GetPositions()[index0], transform);
            auto position1 = Vector3::Transform(geometry.GetPositions()[index1], transform);
            auto position2 = Vector3::Transform(geometry.GetPositions()[index2], transform);

            auto u = position1 - position0;
            auto v = position2 - position0;
            auto normal = u.Cross(v);
            normal.Normalize();

            m_outputStream << "facet normal " << normal.x << " " << -normal.z << " " << normal.y << "\n";
            m_outputStream << "    outer loop\n";
            m_outputStream << "        vertex " << position0.x << " " << -position0.z << " " << position0.y << "\n";
            m_outputStream << "        vertex " << position1.x << " " << -position1.z << " " << position1.y << "\n";
            m_outputStream << "        vertex " << position2.x << " " << -position2.z << " " << position2.y << "\n";
            m_outputStream << "    endloop\n";
            m_outputStream << "endfacet\n";
        }
    }
}

void ExporterAsciiStl::ProcessSceneNodeBeforeChildren(SceneNode& sceneNode)
{
    m_transforms.push(sceneNode.GetTransform() * m_transforms.top());
}

void ExporterAsciiStl::ProcessSceneNodeAfterChildren(SceneNode& sceneNode)
{
    SpectreUnusedParameter(sceneNode);
    m_transforms.pop();
}

ExporterAsciiStl::~ExporterAsciiStl()
{
}
