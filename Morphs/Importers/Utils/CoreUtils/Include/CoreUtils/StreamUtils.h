#pragma once
/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "StringUtils.h"
#include "SmartThrow.h"

#include <array>
#include <deque>
#include <memory>
#include <fstream>

namespace Babylon
{
    namespace Utils
    {
        // ConvertStreamToDeque

        // Not knowing the size of the stream, the safest thing to do is
        // to load it in chucks into a data struct that supports appends efficently.
        // Downside to this technique is that when converting to a string later we need to hold two copies of the data
        //
        // Orginal code by Indi
        // How to read an entire file into memory in C++ by Explicit C++ is licensed under a Creative Commons Attribution 4.0 International License.
        // http://cpp.indi.frih.net/blog/2014/09/how-to-read-an-entire-file-into-memory-in-cpp/
        // Modifed for readability
        //
        // usage:
        // auto dq = ConvertStreamToDeque<char>(stream);
        template <typename CharT, typename Traits,
            typename CharO = CharT,
            typename Allocator = std::allocator<CharO>>
            auto ConvertStreamToDeque(
                std::basic_istream<CharT, Traits>& stream,
                Allocator alloc = {})
        {
            static_assert(
                std::is_same<CharT, CharO>::value ||
                std::is_same<std::make_unsigned_t<CharT>,
                CharO>::value ||
                std::is_same<std::make_signed_t<CharT>,
                CharO>::value,
                "char type of deque must be same "
                "as stream char type "
                "(possibly signed or unsigned)");

            auto const kChunkSize = std::size_t{ BUFSIZ };
            auto container = std::deque<CharO, Allocator>(std::move(alloc));
            auto chunk = std::array<CharO, kChunkSize>{};

            // Note the last read will be false when it can't read an entire chunk, thats when we check gcount() for partial reads
            while (stream.read(reinterpret_cast<CharT*>(chunk.data()), chunk.size()) || stream.gcount())
            {
                container.insert(container.end(), chunk.begin(), chunk.begin() + static_cast<ptrdiff_t>(stream.gcount()));
            }
            return container;
        }

#ifdef _WIN32 // Unicode filename support is only available via Windows specific 'wide' stream constructors
        inline std::shared_ptr<std::ifstream> CreateSharedInputFileStream(const std::wstring& filename, std::ios_base::openmode mode = std::ios_base::in)
        {
            return std::make_shared<std::ifstream>(filename, mode);
        }

        inline std::shared_ptr<std::ifstream> CreateSharedInputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::in)
        {
            return CreateSharedInputFileStream(Babylon::Utils::StringToWString(filename), mode);
        }

        inline std::shared_ptr<std::ofstream> CreateSharedOutputFileStream(const std::wstring& filename, std::ios_base::openmode mode = std::ios_base::out)
        {
            return std::make_shared<std::ofstream>(filename, mode);
        }

        inline std::shared_ptr<std::ofstream> CreateSharedOutputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::out)
        {
            return CreateSharedOutputFileStream(Babylon::Utils::StringToWString(filename), mode);
        }

        inline std::unique_ptr<std::ifstream> CreateUniqueInputFileStream(const std::wstring& filename, std::ios_base::openmode mode = std::ios_base::in)
        {
            return std::make_unique<std::ifstream>(filename, mode);
        }

        inline std::unique_ptr<std::ifstream> CreateUniqueInputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::in)
        {
            return CreateUniqueInputFileStream(Babylon::Utils::StringToWString(filename), mode);
        }

        inline std::unique_ptr<std::ofstream> CreateUniqueOutputFileStream(const std::wstring& filename, std::ios_base::openmode mode = std::ios_base::out)
        {
            return std::make_unique<std::ofstream>(filename, mode);
        }

        inline std::unique_ptr<std::ofstream> CreateUniqueOutputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::out)
        {
            return CreateUniqueOutputFileStream(Babylon::Utils::StringToWString(filename), mode);
        }
#else // For the time being assume all other platforms accept UTF-8 filenames
        inline std::shared_ptr<std::ifstream> CreateSharedInputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::in)
        {
            return std::make_shared<std::ifstream>(filename, mode);
        }

        inline std::shared_ptr<std::ofstream> CreateSharedOutputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::out)
        {
            return std::make_shared<std::ofstream>(filename, mode);
        }

        inline std::unique_ptr<std::ifstream> CreateUniqueInputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::in)
        {
            return std::make_unique<std::ifstream>(filename, mode);
        }

        inline std::unique_ptr<std::ofstream> CreateUniqueOutputFileStream(const std::string& filename, std::ios_base::openmode mode = std::ios_base::out)
        {
            return std::make_unique<std::ofstream>(filename, mode);
        }
#endif

        inline size_t GetIStreamLength(std::istream& stream)
        {
            // Get the length of the stream before reading anything, to validate against later
            // NOTE: The approach used below with seekg to the end and then tellg may be problematic since
            // seekg is not guaranteed to give the number of bytes from the start of the file:
            // see http://stackoverflow.com/a/22986486. This is used elsewhere in the code though,
            // and seems to Do The Right Thing as of right now. TODO: discuss fixing this problem.
            const auto curPos = stream.tellg();
            stream.seekg(0, std::ios::end);
            auto length = stream.tellg(); // in bytes (i.e. sizeof(char))
            stream.seekg(curPos); // reset the stream pointer where it was

            return static_cast<size_t>(length);
        }

        inline std::unique_ptr<uint8_t[]> ReadStreamIntoUniquePtr(std::istream& stream, size_t& length)
        {
            stream.seekg(0, std::ios::end);
            length = static_cast<size_t>(std::max(stream.tellg(), std::streampos(0))); // Guard against tellg returning -1 (EOF) by using std::max to ensure a stream 'size' is always greater than or equal to zero

            std::unique_ptr<uint8_t[]> data = std::make_unique<uint8_t[]>(length);

            stream.seekg(0, std::ios::beg);
            stream.read(reinterpret_cast<char*>(data.get()), length);

            if (static_cast<size_t>(stream.gcount()) != length)
            {
                throw BabylonException("Failed to read the entire stream");
            }
            
            return data;
        }

        inline std::streamsize SafeRead(std::istream& stream, char* buffer, std::streamsize count)
        {
            stream.read(buffer, count);

            if (stream.eof())
            {
                stream.clear();
            }

            return stream.gcount();
        }
    }
}
