#pragma once
/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
#include <iostream>

/*****************************************************

MemoryStream : A stream adapter for raw memory.
               By default, it assumes you want a binary stream.
               For non-binary streams, I would suggest using stringstream.
               Only supports reading. Could easily be extended for writing, but I don't
               have time for the extra testing required.

******************************************************/

namespace Spectre
{
    namespace Plugins
    {
        struct MemoryStream : public std::istream
        {
            struct membuf : std::streambuf
            {
                char* start;
                char* end;
                membuf(char* base, std::size_t size)
                    : start(base)
                    , end( base+size )
                {
                    this->setp(base, base + size);
                    this->setg(base, base, base + size);
                }
                std::size_t written() const { return this->pptr() - this->pbase(); }
                std::size_t read() const { return this->gptr() - this->eback(); }

                pos_type seekoff(off_type off, ios_base::seekdir way, ios_base::openmode om) override
                {
                    if (om&out)
                        throw std::runtime_error("MemoryStream does not fully support write modes");
                    pos_type offset;
                    switch (way)
                    {
                    case  std::ios_base::beg:
                        offset = 0;
                        break;
                    case  std::ios_base::cur:
                        offset = gptr()- eback();
                        break;
                    case  std::ios_base::end:
                        offset = egptr() - eback();
                        break;
                    }
                    offset += off;
                    if(offset < 0)                          // protect against under-write
                        this->setg(eback(), eback(), egptr());
                    else if(offset >= (egptr() - eback()))   // protect against over-write
                        this->setg(eback(), egptr(), egptr());
                    else
                        this->setg(eback(), eback() +static_cast<ptrdiff_t>(offset), egptr());
                    return gptr() - eback();
                }

                pos_type seekpos(pos_type pos, ios_base::openmode om) override
                {
                    if (om&out)
                        throw std::runtime_error("MemoryStream does not fully support write modes");
                    if (pos < 0)                          // protect against under-write
                        this->setg(eback(), eback(), egptr());
                    else if (pos >= (egptr() - eback()))   // protect against over-write
                        this->setg(eback(), egptr(), egptr());
                    else
                        this->setg(eback(), eback() + static_cast<ptrdiff_t>(pos), egptr());

                    return gptr() - eback();
                }
            };
            membuf       sbuf;

            MemoryStream(void* data, size_t size)
                : std::istream(&sbuf)
                , sbuf((char*)data, size)   // char is arbitrary, but should should byte sized
            {
                noskipws(*this);    // disable skipping eol/tabs/etc
            }
        };
    }
}