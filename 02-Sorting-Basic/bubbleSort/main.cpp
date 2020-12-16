#include <iostream>
#include <vector>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;

//冒泡排序
template<typename T>
void bubbleSort(T arr[],int n){

//    bool flag;
//    for(int i = 0;i < n;i++){
//        flag = false;
//        for(int j = 1;j < n-i;j++){
//            if(arr[j - 1] > arr[j]){
//                swap(arr[j-1],arr[j]);
//                flag = true;
//            }
//        }
//        if(!flag)
//            break;
//    }

    //记录最后一次交换位置
    int newn ;
    do{
        newn = 0;
        //把最大的元素往下沉
        for(int j = 1;j < n ;j++){
            if(arr[j] < arr[j-1]){
                swap(arr[j-1],arr[j]);
                newn = j ;
            }
        }
        n = newn;
    }while(newn > 0);
}

int main() {

    int n = 10000;
//    int* arr = SortTestHelper::generateRandomArray(n,0,n);
    int* arr = SortTestHelper::generateNearlyOrderedArray(n,10);
    int* arr2 = SortTestHelper::copyIntArray(arr,n);
    int* arr3 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("SelectionSort",selectionSort,arr,n);
    SortTestHelper::testSort("InsertionSort",insertionSort,arr2,n);
    SortTestHelper::testSort("BubbleSort",bubbleSort,arr3,n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
