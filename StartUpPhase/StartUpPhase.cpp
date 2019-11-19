#include "StartUpPhase.h"
////
//// created by james on 2019-11-04.
////
//
//#pragma once
#include "StartupPhase.h"
#include "../Bidding/Bidding.h"
#include "../GameState/GameState.h"
#include "../GameScore/GameScore.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Map/MapDriver.h"
#include <map>
using namespace std;

int start(Map& map, vector<Player*>* players)
{

	// begin the bidding phase
	int firstplayer = Bidding::biddingPhase(*(players), players->size());

	cout << endl;

	return firstplayer;

	if (players->size() == 2)
	{
		//addNeutralArmies(state);
	}



}


//}