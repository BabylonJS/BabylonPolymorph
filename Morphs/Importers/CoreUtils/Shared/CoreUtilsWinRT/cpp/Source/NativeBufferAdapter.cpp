/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsWinRtPch.h"

#include <memory>
#include <wrl.h>

#include <CoreUtils/Assert.h>
#include <CoreUtilsWinRT/NativeBufferAdapter.h>

namespace Spectre
{

namespace UtilsWinRT
{

namespace
{

class NativePointerBuffer : public MW::RuntimeClass<
    MW::RuntimeClassFlags<MW::WinRtClassicComMix>,
    AWSS::IBuffer,
    WSS::IBufferByteAccess
>
{
    InspectableClass(L"Utils.NativePointerBuffer", BaseTrust)

public: // IBuffer
    virtual STDMETHODIMP get_Capacity(_Out_ UINT32* capacity) override;
    virtual STDMETHODIMP get_Length(_Out_ UINT32* length) override;
    virtual STDMETHODIMP put_Length(UINT32 length) override;
    virtual STDMETHODIMP Buffer(_Outptr_result_buffer_(_Inexpressible_("size given by different API")) byte** buffer) override;

public:
    NativePointerBuffer();
    virtual ~NativePointerBuffer()
    {
        if (m_deleteOnDestroy)
        {
            delete[] m_buffer;
        }
    }

    HRESULT RuntimeClassInitialize(SU::IO::byte* buffer, UINT totalSize, bool deleteOnDestroy = false);

    virtual SU::IO::byte const* GetNativeBuffer() const;

private:
    NativePointerBuffer(const NativePointerBuffer& objectNotCopyable);
    NativePointerBuffer& operator=(const NativePointerBuffer& objectNotAssignable);

    SU::IO::byte*   m_buffer; // non owning
    UINT32      m_length;
    UINT32      m_capacity;
    bool        m_deleteOnDestroy;
};

//------------------------------------------------------------------------------

class NativeVectorBuffer : public MW::RuntimeClass<
    MW::RuntimeClassFlags<MW::WinRtClassicComMix>,
    AWSS::IBuffer,
    WSS::IBufferByteAccess
>
{
    InspectableClass(L"Utils.NativeVectorBuffer", BaseTrust)

public: // IBuffer
    virtual STDMETHODIMP get_Capacity(_Out_ UINT32* capacity) override;
    virtual STDMETHODIMP get_Length(_Out_ UINT32* length) override;
    virtual STDMETHODIMP put_Length(UINT32 length) override;
    virtual STDMETHODIMP Buffer(_Outptr_result_buffer_(_Inexpressible_("size given by different API")) byte** buffer) override;

public:
    NativeVectorBuffer();
    HRESULT RuntimeClassInitialize(std::vector<SU::IO::byte>&& data);

    virtual std::vector<SU::IO::byte> const & GetNativeBuffer() const;

private:
    NativeVectorBuffer(const NativeVectorBuffer& objectNotCopyable);
    NativeVectorBuffer& operator=(const NativeVectorBuffer& objectNotAssignable);

    std::vector<SU::IO::byte> m_data;
};

//------------------------------------------------------------------------------

STDMETHODIMP NativePointerBuffer::get_Capacity(_Out_ UINT32* capacity)
{
    *capacity = m_capacity;
    return S_OK;
}

//------------------------------------------------------------------------------

STDMETHODIMP NativePointerBuffer::get_Length(_Out_ UINT32* length)
{
    *length = m_length;
    return S_OK;
}

//------------------------------------------------------------------------------

STDMETHODIMP NativePointerBuffer::put_Length(UINT32 length)
{
    SpectreUnusedParameter(length);
    SpectreAssert(length <= m_capacity);
    m_length = length;
    return S_OK;
}

//------------------------------------------------------------------------------

STDMETHODIMP NativePointerBuffer::Buffer(_Outptr_result_buffer_(_Inexpressible_("size given by different API")) byte** buffer)
{
    *buffer = m_buffer;
    return S_OK;
}

//------------------------------------------------------------------------------

NativePointerBuffer::NativePointerBuffer()
    :
    m_buffer(nullptr),
    m_length(0),
    m_capacity(0),
    m_deleteOnDestroy(false)
{
    // Nothing
}

//------------------------------------------------------------------------------

HRESULT NativePointerBuffer::RuntimeClassInitialize(byte* buffer, UINT totalSize, bool deleteOnDestroy)
{
    m_deleteOnDestroy = deleteOnDestroy;
    m_buffer = buffer;
    m_length = totalSize;
    m_capacity = totalSize;
    return S_OK;
}

//------------------------------------------------------------------------------

SU::IO::byte const* NativePointerBuffer::GetNativeBuffer() const
{
    return m_buffer;
}

//------------------------------------------------------------------------------

STDMETHODIMP NativeVectorBuffer::get_Capacity(_Out_ UINT32* capacity)
{
    *capacity = static_cast<UINT32>(m_data.size());
    return S_OK;
}

//------------------------------------------------------------------------------

STDMETHODIMP NativeVectorBuffer::get_Length(_Out_ UINT32* length)
{
    *length = static_cast<UINT32>(m_data.size());
    return S_OK;
}

//------------------------------------------------------------------------------

STDMETHODIMP NativeVectorBuffer::put_Length(UINT32 length)
{
    SpectreUnusedParameter(length);
    SpectreAssert(length <= m_data.size());

    //TODO: Fix this to update the length.  There is no code that uses this in Canvas and no unit tests,
    // so I don't feel comfortable trying to fix it until we can test it.
    return S_OK;
}

//------------------------------------------------------------------------------

STDMETHODIMP NativeVectorBuffer::Buffer(_Outptr_result_buffer_(_Inexpressible_("size given by different API")) byte** buffer)
{
    *buffer = m_data.data();
    return S_OK;
}

//------------------------------------------------------------------------------

NativeVectorBuffer::NativeVectorBuffer()
{
    // Nothing
}

//------------------------------------------------------------------------------

HRESULT NativeVectorBuffer::RuntimeClassInitialize(std::vector<SU::IO::byte>&& buffer)
{
    m_data = std::move(buffer);
    return S_OK;
}

//------------------------------------------------------------------------------

std::vector<SU::IO::byte> const & NativeVectorBuffer::GetNativeBuffer() const
{
    return m_data;
}

//------------------------------------------------------------------------------

#ifdef __cplusplus_winrt
MW::ComPtr<WSS::IBufferByteAccess> GetBufferByteAccess(WSS::IBuffer^ b)
{
    MW::ComPtr<WSS::IBufferByteAccess> bba;
    auto hr = reinterpret_cast<IUnknown*>(b)->QueryInterface(IID_PPV_ARGS(&bba));
    SU::ThrowIfFailed(hr);

    return bba;
}
#endif // __cplusplus_winrt

}

namespace Wrl
{

HRESULT CreateNonOwningNativeBuffer(
    _In_reads_bytes_(numberOfBytes) void const* buffer,
    size_t numberOfBytes,
    MW::ComPtr<AWSS::IBuffer>& out
    )
{
    if (numberOfBytes > UINT_MAX)
    {
        SU::ThrowIfFailed(E_INVALIDARG);
    }

    DWORD size = static_cast<DWORD>(numberOfBytes);

    // We output a byte*, so we need to cast away from const
    auto untypedBuffer = const_cast<void *>(buffer);
    auto inputBuffer = static_cast<byte *>(untypedBuffer);

    Microsoft::WRL::ComPtr<NativePointerBuffer> nativeBuffer;
    HRESULT hr = Microsoft::WRL::Details::MakeAndInitialize<NativePointerBuffer>(
        &nativeBuffer,
        inputBuffer,
        size
        );
    if (FAILED(hr))
    {
        return hr;
    }

    out = nativeBuffer;
    return S_OK;
}

HRESULT CreateOwningNativeBuffer(
    std::vector<SU::IO::byte>&& buffer,
    MW::ComPtr<AWSS::IBuffer>& out
    )
{
    if (buffer.size() > UINT_MAX)
    {
        SU::ThrowIfFailed(E_INVALIDARG);
    }

    Microsoft::WRL::ComPtr<NativeVectorBuffer> nativeBuffer;
    HRESULT hr = Microsoft::WRL::Details::MakeAndInitialize<NativeVectorBuffer>(
        &nativeBuffer,
        std::move(buffer)
        );
    if (FAILED(hr))
    {
        return hr;
    }

    out = nativeBuffer;
    return S_OK;
}

}

#ifdef __cplusplus_winrt

//------------------------------------------------------------------------------

WSS::IBuffer^ CreateNonOwningNativeBuffer(std::vector<SU::IO::byte> const & buffer, bool align)
{
    return CreateNonOwningNativeBuffer(buffer.data(), buffer.size(), align);
}

//------------------------------------------------------------------------------

WSS::IBuffer^ CreateNonOwningNativeBuffer(const void* buffer, size_t numberOfBytes, bool align)
{
    if (numberOfBytes > UINT_MAX)
    {
        SU::ThrowIfFailed(E_INVALIDARG);
    }

    DWORD size = static_cast<DWORD>(numberOfBytes);


    if (align)
    {
        //  Align data on the boundary
        //  Warning, buffer will have some rubbish at the end
        size += (4 - (size % 4));
    }

    // We output a byte*, so we need to cast away from const
    auto untypedBuffer = const_cast<void *>(buffer);
    auto inputBuffer = static_cast<byte *>(untypedBuffer);

    Microsoft::WRL::ComPtr<NativePointerBuffer> nativeBuffer;
    HRESULT hr = Microsoft::WRL::Details::MakeAndInitialize<NativePointerBuffer>(
        &nativeBuffer,
        inputBuffer,
        size
        );
    SU::ThrowIfFailed(hr);

    WSS::IBuffer^ ret;
    hr = nativeBuffer.CopyTo(__uuidof(ret), reinterpret_cast<void**>(&ret));
    SU::ThrowIfFailed(hr);
    return ret;
}

//------------------------------------------------------------------------------

WSS::IBuffer^ CreateOwningNativeBuffer(std::vector<SU::IO::byte>&& buffer)
{
    if (buffer.size() > UINT_MAX)
    {
        SU::ThrowIfFailed(E_INVALIDARG);
    }

    Microsoft::WRL::ComPtr<NativeVectorBuffer> nativeBuffer;
    HRESULT hr = Microsoft::WRL::Details::MakeAndInitialize<NativeVectorBuffer>(
        &nativeBuffer,
        std::move(buffer)
        );
    SU::ThrowIfFailed(hr);

    WSS::IBuffer^ ret;
    hr = nativeBuffer.CopyTo(__uuidof(ret), reinterpret_cast<void**>(&ret));
    SU::ThrowIfFailed(hr);

    return ret;
}

//------------------------------------------------------------------------------

WSS::IBuffer^ CreateOwningNativeBuffer(void const* buffer, size_t numberOfBytes)
{
    if (numberOfBytes > UINT_MAX)
    {
        SU::ThrowIfFailed(E_INVALIDARG);
    }

    DWORD size = static_cast<DWORD>(numberOfBytes);

    // We output a byte*, so we need to cast away from const
    auto untypedBuffer = const_cast<void *>(buffer);
    auto inputBuffer = static_cast<byte *>(untypedBuffer);

    Microsoft::WRL::ComPtr<NativePointerBuffer> nativeBuffer;
    HRESULT hr = Microsoft::WRL::Details::MakeAndInitialize<NativePointerBuffer>(
        &nativeBuffer,
        inputBuffer,
        size,
        true
        );
    SU::ThrowIfFailed(hr);

    WSS::IBuffer^ ret;
    hr = nativeBuffer.CopyTo(__uuidof(ret), reinterpret_cast<void**>(&ret));
    SU::ThrowIfFailed(hr);
    return ret;
}

//------------------------------------------------------------------------------

uint32_t GetRefCount(WSS::IBuffer^ buffer)
{
    IUnknown* listUnk = reinterpret_cast<IUnknown*>(buffer);
    return (listUnk->AddRef(), listUnk->Release());
}

//------------------------------------------------------------------------------

SU::IO::byte const* ReadableBuffer::Data() const
{
    SU::IO::byte* bufferBytes;
    auto hr = m_bufferByteAccess->Buffer(&bufferBytes);
    SU::ThrowIfFailed(hr);

    return bufferBytes;
}

size_t ReadableBuffer::Size() const
{
    return m_size;
}

ReadableBuffer::ReadableBuffer(WSS::IBuffer^ b)
    :
    m_bufferByteAccess(GetBufferByteAccess(b)),
    m_size(b->Length)
{
    // do nothing
}

//------------------------------------------------------------------------------

size_t WritableBuffer::Capacity() const
{
    return m_buffer->Capacity;
}

//------------------------------------------------------------------------------

SU::IO::byte* WritableBuffer::Data(size_t s)
{
    SpectreAssert(s <= m_buffer->Capacity);

    m_buffer->Length = static_cast<unsigned int>(s);

    SU::IO::byte* bufferBytes;
    auto hr = m_bufferByteAccess->Buffer(&bufferBytes);
    SU::ThrowIfFailed(hr);

    return bufferBytes;
}

//------------------------------------------------------------------------------

SU::IO::byte* WritableBuffer::Data()
{
    SU::IO::byte* bufferBytes;
    auto hr = m_bufferByteAccess->Buffer(&bufferBytes);
    SU::ThrowIfFailed(hr);

    return bufferBytes;
}

//------------------------------------------------------------------------------

WSS::IBuffer^ WritableBuffer::WinRtBuffer() const
{
    return m_buffer;
}

//------------------------------------------------------------------------------

WritableBuffer::WritableBuffer(WSS::IBuffer^ b)
    :
    m_buffer(b),
    m_bufferByteAccess(GetBufferByteAccess(b))
{
    // do nothing
}

//------------------------------------------------------------------------------

WritableBuffer CreateWritableBuffer(size_t capacity)
{
    auto b = ref new WSS::Buffer(static_cast<unsigned int>(capacity));
    return WritableBuffer(b);
}

//------------------------------------------------------------------------------

#endif

} // namespace Utils

} // namespace Spectre
