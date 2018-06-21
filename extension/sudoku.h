
#ifndef ARM11_28_SUDOKU_H
#define ARM11_28_SUDOKU_H

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <memory.h>


void freeGrid(char **);

int checkSol(char **);

char **matrix_init(char **);

char **change(char **, int, int, char);

void printGrid(char **);
int sudoku_main();

#endif //ARM11_28_SUDOKU_H
