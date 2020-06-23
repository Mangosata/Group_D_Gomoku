#include "game/game.h"
#include "test/test.h"
/*
 * It will randomly generate the number between -100 to 100. these randomized coordinates will be given to the player_move()
 */

int unit_test_player_move(void){
    int nMax = 100;
    int nMin = -100;
    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
	printf("%d\n",nRandonNumber);
    return nRandonNumber;
}