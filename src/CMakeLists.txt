# Project Name
project(iracingTraceOverlay)

# Add Include Directory
include_directories("${CMAKE_SOURCE_DIR}/../Includes/openGLPlotLive/")
include_directories("${CMAKE_SOURCE_DIR}/../Includes/irsdk/")
include_directories("${CMAKE_SOURCE_DIR}")


# Link Directories
link_directories(${CMAKE_SOURCE_DIR}/../Includes)


# Define executables
add_executable(iracingTraceOverlay
        irTraceOverlay.cpp
        DataParser.cpp
        DataParser.h
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_defines.h"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_utils.cpp")

target_link_libraries(iracingTraceOverlay PRIVATE openGLPlotLive ${LIBS} winmm ws2_32)
