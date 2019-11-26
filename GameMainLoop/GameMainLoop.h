
#ifndef COMP345A1_GAMEMAINLOOP_H
#define COMP345A1_GAMEMAINLOOP_H
#include "../Observer/GameObservers.h"

class Loop: public Observable
{
public:
	void mainLoopDriver(Map& map, Deck& deck, Hand& hand, vector<Player*>* players);
};

#endif //COMP345A1_GAMEMAINLOOP_H
