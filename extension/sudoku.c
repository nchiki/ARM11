#include "sudoku.h"

char **current;

char initial [9][9]= {
        {' ', ' ', ' ', '2', '6', ' ', '7', ' ', '1'},
        {'6', '8', ' ', ' ', '7', ' ', ' ', '9', ' '},
        {'1', '9', ' ', ' ', ' ', '4', '5', ' ', ' '},
        {'8', '2', ' ', '1', ' ', ' ', ' ', '4', ' '},
        {' ', ' ', '4', '6', ' ', '2', '9', ' ', ' '},
        {' ', '5', ' ', ' ', ' ', '3', ' ', '2', '8'},
        {' ', ' ', '9', '3', ' ', ' ', ' ', '7', '4'},
        {' ', '4', ' ', ' ', '5', ' ', ' ', '3', '6'},
        {'7', ' ', '3', ' ', '1', '8', ' ', ' ', ' '}
};

char solution [9][9] = {
        {'4', '3', '5', '2', '6', '9', '7', '8', '1'},
        {'6', '8', '2', '5', '7', '1', '4', '9', '3'},
        {'1', '9', '7', '8', '3', '4', '5', '6', '2'},
        {'8', '2', '6', '1', '9', '5', '3', '4', '7'},
        {'3', '7', '4', '6', '8', '2', '9', '1', '5'},
        {'9', '5', '1', '7', '4', '3', '6', '2', '8'},
        {'5', '1', '9', '3', '2', '6', '8', '7', '4'},
        {'2', '4', '8', '9', '5', '7', '1', '3', '6'},
        {'7', '6', '3', '4', '1', '8', '2', '5', '9'}
};

int checkSol(char **matrix){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ( matrix[i][j] != solution[i][j]) {
                printw("Your solution is not correct.");
                return 0;
            }
        }

    }
    printw("Congratulations, your solution is correct!");
    return 1;
}

char **matrix_init(char **matrix) {
    char **newMatrix = (char **) malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++) {
        newMatrix[i] = (char *) malloc(3 * sizeof(char));
        for (int j = 0; j < 3; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    return newMatrix;
}

char **change(char **matrix, int x, int y, char number){
    char **matrix2 = matrix_init(matrix);
    matrix2[x][y] = number;
    return matrix2;
}

void printGrid(char matrix[][9]) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            char value = matrix[i][j];
            printw("%s", value);
            printw("|");
        }
        printw("-----------------------");
        printw("\n");
    }
}

int runSudoku(void) {
    printGrid(initial);

    current = matrix_init((char **) initial);
    while (1) {
        char input[6];

        //Take initial dimensions
        printw("Put in the coordinates of the cell that you want to fill: ");
        refresh();
        getnstr(input, sizeof(input));

        //Take first input outside loop because of strtok params
        int x = atoi(strtok(input, ","));
        int y = atoi(strtok(NULL, " "));

        char number;

        //Take initial dimensions
        printw("Which value should be put in the cell? ");
        refresh();
        //Check
        getnstr(&number, sizeof(number));

        char **newInitial = change(current, x, y, number);

        char inp[1];
        printw("Do you want to continue or stop and check if you are right?[y/n]");
        refresh();
        getnstr(inp, sizeof(inp));

        if(inp[0] == 'y'){
            checkSol(newInitial);
            break;
        }

        current = newInitial;
    }
    return 0;
}

