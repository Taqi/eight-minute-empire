#include <iostream>
#include "MapLoader.h"
#include "Map.h"
using namespace std;

int main () {

    // Create Loader instance with invalid file name

    //    string files[]= {"no_file.map","not_a_map.txt","example.map", "daph.map"};
    string files[]= {"daph.map"};
    int files_nb = sizeof(files);

    Loader my_map("");
    for(int i = 0;i<1;i++){
      my_map.setFileName(files[i]); 
      cout << "\nAbout to read file: "  << files[i] << endl;
      switch(my_map.readFile())
      {
        case 1:
          cout << "Map loaded" << endl;
        break;
        case 0:
          cout << "Not a Map file" << endl;
        break;
        case -1:
          cout << "Unable to open file" << endl;
        break;
      }
    }

  return 0;
}