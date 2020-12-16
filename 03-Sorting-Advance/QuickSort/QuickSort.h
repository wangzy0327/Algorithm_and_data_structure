//
// Created by wzy on 2020/12/2.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H
#include <algorithm>
#include <ctime>
#include "InsertionSort.h"

//[v|          < v|           >= v|e  ]
//     [l+1,i]    i   [i+1,j)     j
//对arr[l...r]部分进行parition操作
//返回p，使得arr[l...p-1]<arr[p];arr[p+1...r]>=arr[p]
//单路快排
template<typename T>
int partition(T arr[],int l,int r){
    int ind = l + rand()%(r - l + 1);
    swap(arr[l],arr[ind]);
    T v = arr[l];
    // arr[l+1...j]<v ; arr[j+1...i) >= v
    int i = l;
    int j = l+1;
    for(;j <= r;j++){
        if(arr[j] <= v)
            swap(arr[++i],arr[j]);
    }
    swap(arr[l],arr[i]);
    return i;
}

//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[],int l,int r){
    //在数据规模小的情况下采用插入排序
    if(r - l <= 15)
        return insertionSort(arr,l,r);
//    if(l >= r)
//        return ;
    int pos = partition(arr,l,r);
    __quickSort(arr,l,pos - 1);
    __quickSort(arr,pos + 1,r);
}

template<typename T>
void quickSort(T arr[],int n){
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}

#endif //QUICKSORT_QUICKSORT_H
