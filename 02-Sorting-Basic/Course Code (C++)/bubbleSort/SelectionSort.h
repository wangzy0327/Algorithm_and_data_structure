//
// Created by wzy on 2020/11/30.
//

#ifndef BUBBLESORT_SELECTIONSORT_H
#define BUBBLESORT_SELECTIONSORT_H

template <typename T>
void selectionSort(T arr[],int n){
    for(int i = 0;i < n;i++){
        //寻找[i,n)区间里的最小值
        int minIndex = i;
        for(int j = i+1;j < n;j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i],arr[minIndex]);
    }
}

#endif //BUBBLESORT_SELECTIONSORT_H
