#include <time.h>

#ifndef ARM11_28_BOARD_H
#define ARM11_28_BOARD_H

struct block {
    char content[5][5];
    int width;
    int height;
};

struct location{
    int x;
    int y;
};

struct block blocks[] =
        {
                {{"##",
                         "##"},
                        2, 2
                },
                {{" X ",
                         "XXX"},
                        3, 2
                },
                {{"@@@@"},
                        4, 1},
                {{"OO",
                         "O ",
                         "O "},
                        2, 3},
                {{"&&",
                         " &",
                         " &"},
                        2, 3},
                {{"ZZ ",
                         " ZZ"},
                        3, 2}
        };

#endif //ARM11_28_BOARD_H
