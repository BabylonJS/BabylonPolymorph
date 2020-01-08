/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
namespace Spectre {
    namespace Transcoder {
        enum MtlTextureMapOptions
        {
            NotASupportedOption = 0,
            blendu,
            blendv,
            clamp,
            o,
            s,
            t,
            mm,
            cc,
            boost,
            texres,
            bm,
            imfchan,
        };
    }
}