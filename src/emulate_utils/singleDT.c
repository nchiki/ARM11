#include "singleDT.h"

void SDTdecode(uint32_t instruction, MACHINE *machine) {
    machine->c.decodedInstruction->binary = instruction;
	machine->c.decodedInstruction->type = SDT;
    machine->c.decodedInstruction->I = (bool)((instruction >> 25) & 1);
    machine->c.decodedInstruction->P = (bool)((instruction >> 24) & 1);
    machine->c.decodedInstruction->U = (bool)((instruction >> 23) & 1);
    machine->c.decodedInstruction->L = (bool)((instruction >> 20) & 1);
    machine->c.decodedInstruction->Rn = getBitRange(instruction, 16, 4);
    machine->c.decodedInstruction->Rd = getBitRange(instruction, 12, 15);
    machine->c.decodedInstruction->offset = getBitRange(instruction, 0, 12);
}
//

