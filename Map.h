#pragma once
using namespace std;
#include <vector>

// Creates a node with a country number (data inside the node)
struct CreateNode
{
	public:
		int countryNumber; //int data //Will be the data contained on a node of the linked list
		CreateNode *next; //Points to the next node
		string *playerName; //This makes the country owned by a player
		int *numArmies; //Number of armies in a country

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
		int totalCountries;
		AdjList *countryArray; //Create an array of adjacency list. Every node will be in this array (as the index), and each will have a linked list that points to their adjacent nodes. 
		AdjList* playerArmyCountryArray; //This array contains a country head in each index, and it tells which player owns the country and how many armies he has.
		
		void setCountryPlayer(Graph* graph, string& player, int countryID); //Set which player owns that country
		string getCountryPlayer(int countryID); //Return which player owns that country
		
		void setCountryArmy(Graph* graph, int& armyN, int countryID); //Set number of armies in that country
		int getCountryArmy(int countryID); //Return the number of army in that country (army owned by that player)

		void setCountryNumber(Graph* graph, int countryID); //Set the country Id for the node
		int getCountryNumber(int countryID); //Return the country ID

};


CreateNode* newNode(int countryN);
Graph* createGraph(int totalCountries);
void addEdge(Graph* graph, int srs, int dest);
void printGraph(Graph* graph);
void checkConnectivity(Graph* graph, int totalCountries);
void DFS(int node, Graph* graph, bool visited[]);	void mapValidation(Graph* map[], const int totalNumberGraph);
