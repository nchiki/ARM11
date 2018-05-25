//
// Created by Blanca Tebar on 25/05/2018.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void branch(uint32_t instruction) {
    uint32_t offset = instruction & 0xFFFFFF; //24 bit offset
    offset <<=2; // shift left

    /* sign extension for two's complement */
    if (offset >> 23 & 0x1) {
        // the number is negative
        offset |= 0xFC000000;
    }
}

