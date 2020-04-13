# Project Name
project(iracingOverlay)

# Add CMP0076 flag
if(POLICY CMP0076)
    cmake_policy(SET CMP0076 NEW)
endif()

# Add Include Directory
include_directories("${CMAKE_SOURCE_DIR}/../Includes/openGLPlotLive/")
include_directories("${CMAKE_SOURCE_DIR}/../Includes/irsdk/")
include_directories("${CMAKE_SOURCE_DIR}")


# Link Directories
link_directories(${CMAKE_SOURCE_DIR}/../Includes)


# Define executables
add_executable(${PROJECT_NAME} irOverlay.cpp
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_defines.h"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_utils.cpp"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_client.h"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_client.cpp"
        "${CMAKE_SOURCE_DIR}/irsdk/yaml_parser.cpp"
        "${CMAKE_SOURCE_DIR}/irsdk/irsdk_diskclient.cpp")

# Add subdirectories
add_subdirectory(irData)
add_subdirectory(throttleBrakeTrace)

# Link required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE openGLPlotLive ${LIBS} winmm ws2_32)

# Copy Shader files to build directory
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ../../openGLPlotLive/Shaders $<TARGET_FILE_DIR:${PROJECT_NAME}>/Shaders)
