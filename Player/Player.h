
 //Created by james on 2019-10-11.

#ifndef COMP345A1_PLAYER_H
#define COMP345A1_PLAYER_H

#include <string>
#include <vector>
#include "../Card/Cards.h"
#include "../Bidding/Bidding.h"
#include "../Map/Map.h"


using namespace std;

class Bidding;

class Map;

class Card;

class PlayerStrategies;

class Player{


private: 

    int* armies; // the number of armies that a player has
    int* coins; // tokens for each player
    int* cities; // player's cities
    int* age; // player's age to for bidding facility
    string* name; // player's name

    vector<string*> resources; /*the resources that a given player has.*/

    Bidding* bid; // the biding facility object that a player has

	int* goodPoints = new int(0);; //Points from goods (carrots, rock, et.c)
	int* victoryPoints = new int(0); //Total amount of points for a player


public:


    // Constructors
    Player(string name, int age); // Default Constructor
    Player(string name, int numbOfPlayers, int age);

    // Deconstructor
    ~Player();

	vector <int> playerCountries;  ////Vector containing the countries a player own
	vector <int> playerContinent; //Vector containing the continents a player own
	vector<Card>* playerHand; 
	vector<Card*> pHand; //Contains the cards that a player owns
	
    // Getters
    int* getCoins() const; // Display the player's coin
    int* getCities() const; // Display the player's cities
    int* getArmy() const; // Display the number of armies
    int* getAge() const; // Return the age of player
    string* getName() const; // Return the name of the player
    vector<Card> *getPlayerHand() const; // Display the number of the player's card
    Bidding* getBidding() const; // Return the number of bidding
	PlayerStrategies* getPlayerStrategies() const;



    // Setters
    void setCoins(int coins); // Change the player's coins
    void setArmy(int armies); // Change the player's armies
    void setCities(int cities); // Change the player's cities
    void setAge(int age); // Change the player's age
    void setName(string name); // Change the player's name


    // Implement Methods Declaration
    bool payCoins(int cost); // Player who wins the bid will pay the coins

    // Place armies on a starting point or player's cities collection
	bool placeNewArmies(int player, int armiesToAdd, Map &map);

    void moveArmies(int player, int moves, Map &map); // Move armies according to the indicated number of armies - land movement only
    void moveOverLand(int player, int moves, Map& map); // Move between two regions(over water or Land) as if they were adjacent
    bool buildCity(int player, int cityToAdd, Map& map); // Place a city anywhere on the board where player has an army
    void destroyArmy(int armyToDestroy, Map& map); // Remove an army from the board belonging to any player
    bool ignore(); // Ignore the card and end the player turn
    void andOrAction(int player, string action, Map &map); // Two diffrent actions for player to choose
	void actionMethod(string choiceAction, int player, int quantity, Map& map); //Goes to approprate method according to cards action
	void addGoodPoint(int point); //Add to good points
	int getGoodPoint();
	void addVictoryPoint(int point); //Add to total points
	int getVictoryPoint();
	void setGoodPoint(int points);
	void setVictoryPoint(int points);

	bool placeArmyValidation(Map& map, int player, int country); //Method that validates for the place new army action
	bool buildCityValidation(Map& map, int player, int country); //Method that validates for the build city action
	bool destroyArmyValidation(Map& map, int player, int country); //Method that validates for the destroy army action
	bool moveArmiesFromValidation(Map& map, int country, int player); //Method that validates for moving an army from
	bool moveArmiesToValidation(Map& map, int srs, int dest, int player); //Method that validates for moving an army to
	bool moveOverWaterValidation(Map& map, int srs, int dest, int player); //Method that validates if army can move over water

	void setPlayerStrategies(PlayerStrategies* newPlayerStrategies);
};

#endif