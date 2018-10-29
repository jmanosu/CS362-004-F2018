/* Jared Tence
 * tencej
 * CS362
 * cardtest2 village
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
   int i;
   int * junk;
   cGame->hand[ 0 ][ cGame->handCount[0] ] = village;
   cGame->handCount[0]++;
   int boolError = 0;
   for(i = 0; i < 4;i++){
     int pastHSize = cGame->handCount[0];
     int pastDSize = cGame->discardCount[0];
     int pastNActions = cGame->numActions;
     cardEffect(smithy, 0,0,0, cGame, cGame->handCount[0]-1, junk);
     if(cGame->handCount[0] != pastHSize + 1){
       printf("ERROR village drawing wrong amount of cards\n");
       boolError = 1;
     }else if(cGame->discardCount[0] != pastDSize + 1){
       printf("ERROR village discarding wrong amount of cards");
       boolError = 1;
     }else if(cGame->discard[0][cGame->discardCount[0]-1] != village){
       printf("ERROR village card not discarded");
       boolError = 1;
     }else if(cGame->numActions != pastNActions + 1){
       printf("ERROR village adding wrong amount of actions");
       boolError = 1;
     }
     cGame->hand[ 0 ][ cGame->handCount[0] ] = village;
     cGame->handCount[0]++;
   }
   if(boolError){
    printf("FAILED\n");
   }else{
     printf("PASSED\n");
   }
 }
