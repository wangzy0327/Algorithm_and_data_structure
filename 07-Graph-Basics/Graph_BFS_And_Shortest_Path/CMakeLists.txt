cmake_minimum_required(VERSION 3.17)
project(Graph_BFS_And_Shortest_Path)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph_BFS_And_Shortest_Path main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Component.h FindPath.h ShortestPath.h)