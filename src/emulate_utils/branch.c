#include "branch.h"



void branch(uint32_t instruction, MACHINE *machine) {
	machine->c.decodedInstruction->type = Branch;
    machine->c.decodedInstruction->offset = (instruction & 0xFFFFFF) << 2;//24 bit offset
    machine->c.decodedInstruction->binary = instruction;
}

