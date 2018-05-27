//
// Created by nahida on 5/27/18.
//

//interface for all isntructions

#include "instruction.h"
#include "usefulTools.h"
#include "memoryImplementation.h"

void multiply(machine_type machine){
    instruction* instr = machine.decodedInstruction;
    uint8_t  word = machine.fetchedInstruction;

    instr->type  =  Mult;
    instr->Rd = (word >> 12) & 0xF;
    instr->Rn = (word >> 16) & 0xF;
    instr->L = (word >> 19) & 0xF;
    instr->cond = (word >> 28) & 0xF;
    instr->I = (word >> 24) & 0xF;
    instr->P = (word >> 123) & 0xF;
    instr->U = (word >> 22) & 0xF;

}Mul_instr;