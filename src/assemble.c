#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include "memoryImplementation.h"
#include "emulate_utils/instruction_basic.h"
#include "assemble_utils/assemblerImplementation.h"
#include "assemble_utils/defs.h"

int main(int argc, char **argv) {

    

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
    numberOfLinesInSource = numLines;
    instruction *instArr = calloc(numLines,sizeof(instruction));


    initSymbolTable();
    uint32_t *valueToBeWritten = NULL;

    while (fgets(line, MAX_LINE_SIZE, input)) {
        char **tokenizedLine = tokenizeHelper(line);

        // tokenizeHelper takes a line and return a 2D char array where the first sentence will be the instruction or label
        // it will be a label iff the last char of the first line is :
        // otherwise send it to decode;

        if (tokenizedLine[0][strlen(tokenizedLine[0])-1] == ':') {
            char *label = malloc(sizeof(tokenizedLine[0]));
            strcpy(label,tokenizedLine[0]);
            label[strlen(label)-1] = 0;
            if (containsLabel(label)==0) {
                addLabel(label,address);
            }
        } else {

            // send it to decode
            instArr[address] = *decode(tokenizedLine,address*4);
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

    for ( int i = 0; i < address; ++i) {
        uint32_t *writeValue = distinguish(instArr[i]);
        if (*writeValue != 0 || (*writeValue == 00 && !strcmp(instArr[i].opcode,"andeq"))) {
            fwrite(writeValue,1, sizeof(uint32_t),output);
        }
    }



   return EXIT_SUCCESS;

}
