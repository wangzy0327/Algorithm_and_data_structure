//
// Created by wzy on 2020/12/17.
//

#ifndef MINIMUM_SPAN_TREES_DENSEGRAPH_H
#define MINIMUM_SPAN_TREES_DENSEGRAPH_H


#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

//稠密图 - 邻接矩阵
template<typename Weight>
class DenseGraph{
private:
    //点数、边数
    int n,m;
    //有向图/无向图
    bool directed;
    vector<vector<Edge<Weight> *>> g;//图的具体数据

public:
    DenseGraph(int n,bool directed){
        this->n = n;
        this->m = 0; // 初始化没有任何边
        this->directed = directed;
//        g = vector<vector<bool>>(n,vector<bool>(n,false));
//      g初始化为n*n的布尔矩阵，每一个g[i][j]均为false,表示没有任何边
        for(int i = 0;i < n;i ++ )
            g.push_back(vector<Edge<Weight> *>(n,NULL));
    }
    ~DenseGraph(){
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j++)
                if(g[i][j] != NULL)
                    delete g[i][j];
    }
    int V(){return n;}//返回节点个数
    int E(){return m;}//返回边的个数

    //向图中添加一个边
    void addEdge(int v,int w,Weight weight){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if(hasEdge(v,w)) {
            delete g[v][w];
            if (!directed)
                delete g[w][v];
            m--;
        }

        g[v][w] = new Edge<Weight>(v,w,weight);
        if(!directed)
            g[w][v] = new Edge<Weight>(v,w,weight);
        m++;
    }

    //验证图中是否有从v到w的边
    bool hasEdge(int v,int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w] != NULL;
    }
    // 显示图的信息
    void show(){
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                if(g[i][j])
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL\t";
            }
            cout<<endl;
        }
    }

    //邻边迭代器，传入一个图和一个顶点
    //迭代在这个图中和这个顶点相连的所有顶点
    class adjIterator{
    private:
        DenseGraph & G;//图G的引用
        int v;
        int index;
    public:
        adjIterator(DenseGraph& graph,int v):G(graph){
            this->v = v;
            this->index = index;
        }
        ~adjIterator(){};
        //返回图中与顶点v相连接的第一个顶点
        Edge<Weight>* begin(){
            index = -1;
            return next();
        }
        //返回图G中与顶点v相连接的下一个顶点
        Edge<Weight>* next(){
            // 从当前index开始向后搜索, 直到找到一个g[v][index]为true
            for(index += 1;index < G.g[v].size();index++)
                if(G.g[v][index])
                    return index;
            //若没有顶点和v相连接，则返回-1
            return NULL;
        }
        //查看是否已经迭代完了图G中与顶点v相连接的所有顶点
        bool end(){
            return index>=G.V();
        }
    };

};

#endif //MINIMUM_SPAN_TREES_DENSEGRAPH_H
