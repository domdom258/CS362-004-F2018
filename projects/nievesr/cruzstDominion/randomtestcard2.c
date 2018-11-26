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

	struct gameState game;
        int i;
        int passActions = 1;
        int passHandCount = 1;
        int k[10] = {adventurer, embargo, village, great_hall, mine, cutpurse, sea_hag, tribute, smithy, council_room};
        initializeGame(2,k,100, &game);

        srand(time(NULL));
	
	for(i = 0; i < 100; i++){
		initializeGame(2,k,100, &game);
                int deckCount = rand() % (500 + 1);
                int handCount = rand() % (deckCount + 1);

                game.deckCount[0] = deckCount - handCount;
                game.handCount[0] = handCount;
		int numActionsBefore = game.numActions = rand() % (10 + 1);	
                int handPosition = game.hand[0][game.handCount[0] - 1];
                int handPreVillage = game.handCount[0];

                playVillage(&game, handPosition);

                int handPostVillage = game.handCount[0];
		int numActionsAfter = game.numActions;
		
		if((numActionsAfter - 3)== numActionsBefore){
			passActions++;
		}
		
		if(handPreVillage == handPostVillage){
			passHandCount++;

		}
	}

		
	printf("Passed %d out of 100 actions test\n", passActions);
	printf("Passed %d out of 100 hand count test\n", passHandCount);

}
