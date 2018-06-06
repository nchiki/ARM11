
#include <memory.h>
#include "assemblerImplementation.h"
// change the return type of the thing


DataProcInstr_t *dataProc(struct instruction instr){

    DataProcInstr_t dataP;

    if(!strcmp(instr.opcode, "mov")){
        dataP.mnemonic = mov;
    } else if(strcmp(instr.opcode, "tst") || strcmp(instr.opcode, "teq") || strcmp(instr.opcode, "cmp")){
        if(!strcmp(instr.opcode, "cmp")) {
            dataP.mnemonic = cmp;
        } else if(!strcmp(instr.opcode, "tst")){
            dataP.mnemonic = tst;
        } else{
            dataP.mnemonic = teq;
        }

    } else{
        if(!strcmp(instr.opcode, "and")) {
            dataP.mnemonic = and;
        } else if(!strcmp(instr.opcode, "eor")){
            dataP.mnemonic = eor;
        } else if(!strcmp(instr.opcode, "sub")){
            dataP.mnemonic = sub;
        } else if(!strcmp(instr.opcode, "rsb")){
            dataP.mnemonic = rsb;
        } else if(!strcmp(instr.opcode, "add")){
            dataP.mnemonic = add;
        } else{
            dataP.mnemonic = orr;
        }
    }

    //still have to complete shifting and so on..


}

