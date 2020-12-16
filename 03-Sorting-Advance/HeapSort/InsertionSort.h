//
// Created by wzy on 2020/12/3.
//

#ifndef HEAPSORT_INSERTIONSORT_H
#define HEAPSORT_INSERTIONSORT_H

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

//对arr[l...r]范围内的数组进行插入排序
template<typename T>
void insertionSort(T arr[],int l,int r){
    for(int i = l+1;i <= r;i++){
        //寻找元素arr[i]合适的插入位置

//        for(int j = i;j > 0 && arr[j] < arr[j-1];j--)
//           swap(arr[j],arr[j-1]);


        //优化 减少swap三次赋值操作为 一次赋值操作
        T e = arr[i];
        int j;//j保存元素e应该插入的位置
        for(j = i;j > l && e < arr[j-1];j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
}

#endif //HEAPSORT_INSERTIONSORT_H
