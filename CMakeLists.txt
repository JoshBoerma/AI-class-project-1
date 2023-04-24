cmake_minimum_required(VERSION "3.10")

project("AIProject1")

add_executable(
    find_route 
    main.cpp 
    Graph.cpp 
    Node.cpp
)

install(TARGETS find_route DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)

