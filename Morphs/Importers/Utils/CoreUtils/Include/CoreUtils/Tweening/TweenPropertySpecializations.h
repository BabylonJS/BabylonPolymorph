/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include "ITweenable.h"

#include <CoreUtils/Tweening/TweenProperty.h>

#if !defined(COREUTILS_SIMPLEMATH_H_INCLUDED)
#include <CoreUtils/Math/SimpleMath.h>
#endif // COREUTILS_SIMPLEMATH_H_INCLUDED

#if !defined(COREUTILS_MATH_H_INCLUDED)
#include <CoreUtils/Math/BabylonMath.h>
#endif // COREUTILS_MATH_H_INCLUDED

#if !defined(COREUTILS_SMARTTHROW_H_INCLUDED)
#include <CoreUtils/SmartThrow.h>
#endif // COREUTILS_SMARTTHROW_H_INCLUDED

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

#if !defined(_MEMORY_)
#include <memory>
#endif // _MEMORY_

#include <CoreUtils/Tweening/TweenManager.h>

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {
            //--------------------------------------------------------------------------------

            /// \brief Polar transform that can be attached to tween property of Vector2 type
            class TransformPolar
            {
            public:
                /// Input function converts Vector2 from Cartesian to polar coordinate system
                Math::Vector2  Input(Math::Vector2 value)
                {
                    auto r = sqrt(value.x*value.x + value.y*value.y);
                    auto phi = atan2(value.y, value.x);

                    return Math::Vector2(r, phi);
                }

                /// Output function converts Vector2 back from polar to Cartesian coordinate system
                Math::Vector2  Output(Math::Vector2 value)
                {
                    auto r = value.x;
                    auto phi = value.y;

                    Math::Vector2 vec;
                    vec.x = r * cos(phi);
                    vec.y = r * sin(phi);

                    return vec;
                }
            };

            //--------------------------------------------------------------------------------

            /// \brief Spherical transform that can be attached to tween property of Vector3 type
            class TransformSpherical
            {
            public:
                /// Input function converts Vector2 from Cartesian to spherical coordinate system
                Math::Vector3  Input(Math::Vector3 value)
                {
                    auto r = sqrt(value.x*value.x + value.y*value.y + value.z*value.z);
                    auto theta = acos(value.z / r);
                    auto phi = atan2(value.y, value.x);

                    return Math::Vector3(r, theta, phi);
                }

                /// Output function converts Vector3 back from spherical to Cartesian coordinate system
                Math::Vector3  Output(Math::Vector3 value)
                {
                    auto r = value.x;
                    auto theta = value.y;
                    auto phi = value.z;

                    Math::Vector3 vec;
                    vec.x = r * sin(theta) * cos(phi);
                    vec.y = r * sin(theta) * sin(phi);
                    vec.z = r * cos(theta);

                    return vec;
                }
            };

            //--------------------------------------------------------------------------------

            /// \brief Color transform that can be attached to tween property of Color type
            class TransformColor
            {
            public:
                TransformColor(float exponent)
                {
                    BabylonUnusedParameter(exponent);
                }

                /// Input function applies gamma to Color type
                /// by applying power function of 2^exponent
                Math::Color Input(Math::Color value)
                {
                    return Math::Color(value.R() * pow(2.0f, m_exponent),
                                       value.G() * pow(2.0f, m_exponent),
                                       value.B() * pow(2.0f, m_exponent),
                                       value.A());
                }

                /// Output function applies inverse gamma function
                /// by applying power function of 2 to inverse of exponent
                Math::Color Output(Math::Color value)
                {
                    return Math::Color(value.R() * pow(2.0f, 1.0f / m_exponent),
                                       value.G() * pow(2.0f, 1.0f / m_exponent),
                                       value.B() * pow(2.0f, 1.0f / m_exponent),
                                       value.A());
                }
            private:
                float m_exponent;
            };

            //--------------------------------------------------------------------------------


            //--------------------------------------------------------------------------------//
            //-----------------------Interpolate Template Specializations---------------------//
            //--------------------------------------------------------------------------------//

            /// \brief Interpolation function for Vector2 type
            template<>
            Babylon::Utils::Math::Vector2 Interpolate(Babylon::Utils::Math::Vector2 from, Babylon::Utils::Math::Vector2 to, double remappedTime);

            //--------------------------------------------------------------------------------

            /// \brief Interpolation function for Vector3 type
            template<>
            Babylon::Utils::Math::Vector3 Interpolate(Babylon::Utils::Math::Vector3 from, Babylon::Utils::Math::Vector3 to, double remappedTime);

            //--------------------------------------------------------------------------------

            /// \brief Interpolation function for Vector4 type
            template<>
            Babylon::Utils::Math::Vector4 Interpolate(Babylon::Utils::Math::Vector4 from, Babylon::Utils::Math::Vector4 to, double remappedTime);

            //--------------------------------------------------------------------------------

            /// \brief Interpolation function for Quaternion type
            template<>
            Babylon::Utils::Math::Quaternion Interpolate(Babylon::Utils::Math::Quaternion from, Babylon::Utils::Math::Quaternion to, double remappedTime);

            //--------------------------------------------------------------------------------

            /// \brief Interpolation function for Color type
            template<>
            Babylon::Utils::Math::Color Interpolate(Babylon::Utils::Math::Color from, Babylon::Utils::Math::Color to, double remappedTime);
            //-------------------------------------------------------------------

            /// \brief Interpolation function for EulerRotation type
            template<>
            Babylon::Utils::Math::RotationEulerAngles Interpolate(Babylon::Utils::Math::RotationEulerAngles from, Babylon::Utils::Math::RotationEulerAngles to, double remappedTime);
            //-------------------------------------------------------------------

            //--------------------------------------------------------------------------------//
            //-----------------------PreProcess Template Specializations----------------------//
            //--------------------------------------------------------------------------------//

            template<>
            void ApplyTweenPreprocess(Babylon::Utils::Math::Quaternion& from, Babylon::Utils::Math::Quaternion& to, Babylon::Utils::Tweening::TweenDirection direction);

            template<>
            void ApplyTweenPreprocess(Babylon::Utils::Math::RotationEulerAngles& from, Babylon::Utils::Math::RotationEulerAngles& to, Babylon::Utils::Tweening::TweenDirection direction);

        }// end Tweening
    }// end Utils
}// end Babylon
