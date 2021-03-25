cmake_minimum_required(VERSION 3.17)
project(MaxHeapSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(MaxHeapSort main.cpp SortTestHelper.h MergeSort.h QuickSort.h InsertionSort.h Heap.h)