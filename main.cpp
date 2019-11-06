#include <iostream>
#include "Player.h"
#include "PlayerDriver.h"
#include "BiddingDriver.h"
#include "MapDriver.h"
#include "MapLoaderDriver.h"
#include "CardDriver.h"


int main()
{
	
	MapLoaderDriver();
	MapDriver(); //Has some duplicates with MapLoaderDriver
	//PlayerDriver();
	//CardDriver();
	//BiddingDriver();
}
