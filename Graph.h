#include <map>
#include <string>
#include "Node.h"
#include "fstream"
#include <iostream>
#include <queue>

using namespace std;

struct PQNode{
    int distance;
    Node* cityNode;
    PQNode* prevNode;

    PQNode(int distance, Node* cityNode, PQNode* prevNode){
        this->distance = distance;
        this->cityNode = cityNode;
        this->prevNode = prevNode;
    }
};

struct PQNodeCompare{
    bool operator()(PQNode* node1, PQNode* node2){
        return node1->distance > node2->distance;
    }
};

class Graph{
    public:
        Graph(string fileName);

        //Print out nodes in the map
        void printMap();

        //Find path from origin to destination, print it out
        void findPath(string origin, string destination);
    private:
        map<string, Node> graphNodes;
        const int MAX_ITERATIONS_SCALE = 10000;

        void printPath(PQNode* endNode, string origin, string destination);

        void printPQNodes(vector<PQNode*>& nodeHolder);
};

