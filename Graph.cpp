#include "graph.h"

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
        
    }
}