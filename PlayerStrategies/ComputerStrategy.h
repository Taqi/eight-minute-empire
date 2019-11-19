#pragma once
#include "PlayerStrategies.h"
#include "../../../OneDrive/Desktop/eight-minute-empire-master/Player/Player.h"


class ComputerStrategy : public PlayerStrategies
{
	virtual bool buildCity(int player, int cityToAdd, Map& map);
	virtual void destroyArmy(int armyToDestroy, Map& map) ;

};

