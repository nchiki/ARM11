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
    char **returnValue;
    // magic 
    return returnValue;
}
// the idea here is to be able to make a switch function which takes the mnemonic
// and returns, using the defs in usefulTools, the code of both the condition and the opcodes






