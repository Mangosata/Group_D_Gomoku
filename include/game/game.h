/*
 * This header file declares game logic functions and related macro definitions.
 * player_move, check_winner declarations in this file.
 */

#ifndef GROUP_D_GOMOKU_GAME_H
#define GROUP_D_GOMOKU_GAME_H

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../include/board/board.h"

void delay(float);

void generate_patterns(void);

int update_board(int row, int column, int board_size, char board[][board_size]);

void is_full_board(int board_size, char board[][board_size]);

void player_move(int board_size, char board[][board_size], int player_name);

int check_winner(int board_size, char board[][board_size], int player_name);


#endif //GROUP_D_GOMOKU_GAME_H
