//#include <iostream>
//
//#include "PlayerStrategiesDriver.h"
//#include "../Player/Player.h"
//#include "../StartUpPhase/StartUpPhase.h"
//#include "PlayerStrategies.h"
//
//// Forward Declarations
//class Player;
//class Card;
//class StartUpPhase;
//
//void playerStrategiesDriver()
//{
//    // Setting up the game
//    GameState state = GameState();
//    int _1stPlayerIndex = start(state);
//    int gameLength = state.gameLength();
//
//    // number of game terms limited by number of players
//    for (int i = 1; i <= gameLength; i++)
//    {
//        bool changeStrategy = checkChangeStrat();
//        if (changeStrategy)
//        {
//            changePlayerStrat(*state.players);
//        }
//
//        cout << "Turn " << i << ". " << gameLength-i << " Turns remain.\n\n" ;
//
//        // Every player get a chance to play once per turn
//        for (int j = _1stPlayerIndex; j < _1stPlayerIndex + state.players->size(); j++)
//        {
//            int turn = j%state.players->size();
//
//            // Inform players on whose turn it is, dislay current state of the map
//            cout << state.players->at(turn)->getName()
//                 << ", it is now your turn. Here is the current state of the game.\n\n";
//            state.map.printMap();
//
//            // Action phase
//            state.players->at(turn)->getPlayerStrategies()->chooseAction(state, turn, i);
//        }
//    }
//}
//
