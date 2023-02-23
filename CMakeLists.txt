cmake_minimum_required(VERSION 3.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(hscSystemInfo C)

include_directories(include)

set(SOURCE_FILES
    src/systeminfo.c
)

add_library(systeminfo SHARED ${SOURCE_FILES})

add_executable(main bin/main.c)

target_link_libraries(main systeminfo)

