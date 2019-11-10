#pragma once
using namespace std;
#include <vector>


// Creates a node with a country number (data inside the node)
struct CreateNode
{
	public:
		int countryNumber; //int data //Will be the data contained on a node of the linked list
		CreateNode *next; //Points to the next node
		string *playerName = new string("-"); //This makes the country owned by a player
		int* numArmies = new int(0); //Number of armies in a country

		vector <pair<int, int>> cityArmyPair; //Vector of type pair <number of armies, number of cities> for 1 country. The vector the size of the total number of players (so if 3 players, then vector of size 3). Each country has this vector.
													  //It gives the number of armies and cities a player has for that specific country. The index of the vector gives the player. Index 0 means player 0.	

};

//struct for an adjacency list (linked list)
struct AdjList
{
	public:
		CreateNode *head;  //pointer to head node of list
};


//A graph as an array of adjacency lists
//Size of array will be totalCountries (total nodes)
struct Graph
{
	public:
		int totalCountries; //total country in continent
		AdjList *countryArray; //Create an array of adjacency list. Every node will be in this array (as the index), and each will have a linked list that points to their adjacent nodes. 

};

class Map
{
	public:
		vector <Graph*> allGraph; //Contains every graph (continent in this array)

		int* test;
		void storeGraph(Graph *graph); //Function to store graph in alLGraph
		void mapValidationG(const int totalNumberGraph); //Check if map is valid


		bool* one = new bool(true); //True value so that the array gets initialized only once
		AdjList* playerArmyCountryArray; //This array contains a country head in each index, and it tells which player owns the country and how many armies he has.
		int* mapSize; //Total country in array

		void setCountryPlayer(string* player, int countryID); //Set which player owns that country
		string getCountryPlayer(int countryID); //Return which player owns that country

		void setCountryArmy(int* armyN, int countryID); //Set number of armies in that country
		int getCountryArmy(int countryID); //Return the number of army in that country (army owned by that player)

		void setCountryNumber(int countryID); //Set the country Id for the node
		int getCountryNumber(int countryID); //Return the country ID

		void printMap(); //Print every country in map with player and army
		void printAllAdjacentCountries(); //Print every country and their adjacent
};


CreateNode* newNode(int countryN); //Creates a node/country
Graph* createGraph(int totalCountries, Map *m); //Creates graph/continent
void addEdge(Graph* graph, int srs, int dest, Map *m); //Add edges between 2 country
void printGraph(Graph* graph); //prints a continent
void checkConnectivity(Graph* graph, int totalCountries); //Check if continent is connected
void DFS(int node, Graph* graph, bool visited[]); //DFS function
void mapValidation(vector <Graph*> map, const int totalNumberGraph); //Check for map validity
