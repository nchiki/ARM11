cmake_minimum_required(VERSION 3.10)
project(C_code C)

set(CMAKE_C_STANDARD 11)

add_executable(C_code
        src/assemble.c
        src/emulate.c
        src/binaryloader.c
        src/branch.c
        src/memoryImplementation.h src/usefulTools.h)