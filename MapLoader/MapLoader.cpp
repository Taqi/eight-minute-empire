#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "MapLoader.h"
#include "../Map/Map.h"
using namespace std;

void SplitLine(vector<string> &list, string line){
  // Split line on whitespaces to extract country and adjacent ones
  string num = "";
  for(auto c : line)
  {
    if (strncmp(&c, " ", 1) == 0){
      if (num.length()>0)
      {
        list.push_back(num);
      }
      num = "";
    }else{
      num += c;
    }
  }
  if (num.length()>0)
    {
      list.push_back(num);
      num = "";
    }
}

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

    Graph* graph = new Graph();

    int totalCountries = 0;
    int totalCountriesByBorder = 0;
    int totalContinents = 0;

    char currentParagraph = ' ';

    typedef std::map<int, std::string> myStringMapType;
    typedef std::map<int, int> myIntMapType;
    myStringMapType continentName;
    myStringMapType countryName;
    myIntMapType countryContinent;
    myIntMapType countriesInContinent;

    vector<string> countryList;

    bool validContinent = false;
    bool validCountry = false;
    bool validBorder = false;

    /* 
    
    Decode Map file to build a vector containing:
       - Label "country" to identify new entry
       - Followed by the code of the current country
       - Followed by as many entries as there are adjacent countries to the current one
    and so on...

    */

	//If file is empty then its invalid
	if (myfile.peek() == ifstream::traits_type::eof())
	{
		cout << "Invalid file.";
		exit(0);
	}

    while ( getline(myfile,line) )
    {
      //debug cout << "line: "<< line <<endl;

      // Remove comments from line
      int com = line.find(";");


      line = line.substr(0,com);

      //debug      cout << pos << " for " << line << endl;

      // Skip empty lines
      if (line=="")
        continue;
      else if (line.find("[continents]") == 0 or line.find("[continent]")==0) // Check for continent descriptions starting point
      {
        currentParagraph = 'c';
        continue;
      } 
      else if (line.find("[countries]") == 0 or line.find("[country]")==0) // Check for country descriptions starting point
      {
        currentParagraph = 'y';
        continue;
      } 
      else if (line.find("[borders]")==0)      // Check for borders descriptions starting point
      {
        currentParagraph = 'b';
        continue;
      }
      else
      {
        switch(currentParagraph)
        {
        case 'c':
          {
            // The line describes a continent, we have to collect id and name
            // Split line on whitespaces to extract continent id and name
            string tmp = "";
            int id = 0;
            string name = "";
            bool next = false;

            for(auto c : line)
            {
              if (strncmp(&c, " ", 1) == 0)
              {
                if (tmp.length()>0)
                {
                  if (next)
                  {
                    name = tmp;
                  }
                  else
                  {
                    id = stoi(tmp);
                    next = true;
                  }                
                }
                tmp = "";
              }
              else
              {
                tmp += c;
              }
            }

            if (tmp.length()>0)
            {
              name = tmp;
            }

            continentName[id] = name;
            
            totalContinents++;
            validContinent = true;
          }
          break;
        case 'y':
          {
            // The line describes a country, we have to collect id, continent id and name
            string tmp = "";
            int id = 0;
            int continent_id = 0;
            string name = "";
            bool next = false;
            bool last = false;

            for(auto c : line)
            {
              if (strncmp(&c, " ", 1) == 0)
              {
                if (tmp.length()>0)
                {
                  if (next)
                  {
                    if (last)
                    {
                      continent_id = stoi(tmp);
                    }
                    else
                    {                   
                      name = tmp;
                      last = true;
                    }
                  }
                  else
                  {
                    id = stoi(tmp);
                    next = true;
                  }                
                }
                tmp = "";
              }
              else
              {
                tmp += c;
              }
            }

            if (tmp.length()>0)
            {
              continent_id = stoi(tmp);
            }

            countryName[id] = name;
            countryContinent[id] = continent_id;
            countriesInContinent[continent_id]++;

            totalCountries++;
            validCountry = true;
          }
          break;
        case 'b':  
          // The line gives the list of adjacent countries to a specific one
          countryList.push_back("next");
          SplitLine(countryList, line);
          totalCountriesByBorder++;
          validBorder = true;
          break;
        default:
          cout << "*** WARNING: No Paragraph Identified, assuming BORDER" << endl;
          currentParagraph = 'b';
          // The line gives the list of adjacent countries to a specific one
          countryList.push_back("next");
          SplitLine(countryList, line);
          totalCountriesByBorder++;
          validBorder = true;
          break;
        } //switch
      } // if line
    } //while
    myfile.close();

    if (validBorder)
    {
      if((!validContinent) and (!validCountry))
      {
        cout << "*** WARNING: Short Map File Syntax Detected" << endl;
      }
      else if ((validContinent) and (validCountry))
      {
        cout << "==> Found " << totalCountries << " countries "<< " on " << totalContinents << " continents in this Map" << endl;
        if(totalCountries != totalCountriesByBorder)
        {
          cout << "ERROR Inconsistent number of countries and borders: " << totalCountriesByBorder << endl;
          return -2;
        }
      }
      else
      {
        return -3;
      }
    }
    else
    {
      return -3;
    }
  	//Initialize map object
	  map = new Map();

	  map->mapSize = new int(totalCountriesByBorder); //Total countries in map

    // Creation of Map Graphs begins, one Graph per continent
    for (myStringMapType::const_iterator continent=continentName.begin(); continent!=continentName.end(); ++continent)
    //for_each(continentName.begin(), continentName.end(), [](std::map<int, string> continent) 
    {
      int continent_id = continent->first;
      string continent_name = continent->second;
      cout << "    - Processing Continent: " << continent_name  << " containing " << countriesInContinent[continent_id]<< " countries." << endl;

      //Graph is pointed to by our *graph pointer.
      graph = createGraph(totalCountries, map);

      int node0;
      int node1;

      bool newCountry = false;
      bool skip = false;
      for(vector<string>::iterator it = countryList.begin(); it < countryList.end(); it++)
      {
        if (*it == "next")
        {
          // New country description
          newCountry = true;
          skip = false;
        }
        else
        {
          if(newCountry){
            // Get current country id
            node0 = stoi(*it); //stoi converts string to integer
            if(countryContinent[node0] == continent_id){
              newCountry = false;
            }else{
              skip = true;
              continue; // skip this country, not in continent
            }
          }else if (!skip){
            // Get adjacent to current
            node1 = stoi(*it);
            addEdge(graph, node0, node1, map);
            //debug cout << "create node " << node0 << " == " << node1 << endl;
          }
        }
      }
      cout << "    - Continent Complete" << endl << endl;

    }
    cout << "== Graph creation complete" << endl;
    


    return 1;
  }// if file open
  else return -1;
}

//Return map object
Map* Loader::getMapPointer()
{
	return map;
}
