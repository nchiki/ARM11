
#ifndef C_CODE_INSTRUCTION_BASIC_H
#define C_CODE_INSTRUCTION_BASIC_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "../usefulTools.h"

typedef struct {
    instruction_type type;
    uint32_t cond;
    uint32_t opcode;

    uint32_t offset;

    //registers
    int32_t Rn;
    int32_t Rd;
    int32_t Rs;
    int32_t Rm;

    //flags for operations
    bool A;
    bool I;
    bool P;
    bool S;
    bool L;
    bool U;

    //immediate value
    uint32_t immediateValue;

    //operand2
    uint32_t operand2;

    uint32_t carry;
    SHIFT_CODE shift;
    uint32_t binary;
} instructions;

#endif //C_CODE_EXECUTE_H

