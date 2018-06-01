//
// Created by nb1317 on 01/06/18.
//

#ifndef ARM11_28_ASSEMBLERIMPLEMENTATION_H
#define ARM11_28_ASSEMBLERIMPLEMENTATION_H

#include <stdint.h>
#include <stdbool.h>

struct symbol {

    char *label;
    uint32_t address;
    struct symbol *next;

    void clear() {
        free(this->label);
        free(this);
    }
};

// purposely did not use typedef because typedef breaks a couple of things in the implementation of addLabel in assemblerImplementation.c
// DO NOT CHANGE TO TYPEDEF STRUCT {..}SYMBOL;

struct symbol *symbolTableHead;

void initSymbolTable(void);

void addLabel (char*, uint32_t) ;

uint32_t getAddress (char*);

void clearSymbolTable();

#endif //ARM11_28_ASSEMBLERIMPLEMENTATION_H
