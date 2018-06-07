
/*

u_int3  2_t *loadFile(char *path, u_int32_t *pointer) {
    FILE *binFile = 0; //all memory locations and registers initialised to 0
    int size = 0;
    binFile = fopen(path, "rb");
    size = (int) ftell(binFile);

    fread(pointer, 1, (size_t) size, binFile);
    fclose(binFile);
    return pointer;
}

*/

#include "binaryloader.h"

// this is just a test comment

void loadFile (char *fname, uint32_t *memory) {
    FILE *f = fopen(fname,"rb");

    if ( f == NULL ) {
        exit(-1);
    }

    if (ferror(f)) {
        exit(-1);
    }
}


//c is 29
