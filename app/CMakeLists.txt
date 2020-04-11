# Project Name
project(iracingOverlay)

# Add Include Directory
include_directories("${CMAKE_SOURCE_DIR}/../Includes/irsdk/")
include_directories("${CMAKE_SOURCE_DIR}")


# Link Directories
link_directories(${CMAKE_SOURCE_DIR}/../Includes)


# Define executables
add_executable(${PROJECT_NAME} irOverlay.cpp
        IRData.cpp
        IRData.h
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_defines.h"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_utils.cpp"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_client.h"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_client.cpp"
        "${CMAKE_SOURCE_DIR}/irsdk/yaml_parser.cpp"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_diskclient.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE openGLPlotLive ${LIBS} winmm ws2_32)
