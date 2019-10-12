#pragma once
#include <string>
using namespace std;

class Loader
{
    private:
        string map_file;
	public:
		Loader(string);
		void setFileName(string);
		int readFile();
};
