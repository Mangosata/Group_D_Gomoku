#include "../../include/graphic_logic/logic.h"
#include <stdio.h>
int board_array[ROW][COL] = {0};
/*
 * Check if stone is overlay. If not, put it.
 * @return: 1 is not overlay, 0 is overlay.
 */
int put_stone_logic(float x, float y) {
    int row, col;
    row = (int) ((x - 100) / 25 + 0.5);
    col = (int) ((y - 100) / 25 + 0.5);

    if (board_array[row][col] == 0) {
        board_array[row][col] = 1;
        return 1;
    } else {
        printf("wrong\n");
        return 0;
    }
}
