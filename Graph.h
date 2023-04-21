#include <map>
#include <string>
#include "Node.h"
#include "fstream"
#include <iostream>
#include <queue>

using namespace std;

class Graph{
    public:
        Graph(string fileName);

        //Print out nodes in the map
        void printMap();

        //Find path from origin to destination, print it out
        void findPath(string origin, string destination);
    private:
        map<string, Node> graphNodes;
        const int MAX_ITERATIONS = 100000;

        void printPath(map<string, Node*>* path, string* origin, string* destination);
};

struct PQNode{
    int distance;
    Node* cityNode;

    PQNode(int distance, Node* cityNode){
        this->distance = distance;
        this->cityNode = cityNode;
    }
};

struct PQNodeCompare{
    bool operator()(PQNode& node1, PQNode& node2){
        return node1.distance < node2.distance;
    }
};