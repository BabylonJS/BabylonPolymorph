/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <Transcoders.h>
#include <JTSDK/IConsumer.h>
#include <TranscoderJT/TranscoderJTConfig.h>
#include <TranscoderJT/MeshBuilder.h>

namespace Babylon
{
    namespace Transcoder
    {
        typedef int JTUniqueId;

        class JTToAsset3DConsumer : JTSDK::IConsumer {

            std::map<JTUniqueId, std::shared_ptr<MeshBuilder<JTToAsset3DConsumer>>> m_meshLibrary;
            std::map<JTUniqueId, std::shared_ptr<SceneNode>> m_nodeLibrary;

        public:
            JTToAsset3DConsumer() :JTSDK::IConsumer() {
            }
            ~JTToAsset3DConsumer(){
            }

            std::map<JTUniqueId, std::shared_ptr<MeshBuilder<JTToAsset3DConsumer>>>& GetMeshLibrary() {
                return m_meshLibrary;
            }

            int ConsumeAssembly(JtkAssembly* CurrNode);
            int ConsumePart(JtkPart* CurrNode);
            int ConsumeInstance(JtkInstance* CurrNode);

            std::shared_ptr<Asset3D> ProduceAsset3D();
        };
    }
}
