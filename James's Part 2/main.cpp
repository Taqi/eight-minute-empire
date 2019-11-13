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
#include "StartUpPhase/StartUpPhase.h"
#include "StartUpPhase/StartUpPhaseDriver.h"



int main()
{
	
	//MapLoaderDriver();
	//Map *m = MapDriver(); //Has some duplicates with MapLoaderDriver //We probably won't end up using mapDriver.cpp
	// PlayerDriver();
	//CardDriver();
	//BiddingDriver();


    // Part 1)
	//Call gameStateDriver which creates a GameState object, and returns that GameState object
    //GameState state = gameStateDriver();
	//gameStateDriver();

    // Part 2)
	StartUpPhaseDriver();

    // Part 3 AND 5)
    // mainLoopDriver();

    // Part 4)
    // playerMethodsDriver();

    // Part 5)
    // gameScoreExample();

    return 0;




}
