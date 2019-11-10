// MapDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Map.h"
#include "MapDriver.h"
using namespace std;


Map* MapDriver()
{
	//Create map object
	Map* myMap = new Map();
	myMap->mapSize = new int(13); //Total countries in map

	//Create graph object
	Graph *graph;

	const int totalCountries = 4; //=total number of nodes in 1 continent

	//Graph is created in Map.cpp, which is pointed to by our *graph pointer.
	graph = createGraph(totalCountries, myMap);

	//Continent 1-----------------------------------------------------------------------------------------------
	cout << "Continent 1-----------------------------------------------------------------------\n";

	//connect edges
	addEdge(graph, 0, 1, myMap);
	addEdge(graph, 2, 1, myMap);
	addEdge(graph, 0, 2, myMap);
	addEdge(graph, 1, 3, myMap);


	//print the adjacency list representation of graph
	printGraph(graph);
	//myMap->printMap(myMap);

	//Check if graph is connected
	checkConnectivity(graph, totalCountries);



	//Continent 2-----------------------------------------------------------------------------------------------
	cout << "\nContinent 2-------------------------------------------------------------------------\n";
	
	//Create graph object
	Graph *graph2;

	const int totalCountries2 = 8;

	graph2 = createGraph(totalCountries2, myMap);
	//Each country is associated with a number (ex: Country Japan is node 0, Canada is node 1)
	addEdge(graph2, 4, 5, myMap);
	addEdge(graph2, 6, 5, myMap);
	addEdge(graph2, 6, 7, myMap);
	//addEdge(graph2, 1, 7, myMap);	//Add to make the map invalid (country found in more than 1 continent)

	//Print the graph
	printGraph(graph2);

	//Check Connectivity
	checkConnectivity(graph2, totalCountries2);


	
	//Continent 3-----------------------------------------------------------------------------------------------
	cout << "\nContinent 3-------------------------------------------------------------------------\n";

	//Create graph object
	Graph* graph3;

	const int totalCountries3 = 13;

	graph3 = createGraph(totalCountries3, myMap);

	addEdge(graph3, 8, 10, myMap);
	addEdge(graph3, 9, 11, myMap);//Remove to make graph not connected
	addEdge(graph3, 10, 9, myMap);
	addEdge(graph3, 11, 12, myMap);


	//Print the graph
	printGraph(graph3);

	//Check Connectivity
	checkConnectivity(graph3, totalCountries3);

	
	//Check if map is valid (cannot have same country (node number) in more than 1 graph
	//Map is made up of several graphs, so create an array of graph objects
	//Max of 3 graphs for memory
	myMap->mapValidationG(myMap->allGraph.size()); //Takes total number of graphs as argument

	//Map* m = new Map();
	//m->allGraph(graph)

	//myMap->printMap();

	//BELOW SHOWS how to set player name and number of armies for a region---------------------------------------
	string *player1 = new string("Taqi");
	string *player2 = new string("Daphne");
	string *player3 = new string("James");

	//Random army numbers
	int *army1 = new int(5);
	int *army2 = new int(3);
	int *army3 = new int(6);

	//Random country number
	int countryNumber1 = 0;

	//Set player to the region
	//myMap->setCountryPlayer(player1, countryNumber1);
	//Set army to the region
	//myMap->setCountryArmy(army3, countryNumber1);

	//myMap->printMap();

	//Modify who owns that country
	//myMap->setCountryPlayer(player2, countryNumber1);
	//myMap->setCountryArmy(army2, 5);

	//print countries with player and army
	//myMap->printMap();

	//print every country with their adjacent
	//myMap->printAllAdjacentCountries();

	////Deallocate
	//delete map;
	//map = NULL;

	return myMap;
}
