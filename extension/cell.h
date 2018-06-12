#ifndef ARM11_28_CELL_H
#define ARM11_28_CELL_H

enum status{ON, OFF};

typedef struct{
    enum status s;
} cell;

void flipCell(cell *);

bool alive(cell *);

#endif //ARM11_28_CELL_H
