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
	MapDriver(); //Will remove since MapLoaderDriver calls map class
	PlayerDriver();
	CardDriver();
	BiddingDriver();
}
