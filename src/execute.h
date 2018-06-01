
#ifndef C_CODE_EXECUTE_H
#define C_CODE_EXECUTE_H

#include <stdlib.h>
#include <stdio.h>
#include "memoryImplementation.h"
#include "instruction_basic.h"
#include "decode.h"
#include <math.h>
#include "usefulTools.h"
#include "usefulFuncs.h"// fixed a merge conflict here

void execute(MACHINE *machine);
#endif //C_CODE_EXECUTE_H