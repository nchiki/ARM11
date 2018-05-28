#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "memoryImplementation.h"
#include "instruction.h"
#include "usefulTools.h"


void STDdecode(uint32_t instruction, machine_type machine) {
    machine.decodedInstruction->I = instruction&0x2000000;
    machine.decodedInstruction->P = instruction&0x1000000;
    machine.decodedInstruction->U = instruction&0x800000;
    machine.decodedInstruction->L = instruction&0x100000;
    machine.decodedInstruction->Rn = getBitRange(instruction, 16, 4);
    machine.decodedInstruction->Rd = getBitRange(instruction, 12, 15);
    machine.decodedInstruction->offset = getBitRange(instruction, 0, 12);
}
//

