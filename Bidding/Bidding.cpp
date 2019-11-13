//
// Created by james on 2019-10-11.
//

#include "Bidding.h"
#include <iostream>

using namespace std;

// Constructor
Bidding::Bidding()
{
	Bidding::bid = new int(0);
}


int Bidding::biddingPhase(vector<Player*> players, int numbOfPlayers)
{

	// Local varibles
	int bid, highest;

	// Each player makes a bid
	for (int i = 0; i < numbOfPlayers; i++)
	{//*(players[i]->getName())
		cout << "How much would you like to bid " << players[i]->getName() << " ?" << endl;
		cin >> bid;
		// Verify if a player could afford the bidding
		while (bid < 0 || bid > *(players[i]->getCoins()))
		{
			cout << "INVALID BID! Enter an affordable bid between 0 and " << players[i]->getCoins() << ": ";
			cin >> bid;
		}
		players[i]->getBidding()->setBid(bid);
	}


	// Set the highest bid to the first array
	int highestBidder = 0;
	highest = players[0]->getBidding()->getBid();

	// A bid is made by compared who has the highest bid and index of highest bidder gets returned
	for (int i = 0; i < numbOfPlayers - 1; i++)
	{
		if (highest < players[i + 1]->getBidding()->getBid())
		{
			highestBidder = i + 1;
			highest = players[i + 1]->getBidding()->getBid();
		}
		// The youngest player wins the bid when bids are tied or all the bids are zero
		if (highest == players[i + 1]->getBidding()->getBid()
			&& players[highestBidder]->getAge() > players[i + 1]->getAge())
		{
			highestBidder = i + 1;
		}
	}

	// Highest bidder pays the cost
	players[highestBidder]->payCoins(players[highestBidder]->getBidding()->getBid());

	return highestBidder;
}

int Bidding::getBid() const
{
	return *bid;
}

void Bidding::setBid(int bid)
{
	*Bidding::bid = bid;
}