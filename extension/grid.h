#ifndef ARM11_28_GRID_H
#define ARM11_28_GRID_H

typedef struct {
    cell **board;
} screen;

cell **setupGrid(int, int);

void evolve(screen, int, int);

void evaluateCell(cell *, int, int);

#endif //ARM11_28_GRID_H
