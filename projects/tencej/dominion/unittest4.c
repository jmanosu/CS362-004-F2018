/* Jared Tence
 * tencej
 * CS362
 * unittest4 shuffle();
 */


 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>


void testshuffle(int correct, int* kingdomC, int playersC[4][10], int player, struct gameState *state){
  int deck[MAX_PLAYERS][MAX_DECK];
  memcpy(deck, state->deck, sizeof state->deck);
  int result = shuffle(player,state);
  if(result != correct){
    printf("ERROR wrong return value \n");
    return;
  }

  if(state->numPlayers < 2){
    printf("PASSED\n");
    return;
  }

  int i;
  for(i = 0; i < 10; i++){
    if(fullDeckCount(player,kingdomC[i],state) != playersC[player][i]){
      printf("ERROR loss of cards after shuffle\n");
      printf("Card %i: %i != %i\n",i, fullDeckCount(player,kingdomC[i],state), playersC[player][i]);
      return;
    }
  }

  for(i = 0; i < state->deckCount[player]; i++){
    if(deck[player][i] != state->deck[player][i]){
      printf("PASSED\n");
      return;
    }
  }

  printf("ERROR deck not shuffled\n");
}

int main(){
  struct gameState * cGame = newGame();
  int kingdomC[10] = {estate, duchy, province, copper, silver, gold, adventurer,
              council_room, feast, gardens};
  initializeGame(1, kingdomC, 7, cGame);
  int playersC[4][10];
  testshuffle(-1, kingdomC, playersC, 0, cGame);

  initializeGame(MAX_PLAYERS, kingdomC, 7, cGame);
  int i, j, cCard, lastCount;
  cCard = 0;
  for(i = 0; i < MAX_PLAYERS; i++){
    for(j = 0; j < 10; j++){
        playersC[i][j] = 0;
    }
    playersC[i][0] = 3;
    playersC[i][3] = 7;
  }

  for(i = 0; i < MAX_PLAYERS; i++){
    for(j = 0; j < 50; j++){
      if(gainCard(kingdomC[cCard], cGame, 1, i) == -1){
        cCard++;
        if(cCard > 9){
          i = MAX_PLAYERS;
          j = 50;
          break;
        }
      }else{
        playersC[i][cCard]+= 1;
      }
    }
  }

  for(i = 0; i < MAX_PLAYERS; i++){
    testshuffle(0, kingdomC, playersC, i, cGame);
  }
}
