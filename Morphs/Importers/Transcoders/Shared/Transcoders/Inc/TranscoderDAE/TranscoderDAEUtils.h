/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <COLLADAFWTransformation.h>
#include <COLLADAFWMatrix.h>

namespace Babylon
{
    namespace Transcoder
    {
        COLLADABU::Math::Matrix4 getMatrixFromTransform(const COLLADAFW::Transformation* transform, float assetScale);
    }
}
