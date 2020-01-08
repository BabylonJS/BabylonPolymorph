/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsWinRtPch.h"

#include <CoreUtilsWinRT/MathHelpersCX.h>

//--------------------------------------------------------------------------------


namespace Spectre
{

    namespace UtilsWinRT
    {
        WFN::float2 ConvertToCX(Vector2 v)
        {
            return WFN::float2{ v.x, v.y };
        }

        Vector2 ConvertFromCX(WFN::float2 v)
        {
            return Vector2{ v.x, v.y };
        }

        WFN::float3 ConvertToCX(Vector3 v)
        {
            return WFN::float3{ v.x, v.y, v.z };
        }

        Vector3 ConvertFromCX(WFN::float3 v)
        {
            return Vector3{ v.x, v.y, v.z };
        }

        WFN::float4 ConvertToCX(Vector4 v)
        {
            return WFN::float4{ v.x, v.y, v.z, v.w };
        }

        Vector4 ConvertFromCX(WFN::float4 v)
        {
            return Vector4{ v.x, v.y, v.z, v.w };
        }

        WFN::float4 ConvertColorToCX(Color v)
        {
            return WFN::float4{ v.x, v.y, v.z, v.w };
        }

        Color ConvertColorFromCX(WFN::float4 v)
        {
            return Color{ v.x, v.y, v.z, v.w };
        }

        WFN::quaternion ConvertToCX(Quaternion q)
        {
            return WFN::quaternion{ q.x, q.y, q.z, q.w };
        }

        Quaternion ConvertFromCX(WFN::quaternion q)
        {
            return Quaternion{ q.x, q.y, q.z, q.w };
        }

        WFN::float4x4 ConvertToCX(Matrix m)
        {
            return WFN::float4x4
            {
                m._11, m._12, m._13, m._14,
                m._21, m._22, m._23, m._24,
                m._31, m._32, m._33, m._34,
                m._41, m._42, m._43, m._44
            };
        }

        Matrix ConvertFromCX(WFN::float4x4 m)
        {
            return Matrix
            {
                m.m11, m.m12, m.m13, m.m14,
                m.m21, m.m22, m.m23, m.m24,
                m.m31, m.m32, m.m33, m.m34,
                m.m41, m.m42, m.m43, m.m44,
            };
        }
    }
}


//--------------------------------------------------------------------------------
