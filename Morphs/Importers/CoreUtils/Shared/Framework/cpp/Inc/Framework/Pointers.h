/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <CoreUtils/Pointers.h>

SPECTRE_SMART_POINTER_(struct, IPluginFactory);
SPECTRE_SMART_POINTER(PluginFactoryBase);

namespace Spectre
{
    namespace Framework
    {
        SPECTRE_SMART_POINTER(AnimationMaker);
        SPECTRE_SMART_POINTER(DataMaker);
        SPECTRE_SMART_POINTER(ICancellationToken);
        SPECTRE_SMART_POINTER(ITextureWriter);
        SPECTRE_SMART_POINTER(LightMaker);
        SPECTRE_SMART_POINTER(MaterialMaker);
        SPECTRE_SMART_POINTER(MeshMaker);
        SPECTRE_SMART_POINTER(SkeletonMaker);
        SPECTRE_SMART_POINTER(TextureMaker);
    }

    namespace Utils
    {
        SPECTRE_SMART_POINTER_(struct, DefaultTimeProvider);
        SPECTRE_SMART_POINTER(ETWTraceProvider);
        SPECTRE_SMART_POINTER_(struct, IMemoryStatsProvider);
        SPECTRE_SMART_POINTER_(struct, ITimeProvider);
        SPECTRE_SMART_POINTER_(struct, ITraceProvider);
        SPECTRE_SMART_POINTER(PerformanceLogger);
        SPECTRE_SMART_POINTER(ITelemetryTraceLogger);
    }
}
