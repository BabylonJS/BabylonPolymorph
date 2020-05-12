/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <CoreUtils/Assert.h>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/Math/BabylonMath.h>

#include <cstdint>

namespace Babylon
{
namespace Utils
{
    inline bool IsAligned(const void* const ptr, size_t alignment)
    {
        // Valid alignment requirements are always a power of two
        if (!Math::IsPowerOfTwo(alignment))
        {
            throw BabylonInvalidArgException("IsAligned: alignment argument value is not a power of two");
        }

        return !(reinterpret_cast<uintptr_t>(ptr) & (alignment - 1U));
    }

    template<typename T>
    inline bool IsAligned(const void* const ptr)
    {
        return IsAligned(ptr, alignof(T));
    }

    /// \brief
    /// Align the value up to be a multiple of the specified alignment.
    /// The alignment must be a power of two, or zero for no alignment.
    inline Babylon_CONSTEXPR size_t AlignUp(size_t value, size_t alignment)
    {
        // The requested alignment must be a power of two, or zero for no alignment
        BabylonAssert((alignment == 0U) || Math::IsPowerOfTwo(alignment));

        return (alignment ? ((value + alignment - 1U) & ~(alignment - 1U)) : value);
    }
}
}
