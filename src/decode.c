#include "decode.h"


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



