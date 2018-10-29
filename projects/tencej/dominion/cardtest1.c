/* Jared Tence
 * tencej
 * CS362
 * cardtest1 smithy
 */


 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>

 void main(){
   struct gameState * cGame = newGame();
   int kingdomC[10] = {estate, duchy, province, copper, silver, gold, adventurer,
               council_room, feast, gardens};
   initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
   int handsize = 0;
   int i;
   int * junk;
   int boolError = 0;
   cGame->hand[ 0 ][ cGame->handCount[0] ] = smithy;
   cGame->handCount[0]++;
   for(i = 0; i < 4;i++){
     int pastHSize = cGame->handCount[0];
     int pastDSize = cGame->discardCount[0];
     int pastNActions = cGame->numActions;
     cardEffect(smithy, 0,0,0, cGame, cGame->handCount[0]-1, junk);
     if(cGame->handCount[0] != pastHSize + 1){
       printf("ERROR smithy drawing wrong amount of cards\n");
       boolError = 1;
     }else if(cGame->discardCount[0] != pastDSize + 1){
       printf("ERROR smithy discarding wrong amount of cards");
       boolError = 1;
     }else if(cGame->discard[0][cGame->discardCount[0]-1] != smithy){
       printf("ERROR smithy card not discarded");
       boolError = 1;
     }
     cGame->hand[ 0 ][ cGame->handCount[0] ] = smithy;
     cGame->handCount[0]++;
   }
   if(boolError){
    printf("FAILED\n");
   }else{
     printf("PASSED\n");
   }
 }
