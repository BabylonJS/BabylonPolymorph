/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <CoreUtils/Pointers.h>

Babylon_SMART_POINTER_(struct, IPluginFactory);
Babylon_SMART_POINTER(PluginFactoryBase);

namespace Babylon
{
    namespace Framework
    {
        Babylon_SMART_POINTER(AnimationMaker);
        Babylon_SMART_POINTER(DataMaker);
        Babylon_SMART_POINTER(ICancellationToken);
        Babylon_SMART_POINTER(ITextureWriter);
        Babylon_SMART_POINTER(LightMaker);
        Babylon_SMART_POINTER(MaterialMaker);
        Babylon_SMART_POINTER(MeshMaker);
        Babylon_SMART_POINTER(SkeletonMaker);
        Babylon_SMART_POINTER(TextureMaker);
    }

    namespace Utils
    {
        Babylon_SMART_POINTER_(struct, DefaultTimeProvider);
        Babylon_SMART_POINTER(ETWTraceProvider);
        Babylon_SMART_POINTER_(struct, IMemoryStatsProvider);
        Babylon_SMART_POINTER_(struct, ITimeProvider);
        Babylon_SMART_POINTER_(struct, ITraceProvider);
        Babylon_SMART_POINTER(PerformanceLogger);
        Babylon_SMART_POINTER(ITelemetryTraceLogger);
    }
}
