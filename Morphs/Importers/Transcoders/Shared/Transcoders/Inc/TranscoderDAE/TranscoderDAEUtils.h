/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <COLLADAFWTransformation.h>
#include <COLLADAFWMatrix.h>
#include <Asset3D/SceneNode.h>

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


#define _ToColor(c)  Babylon::Utils::Math::Color(c.getRed(),c.getGreen(), c.getBlue(),c.getAlpha())


/// macros could be used to average incrementally vector3
#define __AVERAGE_INC(v,b,n) (b) + ((v) - (b)) / (n)
#define __VEC3_AVERAGE_INC_X_UP(ptr,v,n) v.y = __AVERAGE_INC(*(ptr++), v.y, n); v.x = __AVERAGE_INC(-*(ptr++), v.x, n); v.x = __AVERAGE_INC(*(ptr), v.z, n);
#define __VEC3_AVERAGE_INC_Y_UP(ptr,v,n) v.x = __AVERAGE_INC(*(ptr++), v.x, n); v.y = __AVERAGE_INC( *(ptr++), v.y, n); v.z = __AVERAGE_INC(*(ptr), v.z, n);
#define __VEC3_AVERAGE_INC_Z_UP(ptr,v,n) v.x = __AVERAGE_INC(*(ptr++), v.x, n); v.z = __AVERAGE_INC(-*(ptr++), v.z, n); v.y = __AVERAGE_INC(*(ptr), v.y, n);
#define __VEC3_AVERAGE_INC_NONE(ptr,v,n) __VEC3_AVERAGE_INC_Z_UP(ptr, v,n)

#define NAME_OR_ID(nodePtr) (nodePtr)->getName().empty() ? (nodePtr)->getOriginalId(): (nodePtr)->getName()
namespace Babylon
{
    namespace Transcoder
    {
        /// use to cast normalized int to float
        template <typename T>
        constexpr float normalized_unpack(T value) {
            return value < 0
                ? -static_cast<float>(value) / std::numeric_limits<T>::min()
                : static_cast<float>(value) / std::numeric_limits<T>::max();
        }

        /// use to cast float to normalized int
        template <typename T>
        constexpr T normalized_pack(float value) {
             assert(value >= -1 && value <= 1);
             return value < 0
                ? -std::roundf(value * std::numeric_limits<T>::min())
                : std::roundf(value * std::numeric_limits<T>::max());
        }

        template<typename TK, typename TV>
        std::vector<TK> extract_keys(std::map<TK, TV> const& input_map) {
            std::vector<TK> retval;
            retval.reserve(input_map.size());
            for (auto const& element : input_map) {
                retval.push_back(element.first);
            }
            return retval;
        }

        template<typename TK, typename TV>
        std::vector<TV> extract_values(std::map<TK, TV> const& input_map) {
            std::vector<TV> retval;
            retval.reserve(input_map.size());
            for (auto const& element : input_map) {
                retval.push_back(element.second);
            }
            return retval;
        }

        Babylon::Utils::Math::Matrix toBabylonMatrix(COLLADABU::Math::Matrix4 colladaMatrix);
        COLLADABU::Math::Matrix4 getMatrixFromTransform(const COLLADAFW::Transformation* transform, float assetScale);
    }
}
