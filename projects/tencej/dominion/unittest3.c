/* Jared Tence
 * tencej
 * CS362
 * unittest3 isGameOver();
 */


 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>


void testisGameOver(int correct, struct gameState *state){
  int result = isGameOver(state);
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
  initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
  int i, j, cCard;
  cCard = 0;

  printf("First Test Case:\n");
  for(i = 0; i < MAX_PLAYERS; i++){
    for(j = 0; j < 50; j++){
      if(gainCard(kingdomC[cCard], cGame, 1, i) == -1){
        cCard++;
        if(cCard > 9){
          i = MAX_PLAYERS;
          j = MAX_HAND;
          break;
        }
      }else if(cCard == 2 && supplyCount(kingdomC[cCard], cGame) == 0){
        testisGameOver(1, cGame);
        i = MAX_PLAYERS;
        j = 50;
        break;
      }else{
        testisGameOver(0, cGame);
      }
    }
  }


  printf("second Test Case:\n");
  initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
  for(i = 0; i < MAX_PLAYERS; i++){
    for(j = 0; j < MAX_HAND; j++){
      if(gainCard(kingdomC[2], cGame, 1, i) == -1){
        break;
      }else if(supplyCount(kingdomC[2],cGame) == 0){
        testisGameOver(1, cGame);
      }else{
        testisGameOver(0, cGame);
      }
    }
  }
}
