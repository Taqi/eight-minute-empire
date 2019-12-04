#pragma once
#include <string>
#include <vector>
using namespace std;

class Gamecard;

//This class will use the CardsFactory to create cards of different types
class GameDeck
{
private:
	const int* totalCards;

public:

	//GameDeck();
	//~GameDeck();

	Gamecard* card[42];
	void setTotalCards(const int* tCards);
	int getTotalCards();
	//void draw(Hand* hand);
	//bool* firstTime;
	bool* firstTime = new bool(true); //For draw method, if firstTime = true, then its the first draw so pick 6 cards from deck, if firsTime = false, then only draw 1 card

	//deck Will be initalized to a vector of Card objects in Cards.cpp (initially 42 card objects in the vector)
	vector <Gamecard*> deckVector; //Note: when I did   vector <Card> *deckVector; and 	(*deckVector).reserve(*totalCards); it gave an error. Asterix need to be inside "<>" it seems.

	vector <Gamecard*> createDeck(); //Create deck and returns it

	void displayDeck();
};


//Cardsfactory interface
class CardsFactory
{
public:
	virtual Gamecard* createCard(string* type) = 0;	
	
	string* action; //MOVE_OVER_WATER, PLACE_NEW_ARMIES_ON_BOARD, MOVE_OVER_LAND, BUILD_A_CITY, DESTROY_ARMY
	int* Ngood; //Number of 'good'
	string* good; //Carrot, Crystal, Tree, Anvil, Rock

	int* id; //Every card associated with an ID (number) 
	//bool* outDeck = new bool(false); //Member that tells whether the card is still in the deck. Initially false (= false means not taken out of deck, = true means taken out of deck)
	//bool* outHand = new bool(false); //Tells whether card is in the hand space (if = false, then no, if = true, then yes it is in the card space)

	virtual string getGood() = 0;
	virtual string getAction() = 0;
	virtual int getNGood() = 0;
	virtual void setGood(string* gd) = 0;
	virtual void setAction(string* act) = 0;
	virtual void setNGood(int* ngd) = 0;
	virtual void displayCard() = 0;
};

//Concrete Cardsfactory
class Gamecard: public CardsFactory
{
public:
	~Gamecard();
	Gamecard* createCard(string* type); //Creates a card and return it

	string getGood();
	string getAction();
	int getNGood();
	void setGood(string* gd);
	void setAction(string* act);
	void setNGood(int* ngd);
	void displayCard(); //Display the single card

	int* seed = new int(0);
};

