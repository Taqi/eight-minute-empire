//
// Created by james on 2019-10-12.
//

#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

void PlayerDriver()
{
   // Creating local variables for testing
   int numbOfPlayers;
   int age;
   string name;

   // Require input from test user
   cout << "Welcome to Eight Minute Empire, how many player(s) are there in total?" << endl;
   cin >> numbOfPlayers;
   cout << "What is your name?" << endl;
   cin >> name;
   cout << "How old are you?" << endl;
   cin >> age;

   // Initialize User
   Player* testPlayer = new Player(name, numbOfPlayers, age);

   // Return the user's info
   cout << "Hi " << *(testPlayer->getName()) << ", you are " << *(testPlayer->getAge()) << " years old." << endl;
   cout << "Player Setup as following: " << endl;
   cout << " - " << *(testPlayer->getCoins()) << " coins." << endl;
   cout << " - " << *(testPlayer->getArmy()) << " armies." << endl;
   cout << " - " << *(testPlayer->getCities()) << " cities." << endl;

   // Testing method
   testPlayer->payCoins(2);
   testPlayer->payCoins(2);
   testPlayer->payCoins(2);
   testPlayer->payCoins(2);
   testPlayer->payCoins(2);

   // Player::moveArmies()
   testPlayer->moveArmies(3);

   // Player::moveOverLand()
   testPlayer->moveOverLand(3);

   // Player::buildCity()
   testPlayer->buildCity();

   // Player::destroyArmy()
   testPlayer->destroyArmy();

   delete testPlayer;

}