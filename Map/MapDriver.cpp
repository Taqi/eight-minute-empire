// MapDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Map.h"
#include "MapDriver.h"
using namespace std;


Map* MapDriver()
{
	//Create map object
	//Map* map = new Map();
	Map* map = Map::getInstance();
	map->mapSize = new int(13); //Total countries in map

	//Create graph object
	Graph *graph;

	const int totalCountries = 4; //=total number of nodes in 1 continent

	//Graph is created in Map.cpp, which is pointed to by our *graph pointer.
	graph = createGraph(totalCountries, map);

	//Continent 1-----------------------------------------------------------------------------------------------
	cout << "Continent 1-----------------------------------------------------------------------\n";

	//connect edges
	addEdge(graph, 0, 1, map);
	addEdge(graph, 2, 1, map);
	addEdge(graph, 0, 2, map);
	addEdge(graph, 1, 3, map);


	//print the adjacency list representation of graph
	printGraph(graph);
	//map->printMap(map);

	//Check if graph is connected
	checkConnectivity(graph, totalCountries);



	//Continent 2-----------------------------------------------------------------------------------------------
	cout << "\nContinent 2-------------------------------------------------------------------------\n";
	
	//Create graph object
	Graph *graph2;

	const int totalCountries2 = 8;

	graph2 = createGraph(totalCountries2, map);
	//Each country is associated with a number (ex: Country Japan is node 0, Canada is node 1)
	addEdge(graph2, 4, 5, map);
	addEdge(graph2, 6, 5, map);
	addEdge(graph2, 6, 7, map);
	//addEdge(graph2, 1, 7, map);	//Add to make the map invalid (country found in more than 1 continent)

	//Print the graph
	printGraph(graph2);

	//Check Connectivity
	checkConnectivity(graph2, totalCountries2);


	
	//Continent 3-----------------------------------------------------------------------------------------------
	cout << "\nContinent 3-------------------------------------------------------------------------\n";

	//Create graph object
	Graph* graph3;

	const int totalCountries3 = 13;

	graph3 = createGraph(totalCountries3, map);

	addEdge(graph3, 8, 10, map);
	addEdge(graph3, 9, 11, map);//Remove to make graph not connected
	addEdge(graph3, 10, 9, map);
	addEdge(graph3, 11, 12, map);


	//Print the graph
	printGraph(graph3);

	//Check Connectivity
	checkConnectivity(graph3, totalCountries3);

	
	//Check if map is valid (cannot have same country (node number) in more than 1 graph
	//Map is made up of several graphs, so create an array of graph objects
	//Max of 3 graphs for memory
	map->mapValidationG(map->allGraph.size()); //Takes total number of graphs as argument

	//Map* m = new Map();
	//m->allGraph(graph)

	//map->printMap();

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
	//map->setCountryPlayer(player1, countryNumber1);
	//Set army to the region
	//map->setCountryArmy(army3, countryNumber1);

	//map->printMap();

	//Modify who owns that country
	//map->setCountryPlayer(player2, countryNumber1);
	//map->setCountryArmy(army2, 5);

	//print countries with player and army
	//map->printMap();

	//print every country with their adjacent
	//map->printAllAdjacentCountries();

	////Deallocate
	//delete map;
	//map = NULL;

	return map;
}
