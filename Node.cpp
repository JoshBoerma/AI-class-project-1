#include "Node.h"

//Constructor
Node::Node(string name){
    this->name = name;
}

//Add a connection to the node
void Node::addConnection(string name, int distance){
    connections.insert({name,distance});
}