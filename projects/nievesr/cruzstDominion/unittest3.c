#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

	printf("\nUnit Test 3\n");
	printf("Check the isGameOver function\n");
	struct gameState Game;
	int passed;
	int k[10] = {1,2,3,4,5,6,7,8,9,10}; 
	initializeGame(2,k,3,&Game);

	printf("Set the number of province cards to 0\n");
	Game.supplyCount[province] = 0;
	passed = isGameOver(&Game);
	if(passed == -1){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}

	
	printf("Set the number of province cards to 10\n");
	initializeGame(2,k,3,&Game);
	Game.supplyCount[province] = 10;
	passed = isGameOver(&Game);
	if(passed == 0){
		printf("\nPassed\n");
	}else{
		printf("\nFailed\n");
	}
	return 0;
	

}
