/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace Babylon
{
    namespace Transcoder
    {
        enum CoordinateType {
            RIGHT,
            LEFT
        };
    }
}

/// define the coordinate type of work
#define _COLLADA_COORDINATE_TYPE Babylon::Transcoder::CoordinateType::RIGHT
#define _ASSET3D_COORDINATE_TYPE Babylon::Transcoder::CoordinateType::RIGHT

/// options
#define _BASEPATH_OPTION_KEY "basepath"

