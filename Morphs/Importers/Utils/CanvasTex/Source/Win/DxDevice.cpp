/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CanvasTexPch.h"

#include "DxDevice.h"

#include <wrl/client.h>

#include <d3d11.h>
#include <dxgi1_2.h>

#include <CoreUtils/Trace.h>

DEFINE_TRACE_AREA(CanvasTex_DxDevice, Trace::Info);

namespace CanvasTex
{
namespace Internal
{

typedef std::multimap<float, Microsoft::WRL::ComPtr<IDXGIAdapter1>> AdapterMap;
using IDXGIFactory2Ptr = Microsoft::WRL::ComPtr<IDXGIFactory2>;
using IDXGIAdapter1Ptr = Microsoft::WRL::ComPtr<IDXGIAdapter1>;

// Creates a DirectX Adapter for use of BC7 Compression
// Adapter chosen will support at least DirectX level 10 and Compute Shaders.
// returns false If no suitable adapter is available.
bool CreateDXDevice(ID3D11Device** pDevice)
{
    IDXGIFactory2Ptr  m_pFactory;

    if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&m_pFactory))))
    {
        TRACE_IMPORTANT(CanvasTex_DxDevice, "Unable to create DXGIFactory");
        return false;
    }

    // try to enumerate the available HW adapters
    uint32_t itr = 0;
    DXGI_ADAPTER_DESC1 desc;
    AdapterMap adapterMap;
    IDXGIAdapter1Ptr spAdapter = nullptr;

    // Enumerate the adapters and sort by priority (maximum dedicated video memory)
    while (m_pFactory->EnumAdapters1(itr, &spAdapter) != DXGI_ERROR_NOT_FOUND)
    {
        if (SUCCEEDED(spAdapter->GetDesc1(&desc)))
        {
            adapterMap.emplace(desc.DedicatedVideoMemory > 0 ? (1.0f / desc.DedicatedVideoMemory) : 1.0f, spAdapter);
        }
        ++itr;
    }
    spAdapter = nullptr;

    if (adapterMap.size() == 0) return false; // no adapters found

                                              // BC6/7 Hardware acceleration can only be performed on feature level 10 or higher
    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    uint32_t createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    // Attempt to create devices in priority order
    for (AdapterMap::const_iterator adapterItr = adapterMap.cbegin(); adapterItr != adapterMap.cend(); ++adapterItr)
    {
        spAdapter = adapterItr->second;

        if (spAdapter.Get() != nullptr)
        {
            // create D3D device
            D3D_FEATURE_LEVEL featureLevel;
            Microsoft::WRL::ComPtr<ID3D11DeviceContext> spContextBase;
            HRESULT hr = D3D11CreateDevice(spAdapter.Get(),
                D3D_DRIVER_TYPE_UNKNOWN, // Unknown is required when specifying a particular adapter.
                nullptr,
                createDeviceFlags,
                featureLevels,
                std::extent<decltype(featureLevels)>::value,
                D3D11_SDK_VERSION,
                pDevice,
                &featureLevel,
                &spContextBase);

            if (SUCCEEDED(hr))
            {
                // Ensure GPU supports compute shaders
                if (featureLevel < D3D_FEATURE_LEVEL_11_0)
                {
                    D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS hwopts;
                    hr = (*pDevice)->CheckFeatureSupport(D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS, &hwopts, sizeof(hwopts));
                    if (FAILED(hr))
                        memset(&hwopts, 0, sizeof(hwopts));

                    if (!hwopts.ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x)
                    {
                        if (*pDevice)
                        {
                            (*pDevice)->Release();
                            *pDevice = nullptr;
                        }
                        hr = HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
                    }
                }
            }

            if (SUCCEEDED(hr))
            {
                DXGI_ADAPTER_DESC adptDesc;
                hr = spAdapter->GetDesc(&adptDesc);
                if (SUCCEEDED(hr))
                {
                    TRACE_IMPORTANT(CanvasTex_DxDevice, "Using DirectCompute on \"%ls\"", adptDesc.Description);
                }

                return true;
            }
        }

    }

    TRACE_IMPORTANT(CanvasTex_DxDevice, "No suitable DirectX adapter found");
    return false;
}

}  // namespace Internal
}  // namespace CanvasTex
