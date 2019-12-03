
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


	return state;

	
}
