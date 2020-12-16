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


template<typename T>
void __shiftDown(T arr[], int n,int k){
    while(k*2+1 < n){
        int j = 2*k+1;  //在此轮循环中，data[k]和data[j]交换位置
        if(j + 1 < n && arr[j+1] > arr[j])
            j += 1;
        if(arr[k] >= arr[j])
            break;
        swap(arr[k],arr[j]);
        k = j;
    }
}

//应用： 在N元素中选出前M个元素，使用大小为M的优先队列，比M小的元素在遍历过程中都被移出队列。时间复杂度：O(NlogM)

//原地heapify，不占用额外空间
//这里堆的构建采用 数组 从0开始 进行存储  arr[0...n]

template<typename T>
void heapSort3(T arr[],int n){

    //heapify
    for(int i = (n - 1)/2;i >= 0;i--)
        __shiftDown(arr,n,i);

    for(int i = n - 1;i > 0;i--){
        swap(arr[0], arr[i]);
        __shiftDown(arr,i,0);
    }
}

int main() {
    int n = 1000000;
    cout<<"Test for Random Array, size = "<<n<<endl;
    int* arr = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr,n);
    int* arr3 = SortTestHelper::copyIntArray(arr,n);
    int* arr4 = SortTestHelper::copyIntArray(arr,n);
    int* arr5 = SortTestHelper::copyIntArray(arr,n);
    int* arr6 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("HeapSort1",heapSort1,arr,n);
    SortTestHelper::testSort("HeapSort2",heapSort2,arr2,n);
    SortTestHelper::testSort("HeapSort3",heapSort3,arr3,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr4,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr5,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr6,n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout<<endl;

    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<",swap time = "<<swapTimes<<endl;
    arr = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr,n);
    arr3 = SortTestHelper::copyIntArray(arr,n);
    arr4 = SortTestHelper::copyIntArray(arr,n);
    arr5 = SortTestHelper::copyIntArray(arr,n);
    arr6 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("HeapSort1",heapSort1,arr,n);
    SortTestHelper::testSort("HeapSort2",heapSort2,arr2,n);
    SortTestHelper::testSort("HeapSort3",heapSort3,arr3,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr4,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr5,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr6,n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;


    cout<<endl;

    cout<<"Test for Random Array, size = "<<n<<" , random range [0,10]"<<endl;
    arr = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr,n);
    arr3 = SortTestHelper::copyIntArray(arr,n);
    arr4 = SortTestHelper::copyIntArray(arr,n);
    arr5 = SortTestHelper::copyIntArray(arr,n);
    arr6 = SortTestHelper::copyIntArray(arr,n);


    SortTestHelper::testSort("HeapSort1",heapSort1,arr,n);
    SortTestHelper::testSort("HeapSort2",heapSort2,arr2,n);
    SortTestHelper::testSort("HeapSort3",heapSort3,arr3,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr4,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr5,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr6,n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    return 0;
}
