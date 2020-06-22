//#include "../../include/game/game.h"
//
//#define PATTERN_SIZE 5
//#define NUMBER_OF_PATTERNS 4
//int pattern [NUMBER_OF_PATTERNS][PATTERN_SIZE][PATTERN_SIZE];
//
//void generate_patterns(void){
//	//Generating Patterns to check the winner status
//	//Pattern 1
//	for (int i = 0; i < PATTERN_SIZE; i++){
//		for (int j = 0; j < PATTERN_SIZE; j++){
//			if ( i == 0 ){
//				pattern[0][i][j] = 1;
//			}
//			else{
//				pattern[0][i][j] = 0;
//			}
//		}
//	}
//	//Pattern 2
//	for (int i = 0; i < PATTERN_SIZE; i++){
//		for (int j = 0; j < PATTERN_SIZE; j++){
//			if ( i == j ){
//				pattern[1][i][j] = 1;
//			}
//			else{
//				pattern[1][i][j] = 0;
//			}
//		}
//	}
//	//Pattern 3
//	for (int i = 0; i < PATTERN_SIZE; i++){
//		for (int j = 0; j < PATTERN_SIZE; j++){
//			if ( j == 0 ){
//				pattern[2][i][j] = 1;
//			}
//			else{
//				pattern[2][i][j] = 0;
//			}
//		}
//	}
//	//Pattern 4
//	for (int i = 0; i < PATTERN_SIZE; i++){
//		for (int j = 0; j < PATTERN_SIZE; j++){
//			if ( i+j == PATTERN_SIZE-1 ){
//				pattern[3][i][j] = 1;
//			}
//			else{
//				pattern[3][i][j] = 0;
//			}
//		}
//	}
//	//Patterns are generated
//}
//
//void display_board(int board_size, char board[][board_size]){
//	for (int i = 0; i < board_size; i++){
//		for (int j = 0; j < board_size; j++){
//			if (board[i][j] == 1){
//			printf("X");
//			}
//			else if (board[i][j] == -1){
//			printf("O");
//			}
//			else{
//			printf("-");
//			}
//		}
//		printf("\n");
//	}
//	return;
//}
//
//int select_board_size(void){
//	int board_size, select_board;
//	SELECTSIZE: printf("Select the Board Size:\nPress 1 to select the 15*15 board\nPress 2 to select the 19*19 board\n\nEnter your Choice: ");
//	scanf("%d", &select_board);
//	switch (select_board){
//		case 1:
//		board_size = 15;
//		break;
//
//		case 2:
//		board_size = 19;
//		break;
//
//		default:
//		printf("\nIncorrect input. Try Again...\n\n");
//		goto SELECTSIZE;
//	}
//
//	printf("\n\n");
//	return board_size;
//}
//
//int update_board(int row, int column, int board_size, char board[][board_size]){
//	if (board[row][column] == 1 || board[row][column] == -1){
//		printf("!! The coordinates has already been used !!\n!! Use different coordinates !!\n");
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
//
//void is_full_board(int board_size, char board[][board_size]){
//	int is_full = 0;
//	for (int i = 0; i < board_size; i++){
//		for (int j = 0; j < board_size; j++){
//			if (board[i][j] != 0)
//				is_full += 1;
//		}
//	}
//
//	if (is_full == board_size*board_size){
//		printf("!!! The board is full !!!\n\tTIE\n");
//		exit(0);
//	}
//}
//
//void player_move(int board_size, char board[][board_size], int player_name){
//	int row, column, update;
//	int player_sign = -1;
//	if (player_name == 1){
//		player_sign = 1;
//	}
//	PLAY_TURN: printf("\n!! Player %d turn!! \n!! Enter the Coordinates !!\n\nRow: ", player_name);
//
//	scanf("%d", &row);
//	printf("Column: ");
//	scanf("%d", &column);
//
//	printf("\n");
//
//	if ( row >= board_size || row < 0 || column >= board_size || column < 0 ){
//		printf("row = %d\ncolumn = %d",row,column);
//		printf("Enter the valid coordinates. \nThat is, Row and Column number should be between 0 and %d\n", board_size-1);
//		goto PLAY_TURN;
//	}
//
//	update = update_board(row, column, board_size, board);
//	if(update){
//		goto PLAY_TURN;
//	}
//
//	board[row][column] = player_sign;
//
//	display_board(board_size, board);
//
//	return;
//}
//
//int check_winner(int board_size, char board[][board_size], int player_name){
//	if (board_size <= 0){
//		printf("!! Incorrect Board Size !!");
//		exit(1);
//	}
//
//	int winner_array[board_size + PATTERN_SIZE - 1][board_size + PATTERN_SIZE - 1];
//
//	memset(winner_array, 0, sizeof(winner_array));
//
//	for (int i = 0; i < board_size; i++){
//		for (int j = 0; j < board_size; j++){
//			winner_array[i][j] = board[i][j];
//		}
//	}
//
//	int check = 0;
//	for (int p = 0; p < NUMBER_OF_PATTERNS; p++){
//		for (int wi = 0; wi < board_size; wi++){
//			for (int wj = 0; wj < board_size; wj++){
//				for (int pi = 0; pi < PATTERN_SIZE; pi++){
//					for (int pj = 0; pj < PATTERN_SIZE; pj++){
//						check += winner_array[wi+pi][wj+pj]*pattern[p][pi][pj];
//					}
//				}
//				if (check == 5 || check == -5){
//					printf("\n!! Player %d is the winner!!\n",player_name);
//					exit(0);
//				}
//				check = 0;
//			}
//		}
//	}
//	return 1;
//}
