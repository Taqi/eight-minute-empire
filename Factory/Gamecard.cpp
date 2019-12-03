#include "Cardsfactory.h"
using namespace std;
#include <iostream>
#include <time.h>
#include <stdlib.h>


Gamecard::~Gamecard()
{
	delete seed;
}

Gamecard* Gamecard::createCard(string* type)
{	
	Gamecard* oneCard = new Gamecard(); //Will return this card

	//Every possible good: Carrot, Crystal, Tree, Anvil, Rock
	string* good1 = new string("Carrot");
	string* good2 = new string("Rock");
	string* good3 = new string("Tree");
	string* good4 = new string("Anvil");
	string* good5 = new string("Crystal");

	//Every possible Ngood
	int* n = new int(1);
	int* n2 = new int(2);

	if (seed == 0)
	{
		//Draw randomly among goods
		srand(time(NULL)); //initialize the random seed
		(*seed) = 1;
	}

	int randIndex;
	randIndex = rand() % (5); //5 goods in total

	if (randIndex == 0)
	{
		oneCard->setGood(good1);
	}

	else if (randIndex == 1)
	{
		oneCard->setGood(good2);
	}

	else if (randIndex == 2)
	{
		oneCard->setGood(good3);
	}
	else if (randIndex == 3)
	{
		oneCard->setGood(good4);
	}
	else if (randIndex == 4)
	{
		oneCard->setGood(good5);
	}


	if (*type == "MOVE_OVER_LANND 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
		
	}

	else if (*type == "MOVE_OVER_LANND 2")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n2);
	}

	else if (*type == "BUILD_A_CITY 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
	}

	else if (*type == "BUILD_A_CITY 2")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n2);
	}

	else if (*type == "MOVE_OVER_WATER 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
	}

	else if (*type == "MOVE_OVER_WATER 2")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n2);
	}
	
	else if (*type == "PLACE_NEW_ARMIES_ON_BOARD 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
	}

	else if (*type == "PLACE_NEW_ARMIES_ON_BOARD 2")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n2);
	}

	else if (*type == "DESTROY_ARMY 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
	}

	else if (*type == "DESTROY_ARMY 2")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n2);
	}

	else if (*type == "DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
	}

	else if (*type == "PLACE_NEW_ARMIES_ON_BOARD 1 OR MOVE_OVER_LANND 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
	}

	else if (*type == "PLACE_NEW_ARMIES_ON_BOARD 1 OR BUILD_A_CITY 1")
	{
		oneCard->setAction(type);
		oneCard->setNGood(n);
	}

	return oneCard;
}

vector<Gamecard*> GameDeck::createDeck()
{
	//Every possible action
	string* act1 = new string("MOVE_OVER_WATER 1"); //Can move 1 army over water
	string* act2 = new string("PLACE_NEW_ARMIES_ON_BOARD 1");
	string* act3 = new string("MOVE_OVER_LANND 1"); //There is a reason for having 2 'N': LAND contains 'and', which would be an issue when doing exchange method
	string* act4 = new string("BUILD_A_CITY 1");
	string* act5 = new string("DESTROY_ARMY 1");

	string* act6 = new string("MOVE_OVER_WATER 2"); //Can move 2 armies over water
	string* act7 = new string("PLACE_NEW_ARMIES_ON_BOARD 2");
	string* act8 = new string("MOVE_OVER_LANND 2");
	string* act9 = new string("BUILD_A_CITY 2");
	string* act10 = new string("DESTROY_ARMY 2");

	string* act11 = new string("DESTROY_ARMY 1 AND PLACE_NEW_ARMIES_ON_BOARD 1"); //Can move 2 armies over water
	string* act12 = new string("PLACE_NEW_ARMIES_ON_BOARD 1 OR MOVE_OVER_LANND 1");
	string* act13 = new string("PLACE_NEW_ARMIES_ON_BOARD 1 OR BUILD_A_CITY 1");
	
	for (int i = 0; i < 42; i++)
	{
		//Create 42 card objects, and push each into the vector
		card[i] = new Gamecard();

		//Set the card id
		card[i]->id = new int(i);
	}


	for (int i = 0; i < 42; i++)
	{
		if (i < 5)
		{	
			//Create a gamecard and send it back
			card[i] = card[i]->createCard(act1);
		}
		//Total of 5 cards
		else if (i >= 5 && i < 10)
		{
			card[i] = card[i]->createCard(act2);
		}
		//Total of 5 cards
		else if (i >= 10 && i < 15)
		{
			card[i] = card[i]->createCard(act3);
		}
		//Total of 5 cards
		else if (i >= 15 && i < 20)
		{
			card[i] = card[i]->createCard(act4);
		}
		//Total of 5 cards
		else if (i >= 20 && i < 25)
		{
			card[i] = card[i]->createCard(act5);
		}
		//Total of 3 cards
		else if (i >= 25 && i < 28)
		{
			card[i] = card[i]->createCard(act6);
		}
		//Total of 2 cards
		else if (i >= 28 && i < 30)
		{
			card[i] = card[i]->createCard(act7);
		}
		//Total of 5 cards with anvil
		else if (i >= 30 && i < 32)
		{
			card[i] = card[i]->createCard(act8);
		}
		//Total of 8 cards with Crystal
		else if (i >= 32 && i < 34)
		{
			card[i] = card[i]->createCard(act9);
		}
		//Total of 2 cards
		else if (i >= 34 && i < 36)
		{
			card[i] = card[i]->createCard(act10);
		}
		//Total of 2 cards
		else if (i >= 36 && i < 38)
		{
			card[i] = card[i]->createCard(act11);
		}
		//Total of 2 cards
		else if (i >= 38 && i < 40)
		{
			card[i] = card[i]->createCard(act12);
		}
		//Total of 2 cards
		else if (i >= 40 && i < 42)
		{
			card[i] = card[i]->createCard(act13);
		}
	}

	//Push every card
	for (int i = 0; i < 42; i++)
	{
		deckVector.push_back(card[i]);
	}
	return deckVector;
}

/* Return the good of the card
*/
string Gamecard::getGood()
{
	return *good;
}

/* Return the action of the card
*/
string Gamecard::getAction()
{
	return *action;
}
/* Set the good of the card
*/
void Gamecard::setGood(string* gd)
{
	good = gd;
}
/* Set the action of the card
*/
void Gamecard::setAction(string* act)
{
	action = act;
}
/* Set the number of good of the card
*/
void Gamecard::setNGood(int* ngd)
{
	Ngood = ngd;
}

void Gamecard::displayCard()
{
	cout << "\nCard info:\n";
	cout << "Action: " << this->getAction() << endl;
	cout << "Good: " << this->getNGood() << " " << this->getGood() <<endl;
}

/* Return the number of goods of the card
*/
int Gamecard::getNGood()
{
	return *Ngood;
}