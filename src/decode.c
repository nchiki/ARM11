
//interface for alltructions

#include "instruction.h"
#include "usefulTools.h"
#include "memoryImplementation.h"
#include "instructions/branch.c"
#include "instructions/singleDT.c"
#include "instructions/multiply.c"
#include "instructions/DataProcDec.c"
#include "instructions/halt.c"

//This part receives the instruction fetched and has to
// distinguish between the different instructions save the
// value of the different parts they have (Rn, Rs, <offset etc) for
// each of the instruction, and save it as the decoded intruction

void decode(MACHINE *machine){
    if (machine->c.fetchedInstruction == 0){
        halt(machine);
    } else if((machine->c.fetchedInstruction&Branch_MASK)){
        branch(machine->c.fetchedInstruction, machine);
    } else if (machine->c.fetchedInstruction&SDT_MASK){
        SDTdecode(machine->c.fetchedInstruction, machine);
    } else if (((machine->c.fetchedInstruction&Multiply_MASK1)==0)||(machine->c.fetchedInstruction&Multiply_MASK2)==0) {
        decodeDATPROC(machine->c.fetchedInstruction, machine);
    } else {
        multiply(machine->c.fetchedInstruction, machine);
    }
    (machine->c.decodedInstruction) = machine->c.fetchedInstruction;
}


