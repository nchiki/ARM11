#include <stdlib.h>
#include "game.h"
#include "grid.h"
#include "cell.h"
#include "initial_configs.h"
#include <ncurses.h>
#include <zconf.h>
#include <unistd.h>
#include <memory.h>
#include <stdbool.h>

void printScreen(cell **board, int width, int height){
    move(0, 0);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printw(symbol(board[i][j]));
        }
        printw("\n");
    }
}

void takeDimensions(int *width, int *height, int maxW, int maxH) {
    char input[6];

    //Take initial dimensions
    printw("Please enter the size of your matrix <= (maxW, maxH): ");
    refresh();
    getnstr(input, sizeof(input));

    //Need to fix seg fault on strings entered

    *width = atoi(strtok(input, ","));
    *height = atoi(strtok(NULL, "\n"));
    clear();

    //If dimensions don't fulfil requirements, ask for re-entry
    while ((*width > maxW || *height > maxH)) {
        printw("Please enter dimensions <= (%d, %d): ", maxW, maxH);
        refresh();
        getnstr(input, sizeof(input));
        *width = atoi(strtok(input, ","));
        *height = atoi(strtok(NULL, "\n"));
        clear();
    }
}

//Segmentation fault if grid isn't big enough
void printInitialConfigs(cell **game, int width, int height) {
    //nightSky(game, width, height);
    gliderGun(game, width, height);
    //glider(game, width, height);
    //butterfly(game, width, height);
    //acorn(game, width, height);
    //periodic(game, width, height);
}

void printMenu(cell **game, int width, int height) {
    char option = 'a';

    while (option != '1' && option != '2' && option != '3') {
        printw("Initial board setup options:\n\n");
        printw("\t1 - Random Configuration\n");
        printw("\t2 - Pre-made Configuration\n");
        printw("\t3 - User Input\n");

        printw("\nPlease choose an option between 1 and 3");
        refresh();
        scanf("%c", &option);
        clear();
    }

    switch (atoi((const char *) &option)) {
        case 1:
            randomConfig(game, width, height);
            break;
        case 2:
            printInitialConfigs(game, width, height);
            break;
        case 3:
            //Add user input
            break;
    }
}

bool checkDefault() {
    char answer = 'a';

    while (answer != 'y' && answer != 'n') {
        printw("Would you like to choose the game size? (y or n)");
        refresh();
        scanf("%c", &answer);
        clear();
    }

    if (answer == 'y') {
        //Ask user for sizings
        return false;
    }
    //Use default
    return true;
}

int main(int argc, char **argv) {
    //Initialise screen
    initscr();
    //Hide cursors
    curs_set(0);

    //Find max size of screen
    int maxW, maxH;
    getmaxyx(stdscr, maxH, maxW);
    //Leave a line at the edge
    maxW -= 1;

    int width = maxW, height = maxH;

    //Allow use to choose size
    if (!checkDefault()) {
        takeDimensions(&width, &height, maxW, maxH);
    }

    //Setup the grid
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
        //CHANGE SLEEP TIME WITH TICK VARIABLE
        usleep(100000);
    }
}

