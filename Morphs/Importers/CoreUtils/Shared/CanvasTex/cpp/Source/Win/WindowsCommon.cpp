/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CanvasTexPch.h"

#include "WindowsCommon.h"

#include <CoreUtils/Trace.h>

DEFINE_TRACE_AREA(CanvasTex_Internal, Trace::Info);

//-----------------------------------------------------------------------------

namespace CanvasTex
{
namespace Internal
{

//---------------------------------------------------------------------------------------------------------------------

HRESULT GetImagingFactory(
    IWICImagingFactory** factory)
{
    // MULTI_QI has three members:
    // - the identifier for a requested interface (pIID)
    // - the location to return the interface pointer (pItf)
    // - the return value of the call to QueryInterface (hr)
    // Initialize to zero then set our requested interface
    MULTI_QI mq = { 0 };
    mq.pIID = &IID_IWICImagingFactory;
#ifdef __cplusplus_winrt
    HRESULT hr = CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &mq);
#else
    HRESULT hr = CoCreateInstanceEx(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &mq);
#endif

    // strangely the standard insists that you must examine the return value as well as the mq.hr value
    // presumably, because the function can fail before the mq.hr value is set
    if ((mq.hr == S_OK) && (hr == S_OK))
    {
        *factory = static_cast<IWICImagingFactory*>(mq.pItf);
    }
    else
    {
        *factory = nullptr;
        TRACE_ERROR(CanvasTex_Internal, "Failed to create WICImagingFactory COM object");
    }
    return mq.hr;
}

}  // namespace Internal
}  // namespace CanvasTex
