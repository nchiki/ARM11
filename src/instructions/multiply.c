#include <stdlib.h>
#include <stdio.h>
#include "../memoryImplementation.h"
#include "../usefulTools.h"
#include "../instruction.h"
#include "decode.c"

void multiply(uint32_t instruction, machine_type machine){
    machine.decodedInstruction->A = instruction&0x200000;
    machine.decodedInstruction->S = instruction&0x100000;
    machine.decodedInstruction->Rn = getBitRange(instruction, 12, 4);
    machine.decodedInstruction->Rd = getBitRange(instruction, 16, 4);
    machine.decodedInstruction->Rs = getBitRange(instruction, 8, 4);
    machine.decodedInstruction->Rm = getBitRange(instruction, 0, 4);
}

