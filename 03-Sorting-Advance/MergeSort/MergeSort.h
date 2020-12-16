//
// Created by wzy on 2020/12/2.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

//对arr[l,mid] arr[mid+1,r]两部分进行合并
template<typename T>
void __merge(T arr[],T extra[],int l,int mid,int r){
    //k为额外空间将要放入较小比较元素的位置
    int k = l;
    //i为左边数组将要比较的元素位置
    int i = l;
    //j为右边数组将要比较的元素位置
    int j = mid + 1;
    for(;i <= mid && j <= r;){
        if(arr[i] <= arr[j])
            extra[k++] = arr[i++];
        else
            extra[k++] = arr[j++];
    }
    for(;i <= mid;)
        extra[k++] = arr[i++];
    for(;j <= r;)
        extra[k++] = arr[j++];
    for(int t = l;t <= r;t++)
        arr[t] = extra[t];
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[],T extra[],int l,int r){
    //递归到数据规模比较小的情况下，可以使用插入排序
    if(r - l <= 15){
        insertionSort(arr,l,r);
        return;
    }
//    if(l >= r)
//        return;
    int mid = l + (r - l)/2;
    __mergeSort(arr,extra,l,mid);
    __mergeSort(arr,extra,mid+1,r);
    if(arr[mid] > arr[mid + 1])
        __merge(arr,extra,l,mid,r);
}

template<typename T>
void mergeSort(T arr[],int n){
    T extra[n];
    __mergeSort(arr,extra,0,n-1);
}
#endif //MERGESORT_MERGESORT_H
