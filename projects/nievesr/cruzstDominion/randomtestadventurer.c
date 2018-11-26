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
        int i,j,m,l;
        int k[10] = {adventurer, embargo, minion, great_hall, mine, outpost, sea_hag, tribute, smithy, salvager};
	int countPre = 0;
	int countPost = 0;
	int failCount = 0;
        initializeGame(2,k,100, &game);

        srand(time(NULL));	

	
 	for(i = 0; i < 100; i++){

                initializeGame(2,k,100, &game);
                int deckCount = rand() % (500 + 1);
                int handCount = rand() % (deckCount + 1);

                game.deckCount[0] = deckCount - handCount;
                game.handCount[0] = handCount;

		for(j = 0; j < game.deckCount[0]; j++) {
			int coin = rand() % (20 + 1);
			int card = rand() % (10 + 1);		
			if(coin == 3){
				game.deck[0][j] = copper;

			}
			else if( coin == 9){
				game.deck[0][j] = silver;

			}else if(coin == 18){
				game.deck[0][j] = gold;

			}
			else{
				game.deck[0][j] = k[card];

			}
		}	
	
		
		for(m = 0; m < game.deckCount[0]; m++){
			if(game.hand[0][m] == copper || game.hand[0][m] == silver || game.hand[0][m] == gold){
				countPre++;

			}

		}
		
		playAdventurer(&game);

		for(l = 0; l < game.deckCount[0]; l++){
                        if(game.hand[0][l] == copper || game.hand[0][l] == silver || game.hand[0][l] == gold){
                                countPost++;

                        }
                }
		
		if(countPre != countPost){
			failCount++;
		}
	
        	
		countPre = 0;
		countPost = 0;

		
	}
	printf("Failed %d\n tests",failCount);

	return 0;
}
