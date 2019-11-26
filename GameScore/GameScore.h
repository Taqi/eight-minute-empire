
#ifndef COMP345A1_GAMESCORE_H
#define COMP345A1_GAMESCORE_H

#include "../Player/Player.h"
#include "../Card/Cards.h"
#include "../GameState/GameState.h"
#include "../Map/Map.h"\

using namespace std;

class GameScore 
{
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

    // Calculate the points of cards with the same good type
    void countTreePoint(int tree, Player* player);

	void countAnvilPoint(int anvil, Player* player);

	void countCarrotPoint(int carrot, Player* player);

	void countRockPoint(int rock, Player* player);

	void countCrystalPoint(int crystal, Player* player);

	void computeGameScore(vector<Player*>* players); //Compute final scores

	void computeCurrentGameScore(vector<Player*>* players, int player); //Compute score during game

    void winnerGenerator (vector <Player*>* players); //Generates the winner
};


#endif 
