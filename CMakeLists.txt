cmake_minimum_required(VERSION 3.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(hscSystemInfo C)

include_directories(include)

set(SOURCE_FILES
    src/osInfo.c
    src/hardwareInfo.c
)

add_library(osInfo SHARED ${SOURCE_FILES})
add_library(hardwareInfo SHARED ${SOURCE_FILES})

add_executable(saka bin/main.c)
set_target_properties(saka PROPERTIES OUTPUT_NAME "saka")

target_link_libraries(saka osInfo hardwareInfo)