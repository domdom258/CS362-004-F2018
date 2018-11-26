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
	printf("\nUnit Test 2\n");

	printf("Test the Buy Card function\n");

	int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 	initializeGame(2, k, 3, &Game);
		

	printf("Check with 0 buys\n");
	Game.numBuys = 0;
	int passed = buyCard(3, &Game);
	
	if(passed == -1){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}

	
	printf("Check with enough buys not enough coins\n");
	Game.numBuys = 3;
	Game.coins = 1;
	passed = buyCard(5, &Game);
	
	if(passed != -1){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}

	printf("Check with enough buys and enough coins\n");
	Game.coins = 100;
	
	passed = buyCard(5, &Game);
	if(passed == 0){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}

}
