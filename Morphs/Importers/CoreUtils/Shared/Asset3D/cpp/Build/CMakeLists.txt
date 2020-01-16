cmake_minimum_required(VERSION 3.5)
project (Asset3D)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

file(GLOB headers
    "${CMAKE_CURRENT_LIST_DIR}/../Inc/Asset3D/*.h"
)

file(GLOB source_cpp
    "${CMAKE_CURRENT_LIST_DIR}/../Source/*.cpp"
)

add_library(Asset3D ${source_cpp} ${headers})

set_target_properties(Asset3D PROPERTIES
    FOLDER "CoreUtils"
)

target_include_directories(Asset3D
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
    PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(Asset3D
      PRIVATE "-Wunguarded-availability"
      PRIVATE "-Wall"
      PRIVATE "-Werror")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors
    target_compile_options(Asset3D PRIVATE "/WX")
endif()

target_link_libraries(Asset3D
    ImagingComponent
    Framework
    CoreUtils
)

CreateCanvasInstallTargets(Asset3D ${Platform})