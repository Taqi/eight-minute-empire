//#include <iostream>
//#include "player.h"
//#include <string>
//
//using namespace std;
//
//void playerdriver()
//{
//    // creating local variables for testing
//    int numbofplayers;
//    int age;
//    string name;
//
//    // require input from test user
//    cout << "welcome to eight minute empire, how many player(s) are there in total?" << endl;
//    cin >> numbofplayers;
//    cout << "what is your name?" << endl;
//    cin >> name;
//    cout << "how old are you?" << endl;
//    cin >> age;
//
//    // initialize user
//    Player *testplayer = new Player(name, numbofplayers, age);
//
//    // return the user's info
//    /*cout << "hi " << *(testplayer->getname()) << ", you are " << *(testplayer->getage()) << " years old." << endl;
//    cout << "player setup as following: " << endl;
//    cout << " - " << *(testplayer->getcoins()) << " coins." << endl;
//    cout << " - " << *(testplayer->getarmy()) << " armies." << endl;
//    cout << " - " << *(testplayer->getcities()) << " cities." << endl;*/
//
//    // testing method
//    testplayer->payCoins(2);
//    testplayer->payCoins(2);
//    testplayer->payCoins(2);
//    testplayer->payCoins(2);
//    testplayer->payCoins(2);
//
//    // player::movearmies()
//    testplayer->moveArmies(0, 1, map);
//
//    // player::moveoverland()
//    testplayer->moveOverLand(0, 1, map);
//
//    // player::buildcity()
//    testplayer->buildCity(0, 1, map);
//
//    // player::destroyarmy()
//    testplayer->destroyArmy(1, map);
//
//    delete testplayer;
//
//}