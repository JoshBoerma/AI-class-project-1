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
    for(auto const& [connectingCity, distance] : connections){
        cout << connectingCity << " | " << distance << endl;
    }
}