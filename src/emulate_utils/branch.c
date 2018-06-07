#include "branch.h"



void branch(uint32_t instruction, MACHINE *machine) { //checked
	machine->c.decodedInstruction->type = Branch;
    machine->c.decodedInstruction->offset = (instruction & 0xFFFFFF) << 2;//24 bit offset
    machine->c.decodedInstruction->binary = instruction;
		machine->c.decodedInstruction->cond = getBitRange(instruction, 28, 4) & 0xF;
		
}
