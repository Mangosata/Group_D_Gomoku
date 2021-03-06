#include "../../include/game_logic/game_logic.h"

extern int BOARD_ARRAY[ROW][COL];

/*
 * Check if stone is overlay. If not, put it.
 * @Return: 1 is not overlay, 0 is overlay.
 * @Description: If player 1 is playing, set the value to 1.
 *               If player 2 is playing, set the value to 2.
 *               If the mouse clicking is not in the board area, do nothing.
 */
int put_stone_logic(float x, float y, int player) {
    int row, col;
    col = (int) ((x - 100) / 25 + 0.5);
    row = (int) ((y - 100) / 25 + 0.5);

    if (BOARD_ARRAY[row][col] == 0 && player == 1) {
        BOARD_ARRAY[row][col] = 1;
        return 1;
    } else if (BOARD_ARRAY[row][col] == 0 && player == 2) {
        BOARD_ARRAY[row][col] = 2;
        return 2;
    } else {
        printf("wrong\n");
        return 0;
    }
}

/*
 * @Input: board_array[ROW][COl]
 * @Return: 1 has a winner, 0 is no winner.
 * @Description: Check if there is a winner.
 *               If there is a winner, it should be last value of PLAYER,
 *               because the value of PLAYER has changed once in draw_stone.
 */
int check_winner(int board_array[ROW][COL]) {

    /*
     * Generating Patterns to check the winner status
     */
    int number_of_patterns = 4;
    int pattern_size = 5;
    int pattern[number_of_patterns][pattern_size][pattern_size];

    /*
     * Pattern 1 -> Vertical (90 degrees)
     */
    for (int i = 0; i < pattern_size; i++) {
        for (int j = 0; j < pattern_size; j++) {
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
    for (int i = 0; i < pattern_size; i++) {
        for (int j = 0; j < pattern_size; j++) {
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
    for (int i = 0; i < pattern_size; i++) {
        for (int j = 0; j < pattern_size; j++) {
            if (i == j) {
                pattern[2][i][j] = 1;
            } else {
                pattern[2][i][j] = 0;
            }
        }
    }

    /*
     * Pattern 4 -> Diagonal (45 degrees)
     */
    for (int i = 0; i < pattern_size; i++) {
        for (int j = 0; j < pattern_size; j++) {
            if (i + j == pattern_size - 1) {
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
    int board_size = 19;
    int board[board_size][board_size];
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board_array[i][j] == 2) {
                board[i][j] = -1;
            } else if (board_array[i][j] == 1) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }


    int winner_array[board_size + pattern_size - 1][board_size + pattern_size - 1];

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
    for (int p = 0; p < number_of_patterns; p++) {
        for (int wi = 0; wi < board_size; wi++) {
            for (int wj = 0; wj < board_size; wj++) {
                for (int pa = 0; pa < pattern_size; pa++) {
                    for (int pb = 0; pb < pattern_size; pb++) {
                        check += winner_array[wi + pa][wj + pb] * pattern[p][pa][pb];
                    }
                }
                if (check == 5 || check == -5) {
                    return 1;
                }
                check = 0;
            }
        }
    }
    return 0;

}
