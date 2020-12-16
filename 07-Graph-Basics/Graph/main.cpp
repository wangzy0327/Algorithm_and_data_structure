#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

int main() {
    int N = 20;
    int M = 100;

    srand( time(NULL) );


    // Sparse Graph
//    SparseGraph g1(N , false);
//    for( int i = 0 ; i < M ; i ++ ){
//        int a = rand()%N;
//        int b = rand()%N;
//        g1.addEdge( a , b );
//    }
//
//    // O(E)
//    for( int v = 0 ; v < N ; v ++ ){
//        cout<<v<<" : ";
//        SparseGraph::adjIterator adj( g1 , v );
//        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
//            cout<<w<<" ";
//        cout<<endl;
//    }
//
//    cout<<endl;
//
//
//    // Dense Graph
//    DenseGraph g2(N , false);
//    for( int i = 0 ; i < M ; i ++ ){
//        int a = rand()%N;
//        int b = rand()%N;
//        g2.addEdge( a , b );
//    }
//
//    // O(V^2)
//    for( int v = 0 ; v < N ; v ++ ){
//        cout<<v<<" : ";
//        DenseGraph::adjIterator adj( g2 , v );
//        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
//            cout<<w<<" ";
//        cout<<endl;
//    }
//
//
    // 测试通过文件读取图的信息
    // 使用两种图的存储方式读取testG1.txt文件
    string filename = "testG1.txt";
    SparseGraph g1( 13 , false );
    ReadGraph<SparseGraph> readGraph1( g1 , filename );
    cout<<"test G1 in Sparse Graph:" << endl;
    g1.show();

    cout<<endl;

    DenseGraph g2( 13 , false );
    ReadGraph<DenseGraph> readGraph2( g2 , filename );
    cout<<"test G1 in Dense Graph:" << endl;
    g2.show();

    cout<<endl;

    // 使用两种图的存储方式读取testG2.txt文件
    filename = "testG2.txt";
    SparseGraph g3( 6 , false );
    ReadGraph<SparseGraph> readGraph3( g3 , filename );
    cout<<"test G2 in Sparse Graph:" << endl;
    g3.show();

    cout<<endl;

    DenseGraph g4( 6 , false );
    ReadGraph<DenseGraph> readGraph4( g4 , filename );
    cout<<"test G2 in Dense Graph:" << endl;
    g4.show();

}
