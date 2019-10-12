#include <iostream>
#include <dirent.h>
#include <sys/stat.h> 
#include "MapLoader.h"
#include "Map.h"
#include <string>
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
        int pos = file_name.find(".map");

        if (pos<0)
          continue;

        if (file_name[0] == '.')
            continue;

        const bool is_directory = (st.st_mode & S_IFDIR) != 0;

        if (is_directory)
            continue;

//        filenames.push_back(full_file_name); // returns full path
        filenames.push_back(file_name); // returns just filename
    }
    closedir(dir);

    std::sort (filenames.begin(), filenames.end()); //optional, sort the filenames
    return(filenames.size()); //Return how many we found
} // GetFilesInDirectory


int main () {

    cout << endl << "This is MapLoaderDriver" << endl;

    // Read Map files from current directory
    string folder = ".";
    cout << "Reading in directory " << folder << endl;
    vector<string> filenames;

    int num_files = readFilenames(filenames, folder);
    string files[num_files];
    cout << "Number of files = " << num_files << endl;

    // Create Loader instance with no file name
    Loader my_map("");

    for(size_t i = 0; i < filenames.size(); ++i)
    {
      cout << " #" << i << " = " << filenames[i] << endl;

      my_map.setFileName(filenames[i]); 

      cout << "About to process Map" <<endl;
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

    }



  return 0;
}