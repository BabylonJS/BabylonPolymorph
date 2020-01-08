/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

/**
* \file      MathHelpersCX.h
* \brief     MathHelpersCX interface
* \copyright Copyright (C) Microsoft. All rights reserved.
*
* This file contains various helper functions for creating CX interfaces and converting
* data types between C++/CX and native C++ representations.
*/


//-------------------------------------------------------------------

#include <collection.h>
#include <WindowsNumerics.h>

#include <CoreUtils/Math/SimpleMath.h>

namespace Spectre
{

namespace UtilsWinRT
{

//-------------------------------------------------------------------

namespace WFN = Windows::Foundation::Numerics;
using namespace Utils::Math;

//-------------------------------------------------------------------

WFN::float2         ConvertToCX(Vector2 v);
Vector2             ConvertFromCX(WFN::float2 v);

WFN::float3         ConvertToCX(Vector3 v);
Vector3             ConvertFromCX(WFN::float3 v);

WFN::float4         ConvertToCX(Vector4 v);
Vector4             ConvertFromCX(WFN::float4 v);

WFN::float4         ConvertColorToCX(Color v);
Color               ConvertColorFromCX(WFN::float4 v);

WFN::quaternion     ConvertToCX(Quaternion q);
Quaternion          ConvertFromCX(WFN::quaternion q);

WFN::float4x4       ConvertToCX(Matrix m);
Matrix              ConvertFromCX(WFN::float4x4 v);
}
}

//-------------------------------------------------------------------
