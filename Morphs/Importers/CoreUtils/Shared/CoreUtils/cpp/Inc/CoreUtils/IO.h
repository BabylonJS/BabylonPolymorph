/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <CoreUtils/SpectreSDK.h>

#if !defined(_STRING_)
#include <string>
#endif // _STRING_

#if !defined(_VECTOR_)
#include <vector>
#endif // _VECTOR_

#ifdef __cplusplus_winrt
#include <ppltasks.h>
#endif

namespace Spectre
{

namespace Utils
{

namespace File
{

class BinaryFileReader;

}

namespace IO
{

typedef unsigned char byte;

#ifdef __cplusplus_winrt
concurrency::task<Windows::Storage::StorageFolder^> GetPersistentDirectoryStorageFolder();     // Never empty on boot
concurrency::task<Windows::Storage::StorageFolder^> GetTempDirectoryStorageFolder();           // Might be empty on boot
concurrency::task<Windows::Storage::StorageFolder^> GetScratchDirectoryStorageFolder();        // Always empty on boot

std::string GetPersistentDirectory();

void CreateDirectory(Platform::String^ directory);
bool FileExists(Platform::String^ fileName);

std::vector<byte> ReadWholeFileBlocking(const std::string &fileName, bool assertOnThrow = true);
void WriteWholeFileBlocking(const std::string &fileName, const std::vector<byte> &data, bool append = false);

#endif // __cplusplus_winrt

std::string SPECTRESDK_CALL DebugOnlyReadWholeBlockingFileAsString(const std::string &fileName);
void SPECTRESDK_CALL DebugOnlyWriteWholeFile(const std::string &fileName, const std::string &data);

std::string SPECTRESDK_CALL GetTempDirectory();

// Returns the temp directory with a slash. Throws on error
std::string SPECTRESDK_CALL GetScratchDirectory();

std::vector<byte> SPECTRESDK_CALL ReadChunkFromFile(Spectre::Utils::File::BinaryFileReader& f, size_t filePointer, size_t numBytes);

/**
* Given a full file path, the method will return the directory the file is in.
* For example, given C:\Temp\File.txt, the method returns C:\Temp\ - including the trailing '\'
*/
std::string SPECTRESDK_CALL GetDirectory(const std::string& fullpath);

/**
* Return the length of the passed-in file stream
*/
std::size_t SPECTRESDK_CALL GetFileStreamSize(std::ifstream& stream);

/**
 * Return the contents of a file in a byte array
 */
std::vector<uint8_t> SPECTRESDK_CALL GetFileContents(const std::string& path);

std::string SPECTRESDK_CALL GetFileBaseName(const std::string& inFileName);

std::string GetBasePath(const std::string& path);
} // namespace IO

} // namespace Utils

} // namespace Spectre
