#include <stdlib.h>
#include <stdbool.h>
#include "memoryImplementation.h"
#include "binaryloader.c"




  int main(int argc, char **argv) {


    for ( int i = 0 ; i < 17; ++i ) {
      machine.registers[i] = 0;
    }

    for ( int i = 0 ; i < 16384; ++i ) {
      machine.memoryAlloc[i] = 0;
    }

    // could use this to initialise to zero?
    uint32_t *memArray = (uint32_t *) calloc(16384, sizeof(uint32_t));
    machine.memoryAlloc = memArray;
    uint32_t *registerArray = (uint32_t *) calloc(17, sizeof(uint32_t));
    machine.registers = registerArray;
    // i'm assuming traversing through the array and then using calloc is redundant, but im still going to keep it in

    assert(argc == 2 && "Incorrect number of arguments");

    char *givenFile = argv[1];


    bool finalise = false;

    while (!finalise) {
      uint32_t instruction = *registerArray[PC];
      int cond = instruction >> 28;
      switch (cond) {

      }
      int i = 0;
      for (; i < 17; i++) {
        printf("%d\n", registerArray[i]);
      }

      free(*registerArray);
      return 0;
    }


  }

    // i honestly have no clue what this bit here does - niranjan 25 may
    uint32_t fetch(uint32_t registerArray) {
    uint32_t instr = (*registerArray)[15]; //taking the address stored in the PC
    *registerArray[PC]++; // incrementing PC
    return instr;
  }

  bool decode(uint32_t instruction) {

    return true;
}

  void execute(uint32_t instruction) {

}
