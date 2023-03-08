#!/bin/bash

# Verifica se o argumento "-c" foi passado
if [ "$1" = "-c" ]; then
    # Remove arquivos gerados pelo CMake
    rm -rf CMakeCache.txt
    rm -rf CMakeFiles
    rm -rf cmake_install.cmake
    rm -rf Makefile
    rm -rf lib
    if [ -e "./bin/main" ]; then
        rm ./bin/main
    fi
    if [ -e "./bin/saka" ]; then
        rm ./bin/saka
    fi
    
else
    # Executa o comando cmake
    cmake .
    
    # Compila o código
    make
fi
