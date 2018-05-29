#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <memoryImplementation.h>

void branch(uint32_t instruction, machine_type machine) {
    uint32_t offset = instruction & 0xFFFFFF; //24 bit offset
    machine.decodedInstruction->offset = offset;
}

