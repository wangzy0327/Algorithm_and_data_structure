//
// Created by wzy on 2020/12/17.
//

#ifndef MINIMUM_SPAN_TREE_MINHEAP_H
#define MINIMUM_SPAN_TREE_MINHEAP_H

#include <iostream>
using namespace std;

template<typename Item>
class MinHeap{
private:
    Item* data;
    int count;
    int capacity;

    void shiftUp(int k){
        Item item = data[k];
        while(k > 1 && data[k/2] > item){
            data[k] = data[k/2];
            k /= 2;
        }
        data[k] = item;
    }
    void shiftDown(int k){
        Item item = data[k];
        while(2*k <= count){
            int j = 2*k;
            if(j + 1 <= count && data[j + 1] < data[j]) j = 2*k+1;
            if(item <= data[j]) break;
            data[k] = data[j];
            k = j;
        }
        data[k] = item;
    }

public:
    MinHeap(int capacity){
        this->data = new Item[capacity + 1];
        this->count = 0;
        this->capacity = capacity;
    }
    ~MinHeap(){
        delete[] data;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }
    void insert(Item item){
        data[++count] = item;
        shiftUp(count);
    }
    Item extractMin(){
        assert(!isEmpty());
        Item ret = data[1];
        swap(data[1],data[count]);
        count--;
        shiftDown(1);
        return ret;
    }

public:

};

#endif //MINIMUM_SPAN_TREE_MINHEAP_H
