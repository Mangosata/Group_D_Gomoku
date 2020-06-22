#ifndef GROUP_D_GOMOKU_GAME_LOGIC_H
#define GROUP_D_GOMOKU_GAME_LOGIC_H



#include <stdio.h>
#include <string.h>
#include "../graphic/graphic.h"

/* Use an array to store the board status */


/* Check if stone is overlay. If not, put it. */
int put_stone_logic(float x, float y, int player);

/* Check if there is a winner */
int check_winner(int board_array[ROW][COL], int player, gpointer label);

int check_player_win(int player);


#endif //GROUP_D_GOMOKU_GAME_LOGIC_H
