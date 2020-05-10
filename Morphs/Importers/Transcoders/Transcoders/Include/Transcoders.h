/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>
#include <string>

#include <CoreUtils/BabylonSDK.h>

#include <Asset3D/Asset3D.h>
#include <PluginSDK/IResourceServer.h>
#include <PluginSDK/IOutputStreamFactory.h>
#include <PluginSDK/FractionalProgressCallback.h>

#include <Framework/Cancellation.h>
#include <Framework/TelemetryTraceLoggerAliases.h>

namespace Babylon
{
    namespace Transcoder
    {
        /// \brief
        /// Get the current package version string
        // TODO: TEMP COMMENT
        //const char* BabylonSDK_CALL GetVersionString();

        /// \brief
        /// ImportFunction is the function signature that all importers adhere to.
        ///
        /// ADVICE FOR IMPLEMENTORS
        /// -----------------------
        ///
        /// A properly implemented import function must:
        /// - Act as a blocking call (internally spawned threads are allowed, but must be joined before returning)
        /// - Be reentrant (i.e. avoid any unguarded global state)
        /// - Either return a well-formed Asset3D or throw an exception
        /// - Call the progress callback frequently enough to feel responsive (NOTE: most importers currently fail on this point)
        /// - Check the cancellation token frequently enough to feel responsive (NOTE: most importers currently fail on this point)
        ///
        /// \param importFilename        File / resource name of the primary input data stream (e.g. "Model.obj")
        /// \param importResourceServer  Client provided resource server for fetching data streams (e.g. primary model stream, texture streams)
        /// \param progress              Progress callback handler
        /// \param cancellationToken     Cancellation token
        /// \param jsonConfig            JSON configuration (used to pass any format-specific import hints)
        /// \return                      An Asset3D
        using ImportFunction = std::function<Asset3DPtr BABYLON_SDK_CALL (
            const std::string& importFilename,
            IResourceServer* importResourceServer,
            FractionalProgressCallback progress,
            Babylon::Framework::ICancellationTokenPtr cancellationToken,
            const std::unordered_map<std::string, std::string>& options,
            uint64_t* streamSize)>;

        /// \brief
        /// ExportFunction is the function signature that all exporters adhere to.
        ///
        /// ADVICE FOR IMPLEMENTORS
        /// -----------------------
        ///
        /// A properly implemented export function must:
        /// - Act as a blocking call (internally spawned threads are allowed, but must be joined before returning)
        /// - Be reentrant (i.e. avoid any unguarded global state)
        /// - Not lose information if there is support for it in the export format
        /// - Ensure that the 1st output stream created is the primary stream (e.g. material/texture streams must be created after the main model file)
        /// - Call the progress callback frequently enough to feel responsive (NOTE: most exporters currently fail on this point)
        /// - Check the cancellation token frequently enough to feel responsive (NOTE: most exporters currently fail on this point)
        ///
        /// ROUND TRIPPING AND DATA PRESERVATION
        /// ------------------------------------
        ///
        /// A well-formed Asset3D is one that can be re-exported and imported via the original import format without
        /// loss of information. Asset3D supports a carefully chosen subset of all possible features. As such,
        /// it may be impossible for an importer to capture everything supported by the import format,
        /// but it should not lose any further information when exporting back to the import format from the Asset3D.
        /// In other words, an exporter must match the feature subset of its corresponding importer in order to preserve
        /// information.
        ///
        /// \param asset3D               The Asset3D to export from
        /// \param exportAssetName       Asset name used when naming the primary output data stream (e.g. "Model.obj")
        /// \param outputStreamFactory   Client provided stream factory for creating output data streams (e.g. primary model stream, texture streams)
        /// \param progress              Progress callback handler
        /// \param cancellationToken     Cancellation token
        /// \param jsonConfig            JSON configuration (used to pass any format-specific export hints)
        using ExportFunction = std::function<void BABYLON_SDK_CALL(
            Asset3DPtr asset3D,
            const std::string& exportAssetName,
            IOutputStreamFactory* outputStreamFactory,
            FractionalProgressCallback progress,
            Babylon::Framework::ICancellationTokenPtr cancellationToken,
            const std::unordered_map<std::string, std::string>& options)>;

        using HelpFunction = std::string(*)();

        /// \brief
        /// Register an import function for a specific file extension type.
        /// \param extension             File type (e.g. "gltf", "obj")
        /// \param fn                    Function pointer to register
        void BABYLON_SDK_CALL RegisterImportFunction(const std::string& extension, ImportFunction fn);

        /// \brief
        /// Register an export function for a specific file extension type.
        /// \param extension             File type (e.g. "gltf", "obj")
        /// \param fn                    Function pointer to register
        void BABYLON_SDK_CALL RegisterExportFunction(const std::string& extension, ExportFunction fn);

        /// \brief
        /// Register an import help function for a specific file extension type.
        /// \param extension             File type (e.g. "gltf", "obj")
        /// \param fn                    Function pointer to register
        void BABYLON_SDK_CALL RegisterImportHelpFunction(const std::string& extension, HelpFunction fn);

        /// \brief
        /// Register an export help function for a specific file extension type.
        /// \param extension             File type (e.g. "gltf", "obj")
        /// \param fn                    Function pointer to register
        void BABYLON_SDK_CALL RegisterExportHelpFunction(const std::string& extension, HelpFunction fn);

        /// \brief
        /// Return if there is an importer registered for a given extension
        bool BABYLON_SDK_CALL HasImporter(const std::string& extension);

        /// \brief
        /// Return if there is an exporter registered for a given extension
        bool BABYLON_SDK_CALL HasExporter(const std::string& extension);

        /// \brief
        /// Returns importer help information for a given extension
        std::string GetImportHelp(const std::string& extension);

        /// \brief
        /// Returns exporter help information for a given extension
        std::string GetExportHelp(const std::string& extension);

        /// \brief
        /// Return a vector of all supported import formats
        std::set<std::string> BABYLON_SDK_CALL GetImportFormats();

        /// \brief
        /// Return a vector of all supported export formats
        std::set<std::string> BABYLON_SDK_CALL GetExportFormats();

        /// \brief
        /// Transcoder::Import attempts to import input data streams in a given format into an Asset3D.
        ///
        /// OVERVIEW
        /// --------
        /// Import is a blocking call and can (should) throw if the input data is badly formed.
        ///
        /// \param importFormat          Format of the data streams (NOTE: no attempt is made to auto-detect the format)
        /// \param importFilename        File / resource name of the primary input data stream (e.g. "Model.obj")
        /// \param importResourceServer  Client provided resource server for fetching data streams (e.g. primary model stream, texture streams)
        /// \param progress              Optional progress callback handler
        /// \param cancellationToken     Optional cancellation token
        /// \param jsonConfig            Optional JSON configuration
        /// \return                      An Asset3D
        Asset3DPtr BABYLON_SDK_CALL Import(
            const std::string& importFormat,
            const std::string& importFilename,
            IResourceServer* importResourceServer,
            FractionalProgressCallback progress = nullptr,
            Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr,
            const char* jsonConfig = nullptr,
            Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType factory = nullptr);

        Asset3DPtr BABYLON_SDK_CALL Import(
            const std::string& importFormat,
            const std::string& importFilename,
            IResourceServer* importResourceServer,
            const std::unordered_map<std::string, std::string>& options,
            FractionalProgressCallback progress = nullptr,
            Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr,
            bool enableTelemetry = true,
            Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType factory = nullptr);

        /// \brief
        /// Transcoder::Export exports an Asset3D into data streams appropriate for the given export format
        ///
        /// OVERVIEW
        /// --------
        /// Export is a blocking call. It may throw if the Asset3D is badly formed (although a properly implemented
        /// importer is expected to either produce a well formed Asset3D or throw an exception).
        ///
        /// The primary data stream (the main model file, e.g. the OBJ) first is always the first stream requested
        /// through outputStreamFactory.
        ///
        /// \param exportFormat          Format of the data streams (NOTE: no attempt is made to auto-detect the format)
        /// \param asset3D               The Asset3D to export from
        /// \param exportAssetName       Asset name used when naming the primary output data stream (e.g. "Model.obj")
        /// \param outputStreamFactory   Client provided stream factory for creating output data streams (e.g. primary model stream, texture streams)
        /// \param progress              Optional progress callback handler
        /// \param cancellationToken     Optional cancellation token
        /// \param jsonConfig            Optional JSON configuration
        void BABYLON_SDK_CALL Export(
            const std::string& exportFormat,
            Asset3DPtr asset3D,
            const std::string& exportAssetName,
            IOutputStreamFactory* outputStreamFactory,
            FractionalProgressCallback progress = nullptr,
            Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr,
            const char* jsonConfig = nullptr,
            Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType factory = nullptr);

        void BABYLON_SDK_CALL Export(
            const std::string& exportFormat,
            Asset3DPtr asset3D,
            const std::string& exportAssetName,
            IOutputStreamFactory* outputStreamFactory,
            const std::unordered_map<std::string, std::string>& options,
            FractionalProgressCallback progress = nullptr,
            Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr,
            bool enableTelemetry = true,
            Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType factory = nullptr);
    }
}