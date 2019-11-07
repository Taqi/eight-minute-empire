#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
#include "../Map/Map.h"
using namespace std;

Loader::Loader()
{
	
}

Loader::Loader(string file)
{
  map_file = file;
}


void Loader::setFileName(string file)
{
  map_file = file;
}

int Loader::readFile()
{
  string line;
  ifstream myfile (map_file);
  
  if (myfile.is_open())
  {
	//Initialize map object
	map = new Map();

	map->mapSize = new int(6); //Total countries in map

	Graph* graph = new Graph();
    int totalCountries = 0;

    /* 
    
    Decode Map file to build a vector containing:
       - Label "country" to identify new entry
       - Followed by the code of the current country
       - Followed by as many entries as there are adjacent countries to the current one
    and so on...

    */
    vector<string> countryList;
    while ( getline(myfile,line) )
    {
      countryList.push_back("country");
      //debug cout << "line: "<< line <<endl;

      // Remove comments from line
      int com = line.find("//");
      line = line.substr(0,com);

      //debug cout << "Split line on whitespaces" << endl;
      // Split line on whitespaces to extract country and adjacent ones
      int pos0 = 0;
      int pos  = 0;

      // Decode line
      while(pos0<line.length())
      {
        pos = line.find(" ",pos0+1);
        countryList.push_back(line.substr(pos0, pos));
        pos0 = pos;
      }
      totalCountries++;
    }    
    cout << "=> I found " << totalCountries << " countries in this Map" << endl;

    // Creation of Map Graph begins
    //Graph is pointed to by our *graph pointer.
	  graph = createGraph(totalCountries, map);

    int node0;
    int node1;

    bool newCountry = false;
    for(vector<string>::iterator it = countryList.begin(); it < countryList.end(); it++)
    {
      if (*it == "country")
      {
        // New country description
        newCountry = true;
      }else{
        if(newCountry){
          // Get current country id
          node0 = stoi(*it); //stoi converts string to integer
          newCountry = false;
        }else{
          // Get adjacent to current
          node1 = stoi(*it);
         	addEdge(graph, node0, node1, map);
        }
      }
    }
    cout << "== Graph creation complete" << endl;

  	// Print the graph
	  printGraph(graph);

  	//Check Connectivity
	  checkConnectivity(graph, totalCountries);


    myfile.close();
    return 1;
  }

  else return -1;
}

//Return map object
Map* Loader::getMapPointer()
{
	return map;
}
