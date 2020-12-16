#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertSort.h"
#include "BubbleSort.h"
using namespace std;


/**
 * 序列无序的情况下，算法性能：希尔排序>插入排序>选择排序>冒泡排序
 */

//希尔排序 使用 合适的区间 ，每个区间进行插入排序
// 1,4,13,40...
template<typename T>
void shellSort(T arr[],int n){
    int h = 1;
    while(h < n/3){
        h = h*3 + 1;
    }

    while(h >= 1){
        //h-sort the array
        for(int i = h;i < n;i++){
            T e = arr[i];
            int j ;
            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            for(j = i;j >= h && e < arr[j-h];j-=h)
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        h = h/3;
    }

}

int main() {
    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n,0,n);
    int* arr1 = SortTestHelper::copyIntArray(arr,n);
    int* arr2 = SortTestHelper::copyIntArray(arr,n);
    int* arr3 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("ShellSort",shellSort,arr,n);
    SortTestHelper::testSort("InsertionSort",insertionSort,arr1,n);
    SortTestHelper::testSort("SelectionSort",selectionSort,arr2,n);
    SortTestHelper::testSort("BubbleSort",bubbleSort,arr3,n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
