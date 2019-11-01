/* Using Adjacency List Graph Implementation
Adjacency List is the Array[] of Linked List, where array size is same as number of node in the graph. 
Every node has a Linked List. Each Node in this Linked list represents the reference to the other nodes which share an edge with the current vertex.
*/

#include <iostream>
#include "Map.h"
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
Graph *createGraph(int totalCountries)
{
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


	//Create a 2nd array. This one will contain all the nodes
	(*graph).playerArmyCountryArray = new AdjList[totalCountries];
	//initialize with NULL
	for (int i = 0; i < totalCountries; i++)
	{
		(*graph).playerArmyCountryArray[i].head = NULL;
	}


	return graph;
}

//add an edge to an undirected Graph
void addEdge(Graph *graph, int srs, int dest)
{
	//Add an edge from source node (srs) to destination node (dest). A new node added to the adjacency list of src
	CreateNode *countryPointer;
	countryPointer = newNode(dest);	//node dest added at beginning

	//Makes dest point to srs
	(*countryPointer).next = (*graph).countryArray[srs].head; //Ex: srs = 2, dest = 3. So countryArray[2] is now linked to the node dest. Node dest is adjacent to 
	//That element in the array (countryArray[srs]) becomes a node in the linked list. Its the head of the list.
	(*graph).countryArray[srs].head = countryPointer;


	//This Array contains only head, so no link to next node
	(*graph).playerArmyCountryArray[dest].head = countryPointer;



	//connect from dest to srs (since undirected)
	//Create node srs and add it to the linked list
	countryPointer = newNode(srs);
	//Make node srs point to dest
	(*countryPointer).next = (*graph).countryArray[dest].head;
	(*graph).countryArray[dest].head = countryPointer;


	//This Array contains only head, so no link to next node
	(*graph).playerArmyCountryArray[srs].head = countryPointer;
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
			cout << "\n\nThe graph is not connected\n";

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
void mapValidation(Graph* map[], const int totalNumberGraph)
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
					cout << "\nInvalid map, Country found in more than 1 continent";
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
			break;
	}

	if (mapValid == true)
	{
		cout << "\nCountry not found in more than 1 continent";
	}

}

/*Set which player owns that country
*/
void Graph::setCountryPlayer(Graph* graph, string& player, int countryID)
{
	graph->playerArmyCountryArray[countryID].head->playerName = &player;
}

/*Return which player owns that country
*/
string Graph::getCountryPlayer(int countryID)
{
	return *(playerArmyCountryArray[countryID].head->playerName);
}

//set the number of army in that country 
void Graph::setCountryArmy(Graph* graph, int& armyN, int countryID)
{
	graph->playerArmyCountryArray[countryID].head->numArmies = &armyN;
}

//Return the number of army in that country (army owned by the player who owns the country)
int Graph::getCountryArmy(int countryID)
{
	return *(playerArmyCountryArray[countryID].head->numArmies);
}

//Set the country Id for the node
void Graph::setCountryNumber(Graph* graph, int countryID)
{
	graph->playerArmyCountryArray[countryID].head->countryNumber = countryID;
}

//Return the country Id for the node
int Graph::getCountryNumber(int countryID)
{
	return playerArmyCountryArray[countryID].head->countryNumber;
}
