#include "/cygdrive/C/Users/gshar/Downloads/C Project/check/Group_D_Gomoku/include/game/game.h"
#include "/cygdrive/C/Users/gshar/Downloads/C Project/check/Group_D_Gomoku/include/test/test.h"

int main(void) {

    /*
     * patterns are needed to be generated only once to check the winner
     */
    generate_patterns();

    /*
     * calling the function "select_board_size" to intailize the board size
     */
    int board_size;
    board_size = unit_test_when_board_size_15();
	assert(board_size == 15);

    /*
     * Initailizing the Board with all the elements as 0s
     */
    char board[board_size][board_size];
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            board[i][j] = 0;
        }
    }
    display_board(board_size, board);

    /*
     * Randomly deciding which player will go first
     */
    int p = rand() % 2 + 1;

    /*
     * this function will keep on running until a winner is found
     */
    int winner = 1;
    while (winner) {
        player_move(board_size, board, p);
        winner = check_winner(board_size, board, p);
        is_full_board(board_size, board);
        if (p == 1) {
            p = 2;
        } else {
            p = 1;
        }
    }

    return 0;
}
