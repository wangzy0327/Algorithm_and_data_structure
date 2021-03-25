//
// Created by wzy on 2020/12/8.
//

#ifndef PATH_COMPRESSION_UNIONFIND4_H
#define PATH_COMPRESSION_UNIONFIND4_H

#include <iostream>
#include <cassert>
//第四版Union-Find
namespace UF4{
    class UnionFind{
    private:
        int* parent; // parent[i]表示第i个元素所指向的父节点
        int* rank; // rank[i]表示以i为根的集合所表示的树的层数
        int count;
    public:
        // 初始化, 每一个parent[i]指向自己, 表示每一个元素自己自成一个集合
        UnionFind(int n){
            count = n;
            parent = new int[n];
            rank = new int[n];
            for(int i = 0;i < n;i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind(){
            delete[] parent;
            delete[] rank;
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
            // 根据两个元素所在树的元素个数不同判断合并方向
            // 将元素个数少的集合合并到元素个数多的集合上
            if(rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }else if(rank[qRoot] < rank[pRoot]){
                parent[qRoot] = pRoot;
            }else{
                //rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;// 此时, 我维护rank的值
            }
        }

    };
}

#endif //PATH_COMPRESSION_UNIONFIND4_H
