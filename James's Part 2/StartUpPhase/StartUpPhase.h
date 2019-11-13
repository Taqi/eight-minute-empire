//
// Created by james on 2019-11-04.
//
#include "../GameState/GameState.h"

#ifndef COMP345A1_STARTUPPHASE_H
#define COMP345A1_STARTUPPHASE_H

    // 1) Shuffling cards from the deck & draw 6 cards

    // 2) For each player must have:
    // - Set of one color of cubes(14 armies)
    // - Discs (3 cities)
    // - Place 3 armies on the starting region on board
    // - Playing with 2 players, each takes turns placing 1 army

    // 3) Player places coin

    // 4) Players bid and assign the player who will starts

	
    int start(GameState &state);

    // Number of armies to starting region are being added
    //void addArmiesToStart(GameState &state);

    // Ten armies are added to the board
   // void addNeutralArmies(GameState &state);


#endif //COMP345A1_STARTUPPHASE_H
