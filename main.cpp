#include <iostream>
#include "Player/Player.h"
#include "Player/PlayerDriver.h"
#include "Bidding/BiddingDriver.h"
#include "Map/MapDriver.h"
#include "MapLoader/MapLoaderDriver.h"
#include "Card/CardDriver.h"
#include "GameScore/GameScore.h"
#include "GameScore/GameScoreDriver.h"
#include "GameMainLoop/GameMainLoop.h"
#include "GameState/GameState.h"
#include "GameState/GameStateDriver.h"
#include "StartUpPhase/StartUpPhaseDriver.h"


int main()
{
	
	//MapLoaderDriver();
	//Map *m = MapDriver(); //Has some duplicates with MapLoaderDriver //We probably won't end up using mapDriver.cpp
	// PlayerDriver();
	//CardDriver();
	//BiddingDriver();

	int* m = new int(5);
	int* n = new int(7);
	int* k = new int(0);
	int l = 3;

	k = n;
	cout << "ITS " << *k <<endl;
	k = &l; //makes the pointer point to a new address. Note: if it was *k = l, it would change the value inside k, which would also change thevalue inside n, since k was pointing to n.
	cout << "ITS " << *k <<endl;
	cout << "ITS " << *n << endl;

    // Part 1)
	//Call gameStateDriver which creates a GameState object, and returns that GameState object
    GameState state = gameStateDriver();

	//Get the vector of player created in gamestate
	vector<Player*> *players = state.players;
	
	//Get map
	Map* map = state.map;

	map->printMap(players);

	//Get the deck created in gamestate
	Deck* deck = state.getDeck();

	//Get hand object created in gamestate
	Hand* hand = state.getHand();

	//deck->draw(hand);
	StartUpPhaseDriver(*map, *deck, *hand, players);

	mainLoopDriver(*map, *deck, *hand, players);

	
    // Part 2)
    // gameStartupExample();

    // Part 6)
    // gameScoreExample();

    return 0;




}
