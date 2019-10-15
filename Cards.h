#pragma once
using namespace std;
#include <vector>

class Cards
{
	public:
		int *action;
		int *good;
		int *id; //Every card associated with an ID (number) 
		bool *outDeck = new bool(false); //Member that tells whether the card is still in the deck. Initially false (= false means not taken out of deck, = true means taken out of deck)
		bool *outHand = new bool(false); //Tells whether card is in the hand space (if = false, then no, if = true, then yes it is in the card space)

		int getGood();
		int getAction();
		void setGood(int *gd);
		void setAction(int *act);
};

class Deck
{
	private:
		const int *totalCards;

	//Since its a class its members are private by default, so need to precise public to make the members public
	public:
		void setTotalCards(const int *tCards);
		int getTotalCards();
		void draw();
		//deck Will be initalized to a vector of Card objects in Cards.cpp (initially 42 card objects in the vector)
		vector <Cards*> deckVector; //Note: when I did   vector <Card> *deckVector; and 	(*deckVector).reserve(*totalCards); it gave an error. Asterix need to be inside "<>" it seems.
};


class Hand
{
	public:
		int *cost = new int[6]; //Cost of each card in the hand (0, 1, 1, 2, 2, 3)

		void printHand(); //Will print cards currently in hand space
		void exchange();

		//Vector of Cards object for the cards faced up
		vector <Cards*> handVector;
};
