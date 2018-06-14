//
// Created by Blanca Tebar on 03/06/2018.

#include <string.h>
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
    char *tempLine;
    char *tempLine2 = NULL;

    char newline[MAX_LINE_SIZE];
    char **tokenized = malloc(sizeof(char*)*10);
    // 10 is just a placeholder, should probably improve it

    int i = 0;
    if (line[0] == ' ') {
        strcpy(newline,line+1);
    } else {
        strcpy(newline,line);
    }

    if (line[strlen(line)-1] == '\n') {
        line[strlen(line)-1] = '\0';
    }

    strcpy(newline,line);

    if(strchr(line,'[') != NULL) {
        tempLine = strtok(newline,"[");
        tempLine2 = strtok(NULL,"[");
    } else {
        tempLine = newline;
    }
    tempLine = strtok(tempLine, ", ");

    while(tempLine) {
        tokenized[i] = tempLine;
        i++;
        tempLine = strtok(NULL, ", ");
    }

    if ( tempLine2 != NULL && i < 10) {
        tokenized[i] = tempLine2;
        i++;
    }

    while ( i < 10 ) {
        tokenized[i] = "";
        i++;
    }

    for ( int i = 0 ; i < 10 ; ++i ) {
        if (tokenized[i][0] == ' ') {

        }
    }
    return tokenized;
}


uint32_t *distinguish(instruction inst) {
    uint32_t *returnVal;

    switch(inst.type) {
        case DATA_PROCESSING:
            returnVal = dataProcessing(inst);
            break;
        case MULTIPLY:
            returnVal = multiply(inst);
            break;
        case SINGLE_DATA_TRANSFER:
            returnVal = SDTassembling(inst);
            break;

        case BRANCH:
            returnVal = branch(inst);
            // call to function like this: branch(inst, symbolTable), branch hasnt implemented that
            break;

        case LsL:
            returnVal = lslFunc(inst);
            break;


        case ANDEQ:

            break;
    }

    return returnVal;

} // fixed



// the idea here is to be able to make a switch function which takes the mnemonic
// and returns, using the defs in usefulTools, the code of both the condition and the opcodes

int32_t convertToWriteableFormat(char *givenStr) {
    int32_t returnVal = 0;
    int32_t temp = 1;
    bool neg = false;
    switch(givenStr[0]) {
        case 'r' : returnVal = atoi(givenStr+1); break;
        case '#' :
        case '=' :
            if (givenStr[1] == '-') {
                temp = 2;
                neg = true;
            }
            if (givenStr[temp] == '0' && givenStr[temp+1] == 'x') {
                returnVal = (int32_t)strtol(givenStr+1,NULL, 0);
            } else {
                returnVal = atoi(givenStr+1);
            }
            break;
    }
    if (neg) {
      returnVal *= (-1);
    }
    return returnVal;
} // fixed

bool isNeg(char *givenStr) {
    bool neg = false;
    switch(givenStr[0]) {
        case 'r' :
            break;
        case '#' :
        case '=' :
          if (givenStr[1] == '-'){
            neg = true;
          }
            break;
        default:
              break;
            }
    return neg;
} // fixed

uint16_t textToInt(char *givenStr) {
    // the first character of giveStr will definitely be # = or r
    uint16_t returnVal = 0 ;
    int len = strlen(givenStr);

    for (int i = 1 ; i < len ; ++i ) {
        returnVal = returnVal*10 + (givenStr[i] - '0');
    }
    return returnVal;
}

uint32_t getOp2 (int32_t op2) {

    int shiftVal = 32;
    uint32_t tempVal = op2;
    while(!(tempVal & 0x3)){
      tempVal >>= 2;
      shiftVal--;
    }
    return ((shiftVal << 8) | (tempVal & 0xFF)) & 0xFFF;
} // fixed

uint32_t *lslFunc(instruction inst) {
    uint32_t *returnValue = calloc(1,sizeof(uint32_t));
    uint8_t condition = 14;
    uint8_t opcode = 13;

    uint32_t Rn = convertToWriteableFormat(inst.Rn);

    uint32_t shiftVal = convertToWriteableFormat(inst.expression);
    uint8_t S = 0;

    *returnValue = ((condition << 28) | opcode << 21 | S << 20 | Rn << 12 | (shiftVal << 7) | Rn );

    return returnValue;

} //fixed

bool checkIfImmediate(char *text) {
  char *given = malloc(strlen(text));
  strcpy(given,text);
    switch(given[0]) {
        case 'r' :
                return false;
                break;
        case '#' :
        case '=' :
                return true;
                break;
        default:
                return false;
    }

} // fixed


uint32_t shiftOperand (char *base, char *shiftT, char *shiftA) {
    uint32_t returnVal = 0;
    int baseVal = convertToWriteableFormat(base);
    int shiftC = 0;
    int shiftAmount;


    if (!strcmp(shiftT,"lsl")) {
        shiftC = 0;
    } else if (!strcmp(shiftT,"lsr")) {
        shiftC = 1;
    } else if (!strcmp(shiftT,"asr")) {
        shiftC = 2;
    } else if (!strcmp(shiftT,"ror")) {
        shiftC = 3;
    }

    if (checkIfImmediate(shiftA)) {
        shiftAmount = 7;
    } else {
        shiftAmount = 8;
    }

    returnVal = convertToWriteableFormat(shiftA) << shiftAmount | shiftC << 5 |
     (shiftAmount==8) << 4 | baseVal;

    return returnVal;
} // fixed
