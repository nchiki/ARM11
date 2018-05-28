#include <stdio.h>
#include <stdlib.h>
#include <memoryImplementation.h>
#include <instruction.h>
#include "instruction.h"
#include "memoryImplementation.h"
#include "decode.c"

void decodeDATPROC(uint32_t instruction, machine_type machine){
    machine.decodedInstruction->type = DProc;
    machine.decodedInstruction->Rn = getBitRange(instruction, 16, 4);
    machine.decodedInstruction->Rd = getBitRange(instruction, 12, 15);
    machine.decodedInstruction->I = instruction&0x2000000;
    machine.decodedInstruction->S = instruction&0x100000;
    machine.decodedInstruction->operand2 = getBitRange(instruction, 0, 12);
    machine.decodedInstruction->opcode = getBitRange(instruction, 21, 4);
    machine.decodedInstruction->cond = getBitRange(instruction, 28, 4);

}


