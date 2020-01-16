/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/TranscodeOptions.h>

namespace
{
    constexpr const char* kTranscodingModeHelp =
R"(Determines the export format for Materials:
    Passthrough       Materials are MR (if present) + SG (if present) [default]

    MrOnly            Materials are MR (forced)
    SgOnly            Materials are SG (forced)
    MrSg              Materials are MR+SG (forced)
    SgLods            Materials are SG (forced) + MSFT_lod
    MrSgLods          Materials are MR+SG (forced) + MSFT_lod

    MsftPackingNrm    Materials are MR (forced, no Occlusion/Emissive) + MSFT_packing_normalRoughnessMetallic

    Default           Alias for 'Passthrough'
    Standard          Alias for 'MrOnly'
    Legacy            Alias for 'SgLods'
    Remix             Alias for 'SgLods')";

    constexpr const char* kTextureCompressionHelp =
R"(Determines the type of texture compression to export with:
    PNG            Textures are lossless PNG [default]
    PNG256         Textures are 256-color PNG
    JPEGPNG        Textures are JPEG where allowed, otherwise lossless PNG
    JPEGPNG256     Textures are JPEG where allowed, otherwise 256-color PNG)";
}

namespace Babylon
{
    namespace Transcoder
    {
        enum class TranscodingMode
        {
            Passthrough,     // MR (if present) + SG (if present)

            MrOnly,          // MR (forced)
            SgOnly,          //                   SG (forced)
            MrSg,            // MR (forced)     + SG (forced)

            SgLods,          //                   SG (forced)      + MSFT_lod
            MrSgLods,        // MR (forced)     + SG (forced)      + MSFT_lod

            MsftPackingNrm,  // MR (forced, no Occlusion/Emissive) + MSFT_packing_normalRoughnessMetallic
        };

        enum class ExportTextureMode
        {
            // TODO: Passthrough
            PNG,
            PNG256,
            JPEGPNG,
            JPEGPNG256
        };

        class GLTFExportOptions : public TranscodeOptions
        {
        public:
            GLTFExportOptions() : TranscodeOptions()
            {
                AddOption({ "Mode", kTranscodingModeHelp,
                        [this](const std::string& value) { SetTranscodingMode(value); } });
                AddOption({ "TextureCompression", kTextureCompressionHelp,
                        [this](const std::string& value) { SetTextureCompression(value); } });
            }

            static GLTFExportOptions ParseOptions(const std::unordered_map<std::string, std::string>& options)
            {
                return Babylon::Transcoder::ParseOptions<GLTFExportOptions>(options);
            }

            void SetTranscodingMode(const std::string& value)
            {
                if      (value == "passthrough")     { TranscodingMode = TranscodingMode::Passthrough; }
                else if (value == "mronly")          { TranscodingMode = TranscodingMode::MrOnly; }
                else if (value == "sgonly")          { TranscodingMode = TranscodingMode::SgOnly; }
                else if (value == "mrsg")            { TranscodingMode = TranscodingMode::MrSg; }
                else if (value == "sglods")          { TranscodingMode = TranscodingMode::SgLods; }
                else if (value == "mrsglods")        { TranscodingMode = TranscodingMode::MrSgLods; }
                else if (value == "msftpackingnrm")  { TranscodingMode = TranscodingMode::MsftPackingNrm; }
                // Aliases:
                else if (value == "default")         { TranscodingMode = TranscodingMode::Passthrough; }
                else if (value == "standard")        { TranscodingMode = TranscodingMode::MrOnly; }
                else if (value == "legacy")          { TranscodingMode = TranscodingMode::SgLods; }
                else if (value == "remix")           { TranscodingMode = TranscodingMode::SgLods; }
                else { throw Utils::BabylonException("Unrecognized value for 'Mode': " + value); }
            }

            void SetTextureCompression(const std::string& value)
            {
                if      (value == "png")        { TextureCompression = ExportTextureMode::PNG; }
                else if (value == "png256")     { TextureCompression = ExportTextureMode::PNG256; }
                else if (value == "jpegpng")    { TextureCompression = ExportTextureMode::JPEGPNG; }
                else if (value == "jpegpng256") { TextureCompression = ExportTextureMode::JPEGPNG256; }
                // Aliases:
                else if (value == "none")       { TextureCompression = ExportTextureMode::PNG; }
                else { throw Utils::BabylonException("Unrecognized value for 'TextureCompression': " + value); }
            }

            TranscodingMode TranscodingMode      = TranscodingMode::Passthrough;
            ExportTextureMode TextureCompression = ExportTextureMode::PNG;
        };
    }
}
