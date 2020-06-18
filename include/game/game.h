/*
 * This header file declares game logic functions and related macro definitions.
 * player_move, check_winner declarations in this file.
 */

#ifndef GROUP_D_GOMOKU_GAME_H
#define GROUP_D_GOMOKU_GAME_H

#include <string.h>
#include <time.h>
#include <stdlib.h>

//void initGame(int BoardSize);
//void initBoard(char board[ROWS][COLS]);
//void checkWinner(char board[ROWS][COLS]);
//void playerMove(char board[ROWS][COLS], int row, int col);
//void computerMove(char board[ROWS][COLS], int row, int col);
//char* modeSelect(char* mode);
//char* isFullBoard(char board[ROWS][COLS]);

void player_move(int board_size, char board[][board_size], int player_name);
int check_winner(int board_size, char board[][board_size], int player_name);


#endif //GROUP_D_GOMOKU_GAME_H
