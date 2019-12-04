#include "Cards.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "../Player/Player.h"
using namespace std;

void Deck::setTotalCards(const int *tCards)
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

	//Every possible good: Carrot, Crystal, Tree, Anvil, Rock
	string* good1 = new string("Carrot");
	string* good2 = new string("Rock");
	string* good3 = new string("Tree");
	string* good4 = new string("Anvil");
	string* good5 = new string("Crystal");

	//Every possible Ngood
	int* n = new int(1);
	int* n2 = new int(2);
	
	//Set the total amount of cards in the deck to the value specified in the driver
	totalCards = tCards;

	//Reserve 42 spots (number in totalCards) in the vector
	deckVector.reserve(*totalCards);

	int idNumber;

	//Initialize *totalCards amount of card objects
	for (int i = 0; i < *totalCards; i++)
	{
		//Create 42 card objects, and push each into the vector
		card[i] = new Card();

		//Set the card id
		card[i]->id = new int(i);
		//cout << *(card[i]->id) << endl; //Prints every card
	
		/*Set Ngood, action, good for each card*/

		//Set Ngood (1 or 2 for each card, so that means 1 carrot/1 crystal/1 rock\2 carrot\2 trees, etc. for each card. 33 cards with 1 ngood, 9 cards with 2 ngood----------------
		if (i < 33)
		{
			card[i]->setNGood(n);
		}
		else if (i >= 33 && i < 42)
		{
			card[i]->setNGood(n2);
		}

		//Set good for each card------------------------------
		//Total of 10 cards with carrot
		if (i < 10)
		{
			card[i]->setGood(good1);
		}
		//Total of 10 cards with rock
		else if (i >= 10 && i < 20)
		{
			card[i]->setGood(good2);
		}
		//Total of 10 cards with tree
		else if (i >= 20 && i < 30)
		{
			card[i]->setGood(good3);
		}
		//Total of 5 cards with anvil
		else if (i >= 30 && i < 35)
		{
			card[i]->setGood(good4);
		}

		//Total of 8 cards with Crystal
		else if (i >= 35 && i < 42)
		{
			card[i]->setGood(good5);
		}


		//Set action for each card --------------------------------------
		//Total of 5 cards
		if (i < 5)
		{
			card[i]->setAction(act1);
		}
		//Total of 5 cards
		else if (i >= 5 && i < 10)
		{
			card[i]->setAction(act2);
		}
		//Total of 5 cards
		else if (i >= 10 && i < 15)
		{
			card[i]->setAction(act3);
		}
		//Total of 5 cards
		else if (i >= 15 && i < 20)
		{
			card[i]->setAction(act4);
		}
		//Total of 5 cards
		else if (i >= 20 && i < 25)
		{
			card[i]->setAction(act5);
		}
		//Total of 3 cards
		else if (i >= 25 && i < 28)
		{
			card[i]->setAction(act6);
		}
		//Total of 2 cards
		else if (i >= 28 && i < 30)
		{
			card[i]->setAction(act7);
		}
		//Total of 5 cards with anvil
		else if (i >= 30 && i < 32)
		{
			card[i]->setAction(act8);
		}
		//Total of 8 cards with Crystal
		else if (i >= 32 && i < 34)
		{
			card[i]->setAction(act9);
		}
		//Total of 2 cards
		else if (i >= 34 && i < 36)
		{
			card[i]->setAction(act10);
		}
		//Total of 2 cards
		else if (i >= 36 && i < 38)
		{
			card[i]->setAction(act11);
		}
		//Total of 2 cards
		else if (i >= 38 && i < 40)
		{
			card[i]->setAction(act12);
		}
		//Total of 2 cards
		else if (i >= 40 && i < 42)
		{
			card[i]->setAction(act13);
		}

		//Push every card in the vector of deck
		deckVector.push_back(card[i]);
	}
	
}
//Return the total number of cards
int Deck::getTotalCards()
{
	return *totalCards;
}

/* 
The deck must have a draw() method that allows a player to draw a card from the cards remaining in the deck and place it in with the cards space. 
6 cards are to be drawn at the beginning, and then 1 for each time a card is removed (bought by a player).
*/
void Deck::draw(Hand *hand)
{

	//Draw randomly from deck
	srand(time(NULL)); //initialize the random seed
	int randIndex; 

	//Allocate cost to each card in hand;
	hand->cost[0] = 0;
	hand->cost[1] = 1;
	hand->cost[2] = 1;
	hand->cost[3] = 2;
	hand->cost[4] = 2;
	hand->cost[5] = 3;

	
	//Just a true value that we can make our pointer point to
	bool trueValue = true;	
	
	if (*firstTime == true)
	{
		cout << "Draw method (at start - 6 cards are drawn)" << endl; //At the beginning we draw 6 cards, but later on only 1 card
		//Note: Need to make so that the same random card does not get picked
		for (int i = 0; i < 6; i++)
		{
			randIndex = rand() % (*totalCards); //will generates a random number between 0 and totalCards(so if totalCards is 42, then random value between 0 and 42)

			//Take out 6 cards from the deck, and make the hand vector objects point to them
			if (*(deckVector[randIndex]->outDeck) == 0) //If the card with that index is still in the deck, then put it in the hand 
			{
				(*hand).handVector.push_back(deckVector[randIndex]);
			}
			//Card is already out of deck, so take out another random card instead
			else
			{
				i--; //Decrement and go back to loop
				continue;
			}

			deckVector[randIndex]->outDeck = &trueValue; //When taking out a card from the deck, initialize member outDeck to true, meaning it got taken out of the deck. //Note: *(deckVector[randIndex]->out) gives 1 now (means true) for that particular index
			//hand->handVector[randIndex]->outHand = &trueValue; //Since card got taken out of deck, and placed in card space, initialize outHand to true

			cout << "Card: " << randIndex << " taken out of deck." << endl;
		}
		*firstTime = false;

		hand->printHand(); //Print current hand space
	}


	else
	{
		cout << endl << "Draw method (during game - only 1 card is drawn)" << endl;
		for (int i = 0; i < 1; i++)
		{
			randIndex = rand() % (*totalCards);

			if (*(deckVector[randIndex]->outDeck) == 0)
			{
				(*hand).handVector.push_back(deckVector[randIndex]);
			}
			//Card is already out of deck, so take out another random card instead
			else
			{
				i--; //Decrement and go back to loop
				continue;
			}

			deckVector[randIndex]->outDeck = &trueValue;

			cout << "Card: " << randIndex << " drawn from deck and put in hand space." << endl;

			hand->printHand(); //Print current hand space
		}
	}

}


Hand::~Hand()
{
	delete cost;
	cost = NULL;
}

/*
Prints hand space
*/
void Hand::printHand()
{
	cout <<endl << "Cards currently in the card space: " <<endl;
	//Cards currently in card space
	for (int i = 0; i < 6; ++i)
	{
		cout << "Index: " << i << ", Card number: " << *(handVector[i]->id) << "  "; 
		cout << "||Action: " << *(handVector[i]->action) << "  ";
		cout << "||Good: " << *(handVector[i]->Ngood) << "  ";
		cout << *(handVector[i]->good) << "  ";
		//Print with cost of card
		cout << "||Cost: " << cost[i] <<endl;
	}

}


/*
The hand object is a collection of cards that has an exchange () method that allows the player to select the card from its position in the row 
and pay the coin cost listed at the top of the board
*/
void Hand::exchange(Deck *deck, Player *player, int playerIndex, Map *map)
{
	//Player selects a card in the hand space		
	int n;

	do
	{
		cout << endl << *(player->getName()) << ", Which card do you want to buy (index)? ";
		cin >> n;

		if (cin.fail())
		{
			cout << "Invalid, not an integer.\n";
			cin.clear();
			cin.ignore();
			n = -1;
		}
		
	} while (n != 0 && n != 1 && n != 2 && n != 3 && n != 4 && n != 5);

	cout << endl << "Card " << *(handVector[n]->id) << ", " << handVector[n]->getAction() << " is no longer in the hand space." << endl;

	cout << "Player " << *(player->getName()) << " selects card: " << handVector[n]->getAction() << " and pays " << cost[n] << " coins." << endl;
	//Add card to the hand vector of the player
	//player->playerHand->push_back(deck->card[n]);
	player->pHand.push_back(handVector[n]);

	//Action of the card
	//First seperate action with quantity (ex: action = "build_city", quantity = 2)
	string choiceAction = handVector[n]->getAction().substr(0, handVector[n]->getAction().find(" "));
	int quantity = stoi(handVector[n]->getAction().substr(handVector[n]->getAction().find(" ") + 1));

	//Ask player if he wants to ignore the action
	bool ignore = player->ignore();
	if (ignore == true)
	{
		//If its not a and/or card
		if ((handVector[n]->getAction().find("OR") == string::npos && handVector[n]->getAction().find("AND") == string::npos))
		{
			player->actionMethod(choiceAction, playerIndex, quantity, *map);
		}
		else
		{
			player->andOrAction(playerIndex, handVector[n]->getAction(), *map);
		}
	}

	else
	{
		cout << "\nAction ignored.\n";
	}

	handVector.erase(handVector.begin() + n); //Remove card at nth index (it moves the rest of cards to the front/left)
	deck->draw(this); //Draw a new card from deck to put it in handspace
}
Card::~Card()
{
	delete outHand;
	delete outDeck;
	outHand = NULL;
	outDeck = NULL;
}
/* Return the good of the card
*/
string Card::getGood()
{
	return *good;
}

/* Return the action of the card
*/
string Card::getAction()
{
	return *action;
}
/* Set the good of the card
*/
void Card::setGood(string *gd)
{
	good = gd;
}
/* Set the action of the card
*/
void Card::setAction(string *act)
{
	action = act;
}
/* Set the number of good of the card
*/
void Card::setNGood(int* ngd)
{
	Ngood = ngd;
}

/* Return the number of goods of the card
*/
int Card::getNGood()
{
	return *Ngood;
}

