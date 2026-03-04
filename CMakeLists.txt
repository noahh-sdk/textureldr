cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TextureLDR VERSION 1.0.0)

# Use GLOB_RECURSE instead of GLOB
# to recursively add all source files 
# under src/ 
file(GLOB SOURCES
	src/*.cpp
)

# Set up the mod binary
add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{NOAHH_SDK})
    message(FATAL_ERROR "Unable to find Noahh SDK! Please define NOAHH_SDK environment variable to point to Noahh")
else()
    message(STATUS "Found Noahh: $ENV{NOAHH_SDK}")
endif()

set(NOAHH_LINK_NIGHTLY ON)
add_subdirectory($ENV{NOAHH_SDK} $ENV{NOAHH_SDK}/build)

target_link_libraries(${PROJECT_NAME} noahh-sdk)
create_noahh_file(${PROJECT_NAME})