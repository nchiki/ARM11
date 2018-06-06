
#ifndef ARM11_28_USEFULFUNCS_H
#define ARM11_28_USEFULFUNCS_H

#include <stdint.h>
#include "instruction_basic.h"


/*uint32_t getBitRange(uint32_t num, int start, int length)*/
uint32_t getBitRange(uint32_t instruction, int start, int length);

#endif //ARM11_28_USEFULFUNCS_H
