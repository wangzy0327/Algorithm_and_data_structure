cmake_minimum_required(VERSION 3.17)
project(IndexHeap)

set(CMAKE_CXX_STANDARD 14)

add_executable(IndexHeap main.cpp Heap.h HeapSort.h InsertionSort.h MergeSort.h QuickSort.h SortTestHelper.h)