/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

/**
 * \file      Cancellation.h
 * \brief     Cancellation token, exception and factory function
 * \copyright Copyright (C) Microsoft. All rights reserved.
 *
 * This file contains the interface for a cancellation token and a simple
 * factory function that returns a new cancellation token. Cancellation tokens
 * should be checked for cancellation by a task that is bound to the token
 * using CheckCancelledAndThrow which throws a CancelledException if the token
 * has been cancelled.
 *
 * This is a slightly modified version of Cancellation.h from the Babylon::Utils
 * project, hiding the internal cancellation token implementation and removing
 * WinRT specific functionality. It may be worth referencing the Utils
 * implementation instead of duplicating this functionality and simply deploy
 * the remote header.
 */

#include "Pointers.h"

#include <CoreUtils/BabylonSDK.h>

#include <exception>
#include <stdexcept>
#include <functional>
#include <memory>

namespace Babylon
{

namespace Framework
{

//--------------------------------------------------------------------------------

/**
 * Cancelled exception deriving from std::runtime_error used to identify cancellation
 * when calling ICancellationToken::CheckCancelledAndThrow.
 */
struct CancelledException : public std::runtime_error
{
    CancelledException() : std::runtime_error("Operation was cancelled.") {}
};

//--------------------------------------------------------------------------------

class ICancellationToken
{
public:
    virtual ~ICancellationToken() {};

    /**
     * Requests the cancellation of the cancellation token.
     */
    virtual void Cancel() = 0;

    /**
     * Checks if the cancellation token has been cancelled.
     *
     * \return True if the token has been cancelled, false otherwise
     */
    virtual bool IsCancelled() const = 0;

    /**
    * Checks if the cancellation token has been cancelled and throws an
    * exception if it has.
    *
    * \throws CancelledException if the property IsCancelled is true
    */
    virtual void CheckCancelledAndThrow() const = 0;

    /**
     * Adds a slave cancellation token to the current instance. Cancellation of
     * the parent action will result in cancellation of all slaves.
     *
     * \param[in] slaveToken The cancellation token instance to add as a slave
     *                       of the current token.
     *
     * \return An integer representing a registration token used to unregister
     *         the slave using ClearCancelledCallback
     */
    virtual int AddSlaveToken(ICancellationTokenPtr const& slaveToken) = 0;

    /**
     * Adds a new callback to be invoked upon the cancellation of the current
     * token.
     *
     * \param[in] cancelledCallback A function to be invoked upon cancellation
     *                              of the current token
     *
     * \return An integer representing a registration token used to unregister
     *         the slave using ClearCancelledCallback
     */
    virtual int SetCancelledCallback(std::function<void BABYLON_SDK_CALL (void)> cancelledCallback) = 0;

    /**
    * Removes a slave token given a registration token obtained from
    * AddSlaveToken or SetCancelledCallback.
    *
    * \param[in] token The registration token obtained from AddSlaveToken
    */
    virtual void ClearCancelledCallback(int token) = 0;

    /**
    * Removes all callbacks attached via SetCancelledCallback.
    */
    virtual void ClearAllCallbacks() = 0;

};

//--------------------------------------------------------------------------------

/**
 * Factory function returning a new cancellation token.
 *
 * \return A new cancellation token
 */
ICancellationTokenPtr BABYLON_SDK_CALL MakeCancellationToken();

//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------

/**
* Factory function returning a empty cancellation token with all functionality stubbed out.
* Used by default in Api calls when no cancellationToken is provided.
*
* \return A new cancellation token
*/
ICancellationTokenPtr BABYLON_SDK_CALL MakeNullCancellationToken();

//--------------------------------------------------------------------------------


} // namespace Framework

} // namespace Babylon
