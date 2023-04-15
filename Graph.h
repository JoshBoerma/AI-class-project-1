#include <map>
#include "Node.h"

using namespace std;

class Graph{
    public:
        Graph(string fileName);
    private:
        map<string, Node> graphNodes;
        const int MAX_ITERATIONS = 100000;
};