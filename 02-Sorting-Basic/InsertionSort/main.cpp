#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
using namespace std;

//插入排序对比选择排序来说，插入排序可以提前结束（当后面的元素大于前面的元素就可以在内层循环提前结束）
template<typename T>
void insertionSort(T arr[],int n){
    for(int i = 1;i < n;i++){
        //寻找元素arr[i]合适的插入位置

//        for(int j = i;j > 0 && arr[j] < arr[j-1];j--)
//           swap(arr[j],arr[j-1]);


        //优化 减少swap三次赋值操作为 一次赋值操作
        T e = arr[i];
        int j;//j保存元素e应该插入的位置
        for(j = i;j > 0 && e < arr[j-1];j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

int main() {
    int n = 10000;
//    int* arr = SortTestHelper::generateRandomArray(n,0,n);
    int* arr = SortTestHelper::generateNearlyOrderedArray(n,10);

    int* arr2 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("SelectionSort",selectionSort,arr,n);
    SortTestHelper::testSort("InsertionSort",insertionSort,arr2,n);

    delete[] arr;
    delete[] arr2;
    return 0;
}
