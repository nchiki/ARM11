#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include "memoryImplementation.h"
#include "emulate_utils/instruction_basic.h"
#include "assemble_utils/assemblerImplementation.h"

int main(int argc, char **argv) {

    assert(argc == 2 && "Incorrect number of arguments");

    char *sourceFile = argv[1];

    char *destFile = argv[2];

    uint16_t address = 0;

    char line[MAX_LINE_SIZE] ;

    // first pass

    FILE *input;

    if ((input = fopen(argv[1],"r")) == NULL) {
        printf("Could not open the file");
        exit(-1);
    }

    const int numLines = countLines(input);
    struct instruction instArr[numLines];
    // i'll have to count the number of lines, so zeroth pass?

    initSymbolTable();

    while (fgets(line, MAX_LINE_SIZE, input)) {
        char **tokenizedLine = tokenizeHelper(line);

        // tokenizeHelper takes a line and return a 2D char array where the first sentence will be the instruction or label
        // it will be a label iff the last char of the first line is :
        // otherwise send it to decode;

        if (tokenizedLine[0][strlen(tokenizedLine[0])-1] == ':') {
            if (containsLabel(tokenizedLine[0])==0) {
                addLabel(tokenizedLine[0],address);
            }
        } else {

            // send it to decode
            instArr[address] = decode(tokenizedLine,address*4);
            // parameter mismatch?
            address+=1;
        }
    }

    fclose(input);


    FILE *output;

    if ((output = fopen(argv[2],"wb"))==NULL) {
        printf("Could not open output file");
        exit(-1);
    }

    // second pass
    uint32_t *valueToBeWritten = NULL;

    for ( int i = 0 ; i < numLines; ++i ) {
        struct instruction currentInst = instArr[i];
        if (currentInst.type != NULL) {

            valueToBeWritten = distinguish(currentInst,symbolTableHead);
            // write to the file

        }
    }





}
