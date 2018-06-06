#include <assert.h>
#include "emulate_utils/binaryloader.h"
#include "emulate_utils/execute.h"
#include <string.h>
#include <byteswap.h>

uint32_t memArray;
uint32_t *registerArray;

uint32_t getBitRange(uint32_t num, int start, int length);


int main(int argc, char **argv) {
    /* explanation:
     * would it not be easier to just use the global variable machine from memImplementation.h rather than create a new
     * one and have to mess around with pointers and what not?
     * at the start of this function, main, just initialise everything to zero. doesn't mean the struct variable cant
     * exist before this, does it?
     *
     * global var may be changed elsewhere unknowingly
     *
    */

    /*for ( int i = 0 ; i < 17; ++i ) {
      machine.registers[i] = 0;
    }

    for ( int i = 0 ; i < 16384; ++i ) {
      machine.memoryAlloc[i] = 0;
    }*/

    // could use this to initialise to zero?
    MACHINE *machine = (MACHINE*)(malloc(sizeof(MACHINE)));

    memArray = (uint32_t *) calloc(16384, sizeof(uint32_t));


    *(machine->mem.memoryAlloc) = memArray;


    registerArray = (uint32_t *) calloc(17, sizeof(uint32_t));

      *(machine->c.registers) = *registerArray;
    // i'm assuming traversing through the array and then using calloc is redundant, but im still going to keep it in

    assert(argc == 2 && "Incorrect number of arguments");

    char *givenFile = argv[1];



    // another useless comment
            
    // read from binary file into memory array
    // i wonder if i could do this : loadFile(givenFile, memArray) -> technically it should be fine because they both point to memAlloc[0]?

    loadFile(givenFile,machine->mem.memoryAlloc);



    /* for the main while loop of emulate_utils:
     * is it better to create a struct for instructions, and then extract one uint32 from memory and use it, or is it
     * better to not do any such thing and just process the "instructions" in a 3-staggered while loop?
     * if instructions is it's own struct:
     *      then it can have data members instruction_type, cond and a bunch of others to store the effects and particulars
     *      of that particular instructions, but this may lead to problems with dereferencing later
     * if instructions is NOT it's own struct:
     *      then as soon as we extract from memory, there needs to be a helper function which extracts all the necessary
     *      information like instructionType, cond, opcode and other particulars of the instructions. could stick these
     *      functions into a .h and .c file of their own, or could have them inside the while loop which would make it
     *      quite messy
     *      ^^^ oh i was talking about decode here and in the point above.
     *
     * essentially, it comes down to having a helper functions to perform decode, or having decode within the struct      
     * design decision here
     */
     instructions NullInstruction = {
      None,
      1111,
      2, //Random value not equal to any know cond codes
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
      -1
     };

    machine->c.decodedInstruction = (instructions *) malloc(sizeof(instructions)); //creates space for the decoded instructions
    machine->c.decodedInstruction = &NullInstruction;

    // read from binary file into memory array
    // i wonder if i could do this : loadFile(givenFile, memArray) -> technically it should be fine because they both point to memAlloc[0]?
    loadFile(givenFile,machine->mem.memoryAlloc);

    // Fill the pipeline before you begin

    uint32_t address = machine->c.registers[PC];
    uint32_t fetched = 0;
    for(int i = 0; i < 4; i++) {
            fetched |= ((uint32_t) machine->mem.memoryAlloc[address + i]) << (i * 8);
        }


    fetched = bswap_32(fetched);
    // flipped the bits here

    machine->c.fetchedInstruction= fetched;
    registerArray[PC] += 4;
    decode(machine);


    // --------------------MAIN WHILE LOOP---------------------------

    bool finalise = false; //finalise will become true when the instructions is the zero instructions: halt

    while (!finalise) {
      //fetch
      address = machine->c.registers[PC];
      fetched = 0;
      //we need 4 iterations of the loop because each instructions is 4 bytes, and each iteration reads one byte
      //shifting by 8 (1 byte = 8 bits)
      for(int i = 0; i < 4; i++) {
        fetched |= ((uint32_t) machine->mem.memoryAlloc[address + i]) << (i * 8);
      }

      fetched = bswap_32(fetched);
      //flippd the bits here

      machine->c.fetchedInstruction = fetched;
      finalise = (fetched == 0);

      registerArray[PC] += 4; // four bytes because is 4-byte addressable


      //execute
      execute(machine);

      //decode
      machine->c.decodedInstruction = &NullInstruction;
      decode(machine);

      registerArray[PC] += 4; // four bytes because is 4-byte addresable

    }

    execute(machine);
    free(machine->c.decodedInstruction);
    free(registerArray);
    free(memArray);
    return 0;
  }


