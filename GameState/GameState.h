//
// Created by james on 2019-11-04.
//

#include <iostream>
#include <vector>
#include "../Card/Cards.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"

using namespace std;

#ifndef COMP345A1_GAMESTATE_H
#define COMP345A1_GAMESTATE_H


class GameState {
    // All members for this class need to be public since it will be using during gameplay
    public:
        // Game Map
        Graph *graph;

        // Players
        vector<Player *> *players;

        // Cards and hands that are placed on the table
        Deck *deck;

        Hand *hand;

        GameState();
        ~GameState();

        int determineGameLength();
};


#endif //COMP345A1_GAMESTATE_H
