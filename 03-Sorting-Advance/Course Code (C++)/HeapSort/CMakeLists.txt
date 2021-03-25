cmake_minimum_required(VERSION 3.17)
project(HeapSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(HeapSort main.cpp SortTestHelper.h InsertionSort.h QuickSort.h MergeSort.h Heap.h)