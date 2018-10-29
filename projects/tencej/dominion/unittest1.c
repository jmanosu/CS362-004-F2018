/* Jared Tence
 * tencej
 * CS362
 * unittest1 gainCard();
 */


 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>


void testsupplyCount(int correct, int card, struct gameState *state){
  int result = supplyCount(card,state);
  if(result != correct){
    printf("ERROR result %i doesn't equal correct result %i\n", result, correct);
  }else{
    printf("Passed result %i does match correct result %i\n", result, correct);
  }
}

int main(){
  struct gameState * cGame = newGame();
  int kingdomC[10] = {estate, duchy, province, copper, silver, gold, adventurer,
              council_room, feast, gardens};
  int stratingC[10] = {12,12,12,32,40,30,10,10,10,12};
  initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
  int i, j, cCard, lastCount;
  cCard = 0;
  lastCount = stratingC[cCard];

  for(i = 0; i < MAX_PLAYERS; i++){
    for(j = 0; j < 20; j++){
      if(gainCard(kingdomC[cCard], cGame, j%2, i) == -1){
        cCard++;
        if(cCard > 9){
          i = MAX_PLAYERS;
          j = 20;
          break;
        }
        lastCount = stratingC[cCard];
      }else{
        lastCount--;
        testsupplyCount(lastCount,kingdomC[cCard], cGame);
      }
    }
  }
}
