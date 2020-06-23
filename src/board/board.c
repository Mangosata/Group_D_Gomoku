#include "board/board.h"

/*
 * @Parameter: void,
 * @Return: int,
 * @Description: This function is made for the console version where in this function an input will taken from to select the board size.
 * User will have to input "1" if user want to play on 15x15 board or "2" if user want to play on 19x19 board.
 * The returned value is the board size, the function will return 15 or 19 depending upon the user's input.
 */
int select_board_size(void) {
    int board_size, select_board;
    SELECTSIZE:
    printf("Select the Board Size:\nPress 1 to select the 15*15 board\nPress 2 to select the 19*19 board\n\nEnter your Choice: ");
    scanf("%d", &select_board);
    switch (select_board) {
        case 1:
            board_size = 15;
            break;

        case 2:
            board_size = 19;
            break;

        default:
            printf("\nIncorrect input. Try Again...\n\n");
            goto SELECTSIZE;
    }

    printf("\n\n");
    return board_size;
}

/*
 * @Parameter: int board_size, char board[][board_size],
 * @Return: void,
 * @Description: This function is for console version, where the board is displayed in "-", "X" and "O" signs.
 * "-" is representing the empty block
 * "X" is representing the black stone
 * "O" is representing the white stone
 */
void display_board(int board_size, char board[][board_size]) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board[i][j] == 1) {
                printf("X");
            } else if (board[i][j] == -1) {
                printf("O");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    return;
}