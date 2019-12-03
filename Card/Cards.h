#pragma once
using namespace std;
#include <vector>
#include <string>
#include "../Player/Player.h"

class Deck; //forward declaration of Deck class
class Player;
class Map;

class Card
{
	public:
		~Card();
		string *action; //MOVE_OVER_WATER, PLACE_NEW_ARMIES_ON_BOARD, MOVE_OVER_LAND, BUILD_A_CITY, DESTROY_ARMY
		int *Ngood; //Number of 'good'
		string* good; //Carrot, Crystal, Tree, Anvil, Rock

		int *id; //Every card associated with an ID (number) 
		bool *outDeck = new bool(false); //Member that tells whether the card is still in the deck. Initially false (= false means not taken out of deck, = true means taken out of deck)
		bool *outHand = new bool(false); //Tells whether card is in the hand space (if = false, then no, if = true, then yes it is in the card space)

		string getGood();
		string getAction();		
		int getNGood();
		void setGood(string *gd);
		void setAction(string *act);		
		void setNGood(int* ngd);


};

class Hand
{
	public:
		~Hand();
		int *cost = new int[6]; //Cost of each card in the hand (0, 1, 1, 2, 2, 3)
		void printHand(); //Will print cards currently in hand space
		void exchange(Deck* deck, Player *player, int playerIndex, Map *map); //Method that allows user to buy a card from the hand space, and it calls the draw method to pick a new card from deck
		vector <Card*> handVector;	//Vector of Cards object for the cards faced up

		
};

class Deck
{
	private:
		const int *totalCards;

	//Since its a class its members are private by default, so need to precise public to make the members public
	public:

		Card* card[42];
		void setTotalCards(const int *tCards);
		int getTotalCards();
		void draw(Hand *hand);
		//bool* firstTime;
		bool* firstTime = new bool(true); //For draw method, if firstTime = true, then its the first draw so pick 6 cards from deck, if firsTime = false, then only draw 1 card

		//deck Will be initalized to a vector of Card objects in Cards.cpp (initially 42 card objects in the vector)
		vector <Card*> deckVector; //Note: when I did   vector <Card> *deckVector; and 	(*deckVector).reserve(*totalCards); it gave an error. Asterix need to be inside "<>" it seems.


};




