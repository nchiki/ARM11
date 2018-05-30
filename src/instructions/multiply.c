#include <stdlib.h>
#include <stdio.h>
#include "../memoryImplementation.h"
#include "../usefulTools.h"
#include "../instruction.h"
#include "../usefulFuncs.c"

void multiply(uint32_t instruction, MACHINE *machine){
	machine->c.decodedInstruction->type = Mult;
    machine->c.decodedInstruction->A = instruction&0x200000;
    machine->c.decodedInstruction->S = instruction&0x100000;
    machine->c.decodedInstruction->Rn = getBitRange(instruction, 12, 4);
    machine->c.decodedInstruction->Rd = getBitRange(instruction, 16, 4);
    machine->c.decodedInstruction->Rs = getBitRange(instruction, 8, 4);
    machine->c.decodedInstruction->Rm = getBitRange(instruction, 0, 4);
}


