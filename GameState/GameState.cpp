//
// Created by james on 2019-11-04.
//

#include "../Player/Player.h"
#include "GameState.h"
#include <utility>


using namespace std;

GameState::GameState()
{
    // Map Generator
    bool validateMap = false;

    // While loop will validate until the right map is provided
    while (!validateMap)
    {
        try
        {
            // Look for the file location
            string fileLocation;
            cout << "Please enter map file location: ";
            cin >> fileLocation;

            // Map Loading
            Loader mapLoader("");
            // Using method from MapLoader

            validateMap = true;
        }
        // Generate an error message for the exception
        catch(const char *msg)
        {
            cout << "Error: INVALID MAP FILE!";
            cout << msg << endl;
        }
    }

    // Deck of Cards Generator
    deck = new Deck();

    // Players Generator
    players = new vector<Player *>();
    int playerCount;
    cout << "How many people are playing in the game? ";
    cin >> playerCount;
    cout << endl;

    // Retrieve the player name and ages
    for (int i = 0; i < playerCount, i++)
    {
        string name;
        int age;

        cout << "Please enter your name: ";
        cin >> name;

        cout << "Please enter your age: ";
        cin >> age;

        // Using emplace_back instead of push back since I want to return a reference here for the Player
        players->emplace_back(new Player(name, playerCount, age));
    }
}

GameState::~GameState()
{
    // If there exists any map, delete it and set the map to NULL
    if (map)
    {
        delete map;
        map = NULL;
    }

    // If there exists any player, delete it and set the player to NULL
    if (players)
    {
        delete players;
        players = NULL;
    }

    // If there exists any deck on hand, delete it and set the deck to NULL
    if (deck)
    {
        delete deck;
        deck = NULL;
    }
}



int GameState::determineGameLength()
{
    //The game ends when each player owns a
    //certain number of cards depending on the number of players.
    //2 Players 13 Cards
    //3 Players 10 Cards
    //4 Players 8 Cards
    //5 Players 7 Cards
    switch (players->size())
    {
        case (2):
            return 13;
        case (3):
            return 10;
        case (4):
            return 8;
        case (5):
            return 7;
    }
}
