#include <map>
#include <string>
#include "Node.h"
#include "fstream"
#include <iostream>

using namespace std;

class Graph{
    public:
        Graph(string fileName);

        //Print out nodes in the map
        void printMap();
    private:
        map<string, Node> graphNodes;
        const int MAX_ITERATIONS = 100000;
};