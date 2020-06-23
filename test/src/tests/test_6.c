#include "game/game.h"
#include "test/test.h"
/*
 * It will randomly generate the number between 16 to 18 as the size of board.
 */

int unit_test_when_board_size_btw_16_and_18(void){
	int nMax = 18;
    int nMin = 16;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	return nRandonNumber;
}