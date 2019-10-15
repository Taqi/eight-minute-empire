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
    Graph graph;
    int totalNodes = 0;

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
      totalNodes++;
    }    
    cout << "=> I found " << totalNodes << " countries in this Map" << endl;

    // Creation of Map Graph begins
    vector<int> adj[totalNodes+1];
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
          node0 = stoi(*it);
          newCountry = false;
        }else{
          // Get adjacent to current
          node1 = stoi(*it);
         	graph.addEdge(adj, node0, node1);
        }
      }
    }
    cout << "== Graph creation complete" << endl;

  	// Print the graph
	  graph.printGraph(adj, totalNodes);

  	//Check Connectivity
	  graph.checkConnectivity(adj, totalNodes);


    myfile.close();
    return 1;
  }

  else return -1;
}