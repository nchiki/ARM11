#include <stdlib.h>
#include <assert.h>
#include "memoryImplementation.h"
#include "emulate_utils/instruction_basic.h"
#include "assemble_utils/assemblerImplementation.h"

int main(int argc, char **argv) {

    assert(argc == 2 && "Incorrect number of arguments");

    char *sourceFile = argv[1];

    char *destFile = argv[2];

    instructions thisInstruction = NULL;
    symbolTableHead->label = "A:";
    symbolTableHead->address = 0;
    symbolTableHead->next =
    //executes until it reaches the end of the program
    while (thisInstruction.type != Halt) {
        //first pass
        symbolTableHead
    }

}
