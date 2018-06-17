#include "util.h"


void printGame(struct game *tet){
    int x,y;
    for (x = 0; x < 30; x++)
        printf("\n");
    printf("[LEVEL: %d | SCORE: %d]\n", tet->level, tet->score);
    for (x=0; x<2*tet->width+2; x++)
        printf("~");
    printf("\n");
    for (y = 0; y < tet->height; y++) {
        printf ("!");
        for (x=0; x<tet->width; x++) {
            if (x >= tet->loc.x && y >= tet->loc.y
                && x < (tet->loc.x + tet->current.width) && y < (tet->loc.y+tet->current.height)
                && tet->current.content[y-tet->loc.y][x-tet->loc.x]!=' ')
                printf("%c ", tet->current.content[y-tet->loc.y][x-tet->loc.x]);
            else
                printf("%c ", tet->board[x][y]);
        }
        printf ("!\n");
    }
    for (x = 0; x < 2 * tet->width + 2; x++)
        printf("~");
    printf("\n");
}
