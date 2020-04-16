# Project Name
project(WheelInputChecker)

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
add_executable(${PROJECT_NAME} WheelInputChecker.cpp WheelInput.cpp WheelInput.h)


# Link required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS} winmm ws2_32)

