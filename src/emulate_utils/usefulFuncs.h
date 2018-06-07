
#ifndef ARM11_28_USEFULFUNCS_H
#define ARM11_28_USEFULFUNCS_H

#include "instruction_basic.h"
#include "../memoryImplementation.h"

/*uint32_t getBitRange(uint32_t num, int start, int length)*/
uint32_t getBitRange(uint32_t instruction, int start, int length);
void exitProgr(MACHINE *machine);

#endif //ARM11_28_USEFULFUNCS_H
