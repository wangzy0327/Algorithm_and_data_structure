#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"

using namespace std;

//标定点 —— 快速排序的典型应用 (求取数组中第N个大元素)

//[v|          < v|   ==v |  ... |  > v ]
//     [l+1,lt]   [lt+1,i)        [gt,r]
//三路快速排序处理 arr[l...r]
//将arr[l...r]分为<v;>v两部分继续进行三路快速排序
//之后递归对 <v;>v两部分继续进行三路快速排序
template<typename T>
void __quickSort3Ways(T arr[],int l,int r){
    if(r - l <= 15){
        insertionSort(arr,l,r);
        return;
    }
    //partition
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int lt = l; //arr[l+1...lt] < v
    int gt = r + 1; //arr[gt...r] > v
    int i = l + 1;  //arr[lt+1...i) == v
    while(i < gt){
        if(arr[i] < v){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }else if(arr[i] > v){
            swap(arr[i],arr[gt-1]);
            gt--;
        }else{
            i++;
        }
    }
    swap(arr[l],arr[lt]);
    __quickSort3Ways(arr,l,lt - 1);
    __quickSort3Ways(arr,gt,r);
}

template<typename T>
void quickSort3Ways(T arr[],int n){
    srand(time(NULL));
    __quickSort3Ways(arr,0,n-1);
}


int main() {
//    for(int i = 0;i < 100;i++){
//        int x = rand()%(3-2);
//        cout<<x<<endl;
//    }
    int n = 1000000;
    cout<<"Test for Random Array, size = "<<n<<endl;
    int* arr = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr,n);
    int* arr3 = SortTestHelper::copyIntArray(arr,n);
    int* arr4 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr2,n);
    SortTestHelper::testSort("QuickSort",quickSort,arr3,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr4,n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout<<endl;

    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<",swap time = "<<swapTimes<<endl;
    arr = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr,n);
    arr3 = SortTestHelper::copyIntArray(arr,n);
    arr4 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr2,n);
    SortTestHelper::testSort("QuickSort",quickSort,arr3,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr4,n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout<<endl;

    cout<<"Test for Random Array, size = "<<n<<" , random range [0,10]"<<endl;
    arr = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr,n);
//    arr3 = SortTestHelper::copyIntArray(arr,n);
    arr4 = SortTestHelper::copyIntArray(arr,n);
    SortTestHelper::testSort("QuickSort3Ways",quickSort3Ways,arr,n);
    SortTestHelper::testSort("QuickSort2",quickSort2,arr2,n);
//    SortTestHelper::testSort("QuickSort",quickSort,arr3,n);
    SortTestHelper::testSort("MergeSort",mergeSort,arr4,n);
    delete[] arr;
    delete[] arr2;
//    delete[] arr3;
    delete[] arr4;

    return 0;
}
