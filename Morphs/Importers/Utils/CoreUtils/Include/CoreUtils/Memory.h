/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <stdint.h>

#ifndef _MSC_VER
#define Babylon_MEMORY_MEMCPY_S_IMPL
#endif

namespace Babylon
{
namespace Utils
{

    void FastMemSet(uint8_t* destination, uint64_t size, uint8_t value);
    int32_t FastMemCopy(uint8_t* destination, uint64_t destinationSize, uint8_t const* source, uint64_t sourceSize);

#ifdef Babylon_MEMORY_MEMCPY_S_IMPL

    int SafeMemCopy(void* const _Destination, size_t const _DestinationSize, void const* const _Source, size_t const _SourceSize);

#endif
};
};

#ifdef Babylon_MEMORY_MEMCPY_S_IMPL

// define memcpy_s for non-VS platforms.
#define memcpy_s ::Babylon::Utils::SafeMemCopy

#endif
