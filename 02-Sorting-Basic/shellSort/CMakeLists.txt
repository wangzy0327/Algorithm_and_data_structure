cmake_minimum_required(VERSION 3.17)
project(shellSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(shellSort main.cpp SelectionSort.h InsertSort.h SortTestHelper.h BubbleSort.h)