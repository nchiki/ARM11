//
// Created by gp2617 on 30/05/18.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "../memoryImplementation.h"

void halt(MACHINE *machine) {
    machine->c.decodedInstruction->binary = 0;
    machine->c.decodedInstruction->type = Halt;
}
