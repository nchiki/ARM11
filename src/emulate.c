

#include "emulate_utils/binaryloader.h"
#include "emulate_utils/execute.h"
#include <string.h>


word_t getBitRange(word_t num, int start, int length);

// Initialisation of the elements of the machine
CPU cpuo = {
  .registers = {0},
  .fetchedInstruction = 0,
};

MEMORY memoArray = {
  .memoryAlloc = {0},
};

// dummy instruction to fix the effects of the pipeline
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
 (SHIFT_CODE) -1,
 -1
};


int main(int argc, char **argv) {
   //checks if it receives the correct number of arguments
    assert(argc == 2 && "Incorrect number of arguments");

    char *givenFile = argv[1];

    CPU *cpu = (CPU *)malloc(sizeof(CPU)); //allocates the cpu
    *cpu = cpuo;

    MEMORY *memory = (MEMORY *)malloc(sizeof(MEMORY)); //allocates the memory
    *memory = memoArray;

    (cpu->decodedInstruction) = (instructions *)malloc(sizeof(instructions));
    *(cpu->decodedInstruction) = NullInstruction;



    MACHINE *machine = (MACHINE*)(malloc(sizeof(MACHINE))); // allocates the machine
    // setting values
    (machine->c) = *cpu;
    (machine->mem) = *memory;

    //loading the file
    loadFile(givenFile,machine->mem.memoryAlloc);

    // Fill the pipeline before you begin
    word_t fetched = 0;
    word_t address = machine->c.registers[PC];
    fetched |= ((uint32_t) machine->mem.memoryAlloc[binToDec(address)]);

    machine->c.fetchedInstruction = fetched;
    machine->c.instructionIsFetched=true;

    machine->c.registers[PC] += 1;
    if(machine->c.instructionIsFetched){
      decode(machine);
    }

    // --------------------MAIN WHILE LOOP---------------------------

    //once there are instructions to fetch, execute and decode it will execute the loop
    while (machine->c.decodedInstruction->type != Halt  ) {
      //fetch
      address = machine->c.registers[PC];
      fetched = 0;
      fetched |= ((uint32_t) machine->mem.memoryAlloc[binToDec(address)]);
      machine->c.instructionIsFetched = true;
      machine->c.fetchedInstruction = fetched;

      //execute
      if (machine->c.decodedInstruction->type != None) {
      execute(machine);
      }


      //decode
      *(machine->c.decodedInstruction) = NullInstruction; //dummy value to be defined by decode
      if(machine->c.instructionIsFetched){ //check if the instruction has to be decoded
        decode(machine);
      }

      machine->c.registers[PC] += 1; // as we made 4-bytes addresses the value
                                    // of the Pc is only incremented by 1
    }
    machine->c.registers[PC] += 1; // last time incremented
    execute(machine); // executes halt and prints the values held in memory and registers

    //frees and exits the program
    free(machine->c.decodedInstruction);
    free(cpu);
    free(memory);
    free(machine);
    return EXIT_SUCCESS;
  }
