////
//// Created by james on 2019-11-04.
////
//
#include "../GameState/GameState.h"
#include "StartUpPhaseDriver.h"
#include "StartUpPhase.h"
#include <iostream>

using namespace std;

void StartUpPhaseDriver(Map& map, Deck& deck, Hand& hand, vector<Player*>* players)
{
	//Draw 6 cards
	deck.draw(&hand);

	//GameState state1 = GameState();

	//cout << "Map is loaded - Game State is created - Welcome to the game!" << endl;

	//int playerIndex1 = start(state1);
	int playerIndex1 = 0; //? How do I get playerIndex? startmethod does not return anything

	cout << endl << "First player with the following index: "
		<< *(players->at(playerIndex1)->getName())
		<< ", " << playerIndex1 << endl << endl;

	cout << "Details Info For Each Player:" << endl;
	for (int i = 0; i < players->size(); i++)
	{
		cout << "Name: " << *(players->at(i)->getName()) << endl;
		cout << "Age: " << *(players->at(i)->getAge()) << endl;
		cout << "Armies: " << *(players->at(i)->getArmy()) << endl;
		cout << "Cities: " << *(players->at(i)->getCities()) << endl;
		cout << "Coins: " << *(players->at(i)->getCoins()) << endl;
		players->at(i)->setArmy(11);
		cout << "Place three armies in the starting region - Armies: " << *(players->at(i)->getArmy()) << endl;

		cout << "------------------------------------------------------------------------" << endl;

	}

}
