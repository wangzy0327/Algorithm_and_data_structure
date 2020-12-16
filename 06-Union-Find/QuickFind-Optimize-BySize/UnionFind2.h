//
// Created by wzy on 2020/12/8.
//

#ifndef QUICKFIND_OPTIMIZE_BYSIZE_UNIONFIND2_H
#define QUICKFIND_OPTIMIZE_BYSIZE_UNIONFIND2_H

#include <iostream>
#include <cassert>
//思路通过 将每个元素，看做一个节点，如果节点跟其他节点相连接，只需要将其指向另一个节点（父节点）
//
// 使用一个数组构建一棵指向父节点的树
// parent[i]表示第i个元素所指向的父节点
namespace UF2 {
    //第二版并查集
    class UnionFind{
    private:
        int* parent;
        int count;
    public:
        // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
        UnionFind(int n){
            count = n;
            parent = new int[n];
            for(int i = 0;i < n;i++)
                parent[i] = i;
        }
        ~UnionFind(){
            delete[] parent;
        }
        // 查找过程, 查找元素p所对应的集合编号
        // O(h)复杂度, h为树的高度
        int find(int p){
            assert(p >= 0 && p < count);
            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p
            while(p != parent[p])
                p = parent[p];
            return parent[p];
        }
        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected(int p,int q){
            return find(p) == find(q);
        }
        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度
        void unionElements(int p,int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if(pRoot == qRoot)
                return ;
            parent[pRoot] = qRoot;
        }

    };
}

#endif //QUICKFIND_OPTIMIZE_BYSIZE_UNIONFIND2_H
