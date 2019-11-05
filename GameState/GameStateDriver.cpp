//
// Created by james on 2019-11-04.
//

#include "GameState.h"
#include "GameStateDriver.h"

using namespace std;

void gameStateDriver()
{
    cout << endl << "+---------------------------------+" << endl;
    cout << endl << "|     This is GAME START DRIVER     |" << endl;
    cout << endl << "+---------------------------------+" << endl << endl;

    //Here will take 2 example of an invalid map and a valid map

    GameState state1 = GameState();
    GameState state2 = GameState();

    // Getting Card Info

    // Getting Player Info
    for(int i = 0; i < state1.players->size(); i++)
    {
        cout << state1.players->at(i)->getName() << " has "
             << state1.players->at(i)->getHandOfDeck()->size() << "cards and has a bid of "
             << state1.players->at(i)->getBidding()->getBid()
             << endl;
    }
}
