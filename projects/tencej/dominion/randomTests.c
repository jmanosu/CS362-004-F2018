#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct gameState * generateRandomGame(){
  int i, j, randnum;
  struct gameState * newRGame = newGame();
  int kCards[10];
  int randomCard = 0;
  for(i = 0; i < 10; i++){
    randomCard += rand() % 3;
    if(randomCard > 27){
      randomCard = 27;
    }
    kCards[i] = randomCard;
  }
  kCards[0] = copper;
  initializeGame(rand()%4, kCards, rand(), newRGame);
  newRGame->deckCount[0] = rand() % MAX_DECK;
	newRGame->discardCount[0] = rand() % MAX_DECK;
  newRGame->handCount[0] = rand() % MAX_HAND;
  for(i = 0; i < newRGame->numPlayers; i++){
    randnum = rand() % 5 + 3;
    for(j = 0; j < randnum; j++){
      newRGame->hand[i][j] = rand() % 27;
    }
    newRGame->handCount[i] = randnum;

    randnum = rand() % 30;
    for(j = 0; j < randnum; j++){
      newRGame->discard[i][j] = rand() % 27;
    }

    newRGame->discard[i][rand() % 30] = copper;
    newRGame->discard[i][rand() % 30] = copper;
    newRGame->discard[i][rand() % 30] = copper;
    newRGame->discardCount[i] = randnum;

    randnum = rand() % 30;
    for(j = 0; j < randnum; j++){
      newRGame->deck[i][j] = rand() % 27;
    }
    newRGame->deckCount[i] = randnum;
  }
  return newRGame;
}
/*
struct gameState * copyGame(struct gameState * oldGame){

  struct gameState * copiedGame = newGame();
  *copiedGame = *oldGame;
  return copiedGame;

}
/*
int compareGames(struct gameState * game1, struct gameState * game2){
  if(game1->numPlayers != game2->numPlayers){
    printf("ERROR numPlayers do not match\n");
    return 1;
  }

  if(game1->numActions != game2->numActions){
    printf("ERROR numActions do not match\n");
    return 1;
  }

  if(game1->coins != game2->coins){
    printf("ERROR coins do not match\n");
    return 1;
  }

  if(game1->whoseTurn != game2->whoseTurn){
    printf("ERROR whoseTurn does not match\n");
    return 1;
  }

  int i, j;
  for(i = 0; i < game1->numPlayers; i++){

    if(game1->handCount[i] != game2->handCount[i]){
      printf("ERROR handCounts do not match\n");
      return 1;
    }

    for(j = 0; j < game1->handCount[i]; j++){
      if(game1->hand[i][j] != game1->hand[i][j]){
        printf("ERROR cards in hand do not match\n");
        return 1;
      }
    }

    if(game1->discardCount[i] != game2->discardCount[i]){
      printf("ERROR discardCounts do not match\n");
      return 1;
    }

    for(j = 0; j < game1->discardCount[i]; j++){
      if(game1->discard[i][j] != game1->discard[i][j]){
        printf("ERROR cards in discard do not match\n");
        return 1;
      }
    }

    if(game1->deckCount[i] != game2->deckCount[i]){
      printf("ERROR deckCounts do not match\n");
      return 1;
    }

    for(j = 0; j < game1->deckCount[i]; j++){
      if(game1->deck[i][j] != game1->deck[i][j]){
        printf("ERROR cards in deck do not match\n");
        return 1;
      }
    }
  }

  printf("PASSED!\n");
  return 1;
}*/

int main(){
  int i, j = 0;
  j += 0;
  srand(time(0));

/*  printf("Test SMITHYCARD:\n");
  for(i = 0; i < 1000; i++){
    struct gameState* game1 = generateRandomGame();
    game1->hand[game1->whoseTurn][0] = smithy;
//  struct gameState* game2 = copyGame(game1);
    cardEffect(smithy,0,0,0, game1, 0, &j);
    free(game1);
  }*/
  printf("Test adventurer:\n");
   for(i = 0; i < 100000; i++){
     struct gameState* game1 = generateRandomGame();
     game1->hand[game1->whoseTurn][0] = smithy;
 //  struct gameState* game2 = copyGame(game1);
      game1->whoseTurn = game1->numPlayers-1;
     cardEffect(great_hall,0,0,0, game1, 0, &j);
     free(game1);
   }
/*
  if(game2->numActions > 0 && game2 == 0){
    game2->numActions--;
    game2->handCount[game2->whoseTurn] +3;
    if(game2->deckCount[game2->whoseTurn] > ){
      for(int i = 0; i < 3; i++){

      }
    }
  }*/
  //compareGames(game1, game2);
  printf("Test 2:\n");
  struct gameState* game3 = generateRandomGame();
  struct gameState* game4 = generateRandomGame();
  //compareGames(game3, game4);
  //free(game1);
  //free(game2);
  free(game3);
  free(game4);

  return 1;
}
