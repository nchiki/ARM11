//
// Created by Blanca Tebar on 26/05/2018.

#include <stdlib.h>
#include <stdio.h>
#include "memoryImplementation.h"
#include "instruction.h"
#include <execute.h>

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
                break;
            case None:
                //simply waiting for the next instruction?
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
    }
}


//

