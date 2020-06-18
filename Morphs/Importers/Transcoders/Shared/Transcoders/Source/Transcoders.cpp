/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"
#include "Transcoders.h"
#include "TranscoderException.h"
#include "TranscodersTelemetryHelper.h"

//#include <BabylonVersionInternal.h>
#include <CoreUtils/Platform.h>
#include <PluginSDK/TranscodeOptions.h>

#include <TranscoderOBJ/TranscoderOBJ.h>
#include <TranscoderPLY/TranscoderPLY.h>
#include <TranscoderGLTF/TranscoderGLTF.h>
#include <TranscoderGLTF/TranscoderGLB.h>
#include <TranscoderGLTF/GLTFImportOptions.h>
#include <TranscoderSTL/TranscoderSTL.h>
#include <TranscoderDAE/TranscoderDAE.h>
#include <TranscoderJT/TranscoderJT.h>

#include <ExporterOBJ/ExporterObj.h>
#include <ExporterSTL/ExporterAsciiStl.h>
#include <ExporterGLTF/ExporterGLTF.h>
#include <ExporterGLTF/ExporterGLB.h>

#if defined(_WIN32) // TODO: This might work on other platforms without changes
#include <ExporterTexture/ExporterTexture.h>
#endif

namespace Babylon
{
namespace Transcoder
{
    struct TranscoderDefinition
    {
        ImportFunction ImportFunction;
        ExportFunction ExportFunction;
        HelpFunction   ImportHelpFunction = nullptr;
        HelpFunction   ExportHelpFunction = nullptr;
    };

    std::map<std::string, TranscoderDefinition> g_transcoders
    {
        {"glb",  { ImportGLB,         ExporterGLB::ExportStatic,        GetHelp<GLTFImportOptions>,       GetHelp<GLTFExportOptions>    }},
        {"gltf", { ImportGLTF,        ExporterGLTF::ExportStatic,       GetHelp<GLTFImportOptions>,       GetHelp<GLTFExportOptions>    }},
        {"obj",  { ImportOBJ,         ExporterObj::ExportStatic,        nullptr,                          nullptr,                      }},
        {"ply",  { ImportPLY,         nullptr,                          nullptr,                          nullptr,                      }},
        {"stl",  { ImportSTL,         ExporterAsciiStl::ExportStatic,   nullptr,                          nullptr,                      }},
        {"dae",  { ImportDAE,         nullptr                       ,   nullptr,                          nullptr,                      }},
        {"jt",   { ImportJT ,         nullptr                       ,   nullptr,                          nullptr,                      }},

        #ifdef _WIN32
        {"png",  { nullptr,           ExporterTexture::ExportStaticPNG, nullptr,                          nullptr,                      }},
        {"jpg",  { nullptr,           ExporterTexture::ExportStaticJPG, nullptr,                          nullptr,                      }},
        #endif
    };

    void RegisterImportFunction(const std::string& extension, ImportFunction fn)
    {
        g_transcoders[extension].ImportFunction = fn;
    }

    void RegisterExportFunction(const std::string& extension, ExportFunction fn)
    {
        g_transcoders[extension].ExportFunction = fn;
    }

    void RegisterImportHelpFunction(const std::string& extension, HelpFunction fn)
    {
        g_transcoders[extension].ImportHelpFunction = fn;
    }

    void RegisterExportHelpFunction(const std::string& extension, HelpFunction fn)
    {
        g_transcoders[extension].ExportHelpFunction = fn;
    }

    bool HasImporter(const std::string& extension)
    {
        auto it = g_transcoders.find(extension);
        return (it != g_transcoders.end() && it->second.ImportFunction != nullptr);
    }

    bool HasExporter(const std::string& extension)
    {
        auto it = g_transcoders.find(extension);
        return (it != g_transcoders.end() && it->second.ExportFunction != nullptr);
    }

    std::string GetImportHelp(const std::string& extension)
    {
        auto it = g_transcoders.find(extension);
        if (it == g_transcoders.end())
        {
            return "No transcoder available for extension: " + extension;
        }

        if (it->second.ImportHelpFunction == nullptr)
        {
            return "No import help available for extension: " + extension;
        }

        return it->second.ImportHelpFunction();
    }

    std::string GetExportHelp(const std::string& extension)
    {
        auto it = g_transcoders.find(extension);
        if (it == g_transcoders.end())
        {
            return "No transcoder available for extension: " + extension;
        }

        if (it->second.ExportHelpFunction == nullptr)
        {
            return "No export help available for extension: " + extension;
        }

        return it->second.ExportHelpFunction();
    }

    std::set<std::string> GetImportFormats()
    {
        std::set<std::string> formats;
        for (auto& transcoder : g_transcoders)
        {
            if (transcoder.second.ImportFunction != nullptr)
            {
                formats.insert(transcoder.first);
            }
        }
        return formats;
    }

    std::set<std::string> GetExportFormats()
    {
        std::set<std::string> formats;
        for (auto& transcoder : g_transcoders)
        {
            if (transcoder.second.ExportFunction != nullptr)
            {
                formats.insert(transcoder.first);
            }
        }
        return formats;
    }

    Asset3DPtr Import(
        const std::string& importFormat,
        const std::string& importFilename,
        IResourceServer* importResourceServer,
        const std::unordered_map<std::string, std::string>& options,
        FractionalProgressCallback progress,
        Babylon::Framework::ICancellationTokenPtr cancellationToken,
        bool enableTelemetry,
        Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType traceLoggerFactory)
    {
        auto it = g_transcoders.find(importFormat);
        if (it == g_transcoders.end())
        {
            throw TranscoderInvalidArgException("Unrecognised format: " + importFormat);
        }

        auto& transcoder = it->second;
        if (transcoder.ImportFunction == nullptr)
        {
            throw TranscoderInvalidArgException("No importer registered for format: " + importFormat);
        }

        if (importFilename.empty())
        {
            throw TranscoderInvalidArgException("importFilename is empty");
        }

        TranscodersTelemetryHelper telemetryHelper(importFormat, "asset3d", "V2", enableTelemetry);
        telemetryHelper.Initialize(options, traceLoggerFactory);

        // TODO change import functions to return a results class with result.asset3d and result.stats.streamSize

        uint64_t bytesRead = 0;

        try
        {
            telemetryHelper.SendImportStartTelemetry();

            Asset3DPtr asset3D = transcoder.ImportFunction(importFilename, importResourceServer, progress, cancellationToken, options, &bytesRead);

            telemetryHelper.SendImportCompleteTelemetry(asset3D, bytesRead);

            return asset3D;
        }
        catch (const std::bad_alloc& ex)
        {
            telemetryHelper.SendImportAbortTelemetry(ex.what(), bytesRead);
            throw TranscoderOutofMemoryException("std::bad_alloc");
        }
        // rethrow any TranscoderException
        catch (const TranscoderException& ex)
        {
            telemetryHelper.SendImportAbortTelemetry(ex.m_message, bytesRead);
            throw;
        }
        //convert any BabylonException to Transcoder
        catch (const Babylon::Utils::BabylonInvalidArgException& ex)
        {
           telemetryHelper.SendImportAbortTelemetry(ex.m_message, bytesRead);
           throw TranscoderInvalidArgException(ex.m_message);
        }
        catch (const Babylon::Utils::BabylonFailException& ex)
        {
            telemetryHelper.SendImportAbortTelemetry(ex.m_message, bytesRead);
            throw TranscoderInvalidDataException(ex.m_message);
        }
        catch (const Babylon::Utils::BabylonNotImplException& ex)
        {
            telemetryHelper.SendImportAbortTelemetry(ex.m_message, bytesRead);
            throw TranscoderNotImplException(ex.m_message);
        }
        catch (const Babylon::Framework::CancelledException& ex)
        {
            telemetryHelper.SendImportAbortTelemetry(ex.what(), bytesRead);
            throw;
        }
        catch (const Babylon::Utils::BabylonException& ex)
        {
           telemetryHelper.SendImportAbortTelemetry(ex.m_message, bytesRead);
           throw TranscoderException(ex.m_message);
        }
        catch (const std::exception& ex)
        {
            telemetryHelper.SendImportAbortTelemetry(ex.what(), bytesRead);
            throw TranscoderException(ex.what());
        }
        catch (...)
        {
            telemetryHelper.SendImportAbortTelemetry("Unspecified exception occurred", bytesRead);
            throw TranscoderException("Unspecified exception occurred");
        }
    }

    void Export(
        const std::string& exportFormat,
        Asset3DPtr asset3D,
        const std::string& exportAssetName,
        IOutputStreamFactory* outputStreamFactory,
        const std::unordered_map<std::string, std::string>& options,
        FractionalProgressCallback progress,
        Babylon::Framework::ICancellationTokenPtr cancellationToken,
        bool enableTelemetry,
        Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType traceLoggerFactory)
    {
        auto it = g_transcoders.find(exportFormat);
        if (it == g_transcoders.end())
        {
            throw TranscoderInvalidArgException("Unrecognised format: " + exportFormat);
        }

        auto& transcoder = it->second;
        if (transcoder.ExportFunction == nullptr)
        {
            throw TranscoderInvalidArgException("No exporter registered for format: " + exportFormat);
        }

        if (exportAssetName.empty())
        {
            throw TranscoderInvalidArgException("exportAssetName is empty");
        }

        TranscodersTelemetryHelper telemetryHelper("asset3d", exportFormat, "V2", enableTelemetry);
        telemetryHelper.Initialize(options, traceLoggerFactory);

        try
        {
            telemetryHelper.SendExportStartTelemetry();
            // Pass the file name only - remove any leading disk letters and folders
            transcoder.ExportFunction(asset3D, Babylon::Utils::GetPathFileName(exportAssetName), outputStreamFactory, progress, cancellationToken, options);
            telemetryHelper.SendExportCompleteTelemetry(asset3D);
        }
        catch (const std::bad_alloc& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.what());
            throw TranscoderOutofMemoryException("std::bad_alloc");
        }
        // rethrow any TranscoderException
        catch (const TranscoderException& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.what());
            throw;
        }
        //convert any BabylonException to Transcoder
        catch (const Babylon::Utils::BabylonInvalidArgException& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.m_message);
           throw TranscoderInvalidArgException(ex.m_message);
        }
        catch (const Babylon::Utils::BabylonFailException& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.m_message);
            throw TranscoderInvalidDataException(ex.m_message);
        }
        catch (const Babylon::Utils::BabylonNotImplException& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.m_message);
            throw TranscoderNotImplException(ex.m_message);
        }
        catch (const Babylon::Framework::CancelledException& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.what());
            throw;
        }
        catch (const Babylon::Utils::BabylonException& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.m_message);
            throw TranscoderException(ex.m_message);
        }
        catch (const std::exception& ex)
        {
            telemetryHelper.SendExportAbortTelemetry(ex.what());
            throw TranscoderException(ex.what());
        }
        catch (...)
        {
            telemetryHelper.SendExportAbortTelemetry("Unspecified exception occurred");
            throw TranscoderException("Unspecified exception occurred");
        }
    }

    // TODO: TEMP COMMENT
    /*const char* GetVersionString()
    {
        return Babylon_PACKAGE_VERSION;
    }*/

} // namespace Transcoder
} // namespace Babylon
