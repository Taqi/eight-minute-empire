#include "CardFactoryDriver.h"
using namespace std;
#include <iostream>
#include "Cardsfactory.h"

void factoryDriver()
{

	//TEST Card Factory
	cout << "Factory driver test \n";
	Gamecard* c = new Gamecard();;
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

	delete c;
	delete c2;
	delete c3;
	delete test1;
	delete test2;
	delete test3;

}
