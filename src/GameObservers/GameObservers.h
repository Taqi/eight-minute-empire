#pragma once
#include <iostream>
#include <vector>
#include "GameState.h"

// Abstract class
class Observer
{
private:
    // observer needs an id for identification
    std::string *id;

public:
    // uniqueness of uid is enforced
    Observer(std::string uid);
    ~Observer();

    // accessor for the unique id
    std::string getId();

    // new data will be updated with the observer
    virtual void update(const GameState &state, std::string playerName, std::string playerAction) = 0;
};

// Information updated in current phase
class PhaseObserver : public Observer
{
private:
    std::string *currentPlayer;
    std::string *action;

public:
    PhaseObserver(std::string uid);
    ~PhaseObserver();

    // Updates instance variables, displays phase
    virtual void update(const GameState &state, std::string playerName, std::string playerAction);
};

class StatisticsObserver : public Observer
{
private:
    // bar-graph row
    std::string graphRow(std::string header, int width, int value);

public:
    StatisticsObserver(std::string uid);
    ~StatisticsObserver();

    // Updates data, draws bar-graph
    virtual void update(const GameState &state, std::string playerName, std::string playerAction);
};

class Observable
{
private:
    std::vector<Observer *> *observers;

public:
    Observable(); // Constructor
    ~Observable(); //Destructor

    // pushes new observer onto vector
    bool attach(Observer *o);
    // deletes observer by id from vector
    bool detach(std::string id);
    // calls update on all observers to notify of change
    void notify(const GameState &state, std::string playerName, std::string playerAction);
};
