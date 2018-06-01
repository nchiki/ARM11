cmake_minimum_required(VERSION 3.10)
project(arm11_28 C)

set(CMAKE_C_STANDARD 11)

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
        src/instruction_basic.h
        src/memoryImplementation.h
        src/usefulTools.h src/usefulFuncs.c src/assemblerImplementation.h src/assemblerImplementation.c src/usefulFuncs.h src/instructions/branch.h src/instructions/DataProcDec.h src/instructions/halt.h src/instructions/multiply.h src/instructions/singleDT.h src/binaryloader.h src/decode.h)
