#include "game/game.h"
#include "test/test.h"
/*
 * It will randomly generate the number between 20 to 100 as the size of board.
 */

int unit_test_when_board_size_greater_than_19(void){
	int nMax = 100;
    int nMin = 20;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	return nRandonNumber;
}