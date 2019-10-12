#pragma once
using namespace std;
#include <vector>

// Creates a node with a country number (data inside the node)
struct CreateNode
{
	public:
		int countryNumber; //int data //Will be the data contained on a node of the linked list
		CreateNode *next; //Points to the next node
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
};


CreateNode* newNode(int countryN);
Graph* createGraph(int totalCountries);
void addEdge(Graph* graph, int srs, int dest);
void printGraph(Graph* graph);
void checkConnectivity(Graph* graph, int totalCountries);
void DFS(int node, Graph* graph, bool visited[]);	void mapValidation(Graph* map[], const int totalNumberGraph);
