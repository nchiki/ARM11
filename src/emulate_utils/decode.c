#include "decode.h"
#include "instructions/halt.h"
#include "instructions/branch.h"
#include "instructions/singleDT.h"
#include "instructions/DataProcDec.h"
#include "instructions/multiply.h"
#include "instruction_basic.h"


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
    (machine->c.decodedInstruction->binary) = machine->c.fetchedInstruction;

}
