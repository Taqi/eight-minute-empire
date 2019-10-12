//
// Created by james on 2019-10-11.
//

#include <string>
#include <vector>
#include "Country.h"
#include "Card.h"
#include "Biding.h"
#include "Army.h"
#include "Resource.h"

using namespace std;

class Player{



private: // begin private section

    int* playerID; // id for each player
    int* coins; // tokens for each player
    string* color; // color for each player
    int* objCounter; // determine player color
    int* score;

    vector<Army*> armies; // the number of armies that a player has
    vector<Country*> countries; //the regions/countries that a player has
    vector<Resource*> resources; /*the resources that a given player has.*/
    vector<Card* > cards; // the cards that a player has
    vector<Biding* > bid; // the biding facility object that a player has


public: // begin public section


    // Constructors
    Player(); // Default Constructor
    Player(int playerID);

    // Getters
    int getScore(); // Display the player's score
    int getCoins(); // Display the player's coin
    int getID(); // Display the player's id
    int getColor(); // Display the player's color
    vector<Army*> getArmy(); // Display the number of armies
    vector<Card*> getCards(); // Display the number of the player's card
    int getResourceUnities(int* i); // Returns the number of resources of received ID


    // Setters
    int setCoins(int* coins); // Change the player's coins
    int addScore(int* i); // Adds score to the player's scoreboard


    vector<Country*> getCountries(); // Return the collections of countries that a player owns
    vector<Country*> addCountries(); // Adds a country to the player's country collection

    void supply(); // Player get their coin tokens


    // Implement Methods Declaration
    void payCoins(int coins); // Player who wins the bid will pay the coins
    void placeNewArmies(); // Place armies on a starting point or player's cities collection
    void moveArmies(); // Move armies according to the indicated number of armies - land movement only
    void moveOverLand(); // Move between two regions(over water) as if they were adjacent
    void buildCity(); // Place a city anywhere on the board where player has an army
    void destroyArmy(); // Remove an army from the board belonging to any player


};




