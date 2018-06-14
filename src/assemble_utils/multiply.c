#include "instruction_defs.h"
#include "assemblerImplementation.h"
#include "registers.h"
#include "multiply.h"

 uint32_t *multiply(instruction instr){

    MultiplyInstr_t mult;
    int Rd = convertToWriteableFormat(instr.Rd);
    int Rm = convertToWriteableFormat(instr.Rm);
    int Rs = convertToWriteableFormat(instr.Rs);
    int Rn = 0;
    bool A = 0;

    if(strcmp(instr.opcode,"mul")==0){
      A = 0;
   } else if(strcmp(instr.opcode,"mla")==0){
     A = 1;
     Rn = convertToWriteableFormat(instr.Rn);
    }
   bool S = 0;
   int cond = 14;

   //uint32_t binary = mult.Rn | 0x0090 | (mult.Rs << 8) |(mult.Rn << 12) | (mult.Rd << 16) | (mult.S << 20) |
//           (mult.A << 21) | 0x00000000 | 0xE0000000;

    uint32_t *returnVal = malloc(sizeof(uint32_t));
    *returnVal =  cond << 28 | A << 21 | S << 20 | Rd << 16
    | Rn << 12 | Rs << 8 | 0b1001 << 4 | Rm;

     return returnVal;
}
