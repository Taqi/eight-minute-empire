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

	//Start up
	StartUpPhaseDriver(*map, *deck, *hand, players);

	//Main loop
	Loop loop;
	loop.mainLoopDriver(*map, *deck, *hand, players);

	//Compute final score
	score(players);
    return 0;




}
