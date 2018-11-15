CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomTest1: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o randomTest1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

testRandomTest1:
	./randomTest1
	printf "GCDA for test"
	gcov randomtestcard1.gcda

randomTest2: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o randomTest1 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

testRandomTest2:
	./randomTest2
	printf "GCDA for test"
	gcov randomtestcard2.gcda

randomTest3: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o randomTest3 randomtestcard3.c -g dominion.o rngs.o $(CFLAGS)

testRandomTest3:
	./randomTest3
	printf "GCDA for test"
	gcov randomtestcard3.gcda


runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomTest1 randomTest2 randomTest3
