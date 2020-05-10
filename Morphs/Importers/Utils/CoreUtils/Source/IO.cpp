/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/IO.h>

#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <string>

#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/SmartThrow.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <libgen.h>
#include <sys/param.h>
#endif

namespace Babylon
{

namespace Utils
{

namespace IO
{

//--------------------------------------------------------------------------------

void DebugOnlyWriteWholeFile(const std::string &fileName, const std::string &stringData)
{
    std::ofstream out(fileName);
    if (!out)
    {
        throw BabylonInvalidArgException("Failed to open " + fileName, false);
    }

    out << stringData;
    out.close();
}

//--------------------------------------------------------------------------------

std::string DebugOnlyReadWholeBlockingFileAsString(const std::string &fileName)
{
    std::ifstream file;
    file.open(fileName.c_str());
    if (!file.is_open())
    {
        throw BabylonInvalidArgException("Failed to open " + fileName, false);
    }

    file.seekg(0, std::ios::end);
    auto fileSize = static_cast<size_t>(file.tellg());
    file.seekg(0, std::ios::beg);

    std::vector<char> data(fileSize, 0);
    file.read(&data[0], fileSize);

    return std::string(data.begin(), data.end());
}

//--------------------------------------------------------------------------------

std::string GetTempDirectory()
{

#ifdef _WIN32

    auto fallbackFun = [=]()
    {
        WCHAR path[MAX_PATH];
        if (::GetTempPathW(MAX_PATH, path) == 0)
        {
            throw Utils::BabylonException("Could not get a temporary folder.");
        }
        return Utils::LexicalCast<std::string>(path);
    };

    return fallbackFun();

#else // _WIN32

    return "";

#endif // _WIN32
}

//--------------------------------------------------------------------------------
std::string GetDirectory(const std::string& fullpath)
{
    // Get the file extension
    size_t fileNameIdx = fullpath.find_last_of('\\');
    if (fileNameIdx != std::string::npos)
    {
        auto path = fullpath.substr(0, fileNameIdx + 1);
        return path;
    }
    return fullpath;
}

std::size_t GetFileStreamSize(std::ifstream& stream)
{
    stream.seekg(0, std::ios_base::end);
    auto size = static_cast<size_t>(stream.tellg());
    stream.seekg(0, std::ios_base::beg);
    return size;
}

std::vector<uint8_t> GetFileContents(const std::string& path)
{
    std::ifstream file(path.c_str(), std::ios_base::binary);
    if (! file.is_open())
    {
        throw std::runtime_error("Unable to open file for reading at " + path);
    }

    auto size = GetFileStreamSize(file);
    std::vector<uint8_t> buffer(size);
    file.read(reinterpret_cast<char *>(buffer.data()), size);

    return buffer;
}

std::string GetFileBaseName(const std::string& inFileName)
{
#ifdef _WIN32
    char drive[MAX_PATH], dir[MAX_PATH], assetName[MAX_PATH], ext[MAX_PATH];
    _splitpath_s(inFileName.c_str(), drive, dir, assetName, ext);

    return (std::string(assetName) + std::string(ext));
#else
    // basename requires a "char*" argument and it isn't safe to const_cast constFileName
    // since we don't know what it does internally, so we must copy it.
    std::vector<char> nonConstFileName(inFileName.begin(), inFileName.end());
    nonConstFileName.push_back('\0');

    // We shouldn't trust the char* returned from basename so let's copy it into a string ASAP.
    char* filenameWithExtension = basename(&nonConstFileName[0]);
    return std::string(filenameWithExtension);
#endif // _WIN32

}

std::string GetBasePath(const std::string& path)
{
    auto pathIndex = path.find_last_of("/\\");
    auto basePath = path.substr(0, pathIndex);
    return std::string(basePath);
}

} // namespace IO

} // namespace Utils

} // namespace Babylon
