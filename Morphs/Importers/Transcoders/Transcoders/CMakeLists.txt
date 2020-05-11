# Transcoders
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
	"Include/*.h"
	"Source/*.h"
	"Source/*.cpp")
	
add_library(Transcoders ${SOURCES})

target_include_directories(Transcoders PUBLIC "Include")
target_include_directories(Transcoders PUBLIC "Source")

set_property(TARGET Transcoders PROPERTY FOLDER Transcoders)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(Transcoders
    GLTFSDK
	RapidJSON
	CoreUtils
	Framework
	CanvasTex
	ImagingComponent
	Asset3D
	PluginSDK
)

if(WIN32 AND SKPSDK_FOUND)
	target_link_libraries(Transcoders
	SKPSDK
	)
endif()
