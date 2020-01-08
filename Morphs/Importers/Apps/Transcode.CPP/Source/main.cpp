// Copyright (c) Microsoft Corporation. All rights reserved.

#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#ifdef _WIN32
#include <combaseapi.h>
#include <psapi.h>
#endif
// TODO: TEMP COMMENT
//#include <SpectreVersionInternal.h>

#include <CoreUtils/StringUtils.h>
#include <CoreUtils/Trace.h>

#include "Transcode.h"

DEFINE_TRACE_AREA(Transcode_EXE, 0);

namespace
{
    constexpr const char* kHelp =
R"(Usage: [FILE]... [OPTION]...
  e.g. Transcode.CPP.exe foo1.gltf foo2.glb foo3.obj --format=gltf

  --help                          Prints this help message
  --help=[FORMATIN:FORMATOUT]     Prints options for transcoding from FORMATIN to FORMATOUT
  --version                       Prints the version of this tool

  --format=[FORMAT]               The export file format (default: glb) - [glb, gltf, ply, stl]

  --verbosity=[LEVEL]             The level of console output (default: default)
      silent                            No console output
      error                             Errors only
      warn                              Warnings and Errors only
      quiet                             Base3D Warnings and Errors, plus limited Transcode.CPP logging
      default                           Base3D Warnings and Errors, plus typical Transcode.CPP logging
      verbose                           Detailed Base3D output, plus typical Transcode.CPP logging
      debug                             Show all logging messages

  --destination=[DIR]             The base directory to write output to (default: same directory as [FILE])

  --importoption=[KEY:VALUE]      A key-value pair that that will be passed through to Transcoders as an import option.
  --exportoption=[KEY:VALUE]      A key-value pair that that will be passed through to Transcoders as an export option.
)";

    constexpr const char* kOptionDelimiter = ":";

#ifdef _WIN32
    void Fail(const std::string& message)
    {
        std::cout << "Error: " << message << "\n";
        std::exit(EXIT_FAILURE);
    }
#endif

    void PrintHelp()
    {
        std::cout << kHelp;
        std::exit(EXIT_SUCCESS);
    }

    void PrintHelpWithError(const std::string& message)
    {
        std::cout << "Error: " << message << "\n";
        std::cout << kHelp;
        std::exit(EXIT_FAILURE);
    }

    void PrintTranscoderHelp(const std::string& importFormat, const std::string& exportFormat)
    {
        std::string tmp;

        std::cout << "IMPORT options for '" << importFormat << "'..." << "\n";
        std::stringstream importHelp(Spectre::GetImportHelp(importFormat));
        while (std::getline(importHelp, tmp))
        {
            std::cout << "    " << tmp << "\n";
        }

        std::cout << "\n\n"; // Two line gap between Import and Export help

        std::cout << "EXPORT options for '" << exportFormat << "'..." << "\n";
        std::stringstream exportHelp(Spectre::GetExportHelp(exportFormat));
        while (std::getline(exportHelp, tmp))
        {
            std::cout << "    " << tmp << "\n";
        }

        std::exit(EXIT_SUCCESS);
    }

    void PrintVersion()
    {
        // TODO: TEMP COMMENT
        //std::cout << SPECTRE_PACKAGE_VERSION << " (" << SPECTRE_BUILD_BUILDNUMBER << ")\n";
        std::exit(EXIT_SUCCESS);
    }

    std::pair<std::string, std::string> SplitOption(const std::string& str)
    {
        std::string a = str.substr(0, str.find_first_of(kOptionDelimiter));
        std::string b = str.substr(str.find_first_of(kOptionDelimiter) + 1);

        return { a, b };
    }

    void PrintMemoryStatistics()
    {
#ifdef _WIN32
        PROCESS_MEMORY_COUNTERS processMemoryCounters;
        auto result = GetProcessMemoryInfo(GetCurrentProcess(), &processMemoryCounters, sizeof(processMemoryCounters));
        if (result == 0)
        {
            Fail("GetProcessMemoryInfo failed");
        }

        size_t peakMemoryKB = processMemoryCounters.PeakWorkingSetSize / 1024;
        double peakMemoryMB = peakMemoryKB / 1024.0;
        TRACE_IMPORTANT(Transcode_EXE, "Peak memory: %u KB (%.2f MB)", peakMemoryKB, peakMemoryMB);
#endif
    }

    class ArgParser
    {
    public:
        #if defined _WIN32 && defined _UNICODE
        ArgParser(int argc, wchar_t* argv[])
          : m_args(ConvertWCharArgs(argc, argv))
        #else
        ArgParser(int argc, char* argv[])
          : m_args(argv + 1, argv + argc)
        #endif
        {
        }

        bool HasArgument(const std::string& arg)
        {
            if (std::find(m_args.begin(), m_args.end(), arg) != m_args.end())
            {
                return true;
            }
            return false;
        }

        // Finds the first argument called "arg" and returns it's value, if not found returns "defaultValue"
        std::string GetArgument(const std::string& arg, const std::string& defaultValue = "")
        {
            for (size_t i = 0; i < m_args.size(); i++)
            {
                if (Spectre::Utils::BeginsWith(m_args[i] + "=", arg))
                {
                    return m_args[i].substr(arg.size() + 1);
                }
            }
            return defaultValue;
        }

        // Finds all arguments called "arg" and returns their values, if not found returns an empty vector
        std::vector<std::string> GetArgumentMultiple(const std::string& arg)
        {
            std::vector<std::string> argValues;
            for (size_t i = 0; i < m_args.size(); i++)
            {
                if (Spectre::Utils::BeginsWith(m_args[i] + "=", arg))
                {
                    auto argValue = m_args[i].substr(arg.size() + 1);
                    argValues.push_back(argValue);
                }
            }
            return argValues;
        }

        // Finds all positional arguments (all arguments not beginning with "-")
        std::vector<std::string> GetPositionalArguments()
        {
            std::vector<std::string> positionalArguments;
            for (size_t i = 0; i < m_args.size(); i++)
            {
                if (m_args[i][0] != '-')
                {
                    positionalArguments.push_back(m_args[i]);
                }
            }
            return positionalArguments;
        }

    private:
        std::vector<std::string> ConvertWCharArgs(int argc, wchar_t* argv[])
        {
            std::vector<std::string> args;
            for (int i = 1; i < argc; i++)
            {
                args.push_back(Spectre::Utils::WStringToString(argv[i], wcslen(argv[i])));
            }
            return args;
        }

        std::vector<std::string> m_args;
    };

    void SetVerbosity(const std::string& verbosity)
    {
        if (verbosity == "silent")
        {
            // Show no logging
            Trace::SetAreaLevels(Trace::Output, Trace::Level::Off);
        }
        else if (verbosity == "error")
        {
            // Show only Errors
            Trace::SetAreaLevels(Trace::Output, Trace::Level::Errored);
        }
        else if (verbosity == "warn")
        {
            // Show only Warnings+
            Trace::SetAreaLevels(Trace::Output, Trace::Level::Warn);
        }
        else if (verbosity == "quiet")
        {
            // Show Important+ from Transcode.CPP and Warnings+ from other areas of Spectre
            Trace::SetAreaLevels(Trace::Output, Trace::Level::Warn);
            Trace::SetAreaLevel("Transcode_CPP", Trace::Output, Trace::Level::Important);
            Trace::SetAreaLevel("Transcode_EXE", Trace::Output, Trace::Level::Important);
        }
        else if (verbosity == "default")
        {
            // Show Info+ from Transcode.CPP and Warnings+ from other areas of Spectre
            Trace::SetAreaLevels(Trace::Output, Trace::Level::Warn);
            Trace::SetAreaLevel("Transcode_CPP", Trace::Output, Trace::Level::Info);
            Trace::SetAreaLevel("Transcode_EXE", Trace::Output, Trace::Level::Info);
        }
        else if (verbosity == "verbose")
        {
            // Show Info+ from Transcode.CPP and Important+ from other areas of Spectre
            Trace::SetAreaLevels(Trace::Output, Trace::Level::Important);
            Trace::SetAreaLevel("Transcode_CPP", Trace::Output, Trace::Level::Info);
            Trace::SetAreaLevel("Transcode_EXE", Trace::Output, Trace::Level::Info);
        }
        else if (verbosity == "debug")
        {
            // Show all logging
            Trace::SetAreaLevels(Trace::Output, Trace::Level::Verbose);
        }
        else
        {
            PrintHelpWithError("Unsupported verbosity: " + verbosity);
        }
    }
}

#if defined _WIN32 && defined _UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
    ArgParser argParser(argc, argv);

    // Print help if requested
    if (argParser.HasArgument("--help"))
    {
        PrintHelp();
    }

    auto helpArg = argParser.GetArgument("--help", "");
    if (!helpArg.empty())
    {
        auto helpOptions = SplitOption(helpArg);
        PrintTranscoderHelp(helpOptions.first, helpOptions.second);
    }

    // Print version if requested
    if (argParser.HasArgument("--version"))
    {
        PrintVersion();
    }

    // Print help if no positional arguments were supplied
    auto inputFilePaths = argParser.GetPositionalArguments();
    if (inputFilePaths.size() == 0)
    {
        PrintHelpWithError("No files specified");
    }

    // Set verbosity level
    auto verbosity = argParser.GetArgument("--verbosity", "default");
    SetVerbosity(verbosity);

    // Get export format, default is "glb"
    auto format = argParser.GetArgument("--format", "glb");

    // Get destination directory and sanitize it
    auto destination = argParser.GetArgument("--destination");
    if (!destination.empty())
    {
        destination = Spectre::Utils::GetPathConsistentSlashes(Spectre::Utils::GetPathConcatenation(destination, ""));
    }

    // Get Transcoders options
    std::unordered_map<std::string, std::string> importOptions;
    for (auto& option : argParser.GetArgumentMultiple("--importoption"))
    {
        importOptions.insert(SplitOption(option));
    }

    std::unordered_map<std::string, std::string> exportOptions;
    for (auto& option : argParser.GetArgumentMultiple("--exportoption"))
    {
        exportOptions.insert(SplitOption(option));
    }

#ifdef _WIN32
    // Initialize COM
    auto result = ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (FAILED(result))
    {
        Fail("Failed to initialize COM");
    }
#endif //_WIN32

    for (auto& inputFilePath : inputFilePaths)
    {
        auto inputFileName = Spectre::Utils::GetPathFileName(inputFilePath);
        auto outputFilePath = inputFilePath + "." + format;
        TRACE_IMPORTANT(Transcode_EXE, "Transcoding %s to %s", inputFileName.c_str(), outputFilePath.c_str());

        try
        {
            Spectre::Transcode(inputFilePath, format, importOptions, exportOptions, destination);
        }
        catch (const std::exception& e)
        {
            TRACE_ERROR(Transcode_EXE, "An exception was thrown during transcode: %s", e.what());
        }
    }

    PrintMemoryStatistics();
}
