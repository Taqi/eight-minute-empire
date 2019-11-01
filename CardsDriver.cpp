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

	//Create hand object (hand space)
	Hand* hand = new Hand();

	//Draw 6 cards for the hand space
	(*deck).draw(hand);
	//exchange lets user buy a card and it draws a new card from the deck
	hand->exchange(deck);
	hand->exchange(deck);
	hand->exchange(deck);

}