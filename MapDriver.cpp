// MapDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Map.h"
#include "MapDriver.h"
using namespace std;


void MapDriver()
{
	//Create graph object
	Graph *graph;

	const int totalCountries = 4; //=total number of nodes

	//Graph is created in Map.cpp, which is pointed to by our *graph pointer.
	graph = createGraph(totalCountries);

	//Continent 1-----------------------------------------------------------------------------------------------
	cout << "Continent 1-----------------------------------------------------------------------\n";

	//connect edges
	addEdge(graph, 0, 1);
	addEdge(graph, 2, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);


	//print the adjacency list representation of graph
	printGraph(graph);

	//Check if graph is connected
	checkConnectivity(graph, totalCountries);

	//BELOW SHOWS how to set player name and number of armies for a region---------------------------------------
	string player1 = "Taqi";
	string player2 = "Daphne";
	string player3 = "James";

	//Random army numbers
	int army1 = 5;
	int army2 = 3;
	int army3 = 6;

	//Random country number
	int countryNumber1 = 1;

	//Set player to the region
	graph->setCountryPlayer(graph, player1, countryNumber1);
	//Set army to the region
	graph->setCountryArmy(graph, army3, countryNumber1);

	//Print
	//cout << "Country ID (head) " << graph->getCountryNumber(countryNumber1) << " is owned by " << graph->getCountryPlayer(countryNumber1) << " and has " << graph->getCountryArmy(countryNumber1) << " armies." << endl;

	//Modify who owns that country
	graph->setCountryPlayer(graph, player2, countryNumber1);
	graph->setCountryArmy(graph, army2, countryNumber1);
	//cout << "Country ID (head) " << graph->getCountryNumber(countryNumber1) << " is owned by " << graph->getCountryPlayer(countryNumber1) << " and has " << graph->getCountryArmy(countryNumber1) << " armies." << endl;

	//--------------------------------------------------------------------------------------------------------------------






	//Continent 2-----------------------------------------------------------------------------------------------
	cout << "\nContinent 2-------------------------------------------------------------------------\n";
	
	//Create graph object
	Graph *graph2;

	const int totalCountries2 = 8;

	graph2 = createGraph(totalCountries2);
	//Each country is associated with a number (ex: Country Japan is node 0, Canada is node 1)
	addEdge(graph2, 4, 5);
	addEdge(graph2, 6, 5);
	addEdge(graph2, 6, 7);
	//addEdge(graph2, 1, 7);	//Add to make the map invalid (country found in more than 1 continent)

	//Print the graph
	printGraph(graph2);

	//Check Connectivity
	checkConnectivity(graph2, totalCountries2);


	
	//Continent 3-----------------------------------------------------------------------------------------------
	cout << "\nContinent 3-------------------------------------------------------------------------\n";

	//Create graph object
	Graph* graph3;

	const int totalCountries3 = 13;

	graph3 = createGraph(totalCountries3);

	addEdge(graph3, 8, 10);
	addEdge(graph3, 9, 11);//Remove to make graph not connected
	addEdge(graph3, 10, 9);
	addEdge(graph3, 11, 12);


	//Print the graph
	printGraph(graph3);

	//Check Connectivity
	checkConnectivity(graph3, totalCountries3);


	//Check if map is valid (cannot have same country (node number) in more than 1 graph
	//Map is made up of several graphs, so create an array of graph objects
	//Max of 3 graphs for memory
	const int totalNumberGraph = 3;

	Map* m = new Map();
	m->storeGraph(graph);
	m->storeGraph(graph2);
	m->storeGraph(graph3);


	//mapValidation(map, totalNumberGraph);
	m->mapValidationG(m->allGraph.size()); //Takes total number of graphs as argument

	//Map* m = new Map();
	//m->allGraph(graph)

	//Deallocate
	delete m;
	m = NULL;
}
