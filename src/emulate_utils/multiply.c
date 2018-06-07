#include <stdlib.h>
#include <stdio.h>
#include "../memoryImplementation.h"
#include "../usefulTools.h"
#include "instruction_basic.h"
#include "usefulFuncs.h"


void multiply(uint32_t instruction, MACHINE *machine){
    machine->c.decodedInstruction->binary = instruction;
	machine->c.decodedInstruction->type = Mult;
    machine->c.decodedInstruction->A = (bool)((instruction >> 21) & 1);
    machine->c.decodedInstruction->S = (bool)((instruction >> 20) & 1);
    machine->c.decodedInstruction->Rn = getBitRange(instruction, 12, 4);
    machine->c.decodedInstruction->Rd = getBitRange(instruction, 16, 4);
    machine->c.decodedInstruction->Rs = getBitRange(instruction, 8, 4);
    machine->c.decodedInstruction->Rm = getBitRange(instruction, 0, 4);
}


