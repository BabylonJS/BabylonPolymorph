/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <stdint.h>

namespace Spectre
{
    namespace Framework
    {

        /**
        * ExtensionHeader is a base class for arbitrary extra information associated with a BXF segment. They can be chained together
        * in a singly-linked-list.
        */
        struct ExtensionHeader
        {
            enum EType
            {
                kMeshSkeletonBinding
            };

            uint8_t Type;                          /**< One of EType (determines which derived struct to use) */
            uint8_t Reserved[3];
            uint32_t OffsetToNextExtensionHeader;  /**< Offset in bytes from start of this struct to next extension header (0 if this is the last one) */
        };

        //////////////////////////////////////////////////////////////////////////

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
        /**
         * CAUTION: Only use these methods on validated data (they dereference pointers)
         * This is safe to use on segments which have passed through Engine::Parser since it validates data ranges.
         */
        struct ExtensionHeaderLittleEndian : ExtensionHeader
        {
            /**
            * \return The next extension header or NULL if this is the last header in the chain
            */
            inline ExtensionHeaderLittleEndian const* GetNext() const;

            /**
            * Search for the first extension header of a given type.
            *
            * \param[in] type Type of extension header to search for
            * \return The first extension header or NULL if no matching header is found
            */
            inline ExtensionHeaderLittleEndian const* FindFirstHeaderByType(ExtensionHeader::EType type) const;
        };

        inline ExtensionHeaderLittleEndian const* ExtensionHeaderLittleEndian::GetNext() const
        {
            if (OffsetToNextExtensionHeader == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<ExtensionHeaderLittleEndian const*>(uintptr_t(this) + OffsetToNextExtensionHeader);
        }

        inline ExtensionHeaderLittleEndian const* ExtensionHeaderLittleEndian::FindFirstHeaderByType(ExtensionHeader::EType type) const
        {
            if (ExtensionHeader::EType(Type) == type)
            {
                return this;
            }
            return GetNext() ? GetNext()->FindFirstHeaderByType(type) : nullptr;
        }
        #else
        #error Need to Implement for Big Endian
        #endif
    }
}