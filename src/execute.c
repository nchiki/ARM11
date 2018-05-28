
#include <stdlib.h>
#include <stdio.h>
#include "memoryImplementation.h"
#include "instruction.h"
#include <execute.h>
#include "decode.c"

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
                goto next;
                break;
            case DProc:
                //execute code for data processing
                break;
            case SDT:
                //execute code for single data transfer
                break;
            case Mult:
                //execute code for multiply
                break;
            case Branch:
                //execute code for branch
                break;
            default:
                fprintf(stderr, "invalid instruction");
                return EXIT_FAILURE;
        }

        //moves to next instruction
        next: machine->registers[PC] += 4;

    }
}

void execute_MulI(){

    //still needs to be implemented

}

//still have to add printing every non zero memory location
void execute_Halt(machine_type *machine){
    //printing the value of each register to standard output
    for(int i = 0; i < 17; i++){
        printBits(machine->registers[i]);
    }
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






//

