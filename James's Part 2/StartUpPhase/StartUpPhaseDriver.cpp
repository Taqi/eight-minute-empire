////
//// Created by james on 2019-11-04.
////
//
#include "../GameState/GameState.h"
#include "StartUpPhaseDriver.h"
#include "StartUpPhase.h"
#include <iostream>

using namespace std;

void StartUpPhaseDriver()
{
   
    GameState state1 = GameState();

    //cout << "Map is loaded - Game State is created - Welcome to the game!" << endl;

    int playerIndex1 = start(state1);
	
    cout << endl << "First player with the following index: "
         << state1.players->at(playerIndex1)->getName()
         << ", " << playerIndex1 << endl << endl;

    cout << "Details Info For Each Player:" << endl;
    for (int i = 0; i < state1.players->size(); i++)
    {
        cout << "Name: " << state1.players->at(i)->getName() << endl;
        cout << "Age: " << state1.players->at(i)->getAge() << endl;
        cout << "Armies: " << state1.players->at(i)->getArmy() << endl;
        cout << "Cities: " << state1.players->at(i)->getCities() << endl;
        cout << "Coins: " << state1.players->at(i)->getCoins()<< endl;
		state1.players->at(i)->setArmy(11);
		cout << "Place three armies in the starting region - Armies: " << state1.players->at(i)->getArmy() << endl;
	
		cout << "------------------------------------------------------------------------" << endl;
		
    }
	
}



