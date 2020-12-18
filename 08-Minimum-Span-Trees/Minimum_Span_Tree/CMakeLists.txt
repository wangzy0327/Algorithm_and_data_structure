cmake_minimum_required(VERSION 3.17)
project(Minimum_Span_Tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(Minimum_Span_Tree main.cpp SparseGraph.h DenseGraph.h Edge.h ReadGraph.h MinHeap.h LazyPrimMST.h)