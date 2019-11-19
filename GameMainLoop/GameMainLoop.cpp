#include <string>
#include <iostream>
#include "../GameState/GameState.h"
#include "../StartUpPhase/StartUpPhase.h"
#include "GameMainLoop.h"
#include "../Map/Map.h"

using namespace std;

void mainLoopDriver(Map &map, Deck &deck, Hand &hand, vector<Player*>* players)
{
	// Setting up the observers
	Observable s{};
	PhaseObserver* phase = new PhaseObserver();
	StatisticsObserver* stats = new StatisticsObserver();
	s.attach(phase);
	s.attach(stats);

	cout << "Current map: \n";
	map.printMap(players);

	GameState state = GameState();
	int gameLength = state.gameTurns(players->size()); //Get total number of turns

	for (int i = 0; i < gameLength; i++)
	{
		cout << "\nTURN " << i << ". " << gameLength - i << " Turns remain." << endl;

		//Loop for each player 
		for (int j = 0; j < players->size(); j++)
		{	
			map.printMap(players);
			cout <<endl << *(players->at(j)->getName()) << " it is your turn.\n";
			hand.exchange(&deck, (players->at(j)), j, &map);
			//map.updateCountryOwner(players); 
			s.notify();
		}
	}


}
