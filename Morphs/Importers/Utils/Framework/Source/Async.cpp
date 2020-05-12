/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <algorithm>
#include <exception>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include <Framework/Cancellation.h>

#include "PrivateAsync.h"

namespace SF = Babylon::Framework;

//-----------------------------------------------------------------------------

AsyncActionWithProgress::AsyncActionWithProgress(void* userData) :
    m_cancellationToken(Babylon::Framework::MakeCancellationToken()),
    m_status(BabylonAsyncStatus::Started),
    m_userData(userData),
    m_currentValue(0ul)
{}

//-----------------------------------------------------------------------------

AsyncActionWithProgress::~AsyncActionWithProgress()
{}

//-----------------------------------------------------------------------------

RegistrationToken AsyncActionWithProgress::AddProgressCallback(AsyncActionProgressHandler handler)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto t = RegistrationToken();
    t.Value = ++m_currentValue;
    if (m_status == BabylonAsyncStatus::Started)
    {
        m_progressHandlers.push_back(std::make_pair(t, handler));
    }
    return t;
}

//-----------------------------------------------------------------------------

RegistrationToken AsyncActionWithProgress::AddCompletedCallback(AsyncActionWithProgressCompletedHandler handler)
{
    std::unique_lock<std::mutex> lock(m_mutex);

    auto t = RegistrationToken();
    t.Value = ++m_currentValue;
    if (m_status == BabylonAsyncStatus::Started)
    {
        m_completedHandlers.push_back(std::make_pair(t, handler));
    }
    else
    {
        lock.unlock();
        handler(this, m_status);
        return t;
    }
    return t;
}

//-----------------------------------------------------------------------------

RegistrationToken AsyncActionWithProgress::AddResourceRequestCallback(AsyncActionNeedResourceHandler handler)
{
    std::unique_lock<std::mutex> lock(m_mutex);

    auto t = RegistrationToken();
    t.Value = ++m_currentValue;
    if (m_status == BabylonAsyncStatus::Started)
    {
        m_resourceRequestHandlers.push_back(std::make_pair(t, handler));
    }
    return t;
}

//-----------------------------------------------------------------------------

RegistrationToken AsyncActionWithProgress::AddProgressIndicationCallback(AsyncActionProgressIndication handler)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto t = RegistrationToken();
    t.Value = ++m_currentValue;
    if (m_status == BabylonAsyncStatus::Started)
    {
        m_progressIndicators.push_back(std::make_pair(t, handler));
    }
    return t;
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::RemoveProgressCallback(RegistrationToken token)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto it = std::find_if(m_progressHandlers.begin(), m_progressHandlers.end(),
        [token](std::pair<RegistrationToken, AsyncActionProgressHandler> val)
    {
        return val.first.Value == token.Value;
    });

    if (it != m_progressHandlers.end())
    {
        m_progressHandlers.erase(it);
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::RemoveCompletedCallback(RegistrationToken token)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto it = std::find_if(m_completedHandlers.begin(), m_completedHandlers.end(),
        [token](std::pair<RegistrationToken, AsyncActionWithProgressCompletedHandler> val)
    {
        return val.first.Value == token.Value;
    });

    if (it != m_completedHandlers.end())
    {
        m_completedHandlers.erase(it);
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::RemoveResourceRequestCallback(RegistrationToken token)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto it = std::find_if(m_resourceRequestHandlers.begin(), m_resourceRequestHandlers.end(),
        [token](std::pair<RegistrationToken, AsyncActionNeedResourceHandler> val)
    {
        return val.first.Value == token.Value;
    });

    if (it != m_resourceRequestHandlers.end())
    {
        m_resourceRequestHandlers.erase(it);
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::RemoveProgressIndicationCallback(RegistrationToken token)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto it = std::find_if(m_progressIndicators.begin(), m_progressIndicators.end(),
        [token](std::pair<RegistrationToken, AsyncActionProgressIndication> val)
    {
        return val.first.Value == token.Value;
    });

    if (it != m_progressIndicators.end())
    {
        m_progressIndicators.erase(it);
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::Cancel()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_cancellationToken->Cancel();
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::SetProgress(CallbackData const& data)
{
    InvokeProgressCallback(data);
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::SetResourceRequest(ResourceCallbackData const& data)
{
    InvokeResourceRequestCallback(data);
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::SetProgressIndication(float const& percentage)
{
    InvokeProgressIndicationCallback(percentage);
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::SetCanceled()
{
    SetTerminalStatus(BabylonAsyncStatus::Canceled, "Canceled", nullptr);
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::SetCompleted()
{
    SetTerminalStatus(BabylonAsyncStatus::Completed, "Completed", nullptr);
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::SetError(std::string const& message, std::exception_ptr exception)
{
    SetTerminalStatus(BabylonAsyncStatus::Error, message, exception);
}

//-----------------------------------------------------------------------------

Babylon::Framework::ICancellationTokenPtr AsyncActionWithProgress::GetCancellationToken() const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_cancellationToken;
}

//-----------------------------------------------------------------------------

BabylonAsyncStatus AsyncActionWithProgress::GetStatus() const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_status;
}

//-----------------------------------------------------------------------------

void* AsyncActionWithProgress::GetUserData() const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_userData;
}

std::exception_ptr AsyncActionWithProgress::GetException() const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_exception;
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::InvokeProgressCallback(CallbackData const& data)
{
    auto handlers = std::vector<std::pair<RegistrationToken, AsyncActionProgressHandler>>();

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        handlers = m_progressHandlers;
    }

    for (auto h : handlers)
    {
        if (h.second)
        {
            try
            {
                h.second(this, data);
            }
            catch (...)
            {
                // Ignore all exceptions
            }
        }
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::InvokeCompletedCallback()
{
    auto handlers = std::vector<std::pair<RegistrationToken, AsyncActionWithProgressCompletedHandler>>();

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::swap(handlers, m_completedHandlers);
    }

    for (auto h : handlers)
    {
        if (h.second)
        {
            try
            {
                h.second(this, m_status);
            }
            catch (...)
            {
                // Ignore all exceptions
            }
        }
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::InvokeResourceRequestCallback(ResourceCallbackData const& data)
{
    auto handlers = std::vector<std::pair<RegistrationToken, AsyncActionNeedResourceHandler>>();

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        handlers = m_resourceRequestHandlers;
    }

    for (auto h : handlers)
    {
        if (h.second)
        {
            try
            {
                h.second(this, data);
            }
            catch (...)
            {
                // Ignore all exceptions
            }
        }
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::InvokeProgressIndicationCallback(float const& percentage)
{
    auto handlers = std::vector<std::pair<RegistrationToken, AsyncActionProgressIndication>>();

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        handlers = m_progressIndicators;
    }

    for (auto h : handlers)
    {
        if (h.second)
        {
            try
            {
                h.second(this, percentage);
            }
            catch (...)
            {
                // Ignore all exceptions
            }
        }
    }
}

//-----------------------------------------------------------------------------

void AsyncActionWithProgress::SetTerminalStatus(
    BabylonAsyncStatus status,
    std::string const& message,
    std::exception_ptr exception
    )
{
    bool notify = false;
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        if (m_status == BabylonAsyncStatus::Started)
        {
            notify = true;

            m_message = message;
            m_exception = exception;
            m_status = status;
        }

        m_cancellationToken->ClearAllCallbacks();
    }

    if (notify)
    {
        InvokeCompletedCallback();
    }
}

//-----------------------------------------------------------------------------
AsyncActionWithProgress* BABYLON_SDK_CALL CreateAsyncActionWithProgress(
    void* userData,
    AsyncActionProgressHandler progressHandler,
    AsyncActionWithProgressCompletedHandler completedHandler,
    AsyncActionNeedResourceHandler resourceRequestHandler,
    AsyncActionProgressIndication progressIndicator
)
{
    auto a = new AsyncActionWithProgress(userData);

    if (progressHandler != nullptr)
    {
        a->AddProgressCallback(progressHandler);
    }
    if (completedHandler != nullptr)
    {
        a->AddCompletedCallback(completedHandler);
    }
    if (resourceRequestHandler != nullptr)
    {
        a->AddResourceRequestCallback(resourceRequestHandler);
    }
    if (progressIndicator != nullptr)
    {
        a->AddProgressIndicationCallback(progressIndicator);
    }

    return a;
}

//-----------------------------------------------------------------------------
void BABYLON_SDK_CALL RunAsyncActionWithProgressFunction(
    AsyncActionWithProgress* a,
    std::function<void BABYLON_SDK_CALL(Babylon::Framework::ICancellationTokenPtr const&,
    ProgressReporter,
    ResourceRequestReporter,
    ProgressIndicatorReporter)> f,
    bool blockUntilCompleted
)
{
    auto threadFunction = [a, f]() mutable
    {
        try
        {
            f(
                a->GetCancellationToken(),
                [a](CallbackData d) { a->SetProgress(d); },
                [a](ResourceCallbackData d) { a->SetResourceRequest(d); },
                [a](float d) { a->SetProgressIndication(d); }
            );

            //ensure that the cancellation token throws the CancelledException, if the cancel flag has been set.
            //code paths that set the cancellation token may not necesarrily throw the exception.
            //the exception needs to be thrown in order to set the status to cancelled below.
            if (a->GetCancellationToken())
            {
                a->GetCancellationToken()->CheckCancelledAndThrow();
            }

            if (a->GetStatus() == BabylonAsyncStatus::Started)
            {
                a->SetCompleted();
            }
        }
        catch (Babylon::Framework::CancelledException const&)
        {
            a->SetCanceled();
        }
        catch (std::exception const&)
        {
            a->SetError("Caught std::exception.", std::current_exception());
        }
        catch (...)
        {
            a->SetError("Caught unidentified exception.", std::current_exception());
        }
    };

    if (blockUntilCompleted)
    {
        threadFunction();
    }
    else
    {
        auto t = std::thread(threadFunction);
        t.detach();
    }
}


//-----------------------------------------------------------------------------

IAsyncActionWithProgress* BABYLON_SDK_CALL RunAsAsyncActionWithProgress(
    std::function<void BABYLON_SDK_CALL (SF::ICancellationTokenPtr const&,
        ProgressReporter,
        ResourceRequestReporter,
        ProgressIndicatorReporter)> f,
    void* userData,
    AsyncActionProgressHandler progressHandler,
    AsyncActionWithProgressCompletedHandler completedHandler,
    AsyncActionNeedResourceHandler  resourceRequestHandler,
    AsyncActionProgressIndication progressIndicator,
    bool blockUntilCompleted)
{
    auto a = CreateAsyncActionWithProgress(userData, progressHandler, completedHandler, resourceRequestHandler, progressIndicator);
    RunAsyncActionWithProgressFunction(a, f, blockUntilCompleted);
    return (IAsyncActionWithProgress*) a;
}

//-----------------------------------------------------------------------------
