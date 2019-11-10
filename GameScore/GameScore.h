//
// Created by james on 2019-11-04.
//


#ifndef COMP345A1_GAMESCORE_H
#define COMP345A1_GAMESCORE_H

#include "../Player/Player.h"
#include "../Card/Cards.h"
#include "../GameState/GameState.h"
#include "../Map/Map.h"\

using namespace std;

class GameScore {
    int* point;
    vector<Card*> gameHand;
    vector<Player*> players;
    int* numOfRegions;
    int* numOfContinents;
    int* numOfCoins;
    int* numOfArmies;

    // The priority order: mostPoints ->  mostCoins -> mostArmies -> mostRegions
    int* mostPoints;
    int* mostCoins;
    int* mostArmies;
    int* mostRegions;

public:
    GameScore();

    GameScore(const vector<Card*> &gameHand, const vector<Player *> &players);

    virtual ~GameScore();

    // Calculate the points of cards with the same good type
    int* countTreePoint(int *tree);

    int* countAnvilPoint(int *anvil);

    int* countCarrotPoint(int *carrot);

    int* countRockPoint(int *rock);

    int* countCrystalPoint(int *crystal);

    // Initially count the number of the same good type
    int* numOfTree(vector<Card*> &gameHand);

    int* numOfAnvil(vector<Card*> &gameHand);

    int* numOfCarrot(vector<Card*> &gameHand);

    int* numOfRock(vector<Card*> &gameHand);

    int* numOfCrystal(vector<Card*> &gameHand);

    int* numOfWild(vector<Card*> &gameHand);

    int* computeGameScore(vector<Card*> &gameHand);

    void winnerGenerator (vector <Player*> playerVector);
};


#endif //COMP345A1_GAMESCORE_H
