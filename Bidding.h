//
// Created by james on 2019-10-11.
//

#ifndef COMP345A1_BIDDING_H
#define COMP345A1_BIDDING_H

#include "Player.h"
#include <vector>

using namespace std;

class Player;

class Bidding {

private:
    int* bid;

public:

    // Constructor
    Bidding();

    // Gameplay Methods
    static int biddingPhase(vector<Player*> players, int numbOfPlayers);

    // Getters
    int* getBid() const;

    // Setters
    void setBid(int bid);


};


#endif //COMP345A1_BIDDING_H
