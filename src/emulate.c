#include <stdlib.h>
#include "memoryImplementation.h"
#include "binaryloader.c"

  int main(int argc, char **argv) {
    uint32_t *registerArray = (uint32_t *) calloc(17, sizeof(uint32_t));
    uint32_t *memArray = (uint32_t *) calloc(16384, sizeof(uint32_t));
    uint32_t *start = *loadFile(argv[1], )
    while(instruction != 0x0) {
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
