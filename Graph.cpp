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

    //If the origin is the same as the destination
    if(origin == destination){
        cout << "distance: 0 km" << endl;
        cout << "route:" << endl;
        cout << origin << " to " << destination << ", 0 km" << endl;
        return;
    }

    int iterations = 0;

    //Create queue to keep track of distances
    priority_queue<PQNode, vector<PQNode>, PQNodeCompare> nodeQueue;
    vector<PQNode*> pathTracker;

    PQNode firstNode(0, &graphNodes[origin], -1);
    pathTracker.push_back(&firstNode);
    nodeQueue.push(firstNode);

    //Don't exceed max specified iterations
    while(iterations < MAX_ITERATIONS){
        if(nodeQueue.size() == 0){
            //If we have no more nodes to explore, then the destination can't be reached
            break;
        }

        //Get the front node
        PQNode currentPQNode = nodeQueue.top();
        nodeQueue.pop();

        //Check if it is the goal node
        if(currentPQNode.cityNode->getName() == destination){
            printPath(pathTracker, origin, destination, iterations);
            return;
        }

        //Add all connected nodes to the queue and the vector
        map<string, int>* connections = currentPQNode.cityNode->getConnections();
        for(auto i : *connections){
            //Creating node
            int dist = currentPQNode.distance + i.second;
            Node* newNode = &graphNodes[i.first];
            int prevNode = iterations;
            PQNode nextCity(dist, newNode, prevNode);

            //Adding it to vector and pq
            pathTracker.push_back(&nextCity);
            nodeQueue.push(nextCity);
        }

        iterations++;
    }

    //If no connection is found/max iterations exceeded
    cout << "distance: infinity" << endl;
    cout << "route:" << endl;
    cout << "none" << endl;
}

void Graph::printPath(vector<PQNode*>& path, string origin, string destination, int currentIndex){
    int totalDistance = path[currentIndex]->distance;

    cout << "distance: " << totalDistance << endl;

    //Store all data for printing
    vector<string> cityPath;
    PQNode* currentNode = path[currentIndex];
    while(currentNode->prev_index != -1){
        cityPath.push_back(currentNode->cityNode->getName());
        currentNode = path[currentNode->prev_index];
    }
    cityPath.push_back(origin); //Need to also push the origin city
    
    //Iterate through and print
    cout << "route:" << endl;
    for(int i = cityPath.size()-1; i--; i > 0){
        cout << cityPath[i] << " to " << cityPath[i-1] << ", ";
        cout << graphNodes[cityPath[i]].distTo(cityPath[i-1]) << " km" << endl;
    }
}
