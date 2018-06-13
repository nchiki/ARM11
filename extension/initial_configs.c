#include "initial_configs.h"
#include <stdlib.h>

void randomConfig(cell **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j].s = rand() % 2;
        }
    }
}

//Below are a list of various known patterns

void longLine(cell **grid, int width, int height) {
    int midW = width / 2;
    int midH = height / 2;

    for (int i = -4; i < 6; i++) {
        flipCell(&grid[midH][midW + i]);
    }
}


