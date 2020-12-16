//
// Created by wzy on 2020/12/8.
//

#ifndef QUICKFIND_OPTIMIZE_BYRANK_UNIONFIND1_H
#define QUICKFIND_OPTIMIZE_BYRANK_UNIONFIND1_H
#include <iostream>
#include <cassert>
namespace UF1 {
    //第一版并查集
    class UnionFind{
    private:
        int* id;
        int count;
    public:
        // 初始化, 每一个id[i]指向自己, 没有合并的元素
        UnionFind(int n){
            count = n;
            id = new int[n];
            for(int i = 0;i < n;i++)
                id[i] = i;
        }
        ~UnionFind(){
            delete[] id;
        }
        // 查找过程, 查找元素p所对应的集合编号
        int find(int p){
            assert(p >= 0 && p < count);
            return id[p];
        }
        // 查看元素p和元素q是否所属一个集合
        // O(1)复杂度
        bool isConnected(int p,int q){
            return id[p] == id[q];
        }
        // 合并元素p和元素q所属的集合
        // O(n) 复杂度
        void unionElements(int p,int q){
            int pID = find(p);
            int qID = find(q);
            if(pID == qID)
                return ;
            // 合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并
            for(int i = 0;i < count;i++)
                if(id[i] == pID)
                    id[i] = qID;
        }

    };
}
#endif //QUICKFIND_OPTIMIZE_BYRANK_UNIONFIND1_H
