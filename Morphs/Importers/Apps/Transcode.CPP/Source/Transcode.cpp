// Copyright (c) Microsoft Corporation. All rights reserved.

#include <fstream>
#include <sstream>
#include <string>

#include "Transcode.h"

#include <CoreUtils/Platform.h>
#include <CoreUtils/StreamUtils.h>
#include <CoreUtils/StringUtils.h>
#include <CoreUtils/Trace.h>

#include <Transcoders.h>
#include <PluginSKP/PluginSKP.h>

DEFINE_TRACE_AREA(Transcode_CPP, 0);

namespace
{
    double GetDurationSeconds(
        const std::chrono::time_point<std::chrono::system_clock>& start,
        const std::chrono::time_point<std::chrono::system_clock>& end)
    {
        return std::chrono::duration<double, std::milli>(end - start).count() / 1000.0;
    }

    // std::ifstream implementation of Babylon::Transcoder::IResourceServer, which is needed for Import
    class ResourceServer : public Babylon::Transcoder::IResourceServer
    {
    public:
        ResourceServer(std::string baseDirectory)
            : m_baseDirectory(std::move(baseDirectory))
        {
        }

        virtual std::shared_ptr<std::istream> RequestResource(const std::string& path) const
        {
            auto relativePath = Babylon::Utils::IsPathRelative(path) ? path : Babylon::Utils::GetPathFileName(path);
            auto absolutePath = m_baseDirectory + relativePath;
            TRACE_INFO(Transcode_CPP, "Reading: %s", absolutePath.c_str());

            auto istream = Babylon::Utils::CreateSharedInputFileStream(absolutePath, std::ios::binary);
            if (istream->fail())
            {
                TRACE_WARN(Transcode_CPP, "Failed to read: %s", absolutePath.c_str());
                return nullptr;
            }
            return istream;
        }
    private:
        std::string m_baseDirectory;
    };

    // std::ofstream implementation of Babylon::Transcoder::IOutputStreamFactory, which is needed for Export
    class OutputStreamFactory : public Babylon::Transcoder::IOutputStreamFactory
    {
    public:
        OutputStreamFactory(std::string baseDirectory)
            : m_baseDirectory(std::move(baseDirectory))
        {
        }

        virtual std::shared_ptr<std::ostream> CreateStream(const std::string& relativePath)
        {
            auto absolutePath = m_baseDirectory + relativePath;
            TRACE_INFO(Transcode_CPP, "Writing: %s", absolutePath.c_str());

            auto ostream = Babylon::Utils::CreateUniqueOutputFileStream(absolutePath, std::ios::binary);
            if (ostream->fail())
            {
                TRACE_WARN(Transcode_CPP, "Failed to write: %s", absolutePath.c_str());
                return nullptr;
            }
            return ostream;
        }

    private:
        std::string m_baseDirectory;
    };
	
	    void CheckAndInitializeImportFormat(const std::string& format)
    {
#if CANVAS_CAN_USE_SKP()
        // Register SKP importer if necessary
        if (format == "skp" && !Babylon::Transcoder::HasImporter("skp"))
        {
            Babylon::Transcoder::RegisterImportFunction("skp", Babylon::Transcoder::ImportSKP);
        }
#endif
    }

    std::shared_ptr<Babylon::Transcoder::Asset3D> Import(const std::string& inputFilePath, const std::unordered_map<std::string, std::string>& importOptions)
    {
        auto inputFileExtension = Babylon::Utils::GetPathFileExtensionLower(inputFilePath);
        auto inputFileName      = Babylon::Utils::GetPathFileName(inputFilePath);
        auto inputFileDirectory = Babylon::Utils::GetPathDirectory(inputFilePath);

        CheckAndInitializeImportFormat(inputFileExtension);

        auto resourceServer = std::make_shared<ResourceServer>(std::move(inputFileDirectory));
        auto asset3d = Babylon::Transcoder::Import(inputFileExtension, inputFileName, resourceServer.get(), importOptions);
        return asset3d;
    }

    void Export(std::shared_ptr<Babylon::Transcoder::Asset3D> asset3d, const std::string& outputFilePath, const std::string& exportFormat, const std::unordered_map<std::string, std::string>& exportOptions, std::string outputDirectory)
    {
        auto outputFileName = Babylon::Utils::GetPathFileName(outputFilePath);
        if (outputDirectory.empty())
        {
            outputDirectory = Babylon::Utils::GetPathDirectory(outputFilePath);
        }

        auto outputStreamFactory = std::make_shared<OutputStreamFactory>(std::move(outputDirectory));
        Babylon::Transcoder::Export(exportFormat, asset3d, outputFileName, outputStreamFactory.get(), exportOptions);
    }
}

void Babylon::Transcode(
    const std::string& inputFilePath,
    const std::string& outputFormat,
    const std::unordered_map<std::string, std::string>& importOptions,
    const std::unordered_map<std::string, std::string>& exportOptions,
    const std::string& outputDirectory)
{
    TRACE_INFO(Transcode_CPP, "Importing: %s", inputFilePath.c_str());
    auto importStart = std::chrono::system_clock::now();
    auto asset3d = Import(inputFilePath, importOptions);
    auto importEnd = std::chrono::system_clock::now();
    auto importDuration = GetDurationSeconds(importStart, importEnd);

    TRACE_INFO(Transcode_CPP, "Exporting: %s.%s", inputFilePath.c_str(), outputFormat.c_str());
    auto exportStart = std::chrono::system_clock::now();
    Export(asset3d, inputFilePath, outputFormat, exportOptions, outputDirectory);
    auto exportEnd = std::chrono::system_clock::now();
    auto exportDuration = GetDurationSeconds(exportStart, exportEnd);

    TRACE_IMPORTANT(Transcode_CPP, "Time elapsed: %.2f seconds (Import: %.2f seconds / Export: %.2f seconds)",
        importDuration + exportDuration, importDuration, exportDuration);
}

std::string Babylon::GetImportHelp(const std::string& format)
{
    return Babylon::Transcoder::GetImportHelp(format);
}

std::string Babylon::GetExportHelp(const std::string& format)
{
    return Babylon::Transcoder::GetExportHelp(format);
}
