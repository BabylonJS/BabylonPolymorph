// Copyright (c) Microsoft Corporation. All rights reserved.

#include <unordered_map>

namespace Babylon
{
    void Transcode(
        const std::string& inputFile,
        const std::string& outputFile,
        const std::unordered_map<std::string, std::string>& importOptions,
        const std::unordered_map<std::string, std::string>& exportOptions,
        const std::string& outputDirectory = "");
    std::string GetImportHelp(const std::string& format);
    std::string GetExportHelp(const std::string& format);
}
