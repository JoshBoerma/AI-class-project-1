#include <iostream>
#include <string>
#include <map>

using namespace std;

class Node{
    public:
        //Constructor
        Node(string name);

        //Member functions
        void addConnection(string name, int distance);

    private:
        string name;
        map<string, int> connections;
};