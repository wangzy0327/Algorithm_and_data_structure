#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"
using namespace std;


//每次归并可以求出一组逆序 —— 归并排序典型应用（求逆序对 inversed pairs）
//自底向上归并排序（特点：适用于链表）
template<typename T>
void mergeSortBU(T arr[],int n){
    T extra[n];
    //sz 为步长
    for(int sz = 1; sz < n;sz += sz)
        for(int i = 0;i + sz  < n;i += sz + sz){
            //对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
            if(arr[i + sz - 1] > arr[i + sz ])
                __merge(arr,extra,i,i + sz - 1,min(i + sz + sz - 1,n - 1));
        }
}


int main() {
    int n = 50000;
    cout<<"Test for Random Array, size = "<<n<<endl;
    int* arr = SortTestHelper::generateRandomArray(n,0,n);
    int* arr1 = SortTestHelper::copyIntArray(arr,n);
    int* arr2 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr,n);
    SortTestHelper::testSort("mergeSortBU",mergeSortBU,arr1,n);
    SortTestHelper::testSort("InsertionSort",insertionSort,arr2,n);
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    cout<<endl;

    int swapTimes = 10;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<",swap time = "<<swapTimes<<endl;
    arr = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr1 = SortTestHelper::copyIntArray(arr,n);
    arr2 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr,n);
    SortTestHelper::testSort("mergeSortBU",mergeSortBU,arr1,n);
    SortTestHelper::testSort("InsertionSort",insertionSort,arr2,n);
    delete[] arr;
    delete[] arr1;
    delete[] arr2;


    return 0;
}
