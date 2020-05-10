/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <cstdlib>

#ifndef _WIN32
inline void* _aligned_malloc(size_t size, size_t alignment)
{
    void* ptr;
    posix_memalign(&ptr, alignment, size);
    return ptr;
}

inline void _aligned_free(void* ptr)
{
    free(ptr);
}
#endif // !_WIN32

namespace Babylon
{
namespace Framework
{

template<class T>
T* new_aligned(const uint32_t alignment)
{
    return reinterpret_cast<T*>(_aligned_malloc(sizeof(T), alignment));
}

template<class T>
T* new_aligned(const uint32_t size, const uint32_t alignment)
{
    return reinterpret_cast<T*>(_aligned_malloc(size, alignment));
}

template<class T>
void delete_aligned(T*& allocation)
{
    _aligned_free(allocation);
    allocation = nullptr;
}

} // namespace Framework

} // namespace Babylon
