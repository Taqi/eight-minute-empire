#pragma once
#include <string>
#include <list>
#include "../Player/Player.h"
//#include "../Map/Map.h"
using namespace std;

class Map;

class Observer
{
	public:

		Observer();
		~Observer();

		//Observer gets updated with new data
		virtual void update(Map& map, vector<Player*>* players) = 0;
};


class Observable
{

	private:
		list<Observer*>* _observers;

	public:
		void attach(Observer* o);
		void detach(Observer* o);
		void notify(Map& map, vector<Player*>* players);
		Observable();
		~Observable();

};

//Part 2Asg
class PhaseObserver : public Observer
{
	public:
		PhaseObserver();
		~PhaseObserver();

	// Updates instance variables, displays phase
	virtual void update(Map& map, vector<Player*>* players);
};

//Part 3Asg
class StatisticsObserver : public Observer
{
	private:
		// makes a graph row
		string graph(string title, int width, int v);

	public:
		StatisticsObserver();
		~StatisticsObserver();

		// Updates data, draws graph
		virtual void update(Map& map, vector<Player*>* players);
};
