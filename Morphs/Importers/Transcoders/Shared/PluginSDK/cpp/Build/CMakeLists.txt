cmake_minimum_required(VERSION 3.5)
project (PluginSDK)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DFEATURE_TELEMETRYENABLED=1 -DFEATURE_TELEMETRYEXCEPTIONSENABLED=1")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DFEATURE_TELEMETRYENABLED=1 -DFEATURE_TELEMETRYEXCEPTIONSENABLED=1")

file(GLOB source_cpp
    "${CMAKE_CURRENT_LIST_DIR}/../Source/*.cpp"
)

add_library(PluginSDK ${source_cpp})

set_target_properties(PluginSDK PROPERTIES
    FOLDER "Transcoders"
)

target_include_directories(PluginSDK
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(PluginSDK
        PRIVATE "-Wall"
        PRIVATE "-Werror"
        PRIVATE "-Wunguarded-availability"
    )
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors 
    target_compile_options(PluginSDK PRIVATE "/WX")
endif()

target_link_libraries(PluginSDK
    Asset3D
    CanvasTex
    ImagingComponent
    Framework
    CoreUtils
    RapidJSON
)

CreateCanvasInstallTargets(PluginSDK ${Platform})
