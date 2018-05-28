cmake_minimum_required(VERSION 3.10)
project(C_code C)

set(CMAKE_C_STANDARD 11)

add_executable(C_code
        src/assemble.c
        src/emulate.c src/binaryloader.c
        src/instructions/singleDT.c
        src/execute.h
        src/execute.c
        src/instruction.h
        src/memoryImplementation.h
        src/usefulTools.h
        src/decode.c
        src/instructions/multiply.c
        src/instructions/branch.c
        src/instructions/DataProcDec.c
        )

