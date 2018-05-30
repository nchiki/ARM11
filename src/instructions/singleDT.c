#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../memoryImplementation.h"
#include "../instruction.h"
#include "../usefulTools.h"
#include "../usefulFuncs.c"

void SDTdecode(uint32_t instruction, MACHINE *machine) {
	machine->c.decodedInstruction->type = SDT;
    machine->c.decodedInstruction->I = instruction&0x2000000;
    machine->c.decodedInstruction->P = instruction&0x1000000;
    machine->c.decodedInstruction->U = instruction&0x800000;
    machine->c.decodedInstruction->L = instruction&0x100000;
    machine->c.decodedInstruction->Rn = getBitRange(instruction, 16, 4);
    machine->c.decodedInstruction->Rd = getBitRange(instruction, 12, 15);
    machine->c.decodedInstruction->offset = getBitRange(instruction, 0, 12);
}
//

