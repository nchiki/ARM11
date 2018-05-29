cmake_minimum_required(VERSION 3.10)
project(C_code C)

set(CMAKE_C_STANDARD 11)

add_executable(C_code
        assemble.c
        emulate.c binaryloader.c
        instructions/singleDT.c
        execute.h
        execute.c
        instruction.h
        memoryImplementation.h
        usefulTools.h
        decode.c
        instructions/multiply.c
        instructions/branch.c
        instructions/DataProcDec.c
        )

