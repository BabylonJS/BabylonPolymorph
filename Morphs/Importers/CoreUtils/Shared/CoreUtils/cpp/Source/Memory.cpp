/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/Memory.h>
#include <CoreUtils/Assert.h>

#include <string.h>

#if defined(_M_IX86) || defined(_M_X64)
#include <intrin.h>
#endif

namespace Babylon
{

namespace Utils
{

void FastMemSet(uint8_t* destination, uint64_t size, uint8_t value)
{
#if defined(_M_IX86) || defined(_M_X64)
    // Divide by 128.  The SIMD word size is 16 bytes long and we're processing 8 of them per iteration, therefore 16 * 8 = 128.
    uint64_t simdCount = size >> 7;
    uint64_t simdBytes = simdCount << 7;
    __m128i* destinationSIMD = reinterpret_cast<__m128i*>(destination);
    __m128i valueSIMD = _mm_set1_epi8(value);

    while (simdCount > 0)
    {
        _mm_storeu_si128(destinationSIMD++, valueSIMD);
        _mm_storeu_si128(destinationSIMD++, valueSIMD);
        _mm_storeu_si128(destinationSIMD++, valueSIMD);
        _mm_storeu_si128(destinationSIMD++, valueSIMD);
        _mm_storeu_si128(destinationSIMD++, valueSIMD);
        _mm_storeu_si128(destinationSIMD++, valueSIMD);
        _mm_storeu_si128(destinationSIMD++, valueSIMD);
        _mm_storeu_si128(destinationSIMD++, valueSIMD);

        --simdCount;
    }

    destination += simdBytes;
    size -= simdBytes;

    while (size > 0)
    {
        *destination = value;
        ++destination;
        --size;
    }
#else
    // fall back to standard memset
    memset(destination, value, static_cast<size_t>(size));
#endif
}

int32_t FastMemCopy(uint8_t* destination, uint64_t destinationSize, uint8_t const* source, uint64_t sourceSize)
{
    // Also returns a non-zero number if any of these conditions fail, as per the behaviour of memcpy_s.
    BabylonAssert(destinationSize >= sourceSize && destination != nullptr && source != nullptr);

    if (destinationSize >= sourceSize && destination != nullptr && source != nullptr)
#if defined(_M_IX86) || defined(_M_X64)
    {
        // Divide by 128.  The SIMD word size is 16 bytes long and we're processing 8 of them per iteration, therefore 16 * 8 = 128.
        uint64_t simdCount = sourceSize >> 7;
        uint64_t simdBytes = simdCount << 7;
        __m128i* destinationSIMD = reinterpret_cast<__m128i*>(destination);
        const __m128i* sourceSIMD = reinterpret_cast<const __m128i*>(source);

        while (simdCount > 0)
        {
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));
            _mm_storeu_si128(destinationSIMD++, _mm_loadu_si128(sourceSIMD++));

            --simdCount;
        }

        source += simdBytes;
        destination += simdBytes;
        sourceSize -= simdBytes;

        while (sourceSize > 0)
        {
            *destination = *source;
            ++source;
            ++destination;
            --sourceSize;
        }

        return 0;
    }
#else
    {
        return memcpy_s(destination, static_cast<size_t>(destinationSize), source, static_cast<size_t>(sourceSize));
    }
#endif

    return -1;
}

#ifdef Babylon_MEMORY_MEMCPY_S_IMPL

int SafeMemCopy(void* const _Destination, size_t const _DestinationSize, void const* const _Source, size_t const _SourceSize)
{
    if (_DestinationSize >= _SourceSize && _Destination != nullptr && _Source != nullptr)
    {
        memcpy(_Destination, _Source, _SourceSize);
        return 0;
    }

    return -1;
}

#endif // Babylon_MEMORY_MEMCPY_S_IMPL


} // namespace Utils

} // namespace Babylon
