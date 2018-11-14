#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(){

	//test smithy
	//test the deck and hand size of the player
	// +3 for hand, -3 for deck, -1 from hand for discard

	struct gameState game;
	int i;
	int passDeckCount = 0;
	int passHandCount = 0;
	int k[10] = {adventurer, embargo, village, great_hall, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	initializeGame(2,k,100, &game);
	
	srand(time(NULL));
	
	for(i = 0; i < 100; i++){

		initializeGame(2,k,100, &game);
		int deckCount = rand() % (500 + 1);
		int handCount = rand() % (deckCount + 1);	
		
		game.deckCount[0] = deckCount - handCount;
		game.handCount[0] = handCount;
		
		int handPosition = game.hand[0][game.handCount[0] - 1];
		int deckPreSmithy = game.deckCount[0];
		int handPreSmithy = game.handCount[0];

		playSmithy(&game, handPosition);

		int deckPostSmithy = game.deckCount[0];
		int handPostSmithy = game.handCount[0];

		if((deckPreSmithy - 3) == deckPostSmithy){
			//printf("Passed deck count test: %d\n", i);
			passDeckCount++;
		}

		if((handPreSmithy + 2) == handPostSmithy){
			//printf("Passed hand count test: %d\n",i);
			passHandCount++;
		}
	}
	printf("Passed %d deck count tests\n", passDeckCount);
	printf("Passed %d hand count tests\n", passHandCount);
}

