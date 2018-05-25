#include <stdlib.h>
#include <stdbool.h>
#include "memoryImplementation.h"
#include "binaryloader.c"

  int main(int argc, char **argv) {

    uint32_t *memArray = (uint32_t *) calloc(16384, sizeof(uint32_t));
    uint32_t *start = *loadFile(argv[1], 0);
    uint32_t *registerArray = (uint32_t *) calloc(17, sizeof(uint32_t));
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
