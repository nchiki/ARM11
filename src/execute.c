
#include <stdlib.h>
#include <stdio.h>
#include "memoryImplementation.h"
#include "instruction.h"
#include <execute.h>
#include "decode.c"


int checkCondition(MACHINE *machine) {
    //checking whether the condition set in the cond field of the instruction correspond to the flags of the CPSR

    int cpsrFlags = machine->c.registers[CPSR] >> 28; //getting the four last bits of the CPSR

    switch(machine->c.decodedInstruction->cond) {
        case EQ:
            return cpsrFlags&Z_MASK; // equal
        case NE:
            return !cpsrFlags&Z_MASK; //not equal
        case GE:
            return (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) >> 3); //greater or equal
        case LT:
            return (cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) >> 3); //less than
        case GT:
            return (!(cpsrFlags&Z_MASK) && (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) << 3)); // greater than
        case LE:
            return (cpsrFlags&Z_MASK) || ((cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) << 3)); //less than or equal
        case AL:
            return 1; //always
        default:
            return 0;
    }


}
//here we need something that distinguish between the different instructions, and applies the code that each of us
//implemented before to execute it depending on the instruction
void execute(MACHINE *machine) {
    // just a useless comment
    if (checkCondition(machine)) {
        switch (machine->c.decodedInstruction->type) {
            case Halt:
                execute_Halt(machine);
                break;
            case DProc:
                execute_DPI(machine);
                break;
            case SDT:
                execute_SDT(machine);
                break;
            case Mult:
                execute_MulI(machine);
                break;
            case Branch:
                execute_branch(machine);
                break;
            default:
                fprintf(stderr, "invalid instruction");
        }

    }
}

void execute_MulI(MACHINE *machine){
    //simple multiplication
    uint32_t result = machine->c.registers[getBitRange(machine->c.decodedInstruction,0,4)] *
            machine->c.registers[getBitRange(machine->c.decodedInstruction,8,4)];

    //if A is set, then add accumulator
    if(getBitRange(machine->c.decodedInstruction,21,1)){
        result += machine->c.registers[getBitRange(machine->c.decodedInstruction,12,4)];
    }

    //if S is set, update CPSR flag
    if(getBitRange(machine->c.decodedInstruction,20,1)){
        //N will be updated to the last bit of the result, rest of CPSR stays the same

        machine->c.registers[CPSR] = (getBitRange(result, 31, 1) << 31) | getBitRange(machine->c.registers[CPSR],0,31);

        //if result is zero, Z bit is set and the rest of CPSR stays the same
        if(result == 0){
            machine->c.registers[CPSR] = Z_MASK_32 | machine->c.registers[CPSR];
        }
    }



}

void execute_Halt(MACHINE *machine){
    //printing the value of each register to standard output
    for(int i = 0; i < 17; i++){
        printBits(machine->c.registers[i]);
    }
}

void execute_branch(MACHINE *machine){
    int32_t offset = getBitRange(machine->c.decodedInstruction, 0, 24) | 0x000000;
    machine->c.registers[PC] = signedtwos_to_unsigned(offset);
}



void execute_SDT(MACHINE *machine) {
    if ((machine->c.decodedInstruction->Rn == PC) && &(machine->c.decodedInstruction) != machine->c.registers[PC] - 8 ){
        fprintf(stderr, "PC doesn't contain the correct instruction");
        exit(EXIT_FAILURE);
    }
    uint32_t offsetValue;
    if (machine->c.decodedInstruction->I) {
        uint8_t shift = getBitRange(machine->c.decodedInstruction, 4, 8);
        int shifterReg = getBitRange(machine->c.decodedInstruction, 0, 4);
        machine->c.decodedInstruction->Rm = shifterReg;
        shiftReg(machine->c.decodedInstruction->offset & 0xFFF, machine);
        offsetValue = machine->c.registers[machine->c.decodedInstruction->Rm];
    } else {
        offsetValue = (machine->c.decodedInstruction->offset) & 0xFFF;
    }
    uint32_t newAddress;
    if (machine->c.decodedInstruction->U) {
        newAddress = machine->c.registers[machine->c.decodedInstruction->Rn] +
                     offsetValue;
    } else {
        newAddress = machine->c.registers[machine->c.decodedInstruction->Rn] -
                     offsetValue;
    }
    if (machine->c.decodedInstruction->L) {
        if (machine->c.decodedInstruction->P) {
            machine->c.registers[machine->c.decodedInstruction->Rd] = machine->mem.memoryAlloc[newAddress];
        } else {
            machine->c.registers[machine->c.decodedInstruction->Rd] = machine->mem.memoryAlloc[offsetValue];
            machine->c.registers[machine->c.decodedInstruction->Rn] = newAddress;
        }
    } else {
        if (machine->c.decodedInstruction->P) {
            machine->mem.memoryAlloc[newAddress] = machine->c.registers[machine->c.decodedInstruction->Rd];
        } else {
            machine->c.registers[machine->c.decodedInstruction->Rd] = machine->mem.memoryAlloc[offsetValue];
            machine->c.registers[machine->c.decodedInstruction->Rn] = newAddress;
        }

    }

}




//flags still need to be added
void execute_DPI(MACHINE *machine){
    instruction *instr = machine->c.decodedInstruction;
    uint32_t result;

    if(instr->I){
        //value is zero-extended to 32 bits
        uint32_t operand = instr->operand2 | 0x00000000;
        //rotated times the number specified in bit 8 to 11
        int numberRot = getBitRange(instr, 8, 4) * 0x2;
        instr->operand2 = rotate(operand,numberRot);
    } else{
        uint16_t operand = shiftReg(instr->operand2, machine);
        instr->operand2 = operand;
    }

    //carry-out bit
    bool flag = 0;
    //opcode is checked and saved in local variable result
            //flags needed
    switch(machine->c.decodedInstruction->opcode){
        case AND:
        case TST: result = instr->Rn && instr->operand2;
        break;
        case EOR:
        case TEQ: result = instr->Rn ^ instr->operand2;
        break;
        case SUB:
        case CMP: result = instr->Rn - instr->operand2;
        break;
        case RSB: result = instr->operand2 - instr->Rn;
        break;
        case ADD: result = instr->Rn + instr->operand2;
        break;
        case ORR: result = instr->Rn || instr->operand2;
        case MOV: result = instr->operand2;
    }

//if one of these instructions, result is not written
    if(instr->opcode == TST || instr->opcode == TEQ || instr->opcode == CMP) {
        machine->c.registers[machine->c.decodedInstruction->Rd] = result;
    }

    //if S flag is set, CPSR flags have to be set in the following way
    if (instr->S){
        machine->c.registers[CPSR];

    }
    machine-


}

//prints bit sequence of register
void printBits(uint32_t reg) {
    int i;
    uint32_t mask = 1 << 31;
    for (i = 0; i < 32; ++i) {
        printf("%i", (reg & mask) != 0);
        reg <<= 1;
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
//need commenting ----------------------------------
uint16_t shiftReg(uint16_t operand, MACHINE *machine) {
    int amount;
    if (operand & 1) {
        amount = getBitRange(machine->c.registers[getBitRange(operand, 8, 4)], 0, 8);
    } else {
        amount = getBitRange(operand, 7, 5);
    }
    switch(getBitRange(operand, 4, 2)) {
        case 00: //logical shift left
            machine->c.decodedInstruction->shift = LSL;
            if (machine->c.decodedInstruction->S) {
                uint32_t mask = 1 << (32 - amount);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29;
                machine->c.registers[CPSR] |= mask;
            }
            (machine->c.registers[machine->c.decodedInstruction->Rm]) <<= amount;
            break;
        case 01: //logical shift right
            machine->c.decodedInstruction->shift = LSR;
            if (machine->c.decodedInstruction->S) {
                uint32_t mask = 1 << (amount - 1);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29;
                machine->c.registers[CPSR] |= mask;
            }
            (machine->c.registers[machine->c.decodedInstruction->Rm]) >>= amount;
            break;
        case 10: //arithmetic shift right
            machine->c.decodedInstruction->shift = ASR;
            if (machine->c.decodedInstruction->S) {
                uint32_t mask = 1 << (amount - 1);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29;
                machine->c.registers[CPSR] |= mask;
            }
            int signBit = (machine->c.registers[machine->c.decodedInstruction->Rm] &800000000) >> 31;
            uint32_t maskASR = 0;
            for (int i = 0; i < amount; i++) {
                maskASR |= signBit << (32-i);
            }
            (machine->c.registers[machine->c.decodedInstruction->Rm]) = ((machine->c.registers[machine->c.decodedInstruction->Rm])>> amount) | maskASR;
            break;
        case 11: // rotate shift right
            machine->c.decodedInstruction->shift = ASR;
            if (machine->c.decodedInstruction->S) {
                uint32_t mask = 1 << (amount - 1);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29;
                machine->c.registers[CPSR] |= mask;
            }
            uint32_t maskRotate = 0;
            for (int i = 0; i < amount; i++) {
                maskRotate |= 1 << i;
            }
            (machine->c.registers[machine->c.decodedInstruction->Rm]) =
                    ((machine->c.registers[machine->c.decodedInstruction->Rm])>> amount) | maskRotate;
            break;
    }
    return machine->c.registers[machine->c.decodedInstruction->Rm];

}



//rotates with right shifts and takes number of rotations as parameter
uint32_t rotate(uint32_t operand, int numberRot){
    int num = binToDec(numberRot);
    for(int i = 0; i < num; i++){
        int firstBit = getBitRange(operand, 0, 1);
        operand = (firstBit << 31) | (operand >> 1);
    }
    return operand;
}

int binToDec(int n)
{
    int number = 0;
    int i = 0;
    int remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        number += remainder*pow(2,i);
        ++i;
    }
    return number;
}