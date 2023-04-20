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
        void addConnection(string name, int distance); //Add connection to the node
        void printNode() const; //Print out all data

    private:
        string name;
        map<string, int> connections;
};