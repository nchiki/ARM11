//
// Created by Blanca Tebar on 26/05/2018.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "usefulTools.h"

typedef struct {
    instruction_type type;
    uint8_t cond;
    uint8_t opcode;

    //registers
    uint8_t Rn;
    uint8_t Rd;
    uint8_t Rs;
    uint8_t Rm;

    //flags for operations
    bool A;
    bool I;
    bool P;
    bool S;
    bool L;
    bool U;

    //inmediate value
    uint16_t inmediateValue;

} instruction;
//

