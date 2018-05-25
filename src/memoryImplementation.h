//
// Created by Blanca Tebar on 25/05/2018.
//

#ifndef ARM11_28_MEMORYIMPLEMENTATION_H
#define ARM11_28_MEMORYIMPLEMENTATION_H

#include <stdlib.h>


#define PC 15;
#define CPSR 16;

struct MACHINE {
    uint32_t registers[17];
    uint32_t memoryAlloc[16384];
} machine;


#endif //ARM11_28_MEMORYIMPLEMENTATION_H
