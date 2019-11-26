#include <string>
#include <iostream>
#include "../GameState/GameState.h"
#include "../StartUpPhase/StartUpPhase.h"
#include "GameMainLoop.h"
#include "../Map/Map.h"
#include "../Observer/GameObservers.h"


using namespace std;

void Loop::mainLoopDriver(Map &map, Deck &deck, Hand &hand, vector<Player*>* players)
{

	GameState state = GameState();
	int gameLength = state.gameTurns(players->size()); //Get total number of turns

	// Setting up the observers
	Observable subject{};
	//auto* phase = new PhaseObserver("phase");
	auto* stats = new StatisticsObserver();
	//subject.attach(phase);
	subject.attach(stats);
	
	for (int i = 0; i < gameLength; i++)
	//for (int i = 0; i < 2; i++) //TESTING
	{
		cout << "\nTURN " << i << ". " << gameLength - i << " Turns remain." << endl;

		//Loop for each player 
		for (int j = 0; j < players->size(); j++)
		{	
			map.printMap(players);
			cout <<endl << *(players->at(j)->getName()) << " it is your turn.\n";
			hand.exchange(&deck, (players->at(j)), j, &map);
			subject.notify(map, players);	
		}
	}


}
