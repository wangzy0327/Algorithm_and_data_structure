cmake_minimum_required(VERSION 3.17)
project(QuickSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(QuickSort main.cpp SortTestHelper.h InsertionSort.h MergeSort.h QuickSort.h QuickSort2.h)