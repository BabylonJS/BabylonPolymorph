/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsWinRtPch.h"

#include <CoreUtilsWinRT/IO.h>
#include <CoreUtils/LexicalCast.h>
#include <CoreUtilsWinRT/SmartThrow.h>
#include <CoreUtilsWinRT/Path.h>

#include <collection.h>
#include <ppltasks.h>
#include <string>
#include <wrl.h>
#include <wrl/implements.h>

using namespace concurrency;
using namespace Platform;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;
using namespace Microsoft::WRL;

using concurrency::task;

namespace Spectre
{

    namespace UtilsWinRT
    {

        namespace IO
        {
            concurrency::task<Windows::Storage::StorageFolder^> GetPersistentDirectoryStorageFolder()
            {
                concurrency::task_completion_event<Windows::Storage::StorageFolder^> tce;
                tce.set(Windows::Storage::ApplicationData::Current->LocalFolder);
                return concurrency::create_task(tce);
            }

            //--------------------------------------------------------------------------------

            concurrency::task<Windows::Storage::StorageFolder^> GetTempDirectoryStorageFolder()
            {
                return concurrency::create_task(Windows::Storage::ApplicationData::Current->TemporaryFolder->CreateFolderAsync(L"Temp", Windows::Storage::CreationCollisionOption::OpenIfExists));
            }

            //--------------------------------------------------------------------------------

            concurrency::task<Windows::Storage::StorageFolder^> GetScratchDirectoryStorageFolder()
            {
                return concurrency::create_task(Windows::Storage::ApplicationData::Current->TemporaryFolder->CreateFolderAsync(L"Scratch", Windows::Storage::CreationCollisionOption::OpenIfExists));
            }

            //--------------------------------------------------------------------------------

            void CreateDirectory(Platform::String^ directory)
            {
                BOOL success = ::CreateDirectoryW(directory->Data(), nullptr);
                if (!success)
                {
                    DWORD lastError = ::GetLastError();
                    if (lastError != ERROR_ALREADY_EXISTS)
                    {
                        throw Utils::SpectreWinRTException(HRESULT_FROM_WIN32(lastError), "Could not get a temporary folder.");
                    }
                }
            }

            //--------------------------------------------------------------------------------

            std::string GetPersistentDirectory()
            {
                return Utils::LexicalCast<std::string>(Windows::Storage::ApplicationData::Current->LocalFolder->Path + L"\\");
            }

            //--------------------------------------------------------------------------------

            std::string GetScratchDirectory()
            {
                auto dirPath = (Windows::Storage::ApplicationData::Current->TemporaryFolder->Path + L"\\Scratch");
                BOOL success = ::CreateDirectoryW(dirPath->Data(), nullptr);
                if (!success)
                {
                    DWORD lastError = ::GetLastError();
                    if (lastError != ERROR_ALREADY_EXISTS)
                    {
                        throw Utils::SpectreException("Could not get a temporary folder.");
                    }
                }
                return Utils::LexicalCast<std::string>(dirPath + L"\\");
            }

            //--------------------------------------------------------------------------------

            std::vector<std::wstring> GetFilesInDirectory(std::wstring const& path, std::wstring const& filter = L"")
            {
                SpectreUnusedParameter(path);
                SpectreUnusedParameter(filter);

                StorageFolder^ folder = ApplicationData::Current->LocalFolder;
                std::vector<std::wstring> outFiles;

                try
                {
                    create_task(folder->GetFilesAsync()).then([folder, &outFiles](IVectorView<StorageFile^>^ files)
                    {
                        std::locale loc;
                        //auto vec = ref new Platform::Collections::Vector < StorageFile^ >;
                        std::for_each(begin(files), end(files), [&outFiles](StorageFile^ file)
                        {
                            auto path = ref new Path(file->Path);
                            outFiles.push_back(Utils::LexicalCast<std::wstring>(path->Filename));
                        });
                    });

                }
                catch (Platform::Exception^ ex)
                {
                    auto msg = Spectre::Utils::LexicalCast<std::string>(ex->Message);
                    (void)msg;
                }
                return outFiles;
            }

            //--------------------------------------------------------------------------------

            bool FileExists(StorageFolder^ folder, Platform::String^ fileName)
            {
                try
                {
                    create_task(folder->GetFileAsync(fileName)).get();
                    return true;
                }
                catch (Platform::Exception^ ex)
                {
                    return false;
                }
            }

            //--------------------------------------------------------------------------------
        } // namespace IO

    } // namespace Utils

} // namespace Spectre
