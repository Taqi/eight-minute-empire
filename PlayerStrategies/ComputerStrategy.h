#pragma once
#include "PlayerStrategies.h"
#include "../Player/Player.h"


class ComputerStrategy : public PlayerStrategies
{
	virtual void buildCity(int player, int cityToAdd, Map& map);
	virtual void destroyArmy(int armyToDestroy, Map& map) ;

};

