cmake_minimum_required(VERSION 3.10)
project(BabylonImporters)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# External Dependencies
add_subdirectory(Dependencies/RapidJSON)
add_subdirectory(Dependencies/GLTFSDK)
add_subdirectory(Dependencies/DirectXTex)

# Load SketchUP (if available)
if(WIN32)
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Dependencies/SketchUpAPI-Windows")
	find_package(SKPSDK.Windows)
	
	if(SKPSDK_FOUND)
		add_definitions(-DHAS_SKP_LIB)
	endif()
endif()

add_subdirectory(Utils)
add_subdirectory(Transcoders)
add_subdirectory(Apps)