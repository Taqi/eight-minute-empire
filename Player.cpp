//
// Created by james on 2019-10-11.
//
#include <iostream>
#include <string>
#include <vector>
#include "Country.h"
#include "Card.h"
#include "Biding.h"
#include "Resource.h"
#include "Player.h"
#include "Army.h"

using namespace std;
using std::endl;


Player::Player (int playerID)
{
    this->playerID = &playerID;
    coins = 0;
    score = 0;
};

int Player::getScore()
{
    return *score;
}

int Player::getCoins()
{
    return *coins;
}


void Player::payCoins(int cost)
{
    coins = coins - cost;
    cout << "This player has pay " << cost << endl;
}

void Player::placeNewArmies()
{
    cout << "Player has placed an new army. "<< endl;
}

void Player::moveOverLand()
{
    cout <<  "Move army over land." << endl;
}

void Player::moveArmies()
{
    cout << "Move army to this region."<< endl;
}

void Player::buildCity()
{
    cout << "Player " << *playerID << " has built a city." << endl;
}

void Player::destroyArmy()
{
    cout << "An army has been destroyed." << endl;
}