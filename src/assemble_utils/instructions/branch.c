//
// Created by bt3917 on 05/06/18.
//

#include <stdint.h>
#include <memory.h>
#include "../assemblerImplementation.h"

uint32_t branch(struct instruction instruction) {
    BranchInstr_t branchInstr;
    char *cond = instruction.opcode + 1; //it takes rid of the initial "b" of the mnemonic
    if (!strcmp(*cond, "eq")) {
        branchInstr.cond = EQ;
    } else if (!strcmp(*cond, "ne")) {
        branchInstr.cond = NE;
    } else if (!strcmp(*cond, "ge")) {
        branchInstr.cond = GE;
    } else if (!strcmp(*cond, "lt")) {
        branchInstr.cond = LT;
    } else if (!strcmp(*cond, "gt")) {
        branchInstr.cond = GT;
    } else if (!strcmp(*cond, "le")) {
        branchInstr.cond = LE;
    } else {
        branchInstr.cond = AL;
    }

    struct symbol *curr = symbolTableHead;

    while (curr != NULL) {
        
    }
}
