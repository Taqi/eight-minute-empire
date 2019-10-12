#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
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

    while ( getline (myfile,line) )
    {
      // Remove comments from line
      int com = line.find("//");
      line = line.substr(0,com);



      cout << line << endl;
    }
    myfile.close();
    return 1;
  }

  else return -1;
}