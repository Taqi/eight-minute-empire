#include <iostream>

#include "PlayerStrategies.h"

using namespace std;

string GreedyComputer::chooseAction(GameState &state, int turn, int currentTurn)
{
    // card purchase a BUILD CITY or DESTROY ARMY if available
    state.hand->exchange(state.deck);

    string action = state.players->at(turn)->getPlayerHand()->at(currentTurn - 1)->getAction();

    //Check to see if cards is of type "AND" or "OR", if true call AND_OR_ACTION
    if (action.find("OR") != string::npos ||action.find("AND") != string::npos )
    {
        state.players->at(turn)->andOrAction(turn, action, state.map);
    }

    return action;
}

string GreedyComputer::showCurrentStrat()
{
    return "Greedy Computer";
}

string HumanPlayer::chooseAction(GameState &state, int turn, int currentTurn)
{
    // card purchase - user selects
    state.hand->exchange(state.deck);

    string action = state.players->at(turn)->getPlayerHand()->at(currentTurn - 1)->getAction();

    // Player who has the option to ignore card effect -> ending their turn
    bool endTurn = state.players->at(turn)->ignore();
    if (endTurn)
    {
        return action;
    }
    // Validate to see if card is of type "AND" or "OR" if true call andOrAction()
    if (action.find("OR") != string::npos ||action.find("AND") != string::npos )
    {
        state.players->at(turn)->andOrAction(turn, action, state.map);
    }

    return action;
}

string HumanPlayer::showCurrentStrat()
{
    return "Human Player";
}

string ModerateComputer::chooseAction(GameState &state, int turn, int currentTurn)
{
    // card purchase PLACE_NEW_ARMIES if available
    state.hand->exchange(state.deck);

    string action = state.players->at(turn)->getPlayerHand()->at(currentTurn - 1)->getAction();

    //Check to see if cards is of type "AND" or "OR", if true call AND_OR_ACTION
    if (action.find("OR") != string::npos ||action.find("AND") != string::npos )
    {
        state.players->at(turn)->andOrAction(turn, action, state.map);
    }

    return action;
}

string ModerateComputer::showCurrentStrat()
{
    return "Moderate Computer";
}

// Utility Functions that will be implemented in the DRIVER
bool checkChangeStrat()
{
    string answer;
    bool invalidAns = true;

    cout << "Would you like to change or set any player strategies?";
    do
        {
        cin >> answer;
        if (answer == "y" || answer == "n")
            {
                invalidAns = false;
            }
        else
            {
                cout << "Please enter a 'y' or 'n': ";
            }
        }
    while (invalidAns);

    return ("y" == answer);
}

void changePlayerStrat(vector<Player*> players)
{
    bool stratChangeRemain = true;

    while (stratChangeRemain)
    {
        // Show all players and their current strategies
        cout << "Please select a player to change their strategy (1 - " << players.size() << "): \n";
        for (int i = 1; i-1 < players.size(); i++)
        {
            cout << i << ") " << players.at(i-1)->getName() << ": " << players.at(i-1)->getPlayerStrategies()->showCurrentStrat() << "\n";
        }

        int playerSelection;

        // enable user to select a player to change their strategy
        cout << endl;
        cin >> playerSelection;

        while (playerSelection < 1 || playerSelection > players.size())
        {
            cout << "Please enter a number from (1- " << players.size() << "): ";
            cin >> playerSelection;
        }

        // show options
        cout << "\n Please choose that player's new strategy: \n";
        cout << "1) Human Player\n"
             << "2) Greedy Computer\n"
             << "3) Moderate Computer\n";

        int strategySelection;

        // enable user to select a new strategy for that player
        cout << endl;
        cin >> strategySelection;
        while (strategySelection < 1 || strategySelection > 3)
        {
            cout << "Please enter a number from (1-3): ";
            cin >> strategySelection;
        }

        // change player strategy
        switch (strategySelection)
        {
            case (1):
                players.at(playerSelection-1)->setPlayerStrategies(new HumanPlayer);
                cout << players.at(playerSelection-1)->getName() << " is now a Human Player.\n";
                break;
            case (2):
                players.at(playerSelection-1)->setPlayerStrategies(new GreedyComputer);
                cout << players.at(playerSelection-1)->getName() << " is now a Greedy Computer.\n";
                break;
            case (3):
                players.at(playerSelection-1)->setPlayerStrategies(new ModerateComputer);
                cout << players.at(playerSelection-1)->getName() << " is now a Moderate Computer.\n";
                break;
        }

        cout << "Would you like to change the strategy of another player?\n";
        stratChangeRemain = checkChangeStrat();
    }
}