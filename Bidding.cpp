//
// Created by james on 2019-10-11.
//

#include "Bidding.h"
#include <iostream>

using namespace std;

Bidding::Bidding()
{
    Bidding::bid = new int(0);
}

int Bidding::biddingPhase(vector<Player*> players, int numbOfPlayers)
{
    int bid, highest;
    // Make a loop through the player array instead of this array
    //int bidArray [numbOfPlayers];
	int bidArray[5];
    int highestBidder = 0;

    // Eeach player makes a bid
    for (int i = 0; i < numbOfPlayers; i++)
    {
        cout << "How much would you like to bid " << *(players[i]->getName()) << " ?" << endl;
        cin >> bid;
        players[i]->getBidding()->setBid(bid);
        // Remove this sloppy code
        bidArray[i] = *(players[i]->getBidding()->getBid());
    }

    // Test code to display the array
    for (int i = 0; i < numbOfPlayers; i++)
    {
        cout << *(players[i]->getName()) << " has bid " << bidArray[i] << " coins" << endl;
    }

    // Set the highest bid to the first array
    highest = bidArray[0];

    // A bid is made by compared who has the highest bid and index of highest bidder gets returned
    for (int i = 0; i < numbOfPlayers-1; i++)
    {
        if( highest < bidArray[i +1] )
        {
            highestBidder = i + 1;
            highest = bidArray[i + 1];
        }
        // The youngest player wins the bid when bids are tied or all the bids are zero
        if ( highest == bidArray[i+1] )
        {
            if( *(players[highestBidder]->getAge()) > (*(players[i+1]->getAge())))
            {
                highestBidder = i + 1;
            }
        }
    }

    players[highestBidder]->payCoins(*(players[highestBidder]->getBidding()->getBid()));

    return highestBidder;
}

int* Bidding::getBid() const
{
    return bid;
}

void Bidding::setBid(int bid)
{
    *Bidding::bid = bid;
}

