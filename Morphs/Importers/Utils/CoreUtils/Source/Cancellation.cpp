/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <CoreUtils/Cancellation.h>

#include <memory>

#include <CoreUtils/Assert.h>
#include <CoreUtils/SmartThrow.h>

//--------------------------------------------------------------------------------

namespace Babylon {

namespace Utils {

//--------------------------------------------------------------------------------

CancelledException::CancelledException() : BabylonException("Operation was cancelled", false) { }

//--------------------------------------------------------------------------------

namespace Internal
{

//--------------------------------------------------------------------------------

SimpleCancellationToken::SimpleCancellationToken()
:
    m_callbackindex(0),
    m_cancelled(false)
{
    // Do nothing!
}

void SimpleCancellationToken::Cancel()
{
    auto firstCancel = false;
    std::map<int, std::function<void()>> callbacks;
    {
        std::lock_guard<std::mutex> stackLock(m_lock);
        firstCancel = m_cancelled == false;
        m_cancelled = true;
        std::swap(callbacks, m_cancelledCallback);
    }

    if (firstCancel)
    {
        for(auto& func : callbacks)
        {
            func.second();
        }
    }
}

bool SimpleCancellationToken::IsCancelled() const
{
    std::lock_guard<std::mutex> stackLock(m_lock);
    return m_cancelled;
}

void SimpleCancellationToken::ClearAllCallbacks()
{
    std::lock_guard<std::mutex> stackLock(m_lock);
    m_cancelledCallback.clear();
}

#ifdef __cplusplus_winrt
int SimpleCancellationToken::AddSlaveAction(Windows::Foundation::IAsyncInfo^ slaveAction)
{
    BabylonAssert(slaveAction);

    return SetCancelledCallback([slaveAction]()
    {
        slaveAction->Cancel();
    });
}
#endif // __cplusplus_winrt

int SimpleCancellationToken::AddSlaveToken(ICancellationTokenPtr const & slaveToken)
{
    BabylonAssert(slaveToken);

    return SetCancelledCallback([slaveToken]()
    {
        slaveToken->Cancel();
    });
}

void SimpleCancellationToken::CheckCancelledAndThrow() const
{
    std::lock_guard<std::mutex> stackLock(m_lock);
    if(m_cancelled)
    {
        throw CancelledException();
    }
}

int SimpleCancellationToken::SetCancelledCallback(std::function<void BABYLON_SDK_CALL (void)> func)
{
    auto cancelled = false;
    auto registrationToken = 0;
    {
        std::lock_guard<std::mutex> stackLock(m_lock);
        registrationToken = ++m_callbackindex;
        cancelled = m_cancelled;
        if (!cancelled)
        {
            m_cancelledCallback[registrationToken] = std::move(func);
        }
    }
    if (cancelled)
    {
        func();
    }
    return registrationToken;
}

void SimpleCancellationToken::ClearCancelledCallback(int registrationToken)
{
    std::lock_guard<std::mutex> stackLock(m_lock);
    auto iter = m_cancelledCallback.find(registrationToken);
    if (iter != m_cancelledCallback.end())
    {
        m_cancelledCallback.erase(iter);
    }
}

//--------------------------------------------------------------------------------

} // namespace Internal

//--------------------------------------------------------------------------------

ICancellationTokenPtr MakeCancellationToken()
{
    return std::make_shared<Internal::SimpleCancellationToken>();
}

//--------------------------------------------------------------------------------

} // namespace Utils

//--------------------------------------------------------------------------------

} // namespace Babylon

//--------------------------------------------------------------------------------
