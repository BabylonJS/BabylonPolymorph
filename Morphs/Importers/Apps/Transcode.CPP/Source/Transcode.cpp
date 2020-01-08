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

DEFINE_TRACE_AREA(Transcode_CPP, 0);

namespace
{
    double GetDurationSeconds(
        const std::chrono::time_point<std::chrono::system_clock>& start,
        const std::chrono::time_point<std::chrono::system_clock>& end)
    {
        return std::chrono::duration<double, std::milli>(end - start).count() / 1000.0;
    }

    // std::ifstream implementation of Spectre::Transcoder::IResourceServer, which is needed for Import
    class ResourceServer : public Spectre::Transcoder::IResourceServer
    {
    public:
        ResourceServer(std::string baseDirectory)
            : m_baseDirectory(std::move(baseDirectory))
        {
        }

        virtual std::shared_ptr<std::istream> RequestResource(const std::string& path) const
        {
            auto relativePath = Spectre::Utils::IsPathRelative(path) ? path : Spectre::Utils::GetPathFileName(path);
            auto absolutePath = m_baseDirectory + relativePath;
            TRACE_INFO(Transcode_CPP, "Reading: %s", absolutePath.c_str());

            auto istream = Spectre::Utils::CreateSharedInputFileStream(absolutePath, std::ios::binary);
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

    // std::ofstream implementation of Spectre::Transcoder::IOutputStreamFactory, which is needed for Export
    class OutputStreamFactory : public Spectre::Transcoder::IOutputStreamFactory
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

            auto ostream = Spectre::Utils::CreateUniqueOutputFileStream(absolutePath, std::ios::binary);
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

    std::shared_ptr<Spectre::Transcoder::Asset3D> Import(const std::string& inputFilePath, const std::unordered_map<std::string, std::string>& importOptions)
    {
        auto inputFileExtension = Spectre::Utils::GetPathFileExtensionLower(inputFilePath);
        auto inputFileName      = Spectre::Utils::GetPathFileName(inputFilePath);
        auto inputFileDirectory = Spectre::Utils::GetPathDirectory(inputFilePath);

        auto resourceServer = std::make_shared<ResourceServer>(std::move(inputFileDirectory));
        auto asset3d = Spectre::Transcoder::Import(inputFileExtension, inputFileName, resourceServer.get(), importOptions);
        return asset3d;
    }

    void Export(std::shared_ptr<Spectre::Transcoder::Asset3D> asset3d, const std::string& outputFilePath, const std::string& exportFormat, const std::unordered_map<std::string, std::string>& exportOptions, std::string outputDirectory)
    {
        auto outputFileName = Spectre::Utils::GetPathFileName(outputFilePath);
        if (outputDirectory.empty())
        {
            outputDirectory = Spectre::Utils::GetPathDirectory(outputFilePath);
        }

        auto outputStreamFactory = std::make_shared<OutputStreamFactory>(std::move(outputDirectory));
        Spectre::Transcoder::Export(exportFormat, asset3d, outputFileName, outputStreamFactory.get(), exportOptions);
    }
}

void Spectre::Transcode(
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

std::string Spectre::GetImportHelp(const std::string& format)
{
    return Spectre::Transcoder::GetImportHelp(format);
}

std::string Spectre::GetExportHelp(const std::string& format)
{
    return Spectre::Transcoder::GetExportHelp(format);
}
