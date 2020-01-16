/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Async.h>
#include <Framework/Pointers.h>

#include <exception>
#include <memory>
#include <mutex>
#include <string>
#include <vector>


class AsyncActionWithProgress : public IAsyncActionWithProgress
{
public:
    AsyncActionWithProgress(void* userData = nullptr);
    virtual ~AsyncActionWithProgress();

public: // IAsyncActionWithProgress
    virtual RegistrationToken AddProgressCallback(AsyncActionProgressHandler handler) override;
    virtual RegistrationToken AddCompletedCallback(AsyncActionWithProgressCompletedHandler handler) override;
    virtual RegistrationToken AddResourceRequestCallback(AsyncActionNeedResourceHandler handler) override;
    virtual RegistrationToken AddProgressIndicationCallback(AsyncActionProgressIndication indicator) override;

    virtual void RemoveProgressCallback(RegistrationToken token) override;
    virtual void RemoveCompletedCallback(RegistrationToken token) override;
    virtual void RemoveResourceRequestCallback(RegistrationToken token) override;
    virtual void RemoveProgressIndicationCallback(RegistrationToken token) override;

    virtual void Cancel() override;

    virtual BabylonAsyncStatus GetStatus() const override;
    virtual void*              GetUserData() const override;
    virtual std::exception_ptr GetException() const override;
public:
    void SetProgress(CallbackData const& data);
    void SetResourceRequest(ResourceCallbackData const& data);
    void SetProgressIndication(float const& percentage);

    void SetCanceled();
    void SetCompleted();
    void SetError(std::string const& message, std::exception_ptr exception);

    Babylon::Framework::ICancellationTokenPtr GetCancellationToken() const;

private:
    void InvokeProgressCallback(CallbackData const& data);
    void InvokeResourceRequestCallback(ResourceCallbackData const& data);
    void InvokeProgressIndicationCallback(float const& percentage);
    void InvokeCompletedCallback();

    void SetTerminalStatus(
        BabylonAsyncStatus status,
        std::string const& message,
        std::exception_ptr exception
    );

private:
    mutable std::mutex          m_mutex;
    Babylon::Framework::ICancellationTokenPtr m_cancellationToken;

    std::string        m_message;
    std::exception_ptr m_exception;
    BabylonAsyncStatus  m_status;

    void*               m_userData;

    unsigned long m_currentValue;

    std::vector<std::pair<RegistrationToken, AsyncActionProgressHandler>>               m_progressHandlers;
    std::vector<std::pair<RegistrationToken, AsyncActionWithProgressCompletedHandler>>  m_completedHandlers;
    std::vector<std::pair<RegistrationToken, AsyncActionNeedResourceHandler>>           m_resourceRequestHandlers;
    std::vector<std::pair<RegistrationToken, AsyncActionProgressIndication>>            m_progressIndicators;
};