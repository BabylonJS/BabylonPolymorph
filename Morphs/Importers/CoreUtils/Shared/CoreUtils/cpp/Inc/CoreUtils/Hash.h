/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

namespace Spectre
{
    namespace Utils
    {
        inline uint32_t Hash(const char *str)
        {
            if (str == nullptr)
            {
                return 0;
            }

            unsigned int hash = 5381;

            while (*str)
            {
                hash = ((hash << 5) + hash) + *str;
                ++str;
            }
            return hash;
        }

        inline void HashCombine(std::size_t& /*seed*/) {}

        template<typename T>
        void HashCombine(std::size_t& seed, const T& t)
        {
            // This method of combining hashes is from boost::hash_combine - http://www.boost.org/doc/libs/1_62_0/boost/functional/hash/hash.hpp
            seed ^= std::hash<T>{}(t) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }

        template<typename T, typename ...A>
        void HashCombine(std::size_t& seed, const T& t, A&& ...args)
        {
            HashCombine(seed, t);
            HashCombine(seed, std::forward<A>(args)...);
        }

        template<typename T, typename ...A>
        std::size_t HashArgs(const T& t, A&& ...args)
        {
            std::size_t hash = std::hash<T>{}(t);
            HashCombine(hash, std::forward<A>(args)...);
            return hash;
        }

    } // End namespace Utils
} // End namespace
