/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <vector>
#include <cstdint>

#include <Framework/IBuffer.h>
#include <CoreUtils/Assert.h>

namespace Babylon
{
namespace Framework
{

/**
 * Manages a memory buffer - a raw blob of bytes. It doesn't care what you
 * write into the buffer, and in what endianess. That is the caller's
 * responsibility.
 */
class MemoryBuffer : public IBuffer
{
public:
    MemoryBuffer(uint32_t minimumSizeInBytes = 1024 * 1024)
    {
        m_buffer.reserve(minimumSizeInBytes);
    }

    virtual ~MemoryBuffer()
    {
    }

    /**
     * Writes raw data in the buffer. The alignment argument, will cause the
     * data to be written to the specified aligned address
     */
    inline virtual uint32_t WriteDataRaw(_In_reads_(sizeInBytes) const void* data, uint32_t sizeInBytes, uint32_t align = 1)
    {
        BabylonAssertExpr(align == 1 || align == 2 || align == 4, "MemoryBuffer::Write - Alignement must be 1, 2 or 4");
        uint32_t top = static_cast<uint32_t>(m_buffer.size());

        uint32_t alignedTop = (top + (align - 1)) & (~(align - 1));
        uint32_t padding = alignedTop - top;

        m_buffer.resize(m_buffer.size() + sizeInBytes + padding);
        memcpy(&m_buffer[top + padding], data, sizeInBytes);
        return top + padding;
    }

    /**
     * Reserve a contiguous section of the buffer large enough to fit the
     * specified number of bytes.
     *
     * \return The offset in the buffer where the reservation starts from
     */
    inline virtual uint32_t ReserveSpace(uint32_t sizeInBytes, uint32_t align)
    {
        BabylonAssertExpr(align == 1 || align == 2 || align == 4, "MemoryBuffer::Write - Alignement must be 1, 2 or 4");
        uint32_t top = static_cast<uint32_t>(m_buffer.size());

        uint32_t alignedTop = (top + (align - 1)) & (~(align - 1));
        uint32_t padding = alignedTop - top;

        m_buffer.resize(m_buffer.size() + sizeInBytes + padding);
        return top + padding;
    }

    virtual void TrimBytes(uint32_t numBytes)
    {
        if (numBytes > m_buffer.size())
        {
            m_buffer.clear();
            m_buffer.shrink_to_fit();
            return;
        }
        m_buffer.resize(m_buffer.size() - numBytes);
        m_buffer.shrink_to_fit();
    }

    /**
     * \return The offset in the buffer of the specified header
     */
    virtual uint32_t OffsetOf(const void* ptr) const
    {
        size_t addr = (size_t)ptr;
        size_t start = (size_t)(&m_buffer[0]);
        size_t end = start + m_buffer.size();

        if (addr < start || addr > end)
            return (uint32_t)-1;
        return (uint32_t)(addr - start);
    }

    virtual inline uint32_t GetSizeInBytes() const
    {
        return static_cast<uint32_t>(m_buffer.size());
    }

    virtual void* GetBuffer(uint32_t atOffset = 0)
    {
        BabylonAssertExpr(atOffset < m_buffer.size(), "MemoryBuffer: Invalid Offset for GetBuffer");
        return &m_buffer[atOffset];
    }

    inline void Reset()
    {
        m_buffer.clear();
        m_buffer.shrink_to_fit();
    }

private:
    MemoryBuffer(const MemoryBuffer& rhs);
    MemoryBuffer& operator=(const MemoryBuffer& other);

    std::vector<uint8_t> m_buffer;
};

} // End namespace Framework

} // End namespace Babylon
