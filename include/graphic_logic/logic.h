#ifndef GROUP_D_GOMOKU_LOGIC_H
#define GROUP_D_GOMOKU_LOGIC_H

#define ROW 19
#define COL 19

/* Check if stone is overlay. If not, put it. */
int put_stone_logic(float x, float y, int player);

/* Check if there is a winner */
int check_winner(int board_array[ROW][COL], int player);


#endif //GROUP_D_GOMOKU_LOGIC_H
