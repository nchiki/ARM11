//
// Created by nb1317 on 01/06/18.
//



#include <stdlib.h>
#include "assemblerImplementation.h"
#include <strings.h>
#include <string.h>


void initSymbolTable(void) {
    symbolTableHead = (struct symbol*)(malloc(sizeof(struct symbol)));
    symbolTableHead->label = NULL;
    symbolTableHead->next = NULL;
    symbolTableHead->address = 0;
}

void initConstantTable(void) {
    constantTableHead = (struct constantLL*)(malloc(sizeof(struct constantLL)));
    constantTableHead->label = NULL;
    constantTableHead->next = NULL;
    constantTableHead->address = 0;
}

void addLabel( char* newLabel, uint16_t givAddress ) {
    struct symbol *temp = symbolTableHead;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = (struct symbol*)(malloc(sizeof(struct symbol)));
    temp->next->label = NULL;
    temp->next->address = 0;
    temp->next->next = NULL;
    temp->label = malloc(strlen(newLabel)+1);
    strcpy(temp->label,newLabel);
    temp->address = givAddress;

}

void addConstant(uint32_t *newLabel, uint32_t givAddress) {
    struct constantLL *temp = constantTableHead;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = (struct constantLL*)(malloc(sizeof(struct constantLL)));
    temp->next->label = NULL;
    temp->next->address = 0;
    temp->next->next = NULL;
    temp->label = malloc(sizeof(uint32_t));
    temp->label = newLabel;
    temp->address = givAddress;

}

uint16_t getAddress(char *givLabel) {
    struct symbol *temp = symbolTableHead;
    while (temp->next != NULL ) {
        if (strcmp(temp->label,givLabel) == 0) {
            return temp->address;
        }
        temp = temp->next;
    }
    return -1;
}

uint16_t getLastAddress() {
    struct symbol *temp = symbolTableHead;
    while (temp->next != NULL ) {
    }
    return temp->address;
}

uint32_t getConstantLastAddress() {
    if(constantTableHead->label == NULL) {
      return getLastAddress();
    } else {
      struct constantLL *temp = constantTableHead;
      while (temp->next != NULL ) {
      }
      return temp->address;
    }
    return -1;
}

uint32_t getConstantAddress(uint32_t *givenLabel) {
    struct constantLL *temp = constantTableHead;
    while (temp->next != NULL ) {
        if (temp->label == *givenLabel) {
            return temp->address;
        }
    }
    return -1;
}


void helperFunction(struct symbol* something) {
    if (something->next != NULL ) {
        helperFunction(something->next);
    }
    free(something->label);
    free(something);


}

void constantsHelperFunction(struct constantLL* something) {
    if (something->next != NULL ) {
        constantsHelperFunction(something->next);
    }
    free(something->label);
    free(something);

}

void clearSymbolTable() {
    if (symbolTableHead->next != NULL) {
        helperFunction(symbolTableHead->next);
    }
   free(symbolTableHead->label);
    free(symbolTableHead);
}

void clearConstantTable() {
    if (constantTableHead->next != NULL) {
        constantsHelperFunction(constantTableHead->next);
    }
    free(constantTableHead->label);
    free(constantTableHead);
}



bool containsLabel(char *givenLabel) {
    struct symbol *temp = symbolTableHead;
    while (temp->next != NULL ) {
        if (strcmp(temp->label,givenLabel) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false ;
}

bool containsConstant (uint32_t *givenLabel) {
    struct constantLL *temp = constantTableHead;
    while (temp->next != NULL ) {
        if (temp->label == givenLabel) {
            return true;
        }
    }
    return false ;
}

int32_t calculateOffset(uint32_t PC, uint32_t value) {
    int32_t returnValue;
    uint32_t *key = malloc(sizeof(uint32_t));
    *key = value;
    uint32_t address = getLastAddress();
    addConstant(key, value);
    returnValue = (address) - (int32_t)PC;
    return returnValue&0xFFF;
}


int numberOfConstants() {
    struct constantLL *temp = constantTableHead;
    int count = 0;
    while (temp->next!= NULL) {
        temp = temp->next;
        count+=1;
    }
    count+=1;
    return count;
}
uint32_t parse(char *line) {
    int i = 0;
    char *addr = line;
    char *word = "";
    while (line[i] != ' '){
        if(line[i] != ' ') {
            *word += line[i];//saves the first word;
        }
        addr ++; // increments the addres of the array
    }
}

instruction *decode(char** given, uint16_t memoryAddr) {
    instruction *instr = malloc(sizeof(instruction));

    char *line[5];
    for ( int i = 0 ; i < 5 ; ++i ) {
        line[i] = malloc(strlen(given[i])+1);
    }

    for ( int i = 0 ; i < 5 ; ++i ) {
        strcpy(line[i],given[i]);
    }
    instr->opcode  = line[0];
    instr->memoryAddr = memoryAddr;


    for ( int i = 0 ; i < 4 ; ++i ) {
        //char *codes = ;
        int len = sizeof(Opcodes[i])/ sizeof(Opcodes[i][0]);

        for (int j = 0 ; j < len; ++j) {
            if (!strcmp(Opcodes[i][j],line[0])) {
                instr->type = i;
                break;
            }

        }

    }

    if (strcmp(line[0],"andeq")==0) {
        instr->type = 5;
    } else if (strcmp(line[0],"lsl")==0) {
        instr->type = LsL;
    }

    switch(instr->type) {
        case DATA_PROCESSING:
            if (!strcmp(line[0], "mov")) {
                instr->Rd = line[1];
                instr->Rn = "#0";
                instr->operand2 = line[2];
                //strcpy(instr->Rd,line[1]);
                //strcpy(instr->Rn,"#0");
                //strcpy(instr->operand2,line[2]);
            } else if (!strcmp(line[0],"tst") || !strcmp(line[0],"teq") || !strcmp(line[0],"cmp")) {
                instr->Rd = "#0";
                instr->Rn = line[1];
                instr->operand2 = line[2];
            } else {
                instr->Rd = line[1];
                instr->Rn = line[2];
                instr->operand2 = line[3];
            }
            break;

        case MULTIPLY:
            instr->Rd = line[1];
            instr->Rm = line[2];
            instr->Rs = line[3];

            if (!strcmp(line[0],"mla")) {
                instr->Rn = line[4];
            }

            break;

        case SINGLE_DATA_TRANSFER:
            instr->Rd = line[1];
            instr->address = line[2];
            //for cases where there is a complex address;

            break;


        case BRANCH:
            instr->expression = line[1];
            break;

        case LsL:
            instr->Rn = line[1];
            instr->expression = line[2];
            break;

        case ANDEQ:
            instr->Rn = '\0';
            instr->Rd = '\0';
            instr->operand2 = '\0';
            break;
    }
    return instr;
} // fixed

int countLines (FILE* input) {
    int returnVal;
    char line[MAX_LINE_SIZE];


    while(fgets(line, sizeof(line),input)) {
        returnVal++;
    }

    return returnVal;
}

void setInstNull(instruction inst) {
    inst.opcode = NULL;
    inst.Rd = NULL;
    inst.Rn = NULL;
    inst.operand2 = NULL;
    inst.Rm = NULL;
    inst.Rs = NULL;

    inst.address = NULL;
    inst.expression = NULL;
    inst.memoryAddr = 0;

}
