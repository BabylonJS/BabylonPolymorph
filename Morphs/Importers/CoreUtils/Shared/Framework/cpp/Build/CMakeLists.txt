cmake_minimum_required(VERSION 3.5)
project (Framework)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

file (GLOB COMMON_SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/../Source/*")

if(ANDROID_OS_PLATFORM)
    file (GLOB PLATFORM_SOURCE_FILES
      "${CMAKE_CURRENT_LIST_DIR}/../Source/Android/*")
elseif(APPLE)
    add_custom_command(
      OUTPUT ${CMAKE_SOURCE_DIR}/Built/Int/TraceProviders.h
      COMMAND /usr/sbin/dtrace -h -s ${CMAKE_CURRENT_LIST_DIR}/../Source/Mac/TraceProviders.d -o ${CMAKE_SOURCE_DIR}/Built/Int/TraceProviders.h
      DEPENDS ${CMAKE_CURRENT_LIST_DIR}/../Source/Mac/TraceProviders.d
    )
    file (GLOB PLATFORM_SOURCE_FILES
      "${CMAKE_CURRENT_LIST_DIR}/../Source/Mac/*"
      "${CMAKE_SOURCE_DIR}/Built/Int/TraceProviders.h")
elseif(WIN32)
    file (GLOB PLATFORM_SOURCE_FILES
      "${CMAKE_CURRENT_LIST_DIR}/../Source/Win/*"
    )
else()
    message(FATAL_ERROR "Unknown platform")
endif()

add_library(Framework ${COMMON_SOURCE_FILES} ${PLATFORM_SOURCE_FILES})
    target_include_directories(Framework
      PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
      PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Source"
      PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int"
)

set_target_properties(Framework PROPERTIES
    FOLDER "CoreUtils"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(Framework
      PRIVATE "-Wunguarded-availability"
      PRIVATE "-Wall"
      PRIVATE "-Werror")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors 
    target_compile_options(Framework PRIVATE "/WX")
endif()

target_link_libraries(Framework CoreUtils)

if(APPLE)
    target_link_libraries(Framework
      RapidJSON
      boost
      CLLCore
      CLL
      "-framework IOKit"
)
endif()
CreateCanvasInstallTargets(Framework ${Platform})