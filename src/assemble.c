#include <stdlib.h>
#include <assert.h>
#include "memoryImplementation.h"
#include "emulate_utils/instruction_basic.h"
#include "assemble_utils/assemblerImplementation.h"

int main(int argc, char **argv) {

    assert(argc == 2 && "Incorrect number of arguments");

    char *sourceFile = argv[1];

    char *destFile = argv[2];

    uint32_t address = 0;
    struct symbol *temp = symbolTableHead;
    //first pass
    char a = 65; // ascii value of 'A'
    char b = 65;
    char c = 65;
    for(int i = 0; i < 511 ; i++) {
        temp->label = a + b + c + ":"; //concatenation of three letters
        temp->address = address; //sets address
        temp = temp->next; // next instruction to be translated
        if((int )a == 90) { // jumps to lower case letters
            a = 97;
        }else if((int )a == 122) {
            a = 65;
            if((int )b == 90) {
                b = 97;
            }else if((int )b == 122) {
                b = 65;
                if((int )c == 90) {
                    c = 97;
                }else if((int )c == 122) {
                    c = 65;
                } else {
                    c += 1;
                }
            } else {
                b += 1;
            }
        } else {
            a += 1;
        }
        address+= 4; //increments the address by four bits
    }

    //need sth that reads each line of the file, taking it to a "distinguishInstruction" method that would return the
            // type of the instruction, and with a switch(by the different instructions in usefulTools)
                    // in a helper method that splits the following code depending on the instruction (as in decode for emulator)
                            // and using the structs in .h encode the different fields of each instruction
                                    //would it be useful to have a method that encodes different instructions?

    char chr;
    char *line;
    while (chr != feof(sourceFile)) {
        while (chr != '/n') {
           chr = fgets(line, 512, sourceFile);
        }
    }

    fclose(sourceFile);
}
