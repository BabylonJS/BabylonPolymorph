/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <TranscoderJT/TranscoderJTConfig.h>
#include <JtkString.h>
namespace Babylon
{
    namespace Transcoder
    {
        std::string JtkString2String(JtkString src);
        Babylon::Utils::Math::Matrix toBabylonMatrix(JtkTransform* jtkMatrix);
    }
}

