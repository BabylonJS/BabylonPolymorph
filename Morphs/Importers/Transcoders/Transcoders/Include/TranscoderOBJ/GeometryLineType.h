/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace Babylon {
    namespace Transcoder {
        enum GeometryLineType
        {
            v = 1,
            vt,
            vn,
            f,
            SmoothingGroupLine,
            mtllib,
            usemtl,
            comment,
        };
    }
}