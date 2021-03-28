//
// Created by wangzy on 2021/3/28.
//

#ifndef INC_09_INDEX_HEAP_ADVANCE_MAXHEAP_H
#define INC_09_INDEX_HEAP_ADVANCE_MAXHEAP_H


#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Item>
class IndexMaxHeap{
private:
    //data 存储数据值
    Item* data;
    /**
     * 二者的关系
     *  indexes[i] = j;
     *  reverse[j] = i;
     */
    //indexes 存储按照数据大小排列的索引
    int* indexes;
    //reverse  存储按照索引顺序排列的索引在索引堆中的位置
    int* reverse;
    int count;
    int capacity;

    void shiftUp(int k){
        while(k > 1 && data[indexes[k]] > data[indexes[k/2]]){
            swap(indexes[k],indexes[k/2]);
            reverse[indexes[k]] = k;
            reverse[indexes[k/2]] = k/2;
            k /= 2;
        }
    }

    void shiftDown(int k){
        while(2*k <= count){
            int j = 2*k;
            if(j + 1 <= count && data[indexes[j+1]] > data[indexes[j]])
                j = j + 1;
            if(data[indexes[k]] > data[indexes[j]])
                break;
            swap(indexes[k],indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMaxHeap(int n){
        data = new Item[n + 1];
        indexes = new int[n + 1];
        reverse = new int[n + 1];
        this->capacity = n;
        this->count = 0;
        for(int i = 0;i <= capacity;i++) {
            reverse[i] = 0;
        }
    }
    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }
    // 向最大堆中插入一个新的元素 item
    // 对用户来说数组索引是从0开始的，在堆内部是从1开始的
    void insert(int i,Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );

        // 再插入一个新元素前,还需要保证索引i所在的位置是没有元素的。
        assert( !contain(i) );
        i += 1;
        data[i] = item;
        indexes[++count] = i;
        reverse[indexes[count]] = count;
        shiftUp(count);
    }
    Item extractMax(){
        assert(count > 0);
        Item ret = data[indexes[1]];
        swap(indexes[1],indexes[count]);
        indexes[count] = 0;
        count--;
        // if(count){
        //     reverse[indexes[1]] = 1;
        //     shiftDown(1);
        // }
        return ret;
    }
    // 从最大索引堆中取出堆顶元素的索引
    int extractMaxIndex(){
        assert(count > 0);
        int idx = indexes[1] - 1;
        swap(indexes[1],indexes[count]);
        reverse[indexes[count]] = 0;
        count--;
        // if(count){
        //     reverse[indexes[1]] = 1;
        //     shiftDown(1);
        // }
        return idx;
    }
    //获取最大索引堆中的堆顶元素
    Item getMax(){
        assert( count > 0);
        return data[indexes[1]];
    }
    // 获取最大索引堆中的堆顶元素的索引
    int getMaxIndex(){
        assert(count > 0);
        return indexes[1] - 1;
    }
    //看索引i所在的位置是否存在元素
    //注意索引转化
    bool contain(int i){
        assert( i + 1 >= 1 && i + 1 <= this->capacity);
        i += 1;
        return reverse[i] != 0;
    }
    //获取最大索引堆中索引为i的元素
    //注意索引转化
    Item getItem(int i){
        assert(contain(i));
        i+=1;
        return data[i];
    }
    //将最大索引堆中索引为i的元素修改为newItem
    //注意索引转化
    void change(int i,Item newItem){
        assert(contain(i));
        i += 1;
        data[i] = newItem;
        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
//        for( int j = 1 ; j <= count ; j ++ )
//            if( indexes[j] == i ){
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
        // 有了 reverse 之后,
        // 我们可以非常简单的通过reverse直接定位索引i在indexes中的位置
        shiftUp(indexes[i]);
        shiftDown(indexes[i]);
    }
    //测试索引堆中的索引数组index和反向数组reverse
    //注意：这个测试在向堆中插入元素以后，不进行extract操作有效
    bool testIndexesAndReverseIndexes(){
        int* copyIndexes = new int[count + 1];
        int* copyReverseIndexes = new int[count + 1];
        for(int i = 1;i <= count;i++){
            copyIndexes[i] = indexes[i];
            copyReverseIndexes[i] = reverse[i];
        }

        copyIndexes[0] = copyReverseIndexes[0] = 0;
        sort(copyIndexes,copyIndexes + count + 1);
        sort(copyReverseIndexes,copyReverseIndexes + count + 1);

        // 在对索引堆中的索引和反向索引进行排序后,
        // 两个数组都应该正好是1...count这count个索引

        bool res = true;
        for(int i = 1;i <= count;i++){
            if(copyIndexes[i-1]+1 != copyIndexes[i] ||
               copyReverseIndexes[i-1]+1 != copyReverseIndexes[i]){
                res = false;
                break;
            }
        }
        delete[] copyIndexes;
        delete[] copyReverseIndexes;

        if(!res){
            cout<<"Error ! "<<endl;
            return false;
        }
        for( int i = 1 ; i <= count ; i ++ )
            if( reverse[ indexes[i] ] != i ){
                cout<<"Error 2"<<endl;
                return false;
            }

        return true;
    }
};

#endif //INC_09_INDEX_HEAP_ADVANCE_MAXHEAP_H
