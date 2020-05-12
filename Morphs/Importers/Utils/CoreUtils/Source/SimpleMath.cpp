//-------------------------------------------------------------------------------------
// SimpleMath.cpp -- Simplified C++ Math wrapper for DirectXMath
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// http://go.microsoft.com/fwlink/?LinkId=248929
//-------------------------------------------------------------------------------------

#include "CoreUtilsPch.h"
#include <CoreUtils/Math/SimpleMath.h>

namespace Babylon
{

namespace Utils
{

namespace Math
{
    const Vector2 Vector2::Zero = { 0.f, 0.f };
    const Vector2 Vector2::One = { 1.f, 1.f };
    const Vector2 Vector2::UnitX = { 1.f, 0.f };
    const Vector2 Vector2::UnitY = { 0.f, 1.f };

    const Vector3 Vector3::Zero = { 0.f, 0.f, 0.f };
    const Vector3 Vector3::One = { 1.f, 1.f, 1.f };
    const Vector3 Vector3::UnitX = { 1.f, 0.f, 0.f };
    const Vector3 Vector3::UnitY = { 0.f, 1.f, 0.f };
    const Vector3 Vector3::UnitZ = { 0.f, 0.f, 1.f };
    const Vector3 Vector3::Up = { 0.f, 1.f, 0.f };
    const Vector3 Vector3::Down = { 0.f, -1.f, 0.f };
    const Vector3 Vector3::Right = { 1.f, 0.f, 0.f };
    const Vector3 Vector3::Left = { -1.f, 0.f, 0.f };
    const Vector3 Vector3::Forward = { 0.f, 0.f, -1.f };
    const Vector3 Vector3::Backward = { 0.f, 0.f, 1.f };

    const Vector4 Vector4::Zero = { 0.f, 0.f, 0.f, 0.f };
    const Vector4 Vector4::One = { 1.f, 1.f, 1.f, 1.f };
    const Vector4 Vector4::UnitX = { 1.f, 0.f, 0.f, 0.f };
    const Vector4 Vector4::UnitY = { 0.f, 1.f, 0.f, 0.f };
    const Vector4 Vector4::UnitZ = { 0.f, 0.f, 1.f, 0.f };
    const Vector4 Vector4::UnitW = { 0.f, 0.f, 0.f, 1.f };

    const Matrix Matrix::Identity = { 1.f, 0.f, 0.f, 0.f,
                                        0.f, 1.f, 0.f, 0.f,
                                        0.f, 0.f, 1.f, 0.f,
                                        0.f, 0.f, 0.f, 1.f };

    const Quaternion Quaternion::Identity = { 0.f, 0.f, 0.f, 1.f };

    const Color Color::Black = { 0.0f, 0.0f, 0.0f, 1.0f };
    const Color Color::White = { 1.0f, 1.0f, 1.0f, 1.0f };
    const Color Color::Transparent = { 0.0f, 0.0f, 0.0f, 0.0f };

    Color Color::FromHSB(float hue, float saturation, float brightness)
    {
        float h = Math::Clamp(hue, 0.0f, 360.0f);
        float s = Math::Clamp(saturation / 100.0f, 0.0f, 1.0f);
        float v = Math::Clamp(brightness / 100.0f, 0.0f, 1.0f);

        float r, g, b;

        if (s == 0.0f)
        {
            r = v;
            g = v;
            b = v;
        }
        else
        {
            // sector 0 to 5
            h /= 60.0f;
            int i = static_cast<int>(std::floorf(h));

            // fractional part of h
            float f = h - i;
            float p = v * (1.0f - s);
            float q = v * (1.0f - s * f);
            float t = v * (1.0f - s * (1.0f - f));

            switch (i)
            {
            case 0:
                r = v;
                g = t;
                b = p;
                break;
            case 1:
                r = q;
                g = v;
                b = p;
                break;
            case 2:
                r = p;
                g = v;
                b = t;
                break;
            case 3:
                r = p;
                g = q;
                b = v;
                break;
            case 4:
                r = t;
                g = p;
                b = v;
                break;
            default:        // case 5:
                r = v;
                g = p;
                b = q;
                break;
            }
        }

        return Color(r, g, b, 1.0f);
    }
}
}
}
