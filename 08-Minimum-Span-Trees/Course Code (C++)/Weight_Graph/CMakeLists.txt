cmake_minimum_required(VERSION 3.17)
project(Weight_Graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(Weight_Graph main.cpp SparseGraph.h ReadGraph.h DenseGraph.h Edge.h)