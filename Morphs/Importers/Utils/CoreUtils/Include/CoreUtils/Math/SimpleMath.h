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

#if !defined(COREUTILS_SIMPLEMATH_H_INCLUDED)
#define COREUTILS_SIMPLEMATH_H_INCLUDED

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <cmath>

#ifdef _WIN32
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>
#else
#include <DirectXMath/DirectXMath.h>
#include <DirectXMath/DirectXPackedVector.h>
#include <DirectXMath/DirectXCollision.h>
#endif

#undef min
#undef max
#undef isnan

#include <memory.h>

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

#if !defined(_ALGORITHM_)
#include <algorithm>
#endif //_ALGORITHM_

#if !defined(Babylon_CONSTEXPR_H)
#include <CoreUtils/BabylonConstExpr.h>
#endif // Babylon_CONSTEXPR_H

namespace Babylon
{

namespace Utils
{

namespace Math
{

struct Vector4;
struct Matrix;
struct Quaternion;
struct Plane;

//------------------------------------------------------------------------------
// COMMON MATHEMATICAL CONSTANTS

// Note: these constants are specified to many significant figures sufficient for
// double precision even though declared as float.
static Babylon_CONST float kPi               = 3.14159265358979323846f;
static Babylon_CONST float kEuler            = 2.71828182845904523536f;
static Babylon_CONST float kPhi              = 1.61803398874989484820f;
static Babylon_CONST float kHalfPi           = 1.57079632679489661923f;
static Babylon_CONST float kTwoPi            = 6.28318530717958647692f;
static Babylon_CONST float kSqrtTwo          = 1.41421356237309504880f;
static Babylon_CONST float kSqrtHalf         = 0.70710678118654752440f;
static Babylon_CONST float kEpsilon          = FLT_EPSILON;
static Babylon_CONST float kToleranceDefault = kEpsilon * 5.0f;

inline float Min(float a, float b) { return std::fmin(a, b); }
inline float Max(float a, float b) { return std::fmax(a, b); }
inline float Min(float a, float b, float c) { return Min(Min(a, b), c); }
inline float Max(float a, float b, float c) { return Max(Max(a, b), c); }
inline float Clamp(float value, float min, float max) { return Min(Max(value, min), max); }
inline int ClampInteger(int value, int min, int max) { return value < min ? min : (value > max ? max : value); }

static Babylon_CONST float kDegreesPerRadian = 180.0f / kPi;
static Babylon_CONST float kRadiansPerDegree = kPi / 180.0f;
inline Babylon_CONSTEXPR float DegreesToRadians(float degrees) { return degrees * kRadiansPerDegree; }
inline Babylon_CONSTEXPR float RadiansToDegrees(float radians) { return radians * kDegreesPerRadian; }

inline bool IsValid(float x) { return !std::isinf(x) && !std::isnan(x); }
inline bool IsEquivalent(float a, float b, float tolerance = kToleranceDefault) { return std::fabs(a - b) <= tolerance; }

inline Babylon_CONSTEXPR uint32_t IntegerLog(uint32_t x)
{
    uint32_t result = 0;
    while (x > 1)
    {
        x /= 2;
        result++;
    }
    return result;
}

//------------------------------------------------------------------------------
// 2D vector
struct Vector2 : public DirectX::XMFLOAT2
{
    Babylon_CONSTEXPR Vector2() : DirectX::XMFLOAT2(0.f, 0.f) {}
    explicit Babylon_CONSTEXPR Vector2(float x) : DirectX::XMFLOAT2( x, x ) {}
    Babylon_CONSTEXPR Vector2(float _x, float _y) : DirectX::XMFLOAT2(_x, _y) {}
    explicit Vector2(_In_reads_(2) const float *pArray) : DirectX::XMFLOAT2(pArray) {}
    Vector2(DirectX::FXMVECTOR V) { XMStoreFloat2( this, V ); }

    operator DirectX::XMVECTOR() const { return XMLoadFloat2( this ); }

    explicit operator const float*() const { return reinterpret_cast<const float*>(this); }

    // Comparision operators
    bool operator == ( const Vector2& V ) const;
    bool operator != ( const Vector2& V ) const;

    // Assignment operators
    Babylon_CONSTEXPR Vector2& operator= (const Vector2& V) { x = V.x; y = V.y; return *this; }
    Vector2& operator+= (const Vector2& V);
    Vector2& operator-= (const Vector2& V);
    Vector2& operator*= (const Vector2& V);
    Vector2& operator*= (float S);
    Vector2& operator/= (float S);

    // Unary operators
    Vector2 operator+ () const { return *this; }
    Vector2 operator- () const { return Vector2(-x, -y); }

    // Vector operations
    bool InBounds( const Vector2& Bounds ) const;

    float Length() const;
    float LengthSquared() const;

    float Dot( const Vector2& V ) const;
    void Cross( const Vector2& V, Vector2& result ) const;
    Vector2 Cross( const Vector2& V ) const;

    void Normalize();
    void Normalize( Vector2& result ) const;

    void Clamp( const Vector2& vmin, const Vector2& vmax );
    void Clamp( const Vector2& vmin, const Vector2& vmax, Vector2& result ) const;

    // Static functions
    static float Distance( const Vector2& v1, const Vector2& v2 );
    static float DistanceSquared( const Vector2& v1, const Vector2& v2 );

    static void Min( const Vector2& v1, const Vector2& v2, Vector2& result );
    static Vector2 Min( const Vector2& v1, const Vector2& v2 );

    static void Max( const Vector2& v1, const Vector2& v2, Vector2& result );
    static Vector2 Max( const Vector2& v1, const Vector2& v2 );

    static void Lerp( const Vector2& v1, const Vector2& v2, float t, Vector2& result );
    static Vector2 Lerp( const Vector2& v1, const Vector2& v2, float t );

    static void SmoothStep( const Vector2& v1, const Vector2& v2, float t, Vector2& result );
    static Vector2 SmoothStep( const Vector2& v1, const Vector2& v2, float t );

    static void Barycentric( const Vector2& v1, const Vector2& v2, const Vector2& v3, float f, float g, Vector2& result );
    static Vector2 Barycentric( const Vector2& v1, const Vector2& v2, const Vector2& v3, float f, float g );

    static void CatmullRom( const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& v4, float t, Vector2& result );
    static Vector2 CatmullRom( const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& v4, float t );

    static void Hermite( const Vector2& v1, const Vector2& t1, const Vector2& v2, const Vector2& t2, float t, Vector2& result );
    static Vector2 Hermite( const Vector2& v1, const Vector2& t1, const Vector2& v2, const Vector2& t2, float t );

    static void Reflect( const Vector2& ivec, const Vector2& nvec, Vector2& result );
    static Vector2 Reflect( const Vector2& ivec, const Vector2& nvec );

    static void Refract( const Vector2& ivec, const Vector2& nvec, float refractionIndex, Vector2& result );
    static Vector2 Refract( const Vector2& ivec, const Vector2& nvec, float refractionIndex );

    static void Transform( const Vector2& v, const Quaternion& quat, Vector2& result );
    static Vector2 Transform( const Vector2& v, const Quaternion& quat );

    static void Transform( const Vector2& v, const Matrix& m, Vector2& result );
    static Vector2 Transform( const Vector2& v, const Matrix& m );
    static void Transform( _In_reads_(count) const Vector2* varray, size_t count, const Matrix& m, _Out_writes_(count) Vector2* resultArray );

    static void Transform( const Vector2& v, const Matrix& m, Vector4& result );
    static void Transform( _In_reads_(count) const Vector2* varray, size_t count, const Matrix& m, _Out_writes_(count) Vector4* resultArray );

    static void TransformNormal( const Vector2& v, const Matrix& m, Vector2& result );
    static Vector2 TransformNormal( const Vector2& v, const Matrix& m );
    static void TransformNormal( _In_reads_(count) const Vector2* varray, size_t count, const Matrix& m, _Out_writes_(count) Vector2* resultArray );

    // Constants
    static const Vector2 Zero;
    static const Vector2 One;
    static const Vector2 UnitX;
    static const Vector2 UnitY;
};

static_assert(sizeof(Vector2) == 2 * sizeof(float), "The Vector2 layout is not linear or includes padding");

// Binary operators
Vector2 operator+ (const Vector2& V1, const Vector2& V2);
Vector2 operator- (const Vector2& V1, const Vector2& V2);
Vector2 operator* (const Vector2& V1, const Vector2& V2);
Vector2 operator* (const Vector2& V, float S);
Vector2 operator/ (const Vector2& V1, const Vector2& V2);
Vector2 operator* (float S, const Vector2& V);

//------------------------------------------------------------------------------
// 3D vector
struct Vector3 : public DirectX::XMFLOAT3
{
    Babylon_CONSTEXPR Vector3() : DirectX::XMFLOAT3(0.f, 0.f, 0.f) {}
    explicit Babylon_CONSTEXPR Vector3(float x) : DirectX::XMFLOAT3( x, x, x ) {}
    Babylon_CONSTEXPR Vector3(float _x, float _y, float _z) : DirectX::XMFLOAT3(_x, _y, _z) {}
    explicit Vector3(_In_reads_(3) const float *pArray) : DirectX::XMFLOAT3(pArray) {}
    Vector3(DirectX::FXMVECTOR V) { XMStoreFloat3( this, V ); }

    operator DirectX::XMVECTOR() const { return XMLoadFloat3( this ); }

    explicit operator const float*() const { return reinterpret_cast<const float*>(this); }

    // Comparision operators
    bool operator == ( const Vector3& V ) const;
    bool operator != ( const Vector3& V ) const;
    bool operator == ( const XMFLOAT3& V ) const;
    bool operator != ( const XMFLOAT3& V ) const;

    // Assignment operators
    Babylon_CONSTEXPR Vector3& operator= (const Vector3& V) { x = V.x; y = V.y; z = V.z; return *this; }
    Vector3& operator+= (const Vector3& V);
    Vector3& operator-= (const Vector3& V);
    Vector3& operator*= (const Vector3& V);
    Vector3& operator*= (float S);
    Vector3& operator/= (float S);

    // Unary operators
    Vector3 operator+ () const { return *this; }
    Vector3 operator- () const;

    // Vector operations
    bool InBounds( const Vector3& Bounds ) const;

    float Length() const;
    float LengthSquared() const;

    float Dot( const Vector3& V ) const;
    void Cross( const Vector3& V, Vector3& result ) const;
    Vector3 Cross( const Vector3& V ) const;

    void Normalize();
    void Normalize( Vector3& result ) const;

    void Clamp( const Vector3& vmin, const Vector3& vmax );
    void Clamp( const Vector3& vmin, const Vector3& vmax, Vector3& result ) const;

    // Static functions
    static float Distance( const Vector3& v1, const Vector3& v2 );
    static float DistanceSquared( const Vector3& v1, const Vector3& v2 );

    static void Min( const Vector3& v1, const Vector3& v2, Vector3& result );
    static Vector3 Min( const Vector3& v1, const Vector3& v2 );

    static void Max( const Vector3& v1, const Vector3& v2, Vector3& result );
    static Vector3 Max( const Vector3& v1, const Vector3& v2 );

    static void Lerp( const Vector3& v1, const Vector3& v2, float t, Vector3& result );
    static Vector3 Lerp( const Vector3& v1, const Vector3& v2, float t );

    static void SmoothStep( const Vector3& v1, const Vector3& v2, float t, Vector3& result );
    static Vector3 SmoothStep( const Vector3& v1, const Vector3& v2, float t );

    static void Barycentric( const Vector3& v1, const Vector3& v2, const Vector3& v3, float f, float g, Vector3& result );
    static Vector3 Barycentric( const Vector3& v1, const Vector3& v2, const Vector3& v3, float f, float g );

    static void CatmullRom( const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float t, Vector3& result );
    static Vector3 CatmullRom( const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float t );

    static void Hermite( const Vector3& v1, const Vector3& t1, const Vector3& v2, const Vector3& t2, float t, Vector3& result );
    static Vector3 Hermite( const Vector3& v1, const Vector3& t1, const Vector3& v2, const Vector3& t2, float t );

    static void Reflect( const Vector3& ivec, const Vector3& nvec, Vector3& result );
    static Vector3 Reflect( const Vector3& ivec, const Vector3& nvec );

    static void Refract( const Vector3& ivec, const Vector3& nvec, float refractionIndex, Vector3& result );
    static Vector3 Refract( const Vector3& ivec, const Vector3& nvec, float refractionIndex );

    static void Transform( const Vector3& v, const Quaternion& quat, Vector3& result );
    static Vector3 Transform( const Vector3& v, const Quaternion& quat );

    static void Transform( const Vector3& v, const Matrix& m, Vector3& result );
    static Vector3 Transform( const Vector3& v, const Matrix& m );
    static void Transform( _In_reads_(count) const Vector3* varray, size_t count, const Matrix& m, _Out_writes_(count) Vector3* resultArray );

    static void Transform( const Vector3& v, const Matrix& m, Vector4& result );
    static void Transform( _In_reads_(count) const Vector3* varray, size_t count, const Matrix& m, _Out_writes_(count) Vector4* resultArray );

    static void TransformNormal( const Vector3& v, const Matrix& m, Vector3& result );
    static Vector3 TransformNormal( const Vector3& v, const Matrix& m );
    static void TransformNormal( _In_reads_(count) const Vector3* varray, size_t count, const Matrix& m, _Out_writes_(count) Vector3* resultArray );

    static Vector3 Reciprocal(const Vector3& v);

    // Constants
    static const Vector3 Zero;
    static const Vector3 One;
    static const Vector3 UnitX;
    static const Vector3 UnitY;
    static const Vector3 UnitZ;
    static const Vector3 Up;
    static const Vector3 Down;
    static const Vector3 Right;
    static const Vector3 Left;
    static const Vector3 Forward;
    static const Vector3 Backward;
};

static_assert(sizeof(Vector3) == 3 * sizeof(float), "The Vector3 layout is not linear or includes padding");

// Binary operators
Vector3 operator+ (const Vector3& V1, const Vector3& V2);
Vector3 operator- (const Vector3& V1, const Vector3& V2);
Vector3 operator* (const Vector3& V1, const Vector3& V2);
Vector3 operator* (const Vector3& V, float S);
Vector3 operator/ (const Vector3& V1, const Vector3& V2);
Vector3 operator/ (const Vector3& V, float S);
Vector3 operator* (float S, const Vector3& V);

//------------------------------------------------------------------------------
// 4D vector
struct Vector4 : public DirectX::XMFLOAT4
{
    Babylon_CONSTEXPR Vector4() : DirectX::XMFLOAT4(0.f, 0.f, 0.f, 0.f) {}
    explicit Babylon_CONSTEXPR Vector4(float x) : DirectX::XMFLOAT4( x, x, x, x ) {}
    Babylon_CONSTEXPR Vector4(float _x, float _y, float _z, float _w) : DirectX::XMFLOAT4(_x, _y, _z, _w) {}
    explicit Vector4(_In_reads_(4) const float *pArray) : DirectX::XMFLOAT4(pArray) {}
    Vector4(DirectX::FXMVECTOR V) { XMStoreFloat4( this, V ); }

    operator DirectX::XMVECTOR() const { return XMLoadFloat4( this ); }

    explicit operator const float*() const { return reinterpret_cast<const float*>(this); }

    // Comparision operators
    bool operator == ( const Vector4& V ) const;
    bool operator != ( const Vector4& V ) const;

    // Assignment operators
    Babylon_CONSTEXPR Vector4& operator= (const Vector4& V) { x = V.x; y = V.y; z = V.z; w = V.w; return *this; }
    Vector4& operator+= (const Vector4& V);
    Vector4& operator-= (const Vector4& V);
    Vector4& operator*= (const Vector4& V);
    Vector4& operator*= (float S);
    Vector4& operator/= (float S);

    // Unary operators
    Vector4 operator+ () const { return *this; }
    Vector4 operator- () const;

    // Vector operations
    bool InBounds( const Vector4& Bounds ) const;

    float Length() const;
    float LengthSquared() const;

    float Dot( const Vector4& V ) const;
    void Cross( const Vector4& v1, const Vector4& v2, Vector4& result ) const;
    Vector4 Cross( const Vector4& v1, const Vector4& v2 ) const;

    void Normalize();
    void Normalize( Vector4& result ) const;

    void Clamp( const Vector4& vmin, const Vector4& vmax );
    void Clamp( const Vector4& vmin, const Vector4& vmax, Vector4& result ) const;

    // Static functions
    static float Distance( const Vector4& v1, const Vector4& v2 );
    static float DistanceSquared( const Vector4& v1, const Vector4& v2 );

    static void Min( const Vector4& v1, const Vector4& v2, Vector4& result );
    static Vector4 Min( const Vector4& v1, const Vector4& v2 );

    static void Max( const Vector4& v1, const Vector4& v2, Vector4& result );
    static Vector4 Max( const Vector4& v1, const Vector4& v2 );

    static void Lerp( const Vector4& v1, const Vector4& v2, float t, Vector4& result );
    static Vector4 Lerp( const Vector4& v1, const Vector4& v2, float t );

    static void SmoothStep( const Vector4& v1, const Vector4& v2, float t, Vector4& result );
    static Vector4 SmoothStep( const Vector4& v1, const Vector4& v2, float t );

    static void Barycentric( const Vector4& v1, const Vector4& v2, const Vector4& v3, float f, float g, Vector4& result );
    static Vector4 Barycentric( const Vector4& v1, const Vector4& v2, const Vector4& v3, float f, float g );

    static void CatmullRom( const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4, float t, Vector4& result );
    static Vector4 CatmullRom( const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4, float t );

    static void Hermite( const Vector4& v1, const Vector4& t1, const Vector4& v2, const Vector4& t2, float t, Vector4& result );
    static Vector4 Hermite( const Vector4& v1, const Vector4& t1, const Vector4& v2, const Vector4& t2, float t );

    static void Reflect( const Vector4& ivec, const Vector4& nvec, Vector4& result );
    static Vector4 Reflect( const Vector4& ivec, const Vector4& nvec );

    static void Refract( const Vector4& ivec, const Vector4& nvec, float refractionIndex, Vector4& result );
    static Vector4 Refract( const Vector4& ivec, const Vector4& nvec, float refractionIndex );

    static void Transform( const Vector2& v, const Quaternion& quat, Vector4& result );
    static Vector4 Transform( const Vector2& v, const Quaternion& quat );

    static void Transform( const Vector3& v, const Quaternion& quat, Vector4& result );
    static Vector4 Transform( const Vector3& v, const Quaternion& quat );

    static void Transform( const Vector4& v, const Quaternion& quat, Vector4& result );
    static Vector4 Transform( const Vector4& v, const Quaternion& quat );

    static void Transform( const Vector4& v, const Matrix& m, Vector4& result );
    static Vector4 Transform( const Vector4& v, const Matrix& m );
    static void Transform( _In_reads_(count) const Vector4* varray, size_t count, const Matrix& m, _Out_writes_(count) Vector4* resultArray );

    static Vector4 ToVector4(Vector3 vector, float w) { return Vector4(vector.x, vector.y, vector.z, w); }

    // Constants
    static const Vector4 Zero;
    static const Vector4 One;
    static const Vector4 UnitX;
    static const Vector4 UnitY;
    static const Vector4 UnitZ;
    static const Vector4 UnitW;
};

static_assert(sizeof(Vector4) == 4 * sizeof(float), "The Vector4 layout is not linear or includes padding");

// Binary operators
Vector4 operator+ (const Vector4& V1, const Vector4& V2);
Vector4 operator- (const Vector4& V1, const Vector4& V2);
Vector4 operator* (const Vector4& V1, const Vector4& V2);
Vector4 operator* (const Vector4& V, float S);
Vector4 operator/ (const Vector4& V1, const Vector4& V2);
Vector4 operator/ (const Vector4& V1, float S);
Vector4 operator* (float S, const Vector4& V);

//------------------------------------------------------------------------------
// 4x4 Matrix (assumes right-handed cooordinates)
struct Matrix : public DirectX::XMFLOAT4X4
{
    Babylon_CONSTEXPR Matrix() : DirectX::XMFLOAT4X4(1.f, 0, 0, 0,
        0, 1.f, 0, 0,
        0, 0, 1.f, 0,
        0, 0, 0, 1.f) {}
    Babylon_CONSTEXPR Matrix(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33) : DirectX::XMFLOAT4X4(m00, m01, m02, m03,
            m10, m11, m12, m13,
            m20, m21, m22, m23,
            m30, m31, m32, m33) {}
    explicit Babylon_CONSTEXPR Matrix(const Vector3& r0, const Vector3& r1, const Vector3& r2) : DirectX::XMFLOAT4X4(r0.x, r0.y, r0.z, 0,
        r1.x, r1.y, r1.z, 0,
        r2.x, r2.y, r2.z, 0,
        0, 0, 0, 1.f) {}
    explicit Babylon_CONSTEXPR Matrix(const Vector4& r0, const Vector4& r1, const Vector4& r2, const Vector4& r3) : DirectX::XMFLOAT4X4(r0.x, r0.y, r0.z, r0.w,
        r1.x, r1.y, r1.z, r1.w,
        r2.x, r2.y, r2.z, r2.w,
        r3.x, r3.y, r3.z, r3.w) {}
    explicit Matrix(_In_reads_(16) const float *pArray) : DirectX::XMFLOAT4X4(pArray) {}
    Matrix(DirectX::CXMMATRIX M) { XMStoreFloat4x4(this, M); }

    operator DirectX::XMMATRIX() const { return XMLoadFloat4x4(this); }

    explicit operator const float*() const { return reinterpret_cast<const float*>(this); }

    // Comparision operators
    bool operator == (const Matrix& M) const;
    bool operator != (const Matrix& M) const;

    // Assignment operators
    Matrix& operator= (const Matrix& M);
    Matrix& operator+= (const Matrix& M);
    Matrix& operator-= (const Matrix& M);
    Matrix& operator*= (const Matrix& M);
    Matrix& operator*= (float S);
    Matrix& operator/= (float S);

    Matrix& operator/= (const Matrix& M);
    // Element-wise divide

    // Unary operators
    Matrix operator+ () const { return *this; }
    Matrix operator- () const;

    Babylon_CONSTEXPR float operator[] (std::size_t i) const { return m[i / 4][i % 4]; }

    // Properties
    Babylon_CONSTEXPR Vector3 Up() const { return Vector3( _21, _22, _23); }
    void Up( const Vector3& v ) { _21 = v.x; _22 = v.y; _23 = v.z; }

    Babylon_CONSTEXPR Vector3 Down() const { return Vector3( -_21, -_22, -_23); }
    void Down( const Vector3& v ) { _21 = -v.x; _22 = -v.y; _23 = -v.z; }

    Babylon_CONSTEXPR Vector3 Right() const { return Vector3( _11, _12, _13 ); }
    void Right( const Vector3& v ) { _11 = v.x; _12 = v.y; _13 = v.z; }

    Babylon_CONSTEXPR Vector3 Left() const { return Vector3( -_11, -_12, -_13 ); }
    void Left( const Vector3& v ) { _11 = -v.x; _12 = -v.y; _13 = -v.z; }

    Babylon_CONSTEXPR Vector3 Forward() const  { return Vector3( -_31, -_32, -_33 ); }
    void Forward( const Vector3& v ) { _31 = -v.x; _32 = -v.y; _33 = -v.z; }

    Babylon_CONSTEXPR Vector3 Backward() const { return Vector3( _31, _32, _33 ); }
    void Backward( const Vector3& v ) { _31 = v.x; _32 = v.y; _33 = v.z; }

    Babylon_CONSTEXPR Vector3 Translation() const { return Vector3( _41, _42, _43 ); }
    void Translation( const Vector3& v ) { _41 = v.x; _42 = v.y; _43 = v.z; }

    // Matrix operations
    bool Decompose( Vector3& scale, Quaternion& rotation, Vector3& translation ) const;

    Matrix Transpose() const;
    void Transpose( Matrix& result ) const;

    Matrix Invert() const;
    void Invert( Matrix& result ) const;

    float Determinant() const;

    // Static functions
    static Matrix CreateBillboard( const Vector3& object, const Vector3& cameraPosition, const Vector3& cameraUp, _In_opt_ const Vector3* cameraForward = nullptr );

    static Matrix CreateConstrainedBillboard( const Vector3& object, const Vector3& cameraPosition, const Vector3& rotateAxis,
                                              _In_opt_ const Vector3* cameraForward = nullptr, _In_opt_ const Vector3* objectForward = nullptr);

    static Matrix CreateTranslation( const Vector3& position );
    static Matrix CreateTranslation( float x, float y, float z );

    static Matrix CreateScale( const Vector3& scales );
    static Matrix CreateScale( float xs, float ys, float zs );
    static Matrix CreateScale( float scale );

    static Matrix CreateRotationX( float radians );
    static Matrix CreateRotationY( float radians );
    static Matrix CreateRotationZ( float radians );

    /// Create a Matrix from given axis and angle in radians
    static Matrix CreateFromAxisAngle(const Vector3& axis, float angle);

    static Matrix CreatePerspectiveFieldOfView( float fov, float aspectRatio, float nearPlane, float farPlane );
    static Matrix CreatePerspective( float width, float height, float nearPlane, float farPlane );
    static Matrix CreatePerspectiveOffCenter( float left, float right, float bottom, float top, float nearPlane, float farPlane );
    static Matrix CreateOrthographic( float width, float height, float zNearPlane, float zFarPlane );
    static Matrix CreateOrthographicOffCenter( float left, float right, float bottom, float top, float zNearPlane, float zFarPlane );

    static Matrix CreateLookAt( const Vector3& position, const Vector3& target, const Vector3& up );
    static Matrix CreateWorld( const Vector3& position, const Vector3& forward, const Vector3& up );

    static Matrix CreateFromQuaternion( const Quaternion& quat );

    /// Create a Matrix from Yaw, Pitch and Roll angles in RADIANS around the Y, X and Z axes respectively.
    /// NOTE: unlike Euler angles used in some other contexts, this uses radians rather than degrees.
    static Matrix CreateFromYawPitchRoll(float yaw, float pitch, float roll);

    static Matrix CreateShadow( const Vector3& lightDir, const Plane& plane );

    static Matrix CreateReflection( const Plane& plane );

    static void Lerp( const Matrix& M1, const Matrix& M2, float t, Matrix& result );
    static Matrix Lerp( const Matrix& M1, const Matrix& M2, float t );

    static void Transform( const Matrix& M, const Quaternion& rotation, Matrix& result );
    static Matrix Transform( const Matrix& M, const Quaternion& rotation );

    // Constants
    static const Matrix Identity;
};

static_assert(sizeof(Matrix) == 16 * sizeof(float), "The Matrix layout is not linear or includes padding");

// Binary operators
Matrix operator+ (const Matrix& M1, const Matrix& M2);
Matrix operator- (const Matrix& M1, const Matrix& M2);
Matrix operator* (const Matrix& M1, const Matrix& M2);
Matrix operator* (const Matrix& M, float S);
Matrix operator/ (const Matrix& M, float S);
Matrix operator/ (const Matrix& M1, const Matrix& M2);
    // Element-wise divide
Matrix operator* (float S, const Matrix& M);


//-----------------------------------------------------------------------------
// Plane
struct Plane : public DirectX::XMFLOAT4
{
    Babylon_CONSTEXPR Plane() : DirectX::XMFLOAT4(0.f, 1.f, 0.f, 0.f) {}
    Babylon_CONSTEXPR Plane(float _x, float _y, float _z, float _w) : DirectX::XMFLOAT4(_x, _y, _z, _w) {}
    Babylon_CONSTEXPR Plane(const Vector3& normal, float d) : DirectX::XMFLOAT4(normal.x, normal.y, normal.z, d) {}
    Plane(const Vector3& point1, const Vector3& point2, const Vector3& point3 );
    Plane(const Vector3& point, const Vector3& normal);
    explicit Babylon_CONSTEXPR Plane(const Vector4& v) : DirectX::XMFLOAT4(v.x, v.y, v.z, v.w) {}
    explicit Plane(_In_reads_(4) const float *pArray) : DirectX::XMFLOAT4(pArray) {}
    Plane(DirectX::FXMVECTOR V) { XMStoreFloat4( this, V ); }

    operator DirectX::XMVECTOR() const { return XMLoadFloat4( this ); }

    // Comparision operators
    bool operator == ( const Plane& p ) const;
    bool operator != ( const Plane& p ) const;

    // Assignment operators
    Babylon_CONSTEXPR Plane& operator= (const Plane& p) { x = p.x; y = p.y; z = p.z; w = p.w; return *this; }

    // Properties
    Babylon_CONSTEXPR Vector3 Normal() const { return Vector3( x, y, z ); }
    void Normal( const Vector3& normal ) { x = normal.x; y = normal.y; z = normal.z; }

    Babylon_CONSTEXPR float D() const { return w; }
    void D(float d) { w = d; }

    // Plane operations
    void Normalize();
    void Normalize( Plane& result ) const;

    float Dot( const Vector4& v ) const;
    float DotCoordinate( const Vector3& position ) const;
    float DotNormal( const Vector3& normal ) const;

    // Static functions
    static void Transform( const Plane& plane, const Matrix& M, Plane& result );
    static Plane Transform( const Plane& plane, const Matrix& M );

    static void Transform( const Plane& plane, const Quaternion& rotation, Plane& result );
    static Plane Transform( const Plane& plane, const Quaternion& rotation );
        // Input quaternion must be the inverse transpose of the transformation
};

//------------------------------------------------------------------------------
// Quaternion
struct Quaternion : public DirectX::XMFLOAT4
{
    Babylon_CONSTEXPR Quaternion() : DirectX::XMFLOAT4(0, 0, 0, 1.f) {}
    Babylon_CONSTEXPR Quaternion( float _x, float _y, float _z, float _w ) : DirectX::XMFLOAT4(_x, _y, _z, _w) {}
    Babylon_CONSTEXPR Quaternion( const Vector3& v, float scalar ) : DirectX::XMFLOAT4( v.x, v.y, v.z, scalar ) {}
    explicit Babylon_CONSTEXPR Quaternion( const Vector4& v ) : DirectX::XMFLOAT4( v.x, v.y, v.z, v.w ) {}
    explicit Quaternion(_In_reads_(4) const float *pArray) : DirectX::XMFLOAT4(pArray) {}
    Quaternion(DirectX::FXMVECTOR V) { XMStoreFloat4( this, V ); }

    operator DirectX::XMVECTOR() const { return XMLoadFloat4( this ); }

    // Comparision operators
    bool operator == ( const Quaternion& q ) const;
    bool operator != ( const Quaternion& q ) const;

    // Assignment operators
    Babylon_CONSTEXPR Quaternion& operator= (const Quaternion& q) { x = q.x; y = q.y; z = q.z; w = q.w; return *this; }
    Quaternion& operator+= (const Quaternion& q);
    Quaternion& operator-= (const Quaternion& q);
    Quaternion& operator*= (const Quaternion& q);
    Quaternion& operator*= (float S);
    Quaternion& operator/= (const Quaternion& q);

    // Unary operators
    Quaternion operator+ () const { return *this; }
    Quaternion operator- () const;

    // Quaternion operations
    float Length() const;
    float LengthSquared() const;

    void Normalize();
    void Normalize( Quaternion& result ) const;

    void Conjugate();
    void Conjugate( Quaternion& result ) const;

    void Inverse( Quaternion& result ) const;

    float Dot( const Quaternion& Q ) const;

    // Static functions
    /// Create a Quaternion from given axis and angle in radians
    static Quaternion CreateFromAxisAngle(const Vector3& axis, float angle);
    /// Create a Quaternion from Yaw, Pitch and Roll angles in radians around the Y, X and Z axes respectively.
    static Quaternion CreateFromYawPitchRoll( float yaw, float pitch, float roll );
    static Quaternion CreateFromRotationMatrix( const Matrix& M );

    static void Lerp( const Quaternion& q1, const Quaternion& q2, float t, Quaternion& result );
    static Quaternion Lerp( const Quaternion& q1, const Quaternion& q2, float t );

    static void Slerp( const Quaternion& q1, const Quaternion& q2, float t, Quaternion& result );
    static Quaternion Slerp( const Quaternion& q1, const Quaternion& q2, float t );

    static void Concatenate( const Quaternion& q1, const Quaternion& q2, Quaternion& result );
    static Quaternion Concatenate( const Quaternion& q1, const Quaternion& q2 );

    // Constants
    static const Quaternion Identity;
};

// Binary operators
Quaternion operator+ (const Quaternion& Q1, const Quaternion& Q2);
Quaternion operator- (const Quaternion& Q1, const Quaternion& Q2);
Quaternion operator* (const Quaternion& Q1, const Quaternion& Q2);
Quaternion operator* (const Quaternion& Q, float S);
Quaternion operator/ (const Quaternion& Q1, const Quaternion& Q2);
Quaternion operator* (float S, const Quaternion& Q);

//------------------------------------------------------------------------------
// Color
struct Color : public DirectX::XMFLOAT4
{
    Babylon_CONSTEXPR Color() : DirectX::XMFLOAT4(0, 0, 0, 1.f) {}
    Babylon_CONSTEXPR Color( float _r, float _g, float _b ) : DirectX::XMFLOAT4(_r, _g, _b, 1.f) {}
    Babylon_CONSTEXPR Color( float _r, float _g, float _b, float _a ) : DirectX::XMFLOAT4(_r, _g, _b, _a) {}
    explicit Babylon_CONSTEXPR Color( const Vector3& clr ) : DirectX::XMFLOAT4( clr.x, clr.y, clr.z, 1.f ) {}
    explicit Babylon_CONSTEXPR Color( const Vector4& clr ) : DirectX::XMFLOAT4( clr.x, clr.y, clr.z, clr.w ) {}
    explicit Color(_In_reads_(4) const float *pArray) : DirectX::XMFLOAT4(pArray) {}
    Color(DirectX::FXMVECTOR V) { XMStoreFloat4( this, V ); }

    explicit Color( const DirectX::PackedVector::XMCOLOR& Packed );
        // BGRA Direct3D 9 D3DCOLOR packed color

    explicit Color( const DirectX::PackedVector::XMUBYTEN4& Packed );
        // RGBA XNA Game Studio packed color

    operator DirectX::XMVECTOR() const { return XMLoadFloat4( this ); }

    explicit operator const float*() const { return reinterpret_cast<const float*>(this); }

    // Comparision operators
    bool operator == ( const Color& c ) const;
    bool operator != ( const Color& c ) const;

    // Assignment operators
    Babylon_CONSTEXPR Color& operator= (const Color& c) { x = c.x; y = c.y; z = c.z; w = c.w; return *this; }
    Color& operator+= (const Color& c);
    Color& operator-= (const Color& c);
    Color& operator*= (const Color& c);
    Color& operator*= (float S);
    Color& operator/= (const Color& c);

    // Unary operators
    Color operator+ () const { return *this; }
    Color operator- () const;

    static Babylon_CONSTEXPR Color FromARGB(uint32_t argb)
    {
        float a = static_cast<float>((argb >> 24) & 0xFF) / 255.0f;
        float r = static_cast<float>((argb >> 16) & 0xFF) / 255.0f;
        float g = static_cast<float>((argb >> 8) & 0xFF) / 255.0f;
        float b = static_cast<float>((argb >> 0) & 0xFF) / 255.0f;
        return Color(r, g, b, a);
    }

    static Babylon_CONSTEXPR Color FromRGBA(uint32_t rgba)
    {
        float r = static_cast<float>((rgba >> 24) & 0xFF) / 255.0f;
        float g = static_cast<float>((rgba >> 16) & 0xFF) / 255.0f;
        float b = static_cast<float>((rgba >> 8) & 0xFF) / 255.0f;
        float a = static_cast<float>((rgba >> 0) & 0xFF) / 255.0f;
        return Color(r, g, b, a);
    }

    static Babylon_CONSTEXPR Color FromABGR(uint32_t abgr)
    {
        float a = static_cast<float>((abgr >> 24) & 0xFF) / 255.0f;
        float b = static_cast<float>((abgr >> 16) & 0xFF) / 255.0f;
        float g = static_cast<float>((abgr >> 8) & 0xFF) / 255.0f;
        float r = static_cast<float>((abgr >> 0) & 0xFF) / 255.0f;
        return Color(r, g, b, a);
    }

    static Babylon_CONSTEXPR Color FromBGRA(uint32_t bgra)
    {
        float b = static_cast<float>((bgra >> 24) & 0xFF) / 255.0f;
        float g = static_cast<float>((bgra >> 16) & 0xFF) / 255.0f;
        float r = static_cast<float>((bgra >> 8) & 0xFF) / 255.0f;
        float a = static_cast<float>((bgra >> 0) & 0xFF) / 255.0f;
        return Color(r, g, b, a);
    }

    Babylon_CONSTEXPR uint32_t ToABGR() const
    {
        uint8_t r = static_cast<uint8_t>(x * 255.0f + 0.5f);
        uint8_t g = static_cast<uint8_t>(y * 255.0f + 0.5f);
        uint8_t b = static_cast<uint8_t>(z * 255.0f + 0.5f);
        uint8_t a = static_cast<uint8_t>(w * 255.0f + 0.5f);
        uint32_t abgr = r << 0 | g << 8 | b << 16 | a << 24;
        return abgr;
    }

    uint32_t ToARGB() const
    {
        uint8_t r = static_cast<uint8_t>(x * 255.0f + 0.5f);
        uint8_t g = static_cast<uint8_t>(y * 255.0f + 0.5f);
        uint8_t b = static_cast<uint8_t>(z * 255.0f + 0.5f);
        uint8_t a = static_cast<uint8_t>(w * 255.0f + 0.5f);

        uint32_t argb = b << 0 | g << 8 | r << 16 | a << 24;
        return argb;
    }

    Color Clamped(float min = 0.0f, float max = 1.0f) const
    {
        return Clamp(*this, min, max);
    }

    static Color Clamp(const Color& color, float min, float max)
    {
        return {
            std::min(max, std::max(min, color.x)),
            std::min(max, std::max(min, color.y)),
            std::min(max, std::max(min, color.z)),
            std::min(max, std::max(min, color.w))
        };
    }

    // Properties
    Babylon_CONSTEXPR float R() const { return x; }
    void R(float r) { x = r; }

    Babylon_CONSTEXPR float G() const { return y; }
    void G(float g) { y = g; }

    Babylon_CONSTEXPR float B() const { return z; }
    void B(float b) { z = b; }

    Babylon_CONSTEXPR float A() const { return w; }
    void A(float a) { w = a; }

    // Color operations
    DirectX::PackedVector::XMCOLOR BGRA() const;
    DirectX::PackedVector::XMUBYTEN4 RGBA() const;

    Babylon_CONSTEXPR Vector3 ToVector3() const { return Vector3(x, y, z); }
    Babylon_CONSTEXPR Vector4 ToVector4() const { return Vector4(x, y, z, w); }

    void Negate();
    void Negate( Color& result ) const;

    void Saturate();
    void Saturate( Color& result ) const;

    void Premultiply();
    void Premultiply( Color& result ) const;

    void AdjustSaturation( float sat );
    void AdjustSaturation( float sat, Color& result ) const;

    void AdjustContrast( float contrast );
    void AdjustContrast( float contrast, Color& result ) const;

    // Static functions
    static void Modulate( const Color& c1, const Color& c2, Color& result );
    static Color Modulate( const Color& c1, const Color& c2 );

    static void Lerp( const Color& c1, const Color& c2, float t, Color& result );
    static Color Lerp( const Color& c1, const Color& c2, float t );

    Vector4 ToVector4() { return Vector4(x, y, z, w); }

    Color ToLinearRGB() const
    {
        Babylon_CONSTEXPR float kGammaCurve = 2.2f;
        return Color(pow(x, kGammaCurve), pow(y, kGammaCurve), pow(z, kGammaCurve), w);
    }

    Color ToGammaRGB() const
    {
        Babylon_CONSTEXPR float msInvGammaCurve = 1.0f / 2.2f;
        return Color(pow(x, msInvGammaCurve), pow(y, msInvGammaCurve), pow(z, msInvGammaCurve), w);
    }

    // Performs conversion from HSB to RGB, with hue in [0,360], saturation in [0,100], brightness in [0,100]
    static Color FromHSB(float hue, float saturation, float brightness);

    static const Color Black;
    static const Color White;
    static const Color Transparent;
};

static_assert(sizeof(Color) == 4 * sizeof(float), "The Color layout is not linear or includes padding");

// Binary operators
Color operator+ (const Color& C1, const Color& C2);
Color operator- (const Color& C1, const Color& C2);
Color operator* (const Color& C1, const Color& C2);
Color operator* (const Color& C, float S);
Color operator/ (const Color& C1, const Color& C2);
Color operator* (float S, const Color& C);

//------------------------------------------------------------------------------
// Ray
class Ray
{
public:
    Vector3 position;
    Vector3 direction;

    Babylon_CONSTEXPR Ray() : position(0,0,0), direction(0,0,1) {}
    Babylon_CONSTEXPR Ray( const Vector3& pos, const Vector3& dir ) : position(pos), direction(dir) {}

    // Comparison operators
    bool operator == ( const Ray& r ) const;
    bool operator != ( const Ray& r ) const;

    // Ray operations
//    bool Intersects( const BoundingSphere& sphere, _Out_ float& Dist ) const;
//    bool Intersects( const BoundingBox& box, _Out_ float& Dist ) const;
    bool Intersects( const Vector3& tri0, const Vector3& tri1, const Vector3& tri2, _Out_ float& Dist ) const;
    bool Intersects( const Plane& plane, _Out_ float& Dist ) const;
};

#include "SimpleMath.inl"

}; // namespace Math

}; // namespace Utils

}; // namespace Babylon

//------------------------------------------------------------------------------
// Support for SimpleMath and Standard C++ Library containers
namespace std
{

    template<> struct less<Babylon::Utils::Math::Vector2>
    {
        bool operator()(const Babylon::Utils::Math::Vector2& V1, const Babylon::Utils::Math::Vector2& V2) const
        {
            return ( (V1.x < V2.x) || ((V1.x == V2.x) && (V1.y < V2.y)) );
        }
    };

    template<> struct less<Babylon::Utils::Math::Vector3>
    {
        bool operator()(const Babylon::Utils::Math::Vector3& V1, const Babylon::Utils::Math::Vector3& V2) const
        {
            return ( (V1.x < V2.x)
                     || ((V1.x == V2.x) && (V1.y < V2.y))
                     || ((V1.x == V2.x) && (V1.y == V2.y) && (V1.z < V2.z)) );
        }
    };

    template<> struct less<Babylon::Utils::Math::Vector4>
    {
        bool operator()(const Babylon::Utils::Math::Vector4& V1, const Babylon::Utils::Math::Vector4& V2) const
        {
            return ( (V1.x < V2.x)
                     || ((V1.x == V2.x) && (V1.y < V2.y))
                     || ((V1.x == V2.x) && (V1.y == V2.y) && (V1.z < V2.z))
                     || ((V1.x == V2.x) && (V1.y == V2.y) && (V1.z == V2.z) && (V1.w < V2.w)) );
        }
    };

    template<> struct less<Babylon::Utils::Math::Matrix>
    {
        bool operator()(const Babylon::Utils::Math::Matrix& M1, const Babylon::Utils::Math::Matrix& M2) const
        {
            if (M1._11 != M2._11) return M1._11 < M2._11;
            if (M1._12 != M2._12) return M1._12 < M2._12;
            if (M1._13 != M2._13) return M1._13 < M2._13;
            if (M1._14 != M2._14) return M1._14 < M2._14;
            if (M1._21 != M2._21) return M1._21 < M2._21;
            if (M1._22 != M2._22) return M1._22 < M2._22;
            if (M1._23 != M2._23) return M1._23 < M2._23;
            if (M1._24 != M2._24) return M1._24 < M2._24;
            if (M1._31 != M2._31) return M1._31 < M2._31;
            if (M1._32 != M2._32) return M1._32 < M2._32;
            if (M1._33 != M2._33) return M1._33 < M2._33;
            if (M1._34 != M2._34) return M1._34 < M2._34;
            if (M1._41 != M2._41) return M1._41 < M2._41;
            if (M1._42 != M2._42) return M1._42 < M2._42;
            if (M1._43 != M2._43) return M1._43 < M2._43;
            if (M1._44 != M2._44) return M1._44 < M2._44;

            return false;
        }
    };

    template<> struct less<Babylon::Utils::Math::Plane>
    {
        bool operator()(const Babylon::Utils::Math::Plane& P1, const Babylon::Utils::Math::Plane& P2) const
        {
            return ( (P1.x < P2.x)
                     || ((P1.x == P2.x) && (P1.y < P2.y))
                     || ((P1.x == P2.x) && (P1.y == P2.y) && (P1.z < P2.z))
                     || ((P1.x == P2.x) && (P1.y == P2.y) && (P1.z == P2.z) && (P1.w < P2.w)) );
        }
    };

    template<> struct less<Babylon::Utils::Math::Quaternion>
    {
        bool operator()(const Babylon::Utils::Math::Quaternion& Q1, const Babylon::Utils::Math::Quaternion& Q2) const
        {
            return ( (Q1.x < Q2.x)
                     || ((Q1.x == Q2.x) && (Q1.y < Q2.y))
                     || ((Q1.x == Q2.x) && (Q1.y == Q2.y) && (Q1.z < Q2.z))
                     || ((Q1.x == Q2.x) && (Q1.y == Q2.y) && (Q1.z == Q2.z) && (Q1.w < Q2.w)) );
        }
    };

    template<> struct less<Babylon::Utils::Math::Color>
    {
        bool operator()(const Babylon::Utils::Math::Color& C1, const Babylon::Utils::Math::Color& C2) const
        {
            return ( (C1.x < C2.x)
                     || ((C1.x == C2.x) && (C1.y < C2.y))
                     || ((C1.x == C2.x) && (C1.y == C2.y) && (C1.z < C2.z))
                     || ((C1.x == C2.x) && (C1.y == C2.y) && (C1.z == C2.z) && (C1.w < C2.w)) );
        }
    };

    template<> struct less<Babylon::Utils::Math::Ray>
    {
        bool operator()(const Babylon::Utils::Math::Ray& R1, const Babylon::Utils::Math::Ray& R2) const
        {
            if (R1.position.x != R2.position.x) return R1.position.x < R2.position.x;
            if (R1.position.y != R2.position.y) return R1.position.y < R2.position.y;
            if (R1.position.z != R2.position.z) return R1.position.z < R2.position.z;

            if (R1.direction.x != R2.direction.x) return R1.direction.x < R2.direction.x;
            if (R1.direction.y != R2.direction.y) return R1.direction.y < R2.direction.y;
            if (R1.direction.z != R2.direction.z) return R1.direction.z < R2.direction.z;

            return false;
        }
    };

} // namespace std

#endif // COREUTILS_SIMPLEMATH_H_INCLUDED
