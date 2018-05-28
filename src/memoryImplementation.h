
#ifndef ARM11_28_MEMORYIMPLEMENTATION_H
#define ARM11_28_MEMORYIMPLEMENTATION_H

#include <stdlib.h>
#include <stdio.h>
#include "instruction.h"

#define PC 15
#define CPSR 16

//holds the state of the program
typedef struct{
    uint32_t registers[17];
    uint32_t memoryAlloc[16384];
    bool instructionFetched;
    uint32_t fetchedInstruction;
    instruction *decodedInstruction;
} machine_type;


#endif //ARM11_28_MEMORYIMPLEMENTATION_H
