cmake_minimum_required(VERSION 3.10)
project(arm11_28 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(arm11_28
        src/instructions/branch.c
        src/instructions/DataProcDec.c
        src/instructions/multiply.c
        src/instructions/singleDT.c
        src/assemble.c
        src/binaryloader.c
        src/decode.c
        src/emulate.c
        src/execute.c
        src/execute.h
        src/instruction.h
        src/memoryImplementation.h
        src/usefulTools.h)