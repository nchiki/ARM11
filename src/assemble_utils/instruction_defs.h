//
// Created by nahida on 6/5/18.
//

#ifndef ARM11_28_INSTRUCTION_DEFS_H
#define ARM11_28_INSTRUCTION_DEFS_H

#include <stdint.h>
#include "../usefulTools.h"
#include "defs.h"

typedef struct {
    MNEMONIC mnemonic;
    cond_code cond;
    OPCODE opcode;
    int Rn;
    int Rd;
    uint32_t Operand2;
} DataProcInstr_t;

typedef struct {
    MNEMONIC mnemonic;
    cond_code cond;
    char A;
    char S;
    int Rn;
    int Rd;
    int Rs;
    int Rm;
} MultiplyInstr_t;

typedef struct {
    MNEMONIC mnemonic;
    cond_code cond;
    char P;
    char U;
    char L;
    int Rn;
    int Rd;
    uint16_t offset;
} SDTinstr_t;

typedef struct {
    MNEMONIC mnemonic;
    cond_code cond;
    uint32_t offset;
} BranchInstr_t;


#endif //ARM11_28_INSTRUCTION_DEFS_H
