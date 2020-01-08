/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <cctype>
// TODO: TEMP COMMENT
//#include <SpectreVersionInternal.h>

#include <ImagingComponent/ImagingComponent.h>

#include <PluginSDK/TranscodeOptions.h>

#include <ExporterOBJ/ExporterObj.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>

DEFINE_TRACE_AREA(ExporterObj, 0);

using namespace Spectre::Transcoder;

namespace
{
    std::string GetFace(const Geometry& geometry)
    {
        if (geometry.HasNormals() && geometry.HasUv0s())
        {
            // f v/vt/vn v/vt/vn v/vt/vn
            return "f -3/-3/-3 -2/-2/-2 -1/-1/-1\n";
        }
        else if (geometry.HasNormals())
        {
            // f v//vn v//vn v//vn
            return "f -3//-3 -2//-2 -1//-1\n";
        }
        else if (geometry.HasUv0s())
        {
            // f v/vt/ v/vt/ v/vt/
            return "f -3/-3/ -2/-2/ -1/-1/\n";
        }

        // f v// v// v//
        return "f -3// -2// -1//\n";
    }

    std::string GetSanitizedName(const std::string& name)
    {
        auto sanitizedName = name;
        std::replace_if(sanitizedName.begin(), sanitizedName.end(), [](const auto& c) -> bool { return !std::isalnum(c); }, '_');
        return sanitizedName;
    }
}

void ExporterObj::ExportStatic(Asset3DPtr asset3D, const std::string& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress, Spectre::Framework::ICancellationTokenPtr cancellationToken, const std::unordered_map<std::string, std::string>& options)
{
    TranscodeOptions transcodeOptions;
    transcodeOptions.Parse(options);

    if (asset3D->HasNonTriangleGeometry())
    {
        throw Utils::SpectreException("Asset3D contains non-triangle geometry.");
    }

    ExporterObj exporter(assetName, streamFactory, cancellationToken);
    exporter.Export(*asset3D);
}

ExporterObj::ExporterObj(std::string assetName, IOutputStreamFactory* streamFactory, Spectre::Framework::ICancellationTokenPtr cancellationToken) :
    m_name(std::move(assetName)),
    m_streamFactory(streamFactory),
    m_cancellationToken(cancellationToken)
{
    if (m_cancellationToken == nullptr)
    {
        m_cancellationToken = Spectre::Framework::MakeNullCancellationToken();
    }

    m_geometryStream = streamFactory->CreateStream(m_name + ".obj");
    m_materialStream = streamFactory->CreateStream(m_name + ".mtl");
}

void ExporterObj::ExportNodeDownwardPass(Asset3D& asset3D)
{
    // TODO: TEMP COMMENT
    *m_geometryStream << "# Exported by Microsoft Base3D Exporter"; // << SPECTRE_PACKAGE_VERSION << "\n";
    *m_geometryStream << "# Contains: " << asset3D.GetTotalGeometryCount() << " geometries." << "\n";
    *m_geometryStream << "# Made out of: " << asset3D.GetTotalTriangleCount() << " triangles." << "\n\n";
    *m_geometryStream << "mtllib " << m_name << ".mtl" << "\n";
}

void ExporterObj::ExportNodeDownwardPass(SceneNode& sceneNode)
{
    *m_geometryStream << "\n";
    *m_geometryStream << "g " << GetUniqueName(sceneNode) << "\n";
}

void ExporterObj::ExportNodeDownwardPass(SceneNode&, Mesh& mesh)
{
    size_t geometryCount = 0;
    for (auto& geometry : mesh.GetGeometries())
    {
        m_cancellationToken->CheckCancelledAndThrow();

        *m_geometryStream << "\n";
        *m_geometryStream << "usemtl " << GetUniqueName(*geometry.GetMaterial()) << "\n";
        *m_geometryStream << "o " << GetUniqueName(mesh) << "_geo_" << std::to_string(geometryCount) << "\n";

        auto face = GetFace(geometry);

        if (geometry.HasIndices())
        {
            for (size_t i = 0; i < geometry.GetIndices().size(); i += 3)
            {
                WriteVertex(geometry, geometry.GetIndices()[i]);
                WriteVertex(geometry, geometry.GetIndices()[i + 1]);
                WriteVertex(geometry, geometry.GetIndices()[i + 2]);
                *m_geometryStream << face;
            }
        }
        else
        {
            for (size_t i = 0; i < geometry.GetPositions().size(); i += 3)
            {
                WriteVertex(geometry, i);
                WriteVertex(geometry, i + 1);
                WriteVertex(geometry, i + 2);
                *m_geometryStream << face;
            }
        }

        geometryCount++;
    }
}

void Spectre::Transcoder::ExporterObj::WriteVertex(const Geometry& geometry, size_t index)
{
    auto transform = GetGlobalTransform();

    auto position = Vector3::Transform(geometry.GetPositions()[index], transform);
    *m_geometryStream << "v " << position.x << " " << position.y << " " << position.z << "\n";

    if (geometry.HasUv0s())
    {
        auto uv = geometry.GetUv0s()[index];
        *m_geometryStream << "vt " << uv.x << " " << 1 - uv.y << "\n";
    }

    if (geometry.HasNormals())
    {
        auto normal = Vector3::TransformNormal(geometry.GetNormals()[index], transform);
        normal.Normalize();
        *m_geometryStream << "vn " << normal.x << " " << normal.y << " " << normal.z << "\n";
    }
}

void Spectre::Transcoder::ExporterObj::ExportLeaf(MaterialDescriptor& material)
{
    auto result = m_exportedMaterials.insert(material.GetId());
    if (!result.second)
    {
        // Material was already exported, do nothing
        return;
    }

    auto materialName = GetUniqueName(material);
    *m_materialStream << "newmtl " << materialName << "\n";

    auto layerPair = material.GetOrGenerateSpecGloss();

    auto& diffuseLayer = layerPair.Albedo;
    if (diffuseLayer)
    {
        auto diffuseColor = *diffuseLayer->Color;
        *m_materialStream << "Kd " << diffuseColor.R() << " " << diffuseColor.G() << " " << diffuseColor.B() << "\n";
        *m_materialStream << "d " << diffuseColor.A() << "\n";

        if (diffuseLayer->Texture)
        {
            *m_materialStream << "map_Kd " << ExportTexture(*diffuseLayer->Texture) << "\n";
        }
    }

    auto& specularLayer = layerPair.Workflow;
    if (specularLayer)
    {
        auto specularColor = *specularLayer->Color;
        *m_materialStream << "Ks " << specularColor.R() << " " << specularColor.G() << " " << specularColor.B() << "\n";
        *m_materialStream << "Ns " << SmoothnessToSpecularPower(specularColor.A()) << "\n";

        if (specularLayer->Texture)
        {
            *m_materialStream << "map_Ks " << ExportTexture(*specularLayer->Texture) << "\n";
        }
    }

    auto normalLayer = material.GetLayer(LayerType::kNormal);
    if (normalLayer && normalLayer->Texture)
    {
        *m_materialStream << "bump " << ExportTexture(*normalLayer->Texture) << "\n";
    }

    auto emissiveLayer = material.GetLayer(LayerType::kEmissive);
    if (emissiveLayer && emissiveLayer->Texture)
    {
        *m_materialStream << "map_Ke " << ExportTexture(*emissiveLayer->Texture) << "\n";
    }
}

std::string Spectre::Transcoder::ExporterObj::ExportTexture(TextureDescriptor& texture)
{
    auto uniqueName = GetUniqueName(texture) + ".png";

    auto result = m_exportedTextures.insert(texture.GetId());
    if (!result.second)
    {
        // Texture was already exported, do nothing
        return uniqueName;
    }

    auto pngBuffer = texture.EncodeToPNG();
    auto stream = m_streamFactory->CreateStream(uniqueName);

    stream->write(reinterpret_cast<char*>(pngBuffer.data()), pngBuffer.size());

    return uniqueName;
}

std::string Spectre::Transcoder::ExporterObj::GetUniqueName(const ITraversableWithName& element)
{
    auto result = m_uniqueNames.insert({ element.GetId(), "" });
    if (result.second)
    {
        auto name = GetSanitizedName(element.GetName());
        if (name.empty())
        {
            name = element.GetIdString();
        }

        auto nameIsUniqueFn = [&](const std::string& name)
        {
            for (const auto& item : m_uniqueNames)
            {
                if (item.second == name)
                {
                    return false;
                }
            }
            return true;
        };

        while (!nameIsUniqueFn(name))
        {
            name += "+";
        }

        result.first->second = name;
    }

    return result.first->second;
}