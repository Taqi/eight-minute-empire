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


//void addNeutralArmies(GameState& state)
//{
//	cout << "For a game of two players, each players take their turn to add five neutral armies to any region." << endl;
//	
//
//	for (int i = 1; i < 11; i++)
//	{
//
//		int neutralCountry;
//		auto countryID = state.map->getCountryPlayer();
//
//		// print the map so player can reference it
//		cout << "Printing map's current state: \n";
//		state.map->printMap();
//
//		// add the army through the loop statement
//		//while (!validname)
//
//			//for (int i = 0; i < *(map->mapSize); i++) //Index of array playerCountryArmyArray
//				//{
//				//	for (int j = 0; j < nPlayers; j++) //Index of vector cityArmyPair
//				//	{
//				//		//map->playerArmyCountryArray[i].head->cityArmyPair = new vector<pair<int, int>>(); //when cityArmyPair is a pointer
//
//				//		if (i == 0) //At country 0, each player has 3 armies and 1 city
//				//		{
//				//			//map->playerArmyCountryArray[i].head->cityArmyPair->push_back(make_pair(3, 1)); //when cityArmyPair is a pointer
//				//			map->playerArmyCountryArray[i].head->cityArmyPair.push_back(make_pair(3, 1));
//				//	
//				//		}
//
//				//		else
//				//		{
//				//			//map->playerArmyCountryArray[i].head->cityArmyPair->push_back(make_pair(0, 0));
//				//			map->playerArmyCountryArray[i].head->cityArmyPair.push_back(make_pair(0, 0));
//				//		}
//				//	}
//
//	}
//}