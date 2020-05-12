/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <CoreUtils/BabylonSDK.h>

#if !defined(_STRING_)
#include <string>
#endif // _STRING_

#if !defined(_VECTOR_)
#include <vector>
#endif // _VECTOR_

#ifdef __cplusplus_winrt
#include <ppltasks.h>
#endif

namespace Babylon
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

std::string BABYLON_SDK_CALL DebugOnlyReadWholeBlockingFileAsString(const std::string &fileName);
void BABYLON_SDK_CALL DebugOnlyWriteWholeFile(const std::string &fileName, const std::string &data);

std::string BABYLON_SDK_CALL GetTempDirectory();

// Returns the temp directory with a slash. Throws on error
std::string BABYLON_SDK_CALL GetScratchDirectory();

std::vector<byte> BABYLON_SDK_CALL ReadChunkFromFile(Babylon::Utils::File::BinaryFileReader& f, size_t filePointer, size_t numBytes);

/**
* Given a full file path, the method will return the directory the file is in.
* For example, given C:\Temp\File.txt, the method returns C:\Temp\ - including the trailing '\'
*/
std::string BABYLON_SDK_CALL GetDirectory(const std::string& fullpath);

/**
* Return the length of the passed-in file stream
*/
std::size_t BABYLON_SDK_CALL GetFileStreamSize(std::ifstream& stream);

/**
 * Return the contents of a file in a byte array
 */
std::vector<uint8_t> BABYLON_SDK_CALL GetFileContents(const std::string& path);

std::string BABYLON_SDK_CALL GetFileBaseName(const std::string& inFileName);

std::string GetBasePath(const std::string& path);
} // namespace IO

} // namespace Utils

} // namespace Babylon
