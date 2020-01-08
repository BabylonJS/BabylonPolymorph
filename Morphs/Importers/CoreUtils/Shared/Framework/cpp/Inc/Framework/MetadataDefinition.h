/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Types.h>

namespace Spectre
{
    namespace Framework
    {

        /**
         * Represents the Metadata associated with a model.
         * Contains name <-> ID mapping
         */
        struct MetadataDefinition
        {
            enum EVersion
            {
                kVersion0 = 0x10001000
            };

            uint32_t Version;
            uint32_t ID;

            uint16_t NameNumBytes;
            uint16_t OffsetName;

        protected:
            inline const char* Base() const
            {
                return reinterpret_cast<const char*>(this);
            }
        };

        //////////////////////////////////////////////////////////////////////////

#if (__BYTE_ORDER == __LITTLE_ENDIAN)

        struct MetadataDefinitionBigEndian : MetadataDefinition
        {
            // Helper methods
            inline bool IsValid() const{ return Endian::FromNetworkU32(Version) == kVersion0; }
            inline uint32_t GetID() const{return Endian::FromNetworkU32(ID);}
            inline uint32_t GetNameLengthInBytes() const{ return Endian::FromNetworkU16(NameNumBytes); }
            inline uint16_t* GetName() const { return (uint16_t*)(Base() + Endian::FromNetworkU16(OffsetName)); }
        };


        struct MetadataDefinitionLittleEndian : MetadataDefinition
        {
            // Helper methods
            inline bool IsValid() const{ return Version == kVersion0; }
            inline uint32_t GetID() const{ return ID; }
            inline uint32_t GetNameLengthInBytes() const{ return NameNumBytes; }
            inline uint16_t* GetName() const { return (uint16_t*)(Base() + OffsetName); }
        };


#else
#endif

    } // End namespace Framework

} // End namespace Spectre
