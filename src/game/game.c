#include "../../include/game/game.h"

void playerMove(int board_size, char board[][board_size], int player_name)
{
	int row, column, update;
	int player_sign = -1;
	if (player_name == 1)
		player_sign = 1;	
	PLAY_TURN: printf("\n!! Player %d turn!! \n!! Enter the Coordinates !!\n\nRow: ", player_name);
	
	scanf("%d", &row);
	printf("Column: ");
	scanf("%d", &column);
	
	printf("\n");
	
	if ( row >= board_size || row < 0 || column >= board_size || column < 0 )
	{
		printf("row = %d\ncolumn = %d",row,column);
		printf("Enter the valid coordinates. \nThat is, Row and Column number should be between 0 and %d\n", board_size-1);
		goto PLAY_TURN;
	}
	
	update = updateBoard(row, column, board_size, board);
	if(update)
	{	goto PLAY_TURN;}
	
	board[row][column] = player_sign;
	
	displayBoard(board_size, board);
	
	return;
}

/*
 * Todo: implement player_move and complete the description for this function, after completed, please delete todo.
 * @Author: Tingyu Ye,
 * @Parameter: int board_size, char board[][board_size], int player_name,
 * @Return: ?,
 * @Description:
 */
int check_winner(int board_size, char board[][board_size], int player_name) {
    ;
}
