/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#pragma warning(push)
#pragma warning(disable: 4467)
#include <robuffer.h>
#pragma warning(pop)

#include <vector>
#include <Windows.Storage.Streams.h>
#include <wrl.h>

#include <CoreUtils/IO.h>

namespace Spectre
{

namespace UtilsWinRT
{

namespace AWSS = ABI::Windows::Storage::Streams;
namespace MW = Microsoft::WRL;
namespace WSS = Windows::Storage::Streams;
namespace SU = Spectre::Utils;


namespace Wrl
{

HRESULT CreateNonOwningNativeBuffer(
    _In_reads_bytes_(numberOfBytes) void const* buffer,
    size_t numberOfBytes,
    MW::ComPtr<AWSS::IBuffer>& out
    );

HRESULT CreateOwningNativeBuffer(
    std::vector<SU::IO::byte>&& buffer,
    MW::ComPtr<AWSS::IBuffer>& out
    );

}

#ifdef __cplusplus_winrt

WSS::IBuffer^ CreateNonOwningNativeBuffer(std::vector<SU::IO::byte> const & buffer);
WSS::IBuffer^ CreateNonOwningNativeBuffer(void const* buffer, size_t numberOfBytes, bool align);

WSS::IBuffer^ CreateOwningNativeBuffer(std::vector<SU::IO::byte>&& buffer, bool align);
WSS::IBuffer^ CreateOwningNativeBuffer(void const* buffer, size_t numberOfBytes);

uint32_t GetRefCount(WSS::IBuffer^ buffer);

class ReadableBuffer
{
public:
    SU::IO::byte const* Data() const;
    size_t Size() const;

    explicit ReadableBuffer(WSS::IBuffer^ b);

private:
    MW::ComPtr<WSS::IBufferByteAccess> m_bufferByteAccess;
    size_t m_size;
};

class WritableBuffer
{
public:
    size_t Capacity() const;

    SU::IO::byte* Data(size_t s);
    SU::IO::byte* Data();

    WSS::IBuffer^ WinRtBuffer() const;

    explicit WritableBuffer(WSS::IBuffer^ b);

private:
    WSS::IBuffer^ m_buffer;
    MW::ComPtr<WSS::IBufferByteAccess> m_bufferByteAccess;
};

WritableBuffer CreateWritableBuffer(size_t capacity);

#endif

};

};
