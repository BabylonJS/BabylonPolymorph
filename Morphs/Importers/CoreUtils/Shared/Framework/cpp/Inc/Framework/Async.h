/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

/**
 * \file      Async.h
 * \brief     Specific async functionality for plugin usage and development
 * \copyright Copyright (C) Microsoft. All rights reserved.
 *
 * This file contains the core interfaces and helpers for creating and
 * interacting with asynchronous operations specific to Babylon plugins. This
 * is not a generic async solution.
 */

#include "Pointers.h"
#include "Frame.h"
#include "Cancellation.h"

#include <CoreUtils/BabylonSDK.h>

#include <memory>
#include <atomic>

extern "C"
{

//-----------------------------------------------------------------------------

/**
 * \brief POD struct representing a successful async event registration
 *
 * This registration token is returned after an event handler has been
 * successfully attached to an IAsyncActionWithProgress object. There are two
 * possible events that can be listened for, progress and completion.
 *
 * A registration token can be used to detach a listener from an event.
 */
struct RegistrationToken
{
    unsigned long Value; /**< A unique ID per event */
};

//-----------------------------------------------------------------------------

/**
 * The status of an asynchronous operation
 */
enum class BabylonAsyncStatus
{
    NotStarted = 0, /**< Action has not been started yet, it only applies to plugin status */
    Started = 1,    /**< Action is running, default value */
    Completed = 2,  /**< Action has completed successfully */
    Canceled = 3,   /**< Action got canceled */
    Error = 4       /**< Action ended before it could complete due to an error */
};

//-----------------------------------------------------------------------------

/**
 * Structure containing file load state including frames and other arbitrary
 * user data. A copy of this structure is returned to each load listener when
 * the callback is triggered.
 */
struct CallbackData
{
    Babylon::Framework::Frame*  FrameData;   /**< Raw frame data. */
    uint32_t                    FrameSize;   /**< Raw frame data. */
    const char*                 MetadataJSON;/**< Frame metadata. */
};

/*
Used to notify about transcoder3D frame processing completion
*/
struct ProgressiveFrameCallbackData
{
    void*                       ProgressiveFramePayload;/**< Raw frame data. */
    uint32_t                    ProgressiveFrameSize;   /**< Raw frame data. */
    const char*                 MetadataJSON;/**< Frame metadata. */
};


/*
Used to return data then Exporting / ConvertingTo with Transcoder3d
*/
struct TranscodeToItemCompleteCallbackData
{
    const char* ItemId;         /**< Transcoded item ID. */
    void*       ItemData;       /**< Payload data. */
    uint32_t    ItemDataLen;    /**< Payload len. */
};

//-----------------------------------------------------------------------------

/**
 * Type of the resource requested by plugin API
*/
enum class ResourceType
{
    Texture = 0,
    MaterialLibrary = 1,
    PreLoadedTexture = 2,
    Max = 3
};

//-----------------------------------------------------------------------------

/**
* Structure containing resource request data including resource id, resource type and
* path to the resource. A copy of this structure is returned to each load listener when
* the callback is triggered.
*/
struct ResourceCallbackData
{
    uint32_t        ResourceId;
    ResourceType    ResourceType;
    const char*     ResourcePath;
};

//-----------------------------------------------------------------------------

class IAsyncActionWithProgress;
class AsyncActionWithProgress;
/**
* Function signature for the IAsyncActionWithProgress progress callback.
* Arguments are a reference to the action in question and the ResourceCallbackData
* structure containing resource request information.
*
* \param[in] action             Pointer to the action that raised the progress handler
* \param[in] resourceCallback   Resource request data associated with the raised event
*/
typedef void(BABYLON_SDK_CALL *AsyncActionNeedResourceHandler)(::IAsyncActionWithProgress* action, ResourceCallbackData resourceCallback);

/**
 * Function signature for the IAsyncActionWithProgress progress callback.
 * Arguments are a reference to the action in question and the CallbackData
 * structure containing progress information.
 *
 * \param[in] action   Pointer to the action that raised the progress handler
 * \param[in] progress Progress data associated with the raised progress event
 */
typedef void(BABYLON_SDK_CALL *AsyncActionProgressHandler)(::IAsyncActionWithProgress* action, CallbackData progress);

/**
* Function signature for the IAsyncActionWithProgress progress callback.
* Arguments are a reference to the action in question and the CallbackData
* structure containing progress information.
*
* \param[in] action   Pointer to the action that raised the progress handler
* \param[in] percentage percentage completion
*/
typedef void(BABYLON_SDK_CALL *AsyncActionProgressIndication)(::IAsyncActionWithProgress* action,  float percentage);

/**
* Function signature for the IAsyncActionWithProgress progress callback when using Transcoder3d and async transcoding.
*/
typedef void(BABYLON_SDK_CALL *AsyncActionProgressiveFrameHandler)(::IAsyncActionWithProgress* action, ProgressiveFrameCallbackData frameData);

/**
* Function signature for the IAsyncActionWithProgress TranscodeTo completion callback when using Transcoder3d.
*/
typedef void(BABYLON_SDK_CALL *AsyncActionTranscodeToItemHandler)(::IAsyncActionWithProgress* action, TranscodeToItemCompleteCallbackData itemData);

/**
 * Function signature for the IAsyncActionWithProgress completed callback.
 * Arguments are a reference to the action in question and the AsyncStatus
 * enumeration stating the reason why the action completed.
 *
 * \param[in] action Pointer to the action that raised the progress handler
 * \param[in] status The status of the async action that caused completion.
 *                   Will never be BabylonAsyncStatus::Started.
 */
typedef void(BABYLON_SDK_CALL *AsyncActionWithProgressCompletedHandler)(::IAsyncActionWithProgress* action, BabylonAsyncStatus status);

/**
* Function signature for the BabylonTraceHandler callback.
*
* \param[in] area Specifies where the trace is coming from in the plugin. (what part of the code)
* \param[in] level The criticity of trace from 0 to 5 where five is the highest priority
* \param[in] description The trace message to send to the application.
*/
typedef void(BABYLON_SDK_CALL *BabylonTraceHandler)(const char* area, int level, const char* description);

//-----------------------------------------------------------------------------

/**
 * Interface for an async action with progress reporting. An async action does
 * not return a final result but instead provides feedback through progress
 * callbacks.
 *
 * This interface allows multicast progress and completion callbacks and
 * individual callback registrations can be unregistered using the
 * RegistrationToken returned from the initial registration step.
 *
 * Plugin API users should map from their own internal async mechanism to this
 * interface as well as possible for maximum compatibility with the host
 * application.
 */
class IAsyncActionWithProgress
{
public:
    virtual ~IAsyncActionWithProgress() {}

    /**
     * Attach an AsyncActionProgressHandler to the AsyncActionWithProgress to
     * listen for progress updates. The callback will be invoked for each
     * progress broadcast from the parent action but any progress calls that
     * were invoked before the handler was attached will be lost.
     *
     * \param[in] handler C-style function pointer to attach to the progress
     *                    event
     *
     * \return a unique registration token that can be used to detach the
     *         handler using RemoveProgressCallback
     */
    virtual RegistrationToken AddProgressCallback(::AsyncActionProgressHandler handler) = 0;

    /**
     * Attach an AsyncActionWithProgressCompletedHandler to the
     * AsyncActionWithProgress to listen for action completion. The callback
     * will be called in the event of success, cancellation or failure. If
     * a handler is attached after the action completes the callback will be
     * called immediately.
     *
     * \param[in] handler C-style function pointer to attach to the completed
     *            event
     *
     * \return a unique registration token that can be used to detach the
     *         handler using RemoveCompletedCallback
     */
    virtual RegistrationToken AddCompletedCallback(::AsyncActionWithProgressCompletedHandler handler) = 0;


    /**
    * Attach an AsyncActionNeedResourceHandler to the
    * AsyncActionWithProgress to listen for requests for additional resources.
    *
    * \param[in] handler C-style function pointer to attach to the completed
    *            event
    *
    * \return a unique registration token that can be used to detach the
    *         handler using RemoveResourceRequestCallback
    */
    virtual RegistrationToken AddResourceRequestCallback(AsyncActionNeedResourceHandler handler) = 0;

    /**
    * Attach an AsyncActionProgressIndication to the
    * AsyncActionWithProgress to listen for progress indication. The callback will be invoked for each
    * progress indication from the parent action but any progression Indication calls that
    * were invoked before the handler was attached will be lost.
    *
    * \param[in] indicator C-style function pointer to attach to the completed
    *            event
    *
    * \return a unique registration token that can be used to detach the
    *         handler using RemoveProgressIndicationCallback
    */
    virtual RegistrationToken AddProgressIndicationCallback(AsyncActionProgressIndication indicator) = 0;

    /**
     * Removes a progress handler from the action via the token returned from
     * the act of attaching it. No further progress broadcasts will be received
     *
     * \param[in] token The token used to attach the progress handler you wish
     *                  to remove
     */
    virtual void RemoveProgressCallback(RegistrationToken token) = 0;

    /**
     * Removes a completed handler from the action via the token returned from
     * the act of attaching it. No further completion, cancellation or failure
     * broadcasts will be received.
     *
     * \param[in] token The token used to attach the completed handler you wish
     *                  to remove
     */
    virtual void RemoveCompletedCallback(RegistrationToken token) = 0;

    /**
    * Removes a completed handler from the action via the token returned from
    * the act of attaching it. No further completion, cancellation or failure
    * broadcasts will be received.
    *
    * \param[in] token The token used to attach the completed handler you wish
    *                  to remove
    */
    virtual void RemoveResourceRequestCallback(RegistrationToken token) = 0;

    /**
    * Removes a progress indicator from the action via the token returned from
    * the act of attaching it. No further progress broadcasts will be received
    *
    * \param[in] token The token used to attach the progress handler you wish
    *                  to remove
    */
    virtual void RemoveProgressIndicationCallback(RegistrationToken token) = 0;

    /**
     * Requests that the async action is canceled. This does not result in
     * an immediate cancellation but instead notifies that internal action that
     * one was requested for the action to exit cleanly.
     */
    virtual void Cancel() = 0;

    /**
     * Gets the status of the async action.
     *
     * \return The current status of the async action
     */
    virtual BabylonAsyncStatus GetStatus() const = 0;

    /**
     * Gets the user data associated with the async action.
     *
     * \return A non-owning buffer pointing to some arbitrary user data
     */
    virtual void* GetUserData() const = 0;

    /**
    * Gets the last exception caught inside the async action.
    *
    * \return a copy of the exception that occured
    */
    virtual std::exception_ptr GetException() const = 0;
};

//-----------------------------------------------------------------------------

/**
 * Progress reporter callback returning void and taking CallbackData by value.
 */
typedef std::function<void BABYLON_SDK_CALL (CallbackData)> ProgressReporter;

/**
 * Progress indication callback returning void and taking a float by value.
 */
typedef std::function<void BABYLON_SDK_CALL (float)> ProgressIndicatorReporter;


//-----------------------------------------------------------------------------

// TODO: Add comment
typedef std::function<void BABYLON_SDK_CALL (ResourceCallbackData)> ResourceRequestReporter;

//-----------------------------------------------------------------------------

/**
* CreateAsyncActionWithProgress
* Creates an AsyncActionWithProgress, but does not run it.
*
* \param[in] userData               Some arbitrary user data to carry with the
*                                   action
* \param[in] progressHandler        An optional progress handler to be attached
*                                   before the async action begins
* \param[in] completedHandler       An optional completed handler to be attached
*                                   before the async action begins
* \param[in] resourceRequestHandler An optional resource request handler to be
*                                   attached before the async action begins
* \param[in] progressIndicator      An optional progress indication handler to be
*                                   attached before the the async operation begins
*/
AsyncActionWithProgress* BABYLON_SDK_CALL CreateAsyncActionWithProgress(
    void* userData,
    ::AsyncActionProgressHandler progressHandler = nullptr,
    ::AsyncActionWithProgressCompletedHandler completedHandler = nullptr,
    AsyncActionNeedResourceHandler resourceRequestHandler = nullptr,
    ::AsyncActionProgressIndication progressIndicator = nullptr
);

/* RunAsyncActionWithProgressFunction
* Runs the given function using an existing AsyncActionWithProgress
* \param[in] a                      Pointer to an existing AsyncActionWithProgress
* \param[in] f                      A function taking a cancellation token and
*                                   progress reporter representing the body of the
*                                   async action to run
* \param[in] blockUntilCompleted    Block until the task has completed before returning
*                                   (useful for diagnosing threading issues)
*/
void BABYLON_SDK_CALL RunAsyncActionWithProgressFunction(
    AsyncActionWithProgress* a,
    std::function<void BABYLON_SDK_CALL(Babylon::Framework::ICancellationTokenPtr const&,
        ProgressReporter,
        ResourceRequestReporter,
        ProgressIndicatorReporter)> f,
        bool blockUntilCompleted = false
);


/**
* RunAsAsyncActionWithProgress
* Note: when blockUntilCompleted is true, the action object will not be returned until after the action completes.
* When blockUntilCompleted is true and access to the action object is required, do not use this function.
* Instead, call CreateAsyncActionWithProgress to get the object, then call RunAsyncActionWithProgressFunction to run the action.
*
* Factory function taking a function to execute on a new thread. The function
* should return void and take a cancellation token which should be
* periodically checked for async cancellation requests and a progress reporter
* used for feeding back data to the user.
* An IAsyncActionWithProgress pointer is returned representing the async
* action. Progress and completed handlers can be attached and the action can
* be canceled through this interface.
*
* \param[in] f                      A function taking a cancellation token and
*                                   progress reporter representing the body of the
*                                   async action to run
* \param[in] userData               Some arbitrary user data to carry with the
*                                   action
* \param[in] progressHandler        An optional progress handler to be attached
*                                   before the async action begins
* \param[in] completedHandler       An optional completed handler to be attached
*                                   before the async action begins
* \param[in] resourceRequestHandler An optional resource request handler to be
*                                   attached before the async action begins
* \param[in] progressIndicator      An optional progress indication handler to be
*                                   attached before the the async operation begins
* \param[in] blockUntilCompleted    Block until the task has completed before returning
*                                   (useful for diagnosing threading issues)
*/
::IAsyncActionWithProgress* BABYLON_SDK_CALL RunAsAsyncActionWithProgress(
    std::function<void BABYLON_SDK_CALL (Babylon::Framework::ICancellationTokenPtr const&,
                       ProgressReporter,
                       ResourceRequestReporter,
                       ProgressIndicatorReporter)> f,
    void* userData,
    ::AsyncActionProgressHandler progressHandler = nullptr,
    ::AsyncActionWithProgressCompletedHandler completedHandler = nullptr,
    AsyncActionNeedResourceHandler resourceRequestHandler = nullptr,
    ::AsyncActionProgressIndication progressIndicator = nullptr,
    bool blockUntilCompleted = false
);

//-----------------------------------------------------------------------------

} // extern "C"
