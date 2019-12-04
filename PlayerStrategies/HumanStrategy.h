#pragma once

#include "PlayerStrategies.h"

class Map;
class Player;

class HumanStrategy : public PlayerStrategies
{
public:

	Player* player;

	virtual void moveArmies(int Player, int moves, Map& map);
	virtual void moveOverLand(int player, int moves, Map& map); // Move between two regions(over water or Land) as if they were adjacent
	virtual void buildCity(int player, int cityToAdd, Map& map); // Place a city anywhere on the board where player has an army
	virtual void destroyArmy(int armyToDestroy, Map& map) = 0; // Remove an army from the board belonging to any player
	virtual bool placeNewArmies(int player, int armiesToAdd, Map& map);
	virtual bool ignore(); // Ignore the card and end the player turn
};

