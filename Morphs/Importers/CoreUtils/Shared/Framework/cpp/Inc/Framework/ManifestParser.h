/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Frame.h>

namespace Babylon
{
    namespace Framework
    {
        class ManifestParser final
        {
        public:
            struct FrameContent
            {
                Framework::EFrameQuality LOD;
                Framework::EFrameCompression Compression;
                std::wstring StreamGUID;
                uint64_t Size;
            };

            struct Manifest : public std::map<Framework::EFrameType, std::vector<FrameContent>>
            {
                std::wstring Id;
                std::wstring PackageVersion;
            };

        public:
            ManifestParser( std::wstring const& jsonString );
            Manifest const& Get() const { return m_manifest; }

        private:
            Manifest m_manifest;
        };

    } // namespace Framework
} // namespace Babylon
