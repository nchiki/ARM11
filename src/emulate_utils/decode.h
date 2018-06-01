#ifndef ARM11_28_DECODE_H
#define ARM11_28_DECODE_H

//interface for alltructions

#include "instruction_basic.h"
#include "../usefulTools.h"
#include "../memoryImplementation.h"
#include "../emulate_utils/instructions/branch.h"
#include "../emulate_utils/instructions/singleDT.h"
#include "../emulate_utils/instructions/multiply.h"
#include "../emulate_utils/instructions/DataProcDec.h"
#include "../emulate_utils/instructions/halt.h"

//This part receives the instructions fetched and has to
// distinguish between the different instructions save the
// value of the different parts they have (Rn, Rs, <offset etc) for
// each of the instructions, and save it as the decoded intruction


void decode(MACHINE *machine);

#endif //ARM11_28_DECODE_H