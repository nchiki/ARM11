//
// Created by Blanca Tebar on 03/06/2018.

#include <memory.h>
#include "defs.h"
#include "../usefulTools.h"
#include "assemblerImplementation.h"


MNEMONIC takeMnemonic(char *word) {
    if (!strcmp(word, "add")) {
        return add;
    } else if(!strcmp(word, "sub")) {
        return sub;
    } else if(!strcmp(word, "rsb")) {
        return rsb;
    } else if(!strcmp(word, "and")) {
        return and;
    } else if(!strcmp(word, "eor")) {
        return eor;
    } else if(!strcmp(word, "orr")) {
        return orr;
    } else if(!strcmp(word, "mov")) {
        return mov;
    } else if(!strcmp(word, "tst")) {
        return tst;
    } else if(!strcmp(word, "teq")) {
        return teq;
    } else if(!strcmp(word, "cmp")) {
        return cmp;
    } else if(!strcmp(word, "mul")) {
        return mul;
    } else if (!strcmp(word, "mla")) {
        return mla;
    } //to be continued
}


char **tokenizeHelper(char *line) {

    char new_line[MAX_LINE_SIZE];
    char *tokenized[10];
    // 10 is just a random number, but each instruction definitely has less than 10 arguments.
    // if theres only 2 arguments, the rest of them will be set to null so it wont be a problem
    // only have to check for null when we're using the sentence in decode (presumably)
    int i = 0;

    strcpy(new_line, line); /* can't use strtok on string literal */
    char *temp1 = strtok(new_line, "[");
    char *temp2 = strtok(NULL, "[");
    //IMPORTANT---------------------------------------------------
    // needed a flag for the pre/post indexing in sdt (PFlag?)
    //look at sdt.c, PFlag in instruction would have to be set if the address
    //is of the form [Rn, <#expression>] instead of [Rn], <#expression>
    temp1 = strtok(temp1, " ,");

    while(temp1) {
        tokenized[i++] = temp1;
        temp1 = strtok(NULL, " ,");
    }
    tokenized[i] = temp2;


    return tokenized;
}


uint32_t *distingush(struct instruction inst, struct symbol *symbolTable) {
    uint32_t *returnVal = NULL;

    switch(inst.type) {
        case DATA_PROCESSING:
            // call to function ?
            break;
        case MULTIPLY:
            // call to function? where will you convert to uint32?
            break;

        // HOW DO I HANDLE LSL FOR GODS SAKE WHY DOES IT SAY DUPLICATE CASE VALUE
        case LsL:
            // call to function, where will you convert to uint32?
            break;

        case SINGLE_DATA_TRANSFER:
            // call to function? where will you convert internal struct to uint32?
            break;
        case BRANCH:
            //  call to function? where will you convert internal sturct to uint32?
            // call to function like this: branch(inst, symbolTable), branch hasnt implemented that
            break;
        case ANDEQ:
            returnVal = 0;
            break;
    }

    return returnVal; 

}



// the idea here is to be able to make a switch function which takes the mnemonic
// and returns, using the defs in usefulTools, the code of both the condition and the opcodes

uint16_t convertToWriteableFormat(char* givenStr) {
    uint16_t returnVal = 0 ;

    switch(givenStr[0]) {
        case 'r' :
            // if its a register
            returnVal = textToInt(givenStr);
            break;
        case '#' :
            // this is where we convert Immediates to text
            break;
        case '=' :
            returnVal = textToint(givenStr);
            break;
    }
    return returnVal;
}

uint16_t textToInt(char *givenStr) {
    // the first character of giveStr will definitely be # = or r
    uint16_t returnVal = 0 ;
    int len = strlen(givenStr);

    for (int i = 1 ; i < len ; ++i ) {
        returnVal = returnVal*10 + (givenStr[i] - '0');
    }
    return returnVal;
}




