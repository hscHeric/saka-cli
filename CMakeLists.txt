cmake_minimum_required(VERSION 3.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(hscSystemInfo C)

include_directories(include)

set(SOURCE_FILES
    src/OsInfo.c
)

# if (CMAKE_SYSTEM_NAME MATCHES "Windows")
#     # Coloque aqui as configurações para a plataforma Windows
# else ()
#     # Coloque aqui as configurações para outras plataformas
# endif()

add_library(OsInfo SHARED ${SOURCE_FILES})

add_executable(main bin/main.c)

target_link_libraries(main OsInfo)