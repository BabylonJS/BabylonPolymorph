# Framework
file(GLOB SOURCES CONFIGURE_DEPENDS
	"Include/Framework/*.h"
	"Include/Framework/*.hpp"
	"Source/*.h"
	"Source/*.cpp"
	"Source/Win/*.h"
	"Source/Win/*.cpp")
	
add_library(Framework ${SOURCES})

target_include_directories(Framework PUBLIC "Include")
target_include_directories(Framework PUBLIC "Source")

set_property(TARGET Framework PROPERTY FOLDER Utils)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(Framework
    CoreUtils
)