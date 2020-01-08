/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
#pragma once

#include <Framework/IBuffer.h>
#include <Framework/Types.h>
#include <Framework/MemoryBuffer.h>
#include <Framework/SceneSegment.h>

#include <CoreUtils/SpectreSDK.h>

#include <cstdint>
#include <memory>

namespace Spectre
{
    namespace Framework
    {
        /**
        * Use the ISceneWriter to help you serialize out scene data (e.g. cameras and lights)
        * into the common object format.
        */
        class SPECTRESDK_API ISceneWriter
        {

        public:
            virtual ~ISceneWriter() {}

            virtual void BeginFrame(
                const std::shared_ptr<IBuffer>& outputBuffer,
                int itemCount,
                EByteOrder byteOrder) = 0;

            virtual Frame* EndFrame() = 0;

            virtual void AddScene(const SceneDefinition& scene) = 0;
            virtual void AddLight(const LightDefinition& light) = 0;
            virtual void AddCamera(const CameraDefinition& camera) = 0;

            virtual uint32_t GetVersion() const = 0;
        };

        SPECTRESDK_API ISceneWriter* SceneWriterCreate();
        SPECTRESDK_API void SceneWriterDestroy(ISceneWriter*& pWriter);


    } // End namespace Cool

} // End namespace Spectre
