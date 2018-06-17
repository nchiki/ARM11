#include "tetris.h"


struct termios save;
struct level levels[]=
        {
                {0,
                        1200000},
                {1500,
                        900000},
                {8000,
                        700000},
                {20000,
                        500000},
                {40000,
                        400000},
                {75000,
                        300000},
                {100000,
                        200000}
        };


struct game *game_init(struct game *t, int w, int h){
    t->width = w;
    t->height = h;
    t->score = 0;
    t->level = 1;
    t->gameover = 0;
    t->board = malloc(sizeof(char *) *w);
    for(int x = 0; x < w; x++){
        t->board[x] = malloc(sizeof(char) *h);
        for(int y = 0; y < h; y++){
            t->board[x][y] = ' ';
        }
    }
    return t;
}
void block_init(struct game *t){
    t->current = blocks[random()%TETRIS_PIECES];
    t->loc.x = (t->width / 2) - (t->current.width / 2);
    t->loc.y = 0;
    if(hits(t)){
        t->gameover = 1;
    }
}

void printBlock(struct game *t){
    struct block b = t->current;
    for(int x = 0; x < b.width; x++){
        for(int y = 0; y < b.height; y++){
            if(b.content[y][x] != ' '){
                t->board[t->loc.x + x][t->loc.y + y] = b.content[y][x];
            }
        }
    }
}

void rotate(struct game *t){
    struct block b = t->current;
    struct block s = b;
    b.width = s.height;
    b.height = s.width;
    for(int x = 0; x < s.width; x++){
        for(int y = 0; y < s.height; y++){
            b.content[x][y] = s.content[s.height - y - 1][x];
        }
    }
    int x = t->loc.x;
    int y = t->loc.y;
    t->loc.x -= (b.width - s.width) / 2;
    t->loc.y -= (b.height - s.height) / 2;
    t->current = b;
    if(hits(t)){
        t->current = s;
        t->loc.x = x;
        t->loc.y = y;
    }
}

void set_config(){
    struct termios custom;
    int fd = fileno(stdin);
    tcgetattr(fd, &save);
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
}

void clean(struct game *t){
    for(int x = 0; x < t->width; x++){
        free(t->board[x]);
    }
    free(t->board);
}

void print(struct game *t){
    for(int x = 0; x < 30; x++) {
        printf("\n");
    }
    printf("[LEVEL: %d | SCORE: %d]\n", t->level, t->score);
    for(int x = 0; x < 2 * t->width + 2; x++){
        printf("~");
    }
    printf("\n");
    for(int y = 0; y < t->height; y++){
        printf("!");
        for(int x = 0; x <t->width; x++){
            if(x >= t->loc.x && y >= t->loc.y && x < (t->loc.x + t->current.width) && y < (t->loc.y + t->current.height)
                && t->current.content[y - t->loc.y][x - t->loc.x] != ' '){
                printf("%c ", t->current.content[y - t->loc.y][x - t->loc.x]);
            } else {
                printf("%c ", t->board[x][y]);
            }
            printf("!\n");
        }
        for(int x = 0; x < 2 * t->width + 2; x++){
            printf("~");
        }

    }
    printf("\n");
}

int hits(struct game *t){
    int X, Y;
    struct block b = t->current;
    for(int x = 0; x < b.width; x++){
        for( int y = 0; y < b.height; y++){
            X = t->loc.x + x;
            Y = t->loc.y + y;
            if(X < 0 || X > t->width){
                return 1;
            }
            if(b.content[y][x] != ' '){
                if((Y >= t->height) || (X >= 0 && X < t->width && Y >= 0 && t->board[X][Y] != ' ')){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void gravity(struct game *t){
    t->loc.y++;
    if(hits(t)){
        t->loc.y--;
        printBlock(t);
        block_init(t);
    }
}

void fall(struct game *t, int l){
    for (int y = 1; y > 0; y--){
        for(int x = 0; x < t->width; x++){
            t->board[x][y] = t->board[x][y-1];
        }
    }
    for(int x = 0; x < t->width; x++){
        t->board[x][0] = ' ';
    }
}

void check_lines(struct game *t){
    int p = 100;
    int l;
    for(int y = t->height - 1; y >= 0; y--){
        l = 1;
        for(int x = 0; x < t->width && l; x++){
           if(t->board[x][y] == ' '){
               l = 0;
           }
        }
        if(l){
            t->score += p;
            p *= 2;

        }
    }
}

int t_level(struct game *t){
    for(int i = 0; i < LEVELS; i++){
        if(t->score >= levels[i].score){
            t->level = i+1;
        } else {
            break;
        }
    }
    return levels[t->level-1].sec;
}

void t_cleanup(){
    tcsetattr(fileno(stdin), TCSANOW, &save);
}

void t_clean(struct game *t){
    for(int x = 0; x < t->width; x++){
        free(t->board[x]);
    }
    free(t->board);
}

void t_run(int width, int height){
    struct timespec tm;
    struct game t;
    char cmd;
    int count = 0;
    set_config();
    game_init(&t, width, height);
    srand(time(NULL));

    tm.tv_sec = 0;
    tm.tv_nsec = 1000000;

    block_init(&t);
    while(!t.gameover){
        nanosleep(&tm, NULL);
        count++;
        if(count%50 == 0){
            print(&t);
        }
        if(count%350 == 0){
            gravity(&t);
            check_lines(&t);
        }
        while((cmd = getchar()) > 0){
            switch(cmd){
                case 'q':
                    t.loc.x--;
                    if(hits(&t)) {
                        t.loc.x++;
                    }
                    break;
                case 'd':
                    t.loc.x++;
                    if(hits(&t)){
                        t.loc.x--;
                    }
                    break;
                case 's':
                    gravity(&t);
                    break;
                case ' ':
                    rotate(&t);
                    break;
            }
        }
        tm.tv_nsec = t_level(&t);
    }
    print(&t);
    printf("GAME OVER \n");
    t_clean(&t);
    t_cleanup();
}

