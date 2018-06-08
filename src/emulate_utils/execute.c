#include <byteswap.h>
#include "execute.h"
#include "../memoryImplementation.h"


int checkCondition(MACHINE *machine) { //checked
    //checking whether the condition set in the cond field of the instructions correspond to the flags of the CPSR

    int cpsrFlags = machine->c.registers[CPSR] >> 28; //getting the four last bits of the CPSR

    switch(machine->c.decodedInstruction->cond) {
        case 0b0000:
            return cpsrFlags&Z_MASK; // equal
        case 0b0001:
            return !(cpsrFlags&Z_MASK); //not equal
        case 0b1010:
            return (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) >> 3); //greater or equal
        case 0b1011:
            return ((cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) >> 3)); //less than
        case 0b1100:
            return (!(cpsrFlags&Z_MASK) && (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) << 3)); // greater than
        case 0b1101:
            return (cpsrFlags&Z_MASK) || ((cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) << 3)); //less than or equal
        case 0b1110 :
            return 1; //always
        default:
            exitProgr(machine);
            return 0;
    }


}
//here we need something that distinguish between the different instructions, and applies the code that each of us
//implemented before to execute it depending on the instructions

void execute_MulI(MACHINE *machine){ //checked
    //simple multiplication

    uint32_t result = machine->c.registers[machine->c.decodedInstruction->Rm] *
            machine->c.registers[machine->c.decodedInstruction->Rs];

    //if A is set, then add accumulator
    if(machine->c.decodedInstruction->A){
        result += machine->c.registers[machine->c.decodedInstruction->Rn];
    }

    //if S is set, update CPSR flag
    if(machine->c.decodedInstruction->S){

        //N will be updated to the last bit of the result, rest of CPSR stays the same

        machine->c.registers[CPSR] = (getBitRange(result, 31, 1) | getBitRange(machine->c.registers[CPSR],0,31));

        //if result is zero, Z bit is set and the rest of CPSR stays the same
        if(result == 0){
            machine->c.registers[CPSR] = Z_MASK_32 | machine->c.registers[CPSR];
        }
    }
}


void execute_Halt(MACHINE *machine){ //not 100% sure
    //printing the value of each register to standard output
    printf("Registers:\n");
    for(int i = 0; i < 17; i++){
      if (i != 13 && i != 14) {
        if (i == 15){
          printf("PC   :");
        } else if(i == 16){
          printf("CPSR  :");
        } else if {
        printf("$%d  :", i);
        }
        printBitsofReg(machine->c.registers[i]);
      }
    }
    printf("Non-zero memory:\n");
    for(int i = 0; i < 16384; i++){
        if(machine->mem.memoryAlloc[i] != 0){
        printf("%08x: ", i*4);
        printBitsofMem(machine->mem.memoryAlloc[i]);
      }
    }
    exitProgr(machine);
}

void execute_branch(MACHINE *machine){ //checked

    int32_t offset = machine->c.decodedInstruction->offset;
    machine->c.registers[PC] += signedtwos_to_unsigned(offset);
}

//prints bit sequence of register
void printBitsofReg(uint32_t reg) { //checked
    int valueInDec = binToDec(reg); // this is gonna be the decimal value of the binary value
    valueInDecflipped = bswap_32(valueInDec); //swapping bits
    printf("%d (%#0-8x) \n", valueInDec, valueInDecflipped);
  }
void printBitsofMem(uint32_t memAlloc) { //checked
      int valueInDec = binToDec(memAlloc); // this is gonna be the decimal value of the binary value
      valueInDecflipped = bswap_32(valueInDec); //swapping bits
      printf("%#08x \n", valueInDecflipped);
}


//checks for negative value and turns offset into positive binary
uint32_t signedtwos_to_unsigned(int32_t signednum){ //checked
    if(signednum >> 31){
        signednum = (~signednum) + 1;
        signednum *= -1;
    }
    return (uint32_t) signednum;
}
//need commenting ----------------------------------
// operand are the 12 last bits of the instruction (although it is passed as an uin32_t)
uint32_t shiftReg(uint32_t operand, MACHINE *machine) { //blanca should check this
    int amount; //the number of positions to be shifted
    int32_t mask2; // mask that we are gonna use later
    if (operand&0x10 != 0) {  //checks if it's shifted by constant amount or by the amount stored in Rs
        amount = getBitRange(machine->c.registers[getBitRange(operand, 8, 4)], 0, 8); // amount stored in las byte of Rs
    } else {
        amount = getBitRange(operand, 7, 5); // takes the five bits from bit 7 as a constant value
    }
    switch(getBitRange(operand, 4, 2)) { // bits that determine the type of shift
        case 00: //logical shift left
            machine->c.decodedInstruction->shift = LSL; //sets the type of switch
            if (machine->c.decodedInstruction->S) { //if S is set then carry flag changes
                int32_t mask = 1 << (32 - amount); // mask to get the LSB in the original value we are gonna shift later
                machine->c.registers[CPSR] &= 0xDFFFFFFF; // mask that sets to zero the carry bit so we can set it later
                mask2 = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29; //takes the bit we need (for setting C in CPSR) and shifts it to its correct position in CPSR
                machine->c.registers[CPSR] |= mask2; //ors, to set the CPSR C bit
            }
            (machine->c.registers[machine->c.decodedInstruction->Rm]) <<= amount; //shifts
            break;
        case 01: //logical shift right
            machine->c.decodedInstruction->shift = LSR;//sets the type of switch
            if (machine->c.decodedInstruction->S) { //if S is set then carry flag changes
                int32_t mask = 1 << (amount); // mask to get the LSB in the original value we are gonna shift later
                machine->c.registers[CPSR] &= 0xDFFFFFFF; // mask that sets to zero the carry bit so we can set it later
                mask2 = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29; //takes the bit we need (for setting C in CPSR) and shifts it to its correct position in CPSR
                machine->c.registers[CPSR] |= mask2; //ors, to set the CPSR C bit

            }
            (machine->c.registers[machine->c.decodedInstruction->Rm]) >>= amount;
            break;
        case 10: //arithmetic shift right
            machine->c.decodedInstruction->shift = ASR; //type of shift
            if (machine->c.decodedInstruction->S) { //checks if S flag is set so CPSR would be altered
                int32_t mask = 1 << (amount);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask2 = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29;
                machine->c.registers[CPSR] |= mask2;
            }
            char signBit = (machine->c.registers[machine->c.decodedInstruction->Rm] &800000000) >> 31; //takes bit 31
            uint32_t maskASR = 0;
            for (int i = 0; i < amount; i++) {
                maskASR |= signBit << (31-i); //creates a mask for the bits on the left with the value of signbit
            }
            //shifts it to the right and then sets the bits on the left with signBit
            (machine->c.registers[machine->c.decodedInstruction->Rm]) = ((machine->c.registers[machine->c.decodedInstruction->Rm])>> amount) | maskASR;
            break;
        case 11: // rotate shift right
            machine->c.decodedInstruction->shift = ASR;
            if (machine->c.decodedInstruction->S) {
                int32_t mask = 1 << (amount);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask2 = (machine->c.registers[machine->c.decodedInstruction->Rm] & mask) << 29;
                machine->c.registers[CPSR] |= mask2;
            }
            uint32_t maskRotate = 0;
            for (int i = 0; i < amount; i++) {
                maskRotate |= 1 << i;// creates a mask to get the last (amount) bits of the value
            }
            maskRotate <<= 27; //shifts the value because it going to be the right bits of the shifted value
            (machine->c.registers[machine->c.decodedInstruction->Rm]) =
                    ((machine->c.registers[machine->c.decodedInstruction->Rm])>> amount) | maskRotate;
            break;
        default: break;
    }
    return machine->c.registers[machine->c.decodedInstruction->Rm];
}



//rotates with right shifts and takes number of rotations as parameter
uint32_t rotate(uint32_t operand, int numberRot){
    int num = binToDec(numberRot);  //number of rotations
    for(int i = 0; i < num; i++){
        int firstBit = getBitRange(operand, 0, 1);
        operand = (firstBit << 31) | (operand >> 1);
    }
    return operand;
}

int binToDec(int n) //checked
{
    int number = 0;
    int i = 0;
    int remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        number += remainder*(1 << i);
        ++i;
    }
    return number;
}

void execute_SDT(MACHINE *machine) {
    //if ((machine->c.decodedInstruction->Rn == PC) && ((machine->c.decodedInstruction) != (machine->c.registers[PC] - 8))){
    if ((machine->c.decodedInstruction->Rn == PC) && (machine->c.decodedInstruction->binary) != machine->c.registers[PC] - 8 ){
        fprintf(stderr, "PC doesn't contain the correct instructions");
        exit(EXIT_FAILURE);
    }
    uint32_t offsetValue;
    if (machine->c.decodedInstruction->I) {
        /*uint8_t shift = (uint8_t) ((getBitRange(machine->c.decodedInstruction->operand2, 4, 8)) >> 4);
        uint32_t shifterReg = getBitRange(machine->c.decodedInstruction->operand2, 0, 4);*/

        int shifterReg = getBitRange(machine->c.decodedInstruction->binary, 0, 4);

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


void execute_DPI(MACHINE *machine){
    instructions *instr = machine->c.decodedInstruction;
    uint32_t result;
    bool carry = 0;
    uint32_t flag = 0;
    uint32_t op2;
    int32_t RN = machine->c.registers[instr->Rn];

    if(instr->Rn){
        op2 = instr->operand2 | 0x00000000;
        int numberRot = getBitRange(instr->binary, 8, 4) << 1;
        op2 = rotate(op2, numberRot);
    }
    else{
        op2 = shiftReg(instr->operand2, machine);
        carry = instr->carry;
    }

    switch(machine->c.decodedInstruction->opcode) {
        case AND:
        case TST:
            result = RN & op2;
            flag = carry * C_MASK;
                    break;
        case EOR:
        case TEQ:
            result = RN ^ op2;
            flag = carry * C_MASK;
            break;
        case SUB:
        case CMP:
            result = RN + ((~op2) + 1);
            flag = C_MASK * ((RN >> 31) == (op2 >> 31) != (result >> 31));
                    break;
        case RSB: result = op2 + ((~RN) +1);
            flag = C_MASK * ((RN >> 31) == (op2 >> 31) != (result >> 31));
                break;
        case ADD: result = RN + op2;
            flag = C_MASK * ((RN >> 31) == (op2 >> 31) != (result >> 31));
                break;
        case ORR: result = RN | op2;
            flag = carry * C_MASK;
                break;
        case MOV: result = op2;
            flag = carry * C_MASK;
                break;
        default: result = 0;
        exitProgr(machine);
        break;
    }

    //if one of these instructions, result is not written
    if(instr->opcode == TST || instr->opcode == TEQ || instr->opcode == CMP) {
        machine->c.registers[machine->c.decodedInstruction->Rd] = result;
    }

    //if S flag is set, CPSR flags have to be set in the following way
    if (instr->S){
        //if result is all zeros, Z bit will be set
        if(result == 0){
            machine->c.registers[CPSR] |= Z_MASK_32;
        }
        //N bit will be set to bit 31 of result
        machine->c.registers[CPSR] |= (result >> 31);
        //flag C is set to flag value but shifted to right position
        machine->c.registers[CPSR] |= (flag << 29);
    }
}
    

 /*         case AND:
        case TST: result = RN & instr->operand2;
            flag = (machine->c.registers[CPSR] >> 29) && C_MASK;
            break;
        case EOR:
        case TEQ: result = RN ^ instr->operand2;
            flag = (machine->c.registers[CPSR] >> 29) && C_MASK;
            break;
        case SUB:
        case CMP: result = RN + ((~(instr->operand2)) + 1);
            if(((!(RN) && (instr->operand2) || ((machine->c.registers[CPSR] >> 29) & C_MASK))) ||
               (instr->operand2 && ((machine->c.registers[CPSR] >> 29) & C_MASK))){
                flag = 1;
            }
            break;
        case RSB: result = instr->operand2 - RN;
            if((((machine->c.registers[CPSR] >> 29) & C_MASK) && (RN >> 31 || (instr->operand2) >> 31))
               || (RN >> 31 && (instr->operand2) >> 31)){
                flag = 1;
            }
            break;
        case ADD: result = RN + instr->operand2;
            if((((machine->c.registers[CPSR] >> 29) & C_MASK) && (RN >> 31 || (instr->operand2) >> 31))
               || (RN >> 31 && (instr->operand2) >> 31)){
                flag = 1;
            }
            break;
        case ORR: result = RN | instr->operand2;
            break;
        case MOV: result = instr->operand2;
            flag = ((machine->c.registers[CPSR] >> 29) & C_MASK) >> 29;
            break;
        default: break;
    }

//if one of these instructions, result is not written
    if(instr->opcode == TST || instr->opcode == TEQ || instr->opcode == CMP) {
        machine->c.registers[machine->c.decodedInstruction->Rd] = result;
    }

    //if S flag is set, CPSR flags have to be set in the following way
    if (instr->S){
        //if result is all zeros, Z bit will be set
        if(result == 0){
            machine->c.registers[CPSR] |= Z_MASK_32;
        }
        //N bit will be set to bit 31 of result
        uint32_t nvalue = result >> 31;
        machine->c.registers[CPSR] |= nvalue;
        //flag C is set to flag value but shifted to right position
        uint32_t flagC = (uint32_t) flag << 29;
        machine->c.registers[CPSR] |= flagC;
    } */
}

void execute(MACHINE *machine) {
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
                fprintf(stderr, "invalid instructions");
        }

    }
}
