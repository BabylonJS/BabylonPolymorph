/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <CanvasTex/TextureMetadata.h>

#include <DirectXTex.h>

namespace CanvasTex
{

class TextureMetadataBase::TextureMetadataImplementation : public ::DirectX::TexMetadata
{
};

}  // namespace CanvasTex
