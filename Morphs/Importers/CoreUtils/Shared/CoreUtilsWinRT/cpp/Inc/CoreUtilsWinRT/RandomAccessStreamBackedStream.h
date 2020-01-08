/********************************************************
*                                                      *
*    Copyright (C) Microsoft. All rights reserved.     *
*                                                      *
********************************************************/

#pragma once

/// \file      RandomAccessStreamBackedStream.h
/// \brief     A std::istream derived type that wraps a UWP IRandomAccessStream interface
/// \copyright Copyright (C) Microsoft. All rights reserved.

#include "NativeBufferAdapter.h"

#include <algorithm>
#include <istream>
#include <streambuf>

namespace Spectre
{
    namespace UtilsWinRT
    {
        //-------------------------------------------------------------------
        // Important:  This class does not currently support being an iostream.  It supports istream or
        // ostream.  In order to support iostream we need to handle the read and write windows overlapping.
        //
        // Notes:
        // For read m_stream->Position has two states:
        //  When setg has been called with nullptr it will be set to the position we want to read from next.
        //  When setg has been called with real data, it will be set to the end of the section that was read in.
        //      This WAS why m_stream->Position + (bufferBegin - bufferEnd) gave us the beginning position of the read area.
        //      m_readBufferDesiredPosition replaces m_stream->Position so an i/o stream could potentially exist, and maintains this behavior.
        // For write, m_writeBufferDesiredPosition has the same behavior.  When a buffer needs to be created
        // to write to it is desired it is the location for the start of the buffer.  While a buffer exists
        // it is the end of the the write buffer and m_writeBufferBasePosition is the beginning.

        template<typename T, std::ios::openmode _Mode>
        class RandomAccessStreamBackedStreamBuf : public std::basic_streambuf<T>
        {
            static_assert(_Mode == std::ios::in || _Mode == std::ios::out, "RandomAccessStreamBackedStreamBuf only supports istream or ostream, not iostream currently!");
            static constexpr unsigned int DefaultBufferSize = 4096U;

        public:
            using typename std::basic_streambuf<T>::int_type;
            using typename std::basic_streambuf<T>::pos_type;
            using typename std::basic_streambuf<T>::off_type;

            RandomAccessStreamBackedStreamBuf(Windows::Storage::Streams::IRandomAccessStream^ ras, unsigned int bufferSize = DefaultBufferSize) :
                m_stream{ ras },
                m_readBuffer{},
                m_writeBuffer{},
                m_readBufferDesiredPosition{ static_cast<off_type>(m_stream->Position) },
                m_writeBufferBasePosition{ static_cast<off_type>(m_stream->Position) },
                m_writeBufferDesiredPosition{ static_cast<off_type>(m_stream->Position) },
                m_bufferSize{bufferSize}
            {
                if (bufferSize > static_cast<unsigned int>(std::numeric_limits<int>::max()))
                {
                    throw std::runtime_error("Pointer arithmetic is done with a signed type, so we must limit buffer size to less than std::numeric_limits<int>::max() to work on 32 bit platforms.");
                }

                setg(nullptr, nullptr, nullptr);
                setp(nullptr, nullptr);
            }

            virtual ~RandomAccessStreamBackedStreamBuf()
            {
                FlushWriteBuffer();
            }

        protected:
            int_type overflow(int_type ch) override
            {
                if (pptr() == epptr())
                {
                    CreateWriteBuffer();
                }

                if (pptr() == epptr())
                {
                    return traits_type::eof();
                }
                else
                {
                    if (traits_type::eq_int_type(ch, traits_type::eof()))
                    {
                        return traits_type::not_eof(ch);
                    }
                    else
                    {
                        return sputc(traits_type::to_char_type(ch));
                    }
                }
            }

            int_type underflow() override
            {
                if (gptr() == egptr())
                {
                    CreateReadBuffer();
                }

                return gptr() == egptr() ?
                    traits_type::eof() :
                    traits_type::to_int_type(*gptr());
            }

            pos_type seekpos(pos_type pos, std::ios_base::openmode which) override
            {
                return seekoff(pos, std::ios_base::beg, which);
            }

            pos_type seekoff(off_type off, std::ios_base::seekdir dir, std::ios_base::openmode which) override
            {
                if (which == (std::ios_base::in | std::ios_base::out))
                {
                    throw std::runtime_error("Seeking both input and output handles at once is unsupported.");
                }
                else if (which & std::ios_base::out)
                {
                    off_type new_ppos;

                    const auto pbeg = static_cast<off_type>(m_writeBufferBasePosition);
                    const auto pend = static_cast<off_type>(m_writeBufferBasePosition) + (epptr() - pbase());

                    switch (dir)
                    {
                    case std::ios_base::beg:
                        new_ppos = {};
                        break;
                    case std::ios_base::end:
                        new_ppos = static_cast<off_type>(m_stream->Size);
                        break;
                    case std::ios_base::cur:
                    default:
                        new_ppos = static_cast<off_type>(m_writeBufferBasePosition) + (pptr() - pbase());
                    }

                    new_ppos += off;

                    if (new_ppos < pbeg ||
                        new_ppos > pend)
                    {
                        if (new_ppos < off_type())
                        {
                            return traits_type::eof();
                        }
                        else
                        {
                            if (pptr() != pbase())
                            {
                                FlushWriteBuffer();
                            }

                            setp(nullptr,
                                nullptr);

                            m_writeBufferDesiredPosition = new_ppos;
                        }
                    }
                    else
                    {
                        auto desireOffset = new_ppos - m_writeBufferBasePosition;
                        auto currentOffset = pptr() - pbase();
                        pbump(static_cast<int>(desireOffset) - static_cast<int>(currentOffset));

                        m_currentWrittenLength = std::max(static_cast<unsigned int>(currentOffset), m_currentWrittenLength);
                    }

                    return new_ppos;
                }
                else if (which & std::ios_base::in)
                {
                    off_type new_gpos;

                    // Beginning and End indices of the current read buffer segment.
                    const auto gbeg = static_cast<off_type>(m_readBufferDesiredPosition) + (eback() - egptr());
                    const auto gend = static_cast<off_type>(m_readBufferDesiredPosition);

                    // Get the position to offset from.
                    switch (dir)
                    {
                    case std::ios_base::beg:
                        new_gpos = {};
                        break;
                    case std::ios_base::end:
                        new_gpos = static_cast<off_type>(m_stream->Size);
                        break;
                    case std::ios_base::cur:
                    default:
                        new_gpos = static_cast<off_type>(m_readBufferDesiredPosition) + (gptr() - egptr());
                    }

                    // Offset from the start position for this seek.
                    new_gpos += off;

                    // If the new position is outside of the loaded range...
                    if (new_gpos < gbeg ||
                        new_gpos > gend)
                    {
                        // If the new position is outside of the buffer range, return eof.
                        if (new_gpos < off_type() ||
                            new_gpos > static_cast<off_type>(m_stream->Size))
                        {
                            return traits_type::eof();
                        }
                        else
                        {
                            // Otherwise, clear the buffer pointers and set the position to read from.
                            setg(nullptr,
                                nullptr,
                                nullptr);

                            m_readBufferDesiredPosition = new_gpos;
                        }
                    }
                    else
                    {
                        // Otherwise, shift gptr() to the correct spot in the current buffer segment.
                        setg(eback(), (new_gpos - gend) + egptr(), egptr());
                    }

                    // Return the effective current position in the buffer.
                    return new_gpos;
                }

                return traits_type::eof();
            }

        private:
            void CreateReadBuffer()
            {
                Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer^, unsigned int>^ readOperation;

                try
                {
                    m_readBuffer = ref new Windows::Storage::Streams::Buffer(m_bufferSize);

                    m_stream->Seek(m_readBufferDesiredPosition);

                    readOperation = m_stream->ReadAsync(
                        m_readBuffer,
                        m_readBuffer->Capacity,
                        Windows::Storage::Streams::InputStreamOptions::None);
                }
                catch (Platform::Exception^ ex)
                {
                    throw std::runtime_error("The call to IRandomAccessStream::ReadAsync failed");
                }

                // We can't do readOperation.get() because it's "Illegal to wait on a task in a Windows Runtime STA"
                // This violates the spirit of the Parallel Patterns Library (PPL), but we need this to be a blocking
                // call see: http://stackoverflow.com/questions/19917466/how-to-wait-for-an-iasyncaction
                while (readOperation->Status == Windows::Foundation::AsyncStatus::Started)
                {
                    std::this_thread::yield();
                }

                if (readOperation->Status != Windows::Foundation::AsyncStatus::Completed)
                {
                    throw std::runtime_error("could not read buffer");
                }

                try
                {
                    // ReadAsync is not guaranteed to use the buffer you pass in, so get the buffer it used.
                    m_readBuffer = readOperation->GetResults();

                    Spectre::UtilsWinRT::WritableBuffer writableBuffer(m_readBuffer);
                    T* const bufferData = reinterpret_cast<T*>(writableBuffer.Data());

                    m_readBufferDesiredPosition += m_readBuffer->Length;

                    setg(bufferData,
                        bufferData,
                        bufferData + m_readBuffer->Length);
                }
                catch (Platform::Exception^ ex)
                {
                    throw std::runtime_error("Unable to get bytes from IBuffer");
                }
            }

            void CreateWriteBuffer()
            {
                Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer^, unsigned int>^ readOperation;

                FlushWriteBuffer();

                try
                {
                    m_writeBuffer = ref new Windows::Storage::Streams::Buffer(m_bufferSize);

                    m_stream->Seek(m_writeBufferDesiredPosition);

                    readOperation = m_stream->ReadAsync(
                        m_writeBuffer,
                        m_writeBuffer->Capacity,
                        Windows::Storage::Streams::InputStreamOptions::None);
                }
                catch (Platform::Exception^ ex)
                {
                    throw std::runtime_error("The call to IRandomAccessStream::ReadAsync failed");
                }

                // We can't do readOperation.get() because it's "Illegal to wait on a task in a Windows Runtime STA"
                // This violates the spirit of the Parallel Patterns Library (PPL), but we need this to be a blocking
                // call see: http://stackoverflow.com/questions/19917466/how-to-wait-for-an-iasyncaction
                while (readOperation->Status == Windows::Foundation::AsyncStatus::Started)
                {
                    std::this_thread::yield();
                }

                if (readOperation->Status != Windows::Foundation::AsyncStatus::Completed)
                {
                    throw std::runtime_error("could not read buffer");
                }

                try
                {
                    // ReadAsync is not guaranteed to use the buffer you pass in, so get the buffer it used.
                    m_writeBuffer = static_cast<Windows::Storage::Streams::Buffer^>(readOperation->GetResults());

                    Spectre::UtilsWinRT::WritableBuffer writableBuffer(m_writeBuffer);
                    T* const bufferData = reinterpret_cast<T*>(writableBuffer.Data());

                    m_writeBufferBasePosition = m_writeBufferDesiredPosition;
                    m_writeBufferDesiredPosition += m_writeBuffer->Capacity;

                    setp(bufferData,
                        bufferData + m_writeBuffer->Capacity);
                }
                catch (Platform::Exception^ ex)
                {
                    throw std::runtime_error("Unable to get bytes from IBuffer");
                }
            }

            void FlushWriteBuffer()
            {
                if (m_writeBuffer)
                {
                    try
                    {
                        // The result of the pointer arithmetic is signed, and we need an unsigned int.
                        auto length = pptr() - pbase();

                        m_currentWrittenLength = std::max(static_cast<unsigned int>(length), m_currentWrittenLength);

                        // BufferSize was checked to not be greater than INT_MAX in the constructor due to 32 bit signed pointer arithmathic limiting us to that range.
                        // This means unless we have overwritten the buffer we can safely cast to an unsigned int here.
                        m_writeBuffer->Length = m_currentWrittenLength;
                        m_currentWrittenLength = 0;

                        m_stream->Seek(m_writeBufferBasePosition);
                        auto writeOperation = m_stream->WriteAsync(m_writeBuffer);

                        while (writeOperation->Status == Windows::Foundation::AsyncStatus::Started)
                        {
                            std::this_thread::yield();
                        }

                        m_writeBuffer = nullptr;
                    }
                    catch (Platform::Exception^ ex)
                    {
                        throw std::runtime_error("The call to IRandomAccessStream::WriteAsync failed");
                    }
                }
            }

            Windows::Storage::Streams::IRandomAccessStream^ m_stream;
            Windows::Storage::Streams::IBuffer^ m_readBuffer;
            Windows::Storage::Streams::Buffer^ m_writeBuffer;
            off_type m_readBufferDesiredPosition;
            off_type m_writeBufferBasePosition;
            off_type m_writeBufferDesiredPosition;

            unsigned int m_currentWrittenLength{ 0 };

            const unsigned int m_bufferSize;
        };

        //-------------------------------------------------------------------

        template<typename T>
        class RandomAccessStreamBackedStream : public std::basic_istream<T>
        {
        public:
            RandomAccessStreamBackedStream(Windows::Storage::Streams::IRandomAccessStream^ ras)
                : std::basic_istream<T>(&m_buffer), m_buffer(ras)
            {
            }

        private:
            RandomAccessStreamBackedStreamBuf<T, std::ios::in> m_buffer;
        };

        //-------------------------------------------------------------------

        template<typename T>
        class RandomAccessStreamBackedOutStream : public std::basic_ostream<T>
        {
        public:
            RandomAccessStreamBackedOutStream(Windows::Storage::Streams::IRandomAccessStream^ ras)
                : std::basic_ostream<T>(&m_buffer), m_buffer(ras)
            {
            }

            RandomAccessStreamBackedOutStream(Windows::Storage::Streams::IRandomAccessStream^ ras, unsigned int bufferSize)
                : std::basic_ostream<T>(&m_buffer), m_buffer(ras, bufferSize)
            {
            }

        private:
            RandomAccessStreamBackedStreamBuf<T, std::ios::out> m_buffer;
        };

        //-------------------------------------------------------------------
    }
}
