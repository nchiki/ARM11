//
// Created by nb1317 on 01/06/18.
//



#include <stdlib.h>
#include "assemblerImplementation.h"
#include <strings.h>
#include<string.h>


void initSymbolTable(void) {
    symbolTableHead = (struct symbol*)(malloc(sizeof(struct symbol)));
    symbolTableHead->label = NULL;
    symbolTableHead->next = NULL;
    symbolTableHead->address = 0;
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

uint16_t getAddress(char *givLabel) {
    struct symbol *temp = symbolTableHead;
    while (temp->next != NULL ) {
        if (strcmp(temp->label,givLabel) == 0) {
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

void clearSymbolTable() {
    if (symbolTableHead->next != NULL) {
        helperFunction(symbolTableHead->next);
    }
   free(symbolTableHead->label);
    free(symbolTableHead);
}



bool containsLabel(char *givenLabel) {
    struct symbol *temp = symbolTableHead;
    while (temp->next != NULL ) {
        if (strcmp(temp->label,givenLabel) == 0) {
            return true;
        }
    }
    return false ;
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

struct instruction decode(char** line, uint16_t memoryAddr) {
    struct instruction instr;
    instr.opcode  = line[0];
    instr.memoryAddr = memoryAddr;

    for ( int i = 0 ; i < 4 ; ++i ) {
        char *codes = Opcodes[i];
        int len = sizeof(codes)/ sizeof(codes[0]);

        for (int j = 0 ; j < len; ++j) {
            if (!strcmp(codes[j],line[0])) {
                instr.type = i;
                break;
            }

        }

    }

    switch(instr.type) {
        case DATA_PROCESSING:
            if (!strcmp(line[0], "mov")) {
                instr.Rd = line[1];
                instr.operand2 = line[2];
            } else if (!strcmp(line[0],"tst") || !strcmp(line[0],"teq") || !strcmp(line[0],"cmp")) {
                instr.Rn = line[1];
                instr.operand2 = line[2];
            } else {
                instr.Rd = line[1];
                instr.Rn = line[2];
                instr.operand2 = line[3];
            }
            break;

        case MULTIPLY:
            instr.Rd = line[1];
            instr.Rm = line[2];
            instr.Rs = line[3];

            if (!strcmp(line[0],"mla")) {
                instr.Rn = line[4];
            }

            break;
        case SINGLE_DATA_TRANSFER:

            
    }
}