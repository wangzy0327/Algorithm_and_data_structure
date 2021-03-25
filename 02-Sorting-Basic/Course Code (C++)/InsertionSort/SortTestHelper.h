//
// Created by wzy on 2020/11/30.
//

#ifndef INSERTIONSORT_SORTTESTHELPER_H
#define INSERTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper{
    //生成有n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
    int* generateRandomArray(int n,int rangeL,int rangeR){
        assert(rangeL <= rangeR);
        int* arr = new int[n];
        srand(time(NULL));
        for(int i = 0;i < n;i++)
            arr[i] = rand()%(rangeR - rangeL + 1) + rangeL;
        return arr;
    }
    //随机生成近乎有序的随机数组
    int* generateNearlyOrderedArray(int n,int swapTimes){
        int* arr = new int[n];
        for(int i = 0;i < n;i++)
            arr[i] = i;
        srand(time(NULL));
        for(int i = 0;i < swapTimes;i++){
            int posX = rand()%n;
            int poxY = rand()%n;
            swap(arr[posX],arr[poxY]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[],int n){
        for(int i = 0;i < n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    template<typename T>
    bool isSorted(T arr[],int n){
        for(int i = 0;i < n - 1;i++)
            if(arr[i] > arr[i+1])
                return false;
            return true;
    }

    //测试排序算法性能，params:排序名、排序函数指针、测试数组、测试数量
    template<typename T>
    void testSort(string sortName, void(*sort)(T[],int),T arr[],int n){
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();

        assert(isSorted(arr,n));
        cout<<sortName<<" : "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s "<<endl;
        return ;
    }

    //注意 拷贝结构体或者类时需要深拷贝
    template<typename T>
    T* copyIntArray(T a[],int n){
        T* arr = new T[n];
        copy(a,a+n,arr);
        return arr;
    }
}

#endif //SELECTIONSORT_SORTTESTHELPER_H
