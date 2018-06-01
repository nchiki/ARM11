//
// Created by nb1317 on 01/06/18.
//

#ifndef ARM11_28_ASSEMBLERIMPLEMENTATION_H
#define ARM11_28_ASSEMBLERIMPLEMENTATION_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {

    char *label;
    uint32_t address;
    struct symbol *next;
} symbol;

typedef struct {
    struct symbol *head;
}symbolTable;






#endif //ARM11_28_ASSEMBLERIMPLEMENTATION_H
