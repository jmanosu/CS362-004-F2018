/* Jared Tence
 * tencej
 * CS362
 * unittest2 fullDeccCardCount();
 */


 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>


void testfullDeckCount(int correct,int player, int card, struct gameState *state){
  int result = fullDeckCount(player,card,state);
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
  int playersC[4][10];
  initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
  int i, j, cCard, lastCount;
  cCard = 0;
  for(i = 0; i < MAX_PLAYERS; i++){
    playersC[i][0] = 3;
    for(j = 1; j < 10; j++){
        playersC[i][j] = 0;
    }
    playersC[i][3] = 7;
  }

  for(i = 0; i < MAX_PLAYERS; i++){
    for(j = 0; j < 50; j++){
      if(gainCard(kingdomC[cCard], cGame, j%3, i) == -1){
        cCard++;
        if(cCard > 9){
          i = MAX_PLAYERS;
          j = 20;
          break;
        }
      }else{
        playersC[i][cCard]++;
        testfullDeckCount(playersC[i][cCard], i,kingdomC[cCard], cGame);
      }
    }
  }
}
