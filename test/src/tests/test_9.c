#include "game/game.h"
#include "test/test.h"
/*
 * It will randomly generate the number between -100 to 0 as the size of board.
 */

int unit_test_when_board_size_less_than_0(void){
	int nMax = 0;
    int nMin = -100;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	return nRandonNumber;
}