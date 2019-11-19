#pragma once

class Player;
class Map;

class PlayerStrategies
{


public: 
	Player* player;
	int getStrategy();
	

	virtual void moveArmies(int player, int moves, Map& map) = 0; // Move armies according to the indicated number of armies - land movement only
	virtual void moveOverLand(int player, int moves, Map& map) = 0; // Move between two regions(over water or Land) as if they were adjacent
	virtual bool buildCity(int player, int cityToAdd, Map& map); // Place a city anywhere on the board where player has an army
	virtual void destroyArmy(int armyToDestroy, Map& map) = 0; // Remove an army from the board belonging to any player
	virtual bool placeNewArmies(int player, int armiesToAdd, Map& map); 
	virtual bool ignore(); // Ignore the card and end the player turn
	PlayerStrategies(Player* player);
};



