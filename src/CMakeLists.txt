cmake_minimum_required(VERSION 3.10)
project(C_code C)

set(CMAKE_C_STANDARD 11)

add_executable(C_code
        assemble.c
        emulate.c
        binaryloader.c
        branch.c
        memoryImplementation.h)