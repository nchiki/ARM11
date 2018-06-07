#include "DataProcDec.h"

void decodeDATPROC(uint32_t instruction, MACHINE *machine){
    machine->c.decodedInstruction->binary = instruction;
    machine->c.decodedInstruction->type = DProc;
    machine->c.decodedInstruction->Rn = getBitRange(instruction, 16, 4);
    machine->c.decodedInstruction->Rd = getBitRange(instruction, 12, 15);
    machine->c.decodedInstruction->I = (bool)((instruction >> 25) & 1);
    machine->c.decodedInstruction->S = (bool)((instruction >> 20) & 1);
    machine->c.decodedInstruction->operand2 = getBitRange(instruction, 0, 12);
    machine->c.decodedInstruction->opcode = getBitRange(instruction, 21, 4);
    machine->c.decodedInstruction->cond = getBitRange(instruction, 28, 4);

}


