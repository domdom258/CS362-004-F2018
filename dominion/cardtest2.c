#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	

	printf("Card test 2\n");
	printf("Testing the village card\n");

	struct gameState Game;
        int k[10] = {smithy,copper, mine, adventurer, gold, sea_hag, baron, village, gardens, estate};
        initializeGame(2, k, 3, &Game);	

	Game.whoseTurn = 0;
	Game.numActions = 1;
	Game.handCount[0] = 3;
	Game.deckCount[0] = 3;
	int numActions = Game.numActions;
	int handCount = Game.handCount[0];
	int deckCount = Game.deckCount[0];
	
	 playVillage(&Game, 0);
	

	//printf("%d, %d\n", numActions, Game.numActions);
	//printf("%d, %d\n", handCount, Game.handCount[0]);
	//printf("%d, %d\n", deckCount, Game.deckCount[0]);
	printf("Testing number of actions\n");
	if((numActions + 2) == Game.numActions){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");

	}
	
	printf("Testing hand count of player\n");
	if((handCount + 1 - 1) == Game.handCount[0]){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}
	
	printf("Testing deck count of player\n");
	if((deckCount - 1) == Game.deckCount[0]){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}
	return 0;
}
