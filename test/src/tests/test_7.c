#include "game/game.h"
#include "test/test.h"
/*
 * It will randomly generate the number between 1 to 14 as the size of board.
 */

int unit_test_when_board_size_btw_1_and_14(void){
	int nMax = 14;
    int nMin = 1;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	return nRandonNumber;
}