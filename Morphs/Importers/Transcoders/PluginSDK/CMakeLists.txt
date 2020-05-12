# PluginSDK
file(GLOB SOURCES CONFIGURE_DEPENDS
	"Include/PluginSDK/*.h"
	"Source/*.h"
	"Source/*.cpp")
	
add_library(PluginSDK ${SOURCES})

target_include_directories(PluginSDK PUBLIC "Include")

target_compile_definitions(PluginSDK
    PRIVATE NOMINMAX)

set_property(TARGET PluginSDK PROPERTY FOLDER Transcoders)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(PluginSDK
    CoreUtils
	Framework
	CanvasTex
	ImagingComponent
	Asset3D
	RapidJSON
)
