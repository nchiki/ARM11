
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "usefulTools.h"

typedef struct {
    instruction_type type;
    uint8_t cond;
    uint8_t opcode;

    uint32_t offset;

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

    //immediate value
    uint16_t immediateValue;
    
    //operand2
    uint16_t operand2;

    uint16_t carry;
    SHIFT_CODE shift;

} instruction;
//

