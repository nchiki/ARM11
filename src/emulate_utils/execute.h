
#ifndef C_CODE_EXECUTE_H
#define C_CODE_EXECUTE_H

#include <stdlib.h>
#include <stdio.h>
#include "../memoryImplementation.h"
#include "instruction_basic.h"
#include "decode.h"
#include <math.h>
#include "../usefulTools.h"
#include "../usefulFuncs.h"// fixed a merge conflict here

void execute(MACHINE *machine);

int checkCondition(MACHINE*);

void execute_MulI(MACHINE*);

void execute_Halt(MACHINE*);

void execute_branch(MACHINE*);

void printBits(uint32_t);

uint32_t signedtwos_to_unsigned(int32_t);

uint32_t shiftReg(uint32_t, MACHINE*);

uint32_t rotate(uint32_t , int);

int binToDec(int);

void execute_SDT(MACHINE*);

void execute_DPI(MACHINE*);

void execute(MACHINE*);


#endif //C_CODE_EXECUTE_H