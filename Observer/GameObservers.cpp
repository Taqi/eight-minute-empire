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

void Observable::notify(Map& map, vector<Player*>* players) 
{
	list<Observer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->update(map, players);
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

void PhaseObserver::update(Map& map, vector<Player*>* players)
{
}

StatisticsObserver::StatisticsObserver()
{
}

StatisticsObserver::~StatisticsObserver()
{
}

void StatisticsObserver::update(Map& map, vector<Player*>* players)
{
	cout << "\nGame stats------------------------------" << endl;
	map.updateCountryOwner(players);
	map.updatePlayerContinent(players);
	map.displayPlayerStats(players);
}
