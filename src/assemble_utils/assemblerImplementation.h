//
// Created by nb1317 on 01/06/18.
//

#ifndef ARM11_28_ASSEMBLERIMPLEMENTATION_H
#define ARM11_28_ASSEMBLERIMPLEMENTATION_H

#include <stdint.h>
#include <stdbool.h>
//#include "../usefulTools.h"
#include "assemblerImplementation.h"
#include "defs.h"
#include "../usefulTools.h"

struct symbol {

    char *label;
    uint16_t address;
    struct symbol *next;


};

// this was just extra effort, instead, let there be an overall data structure like the one in emulate which has a subtype type

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

// purposely did not use typedef because typedef breaks a couple of things in the implementation of addLabel in assemblerImplementation.c
// DO NOT CHANGE TO TYPEDEF STRUCT {..}SYMBOL;

// all the opcodes, not entirely too sure what to do for the special instructions
static const char *Opcodes[][10] = {
        {"add", "sub", "rsb", "and", "eor", "orr", "mov", "tst", "teq", "cmp"},
        {"mul", "mla"},
        {"ldr", "str"},
        { "beq", "bne", "bge", "blt", "bgt", "ble", "b"}

};


typedef enum {
    DATA_PROCESSING, MULTIPLY, SINGLE_DATA_TRANSFER, BRANCH, LSL, ANDEQ
}instrType ;

// there should be an enum for instrtype
struct instruction {
    char *opcode;
    instrType type;

    char *Rd;
    char *Rn;
    char *operand2;

    char *Rm;
    char *Rs;

    char *address;
    char *expression;

    uint16_t memoryAddr;
};


struct instruction decode(char**, uint16_t);

struct symbol *symbolTableHead;

void initSymbolTable(void);

void addLabel (char*, uint16_t) ;

uint16_t getAddress (char*);

void clearSymbolTable();

bool containsLabel(char*);
uint32_t parse(char*);

#endif //ARM11_28_ASSEMBLERIMPLEMENTATION_H
