#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "../memoryImplementation.h"
#include "instruction_basic.h"

void branch(uint32_t instruction, MACHINE *machine) {
	machine->c.decodedInstruction->type = Branch;
    machine->c.decodedInstruction->offset = instruction & 0xFFFFFF;//24 bit offset
    machine->c.decodedInstruction->binary = instruction;
}

