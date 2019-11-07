//
// Created by james on 2019-10-11.
//

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include "Player.h"
#include "../Map/Map.h"
#include "../Bidding/Bidding.h"

using namespace std;

//// Constructor
//Player::Player (string name, int age)
//{
//    Player::cities = new int(3);
//    Player::armies = new int(14);
//    Player::coins = new int(14);
//    Player::name = new string(name);
//    Player::age = new int(age);
//    Player::bid = new Bidding();
//    Player::getHandOfDeck() == new vector<Card>();
//}
//
//Player::Player(string name, int numbOfPlayers, int age)
//{
//    Player::cities = new int(3);
//    Player::armies = new int(14);
//    Player::name = new string(name);
//    Player::age = new int(age);
//    Player::bid = new Bidding();
//    Player::getHandOfDeck() == new vector<Card>();
//
//    // Determine the amount of token/coins to players by number of players
//    switch (numbOfPlayers)
//    {
//        case 2:
//            Player::coins = new int(14);
//            break;
//        case 3:
//            Player::coins = new int(11);
//            break;
//        case 4:
//            Player::coins = new int(9);
//            break;
//        case 5:
//            Player::coins = new int(8);
//            break;
//    }
//}
//
//// Destructor
//Player::~Player()
//{
//    if (coins) {
//        delete coins;
//        coins = NULL;
//    }
//
//    if (armies) {
//        delete armies;
//        armies = NULL;
//    }
//    if (cities) {
//        delete cities;
//        cities = NULL;
//    }
//    if (age) {
//        delete age;
//        age = NULL;
//    }
//    if (name) {
//        delete name;
//        name = NULL;
//    }
//
//
//    if (handOfDeck) {
//        delete handOfDeck;
//        handOfDeck = NULL;
//    }
//    if (bid) {
//        delete bid;
//        bid = NULL;
//    }
//}
//
//// Implemented Methods
//bool Player::payCoins(int cost)
//{
//    if (*(this->getCoins()) < cost)
//    {
//        cout << "Insufficient coins to make this purchase." << endl;
//        return false;
//    }
//    else
//    {
//        this->setCoins(*(this->getCoins()) - cost);
//        cout << "Purchase Successfully!! You have " << *(this->getCoins()) << " amount of coins remaining." << endl;
//        return true;
//    }
//}
//
//bool Player::placeNewArmies(int armies, Graph &gameboard)
//{
//    // Verify if the player has an available armies to place
//    if (armies == 0)
//    {
//       cout << "Unavailable Armies To Place" << endl;
//       return false;
//    }
//
//}
//
//void Player::moveOverLand(int moves)
//{
//    cout << "This method allows player to move " << moves << " armies across land/over sea." << endl;
//}
//
//void Player::moveArmies(int moves)
//{
//    cout << "This method allows player to move " << moves << " armies." << endl;
//}
//
//void Player::buildCity()
//{
//    cout << "This method allows player to build city." << endl;
//}
//
//void Player::destroyArmy()
//{
//    cout << "This method allows player to destroy other player's armies" << endl;
//}
//
//bool Player::ignore()
//{
//    bool invalidAnswer = true;
//    std::string answer;
//    std::cout << "Would you like to use the action listed on the card (y/n)? ";
//    do {
//        std::cin >> answer;
//        if (answer == "y" || answer == "n") {
//            invalidAnswer = false;
//        }
//        else {
//            std::cout << "Invalid answer. Please response with \'y\' or \'n\': ";
//        }
//    } while (invalidAnswer);
//    return (answer == "n");
//}
//
//void Player::takeAction(string action, Graph &gameBoard, vector<Player*> &allPlayers)
//{
//    std::string playerAction = action.substr(0, action.find(" "));
//    int quantity = std::stoi(action.substr(action.find(" ") + 1));
//
//    if (playerAction == "MOVE_OVER_WATER") {
//        moveArmies(quantity, gameBoard, true);
//    }
//    else if (playerAction == "MOVE_OVER_LAND") {
//        moveArmies(quantity, gameBoard, false);
//    }
//    else if (playerAction == "PLACE_NEW_ARMIES_ON_BOARD") {
//        placeNewArmies(quantity, gameBoard);
//    }
//    else if (playerAction == "BUILD_A_CITY") {
//        buildCity(gameBoard);
//    }
//    else if (playerAction == "DESTROY_ARMY") {
//        destroyArmy(gameBoard, allPlayers);
//    }
//}
//
//void Player::andOrAction(std::string action, Map &gameBoard, std::vector<Player*> &allPlayers)
//{
//    int answer;
//
//    if (action.find("OR") != std::string::npos) {
//        // split string into two halves
//        std::string firstAction = action.substr(0, action.find("OR"));
//        std::string secondAction = action.substr(action.find("OR") + 3);
//
//        std::cout << "Here are your following choices: " << std::endl;
//        std::cout << "1 - " << firstAction << std::endl;
//        std::cout << "2 - " << secondAction << std::endl;
//        std::cout << "Please select one of the following by entering '1' or '2': ";
//
//        answer = validateActionSelection();
//
//        if (answer == 1) {
//            takeAction(firstAction, gameBoard, allPlayers);
//        }
//        else {
//            takeAction(secondAction, gameBoard, allPlayers);
//        }
//    }
//    else {
//        // split string into two halves
//        std::string firstAction = action.substr(0, action.find("AND"));
//        std::string secondAction = action.substr(action.find("AND") + 4);
//
//        std::cout << "Here are your following choices: " << std::endl;
//        std::cout << "1 - " << firstAction << std::endl;
//        std::cout << "2 - " << secondAction << std::endl;
//        std::cout << "Would you prefer to take '1' or '2' actions? : ";
//
//        // validate user selection
//        answer = validateActionSelection();
//
//        // player only wants to use one of the actions
//        if (answer == 1) {
//            std::cout << "Please select one of the above actions by entering '1' or '2': ";
//            answer = validateActionSelection();
//            if (answer == 1) {
//                takeAction(firstAction, gameBoard, allPlayers);
//            }
//            else {
//                takeAction(secondAction, gameBoard, allPlayers);
//            }
//        }
//            // player wants to use both actions
//        else {
//            std::cout << "Which action would you like to use first? Please select one of the above actions by entering '1' or '2': ";
//            answer = validateActionSelection();
//            if (answer == 1) {
//                takeAction(firstAction, gameBoard, allPlayers);
//                takeAction(secondAction, gameBoard, allPlayers);
//            }
//            else {
//                takeAction(secondAction, gameBoard, allPlayers);
//                takeAction(firstAction, gameBoard, allPlayers);
//            }
//        }
//    }
//}
//// Getters
//int* Player::getCoins() const {
//    return coins;
//}
//
//int* Player::getArmy() const {
//    return armies;
//}
//
//int* Player::getCities() const {
//    return cities;
//}
//
//int *Player::getAge() const {
//    return age;
//}
//
//string *Player::getName() const {
//    return name;
//}
//
//vector<Card> *Player::getHandOfDeck() const {
//    return handOfDeck;
//}
//
//Bidding *Player::getBidding() const {
//    return bid;
//}
//
//// Setters
//void Player::setCoins(int coins) {
//    *Player::coins = coins;
//}
//
//void Player::setArmy(int armies){
//    *Player::armies = armies;
//}
//
//void Player::setCities(int cities) {
//    *Player::cities = cities;
//}
//
//void Player::setAge(int age){
//    *Player::age = age;
//}
//
//void Player::setName(string name) {
//    *Player::name = name;
//}
//
//
