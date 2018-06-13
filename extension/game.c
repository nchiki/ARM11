#include <stdlib.h>
#include "game.h"
#include "grid.h"
#include "cell.h"
#include "initial_configs.h"
#include <ncurses.h>
#include <zconf.h>
#include <unistd.h>
#include <memory.h>


//Decide defaults
#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 50
#define MAX_WIDTH 211
#define MAX_HEIGHT 57


void printScreen(cell **board, int width, int height){
    move(0, 0);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printw(symbol(board[i][j]));
        }
        printw("\n");
    }
}

void takeDimensions(int *width, int *height) {
    char input[6];

    //Take initial dimensions
    printw("Please enter the size of your matrix (width, height): ");
    refresh();
    getnstr(input, sizeof(input));

    *width = atoi(strtok(input, ","));
    *height = atoi(strtok(NULL, "\n"));
    clear();

    //If dimensions don't fulfil requirements, ask for re-entry
    while ((*width > MAX_WIDTH || *height > MAX_HEIGHT)) {
        printw("Please enter dimensions <= (211, 57): ");
        refresh();
        getnstr(input, sizeof(input));
        *width = atoi(strtok(input, ","));
        *height = atoi(strtok(NULL, "\n"));
        clear();
    }
}

void printMenu(cell **game, int width, int height) {
    printw("Initial board setup options:\n\n");
    printw("\t1 - Random Configuration\n");
    printw("\t2 - Premade Configuration\n");
    printw("\t3 - User Input\n");
    printw("\nPlease choose an option: ");
    refresh();

    int option;
    scanf("%i", &option);
    clear();

    while (option != 1 && option != 2 && option != 3) {
        printw("Please choose a valid option: ");
        refresh();
        scanf("%i", &option);
        clear();
    }

    switch (option) {
        case 1:
            randomConfig(game, width, height);
            break;
        case 2:
            longLine(game, width, height);
            break;
        case 3:
            //Add user input
            break;
    }

    //Wait for user to press enter
    getchar();
}

int main(int argc, char **argv) {
    initscr();

    int width, height;

    takeDimensions(&width, &height);

    cell** game = {setupGrid(width, height)};

    printMenu(game, width, height);

    printScreen(game, width, height);
    refresh();
    //Wait for user to click before starting
    getchar();

    while(1) {
        evolve(game, width, height);
        printScreen(game, width, height);
        refresh();
        usleep(100000);
    }
}

