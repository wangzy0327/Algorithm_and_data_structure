cmake_minimum_required(VERSION 3.17)
project(Graph_DFS)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph_DFS main.cpp ReadGraph.h SparseGraph.h DenseGraph.h Component.h FindPath.h)