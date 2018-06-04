//
// Created by Blanca Tebar on 03/06/2018.

#include <memory.h>
#include "defs.h"
#include "../usefulTools.h"

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

    temp1 = strtok(temp1, " ,");

    while(temp1) {
        tokenized[i++] = temp1;
        temp1 = strtok(NULL, " ,");
    }
    tokenized[i] = temp2;


    return tokenized;
}

// the idea here is to be able to make a switch function which takes the mnemonic
// and returns, using the defs in usefulTools, the code of both the condition and the opcodes






