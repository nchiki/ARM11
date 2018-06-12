#include <stdio.h>
#include <stdint.h>
#include "instruction_defs.h"
#include "registers.h"

uint32_t *SDTassembling(instruction inst){
  /*SDTinstr_t SDTinstr;
  SDTinstr.cond = AL;
  if (!strcmp(inst.opcode, "ldr")) {
    SDTinstr.L = '1'; //load bit set
  } else {
    SDTinstr.L = '0';
  }
  //checks if its the form of <=expression>
  if(inst.address[0] == '=') {
    char *expr = inst.address + 1;
    if (atoi(expr) <= 0xFF) { //the value to be load fits in a mov instruction
      instruction movInstr;
      movInstr.opcode = "mov";
      movInstr.memoryAddr = inst.address;
      movInstr.type = DATA_PROCESSING;
      movInstr.Rd = inst.Rd;
      movInstr.operand2 = inst.address;
      return dataProc(movInstr);
    } else { // stores the value at the end of the assemble file and gets the address
      SDTinstr.P = '1';
      int NUMofLines= numberOfLinesInSource;

      SDTinstr.Rn = r16; //this should be r15 bc its the PC-----
      SDTinstr.U = '0';
      SDTinstr.I = '1';
      // the address of the value is going to be the actual address adding the number of lines multiplied by 4 so its unique
      SDTinstr.offset = inst.memoryAddr + (NUMofLines*4);
      //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
      //have to save the value in the destination file (no clue of how to do that)
      //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    }
  }else {
    SDTinstr.Rn = assignReg(inst.Rn);
    SDTinstr.offset = inst.expression;

    SDTinstr.P = inst.PFlag; //sets the P bit if the tokenizeHelper decoded an address of the form [Rn, <#expression>]
  }
*/




}
