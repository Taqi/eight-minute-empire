#include <iostream>
#include <sys/stat.h> 
#include "MapLoader.h"
#include "../Map/Map.h"
#include <string>
#include <dirent.h> //Need to do this to be able to use dirent.h on windows https://codeyarns.com/2014/06/06/how-to-use-dirent-h-with-visual-studio/?fbclid=IwAR24yPTiEBg1QsfFzWddJkBcOJhA_k63A7B4NNh501BCdyCtWFgfgRzBq20
using namespace std;

/* Returns a list of Map files in a directory (except the ones that begin with a dot) */
int readFilenames(std::vector<string> &filenames, const string &directory)
{
    DIR *dir;
    class dirent *ent;
    class stat st;

    dir = opendir(directory.c_str());
    while ((ent = readdir(dir)) != NULL) {
        const string file_name = ent->d_name;
        const string full_file_name = directory + "/" + file_name;
        int pos = file_name.find(".map");

        if (pos<0)
          continue;

        if (file_name[0] == '.')
            continue;
        
        if (stat(full_file_name.c_str(), &st) == -1)
            continue;
        
        const bool is_directory = (st.st_mode & S_IFDIR) != 0;

        if (is_directory)
            continue;

//        filenames.push_back(full_file_name); // returns full path
        filenames.push_back(file_name); // returns just filename
    }
    closedir(dir);

    //sort (filenames.begin(), filenames.end()); //optional, sort the filenames
    return(filenames.size()); //Return how many we found
} // GetFilesInDirectory

//Return map object created in Loader
Map* MapLoaderDriver () {

    cout << endl << "+---------------------------------+";
    cout << endl << "|     This is MapLoaderDriver     |";
    cout << endl << "+---------------------------------+" << endl << endl;

    // Read Map files from current directory
    string folder = ".";
    vector<string> filenames;
    int num_files = readFilenames(filenames, folder);

    cout << "Found " << num_files << " Map file(s) in directory: " << folder << endl;

    // Create Loader instance with no file name
    Loader my_map("");

    for(size_t i = 0; i < filenames.size(); ++i)
    {
      cout << "File #"<< i+1 << ": \t" << filenames[i] << endl;
    }
    
    
    int file_choice = -1;
    while (file_choice < 1 or file_choice > num_files){
      cout << endl << "Select file # to process: ==> " ;
      cin >> file_choice;
    }
    
    cout << endl << "==  About to process file #" << file_choice << " = " << filenames[file_choice-1] << endl;

    my_map.setFileName(filenames[file_choice-1]); 

    switch(my_map.readFile())
    {
      case 1:
        cout << "=== Map loaded" << endl;
      break;
      case 0:
        cout << "*** Not a Map file" << endl;
      break;
      case -1:
        cout << "*** Unable to open file" << endl;
      break;
    }

	//We created the map object (in Loader) with all the graph (continents in it), so now return it.
	Map* m = my_map.getMapPointer();
	//auto m = Map::getInstance();

	return m;


}