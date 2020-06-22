#include "../../include/game_logic/game_logic.h"

/* Use an array to store the board status */
int board_array[ROW][COL] = {0};

/*
 * Check if stone is overlay. If not, put it.
 * @Return: 1 is not overlay, 0 is overlay.
 *
 * If player 1 is playing, set the value to 1
 * If player 2 is playing, set the value to 2
 * If the mouse clicking is not in the board area, do nothing.
 */

int put_stone_logic(float x, float y, int player) {
    int row, col;
    row = (int) ((x - 100) / 25 + 0.5);
    col = (int) ((y - 100) / 25 + 0.5);

    if (board_array[row][col] == 0 && player == 0) {
        board_array[row][col] = 1;
        printf("player 1 %d\n", board_array[row][col]);
        return 1;
    } else if (board_array[row][col] == 0 && player == 1) {
        board_array[row][col] = 2;
        printf("player 2 %d\n", board_array[row][col]);
        return 2;
    } else {
        printf("wrong\n");
        return 0;
    }
}

/*
 * Todo: check winner function
 * @Input: board_array[ROW][COl], player
 * @Return: 1 is win, 0 is no winner.
 */
int check_winner(int board_array[ROW][COL], int player) {
	
	/*
	 * Generating Patterns to check the winner status
	 */
	int number_of_patterns = 4;
	int pattern_size = 5;
	int pattern [number_of_patterns][pattern_size][pattern_size];
	
	/*
     * Pattern 1 -> Vertical (90 degrees)
     */
    for (int i = 0; i < PATTERN_SIZE; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            if (i == 0) {
                pattern[0][i][j] = 1;
            } else {
                pattern[0][i][j] = 0;
            }
        }
    }

    /*
     * Pattern 2 ->  Horizontal (0 degrees)
     */
    for (int i = 0; i < PATTERN_SIZE; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            if (j == 0) {
                pattern[1][i][j] = 1;
            } else {
                pattern[1][i][j] = 0;
            }
        }
    }

    /*
     * Pattern 3 -> Diagonal (135 degrees)
     */
    for (int i = 0; i < PATTERN_SIZE; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            if (i == j) {
                pattern[2][i][j] = 1;
            } else {
                pattern[2][i][j] = 0;
            }
        }
    }

    /*
     * Pattern 4 -> Diagonal (145 degrees)
     */
    for (int i = 0; i < PATTERN_SIZE; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            if (i + j == PATTERN_SIZE - 1) {
                pattern[3][i][j] = 1;
            } else {
                pattern[3][i][j] = 0;
            }
        }
    }
	
    /*
     * Creating an array named "winner_array" to store all the elements of board and extend it by PATTERN_SIZE - 1
     * to implement the pattern multiplication to get the winner status
     */
	board_size = COL;
	int board[board_size][board_size];
	for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
			if (board_array[i][j] == 2){
            board[i][j] = -1;
			}
        }
    }
	
    int winner_array[board_size + PATTERN_SIZE - 1][board_size + PATTERN_SIZE - 1];

    /*
     * memset() will give the same value to all the elements of the winner_array
     */
    memset(winner_array, 0, sizeof(winner_array));

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            winner_array[i][j] = board[i][j];
        }
    }

    int check = 0;
    for (int p = 0; p < NUMBER_OF_PATTERNS; p++) {
        for (int wi = 0; wi < board_size; wi++) {
            for (int wj = 0; wj < board_size; wj++) {
                for (int pi = 0; pi < PATTERN_SIZE; pi++) {
                    for (int pj = 0; pj < PATTERN_SIZE; pj++) {
                        check += winner_array[wi + pi][wj + pj] * pattern[p][pi][pj];
                    }
                }
                if (check == 5 || check == -5) {
					printf("\n!! PLAYER %d is the WINNER!!",player);
					return 1;
		    
		    }
                }
                check = 0;
            }
        }
    }
    return 0;
}
