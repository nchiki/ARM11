#include "minesweeper.h"
#include <ncurses.h>

char **generateField(int width, int height) {
char **field;
field = (char **) malloc(width * sizeof(char *));
if (!field) { return NULL;} //failed

for (int i = 0; i < width; i++) {
  field[i] = (char *) malloc(height * sizeof(char));//allocates each cell
  if(!field[i]) {
    return NULL;
  }
}
printf("Generating minefield...");
return field;
}

//frees the grid
void freeField(int width, int height, char** minefield) {
  for (int i = 0; i < width; i++) {
    free(minefield[i]);
  }
  free(minefield);
}

void placeMines(char **minefield, int width, int height, int mines) {
  int placed = 0;
  while(placed < mines) {
    srand(width);
    int x = rand(); // a number between 0 and mWidth - 1
    srand(height);
    int y = rand();
    // make sure we don't place a mine on top of another
    if(minefield[y][x] != '*') {
      minefield[y][x] = '*';
      placed++;
    }
  }
  printf("\n Mines placed");
}

void clearField(char **minefield, int width, int height) {
    // Set every grid space to a space character.
    for(int y = 0; y < height; y++) {
      for(int x = 0; x < width; x++) {
        minefield[y][x] = ' ';
      }
    }
}

void drawField(char **minefield, int width, int height) {
    for(int y = 0; y < height; y++) {
      for(int x = 0; x < width; x++) {
        printf("%c", minefield[y][x]);
      }
      printf("\n");
    }
}

void calculateHints(char **minefield, int width, int height) {
    for(int y = 0; y < height; y++) {
      for(int x = 0; x < width; x++) {
        if(minefield[y][x] != '*') {
          minefield[y][x] = minesNear(y, x, width, height, minefield);
        }
      }
    }
}

char minesNear(int y, int x, int width, int height, char **minefield) {
    int mines = 0;
    // check mines in all directions
    mines += mineAt(y - 1, x - 1, width, height, minefield);  // NW
    mines += mineAt(y - 1, x, width, height, minefield);      // N
    mines += mineAt(y - 1, x + 1, width, height, minefield);  // NE
    mines += mineAt(y, x - 1, width, height, minefield);      // W
    mines += mineAt(y, x + 1, width, height, minefield);      // E
    mines += mineAt(y + 1, x - 1, width, height, minefield);  // SW
    mines += mineAt(y + 1, x, width, height, minefield);      // S
    mines += mineAt(y + 1, x + 1, width, height, minefield);  // SE
    if(mines > 0) {
      return (char)(mines + 48); //converts to char representing an int (ASCII)
    } else {
      return ' ';
    }
}

int mineAt(int y, int x, int width, int height, char **minefield) {
   // we need to check also that we're not out of array bounds as that would
   // be an error
   if(y >= 0 && y < height && x >= 0 && x < width && minefield[y][x] == '*') {
     return 1;
   } else {
     return 0;
   }
 }


void minesweeper(int width, int height) {
int option = 200;
int Mwidth = width;
int Mheight = height;
int mMines;
printw("\n Please enter the number of mines you want: ");
refresh();
char *answer;
getnstr(answer, sizeof(&option)); // gets the number typed by the player
mMines = atoi(answer);
char **minefield = generateField(width, height);//generates the grid
clearField(minefield, Mwidth, Mheight); //sets an empty grid
placeMines(minefield, Mwidth, Mheight, mMines); //places the mines
drawField(minefield, Mwidth, Mheight);//draws the grid
calculateHints(minefield, Mwidth, Mheight);
freeField(width, height, minefield);//frees allocated space
}
