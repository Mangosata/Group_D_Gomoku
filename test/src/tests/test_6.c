#include "/cygdrive/C/Users/gshar/Downloads/C Project/check/Group_D_Gomoku/include/game/game.h"
#include "/cygdrive/C/Users/gshar/Downloads/C Project/check/Group_D_Gomoku/include/test/test.h"
/*
 * It will randomly generate the number between -10 to 10. But input values 1 and 2 of type integer are acceptable
 */

int unit_test_when_board_size_btw_16_and_18(void){
	int nMax = 18;
    int nMin = 16;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	return nRandonNumber;
}