/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/Cancellation.h>

#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <string>

#include <CoreUtils/Assert.h>

//--------------------------------------------------------------------------------

namespace Babylon
{

namespace Framework
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

    virtual int AddSlaveToken(ICancellationTokenPtr const& slaveToken) override;

    virtual void CheckCancelledAndThrow() const override;
    virtual int SetCancelledCallback(std::function<void BABYLON_SDK_CALL (void)> func) override;
    virtual void ClearCancelledCallback(int registrationToken) override;

private:
    mutable std::mutex m_lock;

    int  m_callbackindex;
    bool m_cancelled;

    std::map<int, std::function<void()>> m_cancelledCallback;
};

//--------------------------------------------------------------------------------

SimpleCancellationToken::SimpleCancellationToken() :
    m_callbackindex(0),
    m_cancelled(false)
{}

//--------------------------------------------------------------------------------

void SimpleCancellationToken::Cancel()
{
    bool firstCancel = false;
    std::map<int, std::function<void()>> callbacks;

    {
        std::lock_guard<std::mutex> stackLock(m_lock);

        firstCancel = (m_cancelled == false);
        m_cancelled = true;

        std::swap(callbacks, m_cancelledCallback);
    }

    if (firstCancel)
    {
        for (auto& func : callbacks)
        {
            func.second();
        }
    }
}

//--------------------------------------------------------------------------------

bool SimpleCancellationToken::IsCancelled() const
{
    std::lock_guard<std::mutex> stackLock(m_lock);
    return m_cancelled;
}

//--------------------------------------------------------------------------------

void SimpleCancellationToken::ClearAllCallbacks()
{
    std::lock_guard<std::mutex> stackLock(m_lock);
    m_cancelledCallback.clear();
}

//--------------------------------------------------------------------------------

int SimpleCancellationToken::AddSlaveToken(ICancellationTokenPtr const& slaveToken)
{
    return SetCancelledCallback([slaveToken]()
    {
        slaveToken->Cancel();
    });
}

//--------------------------------------------------------------------------------

void SimpleCancellationToken::CheckCancelledAndThrow() const
{
    std::lock_guard<std::mutex> stackLock(m_lock);
    if (m_cancelled)
    {
        throw CancelledException();
    }
}

//--------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------

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

ICancellationTokenPtr MakeCancellationToken()
{
    return std::make_shared<SimpleCancellationToken>();
}

//--------------------------------------------------------------------------------



//--------------------------------------------------------------------------------

class NullCancellationToken : public ICancellationToken
{
public:
    NullCancellationToken()
    {
    }

public: // ICancellationToken
    virtual void Cancel() override
    {
    }

    virtual bool IsCancelled() const override
    {
        return false;
    }

    virtual void ClearAllCallbacks() override
    {
    }

    virtual int AddSlaveToken(ICancellationTokenPtr const& slaveToken) override
    {
        BabylonUnusedParameter(slaveToken);
        return 0;
    }

    virtual void CheckCancelledAndThrow() const override
    {
    }

    virtual int SetCancelledCallback(std::function<void BABYLON_SDK_CALL(void)> func) override
    {
        BabylonUnusedParameter(func);
        return 0;
    }

    virtual void ClearCancelledCallback(int registrationToken) override
    {
        BabylonUnusedParameter(registrationToken);
    }
};

//--------------------------------------------------------------------------------

ICancellationTokenPtr MakeNullCancellationToken()
{
    return std::make_shared<NullCancellationToken>();
}

//--------------------------------------------------------------------------------

} // namespace PluginSDK

} // namespace Babylon
