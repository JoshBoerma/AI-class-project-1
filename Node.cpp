#include "Node.h"

using namespace std;

//Constructor
Node::Node(string name){
    this->name = name;
}

//Add a connection to the node
void Node::addConnection(string name, int distance){
    connections.insert({name,distance});
}

//Print out data
void Node::printNode() const{
    cout << "Node of: " << name << endl;
    cout << "Total connections: " << connections.size() << endl;


    cout << "Connecting city | distance" << endl;
    for(auto const& cities : connections){
        cout << cities.first << " | " << cities.second << endl;
    }
}

//Print distance to connected city
int Node::distTo(string name){
    if(connections.count(name) == 0){
        cerr << "No connection to the city" << endl;
        return -1;
    }
    return connections[name];
}

//Getters
string Node::getName() const{
    return name;
}