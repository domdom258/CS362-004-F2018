#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){

	struct gameState Game;
	        int k[10] = {smithy,copper, mine, adventurer, gold, sea_hag, baron, village, gardens, estate};

	initializeGame(2,k,3,&Game);
	Game.coins = 0;
		
	printf("\n Unit test 1*\n");
	
	printf("\nTest 1: using differnet coins\n");
	Game.hand[0][0] = copper;
	Game.hand[0][1] = copper;
	Game.hand[0][2] = silver;
	Game.hand[0][3] = silver;
	Game.hand[0][4] = gold;
	Game.hand[0][5] = gold;
	Game.hand[0][6] = copper;
	Game.hand[0][7] = gold;
        Game.hand[0][8] = gold;
        Game.hand[0][9] = copper;
	updateCoins(0,&Game,0);

	if(Game.coins == 18)
		printf("Passed\n");
	else
		printf("Failed\n");
	
	printf("\nTest 2: using different coins with bonus\n");
	Game.hand[0][0] = copper;
        Game.hand[0][1] = copper;
        Game.hand[0][2] = silver;
        Game.hand[0][3] = silver;
        Game.hand[0][4] = gold;
        Game.hand[0][5] = gold;
        Game.hand[0][6] = copper;
	Game.hand[0][7] = gold;
        Game.hand[0][8] = copper;
	Game.hand[0][9] = copper;
	updateCoins(0,&Game, 10);
	
	if(Game.coins == 28)
		printf("Passed\n");
	else
		printf("Failed\n");
	
	printf("\nTesting all gold coins:\n");
	Game.hand[0][0] = gold;
	Game.hand[0][1] = gold;
	Game.hand[0][2] = gold;
	Game.hand[0][3] = gold;
	Game.hand[0][4] = gold;
	Game.hand[0][5] = gold;
        Game.hand[0][6] = gold;
        Game.hand[0][7] = gold;
        Game.hand[0][8] = gold;
        Game.hand[0][9] = gold;

	updateCoins(0,&Game, 0);
	if(Game.coins == 30){
		printf("Passed\n");
	}else
		printf("Failed\n");
	return 0;
}
