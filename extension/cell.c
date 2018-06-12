#include "cell.h"

void flipCell(cell *c) {
    //Change value of cell
    c->s = 1 - c->s;
}

bool alive(cell *c) {
    //Return true if cell is alive
    return c->s == ON;
}