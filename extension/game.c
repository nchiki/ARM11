#include "game.h"
#include "grid.h"
#include "cell.h"

//Decide defaults
#define DEFAULT_WIDTH 50
#define DEFAULT_HEIGHT 100

int main(int argc, char **argv) {
    screen game;
    int width = DEFAULT_WIDTH;
    int height = DEFAULT_HEIGHT;

    if (argc == 4) {
        int width = atoi(argv[2]);
        int height = atoi(argv[3]);
    }

    game = setupGrid(width, height);
    while(1) {
        evolve(game, width, height);
    }
}
