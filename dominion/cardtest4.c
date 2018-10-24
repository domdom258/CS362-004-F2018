#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){


        printf("Card test 4\n");
        printf("Testing the adventure card\n");

        struct gameState Game;
        int k[10] = {smithy,copper, mine, adventurer, gold, sea_hag, baron, village, gardens, estate};
        initializeGame(2, k, 3, &Game);
	Game.whoseTurn = 0;	
	
	//int treasureDrawn = 0;
	
	Game.deckCount[0] = 2;
	Game.deck[0][0] = gold;
	Game.deck[0][1] = copper;
	int deckCount = Game.deckCount[0];
	Game.handCount[0] = 4;
	int handCount = Game.handCount[0];
	
	playAdventurer(&Game);

	printf("check the hand count\n");
	if(handCount - 2 == Game.handCount[0]){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}
	
	printf("Check the deck count after shuffling\n");
	initializeGame(2, k, 3, &Game);
	Game.deckCount[0] = 0;
	deckCount = Game.deckCount[0];
	playAdventurer(&Game);	

	if(deckCount < Game.deckCount[0]){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}
	

	return 0;
}

