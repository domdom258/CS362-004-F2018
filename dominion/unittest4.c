#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("Unit Test 4\n");
	printf("Testing the getCost function\n");

	int cardCost[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
	int cardNum[30] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
	char *cardNames[27] = {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};

	int count = 0;
	int i;
	for(i = 0; i < 27; i++){
		if(cardCost[i] == getCost(cardNum[i])){
			count++;	
		}
		else{
			printf("%s is wrong\n", cardNames[i]);

		}

	}
	
	if(count == 27){
		printf("\nAll cards passed\n");

	}else{
		printf("\nFailed\n");
	}
	
	return 0;

}
