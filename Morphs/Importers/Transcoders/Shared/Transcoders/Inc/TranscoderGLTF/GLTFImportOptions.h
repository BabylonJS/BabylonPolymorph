/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/TranscodeOptions.h>

namespace
{
    constexpr const char* kExtractAnimationDataHelp = "Determines whether to enable animation (true|false)";
    constexpr const char* kForceMinecraftBlendMaterialsToMaskHelp = "Determines whether force Minecraft blend materials to mask (true|false)";
}

namespace Spectre
{
    namespace Transcoder
    {
        class GLTFImportOptions : public TranscodeOptions
        {
        public:
            GLTFImportOptions() : TranscodeOptions()
            {
                AddOption({ "ExtractAnimationData", kExtractAnimationDataHelp,
                        [this](const std::string& value) { SetExtractAnimationData(value); } });
                AddOption({ "ForceMinecraftBlendMaterialsToMask", kForceMinecraftBlendMaterialsToMaskHelp,
                        [this](const std::string& value) { SetForceMinecraftBlendMaterialsToMask(value); } });
            }

            static GLTFImportOptions ParseOptions(const std::unordered_map<std::string, std::string>& options)
            {
                return Spectre::Transcoder::ParseOptions<GLTFImportOptions>(options);
            }

            void SetExtractAnimationData(const std::string& value)
            {
                if      (value == "true")  { ExtractAnimationData = true; }
                else if (value == "false") { ExtractAnimationData = false; }
                else { throw Utils::SpectreException("Unrecognized value for 'ExtractAnimationData': " + value); }
            }

            void SetForceMinecraftBlendMaterialsToMask(const std::string& value)
            {
                if      (value == "true")  { ForceMinecraftBlendMaterialsToMask = true; }
                else if (value == "false") { ForceMinecraftBlendMaterialsToMask = false; }
                else { throw Utils::SpectreException("Unrecognized value for 'ForceMinecraftBlendMaterialsToMask': " + value); }
            }

            bool ExtractAnimationData               = true;
            bool ForceMinecraftBlendMaterialsToMask = false;
        };
    }
}