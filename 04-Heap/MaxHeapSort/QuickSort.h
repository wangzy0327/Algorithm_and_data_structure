//
// Created by wzy on 2020/12/2.
//

#ifndef MAXHEAPSORT_QUICKSORT_H
#define MAXHEAPSORT_QUICKSORT_H

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

#endif //MAXHEAPSORT_QUICKSORT_H
