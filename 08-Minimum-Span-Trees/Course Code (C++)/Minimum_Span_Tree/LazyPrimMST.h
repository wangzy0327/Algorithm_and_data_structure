//
// Created by wzy on 2020/12/17.
//

#ifndef MINIMUM_SPAN_TREE_LAZYPRIMMST_H
#define MINIMUM_SPAN_TREE_LAZYPRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "MinHeap.h"
#include "Edge.h"

using namespace std;

// 使用Prim算法求图的最小生成树
template<typename Graph,typename Weight>
class LazyPrimMST{

private:
    Graph& G;    // 图的引用
    MinHeap<Edge<Weight>> pq;   // 最小堆, 算法辅助数据结构
    bool* marked;     // 标记数组, 在算法运行过程中标记节点i是否被访问
    vector<Edge<Weight>> mst;    // 最小生成树所包含的所有边
    Weight mstWeight;      // 最小生成树的权值

    //访问节点v
    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;
        //将和节点v相连接的所有未访问的边放入最小堆中
        typename Graph::adjIterator adj(G,v);
        for(Edge<Weight>* e = adj.begin();!adj.end();e = adj.next()){
            if(!marked[e->other(v)])
                pq.insert(*e);
        }
    }

public:
    //构造函数，使用Prim算法求图中的最小生成树
    LazyPrimMST(Graph& graph):G(graph),pq(MinHeap<Edge<Weight>>(graph.E())){
        //算法初始化
        marked = new bool[G.V()];
        for(int i = 0;i < G.V();i++)
            marked[i] = false;
        mst.clear();

        //Lazy Prim
        visit(0);
        while(!pq.isEmpty()){
            //使用最小堆找出已经访问的边中权值最小的边
            Edge<Weight> edge = pq.extractMin();
            //如果这条边的两端都已经访问过了，则扔掉这条边
            if(marked[edge.v()] == true && marked[edge.w()] == true)
                continue;
            //否则，这条边则应该存在在最小生成树中
            mst.push_back(edge);

            //访问和这条边连接的还没有被访问过的节点
            if(!marked[edge.v()])
                visit(edge.v());
            else
                visit(edge.w());
        }

        //计算最小生成树的权值
        mstWeight = mst[0].wt();
        for(int i = 1;i < mst.size();i++)
            mstWeight += mst[i].wt();
    }
    //析构函数
    ~LazyPrimMST(){
        delete[] marked;
    }
    // 返回最小生成树的所有边
    vector<Edge<Weight>> mstEdges(){
        return mst;
    }
    Weight result(){
        return mstWeight;
    }
};

#endif //MINIMUM_SPAN_TREE_LAZYPRIMMST_H
