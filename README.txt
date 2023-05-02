1. Name: Joshua Boerma, CWID: 10873500
2. The project was made in C++ and compiled with g++ 6.1.0 (2016).
    Make files were created and run with cmake version 3.23.0, however older versions should work.
3. I used Windows 10 to run and compile the code, along with mingw
4. The code is strucuted around main, which is called when the program is run.
    Main includes the Graph class which will represent the graph from the given input.
    The Graph class includes the Node class and a map that maps strings (city names) to the node that represents that city.
    Nodes hold a map that maps city names to a distance to that city.
5. In order to compile the code a terminal must be opened in the projct directory.
    Run the below commands in order
    Command:                                     Use:
    cmake . -B build -G "MinGW Makefiles"       Creates build directory
    cd build                                    Changes to build directory
    mingw32-make                                Compiles the program

    The program can now be run in this format (in the build directory):
    .\find_route.exe ../Datafiles/<input_file_name> <city1> <city2>
    
