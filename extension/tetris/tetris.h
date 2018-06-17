#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <fcntl.h>
#include "block.h"

#ifndef ARM11_28_TETRIS_H
#define ARM11_28_TETRIS_H

#define TETRIS_PIECES (sizeof(blocks)/sizeof(struct block))
#define LEVELS (sizeof(levels)/sizeof(struct level))


struct level {
    int score;
    int sec;
};

struct game {
    char **board;
    int width;
    int height;
    int level;
    int gameover;
    int score;
    struct block current;
    struct location loc;
};

struct game *game_init(struct game *, int, int);

void set_config();
void clean(struct game *);

void block_init(struct game *);

void printBlock(struct game *);
void rotate(struct game *);

void print(struct game *);

int hits(struct game *);

void gravity(struct game *);
void fall(struct game *, int);

void check_lines(struct game *);

int t_level(struct game *);

void t_cleanup();

void t_clean(struct game *);

void t_run(int, int);

#endif //ARM11_28_TETRIS_H
