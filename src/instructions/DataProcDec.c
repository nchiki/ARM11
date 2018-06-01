#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../instruction_basic.h"
#include "../usefulFuncs.c"
#include "../memoryImplementation.h"

void decodeDATPROC(uint32_t instruction, MACHINE *machine){
    machine->c.decodedInstruction->type = DProc;
    machine->c.decodedInstruction->Rn = getBitRange(instruction, 16, 4);
    machine->c.decodedInstruction->Rd = getBitRange(instruction, 12, 15);
    machine->c.decodedInstruction->I = instruction&0x2000000;
    machine->c.decodedInstruction->S = instruction&0x100000;
    machine->c.decodedInstruction->operand2 = getBitRange(instruction, 0, 12);
    machine->c.decodedInstruction->opcode = getBitRange(instruction, 21, 4);
    machine->c.decodedInstruction->cond = getBitRange(instruction, 28, 4);

}


