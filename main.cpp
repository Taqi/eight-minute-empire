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


int main()
{
	
	//MapLoaderDriver();
	//Map *m = MapDriver(); //Has some duplicates with MapLoaderDriver //We probably won't end up using mapDriver.cpp
	// PlayerDriver();
	//CardDriver();
	//BiddingDriver();


    // Part 1)
	//Call gameStateDriver which creates a GameState object, and returns that GameState object
    GameState state = gameStateDriver();

	//Get the vector of player created in gamestate
	vector<Player*> *players = state.players;
	
	//Get map
	Map* map = state.map;

	map->printMap();

	//Get the deck created in gamestate
	Deck* deck = state.getDeck();

	//Get hand object created in gamestate
	Hand* hand = state.getHand();

	deck->draw(hand);

	mainLoopDriver(*map, *deck, *hand, players);


    // Part 2)
    // gameStartupExample();

    // Part 3 AND 5)
    // mainLoopDriver();

    // Part 4)
    // in gamestate.cpp

    // Part 6)
    // gameScoreExample();

    return 0;




}
