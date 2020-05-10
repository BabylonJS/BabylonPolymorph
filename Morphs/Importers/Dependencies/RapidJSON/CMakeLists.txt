# Check if this target has already been included elsewhere (like through another external project like GLTFSDK)
if (TARGET RapidJSON)
  get_target_property(IncludeDirs RapidJSON INTERFACE_INCLUDE_DIRECTORIES)
  message(AUTHOR_WARNING "RapidJSON target already defined.  Will be included from here ${IncludeDirs}")
  return()
endif()

# Download and unpack RapidJSON at configure time
configure_file(CMakeRapidJSONDownload.txt.in ${CMAKE_BINARY_DIR}/RapidJSON-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/RapidJSON-download )
if(result)
  message(FATAL_ERROR "CMake step for RapidJSON failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/RapidJSON-download )
if(result)
  message(FATAL_ERROR "Build step for RapidJSON failed: ${result}")
endif()

# Disable building the docs, tests, and examples
set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_DOC OFF CACHE BOOL "" FORCE)

# Add RapidJSON directly to our build.
add_subdirectory(${CMAKE_BINARY_DIR}/RapidJSON-src
                 ${CMAKE_BINARY_DIR}/RapidJSON-build
                 EXCLUDE_FROM_ALL)

# Set the RapidJSONConfig.cmake path and make find_package to work in config mode explicitly.
set(RapidJSON_DIR "${CMAKE_BINARY_DIR}/RapidJSON-build" CACHE LOCATION "Specific configuration file location")
find_package(RapidJSON REQUIRED CONFIG)

add_library(RapidJSON INTERFACE IMPORTED GLOBAL)
set_target_properties(RapidJSON PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${RapidJSON_INCLUDE_DIRS})
