//
// Created by bt3917 on 05/06/18.
//

#include <stdint.h>
#include <memory.h>
#include "../assemblerImplementation.h"
#include "instruction_defs.h"

uint32_t *branch(struct instruction instruction) {
    BranchInstr_t branchInstr;
    char *cond = instruction.opcode + 1; //it takes rid of the initial "b" of the mnemonic
    //compares the condition part of the instruction's mnemonic to the different conditions and
    //sets the binary of the cond using the struct defined in usefulTools.h
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

    while (curr != NULL) { //looks for the label in the symbol table
        if(!strcmp(curr.label, instruction.expression)) { // compares each label of the elements in the symbol table to find the correct one
            uint32_t signedVal = (curr.address-(instruction.address - 8))>> 2; // if found, subtracts the address of the current instruction
            //(taking into account the 8 bits offset of the pipeline) to the address of the label, and shifts it to the right
            uint32_t absVal = abs(signedVal); //to two's complement
            if (signedVal< 0) {
            absVal = (~absVal) + 1;
              }
            branchInstr.offset = absVal; // sets the offset to the two's complement
        }
    }
}
