#include "PlayerStrategies.h"
#include <stdlib.h>
#include <iostream>
#include "../../../OneDrive/Desktop/eight-minute-empire-master/Player/Player.h"

class Player;

using namespace std;

int PlayerStrategies::getStrategy()
{
	return ((rand() % 3));
}

void PlayerStrategies::moveArmies(int player, int moves, Map& map)
{
}

//void PlayerStrategies::moveOverLand(int player, int moves, Map& map)
//{
//}
//
//bool PlayerStrategies::buildCity(int player, int cityToAdd, Map& map)
//{
//	return false;
//}
//
//void PlayerStrategies::destroyArmy(int armyToDestroy, Map& map)
//{
//}
//
//bool PlayerStrategies::ignore()
//{
//	return false;
//}
//
//PlayerStrategies::PlayerStrategies(Player* player)
//{
//}



//void ComputerBehavior::moveArmies(int Player, int moves, Map& map)
//{
//}
//
//void MixBehavior::moveArmies(int Player, int moves, Map& map)
//{
//}
