#include <iostream>
#include <string>
#include "Graph.h"
#include <queue>

using namespace std;


int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "Please input the correct amount of arguments" << endl;
        return -1;
    }
    string file = argv[1];
    string origin = argv[2];
    string destination = argv[3];

    //Create graph from the file
    Graph city(file);

    //Calculate path from origin city to destination
    city.findPath(origin, destination);

    return 0;
}