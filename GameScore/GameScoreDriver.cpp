
#include "GameScoreDriver.h"
#include "../Player/Player.h"
#include "../Card/Cards.h"
#include "../GameState/GameState.h"
#include "../Map/Map.h"\
#include "GameScore.h"

using namespace std;

void score(vector<Player*>* players)
{
	cout << endl << "+---------------------------------+" << endl;
	cout << endl << "|       this is game score        |" << endl;
	cout << endl << "+---------------------------------+" << endl << endl;
	GameScore finalScore;
	finalScore.computeGameScore(players);
	finalScore.winnerGenerator(players);
	

}