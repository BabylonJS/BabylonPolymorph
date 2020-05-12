/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <d3d11.h>

namespace CanvasTex
{
namespace Internal
{

// Creates a DirectX Adapter for use of BC7 Compression
// Adapter chosen will support at least DirectX level 10 and Compute Shaders.
// returns false If no suitable adapter is available.
bool CreateDXDevice(ID3D11Device** pDevice);

}  // namespace Internal
}  // namespace CanvasTex
