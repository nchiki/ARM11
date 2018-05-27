#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include "memoryImplementation.h"
#include "binaryloader.c"
#include "execute.h"
#include <string.h>


  int main(int argc, char **argv) {
    /* explanation:
     * would it not be easier to just use the global variable machine from memImplementation.h rather than create a new
     * one and have to mess around with pointers and what not?
     * at the start of this function, main, just initialise everything to zero. doesn't mean the struct variable cant
     * exist before this, does it?
    */

    /*for ( int i = 0 ; i < 17; ++i ) {
      machine.registers[i] = 0;
    }

    for ( int i = 0 ; i < 16384; ++i ) {
      machine.memoryAlloc[i] = 0;
    }*/

    // could use this to initialise to zero?
    machine_type *machine;
    uint32_t *memArray = (uint32_t *) calloc(16384, sizeof(uint32_t));
    machine->memoryAlloc = memArray; //not sure how to do this
    uint32_t *registerArray = (uint32_t *) calloc(17, sizeof(uint32_t));
    machine->registers = registerArray;
    // i'm assuming traversing through the array and then using calloc is redundant, but im still going to keep it in

    assert(argc == 2 && "Incorrect number of arguments");

    char *givenFile = argv[1];

    // read from binary file into memory array
    // i wonder if i could do this : loadFile(givenFile, memArray) -> technically it should be fine because they both point to memAlloc[0]?
    loadFile(givenFile,machine->memoryAlloc);


    /* for the main while loop of emulate:
     * is it better to create a struct for instructions, and then extract one uint32 from memory and use it, or is it
     * better to not do any such thing and just process the "instructions" in a 3-staggered while loop?
     * if instructions is it's own struct:
     *      then it can have data members instruction_type, cond and a bunch of others to store the effects and particulars
     *      of that particular instruction, but this may lead to problems with dereferencing later
     * if instructions is NOT it's own struct:
     *      then as soon as we extract from memory, there needs to be a helper function which extracts all the necessary
     *      information like instructionType, cond, opcode and other particulars of the instruction. could stick these
     *      functions into a .h and .c file of their own, or could have them inside the while loop which would make it
     *      quite messy
     *      ^^^ oh i was talking about decode here and in the point above.
     *
     * essentially, it comes down to having a helper functions to perform decode, or having decode within the struct      
     * design decision here
     */





    bool finalise = false; //finalise will become true when the instruction is the zero instruction: halt

    while (!finalise) {

      //execute
      execute(*machine);

      //decode
      //needed a file that decodes the instructions

      //fetch: takes the next instruction from program counter (what happens if the instruction is halt?)

      registerArray[PC] += 4; // four bytes because is 4-byte addresable


      free(*registerArray);
      free(*memArray);
      return 0;
    }


  }


