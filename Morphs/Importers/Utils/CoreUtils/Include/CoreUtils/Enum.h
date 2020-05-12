/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <type_traits>

namespace Babylon
{
    namespace Utils
    {
        template<typename T>
        constexpr auto underlying_cast(const T elem)
        {
            static_assert(std::is_enum<T>::value, "underlying_cast only operates on enum types");

            return static_cast<std::underlying_type_t<T>>(elem);
        }
    }
}
