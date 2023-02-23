#!/bin/bash

# Verifica se o argumento "-c" foi passado
if [ "$1" = "-c" ]; then
  # Remove arquivos gerados pelo CMake
  rm -rf CMakeCache.txt
  rm -rf CMakeFiles
  rm -rf cmake_install.cmake
  rm -rf Makefile
else
  # Executa o comando cmake
  cmake .

  # Compila o código
  make
fi
