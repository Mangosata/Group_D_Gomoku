#include "/cygdrive/C/Users/gshar/Downloads/C Project/check/Group_D_Gomoku/include/game/game.h"
#include "/cygdrive/C/Users/gshar/Downloads/C Project/check/Group_D_Gomoku/include/test/test.h"
/*
 * It will randomly generate the number between -10 to 10. But input values 1 and 2 of type integer are acceptable
 */

int unit_test_check_winner(int board_size){
    int nMax = board_size - 1;
    int nMin = 0;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	printf("%d\n",nRandonNumber);
    return nRandonNumber;
}