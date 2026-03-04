cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TextureLoader VERSION 1.0.0)

file(GLOB SOURCES
	src/*.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{NOAHH_SDK})
    message(FATAL_ERROR "Unable to find Noahh SDK! Please define NOAHH_SDK environment variable to point to Noahh")
else()
    message(STATUS "Found Noahh: $ENV{NOAHH_SDK}")
endif()

add_subdirectory($ENV{NOAHH_SDK} ${CMAKE_CURRENT_BINARY_DIR}/noahh)

target_link_libraries(${PROJECT_NAME} noahh-sdk)
create_noahh_file(${PROJECT_NAME})