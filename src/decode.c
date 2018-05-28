
//interface for all isntructions

#include "instruction.h"
#include "usefulTools.h"
#include "memoryImplementation.h"
#include "instructions/branch.c"
#include "instructions/singleDT.c"
#include "instructions/multiply.c"
#include "instructions/DataProcDec.c"

//This part receives the instruction fetched and has to
// distinguish between the different instructions save the
// value of the different parts they have (Rn, Rs, <offset etc) for
// each of the instruction, and save it as the decoded intruction

void decode(machine_type machine){
    if((machine.fetchedInstruction&Branch_MASK)>>3){
        branch(machine.fetchedInstruction);
    } else if (machine.fetchedInstruction&SDT_MASK>>2){
        STDdecode(machine.fetchedInstruction);
    } else if (((machine.fetchedInstruction&Multiply_MASK1)==0)||(machine.fetchedInstruction&Multiply_MASK2)==0) {
        multiply(machine.fetchedInstruction);
    } else{
        decodeDATPROC(machine.fetchedInstruction);

}

}

//extracts any number of bits from any starting index
//start won't be included
uint32_t getBitRange(uint32_t num, int start, int length){
    uint32_t res = 0;
    for(int i = start; i < start + length; i++){
        res += (1 << i) & num;
    }
    return res >> start;
}
