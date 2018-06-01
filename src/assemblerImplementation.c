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

void addLabel( char* newLabel, uint32_t givAddress ) {
    struct symbol *temp = symbolTableHead;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = (struct symbol*)(malloc(sizeof(struct symbol)));
    temp->next->label = NULL;
    temp->next->address = 0;

}

uint32_t getAddress(char *givLabel) {
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
    something->clear();

}
void clearSymbolTable() {
    if (symbolTableHead->next != NULL) {
        helperFunction(symbolTableHead->next);
    }
   symbolTableHead->clear();
}