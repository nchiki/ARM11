#include "initial_configs.h"
#include <stdlib.h>

void randomConfig(cell **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j].s = rand() % 2;
        }
    }
}

//Below are a list of various known patterns - require reasonably sized grids

void periodic(cell **grid, int width, int height) {
    int midW = width / 2;
    int midH = height / 2;

    for (int i = -4; i < 6; i++) {
        flipCell(&grid[midH][midW + i]);
    }
}

void geometry(cell **grid, int width, int height) {
    int midW = width / 2;
    int midH = height / 2;

    flipCell(&grid[midH][midW]);
    flipCell(&grid[midH - 1][midW + 1]);
    flipCell(&grid[midH - 1][midW + 2]);
    flipCell(&grid[midH - 1][midW + 3]);
    flipCell(&grid[midH - 1][midW - 2]);
    flipCell(&grid[midH - 1][midW - 3]);
    flipCell(&grid[midH + 1][midW - 2]);
}

//Minimum size is (16, 16)
void butterfly(cell **grid, int width, int height) {
    int midW = width / 2;
    int midH = height / 2;

    flipCell(&grid[midH - 2][midW]);
    flipCell(&grid[midH + 2][midW]);

    for (int i = -2; i < 3; i++) {
        flipCell(&grid[midH + i][midW + 2]);
    }

    for (int i = -2; i < 3; i++) {
        flipCell(&grid[midH + i][midW - 2]);
    }
}

//Starts in top right
void glider(cell **grid, int width, int height) {
    flipCell(&grid[0][width - 2]);
    flipCell(&grid[1][width - 3]);
    flipCell(&grid[2][width - 3]);
    flipCell(&grid[2][width - 2]);
    flipCell(&grid[2][width - 1]);
}

//Minimum size is (35, 20)
void gliderGun(cell **grid, int width, int height) {
    int midW = width / 2;
    int midH = height / 2;

    //Gun
    flipCell(&grid[midH - 4][midW + 16]);
    flipCell(&grid[midH - 5][midW + 16]);
    flipCell(&grid[midH - 4][midW + 17]);
    flipCell(&grid[midH - 5][midW + 17]);

    flipCell(&grid[midH - 2][midW - 17]);
    flipCell(&grid[midH - 3][midW - 17]);
    flipCell(&grid[midH - 2][midW - 18]);
    flipCell(&grid[midH - 3][midW - 18]);

    flipCell(&grid[midH][midW]);
    flipCell(&grid[midH - 1][midW - 1]);
    flipCell(&grid[midH - 1][midW - 2]);
    flipCell(&grid[midH][midW - 2]);
    flipCell(&grid[midH + 1][midW - 2]);

    flipCell(&grid[midH + 7][midW + 6]);
    flipCell(&grid[midH + 7][midW + 7]);
    flipCell(&grid[midH + 7][midW + 8]);
    flipCell(&grid[midH + 8][midW + 6]);
    flipCell(&grid[midH + 9][midW + 7]);

    flipCell(&grid[midH + 2][midW + 17]);
    flipCell(&grid[midH + 2][midW + 18]);
    flipCell(&grid[midH + 3][midW + 17]);
    flipCell(&grid[midH + 3][midW + 19]);
    flipCell(&grid[midH + 4][midW + 17]);

    flipCell(&grid[midH - 3][midW + 4]);
    flipCell(&grid[midH - 4][midW + 4]);
    flipCell(&grid[midH - 3][midW + 5]);
    flipCell(&grid[midH - 5][midW + 5]);
    flipCell(&grid[midH - 4][midW + 6]);
    flipCell(&grid[midH - 5][midW + 6]);

    flipCell(&grid[midH - 3][midW - 8]);
    flipCell(&grid[midH - 2][midW - 8]);
    flipCell(&grid[midH - 3][midW - 9]);
    flipCell(&grid[midH - 1][midW - 9]);
    flipCell(&grid[midH - 2][midW - 10]);
    flipCell(&grid[midH - 1][midW - 10]);

    //Eater
    flipCell(&grid[midH + 23][midW + 27]);
    flipCell(&grid[midH + 23][midW + 28]);
    flipCell(&grid[midH + 24][midW + 27]);
    flipCell(&grid[midH + 24][midW + 29]);
    flipCell(&grid[midH + 25][midW + 29]);
    flipCell(&grid[midH + 26][midW + 29]);
    flipCell(&grid[midH + 26][midW + 30]);
}

void nightSky(cell **grid, int width, int height) {
    int midW = width / 2;
    int midH = height / 2;

    flipCell(&grid[midH][midW]);
    flipCell(&grid[midH - 1][midW]);
    flipCell(&grid[midH - 2][midW]);

    flipCell(&grid[midH - 1][midW + 2]);
    flipCell(&grid[midH - 2][midW + 2]);
    flipCell(&grid[midH - 2][midW + 3]);
    flipCell(&grid[midH - 3][midW + 2]);

    flipCell(&grid[midH + 1][midW - 2]);
    flipCell(&grid[midH + 2][midW - 2]);

    flipCell(&grid[midH + 2][midW - 4]);
}

