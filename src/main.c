int main (void){
	int board_size;
	
	generate_patterns();	
	
	board_size = select_board_size();
	
	//Initailizing the Board
	char board[board_size][board_size];
	for (int i = 0; i < board_size; i++){
		for (int j = 0; j < board_size; j++){
			board[i][j] = 0;
		}
	}
	display_board(board_size, board);
	
	int p = rand() % 2 + 1;
	
	int winner = 1;
	while(winner){
		player_move(board_size, board, p);
		winner = check_winner(board_size, board, p);
		is_full_board(board_size, board);
		if (p == 1){
			p = 2;
		}
		else{
			p = 1;
		}
	}
			
	return 0;
}
