#include "instruction_defs.h"
#include "../assemblerImplementation.h"


 MultiplyInstr_t *multiply(struct instruction instr){

    MultiplyInstr_t mult;

     mult.Rn = *instr.Rn;
     mult.Rs = *instr.Rs;
     mult.Rm = *instr.Rm;

    if(instr.opcode == "mul"){
     mult.A = 0;
     mult.Rd = mult.Rm * mult.Rs;
     mult.mnemonic = mul;
   } else if(instr.opcode == "mla"){
       mult.A = 1;
       mult.Rd = mult.Rm * mult.Rs + mult.Rn;
       mult.mnemonic = mla;
    }
   mult.S = 0;
   mult.cond = AL;

   MultiplyInstr_t * multPtr;
   multPtr = &mult;

   return multPtr;
}