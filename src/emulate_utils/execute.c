#include "execute.h"

//declaration of the methods
void printBitsofMem(uint32_t memAlloc);
void printBitsofReg(int32_t reg, bool isPC);

int checkCondition(MACHINE *machine) { //checked
    //checking whether the condition set in the cond field of the instructions correspond to the flags of the CPSR

    int cpsrFlags = machine->c.registers[CPSR] >> 28; //getting the four last bits of the CPSR

    switch(machine->c.decodedInstruction->cond) {
        case 0:
            return cpsrFlags&Z_MASK; // equal
        case 1:
            return !(cpsrFlags&Z_MASK); //not equal
        case 10:
            return (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) >> 3); //greater or equal
        case 11:
            return ((cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) >> 3)); //less than
        case 12:
            return (!(cpsrFlags&Z_MASK) && (cpsrFlags&N_MASK) == ((cpsrFlags&V_MASK) << 3)); // greater than
        case 13:
            return (cpsrFlags&Z_MASK) || ((cpsrFlags&N_MASK) != ((cpsrFlags&V_MASK) << 3)); //less than or equal
        case 14:
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

    uint32_t result = machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)] *
            machine->c.registers[binToDec(machine->c.decodedInstruction->Rs)];

    //if A is set, then add accumulator
    if(machine->c.decodedInstruction->A){
        result += machine->c.registers[binToDec(machine->c.decodedInstruction->Rn)];
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
    bool isPC = false;
    for(int i = 0; i < 17; i++){
      if (!(i == 13 || i == 14)) {
        if (i == 15){
          printf("PC  :");
          isPC = true;
        } else if(i == 16){
          printf("CPSR:");
        } else {
        printf("$%-3i:", i);
        }
        printBitsofReg(machine->c.registers[i], isPC);
      }
    }
    printf("Non-zero memory:\n");
    for(int i = 0; i < 16384; i++){
      if(machine->mem.memoryAlloc[i] != 0){
        printf("0x%08x: ", i*4);
        printBitsofMem(machine->mem.memoryAlloc[i]);
      }
    }
    // exitProgr(machine);
}

void execute_branch(MACHINE *machine){ //checked

    int32_t offset = machine->c.decodedInstruction->offset;
    machine->c.registers[PC] += signedtwos_to_unsigned(offset);
}

//prints bit sequence of register
void printBitsofReg(int32_t reg, bool isPC) { //checked
    int32_t valueInDec = binToDec(reg); // this is gonna be the decimal value of the binary value
    //int32_t valueInDecflipped = bswap_32(valueInDec); //swapping bits
    //uint32_t valueInDecflipped = bswap_32(reg);
    if (isPC) {
      printf("% 11d (0x%08x)\n", valueInDec*4, reg*4); //4-byte addressable
    } else if (valueInDec < 0) { // if the number is ngative we need more space
      printf("% 12d (0x%08x)\n", valueInDec, reg);
    } else {
    printf("% 11d (0x%08x)\n", valueInDec, reg);
    }
}

void printBitsofMem(uint32_t memAlloc) { //checked
      //int valueInDec = binToDec(memAlloc); // this is gonna be the decimal value of the binary value
      //int valueInDecflipped = bswap_32(valueInDec); //swapping bits
      uint32_t mem = bswap_32(memAlloc);
      printf("0x%08x\n", mem);
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
    if ((operand & 0x10) != 0) {  //checks if it's shifted by constant amount or by the amount stored in Rs
        amount = getBitRange(machine->c.registers[binToDec(getBitRange(operand, 8, 4))], 0, 8); // amount stored in las byte of Rs
    } else {
        amount = getBitRange(operand, 7, 5); // takes the five bits from bit 7 as a constant value
    }
    switch(getBitRange(operand, 4, 2)) { // bits that determine the type of shift
        case 00: //logical shift left
            machine->c.decodedInstruction->shift = LSL; //sets the type of switch
            if (machine->c.decodedInstruction->S) { //if S is set then carry flag changes
                int32_t mask = 1 << (32 - amount); // mask to get the LSB in the original value we are gonna shift later
                machine->c.registers[CPSR] &= 0xDFFFFFFF; // mask that sets to zero the carry bit so we can set it later
                mask2 = (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)] & mask) << 29; //takes the bit we need (for setting C in CPSR) and shifts it to its correct position in CPSR
                machine->c.registers[CPSR] |= mask2; //ors, to set the CPSR C bit
            }
            (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)]) <<= amount; //shifts
            break;
        case 01: //logical shift right
            machine->c.decodedInstruction->shift = LSR;//sets the type of switch
            if (machine->c.decodedInstruction->S) { //if S is set then carry flag changes
                int32_t mask = 1 << (amount); // mask to get the LSB in the original value we are gonna shift later
                machine->c.registers[CPSR] &= 0xDFFFFFFF; // mask that sets to zero the carry bit so we can set it later
                mask2 = (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)] & mask) << 29; //takes the bit we need (for setting C in CPSR) and shifts it to its correct position in CPSR
                machine->c.registers[CPSR] |= mask2; //ors, to set the CPSR C bit

            }
            (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)]) >>= amount;
            break;
        case 10: //arithmetic shift right
            machine->c.decodedInstruction->shift = ASR; //type of shift
            if (machine->c.decodedInstruction->S) { //checks if S flag is set so CPSR would be altered
                int32_t mask = 1 << (amount);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask2 = (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)] & mask) << 29;
                machine->c.registers[CPSR] |= mask2;
            }
            char signBit = (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)] &800000000) >> 31; //takes bit 31
            uint32_t maskASR = 0;
            for (int i = 0; i < amount; i++) {
                maskASR |= signBit << (31-i); //creates a mask for the bits on the left with the value of signbit
            }
            //shifts it to the right and then sets the bits on the left with signBit
            (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)]) =
              ((machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)])>> amount) | maskASR;
            break;
        case 11: // rotate shift right
            machine->c.decodedInstruction->shift = ASR;
            if (machine->c.decodedInstruction->S) {
                int32_t mask = 1 << (amount);
                machine->c.registers[CPSR] &= 0xDFFFFFFF;
                mask2 = (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)] & mask) << 29;
                machine->c.registers[CPSR] |= mask2;
            }
            uint32_t maskRotate = 0;
            for (int i = 0; i < amount; i++) {
                maskRotate |= 1 << i;// creates a mask to get the last (amount) bits of the value
            }
            maskRotate <<= 27; //shifts the value because it going to be the right bits of the shifted value
            (machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)]) =
                    ((machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)])>> amount) | maskRotate;
            break;
        default: break;
    }
    return machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)];
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
    //we must ensure that if Rn is the PC it contains the instruction's address +8 bits bc of the pipeline
    if ((machine->c.decodedInstruction->Rn == PC) && (machine->c.decodedInstruction->binary) != machine->c.registers[PC] - 8 ){
        fprintf(stderr, "PC doesn't contain the correct instructions");
        exit(EXIT_FAILURE);
    }
    int32_t offsetValue; //declaring the value of the offset
    if (machine->c.decodedInstruction->I) { //if I set then the offset is a shifted reg
        //taking the bin code of the register (NOT ITS VALUE)
        int shifterReg = getBitRange(machine->c.decodedInstruction->binary, 0, 4);
        //Rm is the register which holds the value that is gonna be shifted
        machine->c.decodedInstruction->Rm = shifterReg;
        //shiftReg shifts the value in held in Rm
        shiftReg(machine->c.decodedInstruction->offset & 0xFFF, machine);
        //sets the offsetValue to the value that has been just shifted
        offsetValue = machine->c.registers[binToDec(machine->c.decodedInstruction->Rm)];
    } else { //immediate offset (12 bits)
        offsetValue = (machine->c.decodedInstruction->offset) & 0xFFF;
    }
    uint32_t newAddress; //address where to store/load the value
    if (machine->c.decodedInstruction->U) { //U set then the values of base
                                            //register and offset are added
        newAddress = machine->c.registers[binToDec(machine->c.decodedInstruction->Rn)] +
                     offsetValue;
    } else { //subtraction
        newAddress = machine->c.registers[binToDec(machine->c.decodedInstruction->Rn)] -
                     offsetValue;
    }
    if (machine->c.decodedInstruction->L) { //L set the load, otherwise store
        if (machine->c.decodedInstruction->P) { // P set then pre-indexing
            //stores the value of mem[address] in Rd
            machine->c.registers[binToDec(machine->c.decodedInstruction->Rd)] = machine->mem.memoryAlloc[binToDec(newAddress)];
        } else { //Post-indexing (after transferring the data)
            machine->c.registers[binToDec(machine->c.decodedInstruction->Rd)] = machine->mem.memoryAlloc[binToDec(offsetValue)];
            machine->c.registers[binToDec(machine->c.decodedInstruction->Rn)] = newAddress;
        }
    } else {
        if (machine->c.decodedInstruction->P) {
            machine->mem.memoryAlloc[binToDec(newAddress)] = machine->c.registers[binToDec(machine->c.decodedInstruction->Rd)];
        } else {
            //first loads from the address held in Rn
            machine->c.registers[binToDec(machine->c.decodedInstruction->Rd)] =
              machine->mem.memoryAlloc[binToDec(machine->c.decodedInstruction->Rn)];
            //changes the value of Rn by offset
            machine->c.registers[binToDec(machine->c.decodedInstruction->Rn)] = newAddress;
        }

    }

}



void execute_DPI(MACHINE *machine){
    instructions *instr = machine->c.decodedInstruction;
    uint32_t result;
    bool carry = 0;
    uint32_t flag = 0;
    uint32_t op2;
    int32_t RN = machine->c.registers[binToDec(instr->Rn)];

    if(instr->I){
        op2 = instr->operand2 | 0x00000000;
        int numberRot = getBitRange(instr->binary, 8, 4) << 1;
        op2 = rotate(op2, numberRot);
    }
    else{
        op2 = shiftReg(instr->operand2, machine);
        carry = instr->carry;
    }

    switch(machine->c.decodedInstruction->opcode) {
        case 0:
        case 8:
            result = RN & op2;
            flag = carry * C_MASK;
                    break;
        case 1:
        case 9:
            result = RN ^ op2;
            flag = carry * C_MASK;
            break;
        case 2:
        case 10:
            result = RN + ((~op2) + 1);
            flag = C_MASK * ((RN >> 31) == (op2 >> 31) != (result >> 31));
                    break;
        case 3: result = op2 + ((~RN) +1);
            flag = C_MASK * ((RN >> 31) == (op2 >> 31) != (result >> 31));
                break;
        case 4: result = RN + op2;
            flag = C_MASK * ((RN >> 31) == (op2 >> 31) != (result >> 31));
                break;
        case 12: result = RN | op2;
            flag = carry * C_MASK;
                break;
        case 13: result = op2;
            flag = carry * C_MASK;
                break;
        default: result = 0;
        exitProgr(machine);
        break;
    }

    //if one of these instructions, result is not written
    if(!(instr->opcode == TST || instr->opcode == TEQ || instr->opcode == CMP)) {
        machine->c.registers[binToDec(machine->c.decodedInstruction->Rd)] = result;
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
