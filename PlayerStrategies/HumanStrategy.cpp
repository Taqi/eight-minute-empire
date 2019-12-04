#include "HumanStrategy.h"
#include "PlayerStrategies.h"
#include "../Player/Player.h"
#include <iostream>

using namespace std;

class Map;
class Player;


void HumanStrategy::moveArmies(int Player, int moves, Map& map)
{
	cout << "Human Player That Requires User Interaction To Make Decision!\n";

	while (moves > 0)
	{
		cout << "You have armies in the following locations " << endl;
		//map.printMap();

		int countrySource;
		cout << "\nPlease select a region in which to move an army from: ";
		cin >> countrySource;

		int countryDest;
		cout << "\nPlease select a region in which to move an army to ";
		cin >> countryDest;

		map.playerArmyCountryArray[countrySource].head->cityArmyPair[Player].first--;
		map.playerArmyCountryArray[countryDest].head->cityArmyPair[Player].first++;

		cout << "Sucessfully moved 1 army from " << countrySource << " to " << countryDest << "." << endl;
		moves--;
	}

}

void HumanStrategy::moveOverLand(int player, int moves, Map& map)
{
	cout << "-Move Over Land CARD-\n";
	while (moves > 0)
	{
		cout << "You have armies in the following locations " << endl;
		//map.printMap();

		int countrySource;
		cout << "\nPlease select a region in which to move an army from: ";
		cin >> countrySource;

		int countryDest;
		cout << "\nPlease select a region in which to move an army to ";
		cin >> countryDest;

		map.playerArmyCountryArray[countrySource].head->cityArmyPair[player].first--;
		map.playerArmyCountryArray[countryDest].head->cityArmyPair[player].first++;

		cout << "Sucessfully moved 1 army from " << countrySource << " to " << countryDest << "." << endl;
		moves--;
	}

	//map.printMap();
}

void HumanStrategy::buildCity(int player, int cityToAdd, Map& map)
{
	//return false;
}

bool HumanStrategy::placeNewArmies(int player, int armiesToAdd, Map& map)
{
	return false;
}

bool HumanStrategy::ignore()
{
	return false;
}
