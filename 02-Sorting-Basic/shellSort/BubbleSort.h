//
// Created by wzy on 2020/11/30.
//

#ifndef SHELLSORT_BUBBLESORT_H
#define SHELLSORT_BUBBLESORT_H
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
#endif //SHELLSORT_BUBBLESORT_H
