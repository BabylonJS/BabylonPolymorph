//
// Copyright (C) Microsoft.  All rights reserved.
//

#include "GliIncludes.h"

namespace CanvasTex
{
    class ConstImage;

    gli::texture2d DecompressBc1Unorm(const ConstImage& cImage);
    gli::texture2d DecompressBc2Unorm(const ConstImage& cImage);
    gli::texture2d DecompressBc3Unorm(const ConstImage& cImage);
}
