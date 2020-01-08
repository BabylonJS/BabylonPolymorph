/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.        *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/SceneWriter.h>

#include <functional>
#include <vector>

#include <Framework/SceneSegment.h>
#include <Framework/FormatWriterUtils.h>

namespace Spectre
{
    namespace Framework
    {
        namespace V1
        {

            class SPECTRESDK_API SceneWriter : public ISceneWriter, public CommonFrameWriter
            {
            private:
                static const uint32_t sVERSION = 1;

            public:
                SceneWriter();
                virtual ~SceneWriter();

                virtual void BeginFrame(
                    const std::shared_ptr<IBuffer>& outputBuffer,
                    int numItems,
                    EByteOrder byteOrder) override;

                virtual Frame* EndFrame() override;

                virtual void AddScene(const SceneDefinition& scene) override;
                virtual void AddLight(const LightDefinition& light) override;
                virtual void AddCamera(const CameraDefinition& camera) override;

                virtual uint32_t GetVersion() const override
                {
                    return sVERSION;
                }


            private:
                int m_scenesAdded = 0;
                int m_lightsAdded = 0;
                int m_camerasAdded = 0;
            };


            SceneWriter::SceneWriter()
            {
            }

            //---------------------------------------------------------------------
            SceneWriter::~SceneWriter()
            {
            }

            //---------------------------------------------------------------------
            void SceneWriter::BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                int itemCount,
                EByteOrder byteOrder)
            {
                this->DoReset();
                this->DoBeginFrame(outputBuffer, itemCount, byteOrder, kFrameScene);

                m_scenesAdded = 0;
                m_lightsAdded = 0;
                m_camerasAdded = 0;
            }

            void SceneWriter::AddScene(const SceneDefinition& sceneDefinition)
            {
                m_numItems++;
                if (m_numItems > m_expectedItemCount)
                {
                    throw Utils::SpectreFailException("SceneWriter::AddScene: too many items added");
                }

                m_outputBuffer->ReserveSpace(sizeof(SceneDefinition), 4);
                uint32_t sceneOffset = m_outputBuffer->WriteDataRaw(&sceneDefinition, sizeof(SceneDefinition), 4);
                SceneDefinition* scene = static_cast<SceneDefinition*>(m_outputBuffer->GetBuffer(sceneOffset));
                scene->Version = m_byteSwapU16(SceneDefinition::kVersion0);
                scene->Type = SceneItemCommonHeader::ESceneItemType::kScene;
                scene->ScaleFactor = m_byteSwapFloat(scene->ScaleFactor);
                scene->SystemUnit = m_byteSwapFloat(scene->SystemUnit);

                m_savedItemOffsets.push_back(sceneOffset);

                m_scenesAdded++;
            }

            //---------------------------------------------------------------------
            Frame* SceneWriter::EndFrame()
            {
                return this->DoEndFrame();
            }

            //---------------------------------------------------------------------
            void SceneWriter::AddLight(
                const LightDefinition& lightDefinition)
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("SceneWriter::AddLight: You must call BeginFrame() before AddLight()");
                }

                m_numItems++;
                m_lightsAdded++;

                if (m_numItems > m_expectedItemCount)
                {
                    throw Utils::SpectreFailException("SceneWriter::AddLight: too many items added");
                }

                m_outputBuffer->ReserveSpace(sizeof(LightDefinition), 4);
                auto offset = m_outputBuffer->WriteDataRaw(&lightDefinition, sizeof(lightDefinition), 4);
                LightDefinition* light = static_cast<LightDefinition*>(m_outputBuffer->GetBuffer(offset));

                light->Version = m_byteSwapU16(light->kVersion0);
                light->SceneItemCommonHeader::Type = SceneItemCommonHeader::ESceneItemType::kLight;
                light->Type = light->Type;
                light->LightID = m_byteSwapU32(light->LightID);
                light->ParentID = m_byteSwapU32(light->ParentID);
                light->ColorRed = m_byteSwapFloat(light->ColorRed);
                light->ColorGreen = m_byteSwapFloat(light->ColorGreen);
                light->ColorBlue = m_byteSwapFloat(light->ColorBlue);
                light->Intensity = m_byteSwapFloat(light->Intensity);
                light->Radius = m_byteSwapFloat(light->Radius);
                light->Angle = m_byteSwapFloat(light->Angle);

                m_savedItemOffsets.push_back(offset);
            }

            void SceneWriter::AddCamera(
                const CameraDefinition& cameraDefinition)
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("SceneWriter::AddCamera: You must call BeginFrame() before AddCamera()");
                }

                m_numItems++;
                m_camerasAdded++;

                if (m_numItems > m_expectedItemCount)
                {
                    throw Utils::SpectreFailException("SceneWriter::AddCamera: too many items added");
                }

                m_outputBuffer->ReserveSpace(sizeof(CameraDefinition), 4);
                auto offset = m_outputBuffer->WriteDataRaw(&cameraDefinition, sizeof(cameraDefinition), 4);
                CameraDefinition* camera = static_cast<CameraDefinition*>(m_outputBuffer->GetBuffer(offset));
                camera->Version = m_byteSwapU16(camera->kVersion0);
                camera->Type = SceneItemCommonHeader::ESceneItemType::kCamera;

                m_savedItemOffsets.push_back(offset);
            }

        } // Namespace V1

        SPECTRESDK_API ISceneWriter* SceneWriterCreate()
        {
            return new V1::SceneWriter();
        }

        SPECTRESDK_API void SceneWriterDestroy(ISceneWriter*& pWriter)
        {
            SpectreAssert(pWriter != nullptr);

            delete pWriter;
            pWriter = nullptr;
        }


    }//Namespace Framework

}// Namespace Spectre
