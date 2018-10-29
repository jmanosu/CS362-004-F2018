/* Jared Tence
 * tencej
 * CS362
 * cardtest4.c adventurer
 */


 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>

 void main(){
   struct gameState * cGame = newGame();
   int kingdomC[10] = {estate, duchy, province, copper, silver, gold, adventurer,
               council_room, feast, adventurer};
   initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
   int * junk;
   cGame->hand[ 0 ][ cGame->handCount[0] ] = adventurer;
   cGame->handCount[0]++;

   for(int i = 0; i < 10; i++){
     cGame->deck[ 0 ][ cGame->deckCount[0] ] = province;
     cGame->deckCount[0]++;
   }

   cGame->discard[0][ cGame->discardCount[0] ] = copper;
   cGame->discardCount[0]++;
   cGame->discard[0][ cGame->discardCount[0] ] = copper;
   cGame->discardCount[0]++;
  int boolError = 0;
  int pastHSize = cGame->handCount[0];
  int pastDSize = cGame->discardCount[0];
  int pastNActions = cGame->numActions;
  cardEffect(adventurer, 0,0,0, cGame, cGame->handCount[0]-1, junk);
  if(cGame->handCount[0] != pastHSize + 1){
    printf("ERROR adventurer drawing wrong amount of cards\n");
    boolError = 1;
  }else if(cGame->discard[0][cGame->discardCount[0]-1] != adventurer){
    printf("ERROR adventurer card not discarded\n");
    boolError = 1;
  }else if(cGame->numActions != pastNActions){
    printf("ERROR adventurer adding wrong amount of actions\n");
    boolError = 1;
  }else if(cGame->hand[0][cGame->handCount[0]-1] == copper || cGame->hand[0][cGame->handCount[0]-1] == silver || cGame->hand[0][cGame->handCount[0]-1] == gold){
    printf("ERROR adventurer copper, gold, or silver not added to hand for card 1");
    boolError = 1;
  }else if(cGame->hand[0][cGame->handCount[0]-2] == copper || cGame->hand[0][cGame->handCount[0]-2] == silver || cGame->hand[0][cGame->handCount[0]-2] == gold){
    printf("ERROR adventurer copper, gold, or silver not added to hand for card 2");
    boolError = 1;
  }
  int i;
  for(i = pastDSize; i < cGame->discardCount[0]-1; i++){
     if(cGame->discard[0][i] == copper || cGame->discard[0][i] != gold || cGame->discard[0][i] != silver){
     printf("ERROR copper gold or silver was discarded\n");
     boolError = 1;
    }
   }
  if(boolError){
   printf("FAILED\n");
  }else{
    printf("PASSED\n");
  }
 }
