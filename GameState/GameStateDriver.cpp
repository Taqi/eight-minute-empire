//
// Created by james on 2019-11-04.
//

#include "GameState.h"
#include "GameStateDriver.h"

using namespace std;

/*
Creates GameState object (called state), calls the start method, and returns the object to the main.cpp
*/
GameState gameStateDriver()
{
    //cout << endl << "+---------------------------------+" << endl;
    //cout << endl << "|     This is GAME START DRIVER     |" << endl;
    //cout << endl << "+---------------------------------+" << endl << endl;

	GameState state;
	state.start();
	
	//Player *p = new Player("Taqi", 22);
	//state.map = MapDriver();
	//p->moveArmies(0, 1, *(state.map));

	//p->buildCity(0, 1, *state.map);

	//p->placeNewArmies(0, 2, *state.map);

	//p->destroyArmy(1, *state.map);

	//p->ignore();

	//p->andOrAction(0, "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1", *state.map);

	//p->andOrAction(0, "PLACE_NEW_ARMIES_ON_BOARD 1 OR MOVE_OVER_LAND 1", *state.map);



	return state;

    //Here will take 2 example of an invalid map and a valid map

    //GameState state1 = GameState();
    //GameState state2 = GameState();

    // Getting Card Info

    // Getting Player Info
   /* for(int i = 0; i < state1.players->size(); i++)
    {
        cout << state1.players->at(i)->getName() << " has "
             << state1.players->at(i)->getHandOfDeck()->size() << "cards and has a bid of "
             << state1.players->at(i)->getBidding()->getBid()
             << endl;
    }*/

	
}
