#ifndef ARM11_28_MINESWEEPER_H
#define ARM11_28_MINESWEEPER_H
#include <stdlib.h>
#include <stdio.h>

char **generateField(int, int);
void freeField(int, int, char**);
void placeMines(char **, int, int, int);

void clearField(char **, int, int);
void drawField(char **, int, int);
void calculateHints(char **, int, int);
char minesNear(int, int, int, int, char **);

int mineAt(int, int, int, int, char **);


void minesweeper(int, int);

#endif
