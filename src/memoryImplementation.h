//
// Created by Blanca Tebar on 25/05/2018.
//

#ifndef ARM11_28_MEMORYIMPLEMENTATION_H
#define ARM11_28_MEMORYIMPLEMENTATION_H

#include <stdlib.h>
#define N_MASK 0x80000000;
#define Z_MASK 0X40000000;
#define C_MASK 0x20000000;
#define V_MASK 0x10000000;

#define PC 15;
#define CPSR 16;

typedef struct {
    uint32_t registers[17];
    uint32_t memoryAlloc[16384];
};
#endif //ARM11_28_MEMORYIMPLEMENTATION_H
