#pragma once

/********************************************************
*                                                      *
*    Copyright (C) Microsoft. All rights reserved.     *
*                                                      *
********************************************************/

#pragma once

/// \file      BasicMemoryStream.h
/// \brief     A std::istream derived type that wraps an array
/// \copyright Copyright (C) Microsoft. All rights reserved.

#include <istream>
#include <memory>


namespace Babylon
{
    namespace Utils
    {

        template<typename T>
        class BasicMemoryViewStreamBuf : public std::basic_streambuf<T>
        {
        public:
            using typename std::basic_streambuf<T>::char_type;
            using typename std::basic_streambuf<T>::int_type;
            using typename std::basic_streambuf<T>::pos_type;
            using typename std::basic_streambuf<T>::off_type;
            using typename std::basic_streambuf<T>::traits_type;
            using std::basic_streambuf<T>::setg;
            using std::basic_streambuf<T>::eback;
            using std::basic_streambuf<T>::gptr;
            using std::basic_streambuf<T>::egptr;

            BasicMemoryViewStreamBuf(T* const buffer, size_t count)
            {
                T* const pbeg = buffer;
                T* const pend = buffer + count;

                setg(pbeg, pbeg, pend);
            }

            int_type overflow(int_type) override
            {
                return traits_type::eof(); // No support for writing
            }

            int_type underflow() override
            {
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
                if (which & std::ios_base::out)
                {
                    return traits_type::eof();
                }

                char_type* new_gptr = gptr();

                switch (dir)
                {
                case std::ios_base::beg:
                    new_gptr = eback();
                    break;
                case std::ios_base::end:
                    new_gptr = egptr();
                    break;
                }

                new_gptr += off;

                if (new_gptr < eback() ||
                    new_gptr > egptr())
                {
                    return traits_type::eof();
                }
                else
                {
                    setg(eback(), new_gptr, egptr());
                }

                return gptr() - eback();
            }
        };

        template<typename T>
        class BasicMemoryStreamBuf : public BasicMemoryViewStreamBuf<T>
        {
        public:
            using typename BasicMemoryViewStreamBuf<T>::char_type;
            using typename BasicMemoryViewStreamBuf<T>::int_type;
            using typename BasicMemoryViewStreamBuf<T>::pos_type;
            using typename BasicMemoryViewStreamBuf<T>::off_type;
            using typename BasicMemoryViewStreamBuf<T>::traits_type;
            using BasicMemoryViewStreamBuf<T>::setg;
            using BasicMemoryViewStreamBuf<T>::eback;
            using BasicMemoryViewStreamBuf<T>::gptr;
            using BasicMemoryViewStreamBuf<T>::egptr;

            BasicMemoryStreamBuf(std::unique_ptr<T[]>&& buffer, size_t count) : BasicMemoryViewStreamBuf<T>(buffer.get(), count), m_buffer(std::move(buffer))
            {
            }

        private:
            std::unique_ptr<T[]> m_buffer;
        };

        template<typename T>
        class BasicMemoryStream : public std::basic_istream<T>
        {
        public:
            BasicMemoryStream(std::unique_ptr<T[]>&& buffer, size_t count) : std::basic_istream<T>(&m_streamBuf, std::ios::in),
                m_streamBuf(std::move(buffer), count) {}

        private:
            BasicMemoryStreamBuf<T> m_streamBuf;
        };

        template<typename T>
        class BasicMemoryViewStream : public std::basic_istream<T>
        {
        public:
            BasicMemoryViewStream(T* const buffer, size_t count) : std::basic_istream<T>(&m_streamBuf),
                m_streamBuf(buffer, count) {}

        private:
            BasicMemoryViewStreamBuf<T> m_streamBuf;
        };
    }
}
