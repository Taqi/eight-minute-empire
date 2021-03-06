//
// Created by james on 2019-11-04.
//

#include <iostream>
#include <vector>
#include "../Card/Cards.h"
#include "../Map/Map.h"
#include "../Map/MapDriver.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"
#include "../MapLoader/MapLoaderDriver.h"

using namespace std;

#ifndef COMP345A1_GAMESTATE_H
#define COMP345A1_GAMESTATE_H

class Map;
class Deck;
class Hand;
class Player;

class GameState 
{

    public:

        int gameLength();

		Map* map; //Map pointer (points to Map object that contains all the graphs)
		Deck* deck; //Deck pointer
		Hand* hand; //Hand space pointer
		
		vector<Player*>* players;

		/* start function
		- The different valid maps can be loaded and their validity is verified (i.e. it is a connected
		graph, etc.), and invalid maps are rejected without the program crashing.
		- The right number of players is created.
		- An assigned deck with the right number of cards is created.
		- An assigned biding facility to each player.
		- An assigned empty hand of cards to each player. 
		*/
		void start(); 

		void generateTitleScreen(); //Outputs the title screen

		int gameTurns(int totalPlayer);

		//Return pointer to player vector
		vector<Player*> getPlayers();

		//Return map object
		Map* getMap();

		//Return map object
		Deck* getDeck();

		//Return hand object
		Hand* getHand();
};


#endif //COMP345A1_GAMESTATE_H
