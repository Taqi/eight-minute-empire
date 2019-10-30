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

	//Test creation of map1-----------------------------------------------------------------------------------------------
	cout << "TEST CREATION OF MAP1-----------------------------------------------------------------------\n";

	//connect edges
	addEdge(graph, 0, 1);
	addEdge(graph, 2, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);

	//print the adjacency list representation of graph
	printGraph(graph);

	//Check if graph is connected
	checkConnectivity(graph, totalCountries);


	//Test creation of map2-----------------------------------------------------------------------------------------------
	cout << "\nTEST CREATION OF MAP2-------------------------------------------------------------------------\n";
	
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


	
	//Test creation of map3-----------------------------------------------------------------------------------------------
	cout << "\nTEST CREATION OF MAP3-------------------------------------------------------------------------\n";

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
	Graph* map[totalNumberGraph];
	map[0] = graph;
	map[1] = graph2;
	map[2] = graph3;

	mapValidation(map, totalNumberGraph);
}
