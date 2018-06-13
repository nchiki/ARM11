#include <stdlib.h>
#include "game.h"
#include "grid.h"
#include "cell.h"
#include <ncurses.h>
#include <zconf.h>
#include <unistd.h>
#include <memory.h>


//Decide defaults
#define DEFAULT_WIDTH 50
#define DEFAULT_HEIGHT 100


void printScreen(cell **board, int width, int height){
    move(0, 0);
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            printw(symbol(board[i][j]));
        }
        printw("\n");
    }
}

int main(int argc, char **argv) {

    char size_mat[6];

    initscr();
    (void) echo;

    addstr("Please enter the size of your matrix (height, width)> ");
    refresh();
    getnstr(size_mat, sizeof(size_mat)-1);

    int width = atoi(strtok(size_mat,","));
    int height = atoi(strtok(NULL,"\n"));


    clear();

    cell** game = {setupGrid(width, height)};
    flipCell(&game[5][10]);
    flipCell(&game[5][11]);
    flipCell(&game[5][12]);
    flipCell(&game[5][13]);
    flipCell(&game[5][14]);
    flipCell(&game[5][15]);
    flipCell(&game[5][16]);
    flipCell(&game[5][17]);
    flipCell(&game[5][18]);
    flipCell(&game[5][19]);

    printScreen(game, width, height);
    refresh();
    getchar();

    while(1) {
            evolve(game, width, height);
            printScreen(game, width, height);
            refresh();
            usleep(100000);
    }
}