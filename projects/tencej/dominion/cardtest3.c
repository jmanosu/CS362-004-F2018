/* Jared Tence
 * tencej
 * CS362
 * cardtest3.c embargo
 */


 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>

 void main(){
   struct gameState * cGame = newGame();
   int kingdomC[10] = {estate, duchy, province, copper, silver, gold, adventurer,
               council_room, feast, embargo};
   initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
   int i;
   int * junk;
   int boolError = 0;
   cGame->hand[ 0 ][ cGame->handCount[0] ] = embargo;
   cGame->handCount[0]++;
   for(i = 0; i < 4;i++){
     int pastHSize = cGame->handCount[0];
     int pastDSize = cGame->discardCount[0];
     int pastNActions = cGame->numActions;
     int pastETokens = cGame->embargoTokens[estate];
     int pastCoins = cGame->coins;
     cardEffect(embargo, estate,0,0, cGame, cGame->handCount[0]-1, junk);
     if(cGame->handCount[0] != pastHSize - 1){
       printf("ERROR embargo drawing wrong amount of cards\n");
       boolError = 1;
     }else if(cGame->discardCount[0] != pastDSize){
       printf("ERROR embargo discarded wrong amount of cards\n");
       boolError = 1;
     }else if(cGame->discard[0][cGame->discardCount[0]-1] == embargo){
       printf("ERROR embargo card not trashed\n");
       boolError = 1;
     }else if(cGame->numActions != pastNActions){
       printf("ERROR embargo adding wrong amount of actions\n");
       boolError = 1;
     }else if(cGame->embargoTokens[estate] != pastETokens+1){
       printf("ERROR embargo adding wrong amount of tokens\n");
       boolError = 1;
     }else if(cGame->coins != pastCoins + 2){
       printf("ERROR embargo adding wrong amount of coins\n");
       boolError = 1;
     }
     cGame->hand[ 0 ][ cGame->handCount[0] ] = embargo;
     cGame->handCount[0]++;
   }
   if(boolError){
    printf("FAILED\n");
   }else{
     printf("PASSED\n");
   }
 }
