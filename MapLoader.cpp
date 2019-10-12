#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
#include "Map.h"
using namespace std;

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
    cout << endl << "*** File " << map_file << " is open" <<endl;
    
    Graph graph;
    int totalNodes = 0;
    vector<int> country;

    while ( getline(myfile,line) )
    {
      cout << "line: "<< line <<endl;

      // Remove comments from line
      int com = line.find("//");
      line = line.substr(0,com);

      cout << "Split line on whitespaces" << endl;
      // Split line on whitespaces to extract country and adjacent ones
      int pos0 = 0;
      int pos = 0;
      int localNodes;
      int adjacentCountries[localNodes];

      localNodes = 0;
      // Read one line 
      while(pos0<line.length()){
        pos = line.find(" ",pos0+1);
        adjacentCountries[localNodes++] = std::stoi(line.substr(pos0, pos));
        pos0 = pos;
      }
      country.push_back(adjacentCountries[0]);
      totalNodes++;
      cout << "Found country: " << country.back() << " with " << localNodes-1 << " adjacent countries" <<endl;
      for(int i=1;i<localNodes;i++){
        cout << " => adjacent: " << adjacentCountries[i] <<endl;
      }
      cout <<endl;
    }
    cout << "I found " << totalNodes << " countries in this Map" << endl;
    
    // Creation of Map Graph begins
    vector <int> adj[totalNodes];

    // Read adjacent countries
//    	graph.addEdge(adj, 0, 1);
  	// Print the graph
//	  graph.printGraph(adj, totalNodes);

  	//Check Connectivity
//	  graph.checkConnectivity(adj, totalNodes);


    myfile.close();
    return 1;
  }

  else return -1;
}