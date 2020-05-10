/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include "Pointers.h"
#include "SmartThrow.h"
#include "BabylonSDK.h"
#include <memory>

//--------------------------------------------------------------------------------

namespace Babylon {

namespace Utils {

//--------------------------------------------------------------------------------

struct CancelledException : public Babylon::Utils::BabylonException
{
    CancelledException();
};

//--------------------------------------------------------------------------------

class ICancellationToken
{
public:
    virtual ~ICancellationToken() {};

    virtual void Cancel() = 0;
    virtual bool IsCancelled() const = 0;

    virtual void ClearAllCallbacks() = 0;

    virtual int AddSlaveToken(ICancellationTokenPtr const & slaveToken) = 0;

    virtual void CheckCancelledAndThrow() const = 0; // Throws exception on cancellation
    virtual int SetCancelledCallback(std::function<void BABYLON_SDK_CALL (void)> cancelledCallback) = 0;
    virtual void ClearCancelledCallback(int token) = 0;

// NOTE: it is very important that any WinRT/UWP only virtual functions go here at
// the end of the class definition. This ensures the vtable indices for the common
// functions are consistent between UWP and non-UWP.
#ifdef __cplusplus_winrt
    virtual int AddSlaveAction(Windows::Foundation::IAsyncInfo^ action) = 0;
#endif // __cplusplus_winrt
};

//--------------------------------------------------------------------------------

namespace Internal
{

//--------------------------------------------------------------------------------

class SimpleCancellationToken : public ICancellationToken
{
public:
    SimpleCancellationToken();

public: // ICancellationToken
    virtual void Cancel() override;
    virtual bool IsCancelled() const override;
    virtual void ClearAllCallbacks() override;
#ifdef __cplusplus_winrt
    virtual int AddSlaveAction(Windows::Foundation::IAsyncInfo^ slaveAction) override;
#endif // __cplusplus_winrt
    virtual int AddSlaveToken(ICancellationTokenPtr const & slaveToken) override;
    virtual void CheckCancelledAndThrow() const override;
    virtual int SetCancelledCallback(std::function<void BABYLON_SDK_CALL (void)> func) override;
    virtual void ClearCancelledCallback(int registrationToken) override;

private:
    mutable std::mutex m_lock;
    int m_callbackindex;
    std::map<int, std::function<void()>> m_cancelledCallback;
    bool m_cancelled;
};

//--------------------------------------------------------------------------------

} // namespace Internal


//--------------------------------------------------------------------------------

/**
* Factory function returning a new cancellation token.
*
* \return A new cancellation token
*/
ICancellationTokenPtr MakeCancellationToken();

//--------------------------------------------------------------------------------

} // namespace Utils

//--------------------------------------------------------------------------------

} // namespace Babylon
