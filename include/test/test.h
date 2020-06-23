/*
 * This header file declares test functions and related macro definitions.
 */

#ifndef GROUP_D_GOMOKU_TEST_H
#define GROUP_D_GOMOKU_TEST_H

#include "../../include/board/board.h"
#include "../../include/game/game.h"

int unit_test_select_board_size(void);
int unit_test_check_winner(int);
int unit_test_player_move(void);
int unit_test_when_board_size_19(void);
int unit_test_when_board_size_15(void);
int unit_test_when_board_size_btw_16_and_18(void);
int unit_test_when_board_size_btw_1_and_14(void);
int unit_test_when_board_size_greater_than_19(void);
int unit_test_when_board_size_less_than_0(void);

#endif //GROUP_D_GOMOKU_TEST_H
