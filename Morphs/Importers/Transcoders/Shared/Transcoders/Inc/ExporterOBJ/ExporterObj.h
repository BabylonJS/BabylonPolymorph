/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <sstream>
#include <stack>
#include <unordered_set>

#include <Asset3D/Asset3D.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>
#include <PluginSDK/ExporterBase.h>
#include <PluginSDK/IOutputStreamFactory.h>

namespace Spectre
{
    namespace Transcoder
    {
        class ExporterObj : public ExporterBase
        {
        public:
            static void ExportStatic(Asset3DPtr asset3D, const std::string& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress = nullptr, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {});

            ExporterObj(std::string name, IOutputStreamFactory* streamFactory, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr);

            virtual void ExportNodeDownwardPass(Asset3D& asset) override;
            virtual void ExportNodeDownwardPass(SceneNode& sceneNode) override;
            virtual void ExportNodeDownwardPass(SceneNode& sceneNode, Mesh& mesh) override;
            virtual void ExportLeaf(MaterialDescriptor& material) override;

            std::string ExportTexture(TextureDescriptor& texture);

        protected:
            void WriteVertex(const Geometry& geometry, size_t index);
            std::string GetUniqueName(const ITraversableWithName& element);

            std::string m_name;
            IOutputStreamFactory* m_streamFactory;
            Framework::ICancellationTokenPtr m_cancellationToken;

            std::shared_ptr<std::ostream> m_geometryStream;
            std::shared_ptr<std::ostream> m_materialStream;

            std::unordered_set<uint32_t> m_exportedMaterials;
            std::unordered_set<uint32_t> m_exportedTextures;

            std::unordered_map<uint32_t, std::string> m_uniqueNames;
        };
    }
}
