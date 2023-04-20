#include <iostream>
#include <string>
#include <map>

using namespace std;

class Node{
    public:
        //Constructor
        Node(string name);
        Node(){};

        //Member functions
        void addConnection(string name, int distance);

    private:
        string name;
        map<string, int> connections;
};