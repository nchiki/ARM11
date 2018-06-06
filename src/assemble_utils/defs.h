//
// Created by Blanca Tebar on 03/06/2018.
//

#ifndef ARM11_28_DEFS_H
#define ARM11_28_DEFS_H

#include <stdint.h>
#include <stdint-gcc.h>

#define MAX_LINE_SIZE 511

typedef enum {
    add,
    sub,
    rsb,
    and,
    eor,
    orr,
    mov,
    tst,
    teq,
    cmp,
    mul,
    mla,
    ldr,
    str,
    beq,
    bne,
    bge,
    blt,
    bgt,
    ble,
    b,
    lsl,
    andeq
} MNEMONIC;

char **tokenizeHelper(char*);

uint32_t *distinguish(struct instruction, struct symbol *);


#endif //ARM11_28_DEFS_H
