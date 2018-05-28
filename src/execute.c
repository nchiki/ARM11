
#include <stdlib.h>
#include <stdio.h>
#include "memoryImplementation.h"
#include "instruction.h"
#include <execute.h>
#include "decode.c"
#include "usefulTools.h"

int checkCondition(machine_type *machine) {
    //checking whether the condition set in the cond field of the instruction correspond to the flags of the CPSR

    int cpsrFlags = machine->registers[CPSR] >> 28; //getting the four last bits of the CPSR

    switch(machine->decodedInstruction->cond) {

        case EQ:
            return cpsrFlags&Z_MASK; // equal
        case NE:
            return !cpsrFlags&Z_MASK; //not equal
        case GE:
            return (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) >> 3); //greater or equal
        case LT:
            return (cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) >> 3); //less than
        case GT:
            return (!(cpsrFlags&Z_MASK) & (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) >> 3)); // greater than
        case LE:
            return (cpsrFlags&Z_MASK) & (cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) >> 3); //less than or equal
        case AL:
            return 1; //always
    }


}
//here we need something that distinguish between the different instructions, and applies the code that each of us
//implemented before to execute it depending on the instruction
int execute(machine_type *machine) {
    if (checkCondition(machine)) {
        switch (machine->decodedInstruction->type) {
            case Halt:
                execute_Halt(machine);
                break;
            case None:
              //  goto next;
                break;
            case DProc:
                //execute code for data processing
                break;
            case SDT:
                //execute code for single data transfer
                break;
            case Mult:
                execute_MulI(machine);
                break;
            case Branch:
                //execute code for branch
                break;
            default:
                fprintf(stderr, "invalid instruction");
                return EXIT_FAILURE;
        }

        //moves to next instruction, NOT NEEDED
      //  next: machine->registers[PC] += 4;

    }
}

void execute_MulI(machine_type *machine){
    //simple multiplication
    uint32_t result = machine->registers[getBitRange(machine->decodedInstruction,0,3)] *
            machine->registers[getBitRange(machine->decodedInstruction,8,3)];

    //if A is set, then add accumulator
    if(getBitRange(machine->decodedInstruction,21,1)){
        result += machine->registers[getBitRange(machine->decodedInstruction,12,3)];
    }

    //if S is set, update CPSR flag
    if(getBitRange(machine->decodedInstruction,20,1)){
        //N will be updated to the last bit of the result, rest of CPSR stays the same
        machine->registers[CPSR] = (getBitRange(result, 31, 1) << 31) | getBitRange(machine->registers[CPSR],0,31);

        //if result is zero, Z bit is set and the rest of CPSR stays the same
        if(result == 0){
            machine->registers[CPSR] = Z_MASK_32 | machine->registers[CPSR];
        }
    }



}

void execute_Halt(machine_type *machine){
    //printing the value of each register to standard output
    for(int i = 0; i < 17; i++){
        printBits(machine->registers[i]);
    }

    //prints all non-zero memory locations
    for(int i = 0; i < 16384; i++){
        if(!(machine->memoryAlloc[i] == 0)){
            printBits(machine->memoryAlloc[i]);
        }
    }
}

void execute_branch(machine_type *machine){
    //24-bit long offset turned into 32-bit long offset
    int32_t offset = getBitRange(machine->decodedInstruction, 0, 24) | 0x000000;
    machine->instructionFetched = false;
    machine->registers[PC] = signedtwos_to_unsigned(offset);
}

void execute_SDT(machine_type *machine){
    //not implemented yet
}

void execute_DPI(machine_type *machine){
    //not implemented yet
}

//prints bit sequence of register
void printBits(uint32_t reg) {
    int i;
    uint32_t mask = 1 << 31;
    for(i=0; i<32; ++i) {
        if((reg & mask) == 0){
            printf("0");
        }
        else {
            printf("1");
        }
        reg = reg << 1;
    }
    printf("\n");
}

//checks for negative value and turns offset into positive binary
uint32_t signedtwos_to_unsigned(int32_t signednum){
    if(signednum >> 31){
        signednum = (~signednum) + 1;
        signednum *= -1;
    }
    return signednum;
}






//

