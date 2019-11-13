//
// Created by james on 2019-11-04.
//

#include <string>
#include <iostream>
#include "../GameState/GameState.h"
#include "../StartUpPhase/StartUpPhase.h"
#include "GameMainLoop.h"

using namespace std;

void mainLoopDriver(Map &map, Deck &deck, Hand &hand, vector<Player*>* players)
{

	cout << "Current map: \n";
	map.printMap();

	GameState state = GameState();
	int gameLength = state.gameTurns(players->size()); //Get total number of turns

	for (int i = 0; i < gameLength; i++)
	{
		cout << "\nTURN " << i << ". " << gameLength - i << " Turns remain." << endl;

		//Loop for each player 
		for (int j = 0; j < players->size(); j++)
		{
			cout <<endl << *(players->at(j)->getName()) << " it is your turn.\n";
			hand.exchange(&deck, (players->at(j)), j, &map);
		}
	}


    // Have the game set up
//    GameState state = GameState();
	
//    int _1stPlayerIndex = startGame(state);
//    int lengthOfGame = state.determineGameLength();
////    vector<Card*> topBoard = state.deck->topBoardGenerator(*state.deck);
//
//    // The number of game terms are restricted by the number of players
//    for (int i = 1; i <= lengthOfGame; i++)
//    {
//        cout << "Turn " << ". " << lengthOfGame - i << " Turns remai." << endl << endl;
//
//        // Each player has 1 turn to play
//        for (int j = _1stPlayerIndex; j < _1stPlayerIndex + state.players->size(); j++)
//        {
//
//            int turn = j % state.players->size();
//
//            // Let the player knows whose turn it is, show the current state of the map
//            cout << state.players->at(turn)->getName()
//                 << ", it's your turn to go. The current state of the game"
//                 << endl << endl;
//            state.graph->countryArray;
//
//            // A player buy a card
//            // state.hand->exchange(*state.players->at(turn), topBoard, *state.deck);
//
//            // Each player has to power to ignore card effect result in ending their turn
//            bool endTurn = state.players->at(turn)->ignore();
//            if (endTurn)
//            {
//                continue;
//            }
//
//            string action = *(state.players->at(turn)->getHandOfDeck()->at(i-1).getAction());
//
//            // If the action from card is a type of "AND"/"OR" --> Call andOrAction()
//            if (action.find("OR") != string::npos || action.find("AND") != string::npos)
//            {
//                state.players->at(turn)->andOrAction(action, *state.graph, *state.players);
//            }
//
//            // Else call takeAction
//            else
//            {
//                state.players->at(turn)->takeAction(action, *state.graph, *state.players);
//            }
//        }
//    }


}
