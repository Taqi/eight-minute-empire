#pragma once
#include <string>
using namespace std;


class Map; //Need this since Map *m is not initialized below 

class Loader
{
    private:
        string map_file;
	public:
		Loader();

		Loader(string);
		
		void setFileName(string);
		int readFile();

		//Declare map object
		Map* map;

		//Return map object
		Map* getMapPointer();
};
