////
//// Created by james on 2019-10-12.
////
//
//#include "../Player/Player.h"
//#include "BiddingDriver.h"
//#include <iostream>
//
//using namespace std;
//
//void BiddingDriver()
//{
//    // Creating local variables for testing
//    int numbOfPlayers;
//    int age;
//    int _1stPlayer;
//    string name;
//
//    // Determine the number of players
//    cout << "Welcome to Eight Minute Empire, how many player(s) are there in total?" << endl;
//    cin >> numbOfPlayers;
//    vector<Player*> players;
//
//    // Initialize all Players in Player vector
//    for (int i = 0; i < numbOfPlayers; i++)
//    {
//        cout << "What is your name?" << endl;
//        cin >> name;
//        cout << "How old are you?" << endl;
//        cin >> age;
//
//        players.push_back(new Player(name, numbOfPlayers, age));
//    }
//
//    // Determine the 1st player in the bidding phase
//    _1stPlayer = Bidding::biddingPhase(players, numbOfPlayers);
//    cout << "First Player to play the game is " << *(players[_1stPlayer]->getName());
//}