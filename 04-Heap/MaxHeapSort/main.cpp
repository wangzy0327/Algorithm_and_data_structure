#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "SortTestHelper.h"
#include "Heap.h"
#include "QuickSort.h"
#include "MergeSort.h"

using namespace std;

//将n个元素逐个插入到一个空堆中，算法复杂度为O(nlogn)
template<typename T>
void heapSort1(T arr[],int n){
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for(int i = 0;i < n;i ++)
        maxHeap.insert(arr[i]);

    for(int i = n - 1;i >= 0;i --)
        arr[i] = maxHeap.extractMax();
}


//采用heapify的算法复杂度
//heapify的过程，算法复杂度为O(n)
template<typename T>
void heapSort2(T arr[],int n){
    MaxHeap<T> maxHeap = MaxHeap<T>(arr,n);
    for(int i = n - 1;i >= 0;i --)
        arr[i] = maxHeap.extractMax();
}

int main() {

    int n = 1000000;
    cout<<"Test for Random Array, size = "<<n<<endl;
    int* arr = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr,n);
    int* arr3 = SortTestHelper::copyIntArray(arr,n);
    int* arr4 = SortTestHelper::copyIntArray(arr,n);
    int* arr5 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("HeapSort1",heapSort1,arr,n);
    SortTestHelper::testSort("HeapSort2",heapSort2,arr2,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr3,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr4,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr5,n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    cout<<endl;

    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<",swap time = "<<swapTimes<<endl;
    arr = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr,n);
    arr3 = SortTestHelper::copyIntArray(arr,n);
    arr4 = SortTestHelper::copyIntArray(arr,n);
    arr5 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("HeapSort1",heapSort1,arr,n);
    SortTestHelper::testSort("HeapSort2",heapSort2,arr2,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr3,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr4,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr5,n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;


    cout<<endl;

    cout<<"Test for Random Array, size = "<<n<<" , random range [0,10]"<<endl;
    arr = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr,n);
    arr3 = SortTestHelper::copyIntArray(arr,n);
    arr4 = SortTestHelper::copyIntArray(arr,n);
    arr5 = SortTestHelper::copyIntArray(arr,n);


    SortTestHelper::testSort("HeapSort1",heapSort1,arr,n);
    SortTestHelper::testSort("HeapSort2",heapSort2,arr2,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr3,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr4,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr5,n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    return 0;
}
