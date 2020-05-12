/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

/**
* \file      Plugin.h
* \brief     Generic plugin interface and helpers
* \copyright Copyright (C) Microsoft. All rights reserved.
*
* This file defines the IPlugin interface which should be implemented by plugin
* developers. It also contains other helpers such as function signatures,
* traits and versioning structures required for successfully registering a
* plugin with the host application.
*/

#include <Framework/Async.h>
#include <CoreUtils/Math/SimpleMath.h>

#ifdef __cplusplus
#include <memory>
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

    //-----------------------------------------------------------------------------

    /**
     * POD structure representing a basic major-minor style version.
     */
    struct Version
    {
        unsigned int Major; /**< Major version component */
        unsigned int Minor; /**< Minor version component */
    };

    //-----------------------------------------------------------------------------

    /**
     * POD structure containing core information that identifies your plugin. All
     * components other than APIVersion and FileType are optional.
     *
     * APIVersion should be set to the Major and Minor version of the PluginAPI you
     * are writing your plugin for which is listed in the API documentation.
     *
     * FileType is the undecorated file extension that you plugin can parse. If
     * your plugin supports more than one file type, simply create multiple plugin
     * DLLs with unique traits and share a common base parser between them both.
     */
    struct PluginTraits
    {
        Version APIVersion;         /**< Version of the API the plugin was developed for */

        char const* Name;           /**< Friendly name for the plugin */
        char const* Author;         /**< Plugin Author/Company */
        char const* License;        /**< License for plugin use (GPL v2, MIT etc.) */
        char const* Description;    /**< General plugin description */
        char const* URL;            /**< Company/product website */
        char const* FileTypes;       /**< File type supported by the plugin */
    };

    //-----------------------------------------------------------------------------

    enum TextureCompressionType
    {
        None = 0,
        BC3 = 1,
        BC5 = 2,
        BC7 = 3,
        PNG = 4,
        PNG256 = 5,
        JPEG = 6
    };

    //-----------------------------------------------------------------------------

    /**
    * Different modes, or environments, that the converter may be hosted in.
    */
    enum class ConverterMode
    {
        Server = 0,     /**< Converter is running in a server environment */
        Local = 1       /**< Converter is running in a local environment (on client's machine) */
    };


    /**\brief Describes the parameters of the default material to use when loading models without materials.

    * The material is initialized to gray with no specular and 0.5 smoothness by default. The default
    * material can be redefined in the load options allowing the client to choose how they want to display
    * models without materials.
    */
    struct MaterialAttributes
    {
        Babylon::Utils::Math::Color DiffuseColour = Babylon::Utils::Math::Color(0.5f, 0.5f, 0.5f, 1.0f);

        Babylon::Utils::Math::Color SpecularColour = Babylon::Utils::Math::Color(0.0f, 0.0f, 0.0f, 1.0f);

        float Smoothness = 0.5f;
    };

    /**
    * LOD processing modes that the converter can operate on.
    */
    enum class ConverterLODMode
    {
        kNoLOD = 0,     /**< Converter will not generate LOD data for resource */
        kSimpleLOD = 1, /**< Converter will generate a simple LOD for resource (eg. 2 level) */
    };

    enum class ResourceLODType
    {
        kTexture = 0,
    };

    //-----------------------------------------------------------------------------

    /**
     * POD structure containing the caller specified options for the load process.
     * Plugins should respect these options if at all possible
     */
    struct LoadOptions
    {
        LoadOptions() :
            BigEndian(false),
            TextureCompression(BC3),
            Mode(ConverterMode::Local),
            TempFolder(nullptr),
            TextureLODMode(ConverterLODMode::kNoLOD)
        {
        }

        LoadOptions(TextureCompressionType textureCompression) :
            BigEndian(false),
            TextureCompression(textureCompression),
            Mode(ConverterMode::Local),
            TempFolder(nullptr),
            TextureLODMode(ConverterLODMode::kNoLOD)
        {
        }

        bool                  BigEndian;            /**< True to output in BigEndian. False to output in LittleEndian */
        int                   TextureCompression;   /**< Texture compression type specified by TextureCompression enum */
        ConverterMode         Mode;                 /**< Mode that the converter should be running in */
        const char*           TempFolder;           /**< Temporary folder */
        MaterialAttributes    DefaultMaterial;      /**< The default material to use when loading meshes without materials */
        ConverterLODMode      TextureLODMode;       /**< Should converter generate LODs for Textures */
    };

    //-----------------------------------------------------------------------------

    struct IPlugin
    {
        virtual ~IPlugin() {}

        /**
        * Sets the options on the plugin.
        *
        * \param[in] options          Reference to options customizing the load
        *                             operation
        */
        virtual void SetOptions(LoadOptions options) = 0;

        /**
        * Sets the user data on the plugin.
        *
        * \param[in] userData         Some arbitrary user data to carry with the
        *                             action
        */
        virtual void SetUserData(void* userData) = 0;

        /**
        * Set the progress handler on the plugin.
        *
        * \param[in] progressHandler  An optional progress handler to be attached
        *                             before the async action begins
        */
        virtual void SetProgressHandler(::AsyncActionProgressHandler progressHandler) = 0;

        /**
        * Sets the status handler on the plugin.
        *
        * \param[in] completedHandler An optional completed handler to be attached
        *                             before the async action begins
        */
        virtual void SetStatusHandler(::AsyncActionWithProgressCompletedHandler completedHandler) = 0;

        /**
        * Sets the resource request handler on the plugin.
        *
        * \param[in] resourceRequestHandler An optional resource request handler to be attached
        *                             before the async action begins
        */
        virtual void SetResourceRequestHandler(AsyncActionNeedResourceHandler resourceRequestHandler) = 0;

        /**
        * Sets the resource request handler on a plugin.
        * Use trace handler to get back all the traces from the plugin.
        *
        * \param[in] traceHandler a callback function dealing with the trace.
        */
        virtual void SetTraceHandler(BabylonTraceHandler traceHandler) = 0;

        /**
        * Loads the plugin asynchronously. File data is provided in the
        * form of progress callbacks. The load action can be canceled via the
        * IAsyncActionWithProgress object returned from this function.
        */
        virtual ::IAsyncActionWithProgress* LoadAsync() = 0;

        /**
        * Cancel the pending loading of resource,
        * for example
        *
        * \param[in] resourceId Id of the requested resource
        */
        virtual void CancelPendingLoadResource(uint32_t resourceId) = 0;

        /**
        * Cancels all pending async tasks.
        */
        virtual void CancelPendingRequests() = 0;

        /**
         * Frees the memory allocated by the plugin in the form of an async action
         * with progress. This should be called after you are finished with the
         * async action.
         *
         * \param[in,out] action Reference to an async action pointer to free
         */
        virtual void Free(::IAsyncActionWithProgress*& action) = 0;

        /**
        * Frees the memory allocated by the plugin.
        */
        virtual void Destroy() = 0;

        /**
        * Checks if there are any pending requests.
        */
        virtual bool HasPendingRequests() = 0;
    };

    //-----------------------------------------------------------------------------

    /**
     * Function signature for the public API plugin factory function. The factory
     * should return new plugin instances to the caller which will later be freed
     * using a function implementing the PluginFreeFunc signature.
     *
     * \return A new instance of a plugin implementing the IPlugin interface
     */
    typedef IPluginFactory*(BABYLON_SDK_CALL *PluginFactoryFunc)(void);

    /**
     * Function signature for the plugin destroy function returned after
     * plugin initialization. The destroy function is called when the DLL itself is
     * no longer required.
     */
    typedef void(BABYLON_SDK_CALL *PluginDestroyFunc)(void);

    /**
     * Function signature for the plugin initialization function. This function
     * should return a function that can be used to destroy the plugin in the form
     * of PluginDestroyFunc.
     * Initialization is performed as soon as the plugin is loaded from a static
     * or dynamic source and is guaranteed to be executed before the factory,
     * traits, free or destroy functions.
     *
     * \return A function pointer used to destroy a plugin
     */
    typedef PluginDestroyFunc(BABYLON_SDK_CALL *PluginInitFunc)(void);

    /**
     * Function signature for a function that frees plugin objects created with the
     * plugin DLL. Takes a pointer to the plugin instance to free, basic
     * implementations should simply delete (or free) the memory pointed to by the
     * argument.
     *
     * \param[in,out] plugin The plugin instance to delete
     */
    typedef void(BABYLON_SDK_CALL *PluginFreeFunc)(IPluginFactory*& plugin);

    /**
     * Function signature for obtaining a PluginTraits structure from the plugin
     * DLL. The structure should be returned by value and is generally only called
     * once for the lifetime of the plugin and cached on the application side.
     * Any changes to the traits made after initialisation will not propagate to
     * the application until the plugin is unloaded and reloaded.
     *
     * \return The traits structure for a plugin instance
     */
    typedef PluginTraits(BABYLON_SDK_CALL *PluginTraitsFunc)(void);

    //-----------------------------------------------------------------------------

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

//-----------------------------------------------------------------------------

#ifdef __cplusplus

//-----------------------------------------------------------------------------

/**
 * The type of linkage the plugin is built for. This is used to check that the
 * method of registration is in line with the linkage of the plugin.
 */
enum class PluginLinkage
{
    Static, /**< Static linkage */
    Dynamic /**< Dynamic linkage */
};

//-----------------------------------------------------------------------------

/**
 * Plugin base class representing all required functionality from a native C++
 * point of view. This class should be derived from when building a statically
 * linked plugin and registered with the plugin manager directly in code.
 * PluginBase is not needed for the implementation of dynamically linked
 * plugins.
 * When building a static plugin that derives from PluginBase you should not
 * use the plugin directly but immediately register it with the plugin manager
 * and request the internal plugin implementation from the manager. This allows
 * resources to be tracked and controlled by the plugin manager and hides the
 * raw C API interface behind a more user friendly C++ interface.
 */
class PluginFactoryBase
{
public:
    PluginFactoryBase(PluginLinkage linkage = PluginLinkage::Static) :
        m_linkage(linkage)
    {
    }

    virtual ~PluginFactoryBase() {}

    virtual PluginLinkage                 GetLinkage() const { return m_linkage; }
    virtual std::shared_ptr<PluginTraits> GetTraits() = 0;

    virtual std::shared_ptr<IPluginFactory> PluginFactory() = 0;

private:
    PluginLinkage m_linkage;
};

//-----------------------------------------------------------------------------

#endif // __cplusplus
