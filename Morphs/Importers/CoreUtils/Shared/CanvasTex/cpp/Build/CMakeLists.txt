cmake_minimum_required(VERSION 3.5)
project (CanvasTex)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

file (GLOB COMMON_SOURCE_FILES
     "${CMAKE_CURRENT_LIST_DIR}/../Source/*"
)

if(ANDROID_OS_PLATFORM)
    file (GLOB PLATFORM_SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Android/*" 
         "${CMAKE_CURRENT_LIST_DIR}/../Source/Android-Mac/*"
    )
elseif(APPLE)
    file (GLOB PLATFORM_SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Mac/*"
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Android-Mac/*"
    )
elseif(WIN32)
    file (GLOB PLATFORM_SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Win/*"
    )
else()
    message(FATAL_ERROR "Unknown platform")
endif()

add_library(CanvasTex ${COMMON_SOURCE_FILES} ${PLATFORM_SOURCE_FILES})

set_target_properties(CanvasTex PROPERTIES
    FOLDER "CoreUtils"
)

target_include_directories(CanvasTex
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../Source"
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../Source/Android-Mac"
    PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(CanvasTex
      PRIVATE "-Wunguarded-availability"
      PRIVATE "-Wall"
      PRIVATE "-Werror")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors 
    target_compile_options(CanvasTex PRIVATE "/WX")
endif()

set_target_properties(CanvasTex PROPERTIES
    XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES
)

target_link_libraries(CanvasTex Framework CoreUtils)

if(APPLE)

    target_link_libraries(CanvasTex gli "-framework Accelerate")

elseif(ANDROID_OS_PLATFORM)

    target_link_libraries(CanvasTex gli libpng libjpeg-turbo cimg)

elseif(WIN32)

    target_link_libraries(CanvasTex DirectXTex d3d11.lib dxgi.lib windowscodecs.lib)

endif()

CreateCanvasInstallTargets(CanvasTex ${Platform})