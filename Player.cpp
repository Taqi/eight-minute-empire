//
// Created by james on 2019-10-11.
//

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "Bidding.h"

using namespace std;

// Constructor
Player::Player (string name, int age)
{
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::coins = new int(14);
    Player::name = new string(name);
    Player::age = new int(age);
    Player::bid = new Bidding();
}

Player::Player(string name, int numbOfPlayers, int age)
{
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::name = new string(name);
    Player::age = new int(age);
    Player::bid = new Bidding();

    // Determine the amount of token/coins to players by number of players
    switch (numbOfPlayers)
    {
        case 2:
            Player::coins = new int(14);
            break;
        case 3:
            Player::coins = new int(11);
            break;
        case 4:
            Player::coins = new int(9);
            break;
        case 5:
            Player::coins = new int(8);
            break;
    }
}

// Destructor
Player::~Player()
{
    delete this->coins;
    delete this->cities;
    delete this->armies;
    delete this->age;
    delete this->name;
    delete this->bid;
}

// Implemented Methods
bool Player::payCoins(int cost)
{
    if (*(this->getCoins()) < cost)
    {
        cout << "Insufficient coins to make this purchase." << endl;
        return false;
    }
    else
    {
        this->setCoins(*(this->getCoins()) - cost);
        cout << "Purchase Successfully!! You have " << *(this->getCoins()) << " amount of coins remaining." << endl;
        return true;
    }
}

bool Player::placeNewArmies(int armies, string place)
{
//    return gameMap.addArmy(place, *this->getName());
cout << "Player " << *(this->getName()) << " has placed " << armies << " armies at " << place;
return true;
}

void Player::moveOverLand(int moves)
{
    cout << "This method allows player to move " << moves << " armies across land/over sea." << endl;
}

void Player::moveArmies(int moves)
{
    cout << "This method allows player to move " << moves << " armies." << endl;
}

void Player::buildCity()
{
    cout << "This method allows player to build city." << endl;
}

void Player::destroyArmy()
{
    cout << "This method allows player to destroy other player's armies" << endl;
}

// Getters
int* Player::getCoins() const {
    return coins;
}

int* Player::getArmy() const {
    return armies;
}

int* Player::getCities() const {
    return cities;
}

int *Player::getAge() const {
    return age;
}

string *Player::getName() const {
    return name;
}

Bidding *Player::getBidding() const {
    return bid;
}

// Setters
void Player::setCoins(int coins) {
    *Player::coins = coins;
}

void Player::setArmy(int armies){
    *Player::armies = armies;
}

void Player::setCities(int cities) {
    *Player::cities = cities;
}

void Player::setAge(int age){
    *Player::age = age;
}

void Player::setName(string name) {
    *Player::name = name;
}


