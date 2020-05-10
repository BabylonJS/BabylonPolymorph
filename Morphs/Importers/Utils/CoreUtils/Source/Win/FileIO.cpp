/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "../CoreUtilsPch.h"

#if !defined __cplusplus_winrt

#include <CoreUtils/FileIO.h>

#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include <string>

#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/SmartThrow.h>


namespace Babylon
{

namespace Utils
{

namespace IO
{

//--------------------------------------------------------------------------------

bool FileExists(const std::string &fileName)
{
    return FileExists(Utils::LexicalCast<std::wstring>(fileName));
}

//--------------------------------------------------------------------------------

bool FileExists(const std::wstring &fileName)
{
    auto attr = ::GetFileAttributesW(fileName.c_str());
    return (attr != INVALID_FILE_ATTRIBUTES);
}

//--------------------------------------------------------------------------------

std::vector<std::shared_ptr<WIN32_FIND_DATAW>> GetFileSystemEntries(std::wstring const& path)
{
    WIN32_FIND_DATAW fileData;
    HANDLE fileHandle = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;

    if (path.length() > (MAX_PATH - 3))
    {
        throw Utils::BabylonInvalidArgException(
            "Directory path is too long.", false);
    }

    std::wstring directorySearch = path;
    directorySearch.append(L"\\*");

    fileHandle = FindFirstFileW(directorySearch.c_str(), &fileData);
    if (fileHandle == INVALID_HANDLE_VALUE)
    {
        dwError = GetLastError();
        throw Utils::BabylonException(dwError,
            "FindFirstFile returned INVALID_HANDLE_VALUE for " +
            Utils::LexicalCast<std::string>(path), false);
    }

    std::vector<std::shared_ptr<WIN32_FIND_DATAW>> result;
    do
    {
        WIN32_FIND_DATAW data = fileData;
        result.push_back(std::make_shared<WIN32_FIND_DATAW>(data));
    } while (FindNextFileW(fileHandle, &fileData) != NULL);

    dwError = GetLastError();
    if (dwError != ERROR_NO_MORE_FILES)
    {
        throw Utils::BabylonException(dwError,
            "FindNextFile encountered an unexpected error wihle searching " +
            Utils::LexicalCast<std::string>(path), false);
    }

    FindClose(fileHandle);
    return result;
}

//--------------------------------------------------------------------------------

std::vector<std::wstring> GetFilesInDirectory(std::wstring const& path, std::wstring const& filter)
{
    std::vector<std::wstring> result;

    // Path normalisation
    std::wstring normPath = path;
    while (normPath.at(normPath.size() - 1) == '\\')
    {
        normPath.pop_back();
    }

    auto entries = GetFileSystemEntries(path);
    for (auto entry : entries)
    {
        if (!(entry->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            auto file = std::wstring(path + L"\\" + entry->cFileName);
            if (filter.length() != 0 && file.find(filter) != std::wstring::npos)
            {
                result.push_back(file);
            }
        }
    }

    return result;
}

//--------------------------------------------------------------------------------

} // namespace IO

} // namespace Utils

} // namespace Babylon

#endif // #if !defined __cplusplus_winrt
