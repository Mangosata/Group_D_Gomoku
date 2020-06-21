/*
 * This header file declares board functions and related macro definitions.
 * select_board_size, display_board declarations in this file.
 */

#ifndef GROUP_D_GOMOKU_BOARD_H
#define GROUP_D_GOMOKU_BOARD_H

#include <stdio.h>

void display_board(int board_size, char board[][board_size]);

int select_board_size(void);


#endif //GROUP_D_GOMOKU_BOARD_H
