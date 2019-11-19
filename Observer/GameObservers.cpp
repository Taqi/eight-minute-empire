#include "GameObservers.h"
#include <iostream>
#include "../../../../Documents/GitHub/eight-minute-empire/Player/Player.h"

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

void Observable::notify() {
	list<Observer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->update();
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


string StatisticsObserver::graph(string title, int width, int v)
{
	// Add enough spaces so that all rows are equal length
	for (int i = 0; i < (width - title.length()); i++)
	{
		title += " ";
	}

	// Return the row with a newline character on the end
	return title + "\n";
}

StatisticsObserver::StatisticsObserver()
{
}

StatisticsObserver::~StatisticsObserver()
{
}

void StatisticsObserver::update(Map& map, vector<Player*>* players)
{
	cout << "Game stats" << endl;

	
	for (int j = 0; j < players->size(); j++)
	{
		map.printMap(players);
		cout << endl << *(players->at(j)->getName());

		vector<string*> countries; //the regions/countries that a player has
		vector<string*> resources; /*the resources that a given player has.*/
		vector<Card>* playerHand; //Contains the cards that a player owns

		cout << players->at(j)->getName() << endl;
		cout << graph("Points", 11, state.players->at(i)->getScore());
		cout << graph("Regions", 11, players->at(j)->getCities());
		cout << graph("Continents", 11, players->at(j)->getContinents());
		cout << graph("Armies", 11, players->at(j)->getArmy());
	}
}
