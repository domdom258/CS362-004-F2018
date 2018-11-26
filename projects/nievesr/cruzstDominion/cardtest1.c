#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	struct gameState Game;
	int k[10] = {smithy,copper, mine, adventurer, gold, sea_hag, baron, village, gardens, estate};
	initializeGame(2, k, 3, &Game);
	
	printf("Testing Smithy card\n");
	
	//Set the discardCount, deckCoun, and handCount of the player.	
	Game.whoseTurn = 0;
	Game.deckCount[0] = 10;
	Game.handCount[0] = 7;
	
	playSmithy(&Game, 0);
	
			
	//printf("%d\n",Game.deckCount[0]);
	//printf("%d\n",Game.handCount[0]);
	
	//minus 3 to deck count	
	if(Game.deckCount[0] == 7){
		printf("\nPassed deck count check\n");
	}
	else{
		printf("\nFailed deck count check\n");
	}

	//plus 3 to hand count minus 1 for discard
	if(Game.handCount[0] == 9){
		printf("\nPassed hand count check\n");
	}else{
		printf("\nFailed hand count check\n");
	}
}
