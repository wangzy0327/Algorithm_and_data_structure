//
// Created by wzy on 2020/12/14.
//

#ifndef GRAPH_DFS_FINDPATH_H
#define GRAPH_DFS_FINDPATH_H

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

//路径查询
template<typename Graph>
class Path{
private:
    Graph &G; //图的引用
    int s;  //起始点
    bool* visited; //记录dfs的过程中节点是否被访问
    int* from;   //记录路径, from[i]表示查找的路径上i的上一个节点

    //图的深度优先遍历
    void dfs(int v){
        visited[v] = true;
        typename Graph::adjIterator adj(G,v);
        for(int i = adj.begin();!adj.end();i = adj.next()){
            if(!visited[i]){
                from[i] = v;
                dfs(i);
            }
        }
    }
public:
    // 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
    Path(Graph& graph,int s):G(graph){
        //算法初始化
        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        for(int i = 0;i < G.V();i++){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;
        // 寻路算法
        dfs(s);
    }
    //析构函数
    ~Path(){
        delete[] visited;
        delete[] from;
    }
    // 查询从s点到w点是否有路径
    bool hasPath(int w){
        assert(w >= 0 && w < G.V());
        return visited[w];
    }
    // 查询从s点到w点的路径, 存放在vec中
    void path(int w, vector<int> &vec){
        assert(hasPath(w));
        stack<int> s;
        for(int i = w;i != -1;i = from[i])
            s.push(i);
        vec.clear();
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }
    // 打印出从s点到w点的路径
    void showPath(int w){
        assert(hasPath(w));
        vector<int> vec;
        path(w,vec);
        for(int i = 0;i < vec.size();i++){
            cout<<vec[i];
            if(i == vec.size() - 1)
                cout<<endl;
            else
                cout<<" -> ";
        }

    }

};

#endif //GRAPH_DFS_FINDPATH_H
