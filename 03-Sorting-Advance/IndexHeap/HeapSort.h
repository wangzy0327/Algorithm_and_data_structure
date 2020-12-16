//
// Created by wzy on 2020/12/3.
//

#ifndef INDEXHEAP_HEAPSORT_H
#define INDEXHEAP_HEAPSORT_H

#include "Heap.h"

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

#endif //INDEXHEAP_HEAPSORT_H
