//
// Created by bin jia on 2020/5/30.
//

#include "game.h"

void initBoard(char board[ROWS][COLS]) {
    int i, j;

    for (i = 0; i <= ROWS; i++) {
        for (j = 0; j <= COLS; j++) {
            if (0 == i) {
                printf("%3d", j);
            } else if (j == 0) {
                printf("%3d", i);
            } else if (1 == board[i][j]) {
                printf(" X");
            } else {
                printf(" *");
            }
        }
        printf("\n");
    }
}

/* Todo: checkWinner
 * Assignee: Tingye Yu
 * */
void checkWinner(char board[ROWS][COLS]) {
    ;
}


/* Todo: playerMove
 * Assignee: Bin Jia
 *
 * */
void playerMove(char board[ROWS][COLS], int row, int col) {
    ;
}

/* Todo: isFullBoard
 * Assignee: Hongzhi Zhang
 *
 */
char* isFullBoard(char board[ROWS][COLS]) {
    ;
}