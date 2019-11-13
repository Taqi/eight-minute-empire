

#include "../Player/Player.h"
#include "GameState.h"
#include "../Map/Map.h"
#include "../Map/MapDriver.h"
//#include <utility>



using namespace std;




int GameState::gameLength()
{
    //The game ends when each player owns a
    //certain number of cards depending on the number of players.
    //2 Players 13 Cards
    //3 Players 10 Cards
    //4 Players 8 Cards
    //5 Players 7 Cards
    switch (players->size())
    {
        case (2):
            return 13;
        case (3):
            return 10;
        case (4):
            return 8;
        case (5):
            return 7;
    }
}



/* start function
		- The different valid maps can be loaded and their validity is verified (i.e. it is a connected
		graph, etc.), and invalid maps are rejected without the program crashing.
		- The right number of players is created.
		- An assigned deck with the right number of cards is created.
		- An assigned biding facility to each player.
		- An assigned empty hand of cards to each player.
*/
//void GameState::start()
//{
//	generateTitleScreen();
//	
//	//Load Map
//	Map *map = MapLoaderDriver(); //Load Map using MapLoader //MapLoaderDriver in MapLoaderDriver.cpp returns the map created there
//	//map = MapDriver(); //Load map using MapDriver.cpp (using this one temporarily until Daphne fixes the map loader file)
//
//	map->printAllAdjacentCountries(); //Not needed here
//	//map->printMap(); //Not needed here 
//
//	
//
//	//An assigned deck with the right number of cards is created.
//	//Create deck object
//	deck = new Deck();
//	
//
//	int* totalCards = new int(42);
//	deck->setTotalCards(totalCards);
//
//	//Create hand object (hand space) (PROBABLY PUT THIS IN PART 2 - STARTUPPHASE)
//	hand = new Hand();
//
//	//Draw 6 cards for the hand space (PUT THIS IN STARTUPPHASE SINCE ITS PART 2 OF ASSIGNMENT)
//	//deck->draw(hand);
//
//
//	// Players creation
//	players = new vector<Player *>();
//	int nPlayers;
//	cout << "How many people are playing in the game? ";
//	cin >> nPlayers;
//	cout << endl;
//
//	int* three = new int(3);
//
//	//Initialize vector of pair (each player starts with 3 armies and 1 city  in the starting region (country 0), and nothing else where
//	for (int i = 0; i < *(map->mapSize); i++) //Index of array playerCountryArmyArray
//	{
//		for (int j = 0; j < nPlayers; j++) //Index of vector cityArmyPair
//		{
//			//map->playerArmyCountryArray[i].head->cityArmyPair = new vector<pair<int, int>>(); //when cityArmyPair is a pointer
//
//			if (i == 0) //At country 0, each player has 3 armies and 1 city
//			{
//				//map->playerArmyCountryArray[i].head->cityArmyPair->push_back(make_pair(3, 1)); //when cityArmyPair is a pointer
//				map->playerArmyCountryArray[i].head->cityArmyPair.push_back(make_pair(3, 1));
//			}
//
//			else
//			{
//				//map->playerArmyCountryArray[i].head->cityArmyPair->push_back(make_pair(0, 0));
//				map->playerArmyCountryArray[i].head->cityArmyPair.push_back(make_pair(0, 0));
//			}
//		}
//	}
//	
//	
//	// Retrieve the player name and ages
//	for (int i = 0; i < nPlayers; i++)
//	{
//	    string name;
//	    int age;
//	
//	    cout << "Please enter your name: ";
//	    cin >> name;
//	
//	    cout << "Please enter your age: ";
//	    cin >> age;
//	
//	    // Using emplace_back instead of push back since I want to return a reference here for the Player
//	    players->emplace_back(new Player(name, nPlayers, age));
//
//	}
//
//
//	
//	//Driver for PART 4 ASSIGNMENT 2
//	map->printMap();
//	Player *p = new Player("Taqi", 22);
//
//	p->buildCity(0, 1, *map);
//
//	p->placeNewArmies(0, 2, *map);
//
//	p->moveArmies(0, 1, *map);
//
//	p->destroyArmy(2, *map);
//
//	//p->ignore();
//
//	//p->andOrAction(0, "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1", *map);
//	
//	//p->andOrAction(0, "PLACE_NEW_ARMIES_ON_BOARD 1 OR MOVE_OVER_LAND 1", *map);
//
//
//
//	//Deallocate
//	delete map;
//	map = NULL;
//
//	delete hand;
//	hand = NULL;
//
//	delete deck;
//	deck = NULL;
//
//	
//
//}


GameState::GameState()
{
	generateTitleScreen();
		
		//Load Map
		Map *m = MapLoaderDriver(); //Load Map using MapLoader //MapLoaderDriver in MapLoaderDriver.cpp returns the map created there
		map = MapDriver(); //Load map using MapDriver.cpp (using this one temporarily until Daphne fixes the map loader file)
	
		//map->printAllAdjacentCountries(); //Not needed here
		//map->printMap(); //Not needed here 
	
		
	
		//An assigned deck with the right number of cards is created.
		//Create deck object
		deck = new Deck();
		
	
		int* totalCards = new int(42);
		deck->setTotalCards(totalCards);
	
		//Create hand object (hand space) (PROBABLY PUT THIS IN PART 2 - STARTUPPHASE)
		hand = new Hand();
	
		//Draw 6 cards for the hand space (PUT THIS IN STARTUPPHASE SINCE ITS PART 2 OF ASSIGNMENT)
		deck->draw(hand);
	
	
		// Players creation
		players = new vector<Player *>();
		int nPlayers;
		cout << endl << "How many people are playing in the game? ";
		cin >> nPlayers;
		cout << endl;
	
		int* three = new int(3);
	
		//Initialize vector of pair (each player starts with 3 armies and 1 city  in the starting region (country 0), and nothing else where
		//for (int i = 0; i < *(map->mapSize); i++) //Index of array playerCountryArmyArray
		//{
		//	for (int j = 0; j < nPlayers; j++) //Index of vector cityArmyPair
		//	{
		//		//map->playerArmyCountryArray[i].head->cityArmyPair = new vector<pair<int, int>>(); //when cityArmyPair is a pointer
	
		//		if (i == 0) //At country 0, each player has 3 armies and 1 city
		//		{
		//			//map->playerArmyCountryArray[i].head->cityArmyPair->push_back(make_pair(3, 1)); //when cityArmyPair is a pointer
		//			map->playerArmyCountryArray[i].head->cityArmyPair.push_back(make_pair(3, 1));
		//	
		//		}
	
		//		else
		//		{
		//			//map->playerArmyCountryArray[i].head->cityArmyPair->push_back(make_pair(0, 0));
		//			map->playerArmyCountryArray[i].head->cityArmyPair.push_back(make_pair(0, 0));
		//		}
		//	}
		//}
		
		
		// Retrieve the player name and ages
		for (int i = 0; i < nPlayers; i++)
		{
		    string name;
		    int age;
		
		    cout << "Please enter your name: ";
		    cin >> name;
		
		    cout << "Please enter your age: ";
		    cin >> age;
		
		    // Using emplace_back instead of push back since I want to return a reference here for the Player
		    players->emplace_back(new Player(name, nPlayers, age));

			cout << name << " has join the game to bid!" << endl;
		}

		cout << endl << "Total number of players: " << nPlayers << endl;

		cout << endl << "Each player has 0 cards on their hand! " << endl << endl;


		
		////Driver for PART 4 ASSIGNMENT 2
		//map->printMap();
		//Player *p = new Player("Taqi", 22);
	
		//p->buildCity(0, 1, *map);
	
		//p->placeNewArmies(0, 2, *map);
	
		//p->moveArmies(0, 1, *map);
	
		//p->destroyArmy(2, *map);
	
		//p->ignore();
	
		//p->andOrAction(0, "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1", *map);
		
		//p->andOrAction(0, "PLACE_NEW_ARMIES_ON_BOARD 1 OR MOVE_OVER_LAND 1", *map);
	
	
	
		//Deallocate
		delete map;
		map = NULL;
	
		delete hand;
		hand = NULL;
	
		delete deck;
		deck = NULL;
	
		
	
	
}

void GameState::generateTitleScreen()
{
	cout << endl << "+----------------------------------------------------+" << endl;
	cout << endl << "|      WELCOME TO THE EIGHT-MINUTE EMPIRE GAME       |" << endl;
	cout << endl << "+----------------------------------------------------+" << endl << endl;
	
	cout << "Game State Initialized - Deck gets shuffled!" << endl;
	cout << "6 cards are being drawn at the same time!" << endl;

}



