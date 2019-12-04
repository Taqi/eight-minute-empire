#include "CardFactoryDriver.h"
using namespace std;
#include <iostream>
#include "Cardsfactory.h"

void factoryDriver()
{

	//TEST Card Factory
	cout << "Factory driver test \n";
	cout << "Create cards individually\n";
	Gamecard* c = new Gamecard();
	string* test1 = new string("PLACE_NEW_ARMIES_ON_BOARD 1");
	c = c->createCard(test1);
	c->displayCard();

	Gamecard* c2 = new Gamecard();;
	string* test2 = new string("BUILD_A_CITY 1");
	c2 = c2->createCard(test2);
	c2->displayCard();

	Gamecard* c3 = new Gamecard();;
	string* test3 = new string("PLACE_NEW_ARMIES_ON_BOARD 1 OR BUILD_A_CITY 1");
	c3 = c3->createCard(test3);
	c3->displayCard();

	cout << "\n\n-------------Create a deck test-------------------\n";
	GameDeck* d = new GameDeck();
	d->createDeck();
	d->displayDeck();
	


	delete c;
	c = NULL;
	delete c2;
	c2 = NULL;
	delete c3;
	c3 = NULL;
	delete test1;
	test1 = NULL;
	delete test2;
	test2 = NULL;
	delete test3;
	test3 = NULL;
	delete d;
	d = NULL;

}
