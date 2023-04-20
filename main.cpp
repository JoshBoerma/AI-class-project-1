#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;


int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "Please input the correct amount of arguments" << endl;
        return -1;
    }
    string file = argv[1];
    string city1 = argv[2];
    string city2 = argv[3];

    Graph city(file);

    return 0;
}