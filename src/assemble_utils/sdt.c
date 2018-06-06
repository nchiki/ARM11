#include <stdio.h>
#include <stdint.h>
#include "instruction_defs.h"
#include "registers.h"

uint32_t *SDTassembling(struct instruction instruction){
  SDTinstr_t SDTinstr;
  SDTinstr.cond = AL;
if (!strcmp(instruction.opcode, "ldr")) {
  SDTinstr.L = '1'; //load bit set
} else {
  SDTinstr.L = '0';
}
  //checks if its the form of <=expression>
  if(instruction.address[0] == '=') {
    char *expr = instruction.address + 1;
    if (atoi(expr) <= 0xFF) { //the value to be load fits in a mov instruction
      instruction movInstr;
      movInstr.opcode = "mov";
      movInstr.memoryAddr = instruction.address;
      movInstr.type = DATA_PROCESSING;
      movInstr.Rd = instruction.Rd;
      movInstr.operand2 = instruction.address;
      return dataProc(movInstr);
    } else { // stores the value at the end of the assemble file and gets the address
      SDTinstr.P = '1';
      int NUMofLines= countLines(sourceFile);
      SDTinstr.Rn = r16;
      SDTinstr.U = '0';
      SDTinstr.I = '1';
      // the address of the value is going to be the actual address adding the number of lines multiplied by 4 so its unique
      SDTinstr.offset = instruction.memoryAddr + (NUMofLines*4);
      //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
      //have to save the value in the destination file (no clue of how to do that)
      //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    }
  }else {
    SDTinstr.Rn = assignReg(instruction.Rn);
    SDTinstr.offset = instruction.expression;

    SDTinstr.P = instruction.PFlag; //sets the P bit if the tokenizeHelper decoded an address of the form [Rn, <#expression>]
  }

}
