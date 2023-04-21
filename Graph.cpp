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
    }

    int iterations = 0;

    //Create queue to keep track of distances
    priority_queue<PQNode, vector<PQNode>, PQNodeCompare> nodeQueue;
    nodeQueue.push(PQNode(0,&graphNodes[origin]));

    //Keep track of path
    map<string, Node*> path;
    path[origin] = nullptr;

    //Keep track of already optimal nodes
    map<string, bool> optimalNodes;

    //Don't exceed max specified iterations
    while(iterations < MAX_ITERATIONS){
        iterations++;
        if(nodeQueue.size() == 0){
            //If we have no more nodes to explore, then the destination can't be reached
            break;
        }

        //Get the front node
        PQNode currentPQNode = nodeQueue.top();
        nodeQueue.pop();

        if(optimalNodes.count(currentPQNode->getName()) > 0){
            //Node already optimized, go to next
            continue;
        }

        //Mark current node as optimal
        optimalNodes[currentPQNode->getName()] = true;

        //Check if it is the goal node
        if(currentPQNode.cityNode->getName() == destination){
            printPath(&path, &origin, &destination);
            return;
        }

        //Get all connections from the node

        //Loop per connected node

            //Check if we have visted or not
                //If not add to priority queue

    }

    //If no connection is found/max iterations exceeded
    cout << "distance: infinity" << endl;
    cout << "route:" << endl;
    cout << "none" << endl;
}

void Graph::printPath(map<string, Node*>* path, string* origin, string* destination){
    string currentNode = *destination;
    vector<string> correctPath;
    int totalDist = 0;

    //Put path into a vector for easier traversal
    while(currentNode != *origin){
        correctPath.push_back(currentNode);
        totalDist += graphNodes[currentNode].distTo(path->at(currentNode)->getName());
        currentNode = path->at(currentNode)->getName();
    }

    correctPath.push_back(currentNode);

    //Print general info
    cout << "distance: " << totalDist << endl;
    cout << "route:" << endl;

    //Traverse vector and print distances
    for(int i = correctPath.size()-1; i > 0; i--){
        cout << correctPath[i] << " to " << correctPath[i-1] << ", " << graphNodes[correctPath[i]].distTo(correctPath[i-1]) << " km" << endl;
    }
}
