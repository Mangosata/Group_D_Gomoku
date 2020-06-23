#include "game/game.h"
#include "test/test.h"
/*
 * It will randomly generate the number between 0 to board_size - 1.
 */

int unit_test_check_winner(int board_size){
    int nMax = board_size - 1;
    int nMin = 0;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	printf("%d\n",nRandonNumber);
    return nRandonNumber;
}