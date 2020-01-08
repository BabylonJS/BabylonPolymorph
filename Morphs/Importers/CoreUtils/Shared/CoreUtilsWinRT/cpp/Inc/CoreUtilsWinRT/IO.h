/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Windows.Storage.Streams.h>

//#include <CoreUtils/LexicalCast.h>
#include <wrl.h>
#include <ppltasks.h>

namespace Spectre
{

    namespace UtilsWinRT
    {

        namespace IO
        {
            concurrency::task<Windows::Storage::StorageFolder^> GetPersistentDirectoryStorageFolder();     // Never empty on boot
            concurrency::task<Windows::Storage::StorageFolder^> GetTempDirectoryStorageFolder();           // Might be empty on boot
            concurrency::task<Windows::Storage::StorageFolder^> GetScratchDirectoryStorageFolder();        // Always empty on boot

            std::string GetPersistentDirectory();

            void CreateDirectory(Platform::String^ directory);
            bool FileExists(Windows::Storage::StorageFolder^ folder, Platform::String^ fileName);

            std::vector<std::wstring> GetFilesInDirectory(std::wstring const& path, std::wstring const& filter);
        }

    }

}
