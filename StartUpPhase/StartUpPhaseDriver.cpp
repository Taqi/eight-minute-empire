//
// Created by james on 2019-11-04.
//

#include "../GameState/GameState.h"
#include "StartUpPhaseDriver.h"
#include "StartUpPhase.h"
#include <iostream>

using namespace std;

void StartUpPhaseDriver()
{
    GameState state();

    cout << "Game State Initialized - Deck gets shuffled!" << endl;
    cout << "6 cards are being drawn at the same time!" << endl;
    cout << "As an example, we will have two game states that contain the cards with different shuffling." << endl;
    cout << "----LOADING THE EMPTY MAP ----" << endl;

    GameState state1 = GameState();
    GameState state2 = GameState();

    cout << "Map is loaded - Game State is created - Welcome to the game!" << endl;

    int playerIndex1 = startGame(state1);

    cout << "Start Up Phase is completed. Map display: " << endl;
    state1.graph->countryArray;

    cout << "First player with the following index: "
         << state1.players->at(playerIndex1)->getName()
         << ", " << playerIndex1 << endl;

    cout << "Details Info For Each Player:" << endl;
    for (int i = 0; i < state1.players->size(); i++)
    {
        cout << "Name: " << state1.players->at(i)->getName() << endl;
        cout << "Age: " << state1.players->at(i)->getAge() << endl;
        cout << "Armies: " << state1.players->at(i)->getArmy() << endl;
        cout << "Cities: " << state1.players->at(i)->getCities() << endl;
        cout << "Name: " << state1.players->at(i)->getCoins()<< endl;
    }

}
