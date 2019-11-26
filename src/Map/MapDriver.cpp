#include <iostream>
#include "MapDriver.h"
using namespace std;

void mapSingletonTest() {
    cout << "============ SINGLETON TESTING ==============="<< endl;
    std::vector<std::string> regions = {"region1", "region2"};
    std::vector<std::string> continents = {"continent1"};
    std::vector<std::string> players = {"james"};

    Node n1{};
    Node n2{};
    n1.region = "region1";
    n1.continent = "continent1";
    n1.owner = "james";
    n1.armies.insert(make_pair("james", std::pair<int, bool>(10, false)));
    n1.connectedTo.emplace_back(std::pair<std::string, bool>("region2", true));

    n2.region = "region2";
    n2.continent = "continent1";
    n2.owner = "james";
    n2.armies.insert(make_pair("james", std::pair<int, bool>(10, true)));
    n2.connectedTo.emplace_back(std::pair<std::string, bool>("region1", true));

    std::vector<Node> nodeVector;
    nodeVector.emplace_back(n1);
    nodeVector.emplace_back(n2);
    auto m1 = Map::getInstance(nodeVector, "region1", regions, continents, players);
    auto m2 = Map::getInstance(nodeVector, "region1", regions, continents, players);

    m1->addArmy("region1", "taqi");

    if (m1 == m2) {
        cout <<"Same instance showed - SINGLETON WORKS." << endl;
    } else {
        cout <<"Different instance showed - SINGLETON FAILED." << endl;
    }
    cout << "============ --------------- ==============="<< endl;

    cout << "============ -------map 1-------- ==============="<< endl;
    m1->printNodes();
    cout << "============ -------map 2-------- ==============="<< endl;
    m2->printNodes();
    cout << "notice that map 2 also has Taqi's record, which prove singleton works fine." << endl;
    cout << "\n=============== Test resetMapInstance( ) ================"<< endl;
    Map::resetMapInstance();

    cout << "\n=============== Test getInstance( ) from filelocation ================"<< endl;
    // Suggestion map3.map

    auto map = Map::getInstance();
    map->addArmy("Vietnam", "Player1");
    map->printNodes();
    cout <<"\n==== SINGLETON MAP 1 SHOULD BE THE SAME AS MAP WHEN TESTING ==========" << endl;
    auto map1 = Map::getInstance();
    map1->printNodes();
    Map::resetMapInstance();

}
