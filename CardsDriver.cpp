#include <iostream>
#include <vector>
#include "Cards.h"
using namespace std;

void CardDriver()
{
	//Create deck object
	Deck* deck = new Deck();

	//int *totalNumberCards;
	int* totalCards = new int(42); // Does not create 42 elements, but initializes totalCard to 42

	(*deck).setTotalCards(totalCards);

	//Create hand object
	Hand* hand = new Hand();

	(*deck).draw();

	/*int *value = (*deck).getTotalCards;
	cout << *value;*/
}