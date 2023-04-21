#include <map>
#include <string>
#include "Node.h"
#include "fstream"
#include <iostream>
#include <queue>
#include "PQData.h"

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
};

struct PQNode{
    int distance;
    Node* cityNode;
}

struct PQNodeCompare{
    bool operator()(PQNode& const node1, PQNode& const node2){
        return node1.distance < node2.distance;
    }
}