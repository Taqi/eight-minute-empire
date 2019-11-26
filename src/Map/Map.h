#pragma once
#include <iostream>
#include <vector>
#include <map>

struct Node
{
    // region name
    std::string region = "";

    // continent name
    std::string continent = "";

    // key is playername
    // playername for owner
    std::string owner = "";

    // value is array of two ints: armies, cities
    std::map<std::string, std::pair<int, bool>> armies = std::map<std::string, std::pair<int, bool>>();

    // array of regions it is connected to
    // first of pair is region name
    // second is true if water-crossing
    std::vector<std::pair<std::string, bool>> connectedTo = std::vector<std::pair<std::string, bool>>();
};

class Map
{
private:

    //singleton_instance
    static Map* map_instance;

    // connected graph of Nodes
    std::vector<Node> *nodes;
    // starting node
    std::string *start;
    std::vector<std::string> *continents;

    // find a node's index
    int getNodeIndex(std::string regionName);

    // recalculate the owner of a node
    void updateOwner(int index);

    // constructors and destructors
    Map(std::vector<Node> inputNodes, std::string startRegion, std::vector<std::string> regions, std::vector<std::string> continents, std::vector<std::string> players);
    Map(Map const &m);

public:

    ~Map();

    // singleton instance
    static Map* getInstance(std::vector<Node> inputNodes, std::string startRegion, std::vector<std::string> regions, std::vector<std::string> continents, std::vector<std::string> players);

    // singleton instance from file location
    static Map* getInstance();

    static void resetMapInstance();

    // print details of each node
    void printNodes();

    // get name of starting region
    std::string *getStart() const;

    // return pairs of regions and their owner
    std::map<std::string, std::vector<std::string>> getRegionOwners();
    // return pairs of regions and their owner
    std::vector<std::pair<std::string, std::string>> getContinentOwners();
    // add one army
    void addArmy(std::string regionName, std::string playerName);
    // move one army
    void moveArmy(std::string origin, std::string destination, std::string playerName);
    // add city
    void addCity(std::string regionName, std::string playerName);
    // destroy one army
    void destroyArmy(std::string regionName, std::string playerName);
    // return all region names
    std::vector<std::string> getRegionNames();
    // determine all regions with armies, return vector of regions
    std::vector<std::string> getRegionsWithArmies(std::string playerName);
    // determine all regions in which cities can be built, return vector of regions
    std::vector<std::string> getRegionsToAddCities(std::string playerName);
    // determine all regions in which armies can be added, return vector of regions
    std::vector<std::string> getRegionsToAddArmies(std::string playerName);
    // determine all regions connected by land, return vector of regions
    std::vector<std::string> getRegionsConnectedByLand(std::string regionName);
    // determine all regions connected by land and water, return vector of regions
    std::vector<std::string> getRegionsConnectedByLandAndWater(std::string regionName);
};
