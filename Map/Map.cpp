/* Using Adjacency List Graph Implementation
Adjacency List is the Array[] of Linked List, where array size is same as number of node in the graph. 
Every node has a Linked List. Each Node in this Linked list represents the reference to the other nodes which share an edge with the current vertex.
*/

#include <iostream>
#include "../Observer/GameObservers.h"
#include "Map.h"
#include "../Player/Player.h"
#include "../GameScore/GameScore.h"
using namespace std;


//create a new node
CreateNode *newNode(int countryN)
{
	//Create new node/country
	CreateNode *countryPointer = new CreateNode;
	//Set the data of the node to the number of its country (ex: Country 1 will have in linked list node ("1") in its data. That way we know which country a node is.
	(*countryPointer).countryNumber = countryN;

	return countryPointer;
}

//function to create a graph of totalCountries - nodes
//Set total number of countries, initialize the array to AdjList objects, and set the head of each linked list to null.
Graph *createGraph(int totalCountries, Map *m)
{
	bool falseValue = false; //Just a false value

	Graph* graph = new Graph;
	//Set the total number of countries (nodes) of the graph to the value received by this function
	(*graph).totalCountries = totalCountries;

	//create an array of adjacency list. size of array - totalCountries
	(*graph).countryArray = new AdjList[totalCountries]; //AdjList[] is an array of objects of type AdjList (class defined in Map.h). Its of size totalCountries. 

	//initialize with NULL
	for (int i = 0; i < totalCountries; i++) 
	{
		(*graph).countryArray[i].head = NULL;
	}


	////playerArmyCountryArray;
	if (*(m->one) == true) //Only need to initialize the array once
	{
		//Create a 2nd array. This one will contain all the nodes
		(*m).playerArmyCountryArray = new AdjList[*(m->mapSize)]; 
		//initialize with NULL
		for (int i = 0; i < *(m->mapSize); i++)
		{
			(*m).playerArmyCountryArray[i].head = NULL;
		}

		m->one = &falseValue;
	}

	//Store graph in vector allGraph;
	m->storeGraph(graph);

	return graph;
}

//add an edge to an undirected Graph
void addEdge(Graph *graph, int srs, int dest, Map *m)
{
	//Add an edge from source node (srs) to destination node (dest). A new node added to the adjacency list of src
	CreateNode *countryPointer;
	countryPointer = newNode(dest);	//node dest added at beginning

	//Makes dest point to srs
	(*countryPointer).next = (*graph).countryArray[srs].head; //Ex: srs = 2, dest = 3. So countryArray[2] is now linked to the node dest. Node dest is adjacent to 
	//That element in the array (countryArray[srs]) becomes a node in the linked list. Its the head of the list.
	(*graph).countryArray[srs].head = countryPointer;


	//This Array contains only head, so no link to next node
	(*m).playerArmyCountryArray[dest].head = countryPointer;
	

	//connect from dest to srs (since undirected)
	//Create node srs and add it to the linked list
	countryPointer = newNode(srs);
	//Make node srs point to dest
	(*countryPointer).next = (*graph).countryArray[dest].head;
	(*graph).countryArray[dest].head = countryPointer;


	//This Array contains only head, so no link to next node
	(*m).playerArmyCountryArray[srs].head = countryPointer;
}

//function to print the graph
void printGraph(Graph *graph)
{
	//loop over each adjacent list
	for (int i = 0; i < (*graph).totalCountries; i++) 
	{
		//Node root becomes head of linked list (its initialized to the current head of the list). This is done for each node in the array (so countryArray[0], countryArray[1], etc.
		CreateNode *root = (*graph).countryArray[i].head;

		if (root != NULL) //Only display part of array that has elements in it
		{
			cout << endl << "Adjacency list of country " << i << endl;
			//cout << "Country " << (*root).countryNumber << " owned by player " << *(*root).playerName << " and contains " << *(root->numArmies) << " armies" << endl; //the first '*' is for pointer of playername, second '*' is for root pointer
		}


		//loop over each node in list
		while (root != NULL) //Will become null once it reaches the end of the linked list
		{
			cout << (*root).countryNumber << " -> "; //This prints the data inside the node of a linked list

			root = (*root).next; //Set the root to the next node of the linked list
		}
	}
}

void checkConnectivity(Graph *graph, int totalCountries)
{
	cout << "\nConnected components: ";

	//Initialize all countrys as not visited (= false)
	bool *visited = new bool[totalCountries];
	for (int country = 0; country < totalCountries; country++)
	{
		//Its = null if there is nothing in that element, so set the flag to true
		if ((*graph).countryArray[country].head == NULL)
		{
			visited[country] = true;
		}
		//Set the rest to false
		else
		{
			visited[country] = false;
		}
	}

	for (int country = 0; country < totalCountries; country++)
	{
		//If 'country' is not visited before, call DFS function
		if (visited[country] == false)
		{
			cout << country << " ";
			DFS(country, graph, visited);
			break;
		}
		else if (visited[country] == true)
		{
			continue;
		}
	}
		//Initially set the connection as true (means graph is connected)
		bool connection = true;

		//Check if all countrys are visited
		for (int country = 0; country < totalCountries; country++)
		{
			//A country has not been visited, then break. It means that graph is not connected.
			if (visited[country] == false)
			{
				connection = false;
				break;
			}
			//Else country has been visited, so check for the other countrys
			else
			{
				continue;
			}
		}

		//Output test
		/*for (int country = 0; country < totalCountries; country++)
		{
			cout << country + " country is " + visited[country];
		}*/

		//Not connected, so break out of outer loop
		if (connection == false)
		{
			cout << "\n\nThe graph is not connected\n";
			exit(0);
		}

		//Else its connected
		else
		{
			cout << "\n\nThe graph is connected\n";
		}

		//Deallocate
		delete[] visited;
		visited = NULL;
}

//We check if a graph is connected by doing the depth first method (with recursion)
void DFS(int country, Graph* graph, bool visited[])
{
	//Mark 'country' as visited.
	visited[country] = true;

	//node root becomes head of linked list for that particular array index (country)
	CreateNode* root = (*graph).countryArray[country].head;
	//currentCountryVisiting is the data value of the root node in the linked list
	int currentCountryVisiting = (*root).countryNumber;

	//while ((*root).next != NULL) //NEED TO FIX THIS (make the DFS be able to backtrack)
	{
		//Come here if country has not been visited
		if ((!visited[currentCountryVisiting] && root != NULL))
		{
			//Output test: 
			//cout << endl << "Value of adjacent: " << currentCountryVisiting << "       Value of node: " << country << "       Adjacent visited? (0=false, 1=true): " << visited[currentCountryVisiting] << endl;
			cout << currentCountryVisiting << " ";
			DFS(currentCountryVisiting, graph, visited);
		}

		//Come here if country has been visited, but it has an adjacent that has not been visited. Do recursion with the value of that adjacent.
		else if (visited[currentCountryVisiting] && (*root).next != NULL && visited[(*root).next->countryNumber] == false)
		{
			//Root is now the adjacent
			root = (*root).next;
			currentCountryVisiting = (*root).countryNumber; //Get data of that country node
			cout << currentCountryVisiting << " ";
			//cout << endl << "Value of adjacent: " << currentCountryVisiting << "       Value of node: " << country << "       Adjacent visited? (0=false, 1=true): " << visited[currentCountryVisiting] << endl;
			DFS(currentCountryVisiting, graph, visited);
		}
	}
}


/*
Function checks that a country is not found in more than 1 continent.
i represents the graph (ex: i = 0 is graph 0)
k represents the other graphs (ex: k = 1 is graph 1, k = 2 is graph 2)
j represents the elements in the array

So we compare i graph to every other k graphs on their elements j. 
its valid if:
i: j == null, k: j == null
i: j != null, k: j == null
i: j == null, k: j! == null

Anything else means the same country is found in another graph, making it invalid.
Note: j.head = null, means there is no linked list in that element of the array

*/
void mapValidation(vector <Graph*> map, const int totalNumberGraph)
{
	cout << "Checking if a country is found in more than 1 continent...\n";
	bool mapValid = true;

	//srs graph
	for (int i = 0; i < totalNumberGraph; i++)
	{
		//other graphs
		for (int k = 0; k < totalNumberGraph; k++)
		{
			//element of array
			for (int j = 0; j < (*map[i]).totalCountries; j++)
			{
				//Added k>i because for example graph i = 0, graph k = 1, we compare them, but then we don't need to compare graph i = 1, graph l = 0 because its the same thing.
				if (((((*map[i]).countryArray[j].head != NULL && (*map[k]).countryArray[j].head == NULL)) || ((*map[i]).countryArray[j].head == NULL && (*map[k]).countryArray[j].head != NULL) || ((*map[i]).countryArray[j].head == NULL && (*map[k]).countryArray[j].head == NULL)) && k>i)
				{
					//cout << "Valid, graph i = " << i << "    graph k = " << k << "    element j = " << j <<endl;
				}

				//Else a country is found in an another continent, so break
				else if (k>i)
				{
					mapValid = false;
					cout << "\nInvalid map, Country found in more than 1 continent" <<endl;
					//cout << "\nAt, graph i = " << i << "    graph k = " << k << "    element j = " << j <<endl;
					break;
				}

				if (mapValid == false)
					break;
			}

			if (mapValid == false)
				break;
		}


		if (mapValid == false)
		{
			exit(0);
		}
	}

	if (mapValid == true)
	{
		cout << "\nCountry not found in more than 1 continent" <<endl;
	}

}
//Constructor //SINGLETON
//Map::Map()
//{
//
//}
//SINGLETON

//Map* Map::getInstance()
//{
//	if (!map_instance)
//		map_instance = new Map;
//	return map_instance;
//}

Map::~Map()
{
	delete one;
	one = NULL;
	delete mapSize;
	mapSize = NULL;
	delete playerArmyCountryArray;
	playerArmyCountryArray = NULL;
}

void Map::storeGraph(Graph *graph)
{
	allGraph.push_back(graph);
}

void Map::mapValidationG(const int totalNumberGraph)
{
	mapValidation(allGraph, totalNumberGraph);
}

/*Set which player owns that country
*/
void Map::setCountryPlayer(string* player, int countryID)
{
	playerArmyCountryArray[countryID].head->playerName = player;
}

/*Return which player owns that country
*/
string Map::getCountryPlayer(int countryID)
{

	return *(playerArmyCountryArray[countryID].head->playerName);
}

//set the number of army in that country 
void Map::setCountryArmy(int* armyN, int countryID)
{
	playerArmyCountryArray[countryID].head->numArmies = armyN;
}

//Return the number of army in that country (army owned by the player who owns the country)
int Map::getCountryArmy(int countryID)
{

	return *(playerArmyCountryArray[countryID].head->numArmies);
}

//Set the country Id for the node
void Map::setCountryNumber(int countryID)
{
	playerArmyCountryArray[countryID].head->countryNumber = countryID;

}

//Return the country Id for the node
int Map::getCountryNumber(int countryID)
{
	return playerArmyCountryArray[countryID].head->countryNumber;
}

void Map::printMap(vector<Player*>* players)
{

	cout << "\n|======================================MAP==============================================|\n";
	//loop over each adjacent list
	for (int i = 0; i < *mapSize; i++)
	{
		if (i == 0)
		{
			cout << "\n\nContinent 0";
		}

		else if (i == allGraph[0]->totalCountries)
		{
			cout << "\n\nContinent 1";
		}

		else if (i == allGraph[1]->totalCountries)
		{
			cout << "\n\nContinent 2";
		}

		cout << endl << "Country: " << playerArmyCountryArray[i].head->countryNumber << " || Owned by " << *(playerArmyCountryArray[i].head->playerName) << " || Army: " << *(playerArmyCountryArray[i].head->numArmies) << endl;

		for (int j = 0; j < playerArmyCountryArray[i].head->cityArmyPair.size(); j++)
		{
			cout << "Player: " << *(players->at(j)->getName()) << "	-Army: " << playerArmyCountryArray[i].head->cityArmyPair[j].first << " -City: " << playerArmyCountryArray[i].head->cityArmyPair[j].second << endl;
		}
	}

	cout << "\n[---------------------------------------------------------------------------------------]\n";
}

/*
Prints every country with their adjacent
*/
void Map::printAllAdjacentCountries()
{
	cout << "\n|=================================ADJACENT COUNTRIES====================================|\n";
	for (int k = 0; k < allGraph.size(); k++)
	{
		cout << "\n\nContinent " << k;
		//loop over each adjacent list
		for (int i = 0; i < (*allGraph[k]).totalCountries; i++)
		{
			//Node root becomes head of linked list (its initialized to the current head of the list). This is done for each node in the array (so countryArray[0], countryArray[1], etc.
			CreateNode* root = (*allGraph[k]).countryArray[i].head;

			if (root != NULL) //Only display part of array that has elements in it
			{
				cout << endl << "Adjacency list of country " << i << endl;
				//cout << "Country " << (*root).countryNumber << " owned by player " << *(*root).playerName << " and contains " << *(root->numArmies) << " armies" << endl; //the first '*' is for pointer of playername, second '*' is for root pointer
			}


			//loop over each node in list
			while (root != NULL) //Will become null once it reaches the end of the linked list
			{
				cout << (*root).countryNumber << " -> "; //This prints the data inside the node of a linked list

				root = (*root).next; //Set the root to the next node of the linked list
			}
		}
	}

	cout << "\n[---------------------------------------------------------------------------------------]\n";
}

void Map::updateCountryOwner(vector<Player*>* players)
{

	for (int country = 0; country < *mapSize; country++) //Do for each country
	{	
		//Reset value of owner and army of a country
		playerArmyCountryArray[country].head->playerName = new string("-");
		playerArmyCountryArray[country].head->numArmies = new int(0);

		int armyMax = playerArmyCountryArray[country].head->cityArmyPair[0].first; //Biggest army of a country, initially set to player 0
		int owner = 0; //Owner for armyMax

		for (int i = 1; i < playerArmyCountryArray[country].head->cityArmyPair.size(); i++) //Each player
		{

			//Bigger so no changes
			if (armyMax > playerArmyCountryArray[country].head->cityArmyPair[i].first)
			{
				continue;
			}

			//Smaller, so we need to change the owner of the country
			else if (armyMax < playerArmyCountryArray[country].head->cityArmyPair[i].first)
			{
				armyMax = playerArmyCountryArray[country].head->cityArmyPair[i].first;
				owner = i;
			}

			//If equal, then there is no owner.
			else if (armyMax == playerArmyCountryArray[country].head->cityArmyPair[i].first)
			{
				owner = -1; //This tell us there is no owner since nobody has the most armies in a country
			}
		}

		//Finished checking for that country, now check results

		//If its not -1, then someone owns the country
		if (owner != -1)
		{
			playerArmyCountryArray[country].head->playerName = players->at(owner)->getName();
			playerArmyCountryArray[country].head->numArmies = &(playerArmyCountryArray[country].head->cityArmyPair[owner].first);
		}

		//Else, nobody owns that country, so continue
		else
		{
			continue;
		}

	}
}

//Method updates which player owns a continent (player with most countries there), and it puts those continent in the 
void Map::updatePlayerContinent(vector<Player*>* players)
{
	//Reset vector of countries and continent of each player
	for (int player = 0; player < players->size(); player++)
	{
		players->at(player)->playerCountries.clear();
		players->at(player)->playerContinent.clear();
	}

	//Array that counter the number of countries for each player
	int* count = new int[players->size()]; //Index 0 of array is counter for player 0

	//Check which player owns the most countries in each continent
	for (int i = 0; i < allGraph.size(); i++) //Loop for each continent
	{
		//Initialize array
		for (int m = 0; m < players->size(); m++)
		{
			count[m] = 0;
		}

		//Loop for each country and check who owns it
		for (int j = 0; j < allGraph.at(i)->totalCountries; j++)
		{
			if (i == 1 && j < allGraph.at(0)->totalCountries)
			{
				continue;
			}
			if (i == 2 && j < allGraph.at(1)->totalCountries)
			{
				continue;
			}

			//Loop each player
			for (int k = 0; k < players->size(); k++)
			{
				if (*(playerArmyCountryArray[j].head->playerName) == *(players->at(k)->getName()) && checkPlayerOwnsCountry(players, k, j) == false)
				{
					count[k]++; //Increment when a player owns a country
					players->at(k)->playerCountries.push_back(j);
				}
			}

		}
		//Number of countries player owns
		//cout << "Continent : " << i << endl;
		//cout << "Player count 0 : " << *(count) <<endl;
		//cout << "Player count 1 : " << *(count + 1) <<endl;
		//cout << "Player count 2 : " << *(count + 2) <<endl <<endl;

		int continentOwner = 0; //Store the player index with most countries for a specific continent. Initially we give it to player 0, and then compare it with everyone else
		int maxCountries = *(count); //Store how many countries he has (initially set for player 0)

		for (int i = 1; i < players->size(); i++) //Each player
		{

			//Bigger so no changes
			if (maxCountries > *(count +i))
			{
				continue;
			}

			//Smaller, so we need to change the owner of the country
			else if (maxCountries < *(count + i))
			{
				maxCountries = *(count + i);
				continentOwner = i;
			}

			//If equal, then there is no owner.
			else if (maxCountries == *(count + i))
			{
				continentOwner = -1; //This tell us there is no owner since nobody has the most armies in a country
			}
		}

		//Finished checking for that continent, now check results

		//If its not -1, then someone owns the continent
		if (continentOwner != -1)
		{
			//Push the continent to the player continent vector
			players->at(continentOwner)->playerContinent.push_back(i);

			//playerArmyCountryArray[country].head->playerName = players->at(owner)->getName();
			//playerArmyCountryArray[country].head->numArmies = &(playerArmyCountryArray[country].head->cityArmyPair[owner].first);
		}

		//Else, nobody owns that country, so continue
		else
		{
			continue;
		}
	}

}

//Check if that player already owns this country
bool Map::checkPlayerOwnsCountry(vector<Player*>* players, int player, int country)
{
	vector<int>::iterator it = find(players->at(player)->playerCountries.begin(), players->at(player)->playerCountries.end(), country);
	//Country was found, return true
	if (it != players->at(player)->playerCountries.end()) 
	{
		return true;
	}
	//Country was not found, so return false
	else 
	{
		return false;
	}
}


void Map::displayPlayerStats(vector<Player*>* players)
{

	//Display countries and continent owned by each player
	for (int player = 0; player < players->size(); player++)
	{
		cout << "\n\tPlayer: " << *(players->at(player)->getName());
		//Continent
		cout << "\nOwns the following continents: ";
		for (int continent = 0; continent < players->at(player)->playerContinent.size(); continent++)
		{
			cout << players->at(player)->playerContinent[continent] << ", ";
		}
		cout << "\nOwns the following Countries: ";
		for (int countries = 0; countries < players->at(player)->playerCountries.size(); countries++)
		{
			cout << players->at(player)->playerCountries[countries] << ", ";
		}
		/*cout << "\nOwns the following cards: \n";
		for (int card = 0; card < players->at(player)->pHand.size(); card++)
		{
			cout << "-" << players->at(player)->pHand.at(card)->getAction() << " (" << players->at(player)->pHand.at(card)->getNGood() << " " << players->at(player)->pHand.at(card)->getGood() << ")" << endl;
		}*/
		cout << endl;


		GameScore finalScore;
		finalScore.computeCurrentGameScore(players, player);

		int graphSize = 4;

		string* graph = new string[graphSize];

		for (int i = 0; i < graphSize; i++)
		{			
			int itemSize = 0;
			if (i == 0)
			{
				itemSize = players->at(player)->playerCountries.size();			
				string myString(itemSize, '*');
				graph[i] = myString;
			}

			else if (i == 1)
			{
				itemSize = players->at(player)->playerContinent.size();
				string myString(itemSize, '*');
				graph[i] = myString;
			}

			else if (i == 2)
			{
				itemSize = players->at(player)->getGoodPoint();
				string myString(itemSize, '*');
				graph[i] = myString;
			}

			else if (i == 3)
			{
				itemSize = players->at(player)->getVictoryPoint();
				string myString(itemSize, '*');
				graph[i] = myString;
			}

		}

		cout << "\n---------------------Bar Chart-----------------------" << std::endl;
		cout << "Player: " << *(players->at(player)->getName()) <<endl;
		for (int i = 0; i < graphSize; i++)
		{

			if (i == 0)
			{
				cout << "Country points: " << graph[i] << endl;
			}

			else if (i == 1)
			{
				cout << "Continent points: " << graph[i] << endl;
			}

			else if (i == 2)
			{
				cout << "Good points: " << graph[i] << endl;
			}

			else if (i == 3)
			{
				cout << "Victory points: " << graph[i] << endl;
			}
		}

		cout << "-----------------------------------------------------" << std::endl;

		delete[] graph;
		graph = NULL;

	}
	
}

int Map::returnGraphNumber(int country)
{
	if (country < allGraph[0]->totalCountries)
	{
		return 0;
	}

	else if (country < allGraph[1]->totalCountries)
	{
		return 1;
	}

	else
	{
		return 2;
	}

}

CreateNode::~CreateNode()
{
	delete playerName;
	playerName = NULL;
	delete numArmies;
	numArmies = NULL;
}

Graph::~Graph()
{
	delete countryArray;
	countryArray = NULL;
}

AdjList::~AdjList()
{
	delete head;
	head = NULL;
}
