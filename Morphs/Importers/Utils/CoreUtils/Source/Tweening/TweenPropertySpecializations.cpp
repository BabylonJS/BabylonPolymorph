
#include "../CoreUtilsPch.h"
#include <CoreUtils/Tweening/TweenPropertySpecializations.h>
#include <CoreUtils/Math/BabylonMath.h>

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {

            //--------------------------------------------------------------------------------//
            //-----------------------Interpolate Template Specializations---------------------//
            //--------------------------------------------------------------------------------//

            /// \brief Interpolation function for Vector2 type
            template<>
            Math::Vector2 Interpolate(Math::Vector2 from, Math::Vector2 to, double remappedTime)
            {
                return Math::Vector2(
                    RoundToNearestRepresentable<float>((to.x - from.x) * remappedTime + from.x),
                    RoundToNearestRepresentable<float>((to.y - from.y) * remappedTime + from.y));
            }

            //--------------------------------------------------------------------------------

            /// \brief Interpolation function for Vector3 type
            template<>
            Math::Vector3 Interpolate(Math::Vector3 from, Math::Vector3 to, double remappedTime)
            {
                return Math::Vector3(
                    RoundToNearestRepresentable<float>((to.x - from.x) * remappedTime + from.x),
                    RoundToNearestRepresentable<float>((to.y - from.y) * remappedTime + from.y),
                    RoundToNearestRepresentable<float>((to.z - from.z) * remappedTime + from.z));
            }

            //--------------------------------------------------------------------------------

            /// \brief Interpolation function for Vector4 type
            template<>
            Math::Vector4 Interpolate(Math::Vector4 from, Math::Vector4 to, double remappedTime)
            {
                return Math::Vector4(
                    RoundToNearestRepresentable<float>((to.x - from.x) * remappedTime + from.x),
                    RoundToNearestRepresentable<float>((to.y - from.y) * remappedTime + from.y),
                    RoundToNearestRepresentable<float>((to.z - from.z) * remappedTime + from.z),
                    RoundToNearestRepresentable<float>((to.w - from.w) * remappedTime + from.w));
            }

            //--------------------------------------------------------------------------------

            /// \brief Interpolation function for Quaternion type
            template<>
            Math::Quaternion Interpolate(Math::Quaternion from, Math::Quaternion to, double remappedTime)
            {
                return Math::Quaternion::Slerp(from, to, static_cast<float>(remappedTime));
            }

            //--------------------------------------------------------------------------------

            template<>
            Math::Color Interpolate(Math::Color from, Math::Color to, double remappedTime)
            {
                return Math::Color((to - from) * static_cast<float>(remappedTime) + from);
            }

            /// \brief Interpolation function for EulerRotation type
            template<>
            Math::RotationEulerAngles Interpolate(Math::RotationEulerAngles from, Math::RotationEulerAngles to, double remappedTime)
            {
                // Little bit wordy. It is obviously clear what is happening here.
                // Basically identical to Vector3 interpolation
                float pitch = RoundToNearestRepresentable<float>((to.x - from.x) * remappedTime + from.x);
                float yaw   = RoundToNearestRepresentable<float>((to.y - from.y) * remappedTime + from.y);
                float roll  = RoundToNearestRepresentable<float>((to.z - from.z) * remappedTime + from.z);

                Math::RotationEulerAngles rotation;
                rotation.SetPitch(pitch);
                rotation.SetYaw(yaw);
                rotation.SetRoll(roll);
                return rotation;
            }

            // Modifies the 'to' angle so that it is the equivalent angle that is closest to the 'from' angle (modulo 360)
            float NearestAngle(float fromDegrees, float toDegrees)
            {
                float delta = toDegrees - fromDegrees;
                return fromDegrees + Babylon::Utils::Math::NormalizeAngleDegrees(delta);
            }

            //--------------------------------------------------------------------------------//
            //-----------------------PreProcess Template Specializations----------------------//
            //--------------------------------------------------------------------------------//

            template<>
            void ApplyTweenPreprocess(Babylon::Utils::Math::Quaternion& from, Babylon::Utils::Math::Quaternion& to, Babylon::Utils::Tweening::TweenDirection direction)
            {
                if (direction == TweenDirection::Shortest)
                {
                    if (from.Dot(to) < 0.0f)
                    {
                        from = -from;
                    }
                }
            }


            template<>
            void ApplyTweenPreprocess(Babylon::Utils::Math::RotationEulerAngles& from, Babylon::Utils::Math::RotationEulerAngles& to, Babylon::Utils::Tweening::TweenDirection direction)
            {
                if (direction == TweenDirection::Shortest)
                {
                    // Adjust the 'to' to be closest to the 'from' values:
                    to.x = NearestAngle(from.x, to.x);
                    to.y = NearestAngle(from.y, to.y);
                    to.z = NearestAngle(from.z, to.z);
                }
            }

            //--------------------------------------------------------------------------------

        }// end Tweening
    }// end Utils
}// end Babylon
