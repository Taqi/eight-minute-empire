//
// Created by james on 2019-10-11.
//
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

class Player{


private: // begin private section

    //int* armies; // the number of armies that a player has
    //int* coins; // tokens for each player
    //int* cities; // player's cities
    //int* age; // player's age to for bidding facility
    //string* name; // player's name
    //string* color; // color for each player


    //// Implementation according to the question
    //vector<string*> countries; //the regions/countries that a player has
    //vector<string*> resources; /*the resources that a given player has.*/
    //vector<Card> *handOfDeck; //the game hand that a given player has

    ////Cards*  cards; // the cards that a player has
    //Bidding* bid; // the biding facility object that a player has


public: // begin public section


    //// Constructors
    //Player(string name, int age); // Default Constructor
    //Player(string name, int numbOfPlayers, int age);

    //// Deconstructor
    //~Player();

    //// Getters
    //int* getCoins() const; // Display the player's coin
    //int* getCities() const; // Display the player's cities
    //int* getArmy() const; // Display the number of armies
    //int* getAge() const; // Return the age of player
    //string* getName() const; // Return the name of the player
    //vector<Card> *getHandOfDeck() const; // Display the number of the player's card
    //Bidding* getBidding() const; // Return the number of bidding



    //// Setters
    //void addCards(Card card); // Change the player's card
    //void setCoins(int coins); // Change the player's coins
    //void setArmy(int armies); // Change the player's armies
    //void setCities(int cities); // Change the player's cities
    //void setAge(int age); // Change the player's age
    //void setName(string name); // Change the player's name


    //// Implement Methods Declaration
    //bool payCoins(int cost); // Player who wins the bid will pay the coins
    ////bool placeNewArmies(int armies, string place, Map gameMap); // for A2 implementation
    //bool placeNewArmies(int armies, Graph &place); // Place armies on a starting point or player's cities collection
    //void moveArmies(int moves); // Move armies according to the indicated number of armies - land movement only
    //void moveOverLand(int moves); // Move between two regions(over water) as if they were adjacent
    //void buildCity(); // Place a city anywhere on the board where player has an army
    //void destroyArmy(); // Remove an army from the board belonging to any player
    //bool ignore(); // Ignore the card and end the player turn
    //void takeAction(string action, Map &gameBoard, vector<Player *> &allPlayers); // Player choose action to perform
    //void andOrAction(string action, Graph &gameBoard, vector<Player *> &allPlayers); // Two diffrent actions for player to choose

};

#endif