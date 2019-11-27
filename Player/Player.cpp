
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include "Player.h"
#include "../Map/Map.h"
#include "../Bidding/Bidding.h"

using namespace std;

// Constructor
Player::Player (string name, int age)
{
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::coins = new int(14);
    Player::name = new string(name);
    Player::age = new int(age);
    Player::bid = new Bidding();
    Player::getPlayerHand() == new vector<Card>();
}

Player::Player(string name, int numbOfPlayers, int age)
{
    Player::cities = new int(3);
    Player::armies = new int(14);
    Player::name = new string(name);
    Player::age = new int(age);
    Player::bid = new Bidding();
    Player::getPlayerHand() == new vector<Card>();

    // Determine the amount of token/coins to players by number of players
    switch (numbOfPlayers)
    {
        case 2:
            Player::coins = new int(14);
            break;
        case 3:
            Player::coins = new int(11);
            break;
        case 4:
            Player::coins = new int(9);
            break;
        case 5:
            Player::coins = new int(8);
            break;
    }
}

// Destructor
Player::~Player()
{
    if (coins) {
        delete coins;
        coins = NULL;
    }

    if (armies) {
        delete armies;
        armies = NULL;
    }
    if (cities) {
        delete cities;
        cities = NULL;
    }
    if (age) {
        delete age;
        age = NULL;
    }
    if (name) {
        delete name;
        name = NULL;
    }


    if (playerHand) {
        delete playerHand;
        playerHand = NULL;
    }
    //if (bid) {
    //    delete bid;
    //    bid = NULL;
    //}
}

bool Player::payCoins(int cost)
{
    if (*(this->getCoins()) < cost)
    {
        cout << "Insufficient coins to make this purchase." << endl;
        return false;
    }
    else
    {
        this->setCoins(*(this->getCoins()) - cost);
        cout << "Purchase Successfully!! You have " << *(this->getCoins()) << " amount of coins remaining." << endl;
        return true;
    }
}

//This method allows player to move " << moves << " armies across land/over sea.
void Player::moveOverLand(int player, int moves, Map& map)
{
	cout << "\n-Move Over Land CARD-\n";
	while (moves > 0)
	{
		int countrySource;
		cout << "\nPlease select a region in which to move an army from: ";
		cin >> countrySource;

		int countryDest;
		cout << "\nPlease select a region in which to move an army to ";
		cin >> countryDest;

		map.playerArmyCountryArray[countrySource].head->cityArmyPair[player].first--;
		map.playerArmyCountryArray[countryDest].head->cityArmyPair[player].first++;

		cout << "Player " << player << " sucessfully moved 1 army from " << countrySource << " to " << countryDest << "." << endl;
		moves--;
	}

}

//This method allows player to build city.
bool Player::buildCity(int player, int cityToAdd, Map& map)
{
	cout << "\n-BUILD CITY CARD-\n";

	// check to see if player has available cities to place
	if (*cities == 0)
	{
		cout << "Sorry, " << *name << "you have no more available cities." << std::endl;
		return false;
	}

	//Display adjacent countries to show where they can put city
	map.printAllAdjacentCountries();

	while (cityToAdd > 0)
	{
		int country;
		cout << *name <<", select a country (index) to place a city: ";
		cin >> country;
		(*cities)--;
		map.playerArmyCountryArray[country].head->cityArmyPair[player].second++;
		cityToAdd--;
		cout << "Player " << player << " successfully added a city" << endl;
	}

	return true;
}

//This method allows player to destroy other player's armies
void Player::destroyArmy(int armyToDestroy, Map& map)
{
	cout << "\n-DESTROY ARMY CARD-\n";
	while (armyToDestroy > 0)
	{
		int playerDestroyed;
		cout << *name << ", select a player (ex: index 0) to destroy one of their armies: ";
		cin >> playerDestroyed;


		int country;
		cout << endl << "\nSelect a country: ";
		cin >> country;

		map.playerArmyCountryArray[country].head->cityArmyPair[playerDestroyed].first = map.playerArmyCountryArray[country].head->cityArmyPair[playerDestroyed].first--;

		armyToDestroy--;
		cout << "Player " << " successfully destroyed an army" << endl;
	}

}

bool Player::placeNewArmies(int player, int armiesToAdd, Map& map)
{
	cout << "\n-PLACE NEW ARMIES CARD-\n";
	// check to see if player has available armies to place
	if (*armies == 0)
	{
		cout << "Sorry, " << *name << " you have no more available armies." << endl;
		return false;
	}

	// place new armies
	for (int i = 0; i < armiesToAdd; i++)
	{
		int country;
		cout << "\nSelect a region in which you like to place an army: ";
		cin >> country;

		(*armies)--;

		map.playerArmyCountryArray[country].head->cityArmyPair[player].first++;
		cout << "Player " << player << " successfully added an army" <<endl;
	}

	return true;
	
}

void Player::moveArmies(int player, int moves, Map &map)
{
	cout << "\n-MOVE ARMIES CARD-\n";
	while (moves > 0)
	{

		int countrySource;
		cout << "\nPlease select a region in which to move an army from: ";
		cin >> countrySource;

		int countryDest;
		cout << "\nPlease select a region in which to move an army to ";
		cin >> countryDest;

		map.playerArmyCountryArray[countrySource].head->cityArmyPair[player].first--;
		map.playerArmyCountryArray[countryDest].head->cityArmyPair[player].first++;

		cout << "Player " << player << " sucessfully moved 1 army from " << countrySource << " to " << countryDest << "." << endl;
		moves--;
	}
}


bool Player::ignore()
{
    bool invalidAnswer = true;
    string answer;
    cout <<endl<< *name << ", would you like to use the action on the card (y or n)? ";
    do {
        cin >> answer;
        if (answer == "y" || answer == "n") {
            invalidAnswer = false;
        }
        else {
            cout << "Invalid answer. Answer with y or n: ";
        }
    } while (invalidAnswer);
    return (answer == "y"); //Return true if answer is yes (dont want to ignore), else return false (want to ignore action)
}


//Goes to approprate method according to cards action
void Player::actionMethod(string choiceAction, int player, int quantity, Map &map)
{
	if (choiceAction == "MOVE_OVER_WATER") {
		moveArmies(player, quantity, map);
	}
	else if (choiceAction == "MOVE_OVER_LANND") {
		moveArmies(player, quantity, map);
	}
	else if (choiceAction == "PLACE_NEW_ARMIES_ON_BOARD") {
		placeNewArmies(player, quantity, map);
	}
	else if (choiceAction == "BUILD_A_CITY") {
		buildCity(player, quantity, map);
	}
	else if (choiceAction == "DESTROY_ARMY") {
		destroyArmy(quantity, map);
	}
}

//Increment the good (carrots, rocks, etc.) points a player has
void Player::addGoodPoint(int point)
{
	(*goodPoints)+= point;
}

int Player::getGoodPoint()
{
	return *goodPoints;
}

//Increment the total points a player has
void Player::addVictoryPoint(int point)
{
	(*victoryPoints)+= point;
}

int Player::getVictoryPoint()
{
	return *victoryPoints;
}

void Player::setGoodPoint(int points)
{
	(*goodPoints) = points;
}

void Player::setVictoryPoint(int points)
{
	*(victoryPoints) = points;
}

//Method that will the other methods depending on what the action is (action is the string telling the action of the card)
void Player::andOrAction(int player, string action, Map &map)
{
	cout << "-" <<action << " card-\n";
    int choice;
	string choiceAction;
	int quantity;

    if (action.find("OR") != string::npos) //find returns the position (zero based offset) in the string where the word is found. If the word is not found it returns npos.
	{
        // split string into two halves
        string firstAction = action.substr(0, action.find("OR"));
        string secondAction = action.substr(action.find("OR") + 3);

        cout << *name << ", choose one of the 2 actions (1 or 2): " << endl;
        cout << "1 - " << firstAction << endl;
        cout << "2 - " << secondAction << endl;
		cin >> choice;



		string choiceAction;
        if (choice == 1) 
		{

			choiceAction = firstAction.substr(0, firstAction.find(" "));
			quantity = stoi(firstAction.substr(firstAction.find(" ") + 1));
        }
        else 
		{
			choiceAction = secondAction.substr(0, secondAction.find(" "));
			quantity = stoi(secondAction.substr(secondAction.find(" ") + 1));
        }

		actionMethod(choiceAction, player, quantity, map);
    }
    else {
        // split string into two halves
        string firstAction = action.substr(0, action.find("AND"));
        string secondAction = action.substr(action.find("AND") + 4);

        cout << *name << ", take 1 action or 2 actions? (1 or 2): " << endl;
        cout << "1 - " << firstAction << endl;
        cout << "2 - " << secondAction << endl;
		int answer;
		cin >> answer;

         //player only wants to use one of the actions
        if (answer == 1) 
		{
            cout << "Please select one of the above actions by entering '1' or '2': ";
			cin >> choice;

			string choiceAction;
			int quantity;

            if (choice == 1) 
			{
				choiceAction = firstAction.substr(0, firstAction.find(" "));
				quantity = stoi(firstAction.substr(firstAction.find(" ") + 1));

				actionMethod(choiceAction, player, quantity, map);
            }
            else 
			{
				choiceAction = secondAction.substr(0, secondAction.find(" "));
				quantity = stoi(secondAction.substr(secondAction.find(" ") + 1));
				actionMethod(choiceAction, player, quantity, map);
            }
        }
        //player wants to use both actions
        else 
		{
            cout << "Which action would you like to use first? Please select one of the above actions by entering '1' or '2': ";
			int first;
			cin >> first;

            if (first == 1) 
			{
				//First action
				choiceAction = firstAction.substr(0, firstAction.find(" "));
				quantity = stoi(firstAction.substr(firstAction.find(" ") + 1));
				actionMethod(choiceAction, player, quantity, map);

				//Second action
				choiceAction = secondAction.substr(0, secondAction.find(" "));
				quantity = stoi(secondAction.substr(secondAction.find(" ") + 1));
				actionMethod(choiceAction, player, quantity, map);
            }
            else 
			{
				//Second action
				choiceAction = secondAction.substr(0, secondAction.find(" "));
				quantity = stoi(secondAction.substr(secondAction.find(" ") + 1));
				actionMethod(choiceAction, player, quantity, map);

				//First action
				choiceAction = firstAction.substr(0, firstAction.find(" "));
				quantity = stoi(firstAction.substr(firstAction.find(" ") + 1));
				actionMethod(choiceAction, player, quantity, map);
            }
        }
    }
}


int* Player::getCoins() const {
    return coins;
}

int* Player::getArmy() const {
    return armies;
}

int* Player::getCities() const {
    return cities;
}

int *Player::getAge() const {
    return age;
}

string *Player::getName() const {
    return name;
}

vector<Card> *Player::getPlayerHand() const {
    return playerHand;
}

Bidding *Player::getBidding() const {
    return bid;
}

// Setters
void Player::setCoins(int coins) {
    *Player::coins = coins;
}

void Player::setArmy(int armies){
    *Player::armies = armies;
}

void Player::setCities(int cities) {
    *Player::cities = cities;
}

void Player::setAge(int age){
    *Player::age = age;
}

void Player::setName(string name) {
    *Player::name = name;
}


