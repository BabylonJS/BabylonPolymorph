cmake_minimum_required(VERSION 3.5)
project (Transcoders)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

file(GLOB COMMON_SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/../Source/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterSTL/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderSTL/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterOBJ/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderOBJ/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterGLTF/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderGLTF/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderPLY/*.cpp"
)
if(APPLE)
    if(NOT IOS_PLATFORM)
        file(GLOB PLATFORM_SOURCE_FILES
            "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Exporter3MF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Transcoder3MF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderSKP/*.cpp"
        )
    else()
        file(GLOB PLATFORM_SOURCE_FILES
            "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Exporter3MF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Transcoder3MF/*.cpp"
        )
    endif()
elseif (WIN32)
    if(Platform STREQUAL "windows_x64")
        file(GLOB PLATFORM_SOURCE_FILES
            "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Exporter3MF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Transcoder3MF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderBXF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterTexture/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderTexture/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderSKP/*.cpp"
        )
    else()
        file(GLOB PLATFORM_SOURCE_FILES
            "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderFBX/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Exporter3MF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/Transcoder3MF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderBXF/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/ExporterTexture/*.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/../Source/TranscoderTexture/*.cpp"
        )
    endif()
endif()

add_library(Transcoders ${COMMON_SOURCE_FILES} ${PLATFORM_SOURCE_FILES})

set_target_properties(Transcoders PROPERTIES
    FOLDER "Transcoders"
)

target_include_directories(Transcoders
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Source"
    PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(Transcoders
        PRIVATE "-Wall"
        PRIVATE "-Werror"
        PRIVATE "-Wunguarded-availability"
    )
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors 
    target_compile_options(Transcoders PRIVATE "/WX")
endif()

target_link_libraries(Transcoders
    GLTFSDK
    PluginSDK
    Asset3D
    CanvasTex
    ImagingComponent
    Framework
    CoreUtils
    RapidJSON
)

if((APPLE AND NOT IOS_PLATFORM) OR (Platform STREQUAL "windows_x64"))
    target_link_libraries(Transcoders
        SKPSDK
    )
endif()

if(APPLE OR WIN32)
    target_link_libraries(Transcoders
        FBXSDK
        Lib3MF
    )
endif()

CreateCanvasInstallTargets(Transcoders ${Platform})
