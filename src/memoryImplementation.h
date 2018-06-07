
#ifndef ARM11_28_MEMORYIMPLEMENTATION_H
#define ARM11_28_MEMORYIMPLEMENTATION_H

#include "emulate_utils/usefulFuncs.h"

#define PC 15
#define CPSR 16

//holds the state of the program

typedef struct{
    uint32_t memoryAlloc[16384];
} MEMORY;

typedef struct{
    uint32_t registers[17];
    uint32_t fetchedInstruction;
    instructions *decodedInstruction;
} CPU;


typedef struct {
    MEMORY memory;
    CPU cpu ;
} MACHINE;

#endif //ARM11_28_MEMORYIMPLEMENTATION_H
