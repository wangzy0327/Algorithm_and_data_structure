//
// Created by wzy on 2020/12/2.
//

#ifndef QUICKSORT_QUICKSORT2_H
#define QUICKSORT_QUICKSORT2_H
#include <algorithm>
#include <ctime>

//[v|          < v|e    |       >= v| ]
//     [l+1,i]   i      j      [j,r]
//对arr[l...r]部分进行parition操作
//返回p，使得arr[l...p-1]<arr[p];arr[p+1...r]>arr[p]
//双路快排
template<typename T>
int partition2(T arr[],int l,int r){
    swap(arr[l],arr[l + rand()%(r - l + 1)]);
    T v = arr[l];
    // arr[l+1...i)<=v ; arr(j...r] >= v
    int i = l+1;
    int j = r;
    while(true){
        while(i <= j && arr[i] < v)
            i++;
        while(i <= j && arr[j] > v)
            j--;
        if(i > j)
            break;
        swap(arr[i++],arr[j--]);
    }
    swap(arr[l],arr[j]);
    return j;
}

//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort2(T arr[],int l,int r){
    //在数据规模小的情况下采用插入排序
    if(r - l <= 15)
        return insertionSort(arr,l,r);
//    if(l >= r)
//        return ;
    int pos = partition2(arr,l,r);
    __quickSort2(arr,l,pos - 1);
    __quickSort2(arr,pos + 1,r);
}

template<typename T>
void quickSort2(T arr[],int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}
#endif //QUICKSORT_QUICKSORT2_H
