/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <cstring>

#include <Framework/Types.h>
#include <Framework/MemoryBuffer.h>

namespace Babylon
{
    namespace Framework
    {
        struct Vertex
        {
            Vertex();

            inline void SetPosition(float x, float y, float z);
            inline void SetPosition(float pos[3]);
            inline void SetNormal(float x, float y, float z);
            inline void SetNormal(float normal[3]);
            inline void SetTangent(float x, float y, float z, float w);
            inline void SetTangent(float tangent[4]);
            inline void SetUV0(float u, float v);
            inline void SetUV0(float uv[2]);
            inline void SetUV1(float u, float v);
            inline void SetUV1(float uv[2]);
            inline void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
            inline void SetColor(uint8_t* rgba);

            float Position[3];
            float Normal[3];
            float Tangent[4]; // make 4D
            float UV0[2];
            float UV1[2];
            uint8_t Rgba[4];

            bool HasNormal;
            bool HasTangent;
            bool HasUV0;
            bool HasUV1;
            bool HasColor;
            bool HasPosition;
        };

        inline Vertex::Vertex()
        {
            // This is fine to do for POD types
            memset(this, 0, sizeof(Vertex));
        }

        inline void Vertex::SetPosition(float x, float y, float z)
        {
            HasPosition = true;
            Position[0] = x; Position[1] = y; Position[2] = z;
        }

        inline void Vertex::SetPosition(float* pos)
        {
            HasPosition = true;
            Position[0] = pos[0]; Position[1] = pos[1]; Position[2] = pos[2];
        }

        inline void Vertex::SetNormal(float x, float y, float z)
        {
            HasNormal = true;
            Normal[0] = x; Normal[1] = y; Normal[2] = z;
        }

        inline void Vertex::SetNormal(float* normal)
        {
            HasNormal = true;
            Normal[0] = normal[0]; Normal[1] = normal[1]; Normal[2] = normal[2];
        }

        inline void Vertex::SetTangent(float x, float y, float z, float w)
        {
            HasTangent = true;
            Tangent[0] = x; Tangent[1] = y; Tangent[2] = z; Tangent[3] = w;
        }

        inline void Vertex::SetTangent(float tangent[4])
        {
            HasTangent = true;
            Tangent[0] = tangent[0]; Tangent[1] = tangent[1]; Tangent[2] = tangent[2]; Tangent[3] = tangent[3];
        }

        inline void Vertex::SetUV0(float u, float v)
        {
            HasUV0 = true;
            UV0[0] = u; UV0[1] = v;
        }

        inline void Vertex::SetUV0(float* uv)
        {
            HasUV0 = true;
            UV0[0] = uv[0]; UV0[1] = uv[1];
        }

        inline void Vertex::SetUV1(float u, float v)
        {
            HasUV1 = true;
            UV1[0] = u; UV1[1] = v;
        }

        inline void Vertex::SetUV1(float* uv)
        {
            HasUV1 = true;
            UV1[0] = uv[0]; UV1[1] = uv[1];
        }

        inline void Vertex::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        {
            HasColor = true;
            Rgba[0] = r; Rgba[1] = g; Rgba[2] = b; Rgba[3] = a;
        }

        inline void Vertex::SetColor(uint8_t* rgba)
        {
            HasColor = true;
            Rgba[0] = rgba[0]; Rgba[1] = rgba[1]; Rgba[2] = rgba[2]; Rgba[3] = rgba[3];
        }

    } // End namespace Framework

} // End namespace Babylon
