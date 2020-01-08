#pragma once

/********************************************************
*                                                      *
*    Copyright (C) Microsoft. All rights reserved.     *
*                                                      *
********************************************************/

#pragma once

/// \file      BasicVectorStream.h
/// \brief     A std::istream derived type that wraps a std::vector
/// \copyright Copyright (C) Microsoft. All rights reserved.

#include <istream>
#include <vector>

#include <CoreUtils/Assert.h>

namespace Spectre
{
    namespace Utils
    {
        template<typename T>
        class BasicVectorStreamBuf : public std::basic_streambuf<T>
        {
        public:
            // These usings are necessary because of two-phase compilation, specifically
            // that MSVC doesn't strictly adhere to the standard.
            using typename std::basic_streambuf<T>::char_type;
            using typename std::basic_streambuf<T>::int_type;
            using typename std::basic_streambuf<T>::pos_type;
            using typename std::basic_streambuf<T>::off_type;
            using typename std::basic_streambuf<T>::traits_type;
            using std::basic_streambuf<T>::setp;
            using std::basic_streambuf<T>::setg;
            using std::basic_streambuf<T>::eback;
            using std::basic_streambuf<T>::gptr;
            using std::basic_streambuf<T>::egptr;
            using std::basic_streambuf<T>::pbase;
            using std::basic_streambuf<T>::pptr;
            using std::basic_streambuf<T>::epptr;
            using std::basic_streambuf<T>::pbump;

            BasicVectorStreamBuf(std::vector<T>&& buffer = {}, size_t bufferMaxIncrement = 1024U * 1024U) :
                m_buffer(std::move(buffer)),
                m_bufferMaxIncrement(bufferMaxIncrement)
            {
                T* const pbeg = m_buffer.data();
                T* const pend = m_buffer.data() + m_buffer.size();

                setp(pend, pend);
                setg(pbeg, pbeg, pend);
            }

            int_type overflow(int_type ch) override
            {
                if (traits_type::eq_int_type(ch, traits_type::eof()))
                {
                    return traits_type::not_eof(ch);
                }

                SpectreAssert(pptr() == epptr());

                const auto pdelta = pptr() - pbase();
                const auto gdelta = gptr() - eback();

                const size_t bufferSize = m_buffer.size();

                SpectreAssert(bufferSize == static_cast<size_t>(pdelta));
                SpectreAssert(bufferSize >= static_cast<size_t>(gdelta));

                // If the current buffer is empty then increase its size to one
                // If the current buffer isn't empty then double its size, limiting the increase in size to m_bufferMaxIncrement
                m_buffer.resize(bufferSize + std::min(bufferSize > 0 ? bufferSize : 1U, m_bufferMaxIncrement));

                T* const ptr = m_buffer.data();
                T* const ptrEnd = ptr + m_buffer.size();

                setp(ptr, ptrEnd);
                setg(ptr, ptr + gdelta, ptr + pdelta);

                // Increment pptr by one after writing to the current 'put' location
                pbump(static_cast<int>(pdelta));
                *pptr() = traits_type::to_char_type(ch);
                pbump(1);

                return ch;
            }

            int_type underflow() override
            {
                SpectreAssert(gptr() == egptr());
                SpectreAssert(pptr() >= egptr());

                // Update egptr as additional data may have been written to the 'put' area
                setg(eback(), gptr(), pptr());

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
                if (which & std::ios_base::in)
                {
                    // Don't allow seeking within the 'put' and 'get' areas at the same time
                    if (which & std::ios_base::out)
                    {
                        return traits_type::eof();
                    }

                    char_type* gptrNew;
                    switch (dir)
                    {
                    case std::ios_base::beg:
                        gptrNew = eback();
                        break;
                    case std::ios_base::end:
                        gptrNew = pptr();
                        break;
                    case std::ios_base::cur:
                    default:
                        gptrNew = gptr();
                        break;
                    }

                    gptrNew += off;

                    if (gptrNew < eback() ||
                        gptrNew > pptr())
                    {
                        return traits_type::eof();
                    }
                    else
                    {
                        setg(eback(), gptrNew, pptr());
                    }

                    return gptr() - eback();
                }

                if (which & std::ios_base::out)
                {
                    // Don't allow seeking within the 'put' and 'get' areas at the same time
                    if (which & std::ios_base::in)
                    {
                        return traits_type::eof();
                    }

                    char_type* pptrNew;
                    switch (dir)
                    {
                    case std::ios_base::beg:
                        pptrNew = pbase();
                        break;
                    case std::ios_base::end:
                        pptrNew = pptr();
                        break;
                    case std::ios_base::cur:
                    default:
                        pptrNew = pptr();
                        break;
                    }

                    pptrNew += off;

                    if (pptrNew < pbase() ||
                        pptrNew > pptr())
                    {
                        return traits_type::eof();
                    }
                    else
                    {
                        pbump(static_cast<int>(pptrNew - pptr()));
                    }

                    return pptr() - pbase();
                }

                return traits_type::eof();
            }

            const std::vector<T>& GetVector() const
            {
                return m_buffer;
            }

            size_t GetVectorCount() const
            {
                return pptr() - pbase();
            }

        private:
            std::vector<T> m_buffer;
            const size_t   m_bufferMaxIncrement;
        };

        template<typename T>
        class BasicVectorStream : public std::basic_iostream<T>
        {
        public:
            BasicVectorStream(std::vector<T>&& buffer = {}, size_t bufferMaxIncrement = 1024U * 1024U) : std::basic_iostream<T>(&m_streamBuf),
                m_streamBuf(std::move(buffer), bufferMaxIncrement) {}

        private:
            BasicVectorStreamBuf<T> m_streamBuf;
        };
    }
}
