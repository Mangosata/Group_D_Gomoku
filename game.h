#ifndef GROUP_D_GOMOKU_GAME_H
#define GROUP_D_GOMOKU_GAME_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <graphics.h>
#pragma comment(lib,"winmm.lib")

#define ROWS 5
#define COLS 5

void initgame();
void initBoard(char board[ROWS][COLS]);
void checkWinner(char board[ROWS][COLS]);
void playerMove(char board[ROWS][COLS], int row, int col);
void computerMove(char board[ROWS][COLS], int row, int col);
char* modeSelect(char* mode);
char* isFullBoard(char board[ROWS][COLS]);

#endif //GROUP_D_GOMOKU_GAME_H
