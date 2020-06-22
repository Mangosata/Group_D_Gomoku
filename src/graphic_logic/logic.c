#include "../../include/graphic_logic/logic.h"
#include <stdio.h>
int board_array[ROW][COL] = {0};
/*
 * Check if stone is overlay. If not, put it.
 * @return: 1 is not overlay, 0 is overlay.
 */
int put_stone_logic(float x, float y, int player) {
    int row, col;
    row = (int) ((x - 100) / 25 + 0.5);
    col = (int) ((y - 100) / 25 + 0.5);

    /*
     * If player 1 is playing, set the value to 1
     * If player 2 is playing, set the value to 2
     */
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
