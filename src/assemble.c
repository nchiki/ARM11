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

    uint32_t address = 0;

    char line[MAX_LINE_SIZE] ;

    while (fgets(line, MAX_LINE_SIZE, sourceFile)) {
        char **tokenizedLine = tokenizeHelper(line);

        // tokenizeHelper takes a line and return a 2D char array where the first sentence will the instruction or label
        // it will be a label iff the last char of the first line is :
        // otherwise send it to decode;

        if (tokenizedLine[0][strlen(tokenizedLine[0])-1] == ':') {
            if (containsLabel(tokenizedLine[0])==0) {
                addLabel(tokenizedLine[0],address);
            }
        } else {
            address+=1;
            // send it to decode
        }
    }


    //first pass


    //need sth that reads each line of the file, taking it to a "distinguishInstruction" method that would return the
            // type of the instruction, and with a switch(by the different instructions in usefulTools)
                    // in a helper method that splits the following code depending on the instruction (as in decode for emulator)
                            // and using the structs in .h encode the different fields of each instruction
                                    //would it be useful to have a method that encodes different instructions?

    char chr;

    while (chr != feof(sourceFile)) {
        while (chr != '/n') {
           chr = fgets(line, 512, sourceFile);
        }
    }

    fclose(sourceFile);
}
