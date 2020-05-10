# Download and unpack GLTFSDK at configure time
configure_file(CMakeGLTFSDKDownload.txt.in ${CMAKE_BINARY_DIR}/GLTFSDK-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/GLTFSDK-download )
if(result)
  message(FATAL_ERROR "CMake step for GLTFSDK failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/GLTFSDK-download )
if(result)
  message(FATAL_ERROR "Build step for GLTFSDK failed: ${result}")
endif()

# Instead of adding the root of the GLTFSDK to the cmake configuration (which brings in the unit tests and RapidJSON and googletest)
# We just include the GLTFSDK library and dependencies.
# TODO: Once the GLTFSDK has conditional tests around the inclusion of RapidJSON and googletest (to avoid duplicate definitions),
# this can be reveted to the previous version.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/GLTFSDK-src/Build/CMake/Modules")
add_subdirectory(${CMAKE_BINARY_DIR}/GLTFSDK-src/GLTFSDK ${CMAKE_BINARY_DIR}/GLTFSDK-build)

# Force GLTFSDK targets in sub-folder in solution
set_target_properties(GLTFSDK PROPERTIES
    FOLDER "Dependencies"
)
