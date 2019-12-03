#include "GameObservers.h"
#include <iostream>
#include "../Player/Player.h"
#include "../Map/Map.h"

Observable::Observable() {
	_observers = new list<Observer*>;
}

Observable::~Observable() {
	delete _observers;
}

void Observable::attach(Observer* o) {
	_observers->push_back(o);
}

void Observable::detach(Observer* o) {
	_observers->remove(o);
}

void Observable::notify(Map& map, vector<Player*>* players, int player) 
{
	list<Observer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->update(map, players, player);
}

Observer::Observer()
{
}

Observer::~Observer()
{
	
}

PhaseObserver::PhaseObserver()
{
}

PhaseObserver::~PhaseObserver()
{
}

void PhaseObserver::update(Map& map, vector<Player*>* players, int player)
{
	cout << "\nPlayer " << *(players->at(player)->getName()) << " finished his turn.\n";
	
	if (players->size() != (player +1))
	{
		cout << "Player " << *(players->at(player + 1)->getName()) << " will have the next turn.\n";
	}

	else 
	{
		cout << "Player " << *(players->at(0)->getName()) << " will have the next turn.\n";
	}
}

StatisticsObserver::StatisticsObserver()
{
}

StatisticsObserver::~StatisticsObserver()
{
}

void StatisticsObserver::update(Map& map, vector<Player*>* players, int player)
{
	cout << "\nGame stats------------------------------" << endl;
	map.updateCountryOwner(players);
	map.updatePlayerContinent(players);
	map.displayPlayerStats(players);
}
