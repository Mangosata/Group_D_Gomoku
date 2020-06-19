#include <stdio.h>
#include "../include/game/game.h"


int main(void) {
	int board_size;
	
	generatePatterns();	
	
	board_size = selectBoardSize();
	
	/*Initailizing the Board*/
	char board[board_size][board_size];
	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
			board[i][j] = 0;
	displayBoard(board_size, board);
	
	int winner = 0;
	while(winner == 0)
	{
		playerMove(board_size, board, 1);
		winner = checkWinner(board_size, board, 1);
		isFullBoard(board_size, board);
		playerMove(board_size, board, 2);
		winner = checkWinner(board_size, board, 2);
		isFullBoard(board_size, board);
	}
			
    return 0;
}