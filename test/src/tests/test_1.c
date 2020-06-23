#include "game/game.h"
#include "test/test.h"
/*
 * It will randomly generate the number between -10 to 10. But input values 1 and 2 of type integer are acceptable
 */

int unit_test_select_board_size(void){
    int nMax = 10;
    int nMin = -10;
	srand (time(NULL));
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	printf("%d\n",nRandonNumber);
	delay(0.7);
    return nRandonNumber;
}