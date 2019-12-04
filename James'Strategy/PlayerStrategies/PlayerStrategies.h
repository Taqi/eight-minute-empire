//
// Created by james on 2019-11-25.
//

#ifndef COMP345A3_PLAYERSTRATEGIES_H
#define COMP345A3_PLAYERSTRATEGIES_H

#include "../GameState/GameState.h"
#include <string>

using namespace std;

//Forward Declaration
class Card;
class GameState;
class Player;

// Abstract Class
class PlayerStrategies {
public:
    virtual string chooseAction(GameState &state, int turn, int currentTurn) = 0;
    virtual string showCurrentStrat() = 0;
};

// Greedy computer - building cities and destroying opponent
class GreedyComputer : public PlayerStrategies {
public:
    virtual string chooseAction(GameState &state, int turn, int currentTurn);
    virtual string showCurrentStrat();
};

// Human player - actions are being made through user interactions
class HumanPlayer : public PlayerStrategies{
    virtual string chooseAction(GameState &state, int turn, int currentTurn);
    virtual string showCurrentStrat();
};

// Moderate computer - actions are controlling the starting region
class ModerateComputer : public PlayerStrategies {
    virtual string chooseAction(GameState &state, int turn, int currentTurn);
    virtual string showCurrentStrat();
};

// Ultility Functions
bool checkChangeStrat();
void changePlayerStrat(vector<Player*> players);

#endif //COMP345A3_PLAYERSTRATEGIES_H
