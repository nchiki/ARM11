cmake_minimum_required(VERSION 3.10)
project(arm11_28 C)

set(CMAKE_C_STANDARD 11)

add_executable(arm11_28
        src/emulate_utils/instructions/branch.c
        src/emulate_utils/instructions/DataProcDec.c
        src/emulate_utils/instructions/multiply.c
        src/emulate_utils/instructions/singleDT.c
        src/assemble.c
        src/emulate_utils/binaryloader.c
        src/emulate_utils/decode.c
        src/emulate.c
        src/emulate_utils/execute.c
        src/emulate_utils/execute.h
        src/emulate_utils/instruction_basic.h
        src/memoryImplementation.h
        src/usefulTools.h
        src/usefulFuncs.c
        src/assemble_utils/assemblerImplementation.h
        src/assemble_utils/assemblerImplementation.c
        src/usefulFuncs.h
        src/emulate_utils/instructions/branch.h
        src/emulate_utils/instructions/DataProcDec.h
        src/emulate_utils/instructions/halt.h
        src/emulate_utils/instructions/multiply.h
        src/emulate_utils/instructions/singleDT.h
        src/emulate_utils/binaryloader.h
        src/emulate_utils/decode.h src/assemble_utils/defs.h src/assemble_utils/defs.c src/assemble_utils/instructions/multiply.c src/assemble_utils/instructions/instruction_defs.h
        src/assemble_utils/instructions/branch.c src/assemble_utils/instructions/DataProc.c src/assemble_utils/instructions/multiply.h src/assemble_utils/instructions/branch.h src/assemble_utils/instructions/DataProc.h)
