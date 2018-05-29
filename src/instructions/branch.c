#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <memoryImplementation.h>

void branch(uint32_t instruction, MACHINE *machine) {
    machine->c.decodedInstruction->offset = instruction & 0xFFFFFF;     //24 bit offset
}

