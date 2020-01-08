/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <stack>

#include <Framework/GeometryUtils.h>
#include <Asset3D/Asset3D.h>
#include <PluginSDK/ExporterBase.h>
#include <PluginSDK/IOutputStreamFactory.h>

namespace Spectre
{
    namespace Transcoder
    {
        class ExporterAsciiStl : public ExporterBase
        {
        public:
            static void ExportStatic(Asset3DPtr asset3D, const std::string& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress = nullptr, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {});

            explicit ExporterAsciiStl(std::string assetName, std::ostream& outputStream, Framework::ICancellationTokenPtr cancellationToken = nullptr);

            virtual void ProcessAsset3DBeforeChildren(Asset3D& asset3D) override;
            virtual void ProcessAsset3DAfterChildren(Asset3D& asset3D) override;

            virtual void ProcessMeshBeforeMaterialAndGeometry(SceneNode&, Mesh& mesh) override;

            virtual void ProcessSceneNodeBeforeChildren(SceneNode& sceneNode) override;
            virtual void ProcessSceneNodeAfterChildren(SceneNode& sceneNode) override;

            ~ExporterAsciiStl() override;
        protected:
            std::ostream& m_outputStream;
            std::string m_assetName;
            std::stack<Spectre::Utils::Math::Matrix> m_transforms;
            Framework::ICancellationTokenPtr m_cancellationToken;
        };
    }
}
