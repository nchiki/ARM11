//
// Created by nb1317 on 01/06/18.
//

#ifndef ARM11_28_ASSEMBLERIMPLEMENTATION_H
#define ARM11_28_ASSEMBLERIMPLEMENTATION_H

#include <stdint.h>
#include <stdbool.h>
#include "../usefulTools.h"
#include "assemblerImplementation.h"
#include "defs.h"

struct symbol {

    char *label;
    uint32_t address;
    struct symbol *next;


};

// purposely did not use typedef because typedef breaks a couple of things in the implementation of addLabel in assemblerImplementation.c
// DO NOT CHANGE TO TYPEDEF STRUCT {..}SYMBOL;

//typedefs for each of the instruction. To turn them into a uint32_t we might have to add them using masks...
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


struct symbol *symbolTableHead;

void initSymbolTable(void);

void addLabel (char*, uint32_t) ;

uint32_t getAddress (char*);

void clearSymbolTable();

uint32_t parse(char*);

#endif //ARM11_28_ASSEMBLERIMPLEMENTATION_H
