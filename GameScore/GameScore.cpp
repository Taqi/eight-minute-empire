#include "GameScore.h"

GameScore::GameScore() {}




void GameScore::countTreePoint(int tree, Player* player)
{
	while (tree >= 2)
	{
		if (tree < 4)
		{
			player->addGoodPoint(1); //just points from goods
			player->addVictoryPoint(1); //total points (goods + countries + continents)
			tree -= 2; //Remove 2 trees since 2 trees = 1 point
		}
		else if (tree < 5)
		{
			player->addGoodPoint(2);
			player->addVictoryPoint(2);
			tree -= 4;
		}
		else if (tree < 6)
		{
			player->addGoodPoint(3);
			player->addVictoryPoint(3);
			tree -= 5;
		}
		else
		{
			player->addGoodPoint(5);
			player->addVictoryPoint(5);
			tree -= 6;
		}
	}
}

void GameScore::countAnvilPoint(int anvil, Player* player)
{
	while (anvil >= 2)
	{
		if (anvil < 4)
		{
			player->addGoodPoint(1);
			player->addVictoryPoint(1);
			anvil -= 2;
		}
		else if (anvil < 5)
		{
			player->addGoodPoint(2);
			player->addVictoryPoint(2);
			anvil -= 4;
		}
		else if (anvil < 7)
		{
			player->addGoodPoint(3);
			player->addVictoryPoint(3);
			anvil -= 6;
		}
		else
		{
			player->addGoodPoint(5);
			player->addVictoryPoint(5);
			anvil -= 7;
		}
	}

}

void GameScore::countCarrotPoint(int carrot, Player* player)
{
	while (carrot >= 3)
	{

		if (carrot < 4)
		{
			player->addGoodPoint(1);
			player->addVictoryPoint(1);
			carrot -= 3;
		}
		else if (carrot < 6)
		{
			player->addGoodPoint(2);
			player->addVictoryPoint(2);
			carrot -= 5;
		}
		else if (carrot < 8)
		{
			player->addGoodPoint(3);
			player->addVictoryPoint(3);
			carrot -= 7;
		}
		else
		{
			player->addGoodPoint(5);
			player->addVictoryPoint(5);
			carrot -= 8;
		}
	}

}

void GameScore::countRockPoint(int rock, Player* player)
{
	while (rock >= 2)
	{

		if (rock < 3)
		{
			player->addGoodPoint(1);
			player->addVictoryPoint(1);
			rock -= 2;
		}
		else if (rock < 4)
		{
			player->addGoodPoint(2);
			player->addVictoryPoint(2);
			rock -= 3;
		}
		else if (rock < 5)
		{
			player->addGoodPoint(3);
			player->addVictoryPoint(3);
			rock -= 4;
		}
		else
		{
			player->addGoodPoint(5);
			player->addVictoryPoint(5);
			rock -= 5;
		}
	}

}

void GameScore::countCrystalPoint(int crystal, Player* player)
{
	while (crystal >= 1)
	{

		if (crystal < 2)
		{
			player->addGoodPoint(1);
			player->addVictoryPoint(1);
			crystal -= 1;
		}
		else if (crystal < 3)
		{
			player->addGoodPoint(2);
			player->addVictoryPoint(2);
			crystal -= 2;
		}
		else if (crystal < 4)
		{
			player->addGoodPoint(3);
			player->addVictoryPoint(3);
			crystal -= 3;
		}
		else
		{
			player->addGoodPoint(5);
			player->addVictoryPoint(5);
			crystal -= 4;
		}
	}
}

//Compute the score of each players
void GameScore::computeGameScore(vector<Player*>* players)
{
	//Count points for every player
	for (int player = 0; player < players->size(); player++)
	{
		cout << "\n\n\tPlayer: " << *(players->at(player)->getName()) << endl;

		//Total amount of goods a player has
		int sum = 0;
		int rock = 0;
		int crystal = 0;
		int anvil = 0;
		int carrot = 0;
		int tree = 0;

		cout << "Owns the following cards: \n";
		//Check for every card the player has
		for (int card = 0; card < players->at(player)->pHand.size(); card++)
		{
			if (players->at(player)->pHand.at(card)->getGood() == "Carrot")
			{
				carrot += players->at(player)->pHand.at(card)->getNGood();
			}

			else if (players->at(player)->pHand.at(card)->getGood() == "Rock")
			{
				rock += players->at(player)->pHand.at(card)->getNGood();
			}

			else if (players->at(player)->pHand.at(card)->getGood() == "Tree")
			{
				tree += players->at(player)->pHand.at(card)->getNGood();
			}

			else if (players->at(player)->pHand.at(card)->getGood() == "Anvil")
			{
				anvil += players->at(player)->pHand.at(card)->getNGood();
			}

			else if (players->at(player)->pHand.at(card)->getGood() == "Crystal")
			{
				crystal += players->at(player)->pHand.at(card)->getNGood();
			}

			cout << "-" << players->at(player)->pHand.at(card)->getAction() << " (" << players->at(player)->pHand.at(card)->getNGood() << " " << players->at(player)->pHand.at(card)->getGood() << ")" << endl;
		}

		//Now that we collected total amounts of carrots, rocks, etc. for a player, send it to the method to add points depending on the amount they have
		countTreePoint(tree, (players->at(player)));

		countAnvilPoint(anvil, (players->at(player)));

		countCarrotPoint(carrot, (players->at(player)));

		countRockPoint(rock, (players->at(player)));

		countCrystalPoint(crystal, (players->at(player)));

		//cout << "\nOwns the following countries: ";
		//Points for region owned
		for (int countries = 0; countries < players->at(player)->playerCountries.size(); countries++)
		{
			//cout << players->at(player)->playerContinent[countries] << ", ";
			players->at(player)->addVictoryPoint(1); //Add a point for each country
		}

		//cout << "\nOwns the following continents: ";
		//Points for continents owned		
		for (int continent = 0; continent < players->at(player)->playerContinent.size(); continent++)
		{
			//cout << players->at(player)->playerContinent[continent] << ", ";
			players->at(player)->addVictoryPoint(1); //Add a point for each continent
		}

		cout << "\nTotal good (carrots, rocks, etc.) points for player " << *(players->at(player)->getName()) << ": " << players->at(player)->getGoodPoint() << endl;
		cout << "Total victory points " << players->at(player)->getVictoryPoint();
	}

}

//Compute the score of each players
void GameScore::computeCurrentGameScore(vector<Player*>* players, int player)
{
	int previousGoodPoints = players->at(player)->getGoodPoint();

	//Reset values
	players->at(player)->setGoodPoint(0);
	players->at(player)->setVictoryPoint(0);

	//Total amount of goods a player has
	int sum = 0;
	int rock = 0;
	int crystal = 0;
	int anvil = 0;
	int carrot = 0;
	int tree = 0;

	cout << "\nOwns the following cards: \n";
	//Check for every card the player has
	for (int card = 0; card < players->at(player)->pHand.size(); card++)
	{
		if (players->at(player)->pHand.at(card)->getGood() == "Carrot")
		{
			carrot += players->at(player)->pHand.at(card)->getNGood();
		}

		else if (players->at(player)->pHand.at(card)->getGood() == "Rock")
		{
			rock += players->at(player)->pHand.at(card)->getNGood();
		}

		else if (players->at(player)->pHand.at(card)->getGood() == "Tree")
		{
			tree += players->at(player)->pHand.at(card)->getNGood();
		}

		else if (players->at(player)->pHand.at(card)->getGood() == "Anvil")
		{
			anvil += players->at(player)->pHand.at(card)->getNGood();
		}

		else if (players->at(player)->pHand.at(card)->getGood() == "Crystal")
		{
			crystal += players->at(player)->pHand.at(card)->getNGood();
		}

		cout << "-" << players->at(player)->pHand.at(card)->getAction() << " (" << players->at(player)->pHand.at(card)->getNGood() << " " << players->at(player)->pHand.at(card)->getGood() << ")" << endl;
	}

	//Now that we collected total amounts of carrots, rocks, etc. for a player, send it to the method to add points depending on the amount they have
	countTreePoint(tree, (players->at(player)));

	countAnvilPoint(anvil, (players->at(player)));

	countCarrotPoint(carrot, (players->at(player)));

	countRockPoint(rock, (players->at(player)));

	countCrystalPoint(crystal, (players->at(player)));

	//cout << "\nOwns the following countries: ";
	//Points for region owned
	for (int countries = 0; countries < players->at(player)->playerCountries.size(); countries++)
	{
		//cout << players->at(player)->playerContinent[countries] << ", ";
		players->at(player)->addVictoryPoint(1); //Add a point for each country
	}

	//cout << "\nOwns the following continents: ";
	//Points for continents owned		
	for (int continent = 0; continent < players->at(player)->playerContinent.size(); continent++)
	{
		//cout << players->at(player)->playerContinent[continent] << ", ";
		players->at(player)->addVictoryPoint(1); //Add a point for each continent
	}

	//Congratulate player for scoring a new point
	if (previousGoodPoints < players->at(player)->getGoodPoint())
	{
		cout << "\nCongratulation " << *(players->at(player)->getName()) << ", you scored new good point!\n";
	}

	cout << "\nTotal good (carrots, rocks, etc.) points for player " << *(players->at(player)->getName()) << ": " << players->at(player)->getGoodPoint() << endl;
	cout << "Total victory points " << players->at(player)->getVictoryPoint();


}

//Generate winner
void GameScore::winnerGenerator(vector <Player*>* players) 
{
	//Reset values
	int mostPoints = 0;
	int playerWinner;

	mostPoints = players->at(0)->getVictoryPoint(); //Initially set to player 0, and then compare with every other player
	playerWinner = 0; //Winner, initially set to player 0
    
	for (int i = 1; i < players->size(); i++) //Each player
	{

		//Bigger so no changes
		if (mostPoints > players->at(i)->getVictoryPoint())
		{
			continue;
		}

		//Smaller, so we need to change the winner
		else if (mostPoints < players->at(i)->getVictoryPoint())
		{
			mostPoints = mostPoints > players->at(i)->getVictoryPoint();
			playerWinner = i;
		}

		//If equal, then there is no winner.
		else if (mostPoints == players->at(i)->getVictoryPoint())
		{
			playerWinner = -1; //No winner based on victory points
		}

		//Now check based on 2nd criteria



	}		
	//If its not -1, then someone won
	if (playerWinner != -1)
	{
		cout << "\n\nWe have a winner!!!\n";
		cout << "The winner with " << players->at(playerWinner)->getVictoryPoint() << " points is" << endl;

		cout << endl << "+---------------------------------+" << endl;
		cout << endl << "                " << *(players->at(playerWinner)->getName());
		cout << endl << "+---------------------------------+" << endl << endl;
	}

}