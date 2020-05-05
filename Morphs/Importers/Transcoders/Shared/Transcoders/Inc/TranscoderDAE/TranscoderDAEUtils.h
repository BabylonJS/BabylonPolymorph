/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <COLLADAFWTransformation.h>
#include <COLLADAFWMatrix.h>

/**
 * According to COLLADA specification 5-17, All coordinates are righthanded by definition.
 * Valid values are X_UP, Y_UP, or Z_UP.
 * This value specifies which axis is considered upward, which is considered to the right, and which is considered inward.
 * The <up_axis> element’s values have the following meanings:
 *
 * --------------------------------------------------------
 *	Value	|	 Right Axis	|	Up Axis		|	In Axis
 * --------------------------------------------------------
 *	X-UP	|	Negative y	|	Positive x	|	Positive z
 *	Y_UP	|	Positive x	|	Positive y	|	Positive z
 *	Z_UP	|	Positive x	|	Positive z	|	Negative y
 * --------------------------------------------------------
 */

#define __VEC3_TRANSFER_X_UP(ptr,v)  v.y= *(ptr++); v.x = -*(ptr++); v.z = *(ptr);
#define __VEC3_TRANSFER_Y_UP(ptr,v)  v.x= *(ptr++); v.y =  *(ptr++); v.z = *(ptr);
#define __VEC3_TRANSFER_Z_UP(ptr,v)  v.x= *(ptr++); v.z = -*(ptr++); v.y = *(ptr);
#define __VEC3_TRANSFER_NONE(ptr,v) __VEC3_TRANSFER_Z_UP(ptr,v)

#define __VEC3_TRANSFER(u, ptr,v) switch (u) {\
case(COLLADAFW::FileInfo::UpAxisType::X_UP): { __VEC3_TRANSFER_X_UP(ptr, v3_cache0) break; }\
case(COLLADAFW::FileInfo::UpAxisType::Y_UP): { __VEC3_TRANSFER_Y_UP(ptr, v3_cache0) break; }\
case(COLLADAFW::FileInfo::UpAxisType::Z_UP): { __VEC3_TRANSFER_Z_UP(ptr, v3_cache0) break; }\
default: { __VEC3_TRANSFER_NONE(ptr, v3_cache0) break; } }


/// macros could be used to average incrementally vector3
#define __AVERAGE_INC(v,b,n) (b) + ((v) - (b)) / (n)
#define __VEC3_AVERAGE_INC_X_UP(ptr,v,n) v.y = __AVERAGE_INC(*(ptr++), v.y, n); v.x = __AVERAGE_INC(-*(ptr++), v.x, n); v.x = __AVERAGE_INC(*(ptr), v.z, n);
#define __VEC3_AVERAGE_INC_Y_UP(ptr,v,n) v.x = __AVERAGE_INC(*(ptr++), v.x, n); v.y = __AVERAGE_INC( *(ptr++), v.y, n); v.z = __AVERAGE_INC(*(ptr), v.z, n);
#define __VEC3_AVERAGE_INC_Z_UP(ptr,v,n) v.x = __AVERAGE_INC(*(ptr++), v.x, n); v.z = __AVERAGE_INC(-*(ptr++), v.z, n); v.y = __AVERAGE_INC(*(ptr), v.y, n);
#define __VEC3_AVERAGE_INC_NONE(ptr,v,n) __VEC3_AVERAGE_INC_Z_UP(ptr, v,n)


namespace Babylon
{
    namespace Transcoder
    {
        Babylon::Utils::Math::Matrix toBabylonMatrix(COLLADABU::Math::Matrix4 colladaMatrix);
        COLLADABU::Math::Matrix4 getMatrixFromTransform(const COLLADAFW::Transformation* transform, float assetScale);
    }
}
