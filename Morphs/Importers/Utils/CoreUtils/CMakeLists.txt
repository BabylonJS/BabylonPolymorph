# CoreUtils
file(GLOB SOURCES CONFIGURE_DEPENDS
	"Include/CoreUtils/*.h"
	"Include/CoreUtils/Math/*.h"
	"Include/CoreUtils/Tweening/*.h"
	"Include/DirectXMath/*.h"
	"Source/*.h"
	"Source/*.cpp"
	"Source/Tweening/*.cpp"
	"Source/Win/*.cpp")
	
add_library(CoreUtils ${SOURCES})

target_include_directories(CoreUtils PUBLIC "Include")

target_compile_definitions(CoreUtils
    PRIVATE NOMINMAX)

set_property(TARGET CoreUtils PROPERTY FOLDER Utils)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(CoreUtils
    GLTFSDK
    RapidJSON
)