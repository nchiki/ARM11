#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include "memoryImplementation.h"
#include "binaryloader.c"
#include "execute.h"
#include <string.h>
#include "decode.c"

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
    MACHINE *machine;

    uint32_t *memArray = (uint32_t *) calloc(16384, sizeof(uint32_t));


      *(machine->mem.memoryAlloc) = memArray; //not sure how to do this


    uint32_t *registerArray = (uint32_t *) calloc(17, sizeof(uint32_t));

      *(machine->c.registers) = registerArray;
    // i'm assuming traversing through the array and then using calloc is redundant, but im still going to keep it in

    assert(argc == 2 && "Incorrect number of arguments");

    char *givenFile = argv[1];

  


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
     instruction NullInstruction = {
      None,
      1111,
      -1,
      0,

    //registers
      -1,
      -1,
      -1,
      -1,

    //flags for operations
      0,
      0,
      0,
      0,
      0,
      0,

    //immediate value
      0,
    
    //operand2
      0,
      0,
      -1,

     };

    machine->c.decodedInstruction = malloc(sizeof(instruction)); //creates space for the decoded instruction
     *(machine->c.decodedInstruction) = NullInstruction;

    // read from binary file into memory array
    // i wonder if i could do this : loadFile(givenFile, memArray) -> technically it should be fine because they both point to memAlloc[0]?
    loadFile(givenFile,machine->mem.memoryAlloc);
    

    // --------------------MAIN WHILE LOOP---------------------------
    //we need a if condition in fetch that checks if the instruction that has just been decoded is Halt, 
    //if its so -> finalise to true and don't fetch
    //if not -> fetch

    bool finalise = false; //finalise will become true when the instruction is the zero instruction: halt

    while (!finalise) {

      //execute
      // Do we need * here?
      execute(machine);

      //decode
      *(machine->c.decodedInstruction) = NullInstruction;
      decode(machine);

      //fetch
      uint16_t address = machine->c.registers[PC];
      uint32_t fetched = 0;
      //we need 4 iterations of the loop because each instruction is 4 bytes, and each iteration reads one byte
      //shifting by 8 (1 byte = 8 bits)
      for(int i = 0; i < 4; i++) {
        address |= ((uint32_t) machine->mem.memoryAlloc[address + i]) << (i * 8);
      }
      machine->c.fetchedInstruction = address;
      machine->c.instructionFetched = true;

      registerArray[PC] += 4; // four bytes because is 4-byte addresable

      // Do we need *?
      free(machine->c.decodedInstruction);
      free(*registerArray);
      free(*memArray);
      return 0;
    }


  }


