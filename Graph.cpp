#include "Graph.h"

using namespace std;

//Constructor
Graph::Graph(string filename){
    ifstream inputFile(filename);

    //Check if file was opened correctly
    if(!inputFile.is_open()){
        cerr << "There was an error opening the file" << endl;
        return;
    }

    //Loop through and create nodes
    while(!inputFile.eof()){
        //Varaibles
        string city1;
        string city2;
        string tempDist;
        int dist;

        //Get data from file line 
        inputFile >> city1;
        inputFile >> city2;
        inputFile >> tempDist;
        if(city1 == "END" && city2 == "OF" && tempDist == "INPUT"){
            break;
        }
        dist = stoi(tempDist);

        //Check if city1 and city2 exist in the graph, if not add them
        if(graphNodes.count(city1) == 0){
            graphNodes[city1] = Node(city1);
        }
        if(graphNodes.count(city2) == 0){
            graphNodes[city2] = Node(city2);
        }

        //Add connection between the cities
        graphNodes[city1].addConnection(city2, dist);
        graphNodes[city2].addConnection(city1, dist);
    }

    inputFile.close();
}

//Print out nodes in the map
void Graph::printMap(){
    cout << "Printing out all the nodes currently in the graph: " << endl << endl;
    for(auto const& [origin, node] : graphNodes){
        //Loop through all keys
        node.printNode();
        cout << endl;
    }
    
}

//Find path between nodes
void Graph::findPath(string origin, string destination){
    //Ensure origin and destination are in the graph
    if(graphNodes.count(origin) == 0 || graphNodes.count(destination) == 0){
        cerr << "The origin or destination is not present in the graph, invalid" << endl;
        return;
    }

    iterations = 0;

    //Create queue to keep track of distances
    priority_queue<PQNode, vector<PQNode>, PQNodeCompare> nodeQueue;

    //Keep track of path
    map<string, Node*> path;
    

    //Don't exceed max specified iterations
    while(iterations < MAX_ITERATIONS){
        iterations++;
    }

    //If no connection is found
    cout << "distance: infinity" << endl;
    cout << "route:" << endl;
    cout << "none" << endl;
}