#include "game/game.h"
#include "test/test.h"

/* 
 * PATTERN_SIZE defines the number of elements in a straight line required to win the game 
 */
#define PATTERN_SIZE 5

/* 
 * NUMBER_OF_PATTERNS defines the number of total patterns in which a player can win.  
 */
#define NUMBER_OF_PATTERNS 4

/* 
 * the pattern array is defined as a global variable because it will consume more resources
 * if it will generate the arrays every time while using the winner function
 */
int pattern[NUMBER_OF_PATTERNS][PATTERN_SIZE][PATTERN_SIZE];

/*
 * @Parameter: float,
 * @Return: void,
 * @Description: It creates a delay in seconds.
 */
void delay(float number_of_seconds){ 
    /*
     * Converting time into milli_seconds
     */
    int milli_seconds = 1000 * number_of_seconds; 
    /*
     * Storing start time
     */  
    clock_t start_time = clock(); 
    /*
     * looping till required time is not achieved
     */  
    while (clock() < start_time + milli_seconds) 
        ; 
} 

/*
 * @Parameter: void,
 * @Return: void,
 * @Description: This function will generate the 4 different patterns that will be used for checking the status of victory.
 * In the game of Gomoku, a player can win if he/she has 5 same color stones in any of the below 4 cases:
 * 1. Vertical 		(90 degrees)
 * 2. Horizontal	(0 degrees)
 * 3. Diagonal 		(45 degrees)
 * 4. Diagonal 		(135 degrees)
 */

void generate_patterns(void) {

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
     * Pattern 4 -> Diagonal (45 degrees)
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
}


/*
 * @Parameter: int row, int column, int board_size, char board[][board_size],
 * @Return: int,
 * @Description: This function is used to check if the coordinated are used before or not. This function returns an integer
 * if the returned integer is 1, the permission to update the board coordinate's value will be declined. 
 * Otherwise if the returned integer is 1, the permission to update the board coordinate's value will be granted.
 */
int update_board(int row, int column, int board_size, char board[][board_size]) {
    if (board[row][column] == 1 || board[row][column] == -1) {
        printf("!! The coordinates has already been used !!\n!! Use different coordinates !!\n");
        return 1;
    } else {
        return 0;
    }
}

/*
 * @Parameter: int board_size, char board[][board_size],
 * @Return: void,
 * @Description: This function will check if all the spaces on the board are filled. 
 * In the case all the spaces are filled, the function will declare the match as a TIE.
 */
void is_full_board(int board_size, char board[][board_size]) {
    int is_full = 0;
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board[i][j] != 0)
                is_full += 1;
        }
    }

    if (is_full == board_size * board_size) {
        printf("!!! The board is full !!!\n\tTIE\n This window will close in 10 seconds!");
		delay(10);
        exit(0);
    }
}

/*
 * @Parameter: int board_size, char board[][board_size], int player_name,
 * @Return: void,
 * @Description: This function will take coordinates' value (i.e. row number and column number) from the user
 * and check if the inputted coordinates are within defined range or not.
 * After that it will call update_board () to check if the coordinated are already occupied or not.
 */
void player_move(int board_size, char board[][board_size], int player_name) {
    int row, column, update;
    int player_sign = -1;
    if (player_name == 1) {
        player_sign = 1;
    }
    PLAY_TURN:
    printf("\n!! Player %d turn!! \n!! Enter the Coordinates !!\n\nRow: ", player_name);

    scanf("%d", &row);
    printf("Column: ");
    scanf("%d", &column);

    printf("\n");

    if (row >= board_size || row < 0 || column >= board_size || column < 0) {
        printf("row = %d\ncolumn = %d", row, column);
        printf("Enter the valid coordinates. \nThat is, Row and Column number should be between 0 and %d\n",
               board_size - 1);
        goto PLAY_TURN;
    }

    update = update_board(row, column, board_size, board);
    if (update) {
        goto PLAY_TURN;
    }

    board[row][column] = player_sign;

    display_board(board_size, board);

    return;
}

/*
 * @Parameter: int board_size, char board[][board_size], int player_name,
 * @Return: int,
 * @Description: After every turn, this function will check if there are similar numbers (representing the similar color stones) 
 * are in a straight line vertically or horizontally or diagonally. If there is a straight line, it will print the winner's name.
 */

int check_winner(int board_size, char board[][board_size], int player_name) {

    /*
     * Creating an array named "winner_array" to store all the elements of board and extend it by PATTERN_SIZE - 1
     * to implement the pattern multiplication to get the winner status
     */
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
                    printf("\n!! Player %d is the winner!!\n", player_name);
                    delay(3);
                    exit(0);
                }
                check = 0;
            }
        }
    }
    return 1;
}
