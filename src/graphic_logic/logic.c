#include "../../include/graphic_logic/logic.h"
#include <stdio.h>

/* Use an array to store the board status */
int board_array[ROW][COL] = {0};

/*
 * Check if stone is overlay. If not, put it.
 * @Return: 1 is not overlay, 0 is overlay.
 *
 * If player 1 is playing, set the value to 1
 * If player 2 is playing, set the value to 2
 * If the mouse clicking is not in the board area, do nothing.
 */

int put_stone_logic(float x, float y, int player) {
    int row, col;
    row = (int) ((x - 100) / 25 + 0.5);
    col = (int) ((y - 100) / 25 + 0.5);

    if (board_array[row][col] == 0 && player == 0) {
        board_array[row][col] = 1;
        printf("player 1 %d\n", board_array[row][col]);
        return 1;
    } else if (board_array[row][col] == 0 && player == 1) {
        board_array[row][col] = 2;
        printf("player 2 %d\n", board_array[row][col]);
        return 2;
    } else {
        printf("wrong\n");
        return 0;
    }
}

/*
 * Todo: check winner function
 * @Input: board_array[ROW][COl], player
 * @Return: 1 is win, 0 is no winner.
 */
int check_winner(int board_array[ROW][COL], int player) {
    ;
}
