cmake_minimum_required(VERSION 3.10)
project (Canvas)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Rename CMakePredefinedTarget to _CMAKE_ (to show at top of solution)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "_CMAKE_")

option(ENABLE_UNIT_TESTS "ENABLE_UNIT_TESTS" ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DFEATURE_ASSERTS_ENABLED")
set(CMAKE_XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym")
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Build/CMake")

include(CanvasPlatform)
GetCanvasPlatform(Platform)

if((DEFINED IOS_PLATFORM) OR (DEFINED ANDROID_OS_PLATFORM))
    # Disable intrinsics on iOS for now to get things building
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_XM_NO_INTRINSICS_")
endif()

# DEPRECATED: FLAVOR_* are still being used in the code but should be phased out
# Defining them here to keep the existing behaviour in the builds.
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DFLAVOR_RELEASE=1")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DFLAVOR_DEBUG=1")
set(CMAKE_CXX_FLAGS_PERFORMANCE "${CMAKE_CXX_FLAGS_PERFORMANCE} -DFLAVOR_PERFORMANCE=1")
set(CMAKE_CXX_FLAGS_PREFAST "${CMAKE_CXX_FLAGS_PREFAST} -FEATURE_PREFAST=1")

# Use vstest for UWP and gtest for everything else
if (CMAKE_SYSTEM_NAME STREQUAL "WindowsStore")
    add_definitions(-DUSE_GOOGLE_TEST=0)
    set(CANVAS_TEST_LIBRARY "")

    # vstest isn't supported for ARM64 yet
    if (Platform STREQUAL "windows_uwparm64")
        set(ENABLE_UNIT_TESTS OFF)
    endif()
else()
    add_definitions(-DUSE_GOOGLE_TEST=1)
    set(CANVAS_TEST_LIBRARY "gtest_main")
endif()

add_definitions(-DSPECTRE_ENGINE_EXCLUDE_SHADERS)

add_subdirectory("${CMAKE_SOURCE_DIR}/Build/packages")

###############################################################################
# External Projects
###############################################################################

# Add RapidJSON target
add_subdirectory(External/RapidJSON)

# Import the GLTFSDK target
add_subdirectory(External/GLTFSDK)

# For UWP/WinRT apps we use vstest
if (NOT (CMAKE_SYSTEM_NAME STREQUAL "WindowsStore"))
    add_subdirectory(External/googletest)
endif()

# Defines gli
# Only use gli on non-Windows platforms
if (NOT WIN32)
    add_subdirectory(External/gli)
endif()

add_subdirectory(External/ImGui)

if(ANDROID_OS_PLATFORM)
    add_subdirectory(External/remoteImGui)
endif()

if (WIN32)
    add_subdirectory(External/DirectXTex)
endif()

# Only include glslang for 64bit Windows builds
# glslang is only needed by the Windows shader compiler and we only build it for x64
if (Platform STREQUAL "windows_x64")
    add_subdirectory(External/glslang)
endif()

###############################################################################
# Find NuGet Packages
###############################################################################

if(APPLE)
    if(IOS_PLATFORM STREQUAL "OS")
        find_package(FBXSDK.iOS)
        find_package(Lib3MF.iOS)
    elseif(IOS_PLATFORM STREQUAL "SIMULATOR64")
        find_package(FBXSDK.iOSSimulator64)
        find_package(Lib3MF.iOSSimulator64)
    else()
        find_package(FBXSDK.macOS)
        find_package(Lib3MF.macOS)
    endif()
    find_package(PixelPixieClient)
    # Defines CLLCore, CLL, boost dependencies
    add_subdirectory(External/xplatcll)
elseif(ANDROID_OS_PLATFORM)
    add_subdirectory(External/libpng)
    add_subdirectory(External/libjpeg-turbo)
    add_subdirectory(External/cimg)
elseif(WIN32)
    find_package(PixelPixieClient)

    # Find the appropriate version of the Lib3mf package
    if ((${CMAKE_SYSTEM_NAME} STREQUAL "WindowsStore"))
        set(CANVAS_LIB3MF_WINDOWS_PACKAGE Lib3MF.WinRT)
        set(CANVAS_FBXSDK_WINDOWS_PACKAGE FBXSDK.WinRT)
    else()
        set(CANVAS_LIB3MF_WINDOWS_PACKAGE Lib3MF.Win32)
        set(CANVAS_FBXSDK_WINDOWS_PACKAGE FBXSDK.Win32)
    endif()

    find_package(${CANVAS_LIB3MF_WINDOWS_PACKAGE} COMPONENTS ${CMAKE_GENERATOR_PLATFORM})
    find_package(${CANVAS_FBXSDK_WINDOWS_PACKAGE} COMPONENTS ${CMAKE_GENERATOR_PLATFORM})
else()
    message(FATAL_ERROR "Unknown platform")
endif()

# SKP Library
if ((APPLE AND NOT IOS_PLATFORM) OR (Platform STREQUAL "windows_x64"))
    find_package(SKPSDK)
endif()

###############################################################################
# Add Canvas projects
###############################################################################

add_subdirectory(CoreUtils/Shared/CoreUtils/cpp/Build)
add_subdirectory(CoreUtils/Shared/CoreUtilsWinRt/cpp/Build)
add_subdirectory(CoreUtils/Shared/Framework/cpp/Build)
add_subdirectory(CoreUtils/Shared/CanvasTex/cpp/Build)
add_subdirectory(CoreUtils/Shared/ImagingComponent/cpp/Build)
add_subdirectory(CoreUtils/Shared/Asset3D/cpp/Build)
add_subdirectory(Engine/Products/Tools/ShaderCompiler/cpp/Build)
add_subdirectory(Engine/Products/Tools/ShaderDBLinker/cpp/Build)
add_subdirectory(RenderPAL/RenderPAL/Build)
add_subdirectory(Engine/Products/Components/NativeRenderer/cpp/Build)
add_subdirectory(Engine/Shared/NativeRendererStub/cpp/Build)
add_subdirectory(Transcoders/Shared/PluginSDK/cpp/Build)
add_subdirectory(Transcoders/Shared/Transcoders/Build)

if(APPLE)
    add_subdirectory(Engine/Shared/CanvasDebugGui/cpp/Build)
    # Metal doesn't work on the simulator
    if(NOT IOS_PLATFORM STREQUAL "SIMULATOR64")
        add_subdirectory(Engine/Shared/NativeRendererMetal/cpp/Build)
        add_subdirectory(RenderPAL/RenderPAL_Metal/Build)
    endif()

elseif(WIN32)
    add_subdirectory(Transcoders/Shared/PluginManager/cpp/Build)
    add_subdirectory(Engine/Shared/CanvasDebugGui/cpp/Build)
    add_subdirectory(Engine/Shared/NativeRendererD3D11/cpp/Build)
    add_subdirectory(RenderPAL/RenderPAL_D3D11/Build)

    # Some of the OpenGL code currently depends on Win32 APIs
    # and has not yet been ported to UWP.
    # OpenGL is also not available on ARM64.
    if (CMAKE_SYSTEM_NAME STREQUAL "Windows" AND (NOT (Platform STREQUAL "windows_arm64")))
        add_subdirectory(Engine/Shared/NativeRendererOpenGL/cpp/Build)
    endif()

    if (${CMAKE_SYSTEM_NAME} STREQUAL "WindowsStore")
        # Disable EngineWinRT for now since
        # 1. It doesn't link for unknown reasons 
        # 2. It might not be needed anymore
        #add_subdirectory(Engine/Products/Components/EngineWinRT/cpp/Build)
    endif()

elseif(ANDROID_OS_PLATFORM)
    add_subdirectory(Engine/Shared/CanvasDebugGui/cpp/Build)
    add_subdirectory(Engine/Shared/NativeRendererOpenGL/cpp/Build)
endif()


if(ENABLE_UNIT_TESTS)

    add_subdirectory(CoreUtils/Shared/TestUtils/cpp/Build)
    add_subdirectory(CoreUtils/Shared/CoreUtils.Test)
    add_subdirectory(CoreUtils/Shared/Framework.Test)
    add_subdirectory(CoreUtils/Shared/Asset3D.Test/Build)
    add_subdirectory(CoreUtils/Shared/ImagingComponent.Test)
    add_subdirectory(Transcoders/Shared/TranscoderTestUtils/cpp/Build)
    if(APPLE)
        add_subdirectory(Transcoders/Shared/Transcoders.Test)

        if(NOT IOS_PLATFORM) # macOS
            add_subdirectory(Engine/Products/Apps/NativeViewer.macOS.ObjC)
            add_subdirectory(Apps/Transcode.CPP/Build)
            add_subdirectory(Engine/Shared/NativeRenderer.Tests)
            add_subdirectory(Engine/Shared/PixelPixie.Tests.CPP)
            add_subdirectory(Engine/Shared/PixelPixieNativeRendererTests)
            add_subdirectory(Engine/Shared/PixelPixie.AnimationTests.CPP)
            add_subdirectory(Engine/Shared/PixelPixie.GLTFAssetGeneratorTests.CPP)
            add_subdirectory(Transcoders/Shared/PixelPixieTranscoderTests)
            add_subdirectory(Engine/Shared/Performance.Test/Build)

        elseif (IOS_PLATFORM STREQUAL "OS") # iOS Native

            add_subdirectory(CoreUtils/Shared/TestiOSUtils)
            add_subdirectory(Engine/Products/Apps/NativeViewer.iOS.Swft)
            add_subdirectory(Engine/Shared/NativeRenderer.Tests)
            add_subdirectory(Engine/Shared/Performance.Test/Build)

        else() # iOS Simulator

            add_subdirectory(CoreUtils/Shared/TestiOSUtils)

        endif()

    elseif(WIN32)

        #add_subdirectory(Engine/Shared/Performance.Test/Build)
        add_subdirectory(Transcoders/Shared/Transcoders.Test)
        add_subdirectory(Engine/Shared/NativeRenderer.Tests)

        if (NOT (CMAKE_SYSTEM_NAME STREQUAL "WindowsStore"))
            add_subdirectory(Engine/Shared/PixelPixie.Tests.CPP)
            add_subdirectory(Transcoders/Shared/PixelPixieTranscoderTests)
            add_subdirectory(Engine/Shared/PixelPixie.AnimationTests.CPP)
            add_subdirectory(Engine/Shared/PixelPixie.GLTFAssetGeneratorTests.CPP)
            add_subdirectory(Apps/Transcode.CPP/Build)
            add_subdirectory(Apps/GenerateThumbnail.CPP/Build)
            add_subdirectory(Engine/Shared/PixelPixieNativeRendererTests)
            add_subdirectory(Engine/Products/Apps/NativeViewer.Win32.CPP/Build)
        endif()

    elseif(ANDROID_OS_PLATFORM)
        add_subdirectory(Engine/Shared/NativeRenderer.Tests)
    endif()

endif()


if (WIN32)
    include(TargetTools)

    # Force the <WindowsTargetPlatformMinVersion> is set correctly in every project
    SetWindowsMinVersionForAllTargets(${SPECTRE_PLATFORM_MIN_VERSION})

    # Force PDBs to be generated in Release builds
    ForcePDBOutput()
endif()
