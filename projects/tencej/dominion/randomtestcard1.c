#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct gameState * generateRandomGame(){
  int i, j, randnum;
  struct gameState * newRGame = newGame();
  int kCards[10];
  int randomCard = 0;
  for(i = 0; i < 10; i++){
    randomCard += rand() % 3;
    randomCard = randomCard % 27;
    kCards[i] = randomCard;
  }
  kCards[0] = copper;
  initializeGame(rand()%4, kCards, rand(), newRGame);
  for(i = 0; i < newRGame->numPlayers; i++){
    randnum = rand() % MAX_HAND;
    for(j = 0; j < randnum; j++){
      newRGame->hand[i][j] = rand() % 27;
    }
    newRGame->handCount[i] = randnum;

    randnum = rand() % MAX_DECK + 3;
    for(j = 0; j < randnum; j++){
      newRGame->discard[i][j] = rand() % 27;
    }
    newRGame->discardCount[i] = randnum;

    randnum = rand() % MAX_DECK;
    for(j = 0; j < randnum; j++){
      newRGame->deck[i][j] = rand() % 27;
    }
    newRGame->deckCount[i] = randnum;
  }
  return newRGame;
}


int main(){
  int i, j = 0;
  j += 0;
  srand(time(0));

  printf("Test SMITHYCARD:\n");
  for(i = 0; i < 5000; i++){
    struct gameState* game1 = generateRandomGame();
    game1->hand[game1->whoseTurn][0] = smithy;
    int oldDeckCount = game1->deckCount[game1->whoseTurn];
    int oldHandCount = game1->handCount[game1->whoseTurn];
    int oldDiscardCount = game1->discardCount[game1->whoseTurn];
    int oldNumActions = game1->numActions;
    int player = game1->whoseTurn;
    cardEffect(smithy,0,0,0, game1, 0, &j);
    assert(game1->numActions == oldNumActions);
    assert(game1->coins == game1->coins);
    assert(game1->handCount[player] !=  oldHandCount + 3);
    assert(((game1->deckCount[player] ==  oldDeckCount - 3) || oldDeckCount  == 0));
    free(game1);
  }


  printf("passed!\n");
  return 0;
}
