//-------------------------------------------------------------------------------------
// SimpleMath.h -- Simplified C++ Math wrapper for DirectXMath
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

#pragma once

#if !defined(COREUTILS_MATH_H_INCLUDED)
#define COREUTILS_MATH_H_INCLUDED

#if !defined(COREUTILS_SIMPLEMATH_H_INCLUDED)
#include <CoreUtils/Math/SimpleMath.h>
#endif // COREUTILS_SIMPLEMATH_H_INCLUDED

#if !defined(COREUTILS_ASSERT_H_INCLUDED)
#include <CoreUtils/Assert.h>
#endif // COREUTILS_ASSERT_H_INCLUDED

/// BabylonMath.h
/// It's a utility file that includes SimpleMath
/// add adds few function overloads for double type

namespace Babylon
{

namespace Utils
{

namespace Math
{

struct RotationEulerAngles;
struct RotationAxisAngle;

inline double Min(double a, double b) { return std::fmin(a, b); }
inline double Max(double a, double b) { return std::fmax(a, b); }
inline double Min(double a, double b, double c) { return Min(Min(a, b), c); }
inline double Max(double a, double b, double c) { return Max(Max(a, b), c); }
inline double Clamp(double value, double min, double max) { return Min(Max(value, min), max); }

/// Performs saturation operation to clamp the input to the range [0,1].
inline float Saturate(float x)
{
    return Clamp(x, 0.0f, 1.0f);
}

/// Returns the fractional part in range [0,1] of input 'x', defined as: x - floor(x).
inline float Fraction(float x) { return x - std::floorf(x); }

/// Returns the fractional part in range [0,1] of input 'x', defined as: x - floor(x).
inline double Fraction(double x) { return x - std::floor(x); }

/// Returns the interpolation from starting value 'a' towards final value 'b' evaluated at parametric time 't'.
inline Babylon_CONSTEXPR float Interpolate(float a, float b, float t)
{
    // Note: a*(1-t)+b*t is used rather than the slightly simpler fused-multiply-add form: (b-a)*t+a
    // so that 'a' and 'b' are returned when 't' is zero or one.
    return a * (1.0f - t) + b * t;
}

/// Returns true if x is a power of 2, false otherwise (including when x is zero)
inline Babylon_CONSTEXPR bool IsPowerOfTwo(size_t x)
{
    return x && !(x & (x - 1U));
}

/// \brief
/// Rounds the input down (towards positive infinity) to next integer then optionally converts to the output type.
/// Example: RoundDown<int>(2.7f) returns 2; RoundDown<int>(-2.7f) returns -3.
template<typename OutputType = float>
inline OutputType RoundDown(float x) { return static_cast<OutputType>(std::floorf(x)); }

/// \brief
/// Rounds the input up (towards positive infinity) to next integer then optionally converts to the output type.
/// Example: RoundUp<int>(2.7f) returns 3; RoundUp<int>(-2.7f) returns -2.
template<typename OutputType = float>
inline OutputType RoundUp(float x) { return static_cast<OutputType>(std::ceilf(x)); }

/// \brief
/// Rounds the input to closest integer then optionally converts to the output type.
/// Example: RoundNearest<int>(2.7f) returns 3; RoundNearest<int>(-2.7f) returns -3.
template<typename OutputType = float>
inline OutputType RoundNearest(float x) { return static_cast<OutputType>(std::roundf(x)); }

/// \brief
/// Rounds the input to next integer towards zero then optionally converts to the output type.
/// Example: RoundTowardsZero<int>(2.7f) returns 2; RoundTowardsZero<int>(-2.7f) returns -2.
template<typename OutputType = float>
inline OutputType RoundTowardsZero(float x) { return static_cast<OutputType>(std::truncf(x)); }

/// Returns the input angle in degrees normalized to the equivalent angle in the range [-180,+180] via range reduction modulo 360 degrees.
inline float NormalizeAngleDegrees(float x) { return std::remainder(x, 360.0f); }

/// Returns the input angle in degrees normalized to the equivalent angle in the range [-pi,+pi] via range reduction modulo 2*pi radians.
inline float NormalizeAngleRadians(float x) { return std::remainder(x, kTwoPi); }

inline Vector3 operator* (const Quaternion& quaternion, Vector3 vector)
{
    Vector3 quaternionXYZ = Vector3(quaternion.x, quaternion.y, quaternion.z);
    Vector3 quaternionWWW = Vector3(quaternion.w, quaternion.w, quaternion.w);
    Vector3 result = quaternionXYZ.Cross(vector);
    result += quaternionWWW * vector;
    result = quaternionXYZ.Cross(result);
    return 2.0f * result + vector;
}

/// Checks to see that all elements of the matrix are finite.
/// If one or more elements of the matrix are either NaN or infinite this function will return false.
inline bool MatrixIsFinite(const Matrix& matrix)
{
    float accumulatedMatrix = matrix[0];
    // accumulate all 16 elements of the 4 x 4 matrix
    for (int i = 1; i < 16; i++)
    {
        accumulatedMatrix += matrix[i];
    }
    return isfinite(accumulatedMatrix);
}

/// Checks to see that a matrix is affine. i.e. The elements of the 4th column must be equal to {0, 0, 0, 1} in that order.
/// An affine matrix preserves points, straight lines and planes. All parallel lines remain parallel after transformation.
inline Babylon_CONSTEXPR bool MatrixIsAffine(const Matrix& matrix)
{
    return matrix._14 == 0.0f && matrix._24 == 0.0f && matrix._34 == 0.0f && matrix._44 == 1.0f;
}

/// Checks to see that all elements of the Vector3 are finite.
/// If one or more elements of the Vector3 are either NaN or infinite this function will return false.
inline bool VectorIsFinite(const Vector3& vector)
{
    return isfinite(vector.x + vector.y + vector.z);
}

/// Checks to see that all elements of the Vector4 are finite.
/// If one or more elements of the Vector4 are either NaN or infinite this function will return false.
inline bool VectorIsFinite(const Vector4& vector)
{
    return isfinite(vector.x + vector.y + vector.z + vector.w);
}

/// Checks to see that all elements of the Color are finite.
/// If one or more elements of the Color are either NaN or infinite this function will return false.
inline bool ColorIsFinite(const Color& color)
{
    return isfinite(color.R() + color.G() + color.B() + color.A());
}

//------------------------------------------------------------------------------
// RotationEulerAngles

/// \brief
/// RotationEulerAngles stores a rotation as euler angles
///
/// We know that when we calculate a quaternion from EulerAngles
/// XMQuaternionRotationRollPitchYaw interprets the values as such
///
/// Pitch = Rotation around the x-axis
/// Yaw   = Rotation around the y-axis
/// Roll  = Rotation around the z-axis
///
/// We also know that the function applies the rotations in the order
/// stated in the function
///
/// (Roll * Pitch) * Yaw
/// Since quaternions are non-commutative the order in which the multiplications
/// are performed affects the final output.
///
/// The rotations are performed about the stationary world x, y and z axis
/// rather than the local object axes.
///
/// All of these differences affect how we calculate the EulerRotation from the given
/// Quaternion.
struct RotationEulerAngles : public DirectX::XMFLOAT3
{
    Babylon_CONSTEXPR RotationEulerAngles() : DirectX::XMFLOAT3(0.f, 0.f, 0.f) {}

    inline explicit RotationEulerAngles(const Quaternion& q);

    inline Matrix GetMatrix() const;
    inline Quaternion GetQuaternion() const;

    /// Normalize unwinds the rotation making all angles fit in the range
    /// [-180, 180] degrees.
    void Normalize();

    /// Get the pitch angle in degrees.
    float GetPitch() const { return x; }
    /// Get the yaw angle in degrees
    float GetYaw() const { return y; }
    /// Get the roll angle in degrees
    float GetRoll() const { return z; }

    /// Set the pitch to given angle in degrees.
    void SetPitch(float pitch) { x = pitch; }
    /// Set the yaw to the given angle in degrees.
    void SetYaw(float yaw) { y = yaw; }
    /// Set the roll to the given angle in degrees.
    void SetRoll(float roll) { z = roll; }
};

//------------------------------------------------------------------------------
// AxisAngleRotation

struct RotationAxisAngle
{
    Babylon_CONSTEXPR RotationAxisAngle() : Axis(1.0f, 0.0f, 0.0f), Angle(0.0f) {}

    /// Creates a RotationAxisAngle from given axis and angle in radians
    explicit RotationAxisAngle(Vector3 axis, float angle) : Axis(axis), Angle(angle)
    {
        Axis.Normalize();
    }

    // Create an AxisAngle rotation from a quaternion.
    explicit RotationAxisAngle(Quaternion quaternion);

    /// Normalize the rotation angle to be in range [-pi,pi] providing equivalent rotation to the original.
    void Normalize();

    inline Matrix GetMatrix() const;
    inline Quaternion GetQuaternion() const;

    Vector3 Axis;

    // Returns the angle of the rotation in radians.
    float Angle;
};

inline Matrix RotationAxisAngle::GetMatrix() const
{
    return Matrix::CreateFromAxisAngle(Axis, Angle);
}

inline Matrix RotationEulerAngles::GetMatrix() const
{
    return Matrix::CreateFromYawPitchRoll(
        DegreesToRadians(GetYaw()),
        DegreesToRadians(GetPitch()),
        DegreesToRadians(GetRoll()));
}

inline Quaternion RotationAxisAngle::GetQuaternion() const
{
    return Quaternion::CreateFromAxisAngle(Axis, Angle);
}

inline Quaternion RotationEulerAngles::GetQuaternion() const
{
    return Quaternion::CreateFromYawPitchRoll(
        DegreesToRadians(GetYaw()),
        DegreesToRadians(GetPitch()),
        DegreesToRadians(GetRoll()));
}


/****************************************************************************
*
* EulerRotation
*
****************************************************************************/

inline RotationEulerAngles::RotationEulerAngles(const Quaternion& q)
{
    /* Conversion here from Quaternion to Euler angles.
    // Reference:
    Dunn, F. and Parberry I. 2011. 3D Math Primer for Graphics and Game Development

    // Need to check for  singularity case where pitch is near 90 degrees
    // or south pole. Using formula -2.0f * (y*z - w*x) = SP we can determine whether the quaternion
    // is oriented at a pole. Here are the cases:
    //
    // SP = 1.0
    // Quaternion points straight up (North pole)
    //
    // P = -1.0
    // Quaternion points straight down (South pole)

    // In these cases
    //    South: Yaw = -2 * atan2(qx, qw)
    //    North: Yaw = 2 * atan2(qx, qw)

    // This code makes the assumption that q is a unit(normalised)
    // quaternion. We can perform this operation before
    // hand however I think we should keep this operation
    // as simple as possible. It is the clients job to
    // ensure that the quaternion has been normalised
    // before creating an EulerRotation
    */
    //Fix for Warning C4458 : declaration of variables (x, y, z) hides class members

    float qx = q.x;
    float qy = q.y;
    float qz = q.z;
    float qw = q.w;

    float sp = -2.0f * (qy*qz - qw*qx);

    float pitch = 0.0f;
    float yaw = 0.0f;
    float roll = 0.0f;

    if (std::abs(sp) > 0.99999f)
    {
        pitch = kHalfPi * sp;
        yaw = atan2(-qx*qz + qw*qy, 0.5f - qy*qy - qz*qz);
    }
    else
    {
        pitch = asin(sp);
        yaw = atan2(qx*qz + qw*qy, 0.5f - qx*qx - qy*qy);
        roll = atan2(qx*qy + qw*qz, 0.5f - qx*qx - qz*qz);
    }

    // All angles now calculated but stored as radians.
    // Now we store the resulting angles while converting
    // to degrees.

    // Order of rotations (intrinsic)
    SetYaw(RadiansToDegrees(yaw));        // y axis
    SetPitch(RadiansToDegrees(pitch));    // x axis
    SetRoll(RadiansToDegrees(roll));      // z axis
}

// Should this go in a Math.inl, this file is currently small but could
// grow quite quickly.
/****************************************************************************
*
* AxisAngleRotation
*
****************************************************************************/

inline RotationAxisAngle::RotationAxisAngle(Quaternion quaternion)
{
    quaternion.Normalize();

    Angle = 2.0f * acos(quaternion.w);
    float s = sqrt(1.0f - (quaternion.w*quaternion.w));
    if (s < 0.001f) // When angle close to zero degrees axis really doesn't matter.
    {
        // if s is close to zero then direction of axis is not important.
        // However we try and recover the given axis.
        Axis.x = 1.0f;
        Axis.y = 0.0f;
        Axis.z = 0.0f;
    }
    else
    {
        Axis.x = quaternion.x / s;
        Axis.y = quaternion.y / s;
        Axis.z = quaternion.z / s;
    }
}

inline void RotationAxisAngle::Normalize()
{
    Angle = NormalizeAngleRadians(Angle);
}

inline void RotationEulerAngles::Normalize()
{
    x = NormalizeAngleDegrees(x);
    y = NormalizeAngleDegrees(y);
    z = NormalizeAngleDegrees(z);
}


}
}
}

#endif // COREUTILS_MATH_H_INCLUDED
